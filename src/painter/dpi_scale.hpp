#include <d2d1.h>

class DPIScale
{
    static float scale;

public:
    static void Initialize(HWND hwnd)
    {
        UINT dpi = GetDpiForWindow(hwnd);
        scale = 1.0f * dpi / USER_DEFAULT_SCREEN_DPI;
    }

    template <typename T>
    static D2D1_POINT_2F PixelsToDips(T x, T y)
    {
        return D2D1::Point2F(static_cast<float>(x) / scale, static_cast<float>(y) / scale);
    }

    template <typename T>
    static float PixelsToDipsX(T x)
    {
        return static_cast<float>(x) / scale;
    }

    template <typename T>
    static float PixelsToDipsY(T y)
    {
        return static_cast<float>(y) / scale;
    }
};

float DPIScale::scale = 1.0f;