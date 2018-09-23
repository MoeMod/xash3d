#include <SDL.h>
#include <Windows.h>

typedef void(*pfnChangeGame)(const char *progname);
typedef int(*pfnInit)(int argc, char **argv, const char *progname, int bChangeGame, pfnChangeGame func);

int main(int argc, char **argv)
{
	SDL_DisplayMode mode;
	SDL_Window * window = NULL;
	SDL_Renderer * renderer = NULL;
	SDL_Event evt;

	/*if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		return 1;
	}

	if (SDL_GetCurrentDisplayMode(0, &mode) != 0) {
		return 1;
	}

	if (SDL_CreateWindowAndRenderer(mode.w, mode.h, SDL_WINDOW_FULLSCREEN, &window, &renderer) != 0) {
		return 1;
	}

	while (1) {
		while (SDL_PollEvent(&evt)) {
		}

		SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
		SDL_RenderClear(renderer);
		SDL_RenderPresent(renderer);
	}*/

	HMODULE hEngine = LoadPackagedLibrary(L"xash_sdl.dll", 0);
	pfnInit f = (pfnInit)GetProcAddress(hEngine, "Host_Main");
	f(argc, argv, "csbtem", 0, NULL);

	return 0;
}