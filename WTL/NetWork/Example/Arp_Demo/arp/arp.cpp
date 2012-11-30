#include "arpPkt.h"
#include <iostream>
using namespace std;
#include <./pcap.h>

pcap_if_t *g_palldevs;
pcap_if_t *g_pd;
int g_iCount = 0, g_num;                //�ڼ�������������
pcap_t *g_adhandle;                     //ָ�����Ŀռ�
char g_errbuf[PCAP_ERRBUF_SIZE];        //������Ϣ
arp_packet g_arpPacket;                 //����ARPPACKET�ṹ�����

unsigned char tmp_dest_ip[4] = {0, 0, 0, 0}; //Ŀ��ip
unsigned char tmp_sour_ip[4] = {0, 0, 0, 0}; //����ip
unsigned char tmp_sour_addr[6] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00}; //Ŀ��mac
void setpkt();         //��ʼ��packet
void sendPkt();        //���Ͳ�����arp packet
void GetMACaddress();

void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data);//���յ�arp packet����

void main ()
{
    printf("��ȡ���������豸�б�\n");
    //��ñ��ص������б�
    if(pcap_findalldevs(&g_palldevs, g_errbuf) == -1) //��������豸ָ��
    {
        cout << "Error in pcap_findalldevs:" << endl;
        return ;
    }
    printf("��ӡ�����豸�б�\n");
    // ��ʾ�����б�
    for(g_pd = g_palldevs; g_pd; g_pd = g_pd->next)
    {
        ++g_iCount;
        cout << g_iCount << ":name:" << g_pd->name << endl;
        if (g_pd->description)
            cout << "description:" << g_pd->description << endl;
        else
            cout << "No description available)\n";
    }
    if(g_iCount == 0)
    {
        cout << "\nNo interfaces found! Make sure WinPcap is installed.\n";
        return ;//û�з���������Ϣ
    }
    printf("ѡ�������豸�ӿ�\n");
    cout << "Enter the interface number:(1-" << g_iCount << ")";
    cin >> g_num;

    if(g_num < 1 || g_num > g_iCount)
    {
        cout << "\nInterface number out of range.\n";
        /* �ͷ��ڴ� */
        pcap_freealldevs(g_palldevs);
        return ;
    }
    printf("��ת��ѡ�е�������\n");
    /* ת��ѡ������� */
    for(g_pd = g_palldevs, g_iCount = 0; g_iCount < g_num - 1 ; g_pd = g_pd->next, g_iCount++);
    printf("���豸\n");
    /* ���豸 */
    if ( (g_adhandle = pcap_open_live(g_pd->name,         // name of the device
                                      65536,            // portion of the packet to capture
                                      // 65536 guarantees that the whole packet will be captured on all the link layers
                                      1,                // promiscuous mode
                                      1000,             // read timeout
                                      g_errbuf            // error buffer
                                     ) ) == NULL)
    {
        cout << "\nUnable to open the adapter. " << g_pd->name << "is not supported by WinPcap\n";
        /* Free the device list */
        pcap_freealldevs(g_palldevs);
        return ;
    }

    if(g_pd->addresses == NULL)
    {
        cout << "Unable to open the adapter:" << g_pd->name << endl;
        return;
    }
    for(g_iCount = 0; g_iCount < 4; g_iCount++)
    {
        tmp_sour_ip[g_iCount] = g_pd->addresses->addr->sa_data[g_iCount + 2];
        tmp_dest_ip[g_iCount] = g_pd->addresses->addr->sa_data[g_iCount + 2] & g_pd->addresses->netmask->sa_data[g_iCount + 2];
    }
    cout << "this pc's ip and mac:\nip:";
    for(g_iCount = 0; g_iCount < 4; g_iCount++)
    {
        cout << dec << (int)tmp_sour_ip[g_iCount];
        if(g_iCount != 3)
            cout << ".";
    }
    cout << endl << "the results:(ctrl+c to quit)\n";
    GetMACaddress();
    setpkt();//��ʼpacket
    sendPkt();//����arp���󣬲�����arp��Ӧ
}

void sendPkt()
{
    for(g_iCount = 1; g_iCount < 256; g_iCount++)
    {
        g_arpPacket.arp.dest_ip[3] = (unsigned char)g_iCount;
        if (pcap_sendpacket(g_adhandle, (unsigned char *)&g_arpPacket, sizeof(g_arpPacket) ) != 0) //����arp ����
        {
            cout << "\nError sending the packet: \n";
            return;
        }
        pcap_loop(g_adhandle, 1, packet_handler, NULL);//����arp��Ӧ��������������
    }
    cout << "send ok!" << endl;
}

//��ʼ��packet
void setpkt()
{
    //���ó�ʼarppkt������
    memset(&g_arpPacket, 0, sizeof(arp_packet)); // ���ݰ���ʼ��

	 //�Զ������ֶ�
	g_arpPacket.eth.eh_type = htons((unsigned short)0x0806); // DLC Header����̫������
   
	g_arpPacket.arp.hardware_type = htons((unsigned short)1);;      // Ӳ������
	g_arpPacket.arp.protocol_type = htons((unsigned short)0x0800); // �ϲ�Э������
    g_arpPacket.arp.add_len = (unsigned char)6;                    //mac����
    g_arpPacket.arp.pro_len = (unsigned char)4;                    //ip����


    g_arpPacket.arp.option = htons((unsigned short)0x1);//1Ϊarp����
    for(int i = 0; i < sizeof(g_arpPacket.eth.dest_mac); i++)
        g_arpPacket.eth.dest_mac[i] = 0xff; //�㲥��ַ

    //sour ip and mac

    memcpy(g_arpPacket.arp.sour_addr, tmp_sour_addr, sizeof(tmp_sour_addr));
    memcpy(g_arpPacket.arp.sour_ip, tmp_sour_ip, sizeof(tmp_sour_ip));
    memcpy(g_arpPacket.eth.source_mac, tmp_sour_addr, sizeof(tmp_sour_addr));
    memcpy(g_arpPacket.arp.dest_ip, tmp_dest_ip, sizeof(tmp_dest_ip));
}

/* Callback function invoked by libpcap for every incoming packet */
void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data)
{
    ethernet_head *PETHDR;
    arp_head *PARPHDR;

    //retireve the position of the ethernet header
    PETHDR = (ethernet_head *)pkt_data;
    if((PETHDR->eh_type) == 0x0608) //arp data
    {
        //retireve the position of the arp header
        PARPHDR = (arp_head *)(pkt_data + 14);

        if(PARPHDR->option == 0x0200) //��Ӧ����в���
        {
            cout << "ip:\t";
            for(int i = 0; i < 4; i++)
            {
                cout << dec << (int)PARPHDR->sour_ip[i];
                if(i != 3)
                    cout << ".";
            }
            cout << "\tmac:\t";
            for(g_iCount = 0; g_iCount < 6; g_iCount++)
            {
                if((int)PARPHDR->sour_addr[g_iCount] < 16)//��ʾip
                    cout << "0";
                cout << hex << (int)PARPHDR->sour_addr[g_iCount]; //��ʾmac
                if(g_iCount != 5)
                    cout << "-";
            }
            //for(int i = 0; i < 6; i++)
            //{
            //    if((int)PARPHDR->sour_addr[i] < 16)//��ʾip
            //        cout << "0";
            //    cout << hex << (int)PARPHDR->sour_addr[i]; //��ʾmac
            //    if(i != 5)
            //        cout << "-";
            //}

            cout << endl;
        }
    }
}

void GetMACaddress(void)
{
    unsigned char MACData[8];						// Allocate data structure for MAC (6 bytes needed)

    WKSTA_TRANSPORT_INFO_0 *pwkti;					// Allocate data structure for Netbios
    DWORD dwEntriesRead;
    DWORD dwTotalEntries;
    BYTE *pbBuffer;

	//����������п��õ����������Ѿ�����������ʱ�����ñ��������ܳɹ��������ȡ�����κ���Ϣ
	//ͨ�� NetBIOS��ö�ٺ�����ȡMAC��ַ
    // Get MAC address via NetBios's enumerate function
    NET_API_STATUS dwStatus = NetWkstaTransportEnum(
                                  NULL,						// [in]  server name ����������0ָ����
                                  0,							// [in]  data structure to return0ָ��������ָ��WKSTA_TRANSPORT_INFO_0�ṹ��ָ��
								  //����_WKSTA_TRANSPORT_INFO_0��¼����Ļ��������д˺������з��䣬��ʹ�����Ҫ�����涨���NetApiBufferFree�����ͷ��ڴ�
                                  &pbBuffer,					// [out] pointer to buffer
								  MAX_PREFERRED_LENGTH,		// [in]  maximum length��������󳤶ȣ��������涨���MAX_PREFERRED_LENGTH��������
                                  &dwEntriesRead,				// [out] counter of elements actually enumerated ���ڼ�¼ʵ��Ԫ�ظ���
                                  &dwTotalEntries,			// [out] total number of elements that could be enumerated
								  NULL);						// [in/out] resume handle //�ָ����

    assert(dwStatus == NERR_Success);

    pwkti = (WKSTA_TRANSPORT_INFO_0 *)pbBuffer;		// type cast the buffer

    for(DWORD i = 1; i < dwEntriesRead; i++)			// first address is 00000000, skip it
    {
        // enumerate MACs and print
        swscanf((wchar_t *)pwkti[i].wkti0_transport_address, L"%2hx%2hx%2hx%2hx%2hx%2hx",
                &MACData[0], &MACData[1], &MACData[2], &MACData[3], &MACData[4], &MACData[5]);
        printf("mac: %02X-%02X-%02X-%02X-%02X-%02X\n",
               MACData[0], MACData[1], MACData[2], MACData[3], MACData[4], MACData[5]);
        for(int i = 0; i < 6; i++)
            tmp_sour_addr[i] = (int)MACData[i];
    }

	//�ͷ�NetWkstaTransportEnum����������ڴ�
    // Release pbBuffer allocated by above function
    dwStatus = NetApiBufferFree(pbBuffer);
    assert(dwStatus == NERR_Success);
}