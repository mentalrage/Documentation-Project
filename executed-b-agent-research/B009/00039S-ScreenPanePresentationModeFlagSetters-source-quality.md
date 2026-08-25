** TARGET-REPORT-UID:00039S **
** AUTHOR-AGENT-ID:B009 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00039S ScreenPanePresentationModeFlagSetters Source-Quality Reanalysis

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:00039S][0x00557820-0x00557838.ScreenPanePresentationModeFlagSetters](../../../../../by-memory/0x00557820-0x00557838.ScreenPanePresentationModeFlagSetters.md) as a reconstructable ScreenPane helper pair owned/emitted by [UID:0000NB][ScreenPane](../../../../../by-file/ScreenPane.md) at `COMPLETION:88`, `CONFIDENCE:91`.
- Current target state after supervisor validator command `000000006858`: target metadata and formal C++ are already repaired. The page now emits `ScreenPane::EnablePresentationMode()` and `ScreenPane::DisablePresentationMode()` using inferred field `m_presentationModeEnabled`.
- Best target name: `ScreenPanePresentationModeFlagSetters` remains acceptable. The source-facing method names should remain `ScreenPane::EnablePresentationMode()` and `ScreenPane::DisablePresentationMode()`.
- Best field name: `ScreenPane::m_presentationModeEnabled`, with `m_gamePresentationActive` as the only meaningful alternate if a later source-layout pass prefers gameplay lifecycle wording. The spelling is inferred, not recovered from symbols.
- Final disposition: source-authored tiny ScreenPane method pair. This is not Surface-owned code, ScreenshotCapture code, MainUiGraph code, MapPane code, raw JPG liveness evidence, or compiler-generated thunk/padding.
- Current callback result: Gate 1 passed at SHA256 `E0EE62C125D8AD53513DB96E4A245E43590D8C0D5B75DC3E948C1548D1498431`; B009 verified each accepted claim against the target and listed support docs. No target/support by-* edit was needed because current docs already carry the accepted facts at same-or-greater detail after the supervisor-run file repair and prior support synchronizations.
- Score recommendation: keep current `COMPLETION:88`, `CONFIDENCE:91`. Current MCP now removes the old "live IDA MCP unavailable" blocker; the remaining cap below 95 is the inferred original member/method spelling and broader presentation-family source-boundary uncertainty, not behavior, owner, range, or code shape.

## Supporting Research

- Historical de-execution state: the active repair copy previously carried top-level validator status lines `REPORT-VALIDATION-STATUS: needs-revalidation` and `REPORT-REVALIDATION-REASON: target_uid_unknown: 00039S`. Per supervisor override, B009 removed only those two top-level lines and historicalized them here. The validator-owned `VALIDATOR-REPORT-HISTORY` footer remains unchanged.
- Historical validator lifecycle: footer command `000000004167` marked the old executed report `needs-revalidation` for `target_uid_unknown: 00039S`; footer command `000000006856` returned the report to active B009 research for rework.
- Supervisor validator repair incorporated: command `000000006858` ran `python .\tools\validator.py --mode file --file by-memory/0x00557820-0x00557838.ScreenPanePresentationModeFlagSetters.md --apply --queue-timeout 240` at `2026-07-05T07:01:14-04:00`, exited `0`, reported `ok: 1`, and updated the target path/UID mapping, completion `88`, confidence `91`, canonical owner `0000NB`, autogen registry/reference indexes, projected stats, and deferred generated refresh.
- Current MCP correction: the older report body said MCP was unavailable. That statement is now stale. On 2026-07-05, B009 used JSON-RPC `initialize`, `tools/list`, `idb_list`, `server_health`, and exact-address MCP calls against active session `supervisor_recovery_20260705`; those calls are recorded in `Evidence Checked`.
- Callback verification result: B009 re-read the target plus `by-file/ScreenPane.md`, `by-class/ScreenPane.md`, `SurfacePresentation`, `SurfaceMinimapRenderInitializer`, `InitializeMainUiGraph`, `MapPaneExitToMenuTeardown`, and `ScreenshotJpegCapturePath`; every accepted UID00039S fact was already present or explicitly not applicable. B009 updated only this report's ledger/checklist and did not edit target/support by-* docs, generated files, manual `-coverage-report.md` files, validator state, queue/lock files, lifecycle/archive files, executed-report records, supervisor ledgers, or report-history footer comments. No leases were needed.

## Target

- Target UID: `00039S`
- Current target path: `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x00557820-0x00557838.ScreenPanePresentationModeFlagSetters.md`
- Current supervisor classification: repaired source-quality report for reconstructable ScreenPane target.
- Direct target owner/emitter: [UID:0000NB][ScreenPane](../../../../../by-file/ScreenPane.md), source route `NexusTK/ui/core/ScreenPane.cpp`.
- Related support docs checked: [UID:0000CB][ScreenPane](../../../../../by-class/ScreenPane.md), [UID:0000S7][g_pScreenPane](../../../../../by-global/g_pScreenPane.md), [UID:0001OX][0x0067a7cc-0x0067a7d0.g_pScreenPane](../../../../../by-memory/0x0067a7cc-0x0067a7d0.g_pScreenPane.md), [UID:0001G6][0x00557140-0x00559aef.SurfacePresentation](../../../../../by-memory/0x00557140-0x00559aef.SurfacePresentation.md), [UID:00039W][0x00558840-0x00558f63.SurfaceMinimapRenderInitializer](../../../../../by-memory/0x00558840-0x00558f63.SurfaceMinimapRenderInitializer.md), [UID:00019K][0x004f7d10-0x004f8b2a.InitializeMainUiGraph](../../../../../by-memory/0x004f7d10-0x004f8b2a.InitializeMainUiGraph.md), [UID:0002QH][0x005047f0-0x00504b6b.MapPaneExitToMenuTeardown](../../../../../by-memory/0x005047f0-0x00504b6b.MapPaneExitToMenuTeardown.md), and [UID:0001G8][0x00557840-0x00557a95.ScreenshotJpegCapturePath](../../../../../by-memory/0x00557840-0x00557a95.ScreenshotJpegCapturePath.md).

## Current Target State

- Target metadata now reads `COMPLETION:88`, `CONFIDENCE:91`, `CANONICAL_OWNER:0000NB`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000NB`, blank `EMITTER_POSITION_OPTIONAL`.
- Formal C++ is populated with:
  - `void ScreenPane::EnablePresentationMode() { m_presentationModeEnabled = true; }`
  - `void ScreenPane::DisablePresentationMode() { m_presentationModeEnabled = false; }`
- Target item summary already records B009 source-quality evidence: two eight-byte `this+0x12c` setters, internal `0xcc` padding, direct calls at `0x004f8a8e` and `0x00504849` through `g_pScreenPane`, startup initializer clear at `0x00558c86`, inferred field `m_presentationModeEnabled`, and first-draft setter C++.
- Current MCP confirms the same state: `lookup_funcs` models `sub_557820` at `0x00557820` size `0x8` and `sub_557830` at `0x00557830` size `0x8`; `0x00557828`, `0x00557838`, and `0x00557840` are not functions.
- Support docs are current at same-or-greater detail. `ScreenPane.md` and `ScreenPane` class layout include the UID00039S method pair and `+0x12c` field; `SurfacePresentation` lists the child as `88/91`; `SurfaceMinimapRenderInitializer` records the `0x00558c86` clear; `InitializeMainUiGraph` and `MapPaneExitToMenuTeardown` name the enable/disable calls; `ScreenshotJpegCapturePath` keeps the raw JPG no-route caveat separate from the adjacent setters.

## Evidence Standards Used

- Direct MCP evidence: current `supervisor_recovery_20260705` session health, exact function lookup, xrefs, byte reads, byte-pattern search, and decompilation of the two tiny setter functions.
- Documentation evidence: current target and support by-* docs after supervisor validator command `000000006858`, including target metadata/C++ and support synchronization.
- Historical evidence: the old PE-based B009 research remains useful lead material, but current MCP supersedes the stale "MCP unavailable" limitation.
- Inference evidence: method/field spellings are inferred from receiver, callers, byte stores, and lifecycle order; they are not recovered symbols.
- Negative evidence: no current xrefs or little-endian pointer-byte hits for raw JPG start `0x00557840`; no reason to make UID00039S ScreenshotCapture/Surface/MainUiGraph/MapPane-owned.
- Numeric conversion: MCP `int_convert` verified decimal `300` equals hexadecimal `0x12c` and bytes `2c 01`; report references to `this[300]` / `+0x12c` use that verified conversion.

## Evidence Checked

- MCP schema/availability: JSON-RPC `initialize` succeeded; `tools/list` returned schema-current `idb_list`, `server_health`, `lookup_funcs`, `xrefs_to`, `find_bytes`, `get_bytes`, `decompile`, and `int_convert`.
- MCP session: `idb_list` returned one active adopted worker session `supervisor_recovery_20260705`, IDB `NexusTK.exe.i64`, not analyzing, PID/worker PID `19604`.
- MCP health: `server_health` returned `status:"ok"`, IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready, strings cache size `2067`.
- MCP function lookup: `0x00557820 -> sub_557820 size 0x8`; `0x00557830 -> sub_557830 size 0x8`; `0x00557828`, `0x00557838`, and `0x00557840` are not functions; caller addresses map to `sub_4F7D10` size `0xe1b` and `sub_5047F0` size `0x37b`; support initializer `0x00558840 -> sub_558840 size 0x723`.
- MCP xrefs: `xrefs_to 0x00557820` returns one code xref at `0x004f8a8e`; `xrefs_to 0x00557830` returns one code xref at `0x00504849`; `xrefs_to 0x00557840` returns zero.
- MCP bytes: target/padding bytes at `0x00557810` show sixteen pre-target `0xcc`, true setter `c6 81 2c 01 00 00 01 c3`, eight internal `0xcc`, false setter `c6 81 2c 01 00 00 00 c3`, eight post-target `0xcc`, then raw JPG prologue bytes at `0x00557840`; caller windows show `g_pScreenPane` loads immediately before calls; `0x00558c86` bytes are `c6 87 2c 01 00 00 00`.
- MCP decompile: `sub_557820` decompiles to `void __thiscall sub_557820(_BYTE *this) { this[300] = 1; }`; `sub_557830` decompiles to `void __thiscall sub_557830(_BYTE *this) { this[300] = 0; }`.
- MCP pointer-pattern check: little-endian absolute patterns for `0x00557820`, `0x00557830`, and `0x00557840` returned zero matches, supporting direct-call-only setter routes and no raw JPG pointer route.
- Callback target verification: target UID00039S currently has `88/91`, owner/emitter `0000NB`, reconstructable true, blank optional emitter position, populated formal C++ for `ScreenPane::EnablePresentationMode()` / `DisablePresentationMode()`, exact byte/range/padding notes, `g_pScreenPane` caller evidence, startup clear support, and rejected owner alternatives.
- Callback support verification: `ScreenPane.md` lists UID00039S as a ScreenPane setter pair emitted through `NexusTK/ui/core/ScreenPane.cpp`; `ScreenPane` class rows list both methods and `+0x12c`; `SurfacePresentation` lists UID00039S as `88/91` and preserves padding/mixed-owner context; `SurfaceMinimapRenderInitializer` documents `0x00558c86` clearing the same field without rerouting UID00039W; `InitializeMainUiGraph` names the enable call at `0x004f8a8e`; `MapPaneExitToMenuTeardown` names the disable call at `0x00504849`; `ScreenshotJpegCapturePath` separates the adjacent setters from raw JPG reachability and preserves the no-caller/no-pointer caveat.
- Current docs read: target UID00039S and support docs listed under `Target`; old report sections and validator history footer were also read.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| 39S-C01 | Remove only the two top-level validator status/reason lines and preserve xHigh provenance plus validator history footer. | High | Current report header lacks only the removed status/reason lines; provenance remains `CHATGPT | 5.5 | xHigh`; footer history remains unchanged. | Report header / Supporting Research | incorporate | applied |
| 39S-C02 | Historical revalidation reason was `target_uid_unknown: 00039S`; command `000000006856` returned the report; supervisor command `000000006858` repaired target mapping/state. | High | Supporting Research and Validator Results record `000000004167`, `000000006856`, and `000000006858`; target header now has UID00039S mapping/state. | Supporting Research / Validator Results | incorporate | applied |
| 39S-C03 | MCP is currently available through `supervisor_recovery_20260705`; old MCP-unavailable wording is stale. | High | `initialize`, `tools/list`, `idb_list`, `server_health`, exact target calls, and report evidence sections record the current MCP-backed pass. | Supporting Research / Evidence Checked | historicalize | applied |
| 39S-C04 | UID00039S target is currently `88/91`, owner/emitter `0000NB`, reconstructable true, blank emitter position, with formal C++ populated. | High | Target header and formal C++ block currently preserve `ScreenPane::EnablePresentationMode()` / `DisablePresentationMode()` using inferred `m_presentationModeEnabled`. | Current Target State / Score And Metadata Recommendation | already-present | already-present |
| 39S-C05 | `0x00557820` and `0x00557830` are modeled eight-byte setters writing ScreenPane byte `+0x12c` true/false; internal padding remains `0xcc`. | High | Target Address Range/PE sections and ScreenshotJpegCapturePath boundary rows already record the two eight-byte setters, `+0x12c`, and internal `0xcc` padding. | Target/support already; report evidence | already-present | already-present |
| 39S-C06 | Direct callers are `0x004f8a8e` from `InitializeMainUiGraph` and `0x00504849` from `MapPane::ExitToMenu`; both load `g_pScreenPane` immediately before the call. | High | Target PE section plus InitializeMainUiGraph and MapPaneExitToMenuTeardown support docs already name the two call sites and `g_pScreenPane` receiver loads. | Target/support already; report evidence | already-present | already-present |
| 39S-C07 | `0x00558840` startup initializer receives `g_pScreenPane` and clears the same field at `0x00558c86`; this is support evidence, not whole-body owner reroute proof. | High | Target PE section, ScreenPane file/class docs, SurfacePresentation, and SurfaceMinimapRenderInitializer already record the `0x00558c86` clear and UID00039W no-reroute caveat. | Target/support already; report evidence | already-present | already-present |
| 39S-C08 | `0x00557840` raw JPG start is not a function and has no current direct xrefs or absolute pointer hits; UID00039S is not JPG/ScreenshotCapture ownership evidence. | High | Target PE section and ScreenshotJpegCapturePath already separate the adjacent setters from the raw JPG child and preserve no-caller/no-pointer caveats. | Target/support already; report evidence | already-present | already-present |
| 39S-C09 | Keep source route through [UID:0000NB] ScreenPane / `NexusTK/ui/core/ScreenPane.cpp`; reject Surface, ScreenshotCapture, MainUiGraph, and MapPane as direct owners. | High | Target Ownership Analysis, ScreenPane file/class docs, SurfacePresentation, and caller/JPG support docs already preserve ScreenPane route plus rejected direct owners. | Target/support already; report ownership/source sections | already-present | already-present |
| 39S-C10 | No target/support by-* edits were required in callback; generated files, manual coverage files, validator state, lifecycle/archive files, and supervisor ledgers remain excluded. | High | Callback verification found every accepted fact already present or not applicable; B009 edited only this report and took no leases. | Changed Files / Checklist | not-applicable | excluded-with-reason |

## Positive Evidence Summary

- Current MCP confirms two modeled setter functions at `0x00557820` and `0x00557830`, each size `0x8`, with decompiled writes to `this[300]`, verified as `+0x12c`.
- The target page already carries corrected metadata, ScreenPane owner/emitter, first-draft C++, exact caller evidence, initializer support, and rejected owner alternatives.
- `ScreenPane.md`, `ScreenPane` class, `SurfacePresentation`, `SurfaceMinimapRenderInitializer`, `InitializeMainUiGraph`, `MapPaneExitToMenuTeardown`, and `ScreenshotJpegCapturePath` already reflect the accepted UID00039S facts at same-or-greater detail.
- Direct-call evidence and immediate `g_pScreenPane` loads support `ScreenPane::EnablePresentationMode()` and `ScreenPane::DisablePresentationMode()` source shape.
- Startup clear at `0x00558c86` makes the field lifecycle coherent: false at presentation/minimap setup, true after main UI graph initialization, false during exit-to-menu teardown.

## Negative Evidence Summary

- The current report's old MCP-unavailable statement is stale and must not remain as current truth.
- `0x00557828`, `0x00557838`, and `0x00557840` are not function starts in current MCP; target range should not extend into padding or raw JPG code.
- Current MCP reports no xrefs to `0x00557840`, and no little-endian absolute pointer-byte hits for `0x00557820`, `0x00557830`, or `0x00557840`.
- Address adjacency to the raw JPG body does not make UID00039S ScreenshotCapture-owned or a JPG gate.
- Surface/minimap initializer support at `0x00558840` does not reroute the tiny setter pair to Surface; it is a ScreenPane receiver/field initialization fact.

## Heuristic / Inference Reanalysis And Validation

### Issue: source role of `+0x12c`

- Existing claim checked: `+0x12c` is a provisional presentation/mode flag used by startup and map-exit teardown.
- Fresh evidence checked:
  - target bytes at `0x00557820-0x00557838`;
  - direct caller scan for both function starts;
  - `InitializeMainUiGraph` caller window around `0x004f8a8e`;
  - `MapPane::ExitToMenu` caller window around `0x00504849`;
  - startup setup caller at `0x004f6199` into `0x00558840`;
  - `0x00558840` write at `0x00558c86` to the same field.
- Best inference: `+0x12c` is a ScreenPane presentation/gameplay-mode boolean, best named `m_presentationModeEnabled`.
- Evidence:
  - `0x00558840` is reached with `ecx = g_pScreenPane` and initializes the byte to `0` after DirectDraw/minimap presentation setup.
  - `InitializeMainUiGraph` loads `dword_67A7CC` and calls the true setter after the live UI graph is built and profile data has been loaded.
  - `MapPane::ExitToMenu` loads `dword_67A7CC` and calls the false setter as part of active gameplay/session teardown.
  - No target argument controls the value; the two separate methods are source-shaped enable/disable wrappers.
- Rejected alternative: screenshot/JPG enable flag. The raw JPG path at `0x00557840` has no direct caller or pointer to its start, and existing screenshot docs explicitly state the adjacent stubs do not prove JPG capture reachability. The setter callers are main UI graph activation and map/session exit, not screenshot hotkey or proof paths.
- Rejected alternative: generic Surface field. `0x00558840` has Surface/DirectDraw behavior, but the caller passes `g_pScreenPane`, and the target setters are invoked through `g_pScreenPane`. Surface code may initialize or consume ScreenPane presentation state, but the byte field belongs to the ScreenPane object.
- Remaining blocker: no recovered symbol or direct read site for `+0x12c` was found in the checked ScreenPane/presentation support pages. The name is therefore stable enough for first-draft source but not final-audit recovered-source quality.

### Issue: helper names

- Existing names: raw `sub_557820`, `sub_557830`; page title `ScreenPanePresentationModeFlagSetters`.
- Best source-facing names:
  - `0x00557820`: `ScreenPane::EnablePresentationMode()`
  - `0x00557830`: `ScreenPane::DisablePresentationMode()`
- Evidence:
  - Both are no-argument `__thiscall`-shaped methods that mutate the receiver field directly and return.
  - The true setter is called in the common tail of post-login main UI graph setup.
  - The false setter is called in the early phase of map/session exit-to-menu teardown.
  - A startup presentation initializer also starts the field in the false state.
- Rejected alternative: `SetPresentationMode(bool)`. The binary has two retained method bodies and two direct call targets, not one function taking a boolean argument.
- Rejected alternative: `BeginScreenshotMode` / `EndScreenshotMode`. Caller timing and raw JPG no-caller evidence contradict screenshot-specific naming.
- Rejected alternative: `Surface::EnablePresentationMode`. The receiver is the root ScreenPane singleton, not a proven Surface instance.

### Issue: owner/source placement

- Existing owner: [UID:0000NB][ScreenPane](../../../../../by-file/ScreenPane.md).
- Best inference: keep `CANONICAL_OWNER:0000NB` and `EMITTER_UIDS:0000NB`.
- Evidence:
  - Both direct callers load `dword_67A7CC` immediately before the call.
  - [UID:0000S7][g_pScreenPane](../../../../../by-global/g_pScreenPane.md) and [UID:0001OX][0x0067a7cc-0x0067a7d0.g_pScreenPane](../../../../../by-memory/0x0067a7cc-0x0067a7d0.g_pScreenPane.md) establish `dword_67A7CC` as the canonical root ScreenPane singleton.
  - The ScreenPane file parent is already `86/85`, and the ScreenPane class parent is `85/88`.
  - The target pair mutates a ScreenPane object field and has no Surface, ScreenshotCapture, MapPane, or MainUiGraph receiver.
- Rejected Surface direct owner: Surface owns many neighboring DirectDraw helpers and the presentation initializer, but the target receiver and field belong to ScreenPane. Surface is a dependency/support context here.
- Rejected ScreenshotCapture direct owner: adjacency to the JPG raw path is not ownership. Current screenshot docs explicitly separate the live adjacent setter stubs from raw JPG reachability.
- Rejected MapPane direct owner: `MapPane::ExitToMenu` is one caller that disables the flag; it does not own the root screen field.
- Rejected MainUiGraph direct owner: `InitializeMainUiGraph` is one caller that enables the flag; it does not own the ScreenPane object or its field.
- Rejected CursorManager direct owner: cursor aliases over `g_pScreenPane` do not affect this field, and no cursor helper uses `+0x12c`.

### Issue: split and range decision

- Existing range: `0x00557820-0x00557838`.
- Best inference: keep one target page for the paired methods.
- Evidence:
  - `0x00557820-0x00557828` is exactly one true setter.
  - `0x00557828-0x00557830` is eight `0xcc` bytes.
  - `0x00557830-0x00557838` is exactly one false setter.
  - Both methods mutate the same field, have the same owner, and form an obvious reciprocal pair.
  - `0x00557810-0x00557820` and `0x00557838-0x00557840` are external `0xcc` padding spans already listed by the SurfacePresentation split inventory.
- Rejected split into two by-memory targets: technically possible but lower-value. The pair is tiny, semantically coupled, and coverage already names it as one helper pair.
- Rejected range extension to include `0x00557838-0x00557840`: that span is padding before raw JPG code and should remain ignored coverage.

### Issue: first-draft C++ eligibility

- Current target is `RECONSTRUCTABLE:TRUE`.
- Direct parent [UID:0000NB][ScreenPane](../../../../../by-file/ScreenPane.md) clears the parent gate at `86/85`.
- Recommended target score becomes `88/91`, average `89.5`, above the active source-quality/code-entry gate.
- The functions are source-authored tiny methods, not compiler thunks and not STL/template internals.
- The C++ behavior is exact and low-risk: one boolean member write per method.
- Therefore first-draft C++ is eligible. No exact no-code proof is needed for this target.
- Caveat: the method and field names are inferred. That keeps the code at first-draft quality rather than final audited source.

## Fresh PE Evidence

Binary used:

```text
PE: C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe
size: 2679296
MD5: 4247e04e20b65d6414c7238aa8ff5515
image_base: 0x00400000
.text: 0x00401000
```

Target bytes and padding:

```asm
0x00557810: cc cc cc cc cc cc cc cc cc cc cc cc cc cc cc cc
0x00557820: c6 81 2c 01 00 00 01    mov byte ptr [ecx+0x12c], 1
0x00557827: c3                       ret
0x00557828: cc cc cc cc cc cc cc cc
0x00557830: c6 81 2c 01 00 00 00    mov byte ptr [ecx+0x12c], 0
0x00557837: c3                       ret
0x00557838: cc cc cc cc cc cc cc cc
```

Direct rel32 scan:

```text
0x00557820: one direct call, 0x004f8a8e
0x00557830: one direct call, 0x00504849
0x00557840: no direct call/jump to the raw JPG start
absolute dword pointer hits for 0x00557820, 0x00557830, 0x00557840: none
```

Correct-boundary disassembly of the true-setter caller:

```asm
0x004f8a81: 8b cb                    mov ecx, ebx
0x004f8a83: e8 28 0b 00 00           call 0x4f95b0
0x004f8a88: 8b 0d cc a7 67 00        mov ecx, dword ptr [0x67a7cc]
0x004f8a8e: e8 8d ed 05 00           call 0x557820
0x004f8a93: 8b 0d 4c a7 67 00        mov ecx, dword ptr [0x67a74c]
0x004f8a99: 53                       push ebx
0x004f8a9a: e8 e1 06 f7 ff           call 0x469180
```

This is the `InitializeMainUiGraph` common tail. Existing docs identify `0x004f95b0` as `LoadUserProfileData` and `0x00469180` as a BlackHole/deferred-deletion helper. The flag is enabled between those two common-tail operations.

Correct-boundary disassembly of the false-setter caller:

```asm
0x00504824: 8b 35 4c a7 67 00        mov esi, dword ptr [0x67a74c]
0x0050482a: c6 80 40 08 00 00 00     mov byte ptr [eax+0x840], 0
0x00504831: 8b 0d 6c b3 69 00        mov ecx, dword ptr [0x69b36c]
0x00504837: e8 04 c3 fe ff           call 0x4f0b40
0x0050483c: 8b cf                    mov ecx, edi
0x0050483e: e8 bd 05 00 00           call 0x504e00
0x00504843: 8b 0d cc a7 67 00        mov ecx, dword ptr [0x67a7cc]
0x00504849: e8 e2 2f 05 00           call 0x557830
0x0050484e: 8b cf                    mov ecx, edi
0x00504850: e8 4b 63 00 00           call 0x50aba0
```

This is the early part of `MapPane::ExitToMenu(bool notifyServer)`: clear app map-session byte, save compressed map file, disable the ScreenPane presentation flag, then save user settings.

Support initializer evidence:

```asm
0x004f618a: 8b 35 cc a7 67 00        mov esi, dword ptr [0x67a7cc]
0x004f6190: 8b ce                    mov ecx, esi
0x004f6199: e8 a2 26 06 00           call 0x558840
```

Inside `0x00558840`:

```asm
0x0055886d: 8b f9                    mov edi, ecx
0x0055888f: 0f bf 87 12 01 00 00     movsx eax, word ptr [edi+0x112]
0x00558896: 8d 8f 08 01 00 00        lea ecx, [edi+0x108]
0x005588a2: 0f bf 87 14 01 00 00     movsx eax, word ptr [edi+0x114]
...
0x00558c81: 68 00 04 00 00           push 0x400
0x00558c86: c6 87 2c 01 00 00 00     mov byte ptr [edi+0x12c], 0
0x00558c8d: e8 fe ea 06 00           call 0x5c7790
```

This proves the same root ScreenPane object has `+0x12c` cleared during startup presentation/minimap resource initialization. It also confirms this target's field sits near known ScreenPane dimension/surface fields `+0x108`, `+0x112`, and `+0x114`.

## Existing Documentation Evidence

Target page [UID:00039S]:

- Current validator-repaired target path exists at `by-memory/0x00557820-0x00557838.ScreenPanePresentationModeFlagSetters.md` with UID `00039S`, `COMPLETION:88`, `CONFIDENCE:91`, `CANONICAL_OWNER:0000NB`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000NB`.
- It records both modeled functions and the exact `this+0x12c` stores, with internal `0xcc` padding and the adjacent `0x00557840` raw JPG separation.
- It records callers `0x004f8a8e` and `0x00504849` loading `dword_67A7CC` / `g_pScreenPane`, plus startup/support clear evidence at `0x00558c86`.
- It currently contains formal C++ for `ScreenPane::EnablePresentationMode()` and `ScreenPane::DisablePresentationMode()`, using the inferred `m_presentationModeEnabled` byte field.

ScreenPane file/class pages:

- [UID:0000NB][ScreenPane](../../../../../by-file/ScreenPane.md) places `ScreenPane.cpp` under `NexusTK/ui/core/`.
- [UID:0000CB][ScreenPane](../../../../../by-class/ScreenPane.md) documents the root full-screen pane, `g_pScreenPane`, screen dimensions, cursor state, frame/fade state, several ScreenPane helper islands, and the current `+0x12c` presentation-mode byte.
- The support docs already place UID00039S as the ScreenPane `+0x12c` true/false setter pair at same-or-greater detail for this callback verification.

SurfacePresentation split:

- [UID:0001G6][SurfacePresentation](../../../../../by-memory/0x00557140-0x00559aef.SurfacePresentation.md) is a mixed non-emitting container.
- It already lists `00039S` as a ScreenPane child and lists the adjacent padding spans `0x00557810-0x00557820`, `0x00557828-0x00557830`, and `0x00557838-0x00557840`.
- It now reflects the current child metadata for UID00039S (`88/91`) and documents the B009 repair history. Manual coverage-report edits remain out of scope.

g_pScreenPane global/storage docs:

- [UID:0000S7][g_pScreenPane](../../../../../by-global/g_pScreenPane.md) and [UID:0001OX][0x0067a7cc-0x0067a7d0.g_pScreenPane](../../../../../by-memory/0x0067a7cc-0x0067a7d0.g_pScreenPane.md) establish `dword_67A7CC` as the canonical root ScreenPane singleton.
- Constructor publish, destructor clear, cursor alias, browser alias, startup setup, and shutdown removal evidence all point to ScreenPane ownership.

Caller docs:

- [UID:00019K][InitializeMainUiGraph](../../../../../by-memory/0x004f7d10-0x004f8b2a.InitializeMainUiGraph.md) explicitly lists the call to `0x00557820` at `0x004f8a8e` as a shared screen/root refresh helper before deferred deletion and ready hooks.
- [UID:0002QH][MapPaneExitToMenuTeardown](../../../../../by-memory/0x005047f0-0x00504b6b.MapPaneExitToMenuTeardown.md) documents the broad exit-to-menu sequence and names the specific `ScreenPane::DisablePresentationMode()` call at `0x00504849`.

Screenshot docs:

- [UID:0001G8][ScreenshotJpegCapturePath](../../../../../by-memory/0x00557840-0x00557a95.ScreenshotJpegCapturePath.md) correctly warns that the adjacent setters are live but do not prove raw JPG reachability. This report strengthens that caveat: the setters are ScreenPane presentation lifecycle calls, not JPG capture gates.

## Best-Supported Names

| Address / state | Best source-quality name | Status | Notes |
| --- | --- | --- | --- |
| `0x0067a7cc` | `g_pScreenPane` | canonical | Existing global/storage docs support this. Raw names `dword_67A7CC` / `DAT_0067a7cc` should remain raw aliases only. |
| `ScreenPane +0x12c` | `m_presentationModeEnabled` | inferred | Best field name from startup false, main-UI true, exit false. `m_gamePresentationActive` is acceptable if the implementation wants lifecycle emphasis. |
| `0x00557820` | `ScreenPane::EnablePresentationMode()` | inferred source method | No arguments; writes true to `m_presentationModeEnabled`. |
| `0x00557830` | `ScreenPane::DisablePresentationMode()` | inferred source method | No arguments; writes false to `m_presentationModeEnabled`. |
| `0x004f7d10` | `InitializeMainUiGraph` | documented | Caller/consumer only. It enables the ScreenPane flag after post-login UI graph construction. |
| `0x005047f0` | `MapPane::ExitToMenu(bool notifyServer)` | documented | Caller/consumer only. It disables the ScreenPane flag during gameplay teardown. |
| `0x00558840` | `InitializePresentationSurfaces` / current `SurfaceMinimapRenderInitializer` | support context | Called with `g_pScreenPane`, clears `+0x12c`, builds Surface/DirectDraw/minimap resources. Owner may remain Surface for policy/implementation behavior, but it should document the ScreenPane receiver and field initialization. |
| `0x00558680` | separate `+0x5b0` ScreenPane flag setter | documented separate child | Do not merge with `+0x12c`; existing docs tie it to a different presentation flag used/read/cleared by presentation helpers. |

## Ranked Ownership Analysis

### 1. [UID:0000NB] ScreenPane.cpp

Accepted.

Evidence for:

- Both direct target callers load `dword_67A7CC` immediately before the call.
- `dword_67A7CC` is the canonical `g_pScreenPane` singleton.
- The target writes a receiver field, not a global or caller-local field.
- Startup presentation/minimap initialization also receives `g_pScreenPane` and clears the same field.
- The ScreenPane file parent already owns nearby root-screen helpers, presentation/cursor state, singleton storage, and ScreenPane class layout.
- The parent clears the current gate (`86/85`).

Evidence against:

- Some surrounding presentation helpers are assigned to Surface.
- The exact field name is inferred.

Resolution:

- Keep `0000NB` as the direct owner/emitter. Surface adjacency is a dependency/source-neighborhood fact, not target ownership.

### 2. [UID:0000CB] ScreenPane class

Viable but not the chosen direct route.

Evidence for:

- The functions are `thiscall`-shaped and mutate one ScreenPane object field.
- The class parent clears at `85/88`.

Reason not preferred:

- Current target already routes to file parent `0000NB`, and the surrounding mixed helper pair is documented at file-root level. File parent output still emits `ScreenPane::` methods.

### 3. [UID:0000OC] Surface.cpp

Rejected as direct owner for this target.

Evidence for:

- The target sits inside the mixed SurfacePresentation neighborhood.
- The support initializer `0x00558840` is currently assigned to Surface and clears the same field.
- Surface presentation helpers likely depend on the flag.

Evidence against:

- The target's direct callers use `g_pScreenPane` as receiver.
- `+0x12c` is on the ScreenPane object, beside known ScreenPane surface/dimension fields.
- Surface behavior does not override the field's object ownership.

Resolution:

- Surface remains a dependency/support context. `0x00558840` should mention the ScreenPane receiver and clear, but `00039S` stays ScreenPane.

### 4. [UID:0000ND] ScreenshotCapture.cpp

Rejected.

Evidence for:

- Raw JPG code begins after padding at `0x00557840`.
- Screenshot docs historically mentioned adjacent setters.

Evidence against:

- No call or pointer targets raw JPG start `0x00557840` in the fresh direct scan.
- The true/false setter callers are main UI lifecycle paths, not screenshot hotkeys.
- Existing screenshot docs already warn that the adjacent setters do not prove JPG reachability.

Resolution:

- Do not tie `+0x12c` to screenshot capture.

### 5. [UID:0000L1] MainUiGraph.cpp

Rejected as direct owner.

Evidence for:

- `InitializeMainUiGraph` is the sole true-setter caller.

Evidence against:

- It loads `g_pScreenPane` and calls a ScreenPane method.
- It owns live UI graph construction, not ScreenPane fields.

Resolution:

- MainUiGraph is a caller only; the current support doc already names the callee in its direct-call table.

### 6. [UID:00007Q]/[UID:0000L3] MapPane

Rejected as direct owner.

Evidence for:

- `MapPane::ExitToMenu(bool)` is the sole false-setter caller.

Evidence against:

- It loads `g_pScreenPane` and calls a ScreenPane method.
- It owns session teardown, not root ScreenPane presentation state.

Resolution:

- MapPane is a caller only; the current support doc already names the callee in the teardown sequence.

## Source Placement

- Recommended placement: keep UID00039S emitted through [UID:0000NB][ScreenPane](../../../../../by-file/ScreenPane.md), source route `NexusTK/ui/core/ScreenPane.cpp`, as two `ScreenPane::` member methods.
- Why this placement fits: the only current code xrefs pass `g_pScreenPane` as receiver; the body writes a ScreenPane object byte at `+0x12c`; the class/file support pages already place this field and methods in ScreenPane; the parent clears the current attachment gate.
- Rejected placements: ScreenshotCapture because `0x00557840` raw JPG has no current xrefs/pointer route and UID00039S does not enter the JPG child; Surface because DirectDraw/presentation adjacency and the `0x00558840` support initializer do not own the ScreenPane field; MainUiGraph and MapPane because they are callers/consumers only.
- Remaining uncertainty: exact original symbol spelling for the field/method names is not recovered. Current names are source-quality inferred and suitable for first-draft C++; a later original-source/PDB/map discovery could refine spelling without changing owner, range, or behavior.

## Caller / Reachability Summary

Direct caller and pointer state:

| Target | Direct call sites | Absolute pointer hits | Interpretation |
| --- | --- | --- | --- |
| `0x00557820` | `0x004f8a8e` | none | Live true-setter called from `InitializeMainUiGraph`. |
| `0x00557830` | `0x00504849` | none | Live false-setter called from `MapPane::ExitToMenu`. |
| `0x00557840` | none | none | Raw JPG body remains no-direct-caller; it should not explain the setter pair. |

Reachability conclusion:

- The target pair is live by direct call.
- The true setter is reachable from successful login through `LoginDialogPane::OnServerMessage -> InitializeMainUiGraph -> ScreenPane::EnablePresentationMode`.
- The false setter is reachable from application/reconnect/quit routes through `MapPane::ExitToMenu -> ScreenPane::DisablePresentationMode`.
- The raw JPG path's no-caller state is unrelated to target liveness.

## Field / Type / Global / Placeholder Resolution

Fields:

- Add `bool m_presentationModeEnabled;` at `ScreenPane +0x12c`.
- Mark the field name inferred from lifecycle context and support initialization.
- Do not name this field `m_screenshotEnabled`, `m_surfaceFlag`, `m_cursorFlag`, or `m_mapPaneFlag`.

Types:

- Receiver type: `ScreenPane *`.
- Field storage: byte-sized boolean. Source should use `bool`; generated code may emit one byte.
- No additional argument or local types are needed for the target methods.

Globals:

- `dword_67A7CC` should be displayed as `g_pScreenPane`.
- `dword_67A74C` remains the application cleanup queue / BlackHole-related dependency in the caller context, not part of this target.
- `dword_69B36C` in the `MapPane::ExitToMenu` caller context is a UI layer/context dependency, not part of this target.

Placeholders:

- No `a1`, `a2`, or raw placeholder names are needed for the target methods.
- Support docs should avoid naming the field generically as `byte_12c` once this report is applied; use `m_presentationModeEnabled` with an inference note.

## First-Draft C++ Recommendation

Eligible first-draft source:

```cpp
void ScreenPane::EnablePresentationMode()
{
    m_presentationModeEnabled = true;
}

void ScreenPane::DisablePresentationMode()
{
    m_presentationModeEnabled = false;
}
```

Notes:

- This is exact for behavior and calling convention shape.
- The source should not emit padding bytes.
- The member spelling is source-quality inferred. If the implementation pass prefers lifecycle wording, the same code can use `m_gamePresentationActive`.
- No no-code proof should be used for this target unless the supervisor rejects all inferred member names. The active evidence is strong enough for a first-draft C++ body.

## Recommended Target Doc Changes

- Target path: `by-memory/0x00557820-0x00557838.ScreenPanePresentationModeFlagSetters.md`.
- Current disposition after supervisor command `000000006858`: already present at same-or-greater detail. The target has UID00039S, `COMPLETION:88`, `CONFIDENCE:91`, `CANONICAL_OWNER:0000NB`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000NB`, blank `EMITTER_POSITION_OPTIONAL`, populated first-draft C++, exact bytes/range/padding, caller evidence, support initializer clear, owner rejection notes, and cross-references.
- Callback verification result: no target edit required. The target facts were verified as already present at same-or-greater detail.
- Preserve target title/path unless a future naming pass explicitly approves a method-name split; no split is recommended because the two tiny methods are a semantic pair and share owner/field/source route.

## Recommended Support Doc Changes

- `by-file/ScreenPane.md`: already present. It lists UID00039S as a tiny ScreenPane presentation-mode setter pair emitted through this file and records the UID00039W support clear as ScreenPane state initialization, not Surface ownership.
- `by-class/ScreenPane.md`: already present. It records `+0x12c` as inferred `m_presentationModeEnabled` / alternate `m_gamePresentationActive`, and lists lifecycle toggles through UID00039S plus startup clear at `0x00558c86`.
- `by-memory/0x00557140-0x00559aef.SurfacePresentation.md`: already present. It lists UID00039S as `88/91` under ScreenPane and keeps the mixed aggregate non-emitting/parentless.
- `by-memory/0x00558840-0x00558f63.SurfaceMinimapRenderInitializer.md`: already present. It records the `g_pScreenPane` receiver, the `0x00558c86` clear of `ScreenPane::m_presentationModeEnabled` / `+0x12c`, and preserves the no-emitter source-boundary caveat for UID00039W.
- `by-memory/0x004f7d10-0x004f8b2a.InitializeMainUiGraph.md`: already present. It names `ScreenPane::EnablePresentationMode()` at `0x004f8a8e` after loading `g_pScreenPane`.
- `by-memory/0x005047f0-0x00504b6b.MapPaneExitToMenuTeardown.md`: already present. It names `g_pScreenPane->DisablePresentationMode()` after `SaveCompressedMapFile()` and before `SaveUserSettings()`, including formal C++.
- `by-memory/0x00557840-0x00557a95.ScreenshotJpegCapturePath.md`: already present. It separates adjacent UID00039S presentation/gameplay-mode setters from raw JPG reachability and keeps the no-caller raw JPG caveat.
- Callback verification result: no support edit required. The listed support pages were verified as already present at same-or-greater detail.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Not applicable for this callback. Do not manually edit `by-memory/-coverage-report.md`, generated coverage, research tracker, validator state, or supervisor ledgers.
- Historical note: the older report proposed a manual coverage row because the old active coverage state was stale. Supervisor validator command `000000006858` performed validator-owned target/path/registry updates and reported deferred generated refresh; any remaining generated/tracker update belongs to validator/supervisor lifecycle, not B009 callback work.

## Score And Metadata Recommendation

- Current/recommended target metadata: `COMPLETION:88`, `CONFIDENCE:91`, `CANONICAL_OWNER:0000NB`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000NB`, blank `EMITTER_POSITION_OPTIONAL`.
- Current/recommended formal C++: preserve the populated `ScreenPane::EnablePresentationMode()` and `ScreenPane::DisablePresentationMode()` first-draft methods using inferred `m_presentationModeEnabled`.
- Score rationale: `88/91` is justified by current MCP-modeled exact setters, single direct xref to each method, `g_pScreenPane` receiver setup, startup initializer clear of the same field, support-doc incorporation, and rejected owner alternatives. Do not raise to 95+ because exact original field/method spelling and the broader ScreenPane/Surface presentation-family source boundary remain inferred.
- No metadata change is requested during this callback; the current target already reflects the accepted score/metadata after supervisor command `000000006858`.

## Open Questions With Attempted Resolution

- Open question: is `m_presentationModeEnabled` the exact original field spelling?
  - Evidence checked: MCP decompile `this[300]`, int conversion `300 -> 0x12c`, caller lifecycle, ScreenPane class layout, support docs.
  - Resolution: exact spelling is not recovered; `m_presentationModeEnabled` is the best current source-quality inferred name and suitable for first-draft C++.
- Open question: should the target belong to Surface or ScreenshotCapture because of address neighborhood?
  - Evidence checked: MCP xrefs/bytes, raw JPG no-route evidence, SurfaceMinimapRenderInitializer support docs, ScreenshotJpegCapturePath caveat.
  - Resolution: no. UID00039S belongs to ScreenPane; Surface and ScreenshotCapture are support/neighborhood contexts only.
- Open question: does current MCP still block the report?
  - Evidence checked: `initialize`, `tools/list`, `idb_list`, `server_health`, exact `lookup_funcs`, `xrefs_to`, `get_bytes`, `find_bytes`, `decompile`, `int_convert`.
  - Resolution: no. MCP is available and supplies current evidence; the old unavailable statement is historical only.
- Open question: are target/support docs missing the accepted report facts?
  - Evidence checked: current target and listed support docs.
  - Resolution: no concrete by-* mismatch found. Current docs are already present at same-or-greater detail; B009 performs no by-* edit in this callback.

## Final Recommendation

- Keep target path/name, range, owner/emitter route `0000NB`, `88/91` score, and populated first-draft C++.
- Keep `ScreenPane +0x12c` documented as inferred `m_presentationModeEnabled`, with `m_gamePresentationActive` only as a meaningful alternate spelling if later original-source evidence appears.
- Keep UID00039S as ScreenPane-owned source-authored code; reject ScreenshotCapture, Surface, MainUiGraph, and MapPane direct ownership.
- No target/support by-* edits were needed during this callback because current docs already incorporate the accepted facts at same-or-greater detail after command `000000006858` and prior support syncs.
- No manual coverage row, generated edit, validator-state edit, lifecycle/archive command, report move, or scoped validator run is part of this B009 callback because no by-* file changed.
- Future work outside this report: a separate family-wide presentation source-boundary pass may review whether UID00039W remains Surface-owned/non-emitting or becomes part of a broader ScreenPane presentation initialization route. That uncertainty does not block UID00039S.

## Follow-Up Actions

- Supervisor action: perform Gate 2 verification of this callback-updated report, then execute/clear through documented validator lifecycle if satisfied.
- B009 callback result: every accepted claim is applied, already present, or excluded with reason; no blocker remains for supervisor execution.
- Supervisor lifecycle only: B009 must not run `execute_report`, dry-run/probing variants, lifecycle/archive commands, registry commands, or manual report moves.

## Confidence

- Recommendation confidence: high.
- Score confidence: high enough for `88/91`, not high enough for 95+ because the exact original member/method spelling is not recovered and broader presentation-family source boundaries remain partially inferred. Current MCP is available and no longer a score blocker.
- Remaining uncertainty: exact source field spelling and whether the original code used `Enable/Disable`, `Enter/Leave`, or similarly named wrappers. This does not affect owner, range, behavior, or first-draft code shape.

## Validator Results

- B009 did not run scoped validators during this callback because no target/support by-* file was edited.
- Supervisor validator command incorporated: `000000006858`, timestamp `2026-07-05T07:01:14-04:00`, command `python .\tools\validator.py --mode file --file by-memory/0x00557820-0x00557838.ScreenPanePresentationModeFlagSetters.md --apply --queue-timeout 240`, exit `0`, `ok: 1`.
- Supervisor command effects recorded in `goal.md`: `path_update`, `completion_update 88`, `confidence_update 91`, `canonical_owner_update 0000NB`, autogen registry updates, reference index additions, projected stats update, and `generated_refresh: deferred`.
- Historical report lifecycle commands remain only in the validator-owned footer: `000000004167` needs-revalidation for `target_uid_unknown: 00039S` and `000000006856` de-executed the report for rework.
- B009 did not run `execute_report`, dry-run/probing execute variants, registry lifecycle commands, archive commands, generated edits, coverage-report edits, validator-state edits, queue/lock edits, or manual report moves.

## Changed Files

- Modified by B009 in this repair/callback:
  - `tools/leaser/Agents/Agent-B009/research/00039S-ScreenPanePresentationModeFlagSetters-source-quality.md`
- Not modified by B009:
  - `by-memory/0x00557820-0x00557838.ScreenPanePresentationModeFlagSetters.md`
  - `by-file/ScreenPane.md`
  - `by-class/ScreenPane.md`
  - `by-memory/0x00557140-0x00559aef.SurfacePresentation.md`
  - `by-memory/0x00558840-0x00558f63.SurfaceMinimapRenderInitializer.md`
  - `by-memory/0x004f7d10-0x004f8b2a.InitializeMainUiGraph.md`
  - `by-memory/0x005047f0-0x00504b6b.MapPaneExitToMenuTeardown.md`
  - `by-memory/0x00557840-0x00557a95.ScreenshotJpegCapturePath.md`
  - generated files, manual coverage reports, validator state, queue/lock files, lifecycle/archive files, executed-report records, supervisor ledgers, and validator-owned history footer comments.
- Leases: none used; no by-* file was edited, and no lease is needed for editing B009's own active report.

## Implementation Tracking Checklist

Implementation callback verification checklist:

- [x] Gate 1 passed for SHA256 `E0EE62C125D8AD53513DB96E4A245E43590D8C0D5B75DC3E948C1548D1498431`; callback verification was performed on the same active report path.
- [x] Report header preserves `TARGET-REPORT-UID:00039S`, `AUTHOR-AGENT-ID:B009`, and `AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh`.
- [x] Top-level validator status/reason lines remain removed, their historical facts remain under `Supporting Research`, and the validator-owned history footer remains unchanged.
- [x] Current MCP evidence from `supervisor_recovery_20260705` remains in `Evidence Checked`: session/health, function lookup, xrefs, bytes, decompile, pointer-pattern negatives, and int conversion.
- [x] Supervisor validator command `000000006858` and its effects remain recorded under `Supporting Research` and `Validator Results`.
- [x] Verified target `by-memory/0x00557820-0x00557838.ScreenPanePresentationModeFlagSetters.md` already preserves `88/91`, owner/emitter [UID:0000NB], reconstructable true, blank optional emitter position, formal C++ for `ScreenPane::EnablePresentationMode()` / `DisablePresentationMode()`, exact two eight-byte setters, internal `0xcc` padding, `g_pScreenPane` callers, startup initializer clear, rejected owner alternatives, and inferred-name score cap.
- [x] Verified `by-file/ScreenPane.md` already lists UID00039S as a tiny ScreenPane presentation-mode setter pair emitted through `NexusTK/ui/core/ScreenPane.cpp` and records UID00039W clear support without rerouting the setters.
- [x] Verified `by-class/ScreenPane.md` already lists the `EnablePresentationMode()` / `DisablePresentationMode()` methods, `+0x12c` as inferred `m_presentationModeEnabled` / alternate `m_gamePresentationActive`, startup clear at `0x00558c86`, and lifecycle toggles from UID00019K and UID0002QH.
- [x] Verified `by-memory/0x00557140-0x00559aef.SurfacePresentation.md` already lists UID00039S as `88/91` under ScreenPane, preserves internal padding `0x00557828-0x00557830` / `0x00557838-0x00557840`, and keeps the aggregate mixed-owner/non-emitting.
- [x] Verified `by-memory/0x00558840-0x00558f63.SurfaceMinimapRenderInitializer.md` already records the `g_pScreenPane` receiver, `0x00558c86` clear of `ScreenPane::m_presentationModeEnabled` / `+0x12c`, and UID00039W no-emitter source-boundary caveat.
- [x] Verified `by-memory/0x004f7d10-0x004f8b2a.InitializeMainUiGraph.md` already names `ScreenPane::EnablePresentationMode()` at `0x004f8a8e` after loading `g_pScreenPane` at `0x004f8a88`.
- [x] Verified `by-memory/0x005047f0-0x00504b6b.MapPaneExitToMenuTeardown.md` already names `g_pScreenPane->DisablePresentationMode()` at `0x00504849`, after `SaveCompressedMapFile()` and before `SaveUserSettings()`, including formal C++.
- [x] Verified `by-memory/0x00557840-0x00557a95.ScreenshotJpegCapturePath.md` already separates adjacent UID00039S setters from raw JPG reachability and preserves no-direct-caller/no-pointer caveats for `0x00557840`.
- [x] No accepted fact was missing or materially under-detailed; no target/support by-* file was edited, no lease was taken, and no scoped validator was run because there were no by-* changes.
- [x] Generated files, manual `-coverage-report.md` files, validator state, queue/lock files, lifecycle/archive files, executed-report records, supervisor ledgers, and validator-owned report-history footer comments were not edited.
- [x] B009 did not run `execute_report`, dry-run/probing execute variants, registry lifecycle commands, archive commands, or manual report moves. Stop status for this callback is `READY_FOR_SUPERVISOR_EXECUTE`.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 00039S","source_path":"executed-b-agent-research/B009/00039S-ScreenPanePresentationModeFlagSetters-source-quality.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- {"agent":"B009","command_id":"000000006856","destination_path":"tools/leaser/Agents/Agent-B009/research/00039S-ScreenPanePresentationModeFlagSetters-source-quality.md","details":"report returned to active agent research for rework","event":"de-executed-for-rework","source_path":"executed-b-agent-research/B009/00039S-ScreenPanePresentationModeFlagSetters-source-quality.md","timestamp":"2026-07-05T07:00:37-04:00"} -->
<!-- {"agent":"B009","command_id":"000000006868","destination_path":"executed-b-agent-research/B009/00039S-ScreenPanePresentationModeFlagSetters-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B009/research/00039S-ScreenPanePresentationModeFlagSetters-source-quality.md","timestamp":"2026-07-05T07:22:50-04:00","uid":"00039S"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
