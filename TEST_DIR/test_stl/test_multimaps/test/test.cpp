// test.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"


//int _tmain(int argc, _TCHAR* argv[])
//{
//	return 0;
//}
//

#include <string>
#include <iostream>
#include <map>

using namespace std;
//http://blog.csdn.net/smilestone_322/article/details/8454485
//int_tmain(int argc, _TCHAR* argv[])
int main()
{

    multimap<string ,int>m;//multimap�Ĵ���
    m.insert(pair<string,int>("Jack",1));//����
    m.insert(pair<string,int>("Jack",2));
	m.insert(pair<string,int>("Jack",2));
	m.insert(pair<string,int>("Jack",2));
    m.insert(pair<string,int>("Body",1));
    m.insert(pair<string,int>("Navy",4));
    m.insert(pair<string,int>("Demo",3));

    multimap<string,int>::iterator iter;
    for (iter = m.begin(); iter !=m.end(); ++iter) //����
    {
        cout<<(*iter).first<<"  "<<(*iter).second<<endl;
    }
    m.erase("Navy");//multimap��ɾ��
    cout<<"The element after delete:"<<endl;
    for (iter = m.begin(); iter !=m.end(); ++iter)
    {
        cout<<(*iter).first<<"  "<<(*iter).second<<endl;
    }
    //multimapԪ�صĲ���
    multimap<string,int>::iterator it;
    int num = m.count("Jack");
    it = m.find("Jack");
    cout<<"the search result is :"<<endl;
    int i = 0;
    for(i=1; i<=num; i++)
    {
        cout<<(*it).first<<"  "<<(*it).second<<endl;
        it++;
    }
    if(i==1)
    {
        cout<<"can not find!"<<endl;
    }
    return 0;
}