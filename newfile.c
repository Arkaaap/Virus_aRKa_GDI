void create_File() {
    const char* fileName = "Read_This_Sucker.txt";
    const char* message = "Hi! This is the message from creator Arka!! If you really want to destroy your PC, it's going to happen. The data will be lost, and your PC will be unbootable!!";
    
    // Create or open the file
    HANDLE hnd = CreateFileA(
        fileName,                     // File name
        GENERIC_WRITE,                // Write access
        0,                            // No sharing
        NULL,                         // Default security
        CREATE_ALWAYS,                // Create a new file, always
        FILE_ATTRIBUTE_NORMAL,        // Normal file
        NULL                          // No template
    );

    if (hnd == INVALID_HANDLE_VALUE) {
        MessageBox(NULL, TEXT("No file Created !!"), NULL, MB_OK);
        return  ;
    }

    // Write the message to the file
    DWORD bytesWritten = 0;
    WriteFile(hnd, message, strlen(message), &bytesWritten, NULL);
    
    CloseHandle(hnd);
    return ;
}



void open_file() {
    const char* fileName = "Read_This_Sucker.txt";
    HANDLE hFile = CreateFileA(
        fileName,                     // File name
        GENERIC_READ,                 // Read access
        FILE_SHARE_READ,             // Share for reading
        NULL,                         // Default security
        OPEN_EXISTING,                // Open existing file
        FILE_ATTRIBUTE_NORMAL,        // Normal file
        NULL                          // No template
    );

    if (hFile == INVALID_HANDLE_VALUE) {
        MessageBox(NULL, TEXT("Error opening file!"), NULL, MB_OK);
        return  ;
    }

    // Read file contents
    DWORD bytesRead = 0;
    char buffer[512]; // Buffer to store file content
    ZeroMemory(buffer, sizeof(buffer));

    if (ReadFile(hFile, buffer, sizeof(buffer) - 1, &bytesRead, NULL)) {
        buffer[bytesRead] = '\0'; // Null-terminate the string
        std::cout << "File Contents:\n" << buffer << std::endl;
    } else {
        MessageBox(NULL, TEXT("Error reading file!"), NULL, MB_OK);
    }

    CloseHandle(hFile); // Always close the handle
    return ;
}




DWORD WINAPI shellexec(LPVOID Lparam)
{
ShellExecute(NULL,"open","Read_This_Sucker.txt",NULL,NULL,SW_SHOWNORMAL);

//ShellExecute(NULL,"open","https://www.bing.com/search?pglt=2083&q=have+you+found+the+marijuana+I+sent+you%3F&cvid=2c349d4acbcc4059b1af8ad755e72455&gs_lcrp=EgZjaHJvbWUyBggAEEUYOTIGCAEQABhAMgYIAhAAGEAyBggDEAAYQDIGCAQQABhAMgYIBRAAGEDSAQkxNzI5M2owajGoAgCwAgA&FORM=ANNTA1&PC=U531",NULL,NULL,SW_SHOWMAXIMIZED);
Sleep(10000);
return -1;
}
