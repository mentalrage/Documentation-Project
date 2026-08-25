** TARGET-REPORT-UID:0002PL **
** AUTHOR-AGENT-ID:B010 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# Agent-B010 Research Report: [UID:0002PL] LogoPaneConstructor

Report date: 2026-06-25

Assignment: `B010-report-0002PL-logo-pane-constructor-20260625`

Target: [UID:0002PL][0x004f4c10-0x004f4eac.LogoPaneConstructor](../../../../../by-memory/0x004f4c10-0x004f4eac.LogoPaneConstructor.md)

Report-only status: no leases were taken and no by-* documentation, generated output, validator/tool state, lock file, IDA database, or manual coverage report was edited.

## Current State

The target currently carries `COMPLETION:88`, `CONFIDENCE:90`, `CANONICAL_OWNER:00007G`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:00007G`, with a blank formal C++ block. It is already above the code-entry threshold through [UID:00007G][LogoPane](../../../../../by-class/LogoPane.md), which routes to [UID:0000O4][StartupLogoPanes](../../../../../by-file/StartupLogoPanes.md). The current blank C++ rationale cites source-quality blockers around field names, callback wrapper spelling, virtual-slot names, helper ownership, and failure paths.

I rechecked the required context pages: [UID:0002PL], [UID:00019C][LogoPane memory island](../../../../../by-memory/0x004f4c10-0x004f53a8.LogoPane.md), [UID:00007G][LogoPane](../../../../../by-class/LogoPane.md), [UID:0000O4][StartupLogoPanes](../../../../../by-file/StartupLogoPanes.md), [UID:0001RN][startup-logo-media](../../../../../by-resource/startup-logo-media.md), [UID:0000TQ][WideApiDispatchTable](../../../../../by-global/WideApiDispatchTable.md), [UID:0000T6][MainUiLayerSlots](../../../../../by-global/MainUiLayerSlots.md), [UID:00039Y][ScreenPaneCallbackAndFlagHelpers](../../../../../by-memory/0x005590e0-0x0055916b.ScreenPaneCallbackAndFlagHelpers.md), [UID:0003LK][LogoPaneMarkReadyAndScheduleAdvance](../../../../../by-memory/0x004f5040-0x004f506a.LogoPaneMarkReadyAndScheduleAdvance.md), [UID:0002PO][LogoPaneStaticLogoLoaderHelpers](../../../../../by-memory/0x004f50b0-0x004f5246.LogoPaneStaticLogoLoaderHelpers.md), [UID:0002PP][LogoPaneQueueAdvanceToNextScreen](../../../../../by-memory/0x004f5250-0x004f52de.LogoPaneQueueAdvanceToNextScreen.md), [UID:00004I][EPFTileContext](../../../../../by-class/EPFTileContext.md), [UID:00003Z][DLPalette](../../../../../by-class/DLPalette.md), [UID:0003OQ][LogoPaneCallbackVtableData](../../../../../by-memory/0x0061d000-0x0061d018.LogoPaneCallbackVtableData.md), [UID:0001WQ][FunctionObjectTemplates](../../../../../by-type/by-template/FunctionObjectTemplates.md), and [UID:0000S7][g_pScreenPane](../../../../../by-global/g_pScreenPane.md).

Generated `auto-generated/NexusTK/app/StartupLogoPanes.cpp` is stale for this target and still contains an empty emitter marker for [UID:0002PL]. It was used only as a lead and was not edited.

## Live IDA MCP Evidence

Live IDA MCP was available. The active database was session `80de0a67` for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`; `server_health` reported status `ok`, `auto_analysis_ready:true`, and `hexrays_ready:true`.

`lookup_funcs` confirms `0x004f4c10` is `sub_4F4C10`, size `0x29c`, and `0x004f4eac` is not a function start. Bytes at the end of the function show the constructor epilogue `retn 8`, four `0xcc` bytes at `0x004f4eac-0x004f4eaf`, and the next function prologue at `0x004f4eb0`. This validates the documented half-open range `0x004f4c10-0x004f4eac`.

`xrefs_to 0x004f4c10` reports one direct code xref at `0x004f643c` in `sub_4F5FB0` / [UID:0002H7][Application Startup](../../../../../by-memory/0x004f5fb0-0x004f6490.ApplicationStartup.md). That caller checks UTF-16 `NEXON.LGO` at `0x0061d24c`, allocates `0x354` bytes, and constructs `LogoPane` with the logo path and the previously built completion callback. This supports `LogoPane`, not Application, as the constructor owner.

The constructor decompilation shows:

- base pane construction through `0x00544460` with argument `0`;
- `LogoPane` vtable writes at `this+0x00`, `this+0xa0`, and `this+0xa4`;
- `EPFTileContext::Initialize` at `this+0xf8` and `DLPalette` construction at `this+0x120`;
- one word clear at `this+0x34c` for the early-click and ready latches, one byte clear at `this+0x34e`, and storage of the completion callback pointer at `this+0x350`;
- full-screen bounds construction from `g_screenWidth` / `word_66DA94` and `g_screenHeight` / `word_66DA98`;
- `EPFTileContext::ReleaseBuffers` before loading the logo image;
- `_wfopen` dispatch through `0x0069be14` with binary-read mode;
- size-prefixed compressed image read, zlib `Uncompress` at `0x00414390`, decoded pixel storage at `this+0xfc`, row stride at `this+0x104`, rect at `this+0x108`, encoded-mask count/pointer clears at `this+0x118/+0x11c`, and virtual slot `+0x20`;
- size-prefixed palette read, `DLPalette::LoadFromBitmapPalette` at `0x005430a0`, `EPFTileContext::BuildEncodedMask` at `0x00457ab0`, and `fclose` only on the successful palette path;
- surface attachment through the layer slot global at `0x0069b36c` and a follow-up virtual call with `(0, 0)`;
- allocation of a 24-byte `PlainMemberFunctionObject0<LogoPane>` callback, storage of callback target `0x004f5040`, zero `this` adjustment, captured `this`, and queueing through `ScreenPane::QueueFadeInCallback` at `0x005590e0`.

`insn_query` in the constructor confirms the important operand sites: `call dword ptr unk_69BE14` at `0x004f4cd9`, `push dword ptr unk_69B36C` at `0x004f4e20`, `PlainMemberFunctionObject0<LogoPane>` vtable store at `0x004f4e61`, callback target store `0x004f5040` at `0x004f4e67`, and queue call to `0x005590e0` at `0x004f4e87`.

`xrefs_to 0x0061d000` returns constructor and queue sites at `0x004f4e61` and `0x004f529f`. IDA names the vtable `??_7?$PlainMemberFunctionObject0@P8LogoPane@@AEXXZV1@@@6B@`, matching the documented concrete zero-argument member callback wrapper. The template guidance in [UID:0001WQ] supports the source-facing declaration `PlainMemberFunctionObject0<TMember, TObject>` with constructor arguments `(callback, thisAdjust, object)`.

## Source-Quality Reanalysis

Field names are now strong enough for a first draft:

| Offset | Recommended source name | Evidence |
| --- | --- | --- |
| `this+0xf8` | `m_logoTileContext` | [UID:00007G] and [UID:00004I] agree this is an `EPFTileContext`; constructor initializes, releases, populates, builds encoded mask, and passes its bounds to attach. |
| `this+0x120` | `m_logoPalette` | [UID:00007G] and [UID:00003Z] agree this is a `DLPalette`; constructor loads palette bytes through `LoadFromBitmapPalette`. |
| `this+0x34c` | `m_advanceRequestedBeforeReady` | Cleared by constructor; [UID:0003LK] uses it to choose zero-delay versus 3000 ms scheduling after the logo is ready. |
| `this+0x34d` | `m_logoReady` | Cleared by constructor and set by [UID:0003LK] before scheduling advance. |
| `this+0x34e` | `m_advanceQueued` | Cleared by constructor and set by [UID:0002PP] before queueing the next-screen transition. |
| `this+0x350` | `m_completionCallback` | Constructor stores the incoming callback; transition logic owns the eventual terminal/startup continuation. |

The callback wrapper blocker is resolved for first-draft quality. The raw decorated IDA vtable name proves the member-function pointer type shape, while the shared template docs support spelling the construction as:

```cpp
typedef void (__thiscall LogoPane::*LogoPaneCallback0)();
new PlainMemberFunctionObject0<LogoPaneCallback0, LogoPane>(
    &LogoPane::MarkReadyAndScheduleAdvance, 0, this)
```

The virtual-slot names remain behaviorally reconstructed, so they should cap the score below final audit, but they are not a blank-code blocker. Use the existing source-facing names already present in the LogoPane retained-helper research: `OnBoundsChangedOrInvalidate(0)`, `AttachSurface(...)`, and `SetSurfaceOriginOrVisibleState(0, 0)`.

Failure behavior must be preserved exactly. If the file fails to open, the constructor still attaches the pane surface and queues the fade-in callback. If any read fails after opening, the binary does not close the file and does not run normal cleanup for already allocated partial buffers. The first draft below intentionally uses one `attach_static_logo` label to preserve those fall-through/leak paths. Do not "fix" this into RAII or cleanup logic during the first incorporation.

## Ownership And Placement

Keep [UID:0002PL] owned by [UID:00007G][LogoPane](../../../../../by-class/LogoPane.md) and emitted through `EMITTER_UIDS:00007G`, with the file route through [UID:0000O4][StartupLogoPanes](../../../../../by-file/StartupLogoPanes.md). The constructor mutates `LogoPane` fields, installs `LogoPane` vtables, builds a `LogoPane` callback, and is called by Application only as a startup object construction site.

Reject alternative owners:

- [UID:00019C] is a non-emitting class-island inventory and should stay non-emitting.
- [UID:0000O4] is the source-file route, not the direct semantic owner.
- [UID:0001RN] documents the `.LGO` resource contract, not code ownership.
- [UID:0000TQ] owns the wide API dispatch global; the constructor is only a consumer of `_wfopen`.
- [UID:0000T6] owns main UI layer-slot globals; the constructor is only a consumer of slot `0x0069b36c`.
- [UID:00039Y] owns the shared `ScreenPane` fade queue helper; the constructor is only a caller.
- [UID:0002PO] should remain blank as retained/static helper evidence because route scans to those helper starts are negative and the constructor contains the active inline load/attach flow.
- [UID:0003OQ] should remain generated-template/vtable data under `FunctionObjects`; source should construct the callback object and let the compiler emit the vtable.

Recommendation: update [UID:0002PL] to `COMPLETION:90` and `CONFIDENCE:92`. Completion rises because the constructor is now implementation-ready with a formal first-draft body and resolved ownership/source-placement. Confidence rises because live MCP confirms the range, one caller, callback vtable/type, queue target, global consumers, and failure paths. Do not raise above this band until the behavioral virtual-slot names and final original template/header spelling are coordinated across `LogoPane`, `Pane`, and `FunctionObjects`.

## Formal First-Draft C++ For [UID:0002PL]

Recommended exact target insertion text:

```cpp
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00007G | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00007G | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
LogoPane::LogoPane(const wchar_t *logoPath, FunctionObject0 *completionCallback)
    : Pane(0)
{
    m_logoTileContext.Initialize();
    m_advanceRequestedBeforeReady = false;
    m_logoReady = false;
    m_advanceQueued = false;
    m_completionCallback = completionCallback;

    RectBounds fullScreenBounds;
    fullScreenBounds.SetLTRB(0, 0, g_screenWidth, g_screenHeight);
    SetBounds(&fullScreenBounds);

    m_logoTileContext.ReleaseBuffers();

    FILE *logoFile = g_pfnWideOpenFile(logoPath, L"rb");
    if (logoFile != 0) {
        unsigned int compressedImageSize = 0;
        if (fread(&compressedImageSize, sizeof(compressedImageSize), 1, logoFile) != 1) {
            goto attach_static_logo;
        }

        unsigned char *compressedImage =
            static_cast<unsigned char *>(malloc(compressedImageSize));
        if (fread(compressedImage, 1, compressedImageSize, logoFile) != compressedImageSize) {
            goto attach_static_logo;
        }

        uLongf decodedImageSize = static_cast<uLongf>(g_screenWidth * g_screenHeight);
        unsigned char *decodedImage =
            static_cast<unsigned char *>(malloc(decodedImageSize));
        Uncompress(decodedImage, &decodedImageSize, compressedImage, compressedImageSize);
        free(compressedImage);

        m_logoTileContext.pixelData = decodedImage;
        m_logoTileContext.encodedMaskBytes = 0;
        m_logoTileContext.rowStridePixels = g_screenWidth;
        m_logoTileContext.encodedMaskByteCount = 0;
        m_logoTileContext.bounds.SetLTRB(0, 0, g_screenWidth, g_screenHeight);
        OnBoundsChangedOrInvalidate(0);

        unsigned int paletteSize = 0;
        if (fread(&paletteSize, sizeof(paletteSize), 1, logoFile) != 1) {
            goto attach_static_logo;
        }

        unsigned char *paletteBytes =
            static_cast<unsigned char *>(malloc(paletteSize));
        if (fread(paletteBytes, 1, paletteSize, logoFile) != paletteSize) {
            goto attach_static_logo;
        }

        m_logoPalette.LoadFromBitmapPalette(paletteBytes, paletteSize);
        free(paletteBytes);
        m_logoTileContext.BuildEncodedMask();
        fclose(logoFile);
    }

attach_static_logo:
    AttachSurface(&m_logoTileContext.bounds, 0, 0, g_mainUiLayerSlots.overlayPaneLayerContext);
    SetSurfaceOriginOrVisibleState(0, 0);

    typedef void (__thiscall LogoPane::*LogoPaneCallback0)();
    g_pScreenPane->QueueFadeInCallback(
        new PlainMemberFunctionObject0<LogoPaneCallback0, LogoPane>(
            &LogoPane::MarkReadyAndScheduleAdvance, 0, this));
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

## Support-Doc Changes Needed During Incorporation

Update [UID:0002PL] with the formal block above, the `90/92` score, and a score rationale stating that remaining caps are virtual-slot original-name proof and project-wide template/header spelling, not behavior or ownership.

Update [UID:00007G] only if needed to make the constructor's field names explicit on the class page: `m_advanceRequestedBeforeReady`, `m_logoReady`, `m_advanceQueued`, and `m_completionCallback`, plus the local callback typedef shape `void (__thiscall LogoPane::*)()`.

Do not change [UID:00019C] from non-emitting inventory status. Do not add constructor code to [UID:0002PO] retained helpers. Do not emit raw callback vtable bytes under [UID:0003OQ]. Do not hand-edit generated `auto-generated` files or coverage reports.

## Implementation Tracking Checklist

- [x] Acquire short leases only for the exact by-* pages needed for incorporation.
  - Proof: B010 leased only `by-memory/0x004f4c10-0x004f4eac.LogoPaneConstructor.md`, `by-class/LogoPane.md`, `by-memory/0x004f4c10-0x004f53a8.LogoPane.md`, and `by-file/StartupLogoPanes.md` immediately before edits. No generated/project-level files, coverage reports, [UID:0002PO], or callback-vtable data pages were leased or edited.
- [x] Update [UID:0002PL] metadata to `COMPLETION:90` and `CONFIDENCE:92`.
  - Proof: `by-memory/0x004f4c10-0x004f4eac.LogoPaneConstructor.md` now has `COMPLETION:90`, `CONFIDENCE:92`, `CANONICAL_OWNER:00007G`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00007G`, and blank `EMITTER_POSITION_OPTIONAL`.
- [x] Insert the formal [UID:0002PL] `RECONSTRUCTION_CPP CODE` block exactly as recommended above unless supervisor review requires a named-rule adjustment.
  - Proof: the target formal block now contains only the constructor body between `RECONSTRUCTION_CPP CODE:BEGIN` and `END`, with no metadata header lines pasted into the body. The code preserves file-open/read/palette failure fallthrough to `attach_static_logo`, uses the accepted source-facing fields and `PlainMemberFunctionObject0<LogoPaneCallback0, LogoPane>` callback route, and does not add RAII cleanup normalization.
- [x] Add or confirm the [UID:00007G] class field-name notes for `+0x34c`, `+0x34d`, `+0x34e`, and `+0x350`.
  - Proof: `by-class/LogoPane.md` now records `m_advanceRequestedBeforeReady`, `m_logoReady`, `m_advanceQueued`, and `m_completionCallback`, plus constructor first-draft readiness, signature, and zero-argument member-callback route.
- [x] Keep [UID:00019C] non-emitting and keep [UID:0002PO] retained-helper C++ blank.
  - Proof: `by-memory/0x004f4c10-0x004f53a8.LogoPane.md` still has `RECONSTRUCTABLE:FALSE` and blank `EMITTER_UIDS`/C++ while its constructor row now records [UID:0002PL] as a first-draft emitted child. [UID:0002PO] was inspected before implementation, was not edited, and its formal C++ block remains blank.
- [x] Keep [UID:0003OQ] as compiler-generated callback vtable data under `FunctionObjects`; do not emit raw vtable bytes.
  - Proof: [UID:0003OQ] was inspected before implementation, was not edited, and its formal C++ block remains blank. The support docs describe the source callback construction route instead of emitting raw vtable bytes.
- [x] Run the required validator after the leased edit batch.
  - Proof: all scoped validators were run from `source-3/project-documentation` with `--apply --queue-timeout 240 --wait-generated` and exited 0 with `ok: 1`:
    - `python .\tools\validator.py --mode file --file by-memory/0x004f4c10-0x004f4eac.LogoPaneConstructor.md --apply --queue-timeout 240 --wait-generated` -> `command_id: 000000001470`, `command_timestamp: 2026-06-25T13:43:50-04:00`, `generated_refresh: completed`.
    - `python .\tools\validator.py --mode file --file by-class/LogoPane.md --apply --queue-timeout 240 --wait-generated` -> `command_id: 000000001471`, `command_timestamp: 2026-06-25T13:44:06-04:00`, `generated_refresh: completed`.
    - `python .\tools\validator.py --mode file --file by-memory/0x004f4c10-0x004f53a8.LogoPane.md --apply --queue-timeout 240 --wait-generated` -> `command_id: 000000001474`, `command_timestamp: 2026-06-25T13:44:22-04:00`, `generated_refresh: completed`.
    - `python .\tools\validator.py --mode file --file by-file/StartupLogoPanes.md --apply --queue-timeout 240 --wait-generated` -> `command_id: 000000001477`, `command_timestamp: 2026-06-25T13:44:38-04:00`, `generated_refresh: completed`.
  - Validator side effects observed: generated metadata/coverage refreshes completed, `auto-generated/-ag-coverage-report-by-memory.md` and generated C++/autogen reports refreshed where reported, `project-level/-auto-completion-stats.md` projected stats updated, `tools/validator.ini` registry/autogen state updated by validator, and validator autogen backups were created. Known unrelated/stale registry diagnostics remain for missing registered files and missing child UIDs such as `0003L*`; no manual validator-state edits were made.
- [x] Release leases immediately after the edit/validator batch.
  - Proof: `python .\tools\leaser\leaser.py B010 unlease ...` after validation returned `Rejected[No active lease]` for all four leased docs because the short leases had already expired. The subsequent `tools/leaser/Agents/current_leases.md` check showed no active B010 leases.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B010","command_id":"000000004165","destination_path":"executed-b-agent-research/B010/0002PL-LogoPaneConstructor-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B010/research/0002PL-LogoPaneConstructor-source-quality.md","timestamp":"2026-06-25T13:47:15","uid":"0002PL"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
