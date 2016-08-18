#include <Windows.h>
#include <cmath>

DWORD WINAPI run(LPVOID pM) {
	const int INTERVAL = 1000;
	const int FREQUENCY = 3200000000;
	long long origin = GetTickCount() / FREQUENCY;
	double x = 0.0;
	while (true) {
		long long startTime = GetTickCount();
		double busytime = INTERVAL / 2 * sin(x) + INTERVAL / 2;
		double idletime = INTERVAL - busytime;
		while ((GetTickCount() - startTime) < busytime);
		Sleep(idletime);
		x += 0.05;
	}
	return 0;
}

int main()
{
	HANDLE cpu1 = CreateThread(NULL, 0, run, NULL, 0, NULL);
	HANDLE cpu2 = CreateThread(NULL, 0, run, NULL, 0, NULL);
	HANDLE cpu3 = CreateThread(NULL, 0, run, NULL, 0, NULL);

	SetThreadAffinityMask(GetCurrentThread(), 0x00000001);
	SetThreadAffinityMask(cpu1, 0x00000002);
	SetThreadAffinityMask(cpu2, 0x00000004);
	SetThreadAffinityMask(cpu3, 0x00000008);

	run(NULL);
}