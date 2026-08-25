** TARGET-REPORT-UID:0000LE **
** AUTHOR-AGENT-ID:B010 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** TARGET: by-file/MiniMap.md **
** REPORT-TYPE: empty-emitter-family source-quality research **
** STATUS: IMPLEMENTATION CALLBACK APPLIED - PENDING SUPERVISOR VERIFY/EXECUTE **

# UID0000LE MiniMap Empty-Emitter Family Source-Quality Report

## Current Recommendation

[UID:0000LE] `by-file/MiniMap.md` should remain the MiniMap source-family root for `auto-generated/NexusTK/map/MiniMap.cpp`, but its current generated output is nearly empty because most MiniMap emitters are class indexes, aggregate ranges, global storage aliases, or shared-resource records rather than standalone source bodies.

The recommended implementation is not a monolithic MiniMap.cpp body. It is a report-level repair batch that:

- preserves [UID:0000LE] as the file owner/source root;
- replaces the 18 empty emitter markers with either source-disposition markers or small exact source definitions;
- emits first-draft C++ only for the exact control-layout helper and the MiniMap singleton globals;
- keeps prior B004/B005/B007 accepted aggregate decisions intact;
- records current MCP facts and rejected alternatives directly in the affected docs.

Recommended [UID:0000LE] metadata after incorporation:

```text
COMPLETION:87
CONFIDENCE:89
CANONICAL_OWNER:FILE
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000LE
```

No standalone body should be added to the file-root page. The by-file page should gain a detailed source-disposition section explaining that MiniMap.cpp is a split source family whose emitted content comes from exact child functions, singleton globals, and source-disposition markers. The score should rise only one point from `86/88` to `87/89`: this report resolves the empty-emitter disposition map and supplies formal insertion text, but it does not finish the class declarations, downloader task type, `.mnm` record layout, or renderer record-vector field names.

## Current Generated State

Generated file checked:

```text
auto-generated/NexusTK/map/MiniMap.cpp
```

The file currently contains one filled body and 18 empty emitter markers.

Filled body:

| UID | Path | Disposition |
|---|---|---|
| 0001AM | `by-memory/0x00503620-0x00503649.MiniMapButtonPaneCleanup.md` | Already emits `MiniMapButtonPane::~MiniMapButtonPane(){ g_pMiniMapButtonPane = NULL; }`. This proves exact child-method emission is the correct pattern for MiniMap behavior. |

Empty markers:

| UID | Path | Recommended disposition |
|---|---|---|
| 00008B | `by-class/MiniMapButtonPane.md` | Formal class-index marker with `[[CHILDREN]]`; no declaration shell until base/field/click-dispatch blockers close. |
| 00008C | `by-class/MiniMapDialog.md` | Formal class-index marker with `[[CHILDREN]]`; preserve B004 raw/no-route notes and avoid a declaration shell. |
| 00028P | `by-memory/0x0067a7c4-0x0067a7c8.g_pMiniMapDialog.md` | Emit exact singleton definition `MiniMapDialog *g_pMiniMapDialog = NULL;`. |
| 00008D | `by-class/MiniMapDownloader.md` | Class-index marker with `[[CHILDREN]]`; exact downloader child split plan is listed below, but no class declaration/body is safe in this pass. |
| 00008E | `by-class/MiniMapImageControlPane.md` | Formal class-index marker with `[[CHILDREN]]`; exact image-control split plan is listed below. |
| 00008F | `by-class/MiniMapRenderer.md` | Formal class-index marker with `[[CHILDREN]]`; exact renderer split plan is listed below. |
| 00008G | `by-class/MiniMapSymbolControlPane.md` | Formal class-index marker with `[[CHILDREN]]`; preserve B005 accepted 88/90 evidence and no declaration shell. |
| 0000SY | `by-global/GetControlLayout_452260.md` | Alias/source-disposition marker pointing to exact by-memory [UID:0000XL]. Do not duplicate body. |
| 0000RN | `by-global/g_pMiniMapButtonPane.md` | Emit exact singleton definition `MiniMapButtonPane *g_pMiniMapButtonPane = NULL;`. |
| 0002XP | `by-memory/0x0069b4b8-0x0069b4bc.g_pMiniMapButtonPane.md` | Storage child marker covered by [UID:0000RN]. |
| 0000RO | `by-global/g_pMiniMapDownloader.md` | Emit exact singleton definition `MiniMapDownloader *g_pMiniMapDownloader = NULL;`. |
| 00028S | `by-memory/0x0067a7d8-0x0067a7dc.g_pMiniMapDownloader.md` | Storage child marker covered by [UID:0000RO]. |
| 0000XK | `by-memory/0x00450ca0-0x0045381b.MiniMapDialog.md` | Aggregate/source-family marker only. Preserve accepted B004 no-monolithic-body decision. |
| 0000XL | `by-memory/0x00452260-0x0045239a.GetControlLayout_452260.md` | Emit first-draft exact helper body with current rectangle table. |
| 0000XN | `by-memory/0x00453910-0x00453def.MiniMapDownloader.md` | Aggregate marker only; exact child split plan is listed below, and source-body promotion is excluded from this empty-emitter pass. |
| 0000XO | `by-memory/0x00453df0-0x004563b5.MiniMapRendererAndControls.md` | Aggregate/source-family marker only. Preserve accepted B007 split-index decision. |
| 0001ZZ | `by-memory/0x00457620-0x00457a5d.MiniMapFileLoaderHelpers.md` | Formal helper-island marker; exact loader child split plan is listed below and body promotion is excluded from this pass. |
| 00044U | `by-memory/0x00610fa4-0x00610fbc.SharedFramePartPaletteResourceString.md` | Shared-resource literal marker; do not emit a standalone MiniMap global string. |

## MCP Evidence

IDA MCP was available and current. The active session was:

```text
endpoint: http://127.0.0.1:13337/mcp
server: ida-pro-mcp 1.0.0
database: supervisor_resume_20260629
idb: E:\NTK\Resources\NexusTK\NexusTK.exe.i64
input: C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe
process/worker pid: 17592
auto_analysis_ready: true
hexrays_ready: true
```

Schema-current MCP calls used narrow tools from `by-structure.md`: `initialize`, `tools/list`, `idb_list`, `server_health`, `entity_query`, `lookup_funcs`, `xrefs_to`, `get_bytes`, `decompile`, and `callees`.

### Function and Range Facts

MCP `entity_query` confirms the MiniMap family is split across several function islands, not one contiguous source body:

| Range | Current modeled facts |
|---|---|
| `0x00450ca0-0x0045381b` | 23 modeled MiniMapDialog-family functions before the successor at `0x00453820`. Raw starts `0x004517a0`, `0x00452ce0`, and `0x00452ea0` are not functions. |
| `0x00452260-0x0045239a` | Exact helper `0x00452260`, size `0x13a`; body end `0x0045239a`; post-body bytes include switch-table data then `cc` padding. |
| `0x00453910-0x00453def` | Six modeled downloader functions before successor `0x00453df0`: `0x453910`, `0x453990`, `0x453a00`, `0x453aa0`, `0x453d50`, `0x453d60`. |
| `0x00453df0-0x004563b5` | 49 modeled renderer/image/symbol/support functions before successor `0x004563c0`; raw `0x00454e30` is not a modeled function. |
| `0x00457620-0x00457a5d` | Four modeled file-loader/helper functions at `0x457620`, `0x4576b0`, `0x457850`, `0x457960`; successor `0x00457a60`; raw `0x457760` and `0x457780` are not functions. |

`lookup_funcs` confirms the raw labels below must not be treated as standalone function emitters:

```text
not functions: 0x004517a0, 0x00452ce0, 0x00452ea0, 0x00454e30, 0x00457760, 0x00457780
```

### Cross-References

MCP `xrefs_to` evidence:

| Address | Current xref facts | Disposition |
|---|---|---|
| `0x0067a7c4` | 8 xrefs: writes/uses in MiniMapDialog setup and reads at `0x5a59a0`, `0x5a607c`, `0x5a812e`, `0x5ac023`. | Exact global storage for `g_pMiniMapDialog`. |
| `0x0069b4b8` | 6 xrefs: `0x5035c7`, `0x5035ce`, `0x50363a`, `0x503800`, `0x503920`, `0x504a54`. | Exact storage child for `g_pMiniMapButtonPane`; global alias should emit source definition. |
| `0x0067a7d8` | 5 xrefs: `0x453951`, `0x453958`, `0x4539c2`, `0x453d50`, `0x453d99`. | Exact storage child for `g_pMiniMapDownloader`; global alias should emit source definition. |
| `0x00610fa4` | 3 xrefs: `0x461683`, `0x503375`, `0x503678`. | Shared `FRMPART.PAL` resource literal, not MiniMap-owned code. |
| `0x00452260` | 7 code xrefs, all inside `sub_450CA0`: `0x450e60`, `0x450eae`, `0x450f2f`, `0x450fdc`, `0x451089`, `0x451117`, `0x4511ac`. | Exact helper body belongs on [UID:0000XL]. |
| `0x004517a0`, `0x00452ce0`, `0x00452ea0`, `0x00454e30`, `0x00457760`, `0x00457780` | Zero xrefs to each raw label. | Reject standalone helper/function pages. |
| `0x00457620` | Called from `0x454441` in BuildSymbolViews. | Live file-loader helper, but aggregate should not emit monolithic body. |
| `0x004576b0` | Called from `0x454b5a` and `0x5f9e61`. | Live helper; exact child split is future work. |
| `0x00457850` | Called from `0x454457`. | Live file read/load helper; exact child split is future work. |
| `0x00457960` | Called from raw `0x4577e0` and modeled `0x457936`. | Live decode/format helper; exact child split is future work. |

### Data Bytes

MCP `get_bytes` confirms singleton and literal initial state:

```text
0x0067a7c4: 00 00 00 00
0x0069b4b8: 00 00 00 00
0x0067a7d8: 00 00 00 00
0x00610fa4: UTF-16LE "FRMPART.PAL\0"
```

The storage pages are exact zero-initialized pointer storage. `FRMPART.PAL` is an exact shared resource string and should not become a MiniMap-only global variable.

### Exact Helper Decompile Evidence

MCP `decompile 0x00452260` gives an exact switch helper:

```text
int __stdcall sub_452260(__int16 a1, _DWORD *a2)
{
  result = a1;
  switch ( a1 )
  {
    case 0:  sub_4B7C50(a2, 0, 0, 768, 768); break;
    case 1:  sub_4B7C50(a2, 273, 18, 494, 46); break;
    case 2:  sub_4B7C50(a2, 60, 729, 76, 745); break;
    case 4:  sub_4B7C50(a2, 105, 729, 121, 745); break;
    case 6:  sub_4B7C50(a2, 648, 725, 711, 749); break;
    case 7:  sub_4B7C50(a2, 520, 730, 550, 743); break;
    case 8:  sub_4B7C50(a2, 540, 730, 570, 743); break;
    case 9:  sub_4B7C50(a2, 580, 730, 610, 743); break;
    case 10: sub_4B7C50(a2, 600, 730, 630, 743); break;
    default: break;
  }
  return result;
}
```

MCP `decompile 0x004b7c50` confirms the rectangle helper writes left/top/right/bottom and returns the right edge:

```text
int __cdecl sub_4B7C50(_DWORD *a1, int a2, int a3, int a4, int a5)
{
  a1[1] = a3;
  *a1 = a2;
  a1[3] = a5;
  result = a4;
  a1[2] = a4;
  return result;
}
```

This makes [UID:0000XL] source-ready at first-draft quality.

### Downloader Evidence

MCP confirms [UID:0000XN] is a method/helper cluster, not a single reconstructable function:

```text
0x00453910 size 0x75  constructor-like singleton/thread setup
0x00453990 size 0x6?  destructor-like cleanup
0x00453a00 size 0x2f  OnThreadTask dispatcher
0x00453aa0 size 0x2af WinINet/file download helper
0x00453d50 size 0x0b singleton clear helper
0x00453d60 size 0x90 scalar deleting destructor/compiler glue
```

MCP `decompile 0x00453a00` shows the task dispatcher:

```text
if (a2 != 0)
  sub_596920(this, a2, (int)Block, a4);
else
  sub_453AA0(Block), sub_5C7526(Block);
```

MCP `callees 0x00453aa0` shows WinINet and file output behavior: `InternetOpenW`, `InternetOpenUrlW`, `HttpQueryInfoW`, `InternetQueryDataAvailable`, `InternetReadFile`, `WriteFile`, `CloseHandle`, and delete/cleanup calls. The operation is source-real, but the task block and path fields are not yet named enough for an aggregate body. The exact child ranges and source-body policy are listed in the child split plan; no downloader method/helper body should be promoted during the immediate empty-emitter callback.

### Renderer and File-Loader Evidence

MCP `callees 0x004543f0` confirms the renderer/control aggregate calls MiniMap file loader helpers and vector/string/image helpers, including:

```text
0x00457620
0x00457850
0x004d0a90
0x00455a40
0x004550d0
0x00455060
0x00455b40
0x00455a90
0x00455350
0x00455600
0x004551e0
0x004576b0
```

MCP `callees 0x00457850` shows file I/O (`_fseek`, `_ftell`, `_fread`, `_fclose`) and call to `0x00457960`. MCP `callees 0x00457960` shows allocation/copy/free and formatter behavior.

These support the existing B007 split-index decision: the renderer/control aggregate is active source, but not safe as a monolithic function body. Exact renderer, image-control, symbol-control, vector-support, and file-loader child pages are the correct route for future source bodies.

## Prior Accepted Reports Incorporated As Leads

The report incorporates current docs and these accepted/executed B-agent reports as leads, with MCP reconfirmation where applicable:

| Report | Incorporated fact |
|---|---|
| B004 `0000XK-MiniMapDialog-source-quality.md` | [UID:0000XK] is a mixed MiniMapDialog aggregate/source-family range. Keep aggregate body blank/marker-only; raw labels `0x004517a0`, `0x00452ce0`, and `0x00452ea0` are not modeled functions and have no route. |
| B007 `0000XO-MiniMapRendererAndControls-source-quality.md` | [UID:0000XO] is a split index for renderer/image/symbol controls and local support helpers. Keep aggregate body blank/marker-only; raw `0x00454e30` is no-function/no-xref/no-code as a standalone target. |
| B005 `00008G-MiniMapSymbolControlPane-class-source-quality.md` | [UID:00008G] class evidence is already strong at 88/90, but class-level C++ should remain marker-only until exact child pages carry method bodies and layout/base questions close. |
| B005 `0001AN-MiniMapButtonPaneClearAndThunks-source-quality.md` | Button-pane split policy is already accepted: [UID:0001AM] emits the real destructor body; `0001AN` is non-emitting split/index material. This supports exact child emission instead of class/aggregate body emission. |

## Recommended Formal C++ and Source-Disposition Markers

The generated file should not remain empty for these emitters. Every recommended body or comment-only disposition below is supplied as exact formal `RECONSTRUCTION_CPP CODE` insertion text. The by-file root [UID:0000LE] has no formal C++ block and should receive prose/source-disposition text only.

### [UID:0000XL] GetControlLayout_452260

Recommended first-draft formal block for `by-memory/0x00452260-0x0045239a.GetControlLayout_452260.md`:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
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
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Recommended metadata after incorporation:

```text
COMPLETION:88
CONFIDENCE:92
CANONICAL_OWNER:0000LE
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000LE
```

Source-shape justification:

- `RectBounds *` is justified by [UID:0001VP] `RectBoundsLayout`: the callee `0x004b7c50` writes four 32-bit fields in `left, top, right, bottom` order and is already documented as `InitRectBounds` / `RectBounds::SetLTRB`-style support.
- `InitRectBounds` is justified by the same RectBounds support docs and by repeated project use of that source-facing name for `0x004b7c50`. MCP decompile confirms `0x004b7c50` returns the right edge, so `return InitRectBounds(...)` preserves observed `EAX` for known cases. A `void` setter spelling is rejected for this exact helper because the caller-visible return value is part of the recovered function behavior.
- `static` is the best source-shape inference because all seven current callers are inside `MiniMapDialog::MiniMapDialog`, no external calls or vtable slots reference it, and this is private layout support for one source module.
- `__stdcall` should remain in the first-draft block because the modeled function is callee-cleanup (`ret 8` / Hex-Rays `__stdcall`). A final source cleanup may hide this behind a project macro only if equivalent ABI is preserved.
- `GetMiniMapControlLayout` is the best inferred source-facing name. It rejects `GetControlLayout_452260` as an address-suffixed documentation alias, rejects a generic dialog-control helper because all callers are MiniMapDialog constructor sites, and rejects `MiniMapDialog::GetControlLayout` because the body has no `this` receiver and no member-state access.

### [UID:0000SY] GetControlLayout_452260 Global Alias

Recommended formal marker block for `by-global/GetControlLayout_452260.md`:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Emitted code for the recovered GetControlLayout_452260 alias is covered by [UID:0000XL]
// by-memory/0x00452260-0x0045239a.GetControlLayout_452260.md, which emits the
// source-facing file-local helper GetMiniMapControlLayout.
// Do not emit a duplicate global-alias body here.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Recommended metadata after incorporation:

```text
COMPLETION:87
CONFIDENCE:91
CANONICAL_OWNER:0000LE
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000LE
```

### MiniMap Singleton Globals

Recommended formal block for `by-memory/0x0067a7c4-0x0067a7c8.g_pMiniMapDialog.md`:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
MiniMapDialog *g_pMiniMapDialog = NULL;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Recommended metadata:

```text
COMPLETION:89
CONFIDENCE:93
CANONICAL_OWNER:00008C
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000LE
```

Recommended formal block for `by-global/g_pMiniMapButtonPane.md`:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
MiniMapButtonPane *g_pMiniMapButtonPane = NULL;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Recommended metadata:

```text
COMPLETION:88
CONFIDENCE:90
CANONICAL_OWNER:0000LE
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000LE
```

Recommended formal marker block for `by-memory/0x0069b4b8-0x0069b4bc.g_pMiniMapButtonPane.md`:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Emitted storage for g_pMiniMapButtonPane is covered by [UID:0000RN]
// by-global/g_pMiniMapButtonPane.md.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Recommended metadata:

```text
COMPLETION:87
CONFIDENCE:90
CANONICAL_OWNER:0000RN
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000LE
```

Recommended formal block for `by-global/g_pMiniMapDownloader.md`:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
MiniMapDownloader *g_pMiniMapDownloader = NULL;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Recommended metadata:

```text
COMPLETION:87
CONFIDENCE:91
CANONICAL_OWNER:0000LE
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000LE
```

Recommended formal marker block for `by-memory/0x0067a7d8-0x0067a7dc.g_pMiniMapDownloader.md`:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Emitted storage for g_pMiniMapDownloader is covered by [UID:0000RO]
// by-global/g_pMiniMapDownloader.md.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Recommended metadata:

```text
COMPLETION:87
CONFIDENCE:91
CANONICAL_OWNER:0000RO
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000LE
```

Rationale: MCP bytes confirm zero-initialized storage. Xrefs confirm current live use. For ButtonPane and Downloader, the by-global pages are the cleaner source-level declaration/definition owners; exact by-memory storage pages should not duplicate definitions. No `by-global/g_pMiniMapDialog.md` currently exists, and creating one is excluded from this callback because the exact storage page already covers the source definition without introducing a new duplicate route.

### [UID:00044U] SharedFramePartPaletteResourceString

Recommended formal marker block for `by-memory/0x00610fa4-0x00610fbc.SharedFramePartPaletteResourceString.md`:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// FRMPART.PAL is a shared frame-part palette resource literal.
// Source use is emitted at FrameChrome, MapNamePane, and MiniMapButtonPane paint sites,
// not as a standalone MiniMap-owned global string.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Recommended metadata:

```text
COMPLETION:89
CONFIDENCE:93
CANONICAL_OWNER:NONE
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000JL,0000L2,0000LE
```

Rationale: exact bytes decode as UTF-16LE `FRMPART.PAL\0`; xrefs show shared use at `0x461683`, `0x503375`, and `0x503678`. The page should document shared resource ownership, not emit a duplicate MiniMap variable.

### Class Index Audit And Formal Markers

Current MCP refresh for this repair kept the listener healthy (`supervisor_resume_20260629`, pid `17592`, Hex-Rays ready) and reconfirmed the class method starts used below. `lookup_funcs` confirms current modeled sizes for the main constructor/destructor/method starts including MiniMapDialog `0x450ca0` size `0x682`, Downloader `0x453910` size `0x75`, ImageControl `0x453df0` size `0x97`, Renderer `0x453f50` size `0xb8`, SymbolControl `0x455e60` size `0x1d1`, and ButtonPane `0x503580` size `0x9e`. Current `xrefs_to` on vtable bases confirms the expected constructor/destructor/scalar-destructor write pattern: MiniMapDialog primary/secondary/tertiary vtables have two refs each; Downloader has three refs to `0x006106d0`; ImageControl, SymbolControl, and MiniMapButtonPane vtable triplets have three refs each.

Declaration-shell decision: do not emit class declaration shells now. Each class page should receive a formal comment marker with `[[CHILDREN]]` so exact source-bearing children can still appear in generated output, but the marker must not claim a source declaration that the current layout evidence cannot support.

| UID / class | Base/vtable audit | Constructor/destructor route | Known child inventory | Layout blockers | Class shell decision |
|---|---|---|---|---|---|
| `00008B` `MiniMapButtonPane` | Three vtable views at `0x0061e63c`, `0x0061e688`, `0x0061e6b8`; current MCP xrefs confirm three refs to each. The class is pane/control-like but secondary/tertiary base spellings are not accepted. | Constructor `0x00503580-0x0050361d` has one caller from `InitializeMainUiGraph`; ordinary destructor [UID:0001AM] emits; scalar deleting destructor [UID:00040N] and adjustor thunks [UID:00040M] are compiler glue. | Constructor, destructor, `OnPaint`, `OnMouseEvent`, singleton clear [UID:00040L], adjustor thunks, scalar deleting destructor. | Hover/down state fields, tile-context member type, click-dispatch target, and exact secondary/tertiary inherited base names are not source-quality. | No declaration shell. Use marker plus `[[CHILDREN]]`; exact child methods carry source bodies. |
| `00008C` `MiniMapDialog` | Primary/secondary/tertiary vtables at `0x006104f4`, `0x00610554`, `0x00610584`; current MCP xrefs show constructor/destructor stores. It is DialogPane-derived, but the full inherited and derived-tail declaration is not settled. | Constructor `0x00450ca0`, destructor `0x00451330`, cleanup helper `0x004537e0`, adjustor thunks, plus raw no-route bodies inside [UID:0000XK]. | Dialog construction/teardown, input/action/timer/layout/render families, embedded renderer at `+0x1cc`, `GetMiniMapControlLayout` helper, raw refresh/append/center-update bodies. | Large derived tail, raw no-function/no-route bodies, embedded renderer/control field names, and exact private control member declarations are not ready. | No declaration shell. Use marker plus `[[CHILDREN]]`; [UID:0000XK] and exact children document behavior. |
| `00008D` `MiniMapDownloader` | `Thread`-style worker class; vtable base `0x006106d0` has constructor/destructor/scalar-deleting refs. | Constructor `0x00453910` calls the thread base with worker id `5`, publishes `g_pMiniMapDownloader`, installs vtable, and starts the worker. Destructor `0x00453990`, task handler `0x00453a00`, helper `0x00453aa0`, clear `0x00453d50`, scalar deleting destructor `0x00453d60`. | Exact six-function island listed under [UID:0000XN]. | `Thread` base source spelling, task struct type, output-path/map-code fields, and WinINet wrapper names are still below class-shell quality. | No declaration shell. Use marker plus `[[CHILDREN]]`; exact method/helper children should be created only if a split callback is authorized. |
| `00008E` `MiniMapImageControlPane` | Three vtable views at `0x0061070c`, `0x00610774`, `0x006107a4`; vtable refs tie constructor/destructor/scalar paths to this class. | Constructor `0x00453df0`, ordinary destructor `0x00453e90`, `OnPaint` `0x00453eb0`, adjustor thunks `0x00453ed0`, scalar deleting destructor `0x00453ef0`. | Exact image-control rows are in [UID:0000XO]. | ControlPane base spellings, image-handle type at `+0x14c`, render callback names, and helper pollution from fitting-room image labels are not final. | No declaration shell. Use marker plus `[[CHILDREN]]`; child method bodies wait for exact image/control helper names. |
| `00008F` `MiniMapRenderer` | Embedded runtime object, not currently a vtable-backed pane class. MiniMapDialog constructs it at dialog offset `+0x1cc`. | Constructor `0x00453f50`, destructor `0x00454010`, accessors, view-origin update, prepare/version, build, version check. | Renderer exact rows in [UID:0000XO], plus file-loader dependency [UID:0001ZZ]. | Record-vector layouts, `m_viewOrigin*` exact names, 80-byte and 108-byte record fields, raw `0x00454e30` reachability, and `.mnm` format names remain unresolved. | No declaration shell. Use marker plus `[[CHILDREN]]`; simple accessors are later child-body candidates. |
| `00008G` `MiniMapSymbolControlPane` | Primary/secondary/tertiary vtables at `0x0061081c`, `0x00610884`, `0x006108b4`; tertiary view is TimerHandler-compatible and current MCP xrefs confirm constructor/destructor/scalar refs. | Constructor `0x00455e60`, destructor `0x00456040`, `StartAnimation`, `SetCenterPosition`, `OnAnimationTick`, `OnDraw`, thunks, scalar deleting destructor, `GetControlType`. | B005 inventory lists exact proposed children for constructor/destructor/animation/center/tick/draw/type helper. | Exact primary base declaration, TimerHandler secondary subobject spelling, `+0x210/+0x214` center-coordinate ordering, and `.mnm` record id field names remain open. | No declaration shell despite `88/90`; completion is below the active class-code gate and base/field blockers are real. Use marker plus `[[CHILDREN]]`. |

Recommended formal marker block for `by-class/MiniMapButtonPane.md`:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// MiniMapButtonPane class declaration is intentionally withheld: constructor,
// destructor, paint, mouse, singleton, and vtable routes are documented, but
// inherited base spellings, hover/down fields, tile-context ownership, and
// click-dispatch names are not source-quality yet.
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Recommended metadata:

```text
COMPLETION:86
CONFIDENCE:88
CANONICAL_OWNER:0000LE
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000LE
```

Recommended formal marker block for `by-class/MiniMapDialog.md`:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// MiniMapDialog class declaration is intentionally withheld: the DialogPane-derived
// shell, embedded renderer, child controls, and raw no-route bodies are documented,
// but the full derived-tail layout and exact private member declarations are not
// source-quality yet.
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Recommended metadata:

```text
COMPLETION:86
CONFIDENCE:89
CANONICAL_OWNER:0000LE
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000LE
```

Recommended formal marker block for `by-class/MiniMapDownloader.md`:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// MiniMapDownloader class declaration is intentionally withheld: the worker-thread
// singleton and six-function island are documented, but Thread base spelling and
// MiniMapDownloadTask field names are not source-quality yet.
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Recommended metadata:

```text
COMPLETION:86
CONFIDENCE:90
CANONICAL_OWNER:0000LE
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000LE
```

Recommended formal marker block for `by-class/MiniMapImageControlPane.md`:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// MiniMapImageControlPane class declaration is intentionally withheld: constructor,
// ordinary destructor, OnPaint, and vtable routes are documented, but the ControlPane
// base spelling, image-handle type, and render-helper names are not source-quality yet.
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Recommended metadata:

```text
COMPLETION:86
CONFIDENCE:88
CANONICAL_OWNER:0000LE
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000LE
```

Recommended formal marker block for `by-class/MiniMapRenderer.md`:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// MiniMapRenderer class declaration is intentionally withheld: the embedded runtime
// object and method inventory are documented, but renderer record-vector layouts,
// .mnm field names, and raw downloader-helper reachability are not source-quality yet.
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Recommended metadata:

```text
COMPLETION:86
CONFIDENCE:88
CANONICAL_OWNER:0000LE
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000LE
```

Recommended formal marker block for `by-class/MiniMapSymbolControlPane.md`:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// MiniMapSymbolControlPane class declaration is intentionally withheld: method routes,
// TimerHandler-compatible vtable evidence, resources, and field candidates are documented,
// but base-subobject spelling and center-coordinate field order are not source-quality yet.
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Recommended metadata:

```text
COMPLETION:88
CONFIDENCE:90
CANONICAL_OWNER:0000LE
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000LE
```

### Aggregate and Helper-Island Formal Markers

Recommended formal marker block for `by-memory/0x00450ca0-0x0045381b.MiniMapDialog.md`:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// This MiniMapDialog aggregate is a source-family index.
// Exact child pages and documented raw no-route bodies cover the range;
// do not emit a monolithic aggregate body here.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Recommended metadata:

```text
COMPLETION:88
CONFIDENCE:89
CANONICAL_OWNER:0000LE
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000LE
```

Recommended formal marker block for `by-memory/0x00453910-0x00453def.MiniMapDownloader.md`:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// This MiniMapDownloader range is a source-family index for the worker class,
// direct .mnm download helper, singleton-clear helper, and compiler destructor glue.
// Emit exact method/helper bodies only from split child pages; do not emit a
// monolithic downloader aggregate body here.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Recommended metadata:

```text
COMPLETION:87
CONFIDENCE:91
CANONICAL_OWNER:0000LE
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000LE
```

Recommended formal marker block for `by-memory/0x00453df0-0x004563b5.MiniMapRendererAndControls.md`:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// This MiniMap renderer/control aggregate covers image-control, renderer,
// symbol-control, renderer-local vector support, shared string-vector support,
// raw no-route downloader bytes, and compiler destructor glue.
// Emit exact method/helper bodies only from split child pages; do not emit a
// monolithic aggregate body here.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Recommended metadata:

```text
COMPLETION:88
CONFIDENCE:90
CANONICAL_OWNER:0000LE
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000LE
```

Recommended formal marker block for `by-memory/0x00457620-0x00457a5d.MiniMapFileLoaderHelpers.md`:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// This MiniMapFileLoader helper island is a source-family index for the loader
// constructor, destructor, load, payload decode, and raw no-route reset/write bodies.
// Emit exact loader method/helper bodies only from split child pages after
// MiniMapFileLoader fields and .mnm record names are accepted.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Recommended metadata:

```text
COMPLETION:86
CONFIDENCE:89
CANONICAL_OWNER:0000LE
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000LE
```

### Exact Child Split Plans For Named Aggregate Blockers

The immediate empty-emitter implementation can close [UID:0000XN], [UID:0000XO], and [UID:0001ZZ] with the formal aggregate markers above. Source-body promotion is unsafe in this pass because the current assignment is a file-family empty-emitter repair and because the exact child pages do not yet exist. The blocker is converted into these implementation-ready split plans instead of being left as generic future work.

Recommended child plan for [UID:0000XN] `MiniMapDownloader`:

| Proposed child | Range | Create now? | Source-body policy |
|---|---:|---|---|
| `MiniMapDownloaderConstructor` | `0x00453910-0x00453985` | Only if supervisor expands callback to split creation. | Candidate body after `Thread(5)` / worker-start names are accepted; no body in aggregate. |
| `MiniMapDownloaderDestructor` | `0x00453990-0x004539e1` | Only if split creation is authorized. | Candidate body after Thread stop/teardown names are accepted. |
| `MiniMapDownloaderOnThreadTask` | `0x00453a00-0x00453a2f` | Only if split creation is authorized. | Candidate body, but task type and delete/free helper naming must be accepted first. |
| `DownloadMinimap_453AA0` | `0x00453aa0-0x00453d4f` | Only if split creation is authorized. | No first-draft body in this pass; task block/path fields and WinINet wrapper names remain source blockers. |
| `MiniMapDownloaderClearSingleton` | `0x00453d50-0x00453d5b` | Optional exact child if split creation is authorized. | Tiny helper is behavior-known, but may be compiler/EH cleanup support; do not promote during empty-emitter closure. |
| `MiniMapDownloaderScalarDeletingDestructor` | `0x00453d60-0x00453def` | Optional no-code child if split creation is authorized. | Compiler deleting destructor glue; no source-authored body. |

Recommended child plan for [UID:0000XO] `MiniMapRendererAndControls`:

| Proposed child group | Ranges | Create now? | Source-body policy |
|---|---|---|---|
| `MiniMapImageControlPane` methods | `0x00453df0-0x00453e87`, `0x00453e90-0x00453eaf`, `0x00453eb0-0x00453ed0` | Only if split creation is authorized. | Constructor/destructor/OnPaint are candidates after ControlPane/image helper names are accepted. |
| Image-control compiler glue | `0x00453ed0-0x00453ee6`, `0x00453ef0-0x00453f45` | Optional no-code children only. | Adjustor thunks and scalar deleting destructor; no source-authored bodies. |
| Simple renderer methods | `0x00454080-0x00454087`, `0x00454090-0x00454094`, `0x004540a0-0x00454143`, `0x00454150-0x004543ec`, `0x00454d80-0x00454e2f` | Only if split creation is authorized. | Accessors/update/version helpers are first-draft candidates; exact field names still cap score. |
| Renderer constructor/destructor | `0x00453f50-0x00454008`, `0x00454010-0x00454071` | Only if split creation is authorized. | Candidate after renderer record-vector field names are accepted. |
| `BuildSymbolViews` | `0x004543f0-0x00454bac` | Not in this empty-emitter pass. | Behavior-complete but not source-ready; 80-byte/108-byte record layouts and `.mnm` record names must be accepted. |
| Raw downloader body | strict candidate `0x00454e30-0x00455041` if ever split | Do not create now. | No IDA function object, no start xrefs, no PE pointer/branch route; document no-code proof only. |
| Renderer-local vector helpers | `0x004550d0-0x00455e52` buckets from [UID:0000XO] | Do not create now. | Split only after record-vector ownership pass; shared 24-byte string-vector helpers must not become MiniMap-owned bodies. |
| Symbol-control methods | `0x00455e60-0x00456031`, `0x00456040-0x0045609e`, `0x004560a0-0x004560e1`, `0x004560f0-0x00456175`, `0x00456180-0x00456293`, `0x004562a0-0x004562f8`, `0x004563b0-0x004563b5` | Only if split creation is authorized. | Many are first-draft candidates, but base order and `+0x210/+0x214` coordinate order block class/source-body promotion in this pass. |
| Symbol-control compiler glue | `0x004562f8-0x0045630e`, `0x00456310-0x004563af` | Optional no-code children only. | Compiler adjustor/deleting destructor glue. |

Recommended child plan for [UID:0001ZZ] `MiniMapFileLoaderHelpers`:

| Proposed child | Range | Create now? | Source-body policy |
|---|---:|---|---|
| `MiniMapFileLoaderConstructor` | `0x00457620-0x004576a6` | Only if split creation is authorized. | Candidate after `MiniMapFileLoader` field names are accepted. |
| `MiniMapFileLoaderDestructor` | `0x004576b0-0x00457757` | Only if split creation is authorized. | Candidate after string/payload field names are accepted. |
| raw reset helper | `0x00457760-0x00457780` | Do not create now. | No IDA function object and no direct xrefs; document raw no-route body only. |
| raw transform/write helper | `0x00457780-0x00457842` | Do not create now. | No IDA function object and no direct xrefs; possible retained save/write feature, no source-body promotion. |
| `MiniMapFileLoaderLoad` | `0x00457850-0x00457953` | Only if split creation is authorized. | Candidate after `.mnm` header/version field names are accepted. |
| `MiniMapFileLoaderDecodePayload` | `0x00457960-0x00457a5d` | Only if split creation is authorized. | Candidate after path-key and payload-length names are accepted. |

These plans resolve the named blocker for this report: exact child ranges and body candidates are identified, and source-body promotion is explicitly excluded from the immediate empty-emitter implementation where current evidence would force provisional field/type names.

## Rejected Alternatives

| Alternative | Rejection reason |
|---|---|
| Emit one large MiniMap.cpp body from [UID:0000LE]. | The by-file page is a source root, not a function. Current MCP shows multiple method islands, raw no-route labels, globals, `.rdata` resource literals, and shared support helpers. |
| Emit `class MiniMap* { ... [[CHILDREN]] ... }` declaration shells now. | Per-class audit shows every class has at least one declaration blocker: unresolved secondary/tertiary base spellings, task structs, image/helper types, renderer record vectors, or center-coordinate order. Marker plus `[[CHILDREN]]` is the safe emitted shape. |
| Emit class method bodies directly from `by-class/MiniMap*.md`. | Exact source-bearing methods should be split child pages. Current class pages are owner/context indexes and do not have enough layout evidence for full class declarations. |
| Emit aggregate bodies from [UID:0000XK], [UID:0000XN], [UID:0000XO], or [UID:0001ZZ]. | These pages cover mixed source-family ranges/helper islands with multiple methods, raw no-function bodies, compiler glue, and shared support helpers. Formal source-disposition markers are the correct immediate repair. |
| Create source-emitting children for raw labels `0x004517a0`, `0x00452ce0`, `0x00452ea0`, `0x00454e30`, `0x00457760`, or `0x00457780`. | MCP `lookup_funcs` reports no function objects; `xrefs_to` finds no direct refs to the raw starts; existing PE route checks found no direct pointer/branch route. Document raw no-route bodies but do not emit source bodies. |
| Put `GetMiniMapControlLayout` / `GetControlLayout_452260` body on both the by-global and by-memory pages. | The exact by-memory page [UID:0000XL] owns the body. The by-global page is an address-suffixed alias and must emit only a covered-by marker. |
| Emit MiniMap-owned `FRMPART.PAL` global string. | MCP bytes/xrefs show a shared resource literal used by FrameChrome, MapNamePane, and MiniMapButtonPane. Source use belongs at paint/resource sites, not a MiniMap-only standalone global. |
| Move downloader/renderer/file-loader helper bodies into generic `VectorHelpers` or runtime-only support docs. | Current call evidence ties the live behavior to MiniMap downloader, renderer, and file-loader workflows. Shared 24-byte string-vector helpers are rejected from MiniMap ownership separately; MiniMap-specific workflows stay under MiniMap. |

## Open Questions With Attempted Resolution

| Question from current docs | Evidence checked | Resolution for this report |
|---|---|---|
| Exact compact `MiniMap.cpp` versus split `MiniMapDialog.cpp` / `MiniMapRenderer.cpp` / `MiniMapDownloader.cpp` source files. | Current generated route is `auto-generated/NexusTK/map/MiniMap.cpp`; [UID:0000LE] already owns the MiniMap feature root; current MCP shows all empty emitters route to [UID:0000LE]. | Resolved for implementation: keep [UID:0000LE] as the active source root and do not split source files in this callback. Broader source-file decomposition is outside this empty-emitter assignment and should not block formal marker/global/helper repairs. |
| Downloader task structure/path fields. | `0x00453a00` dispatcher decompile, `0x00453aa0` WinINet/file callee set, singleton/vtable xrefs, existing [UID:0000XN]/[UID:00008D] docs. | Converted to exact split plan: create downloader child pages only if supervisor expands the callback. Do not emit downloader bodies in this pass except aggregate marker; task fields remain a documented blocker for child-body promotion, not for empty-emitter repair. |
| `.mnm` and symbol-record layouts. | `BuildSymbolViews` callee set, file-loader helper docs, [UID:0001ZZ] field/format table, image-decode call, 80-byte/108-byte vector-helper inventory. | Converted to exact repair plan: [UID:0000XO] and [UID:0001ZZ] receive aggregate/helper-island markers now. Exact child pages and a `.mnm` format/by-resource pass are recommended only when split creation is authorized. |
| Class base layouts and pane field offsets. | Six by-class docs, MiniMap UI read-only data, vtable xrefs, current MCP method start refresh, B004/B005/B007 reports. | Resolved for this report: no class declaration shells now. Formal marker plus `[[CHILDREN]]` is implementation-ready for every class page. |
| Missing `by-global/g_pMiniMapDialog.md` alias. | `rg` found no existing by-global page; exact storage [UID:00028P] has zero bytes and 8 live xrefs. | Resolved for implementation: do not create a new by-global alias in this pass. Emit `MiniMapDialog *g_pMiniMapDialog = NULL;` on [UID:00028P]; if a future alias is created, [UID:00028P] can be converted to a covered-by storage marker then. |
| Root score bump. | Current file root is `86/88`; report now supplies empty-emitter disposition map, formal blocks, class audits, and child plans, but not declarations or detailed child bodies. | Re-evaluated to `87/89`, not `88/90`. The root improves by one point for direct report coverage and formal emitter repair, but remains capped by class/layout/format split issues. |

## Claim And Incorporation Ledger

| Claim ID | Claim | Evidence | Incorporation Point | Implementation State |
|---|---|---|---|---|
| C1 | [UID:0000LE] remains the MiniMap source-family root; no monolithic file-root body should be emitted. | Generated route, by-file guidance, and current MCP family distribution. | `by-file/MiniMap.md` source-disposition and score sections. | Applied. Root documents the no-file-root-C++ rule and child/marker source routing; validator `000000002234`; captured refresh `000000002256`; latest observed generated header later advanced to `000000002361`. |
| C2 | Root score should move only to `87/89`, not `88/90`. | Empty-emitter disposition is resolved, but class declaration, format, record-vector, and source-file-split limits still cap the root. | `by-file/MiniMap.md` metadata and Score Rationale. | Applied. Header now reads `COMPLETION:87` and `CONFIDENCE:89`; validator `000000002234`. |
| C3 | Generated MiniMap.cpp had one filled destructor body and 18 empty-family emitters requiring exact dispositions. | Previous generated file, tracker row, accepted report audit. | `by-file/MiniMap.md` empty-emitter disposition table and generated `auto-generated/NexusTK/map/MiniMap.cpp`. | Applied. All 19 emitters are mapped to body/marker/definition dispositions; captured refresh `000000002256` regenerated MiniMap.cpp from the docs, and the latest observed generated header shows validator refresh `000000002361`. |
| C4 | MCP was available/current and used; no fallback-only report. | `initialize`, `idb_list`, `server_health`, `lookup_funcs`, `xrefs_to`, `callees`, `decompile`, and `get_bytes` evidence from command IDs `000000005813` through `000000006147`. | Evidence sections in this report and incorporated support-doc rationale. | Already present and incorporated. Implementation did not replace MCP facts with fallback-only reasoning. |
| C5 | [UID:0000XL] should emit source-facing `static int __stdcall GetMiniMapControlLayout(short, RectBounds *)`. | Exact decompile, `0x0045239a` body end, padding nuance, seven constructor callers, `InitRectBounds` decompile, and RectBoundsLayout. | `by-memory/0x00452260-0x0045239a.GetControlLayout_452260.md`. | Applied. Formal body, source-shape rationale, rejected alternatives, metadata `88/92`, and caller/body-end notes are present; validator `000000002235`; captured refresh `000000002256`; latest observed generated header `000000002361`. |
| C6 | [UID:0000SY] is an alias and should not duplicate [UID:0000XL] body. | Same address as [UID:0000XL], by-global alias surface, and exact by-memory owner. | `by-global/GetControlLayout_452260.md`. | Applied. Formal covered-by marker, metadata `87/91`, and no-duplicate-body rationale are present; validator `000000002236`. |
| C7 | `g_pMiniMapDialog`, `g_pMiniMapButtonPane`, and `g_pMiniMapDownloader` are zero-initialized singleton pointers with exact source definitions/covered storage split. | MCP bytes and xrefs for `0x0067a7c4`, `0x0069b4b8`, and `0x0067a7d8`; existing by-global pages for two globals. | [UID:00028P], `by-global/g_pMiniMapButtonPane.md`, [UID:0002XP], `by-global/g_pMiniMapDownloader.md`, [UID:00028S]. | Applied. Definitions and storage covered-by markers are present; validators `000000002237` through `000000002241`; captured refresh `000000002256`; latest observed generated header `000000002361`. |
| C8 | `FRMPART.PAL` is shared resource-literal use, not a MiniMap-owned global. | MCP bytes decode and xrefs at `0x461683`, `0x503375`, and `0x503678`. | `by-memory/0x00610fa4-0x00610fbc.SharedFramePartPaletteResourceString.md`. | Applied. Formal shared-resource marker, metadata `89/93`, and no-code rationale are present; validator `000000002242`. |
| C9 | All six MiniMap class pages should get formal marker-plus-`[[CHILDREN]]` blocks, not declaration shells. | Per-class docs, MiniMap UI read-only data, current MCP method/vtable xrefs, class-code gate, and declaration-shell audits. | Six `by-class/MiniMap*.md` pages. | Applied. All six pages now have formal class-index markers and audit/exclusion sections; validators `000000002243`, `000000002244`, `000000002245`, `000000002246`, `000000002247`, and `000000002249`. |
| C10 | [UID:0000XK], [UID:0000XN], [UID:0000XO], and [UID:0001ZZ] should emit aggregate/helper-island formal markers only. | B004/B007 accepted reports, current MCP function inventories, raw no-route evidence, and mixed helper/compiler-glue ranges. | Four by-memory aggregate/helper pages. | Applied. Formal markers and score/source-shape rationale are present; validators `000000002250`, `000000002251`, `000000002252`, and `000000002253`. |
| C11 | Exact child ranges for [UID:0000XN], [UID:0000XO], and [UID:0001ZZ] are identified; source-body promotion is excluded from the immediate empty-emitter pass. | Current MCP lookup/callees, current docs, and prior B reports. | Aggregate pages and `by-file/MiniMap.md` split-plan sections. | Applied. Exact split plans and current-pass exclusions are present; validators `000000002234`, `000000002251`, `000000002252`, and `000000002253`. |
| C12 | Raw labels `0x004517a0`, `0x00452ce0`, `0x00452ea0`, `0x00454e30`, `0x00457760`, and `0x00457780` must not receive source-emitting standalone bodies now. | MCP `lookup_funcs` negative results, xref negatives, and existing PE route checks. | `by-file/MiniMap.md`, aggregate docs, and rejected-alternative/no-code sections. | Applied. Raw-label no-code proofs and promotion conditions are documented. |
| C13 | B004/B005/B007 accepted MiniMap decisions remain valid and must be preserved. | Executed reports and current support docs. | `by-file/MiniMap.md`, [UID:0000XK], [UID:0000XO], [UID:00008G], and [UID:00008B]. | Applied/already-present. Prior accepted method inventories, downloader facts, renderer facts, and path details were preserved while B010 added source disposition. |

## Implementation Tracking Checklist

- [x] Read Agent-B010 `goal.md`.
- [x] Read project B-agent workflow skill and relevant references.
- [x] Read `by-structure.md` and by-file guidance for schema/current metadata constraints.
- [x] Reused accepted target/support scope; no target/support by-* edits were made before supervisor callback.
- [x] Leased the 19 by-* callback files immediately before editing.
- [x] `by-file/MiniMap.md`: added source-disposition section, empty-emitter inventory summary, direct-report note, root score `87/89`, and source-file split disposition.
- [x] `by-memory/0x00452260-0x0045239a.GetControlLayout_452260.md`: applied [UID:0000XL] formal helper body, metadata `88/92`, source-shape rationale, exact caller/body-end/padding notes.
- [x] `by-global/GetControlLayout_452260.md`: applied alias formal marker, metadata `87/91`, and no-duplicate-body rationale.
- [x] `by-memory/0x0067a7c4-0x0067a7c8.g_pMiniMapDialog.md`: applied formal singleton definition and metadata `89/93`; recorded no by-global alias creation in this callback.
- [x] `by-global/g_pMiniMapButtonPane.md` and `by-memory/0x0069b4b8-0x0069b4bc.g_pMiniMapButtonPane.md`: applied global definition and storage covered-by marker with recommended metadata.
- [x] `by-global/g_pMiniMapDownloader.md` and `by-memory/0x0067a7d8-0x0067a7dc.g_pMiniMapDownloader.md`: applied global definition and storage covered-by marker with recommended metadata.
- [x] `by-memory/0x00610fa4-0x00610fbc.SharedFramePartPaletteResourceString.md`: applied shared-resource literal marker and metadata `89/93`.
- [x] Six class pages `by-class/MiniMapButtonPane.md`, `MiniMapDialog.md`, `MiniMapDownloader.md`, `MiniMapImageControlPane.md`, `MiniMapRenderer.md`, and `MiniMapSymbolControlPane.md`: applied exact formal marker-plus-`[[CHILDREN]]` blocks, class audits, metadata, and no-declaration-shell decisions.
- [x] Aggregate pages [UID:0000XK], [UID:0000XN], [UID:0000XO], and [UID:0001ZZ]: applied formal markers, preserved B004/B007 details, and added exact child split/exclusion plans.
- [x] Preserved rejected alternatives and no-code proof for raw labels and shared/generic helper exclusions.
- [x] Ran scoped validators for every changed by-* file from `E:/NTK/GhidraBridge/source-3/project-documentation`; all exited 0 with `ok: 1`.
- [x] Ran generated refresh through the validator; captured refresh command `000000002256` exited 0 with `ok: 1`. Later validator-owned refreshes advanced observed `auto-generated/NexusTK/map/MiniMap.cpp` freshness, last seen at command `000000002361`.
- [x] Released leases after the edit/validator batch. Release returned `Rejected[No active lease]` for the 19 paths, and a current-lease scan found no active B010 MiniMap rows.
- [x] Updated this report ledger/checklist with proof.
- [x] Did not spawn subagents.
- [x] Did not manually edit generated files, project-level generated files, manual coverage reports, validator/tool state, IDA DB, executed archives, supervisor ledgers, or lock files.
- [x] Did not move or execute this report; it remains in `tools/leaser/Agents/Agent-B010/research/`.

## Validator Results

Initial validator help check:

| Command ID | Timestamp | Command | Exit | Result |
|---|---|---|---:|---|
| `000000002231` | `2026-06-30T04:47:56-04:00` | `python .\tools\validator.py --help` | 0 | Confirmed scoped validator flags. |

Scoped by-* validation used `python .\tools\validator.py --mode file --file <path> --apply --no-generated-refresh` from `E:\NTK\GhidraBridge\source-3\project-documentation`.

| Command ID | Timestamp | File | Exit | OK | Warnings/Notes |
|---|---|---|---:|---:|---|
| `000000002234` | `2026-06-30T04:48:49-04:00` | `by-file/MiniMap.md` | 0 | 1 | `generated_refresh` skipped; `missing_ref_uid: 15`; UID links inserted/updated; projected stats updated. |
| `000000002235` | `2026-06-30T04:48:57-04:00` | `by-memory/0x00452260-0x0045239a.GetControlLayout_452260.md` | 0 | 1 | `generated_refresh` skipped. |
| `000000002236` | `2026-06-30T04:48:59-04:00` | `by-global/GetControlLayout_452260.md` | 0 | 1 | `generated_refresh` skipped; stats row remove/rescore recommended. |
| `000000002237` | `2026-06-30T04:49:00-04:00` | `by-memory/0x0067a7c4-0x0067a7c8.g_pMiniMapDialog.md` | 0 | 1 | `generated_refresh` skipped. |
| `000000002238` | `2026-06-30T04:49:02-04:00` | `by-global/g_pMiniMapButtonPane.md` | 0 | 1 | `generated_refresh` skipped; `missing_ref_uid: 11`; stats row remove/rescore recommended. |
| `000000002239` | `2026-06-30T04:49:04-04:00` | `by-memory/0x0069b4b8-0x0069b4bc.g_pMiniMapButtonPane.md` | 0 | 1 | `generated_refresh` skipped; `missing_ref_uid: 6`. |
| `000000002240` | `2026-06-30T04:49:06-04:00` | `by-global/g_pMiniMapDownloader.md` | 0 | 1 | `generated_refresh` skipped; stats row remove/rescore recommended. |
| `000000002241` | `2026-06-30T04:49:08-04:00` | `by-memory/0x0067a7d8-0x0067a7dc.g_pMiniMapDownloader.md` | 0 | 1 | `generated_refresh` skipped. |
| `000000002242` | `2026-06-30T04:49:10-04:00` | `by-memory/0x00610fa4-0x00610fbc.SharedFramePartPaletteResourceString.md` | 0 | 1 | `generated_refresh` skipped; console output truncated after metadata but command returned `ok: 1`. |
| `000000002243` | `2026-06-30T04:49:11-04:00` | `by-class/MiniMapButtonPane.md` | 0 | 1 | `generated_refresh` skipped; `missing_ref_uid: 26`; stats rows removed/rescore recommended. |
| `000000002244` | `2026-06-30T04:49:13-04:00` | `by-class/MiniMapDialog.md` | 0 | 1 | `generated_refresh` skipped; stats row remove/rescore recommended. |
| `000000002245` | `2026-06-30T04:49:15-04:00` | `by-class/MiniMapDownloader.md` | 0 | 1 | `generated_refresh` skipped; stats row remove/rescore recommended. |
| `000000002246` | `2026-06-30T04:49:17-04:00` | `by-class/MiniMapImageControlPane.md` | 0 | 1 | `generated_refresh` skipped; stats rows removed/rescore recommended. |
| `000000002247` | `2026-06-30T04:49:19-04:00` | `by-class/MiniMapRenderer.md` | 0 | 1 | `generated_refresh` skipped; stats rows removed/rescore recommended. |
| `000000002249` | `2026-06-30T04:49:21-04:00` | `by-class/MiniMapSymbolControlPane.md` | 0 | 1 | `generated_refresh` skipped; `missing_ref_uid: 1`. |
| `000000002250` | `2026-06-30T04:49:22-04:00` | `by-memory/0x00450ca0-0x0045381b.MiniMapDialog.md` | 0 | 1 | `generated_refresh` skipped. |
| `000000002251` | `2026-06-30T04:49:24-04:00` | `by-memory/0x00453910-0x00453def.MiniMapDownloader.md` | 0 | 1 | `generated_refresh` skipped. |
| `000000002252` | `2026-06-30T04:49:26-04:00` | `by-memory/0x00453df0-0x004563b5.MiniMapRendererAndControls.md` | 0 | 1 | `generated_refresh` skipped; `missing_ref_uid: 1`. |
| `000000002253` | `2026-06-30T04:49:28-04:00` | `by-memory/0x00457620-0x00457a5d.MiniMapFileLoaderHelpers.md` | 0 | 1 | `generated_refresh` skipped; stats row remove/rescore recommended. |

Generated refresh used `python .\tools\validator.py --mode file --file by-file/MiniMap.md --apply --wait-generated`.

| Command ID | Timestamp | Exit | OK | Generated Freshness |
|---|---|---:|---:|---|
| `000000002256` | `2026-06-30T04:49:47-04:00` | 0 | 1 | Captured B010 refresh completed; generated output was refreshed from [UID:0000LE]. A later validator-owned refresh superseded the file header. |

Generated-refresh warnings/notes from command `000000002256`: `autogen_cpp_update: 4`, `autogen_backup_create: 3`, `autogen_children_fallback_insert: 9`, `autogen_children_marker_missing: 42`, `autogen_emitter_has_no_code: 360`, `generated_metadata_refresh: 278`, `memory_auto_coverage_update: 1`, `missing_ref_uid: 15`, `projected_stats_update: 1`. Validator-owned backups were created under `tools/validator_autogen_backup/20260630-044956`, `20260630-044958`, and `20260630-045001`. These are validator-owned outputs, not manual edits.

Current generated freshness observed after concurrent validator activity:

```text
auto-generated/NexusTK/map/MiniMap.cpp
validator-command-id: 000000002361
validator-refreshed-at: 2026-06-30T04:59:29-04:00
validator-refresh-source: foreground-generated-refresh
Source by-file UID: 0000LE
```

The current command output for `000000002361` was not captured in this agent console; it is reported here as the latest read-only generated-file header state seen by B010. `tools/validator_command_state.json` also showed validator command activity continuing after B010's captured refresh, so a later supervisor read may legitimately observe a newer validator-owned header.

## Lease Status

- Lease acquisition: `lease_paths.py --agent Agent-B010 --paths ...` succeeded for the 19 by-* callback files before editing.
- Release: `lease_paths.py --agent Agent-B010 --release --paths ...` returned `Rejected[No active lease]` for the same paths after validation.
- Verification: `current_leases.md` scan for `Agent-B010`, `MiniMap`, and `0000LE` returned no rows after release. No active B010 MiniMap leases remain.

## Changed Files

Manual by-* edits:

- `by-file/MiniMap.md`
- `by-memory/0x00452260-0x0045239a.GetControlLayout_452260.md`
- `by-global/GetControlLayout_452260.md`
- `by-memory/0x0067a7c4-0x0067a7c8.g_pMiniMapDialog.md`
- `by-global/g_pMiniMapButtonPane.md`
- `by-memory/0x0069b4b8-0x0069b4bc.g_pMiniMapButtonPane.md`
- `by-global/g_pMiniMapDownloader.md`
- `by-memory/0x0067a7d8-0x0067a7dc.g_pMiniMapDownloader.md`
- `by-memory/0x00610fa4-0x00610fbc.SharedFramePartPaletteResourceString.md`
- `by-class/MiniMapButtonPane.md`
- `by-class/MiniMapDialog.md`
- `by-class/MiniMapDownloader.md`
- `by-class/MiniMapImageControlPane.md`
- `by-class/MiniMapRenderer.md`
- `by-class/MiniMapSymbolControlPane.md`
- `by-memory/0x00450ca0-0x0045381b.MiniMapDialog.md`
- `by-memory/0x00453910-0x00453def.MiniMapDownloader.md`
- `by-memory/0x00453df0-0x004563b5.MiniMapRendererAndControls.md`
- `by-memory/0x00457620-0x00457a5d.MiniMapFileLoaderHelpers.md`
- `tools/leaser/Agents/Agent-B010/research/0000LE-MiniMap-empty-emitter-family-source-quality.md`

Validator-owned/generated updates:

- `auto-generated/NexusTK/map/MiniMap.cpp`
- Project/generated metadata and backup files updated by validator command `000000002256`; `auto-generated/NexusTK/map/MiniMap.cpp` later advanced to validator header `000000002361` in B010's last read-only check; no generated or validator/tool-state file was manually edited.

Unchecked items: none for the accepted callback scope. Supervisor verification/execution remains pending.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B010","command_id":"000000004165","destination_path":"executed-b-agent-research/B010/0000LE-MiniMap-empty-emitter-family-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B010/research/0000LE-MiniMap-empty-emitter-family-source-quality.md","timestamp":"2026-06-30T05:02:30","uid":"0000LE"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
