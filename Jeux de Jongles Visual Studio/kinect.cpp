#include "kinect.h"
#include <qDebug>

kinect::kinect(void)
{
		tetex=400;
			HANDLE        m_hThNuiProcess;
		HANDLE        m_hEvNuiProcessStop;
	m_hThNuiProcess     = NULL;
	m_hEvNuiProcessStop = NULL;

	m_hNextDepthFrameEvent = CreateEvent( NULL, TRUE, FALSE, NULL );
	m_hNextVideoFrameEvent = CreateEvent( NULL, TRUE, FALSE, NULL );
	m_hNextSkeletonEvent = CreateEvent( NULL, TRUE, FALSE, NULL );

hr = NuiInitialize(
	NUI_INITIALIZE_FLAG_USES_DEPTH_AND_PLAYER_INDEX |
	NUI_INITIALIZE_FLAG_USES_SKELETON |
	NUI_INITIALIZE_FLAG_USES_COLOR);

hr = NuiSkeletonTrackingEnable( m_hNextSkeletonEvent, 0 );

hr = NuiImageStreamOpen(     NUI_IMAGE_TYPE_COLOR,
							NUI_IMAGE_RESOLUTION_640x480,
							0,
							2,
							m_hNextVideoFrameEvent,
							&m_pVideoStreamHandle ); 
if (FAILED(hr)) {
        qDebug("Unable to open stream.");
        return;
    }

hr = NuiImageStreamOpen(     NUI_IMAGE_TYPE_DEPTH_AND_PLAYER_INDEX,
							NUI_IMAGE_RESOLUTION_320x240,
							0,
							2,
							m_hNextDepthFrameEvent,
							&m_pDepthStreamHandle );

if (FAILED(hr)) {
        qDebug("Unable to open stream.");
        return;
    }

	m_hEvNuiProcessStop = CreateEvent(NULL,FALSE,FALSE,NULL);
	m_hThNuiProcess = CreateThread(NULL,0,Nui_ProcessThread,this,0,NULL);


}

DWORD WINAPI kinect::Nui_ProcessThread(LPVOID pParam) {
	kinect * pthis=(kinect *) pParam;
	return pthis->Nui_ProcessThread();
}


DWORD WINAPI kinect::Nui_ProcessThread() {
	HANDLE hEvents[3];
	int    nEventIdx,t,dt;

	// Configure events to be listened on
	//hEvents[0]= m_hEvNuiProcessStop;
	hEvents[0]= m_hNextDepthFrameEvent;
	hEvents[1]= m_hNextVideoFrameEvent;
	hEvents[2]= m_hNextSkeletonEvent;

#pragma warning(push)
#pragma warning(disable: 4127) // conditional expression is constant

	// Main thread loop
	while(1)
	{
		// Wait for an event to be signalled
		nEventIdx=WaitForMultipleObjects(sizeof(hEvents)/sizeof(hEvents[0]),hEvents,FALSE,100);

		// If the stop event, stop looping and exit
		//if(nEventIdx==0)
			//break;  


				////////////////////////////////////////////////////////////////////////
				////////////////////////////////////////////////////////////////////////
				////////////////////////////////////////////////////////////////////////

		// Problème à partir d'ici 
				////////////////////////////////////////////////////////////////////////
				////////////////////////////////////////////////////////////////////////
				////////////////////////////////////////////////////////////////////////


		// Process signal events
		switch(nEventIdx)
		{
		case 0:
			this->Nui_GotDepthAlert();
			break;

		case 1:
			this->Nui_GotVideoAlert();
			break;

		case 2:
			this->Nui_GotSkeletonAlert();
			break;
		}
	}

#pragma warning(pop)

	return (0);
}

kinect::~kinect(void)
{
}

void kinect::Nui_GotSkeletonAlert() {

	NUI_SKELETON_FRAME SkeletonFrame;

	bool bFoundSkeleton = false;

	if( SUCCEEDED( NuiSkeletonGetNextFrame(0, &SkeletonFrame) ) )			// Si squelette détecté
	{
		for( int i=1; i < NUI_SKELETON_COUNT; i++)											// Pour tous les squelettes détectés
		{
			if (SkeletonFrame.SkeletonData[i].eTrackingState == NUI_SKELETON_TRACKED)		// Si le squelette est tracked (visible, => validé)
			{
				bFoundSkeleton = true;														// Squelette validé
				tetex=SkeletonFrame.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_HEAD].x;
				tetex = 500 + 1000*tetex;
				qDebug()<<tetex;
			} else {				

			}
		}
	}

	if( !bFoundSkeleton )		// Si aucun squelette, sortie
	{
		return;
	}

	// Affine les points du squelette
	NuiTransformSmooth(&SkeletonFrame, NULL);

	// Reset du timer après détection squelette
	m_bScreenBlanked = false;		// Ecran vide : false
	m_LastSkeletonFoundTime = -1;	// Reset timer

	bool bBlank = true;				// Squelette visible
	for (int i=1; i < NUI_SKELETON_COUNT; i++)			// Pour tous les squelettes
	{
		// Si squelette traqué mais centre épaules non visible
		if (SkeletonFrame.SkeletonData[i].eTrackingState == NUI_SKELETON_TRACKED &&
			SkeletonFrame.SkeletonData[i].eSkeletonPositionTrackingState[NUI_SKELETON_POSITION_SHOULDER_CENTER] != NUI_SKELETON_POSITION_NOT_TRACKED)
		{
			bBlank = false;		// Squelette non visible
		}
	}

}

float kinect::return_tete(){
			return (tetex);		// Squelette non visible
		}


void kinect::Nui_GotVideoAlert( ) {
	const NUI_IMAGE_FRAME * pImageFrame = NULL;

	HRESULT hr = NuiImageStreamGetNextFrame(
		m_pVideoStreamHandle,
		0,
		&pImageFrame );
	if( FAILED( hr ) )
	{
		return;
	}
		NuiImageStreamReleaseFrame( m_pVideoStreamHandle, pImageFrame );
	}

void kinect::Nui_GotDepthAlert( ) {
	const NUI_IMAGE_FRAME * pImageFrame = NULL;

	HRESULT hr = NuiImageStreamGetNextFrame(
		m_pDepthStreamHandle,
		0,
		&pImageFrame );

	if( FAILED( hr ) )
	{
		return;
	}
	
	NuiImageStreamReleaseFrame( m_pDepthStreamHandle, pImageFrame );
	}