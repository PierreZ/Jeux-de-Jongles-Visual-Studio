#ifndef KINECT_H
#define KINECT_H

#include <Windows.h>
#include<NuiApi.h>

class kinect
{
public:
	kinect(void);
	~kinect(void);
	float return_tete();
private:
	float tetex;
		static DWORD WINAPI     Nui_ProcessThread(LPVOID pParam);
		DWORD WINAPI            Nui_ProcessThread();
HANDLE        m_hEvNuiProcessStop;
		void Nui_GotSkeletonAlert();
		HRESULT		  hr;
		HANDLE        m_hNextDepthFrameEvent;
		HANDLE        m_hNextVideoFrameEvent;
		HANDLE        m_hNextSkeletonEvent;				// Evènement de détection squelette
		HANDLE        m_pDepthStreamHandle;
		HANDLE        m_pVideoStreamHandle;

				bool		  m_bScreenBlanked;					// true si squelette(s) à l'écran
		int			  m_LastSkeletonFoundTime;	
};

#endif