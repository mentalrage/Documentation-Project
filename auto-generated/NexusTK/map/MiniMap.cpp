// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000LE
// Source by-file doc: by-file/MiniMap.md
// UID:00008B | by-class/MiniMapButtonPane.md | Completion:86 | Confidence:88
// MiniMapButtonPane class declaration is intentionally withheld: constructor,
// destructor, paint, mouse, singleton, and vtable routes are documented, but
// inherited base spellings, hover/down fields, tile-context ownership, and
// click-dispatch names are not source-quality yet.
// UID:0001AM | by-memory/0x00503620-0x00503649.MiniMapButtonPaneCleanup.md | Completion:89 | Confidence:92
MiniMapButtonPane::~MiniMapButtonPane()
{
    g_pMiniMapButtonPane = NULL;
}

// UID:00040L | by-memory/0x00503800-0x0050380b.MiniMapButtonPaneClearSingleton.md | Completion:86 | Confidence:89
void MiniMapButtonPane::ClearSingleton()
{
    g_pMiniMapButtonPane = NULL;
}



// UID:00008C | by-class/MiniMapDialog.md | Completion:86 | Confidence:89
// MiniMapDialog class declaration is intentionally withheld: the DialogPane-derived
// shell, embedded renderer, child controls, and raw no-route bodies are documented,
// but the full derived-tail layout and exact private member declarations are not
// source-quality yet.
[[No Children Attached]]

// UID:00008D | by-class/MiniMapDownloader.md | Completion:86 | Confidence:90
// MiniMapDownloader class declaration is intentionally withheld: the worker-thread
// singleton and six-function island are documented, but Thread base spelling and
// MiniMapDownloadTask field names are not source-quality yet.
[[No Children Attached]]

// UID:00008E | by-class/MiniMapImageControlPane.md | Completion:86 | Confidence:88
// MiniMapImageControlPane class declaration is intentionally withheld: constructor,
// ordinary destructor, OnPaint, and vtable routes are documented, but the ControlPane
// base spelling, image-handle type, and render-helper names are not source-quality yet.
[[No Children Attached]]

// UID:00008F | by-class/MiniMapRenderer.md | Completion:86 | Confidence:88
// MiniMapRenderer class declaration is intentionally withheld: the embedded runtime
// object and method inventory are documented, but renderer record-vector layouts,
// .mnm field names, and raw downloader-helper reachability are not source-quality yet.
[[No Children Attached]]

// UID:00008G | by-class/MiniMapSymbolControlPane.md | Completion:88 | Confidence:90
// MiniMapSymbolControlPane class declaration is intentionally withheld: method routes,
// TimerHandler-compatible vtable evidence, resources, and field candidates are documented,
// but base-subobject spelling and center-coordinate field order are not source-quality yet.
[[No Children Attached]]

// UID:0000SY | by-global/GetControlLayout_452260.md | Completion:87 | Confidence:91
// Emitted code for the recovered GetControlLayout_452260 alias is covered by [UID:0000XL][0x00452260-0x0045239a.GetControlLayout_452260](by-memory/0x00452260-0x0045239a.GetControlLayout_452260.md)
// by-memory/0x00452260-0x0045239a.GetControlLayout_452260.md, which emits the
// source-facing file-local helper GetMiniMapControlLayout.
// Do not emit a duplicate global-alias body here.

// UID:0000RN | by-global/g_pMiniMapButtonPane.md | Completion:88 | Confidence:90
MiniMapButtonPane *g_pMiniMapButtonPane = NULL;

// UID:0000RO | by-global/g_pMiniMapDownloader.md | Completion:87 | Confidence:91
MiniMapDownloader *g_pMiniMapDownloader = NULL;

// UID:0000XK | by-memory/0x00450ca0-0x0045381b.MiniMapDialog.md | Completion:88 | Confidence:89
// This MiniMapDialog aggregate is a source-family index.
// Exact child pages and documented raw no-route bodies cover the range;
// do not emit a monolithic aggregate body here.

// UID:0000XL | by-memory/0x00452260-0x0045239a.GetControlLayout_452260.md | Completion:88 | Confidence:92
static int __stdcall GetMiniMapControlLayout(short controlId, RectBounds *rectOut)
{
    switch (controlId) {
    case 0:
        return InitRectBounds(rectOut, 0, 0, 768, 768);
    case 1:
        return InitRectBounds(rectOut, 273, 18, 494, 46);
    case 2:
        return InitRectBounds(rectOut, 60, 729, 76, 745);
    case 4:
        return InitRectBounds(rectOut, 105, 729, 121, 745);
    case 6:
        return InitRectBounds(rectOut, 648, 725, 711, 749);
    case 7:
        return InitRectBounds(rectOut, 520, 730, 550, 743);
    case 8:
        return InitRectBounds(rectOut, 540, 730, 570, 743);
    case 9:
        return InitRectBounds(rectOut, 580, 730, 610, 743);
    case 10:
        return InitRectBounds(rectOut, 600, 730, 630, 743);
    default:
        return controlId;
    }
}

// UID:0000XN | by-memory/0x00453910-0x00453def.MiniMapDownloader.md | Completion:87 | Confidence:91
// This MiniMapDownloader range is a source-family index for the worker class,
// direct .mnm download helper, singleton-clear helper, and compiler destructor glue.
// Emit exact method/helper bodies only from split child pages; do not emit a
// monolithic downloader aggregate body here.

// UID:0000XO | by-memory/0x00453df0-0x004563b5.MiniMapRendererAndControls.md | Completion:88 | Confidence:90
// This MiniMap renderer/control aggregate covers image-control, renderer,
// symbol-control, renderer-local vector support, shared string-vector support,
// raw no-route downloader bytes, and compiler destructor glue.
// Emit exact method/helper bodies only from split child pages; do not emit a
// monolithic aggregate body here.

// UID:0001ZZ | by-memory/0x00457620-0x00457a5d.MiniMapFileLoaderHelpers.md | Completion:88 | Confidence:91
// This MiniMapFileLoader helper island is a source-family index for the loader
// constructor, destructor, load, payload decode, and raw no-route reset/write bodies.
// Do not emit a monolithic aggregate body here. Emit exact modeled loader bodies
// only from later split child pages after MiniMapFileLoader field/type names and
// .mnm record names are accepted. Keep the raw reset/write ranges no-code/no-route
// unless a later split/liveness pass proves an emitted source route.




// UID:00028P | by-memory/0x0067a7c4-0x0067a7c8.g_pMiniMapDialog.md | Completion:89 | Confidence:93
MiniMapDialog *g_pMiniMapDialog = NULL;

// UID:00028S | by-memory/0x0067a7d8-0x0067a7dc.g_pMiniMapDownloader.md | Completion:87 | Confidence:91
// Emitted storage for g_pMiniMapDownloader is covered by [UID:0000RO][g_pMiniMapDownloader](by-global/g_pMiniMapDownloader.md)
// by-global/g_pMiniMapDownloader.md.

// UID:0002XP | by-memory/0x0069b4b8-0x0069b4bc.g_pMiniMapButtonPane.md | Completion:87 | Confidence:90
// Emitted storage for g_pMiniMapButtonPane is covered by [UID:0000RN][g_pMiniMapButtonPane](by-global/g_pMiniMapButtonPane.md)
// by-global/g_pMiniMapButtonPane.md.

// UID:0003C0 | by-memory\0x0061e63c-0x0061e6c0.MiniMapButtonPaneVtableData.md | Completion:87 | Confidence:92 | Empty Emitter Marker

// UID:0003IM | by-memory\0x0061e6d8-0x0061e6f0.MiniMapButtonPaneEpfResourceString.md | Completion:86 | Confidence:92 | Empty Emitter Marker

// UID:0003FY | by-memory\0x0060d7e0-0x0060d7f4.SharedDownloaderUserAgentWideString.md | Completion:88 | Confidence:93 | Empty Emitter Marker

// UID:0003FZ | by-memory\0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals.md | Completion:89 | Confidence:93 | Empty Emitter Marker

// UID:0003FP | by-memory\0x006104f4-0x006108d4.MiniMapUiReadOnlyData.md | Completion:86 | Confidence:91 | Empty Emitter Marker
