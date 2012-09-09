; Script generated by the Inno Setup Script Wizard.
; SEE THE DOCUMENTATION FOR DETAILS ON CREATING INNO SETUP SCRIPT FILES!

[Setup]
; NOTE: The value of AppId uniquely identifies this application.
; Do not use the same AppId value in installers for other applications.
; (To generate a new GUID, click Tools | Generate GUID inside the IDE.)
AppId={{DAD20769-75D8-4C1D-80E3-D545563FE9EF}
AppName=QTTabBar
AppVerName=QTTabBar 1.5.0.0 Alpha 4
AppPublisher=Quizo and Paul Accisano
AppPublisherURL=http://qttabbar.sourceforge.net/
AppSupportURL=http://qttabbar.sourceforge.net/
AppUpdatesURL=http://qttabbar.sourceforge.net/
DefaultDirName={pf}\QTTabBar
DefaultGroupName=QTTabBar
AllowNoIcons=yes
LicenseFile=..\LICENSE.txt
OutputBaseFilename=setup
Compression=lzma
SolidCompression=yes
PrivilegesRequired=admin
ArchitecturesInstallIn64BitMode=x64

[Languages]
Name: "english"; MessagesFile: "compiler:Default.isl"

[Files]
Source: "..\BandObjectLib\bin\Release\Interop.SHDocVw.dll"; DestDir: "{app}"; Flags: ignoreversion gacinstall; StrongAssemblyName: "Interop.SHDocVw, Version=1.1.0.0, Culture=neutral, PublicKeyToken=973461f1cd23d8eb"; AfterInstall: NGen('Interop.SHDocVw, Version=1.1.0.0, Culture=neutral, PublicKeyToken=973461f1cd23d8eb');
Source: "..\BandObjectLib\bin\Release\BandObjectLib.dll"; DestDir: "{app}"; Flags: ignoreversion gacinstall; StrongAssemblyName: "BandObjectLib, Version=1.0.0.0, Culture=neutral, PublicKeyToken=973461f1cd23d8eb"; AfterInstall: NGen('BandObjectLib, Version=1.0.0.0, Culture=neutral, PublicKeyToken=973461f1cd23d8eb');
Source: "..\QTPluginLib\bin\Release\QTPluginLib.dll"; DestDir: "{app}"; Flags: ignoreversion gacinstall; StrongAssemblyName: "QTPluginLib, Version=1.0.0.0, Culture=neutral, PublicKeyToken=973461f1cd23d8eb"; AfterInstall: NGen('QTPluginLib, Version=1.0.0.0, Culture=neutral, PublicKeyToken=973461f1cd23d8eb');
Source: "..\QTTabBar\bin\Release\QTTabBar.dll"; DestDir: "{app}"; Flags: ignoreversion gacinstall; StrongAssemblyName: "QTTabBar, Version=1.0.0.0, Culture=neutral, PublicKeyToken=973461f1cd23d8eb"; AfterInstall: RegAndNGen('QTTabBar, Version=1.0.0.0, Culture=neutral, PublicKeyToken=973461f1cd23d8eb');
Source: "Restart Explorer.bat"; DestDir: "{tmp}"

[Run]
Filename: "{tmp}\Restart Explorer.bat"; Description: "Restart explorer immediately"; Flags: postinstall runhidden unchecked

[UninstallRun]
Filename: "{dotnet20}\ngen.exe"; Parameters: "uninstall ""Interop.SHDocVw, Version=1.1.0.0, Culture=neutral, PublicKeyToken=973461f1cd23d8eb"""; StatusMsg: "Removing native images..."; Flags: runhidden
Filename: "{dotnet20}\ngen.exe"; Parameters: "uninstall ""BandObjectLib, Version=1.0.0.0, Culture=neutral, PublicKeyToken=973461f1cd23d8eb"""; StatusMsg: "Removing native images..."; Flags: runhidden
Filename: "{dotnet20}\ngen.exe"; Parameters: "uninstall ""QTPluginLib, Version=1.0.0.0, Culture=neutral, PublicKeyToken=973461f1cd23d8eb"""; StatusMsg: "Removing native images..."; Flags: runhidden
Filename: "{dotnet20}\ngen.exe"; Parameters: "uninstall ""QTTabBar, Version=1.0.0.0, Culture=neutral, PublicKeyToken=973461f1cd23d8eb"""; StatusMsg: "Removing native images..."; Flags: runhidden
Filename: "{dotnet20}\regasm.exe"; Parameters: """{app}\QTTabBar.dll"" /unregister"; StatusMsg: "Unregistering assembly..."; Flags: runhidden

[Messages]
FinishedLabelNoIcons=Setup has finished installing [name] on your computer.  In order to use [name], you must restart Windows Explorer.  You can do this by logging off, rebooting your computer, or by checking the box below.

[Code]
function IsDotNetDetected(version: string; service: cardinal): boolean;
// Indicates whether the specified version and service pack of the .NET Framework is installed.
//
// version -- Specify one of these strings for the required .NET Framework version:
//    'v1.1.4322'     .NET Framework 1.1
//    'v2.0.50727'    .NET Framework 2.0
//    'v3.0'          .NET Framework 3.0
//    'v3.5'          .NET Framework 3.5
//    'v4\Client'     .NET Framework 4.0 Client Profile
//    'v4\Full'       .NET Framework 4.0 Full Installation
//
// service -- Specify any non-negative integer for the required service pack level:
//    0               No service packs required
//    1, 2, etc.      Service pack 1, 2, etc. required
var
    key: string;
    install, serviceCount: cardinal;
    success: boolean;
begin
    key := 'SOFTWARE\Microsoft\NET Framework Setup\NDP\' + version;
    
    // .NET 3.0 uses value InstallSuccess in subkey Setup
    if Pos('v3.0', version) = 1 then begin
        success := RegQueryDWordValue(HKLM, key + '\Setup', 'InstallSuccess', install);
    end else begin
        success := RegQueryDWordValue(HKLM, key, 'Install', install);
    end;
    
    // .NET 4.0 uses value Servicing instead of SP
    if Pos('v4', version) = 1 then begin
        success := success and RegQueryDWordValue(HKLM, key, 'Servicing', serviceCount);
    end else begin
        success := success and RegQueryDWordValue(HKLM, key, 'SP', serviceCount);
    end;
    result := success and (install = 1) and (serviceCount >= service);
end;

function InitializeSetup(): Boolean;
begin
    if not IsDotNetDetected('v2.0.50727', 0) then begin
        MsgBox('QTTabBar requires Microsoft .NET Framework 2, 3, or 3.5.'#13#13
            'Version 4 is not yet supported.  Please install one of these'#13
            'version and then re-run the QTTabBar setup program.', mbInformation, MB_OK);
        result := false;
    end else
        result := true;
end;

function Quote(t: string): string;
begin
  result := '"' + t + '"'
end;

procedure NGen(san: string);
var
  ResultCode: Integer;
begin
  if Exec(ExpandConstant('{dotnet20}\ngen.exe'), Quote(san), '', SW_HIDE,
     ewWaitUntilTerminated, ResultCode) then
  begin
    if not (ResultCode = 0) then
      MsgBox('Error generating native code.', mbError, MB_OK)
  end
  else begin
    MsgBox('Error generating native code.', mbError, MB_OK)
  end;
end;

procedure RegAndNGen(san: string);
var
  ResultCode: Integer;
begin
  if Exec(ExpandConstant('{dotnet20}\regasm.exe'), Quote(ExpandConstant(CurrentFileName)), '', SW_HIDE,
     ewWaitUntilTerminated, ResultCode) then
  begin
    if not (ResultCode = 0) then
      MsgBox('Error registering assembly.', mbError, MB_OK)
  end
  else begin
    MsgBox('Error registering assembly.', mbError, MB_OK)
  end;
  NGen(san);
end;

