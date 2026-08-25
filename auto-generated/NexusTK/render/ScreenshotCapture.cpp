// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000ND
// Source by-file doc: by-file/ScreenshotCapture.md
// UID:0000VF | by-item/ScreenshotProofPacket_00558240.md | Completion:92 | Confidence:94
static void __stdcall SendScreenshotProofPacket(FILE *stream);

// UID:0001G8 | by-memory/0x00557840-0x00557a96.ScreenshotJpegCapturePath.md | Completion:91 | Confidence:92
void ScreenPane::SaveScreenshotJPG()
{
    wchar_t documents[MAX_PATH];
    wchar_t nexusDirectory[MAX_PATH];
    wchar_t screenshotDirectory[MAX_PATH];
    wchar_t fileName[256];
    wchar_t fullPath[MAX_PATH];
    wchar_t statusText[120];

    if (SHGetFolderPathW(NULL, CSIDL_PERSONAL, NULL, 0, documents) != S_OK)
        return;

    swprintf_s(nexusDirectory, L"%s\\NexusTK", documents);
    if (!g_pfnCreateDirectoryW(nexusDirectory, NULL) && GetLastError() != ERROR_ALREADY_EXISTS)
        return;

    swprintf_s(screenshotDirectory, L"%s\\NexusTK\\ScreenShots", documents);
    if (!g_pfnCreateDirectoryW(screenshotDirectory, NULL) && GetLastError() != ERROR_ALREADY_EXISTS)
        return;

    __time64_t now = _time64(NULL);
    tm localTime;
    _localtime64_s(&localTime, &now);
    swprintf_s(fileName, L"TK_%04d%02d%02d%02d%02d%02d.jpg",
        localTime.tm_year + 1900, localTime.tm_mon + 1, localTime.tm_mday,
        localTime.tm_hour, localTime.tm_min, localTime.tm_sec);
    swprintf_s(fullPath, L"%s\\%s", screenshotDirectory, fileName);

    FILE *output = g_pfnWideOpenFile(fullPath, L"wb");
    if (output == NULL)
        return;

    LPDIRECTDRAWSURFACE savedSurface = m_ddSurface;
    m_ddSurface = m_renderSurface;
    UpdateSurfaceInfo();
    if (g_activeBrowserControlPane != NULL)
        g_activeBrowserControlPane->BlitBrowserSurfaceToRenderTarget(m_ddSurface);

    WriteJpegFileFromRgb565Surface(
        static_cast<unsigned short *>(m_surfaceContext.pixelData),
        g_screenWidth, g_screenHeight, g_surfaceUsesRgb565Pixels, output);
    fclose(output);

    EndPaint();
    m_ddSurface = savedSurface;

    if (g_pChattingDisplayPane != NULL) {
        swprintf_s(statusText,
            L"Screen Captured. 'MyDocuments\\NexusTK\\ScreenShots\\%s'", fileName);
        unsigned char savedModifierState;
        g_pEventMan->GetModifierState(&savedModifierState);
        g_pEventMan->m_modifierState = 0;
        g_pChattingDisplayPane->AddChattingMessage(statusText, 0x8f, 1, 0, 0, 0);
        g_pEventMan->m_modifierState = savedModifierState;
    }

    FILE *proofInput = g_pfnWideOpenFile(fullPath, L"rb");
    SendScreenshotProofPacket(proofInput);
    fclose(proofInput);
}

// UID:0004WM | by-memory/0x00557aa0-0x00557e73.ScreenPaneSaveScreenshotBMP.md | Completion:92 | Confidence:94
void ScreenPane::SaveScreenshotBMP()
{
    wchar_t documents[MAX_PATH];
    wchar_t nexusDirectory[MAX_PATH];
    wchar_t screenshotDirectory[MAX_PATH];
    wchar_t fileName[256];
    wchar_t fullPath[MAX_PATH];
    wchar_t statusText[120];

    if (SHGetFolderPathW(NULL, CSIDL_PERSONAL, NULL, 0, documents) != S_OK)
        return;

    swprintf_s(nexusDirectory, L"%s\\NexusTK", documents);
    if (!g_pfnCreateDirectoryW(nexusDirectory, NULL) && GetLastError() != ERROR_ALREADY_EXISTS)
        return;

    swprintf_s(screenshotDirectory, L"%s\\NexusTK\\ScreenShots", documents);
    if (!g_pfnCreateDirectoryW(screenshotDirectory, NULL) && GetLastError() != ERROR_ALREADY_EXISTS)
        return;

    __time64_t now = _time64(NULL);
    tm localTime;
    _localtime64_s(&localTime, &now);
    swprintf_s(fileName, L"TK_%04d%02d%02d%02d%02d%02d.bmp",
        localTime.tm_year + 1900, localTime.tm_mon + 1, localTime.tm_mday,
        localTime.tm_hour, localTime.tm_min, localTime.tm_sec);
    swprintf_s(fullPath, L"%s\\%s", screenshotDirectory, fileName);

    FILE *output = g_pfnWideOpenFile(fullPath, L"wb");
    if (output == NULL)
        return;

    BITMAPFILEHEADER fileHeader;
    fileHeader.bfType = 0x4d42;
    fileHeader.bfSize = 54 + 2 * g_screenWidth * g_screenHeight;
    fileHeader.bfReserved1 = 0;
    fileHeader.bfReserved2 = 0;
    fileHeader.bfOffBits = 54;
    fwrite(&fileHeader, sizeof(fileHeader), 1, output);

    BITMAPINFOHEADER infoHeader;
    memset(&infoHeader, 0, sizeof(infoHeader));
    infoHeader.biSize = sizeof(infoHeader);
    infoHeader.biWidth = g_screenWidth;
    infoHeader.biHeight = g_screenHeight;
    infoHeader.biPlanes = 1;
    infoHeader.biBitCount = 16;
    fwrite(&infoHeader, sizeof(infoHeader), 1, output);

    LPDIRECTDRAWSURFACE savedSurface = m_ddSurface;
    m_ddSurface = m_renderSurface;
    UpdateSurfaceInfo();
    if (g_activeBrowserControlPane != NULL)
        g_activeBrowserControlPane->BlitBrowserSurfaceToRenderTarget(m_ddSurface);

    const int width = m_surfaceContext.bounds.right - m_surfaceContext.bounds.left;
    const int height = m_surfaceContext.bounds.bottom - m_surfaceContext.bounds.top;
    unsigned short *row = static_cast<unsigned short *>(m_surfaceContext.pixelData)
        + m_surfaceContext.rowStridePixels * (height - 1);

    for (int y = 0; y < height; ++y) {
        if (g_surfaceUsesRgb565Pixels) {
            for (int x = 0; x < m_surfaceContext.rowStridePixels; ++x) {
                unsigned short pixel = row[x];
                unsigned short bmpPixel = static_cast<unsigned short>(
                    (pixel & 0x001f) | ((pixel >> 1) & 0x7fe0));
                fwrite(&bmpPixel, sizeof(bmpPixel), 1, output);
            }
        } else {
            fwrite(row, sizeof(unsigned short), width, output);
        }
        row -= m_surfaceContext.rowStridePixels;
    }

    fclose(output);
    EndPaint();
    m_ddSurface = savedSurface;

    if (g_pChattingDisplayPane != NULL) {
        swprintf_s(statusText,
            L"Screen Captured. 'MyDocuments\\NexusTK\\ScreenShots\\%s'", fileName);
        unsigned char savedModifierState;
        g_pEventMan->GetModifierState(&savedModifierState);
        g_pEventMan->m_modifierState = 0;
        g_pChattingDisplayPane->AddChattingMessage(statusText, 0x8f, 1, 0, 0, 0);
        g_pEventMan->m_modifierState = savedModifierState;
    }

    FILE *proofInput = g_pfnWideOpenFile(fullPath, L"rb");
    SendScreenshotProofPacket(proofInput);
    fclose(proofInput);
}

// UID:0004WN | by-memory/0x00557e80-0x00558239.ScreenPaneSaveScreenshotPNG.md | Completion:92 | Confidence:94
void ScreenPane::SaveScreenshotPNG()
{
    wchar_t documents[MAX_PATH];
    wchar_t nexusDirectory[MAX_PATH];
    wchar_t screenshotDirectory[MAX_PATH];
    wchar_t fileName[256];
    wchar_t fullPath[MAX_PATH];
    wchar_t statusText[120];
    char encodedPath[256];

    if (SHGetFolderPathW(NULL, CSIDL_PERSONAL, NULL, 0, documents) != S_OK)
        return;

    swprintf_s(nexusDirectory, L"%s\\NexusTK", documents);
    if (!g_pfnCreateDirectoryW(nexusDirectory, NULL) && GetLastError() != ERROR_ALREADY_EXISTS)
        return;

    swprintf_s(screenshotDirectory, L"%s\\NexusTK\\ScreenShots", documents);
    if (!g_pfnCreateDirectoryW(screenshotDirectory, NULL) && GetLastError() != ERROR_ALREADY_EXISTS)
        return;

    __time64_t now = _time64(NULL);
    tm localTime;
    _localtime64_s(&localTime, &now);
    swprintf_s(fileName, L"TK_%04d%02d%02d%02d%02d%02d.png",
        localTime.tm_year + 1900, localTime.tm_mon + 1, localTime.tm_mday,
        localTime.tm_hour, localTime.tm_min, localTime.tm_sec);
    swprintf_s(fullPath, L"%s\\%s", screenshotDirectory, fileName);
    WideCharToMultiByte(CP_ACP, 0, fullPath, -1, encodedPath,
        sizeof(encodedPath), NULL, NULL);

    unsigned char *rgba = static_cast<unsigned char *>(
        malloc(4 * g_screenWidth * g_screenHeight));

    LPDIRECTDRAWSURFACE savedSurface = m_ddSurface;
    m_ddSurface = m_renderSurface;
    UpdateSurfaceInfo();
    if (g_activeBrowserControlPane != NULL)
        g_activeBrowserControlPane->BlitBrowserSurfaceToRenderTarget(m_ddSurface);

    const int width = m_surfaceContext.bounds.right - m_surfaceContext.bounds.left;
    const int height = m_surfaceContext.bounds.bottom - m_surfaceContext.bounds.top;
    const unsigned short *source =
        static_cast<const unsigned short *>(m_surfaceContext.pixelData);
    unsigned char *destination = rgba;

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            const unsigned short pixel = source[x];
            if (g_surfaceUsesRgb565Pixels) {
                destination[0] = static_cast<unsigned char>((pixel >> 11) << 3);
                destination[1] = static_cast<unsigned char>((pixel >> 6) << 3);
            } else {
                destination[0] = static_cast<unsigned char>((pixel >> 10) << 3);
                destination[1] = static_cast<unsigned char>((pixel >> 5) << 3);
            }
            destination[2] = static_cast<unsigned char>(pixel << 3);
            destination[3] = 0xff;
            destination += 4;
        }
        source += m_surfaceContext.rowStridePixels;
    }

    EndPaint();
    m_ddSurface = savedSurface;
    lodepng_encode32_file(encodedPath, rgba, width, height);
    free(rgba);

    if (g_pChattingDisplayPane != NULL) {
        swprintf_s(statusText,
            L"Screen Captured. 'MyDocuments\\NexusTK\\ScreenShots\\%s'", fileName);
        unsigned char savedModifierState;
        g_pEventMan->GetModifierState(&savedModifierState);
        g_pEventMan->m_modifierState = 0;
        g_pChattingDisplayPane->AddChattingMessage(statusText, 0x8f, 1, 0, 0, 0);
        g_pEventMan->m_modifierState = savedModifierState;
    }

    FILE *proofInput = g_pfnWideOpenFile(fullPath, L"rb");
    SendScreenshotProofPacket(proofInput);
    fclose(proofInput);
}

// UID:0004WO | by-memory/0x00558240-0x00558391.SendScreenshotProofPacket.md | Completion:93 | Confidence:94
static void __stdcall SendScreenshotProofPacket(FILE *stream)
{
    char proofMask[36] = "w-pu6a4Es*5pA@eg+tetayAp6us6EcrE";
    char *maskedDigest = Md5StreamHex(stream);

    for (int i = 0; i < 32; ++i)
        maskedDigest[i] ^= proofMask[i];

    unsigned char packet[128];
    PacketBufferWriteUInt8(0x83, packet);
    memmove(packet + 1, maskedDigest, 13);

    packet[14] = static_cast<unsigned char>((rand() % 10) - 26);
    for (int i = 1; i < 16; ++i)
        packet[14 + i] = static_cast<unsigned char>(rand() % 255);

    memmove(packet + 30, maskedDigest + 13, 19);
    packet[49] = 0;
    g_packetSender->QueueAndSendPacket(packet, 49);
    free(maskedDigest);
}
