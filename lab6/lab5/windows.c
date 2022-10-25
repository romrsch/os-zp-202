#include <windows.h>
void main( void )
{
STARTUPINFO si;
PROCESS_INFORMATION pi;
//char* cmdLine="cmd /C dir";
//Задание процесса с использованием командной строки
    ZeroMemory( &si, sizeof(si) );
//Инициализация si нулями
    si.cb = sizeof(si);
// Инициализация первого поля структуры STARTUPINFO
    ZeroMemory( &pi, sizeof(pi) );
//Инициализация pi нулями

// Запускается дочерний процесс
if( !CreateProcess(
"C:\\Windows\\notepad.exe", //Исполняемый модуль
NULL,                       //cmdLine, // Командная строка не используется
NULL,                       // Дескриптор процесса не наследуется
NULL,                       // Дескриптор потока не наследуется
FALSE,
// Открытые дескрипторы родительского процесса не наследуется
CREATE_NO_WINDOW,
// Не создавать окна (консольного окна)
NULL,
// Используются переменные окружения родителя
NULL, // Используется текущая директория родителя
&si, // Указатель на структуру STARTUPINFO
&pi )
// Указатель на структуру PROCESS_INFORMATION
) {
printf("System error code: %i\n",GetLastError());
}
//Ожидание окончания дочернего процесса
WaitForSingleObject( pi.hProcess, INFINITE );
// Закрытие дескрипторов процесса и начального потока
CloseHandle( pi.hProcess );
CloseHandle( pi.hThread );
}
