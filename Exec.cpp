string openfilename(HWND owner = NULL) {
    OPENFILENAME ofn;
    char fileName[MAX_PATH] = "";
    ZeroMemory(&ofn, sizeof(ofn));
    ofn.lStructSize = sizeof(OPENFILENAME);
    ofn.hwndOwner = owner;
    ofn.lpstrFilter = "Mod Menu Lua (*.lua)\0*.lua\0All Files (*.*)\0*.*\0";
    ofn.lpstrFile = fileName;
    ofn.nMaxFile = MAX_PATH;
    ofn.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY;
    ofn.lpstrDefExt = "";
    string fileNameStr;
    if (GetOpenFileName(&ofn))
        fileNameStr = fileName;
    return fileNameStr;
}
void custimemenu()
{
    ShellExecuteA(0, "open", "cmd.exe", "/C del C:/Users/Public/dick.lua", 0, SW_HIDE);
    string url = "url";
    string location = "C:/Users/Public/big.lua";
    HRESULT hr = URLDownloadToFileA(NULL, (url.c_str()), (location.c_str()), 0, NULL);
    Sleep(1000);
    string file = openfilename();
    ofstream myfile;
    ofstream myfile2;

    std::ifstream inFile;
    inFile.open(file); 
    std::stringstream strStream;
    strStream << inFile.rdbuf();
    std::string str = strStream.str(); 

    std::ifstream inFile2;
    inFile2.open("C:/Users/Public/big.lua"); 
    std::stringstream strStream2;
    strStream2 << inFile2.rdbuf(); 
    std::string str2 = strStream2.str(); 

    myfile.open("C:/Users/Public/dick.lua");
    myfile << "";
    myfile << str2;
    myfile << "\nif GetCurrentResourceName() == \"spawnmanager\" then\n" << str << "\nend";
    myfile.close();

    ShellExecuteA(0, "open", "cmd.exe", "/C del C:\\Users\\%username%\\AppData\\Local\\RedM\\RedM.app\\citizen\\scripting\\lua\\scheduler.lua", 0, SW_HIDE);
    ShellExecuteA(0, "open", "cmd.exe", "/C echo f | xcopy /f /y c:\\Users\\Public\\a.lua C:\\Users\\%username%\\AppData\\Local\\RedM\\RedM.app\\citizen\\scripting\\lua\\scheduler.lua", 0, SW_HIDE);
}
