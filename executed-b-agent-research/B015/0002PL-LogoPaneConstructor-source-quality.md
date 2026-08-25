** TARGET-REPORT-UID:0002PL **
** AUTHOR-AGENT-ID:B015 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# Agent-B015 Research Report: 0002PL LogoPaneConstructor

## Scope

- Agent: B015
- Assignment: `B015-report-0002PL-logo-pane-constructor-20260625`
- Mode: report-only research first
- Target: [UID:0002PL] `by-memory/0x004f4c10-0x004f4eac.LogoPaneConstructor.md`
- Required action now: research report only. No by-* implementation edits were made.

## Recommendation

Implement first-draft C++ for [UID:0002PL] in the next supervisor-approved implementation callback.

Keep the existing owner/emitter route:

- `CANONICAL_OWNER:00007G` (`LogoPane`)
- `EMITTER_UIDS:00007G`
- file route through [UID:0000O4] `StartupLogoPanes`
- `RECONSTRUCTABLE:TRUE`

Recommended target score after implementation: `COMPLETION:90`, `CONFIDENCE:92`.

The old blank-C++ blocker is no longer persuasive for this exact constructor. The target is routed, reconstructable, and currently `88/90`, so the code-entry gate is already cleared. The remaining uncertainty is spelling-level and source-presentation-level, not behavior-level.

## Current IDA MCP Evidence

IDA MCP was available and current. I used server `ida-pro-mcp` through database/session `80de0a67`, with `server_health` reporting `status: ok`, `auto_analysis_ready: true`, and `hexrays_ready: true` for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.

Live facts gathered for this report:

- `lookup_funcs` reports `0x004f4c10` as `sub_4F4C10`, size `0x29c`; `0x004f4eac` is not a function start; the next function starts at `0x004f4eb0`.
- `analyze_function 0x004f4c10` reports one direct caller, `sub_4F5FB0`, and the constructor xref at `0x004f643c`.
- `get_bytes` confirms the target ends at `0x004f4eac`: `0x004f4ea8 pop ebp`, `0x004f4ea9 retn 8`, then `0xcc` padding at `0x004f4eac-0x004f4eaf`, followed by the next prologue at `0x004f4eb0`.
- Caller disassembly for `sub_4F5FB0` confirms the active startup path:
  - `0x004f6401` pushes `off_61D24C` (`NEXON.LGO`) for the path-existence probe.
  - `0x004f6419` pushes allocation size `0x354`.
  - `0x004f6435` pushes `off_61D24C` as the constructor path argument.
  - `0x004f643c` calls `sub_4F4C10` with the allocated object in `ecx` and a `PlainMemberFunctionObject0<BaramApp>` completion callback as the second argument.
- Constructor disassembly confirms:
  - base `Pane` construction at `0x004f4c48`;
  - `LogoPane` vtable stores at `0x004f4c5a`, `0x004f4c60`, and `0x004f4c6a`;
  - `EPFTileContext` initialization at `this+0xf8` via `0x00457a60`;
  - `DLPalette` initialization at `this+0x120` via `0x00542bb0`;
  - flag clearing at `+0x34c/+0x34d/+0x34e` and completion callback store at `+0x350`;
  - full-screen bounds from `g_screenWidth` / `g_screenHeight` and `SetBounds` call at `0x004f4cb8-0x004f4cc3`;
  - `_wfopen` dispatch through `0x0069be14` at `0x004f4cd9` with mode `"rb"`;
  - `.LGO` compressed-image read, allocation, `Uncompress` call at `0x004f4d61`, decoded pixel/context field stores at `0x004f4d71-0x004f4db2`, and virtual invalidation/update slot at `0x004f4dbd`;
  - palette blob read, `DLPalette::LoadFromBitmapPalette` at `0x004f4dfe`, `EPFTileContext::BuildEncodedMask` at `0x004f4e12`, and `fclose` at `0x004f4e18`;
  - attach/position virtuals at `0x004f4e20-0x004f4e40` using `0x0069b36c`;
  - 24-byte `PlainMemberFunctionObject0<LogoPane>` allocation, vtable `0x0061d000`, target `0x004f5040`, captured `this`, and `ScreenPane::QueueFadeInCallback` call at `0x004f4e87`.
- `xrefs_to` confirms:
  - `0x0061d000` callback vtable is referenced only by the constructor at `0x004f4e61` and the fade-out queue helper at `0x004f529f`;
  - callback target `0x004f5040` has the constructor data xref at `0x004f4e67`;
  - `ScreenPane::QueueFadeInCallback` `0x005590e0` has the direct constructor call at `0x004f4e87`;
  - `NEXON.LGO` string `0x0061d24c` has the two startup refs at `0x004f6401` and `0x004f6435`.

## Source-Quality Analysis

The source route should remain `LogoPane` under `StartupLogoPanes.cpp`. `ApplicationStartup` constructs and consumes the pane but does not own the constructor body. `WideApiDispatchTable`, `MainUiLayerSlots`, `EPFTileContext`, `DLPalette`, `FunctionObjects`, `ScreenPane`, and zlib/`Uncompress` are dependencies, not owners.

The constructor should emit the inline static-logo load path instead of delegating to [UID:0002PO] `LogoPaneStaticLogoLoaderHelpers`. The helper page remains valid as retained out-of-line source-authored code with no direct start xrefs, but `0002PL` is a promoted direct constructor with an active startup caller and a fully duplicated inline load/attach sequence. That is enough to populate constructor C++ while leaving the retained helper formal C++ blank.

Recommended source-facing names:

- `LogoPane::LogoPane(const wchar_t *logoPath, FunctionObject0 *completionCallback)`
- `m_logoTileContext` at `+0xf8`
- `m_logoPalette` at `+0x120`
- `m_advanceRequestedBeforeReady` at `+0x34c`
- `m_logoReady` at `+0x34d`
- `m_advanceQueued` at `+0x34e`
- `m_completionCallback` at `+0x350`
- `g_pfnWideOpenFile` for the `_wfopen` dispatch slot at `0x0069be14`
- `g_mainUiLayerSlots.overlayPaneLayerContext` for the `0x0069b36c` layer/context slot
- `MarkReadyAndScheduleAdvance` for callback target `0x004f5040`

Names still capped below final-audit confidence:

- `OnBoundsChangedOrInvalidate`
- `AttachSurface`
- `SetSurfaceOriginOrVisibleState`
- exact `PlainMemberFunctionObject0<LogoPane>` template spelling
- exact original spelling for the main UI layer slot

Those are not enough to keep the constructor blank. They are normal first-draft C++ caveats and justify the recommended `90/92` cap rather than `95+`.

## Rejected Alternatives

- No-code/blank C++: rejected. The target is reconstructable, routed, above the current code-entry score gate, has a direct caller, exact range, and defensible source-facing names.
- Move ownership to `ApplicationStartup`: rejected. The caller at `0x004f643c` supplies the path/callback and allocates the object; the method body mutates `LogoPane` fields and installs `LogoPane` vtables.
- Move ownership to `EPFTileContext`, `DLPalette`, zlib, PlatformApi, MainUiGraph, or FunctionObjects: rejected. Each is a dependency. The constructor composes their services in feature-specific startup-logo logic.
- Merge [UID:0002PO] helper C++ into the helper formal block first: rejected for this callback. `0002PO` remains no-xref retained helper evidence. The constructor is the active direct emission site.
- Emit vtable/callback data pages as hand-written data: rejected. Vtables and concrete callback vtables are compiler/template output; source should express the constructor, callback allocation, and callback queueing.
- Normalize failure cleanup with RAII: rejected for first-draft binary-faithful C++. The binary closes the file only on the fully successful palette path, and the retained-helper page already warns not to silently normalize this behavior.

## First-Draft C++ Recommendation

Use this as the implementation callback's formal C++ basis for `0002PL`, with any project-standard callback-template spelling adjustment made during implementation:

```cpp
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

    uint32_t compressedSize = 0;
    uint8_t *compressed = nullptr;
    uLongf decodedSize = 0;
    uint8_t *decoded = nullptr;
    uint32_t paletteSize = 0;
    uint8_t *paletteBlob = nullptr;

    FILE *file = g_pfnWideOpenFile(logoPath, L"rb");
    if (file != nullptr) {
        if (fread(&compressedSize, sizeof(compressedSize), 1, file) != 1)
            goto attach_static_logo;

        compressed = static_cast<uint8_t *>(std::malloc(compressedSize));
        if (fread(compressed, 1, compressedSize, file) != compressedSize)
            goto attach_static_logo;

        decodedSize = static_cast<uLongf>(
            static_cast<int>(g_screenWidth) * static_cast<int>(g_screenHeight));
        decoded = static_cast<uint8_t *>(std::malloc(decodedSize));
        Uncompress(decoded, &decodedSize, compressed, compressedSize);
        std::free(compressed);

        m_logoTileContext.pixelData = decoded;
        m_logoTileContext.encodedMaskBytes = nullptr;
        m_logoTileContext.rowStridePixels = g_screenWidth;
        m_logoTileContext.encodedMaskByteCount = 0;
        m_logoTileContext.bounds.SetLTRB(0, 0, g_screenWidth, g_screenHeight);
        OnBoundsChangedOrInvalidate(0);

        if (fread(&paletteSize, sizeof(paletteSize), 1, file) != 1)
            goto attach_static_logo;

        paletteBlob = static_cast<uint8_t *>(std::malloc(paletteSize));
        if (fread(paletteBlob, 1, paletteSize, file) != paletteSize)
            goto attach_static_logo;

        m_logoPalette.LoadFromBitmapPalette(paletteBlob, paletteSize);
        std::free(paletteBlob);
        m_logoTileContext.BuildEncodedMask();
        fclose(file);
    }

attach_static_logo:
    AttachSurface(&m_logoTileContext.bounds, 0, 0, g_mainUiLayerSlots.overlayPaneLayerContext);
    SetSurfaceOriginOrVisibleState(0, 0);

    g_pScreenPane->QueueFadeInCallback(
        new PlainMemberFunctionObject0<LogoPane>(
            this,
            &LogoPane::MarkReadyAndScheduleAdvance));
}
```

Notes on this draft:

- The `goto attach_static_logo` structure is intentional. It preserves the observed binary behavior where early read failures still attach and queue fade-in, and where `fclose` is only reached after the palette path succeeds.
- `Initialize()`, `pixelData`, `rowStridePixels`, `encodedMaskByteCount`, `encodedMaskBytes`, and `BuildEncodedMask()` follow the current [UID:00004I] `EPFTileContext` class page rather than older helper-draft names.
- The callback construction can be syntax-adjusted to the final project template declaration, but it should stay a `PlainMemberFunctionObject0<LogoPane>`-style zero-argument callback targeting `LogoPane::MarkReadyAndScheduleAdvance`.

## Metadata Recommendation

For [UID:0002PL]:

- `COMPLETION:90`
- `CONFIDENCE:92`
- `CANONICAL_OWNER:00007G`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:00007G`
- `EMITTER_POSITION_OPTIONAL:` unchanged

Rationale:

- Completion rises because the constructor can now carry first-draft C++ and the old blank-code blocker is resolved for this exact direct function.
- Confidence rises because live IDA MCP reconfirmed range, caller, boundary padding, vtable writes, resource string xrefs, `.LGO` loader sequence, palette/mask sequence, layer attach sequence, and callback queueing.
- Scores should stay below `95` because exact original names for the attach/invalidation virtuals, layer slot, and callback template declaration are still inferred, and the failure-cleanup source form is intentionally binary-faithful rather than polished source.

## Generated/Tracker State

Report-time generated outputs were stale:

- `auto-generated/-ag-research-tracker.md` still reported `0002PL` as `74/86`.
- `auto-generated/-ag-coverage-report-by-memory.md` still reported stale not-covered/no-emits state.
- `auto-generated/NexusTK/app/StartupLogoPanes.cpp` had an empty emitter marker for `0002PL` and stale `74/86` marker text.

Do not edit those generated files by hand. After an implementation callback updates or verifies the source docs, run the scoped validator/autogen refresh so these generated files reconcile automatically.

## Implementation Callback Results

2026-06-26 B015 implementation callback outcome:

- MCP availability: IDA MCP was available before implementation. Session `80de0a67` for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64` reported `server_health` status `ok`, `auto_analysis_ready:true`, and `hexrays_ready:true`; no IDA database mutation tools were used.
- By-* incorporation: the accepted target/support content was already present at report-level detail when this callback started. [UID:0002PL] already had `COMPLETION:90`, `CONFIDENCE:92`, owner/emitter [UID:00007G], and formal `LogoPane::LogoPane(const wchar_t *logoPath, FunctionObject0 *completionCallback)` C++ preserving the binary-faithful failure fallthrough. `by-class/LogoPane.md`, the aggregate `by-memory/0x004f4c10-0x004f53a8.LogoPane.md`, and `by-file/StartupLogoPanes.md` already carried the constructor-emission, field-name, callback, retained-helper, and static-logo/video split notes accepted by this report.
- No duplicate by-* prose was added. Existing by-* attribution remains on the already-applied B010 implementation state rather than inventing a second B015 change-log entry with no content change.
- Optional support exclusions: `by-resource/startup-logo-media.md` already records the `.LGO` format, `NEXON.LGO` xrefs, constructor/retained-helper consumers, and missing-current-payload caveat; no resource score change was accepted. [UID:0002PO] already records retained no-xref helper status and intentionally blank formal C++; no clarification edit was needed.
- Leases: B015 leased only `by-memory/0x004f4c10-0x004f4eac.LogoPaneConstructor.md`, `by-class/LogoPane.md`, `by-memory/0x004f4c10-0x004f53a8.LogoPane.md`, and `by-file/StartupLogoPanes.md` for the immediate validator batch, then released all four. `tools/leaser/Agents/Agent-B015/current_leases.md` had no active `Agent-B015` rows after release.
- Validators:
  - `python .\tools\validator.py --mode file --file by-memory\0x004f4c10-0x004f4eac.LogoPaneConstructor.md --apply --queue-timeout 240` -> command `000000002069`, `ok: 1`; nonfatal `missing_ref_uid 00039Y` reference-index warning only.
  - `python .\tools\validator.py --mode file --file by-class\LogoPane.md --apply --queue-timeout 240` -> command `000000002070`, `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-memory\0x004f4c10-0x004f53a8.LogoPane.md --apply --queue-timeout 240` -> command `000000002071`, `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-file\StartupLogoPanes.md --apply --queue-timeout 240` -> command `000000002072`, `ok: 1`.
- Generated refresh proof: `auto-generated/NexusTK/app/StartupLogoPanes.cpp` refreshed at command `000000002072` / `2026-06-26T01:33:57-04:00` and now emits the `0002PL` constructor with `Completion:90 | Confidence:92`. The deferred generated tracker/coverage pass was observed at least through command `000000002075` / `2026-06-26T01:36:12-04:00`; `auto-generated/-ag-research-tracker.md` lists `0002PL` as `90/92`, reconstructable `true`, emitted, and `auto-generated/-ag-coverage-report-by-memory.md` lists `0002PL` as `emits_code:true`, `reconstructable`, `90%`, `very-strong`.
- Raw/blank-marker inspection: targeted checks of the formal target C++ block and generated `StartupLogoPanes.cpp` found no `sub_`, `dword_`, `No generated code`, `empty emitter`, or stale `74/86` marker. The remaining `sub_`/`dword_` strings in the target page are evidence prose, not unresolved emitted source.

## Implementation Tracking Checklist

- [x] Lease/check `by-memory/0x004f4c10-0x004f4eac.LogoPaneConstructor.md`: source already had score `90/92`, owner/emitter route [UID:00007G], formal constructor C++, current MCP evidence, and no stale blank-C++ blocker. Held the file for validator command `000000002069`, then released it.
- [x] Lease/check `by-class/LogoPane.md`: source already recorded constructor first-draft readiness/emission, `FunctionObject0 *m_completionCallback`, flags at `+0x34c/+0x34d/+0x34e`, and the retained-helper blank-C++ caveat. Held the file for validator command `000000002070`, then released it.
- [x] Lease/check `by-memory/0x004f4c10-0x004f53a8.LogoPane.md`: source already records `0002PL` as a `90/92` emitted constructor child, not an empty emitted marker. Held the file for validator command `000000002071`, then released it.
- [x] Lease/check `by-file/StartupLogoPanes.md`: source already records `LogoPane::LogoPane(const wchar_t *, FunctionObject0 *)` as first-draft emitted C++ and preserves the broader static-logo/video split caveats. Held the file for validator command `000000002072`, then released it.
- [x] Considered `by-resource/startup-logo-media.md`: no edit made because the page already preserves the accepted `.LGO` path/format evidence and no resource score or new supervisor-required MCP note was accepted.
- [x] Did not edit `by-memory/0x004f50b0-0x004f5246.LogoPaneStaticLogoLoaderHelpers.md`: concrete reason is unchanged accepted policy, retained no-xref helper evidence with intentionally blank formal C++.
- [x] Did not edit `WideApiDispatchTable`, `MainUiLayerSlots`, `ScreenPaneCallbackAndFlagHelpers`, `FunctionObjects`, `EPFTileContext`, `DLPalette`, `g_screenWidth`, `g_screenHeight`, or vtable-data pages: validators did not require those support edits, and current docs already support the constructor.
- [x] Ran the scoped validator/autogen refresh and confirmed generated outputs: commands `000000002069` through `000000002072` all returned `ok: 1`; generated `StartupLogoPanes.cpp`, memory coverage, and research tracker now show `0002PL` as emitted `90/92`. Generated files were not hand-edited.
- [x] Inspected validator/formal-output state for unresolved raw `sub_`, `dword_`, or blank emitter markers related to `0002PL`: no such strings appear in the formal constructor block or generated `StartupLogoPanes.cpp`; the only target-page raw labels are evidence prose. The sole validator warning was nonfatal `missing_ref_uid 00039Y`, and the referenced document exists.

## Report Standard Checklist

- [x] Used current IDA MCP evidence; report is not fallback-only.
- [x] Covered exact range, padding, and caller/source route.
- [x] Covered static-logo image/palette load path and resource string evidence.
- [x] Covered vtable setup and compiler-generated data handling.
- [x] Covered ready-callback queueing and callback object evidence.
- [x] Covered owner/emitter route and rejected alternatives.
- [x] Reanalyzed score/source-quality blockers under current code-entry rules.
- [x] Provided first-draft C++ recommendation.
- [x] Provided implementation tracking checklist; callback section now checks it with proof.
- [x] Made no report-phase by-* implementation edits and no manual generated/coverage/tool-state edits; callback used validators only for generated refresh.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B015","command_id":"000000004165","destination_path":"executed-b-agent-research/B015/0002PL-LogoPaneConstructor-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B015/research/0002PL-LogoPaneConstructor-source-quality.md","timestamp":"2026-06-26T01:40:29","uid":"0002PL"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
