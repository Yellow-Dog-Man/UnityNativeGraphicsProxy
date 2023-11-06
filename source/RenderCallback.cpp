#include "RenderAPI.h"
#include "PlatformBase.h"

typedef void(*UpdateEvent)();

UpdateEvent _update;

extern "C" void UNITY_INTERFACE_EXPORT UNITY_INTERFACE_API SetUpdateCallback(UpdateEvent callback)
{
    _update = callback;
}

static void UNITY_INTERFACE_API OnRenderEvent(int eventID)
{
    _update();
}

extern "C" UnityRenderingEvent UNITY_INTERFACE_EXPORT UNITY_INTERFACE_API GetRenderEventFunc()
{
    return OnRenderEvent;
}
