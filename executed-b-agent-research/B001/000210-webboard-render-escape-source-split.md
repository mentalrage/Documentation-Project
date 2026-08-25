** TARGET-REPORT-UID:000210 **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# UID 000210 Research Report - WebBoardDialog Render/Escape Source Split

Agent: B001  
Assignment: `B001-goal2-webboard-render-escape-source-split-20260616`  
Target: `[UID:000210] by-memory/0x0046da70-0x0046e294.WebBoardDialogRenderEscapeAndOldTeardownHelpers.md`  
Report status: research/recommendation only. Do not move to `executed`; supervisor applies or rejects.
Workspace path: `E:\NTK\GhidraBridge\source-3\project-documentation`

## Current Recommendation

Split `[UID:000210]` into an explicitly non-emitting split index plus five exact executable children and four internal padding rows.

The current broad item mixes:

- active raw file-local URL escape helper `0x0046da70-0x0046dbca`;
- active `WebBoardDialog` vtable-backed render helpers at `0x0046dbd0`, `0x0046dd00`, and `0x0046dea0`;
- old-dialog raw method-shaped teardown helper `0x0046e260-0x0046e294`;
- internal `0xcc` alignment spans between those entries.

Recommended final state for original UID `000210`:

- Keep as a reviewed non-emitting split index/container over `0x0046da70-0x0046e294`.
- Set `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank C++.
- Keep semantic file owner `CANONICAL_OWNER:0000P9` because the physical island belongs to the WebBoardDialog source neighborhood, but exact source-bearing children carry class/file routing.
- Raise to about `88/90` only after split text is applied, because the unresolved parts are now documented as child-level blockers rather than hidden in the aggregate.

No final C++ should be added yet. The source-quality blockers were investigated, but original source names and raw helper liveness remain below the final-source bar.

## Scope Read Before Conclusions

Required and supporting docs read:

- Target: `by-memory/0x0046da70-0x0046e294.WebBoardDialogRenderEscapeAndOldTeardownHelpers.md`
- Active class: `by-class/WebBoardDialog.md`
- Old class: `by-class/WebBoardDialogOld.md`
- Source file: `by-file/WebBoardDialog.md`
- Resource context: `by-resource/webboard-dialog-resources.md`
- Active URL escape state: `by-memory/0x0067aba8-0x0067acb0.WebBoardDialogUrlEscapeState.md`
- Old URL escape state: `by-memory/0x0067acb0-0x0067adb8.WebBoardDialogOldUrlEscapeState.md`
- Escape character sets: `by-memory/0x0066d430-0x0066d468.BrowserUrlEscapeCharacterSets.md`
- Active response handler: `by-memory/0x0046d580-0x0046da63.WebBoardDialogHandleBoardResponse.md`
- Old response handler: `by-memory/0x0046eaa0-0x0046ee7a.WebBoardDialogOldHandleBoardResponse.md`
- Old URL escape helper: `by-memory/0x0046ee80-0x0046efda.WebBoardDialogOldUrlEscapeHelper.md`
- Old layout successor: `by-memory/0x0046e2a0-0x0046e4b6.WebBoardDialogOldLayoutRefresh.md`
- Browser comparison slot docs: `by-memory/0x0046ad10-0x0046b51d.BrowserDialogPaneVirtuals.md`, `by-class/BrowserDialog.md`, `by-class/BrowserPane.md`
- Base context: `by-class/DialogPane.md`, `by-file/DialogPane.md`, `by-memory/0x0049d8a0-0x0049feae.DialogPane.md`
- Vtable neighborhood: `by-memory/0x006131b4-0x006139df.BrowserVtablesAndStrings.md`
- Coverage and padding ledgers: `by-memory/-coverage-report.md`, `by-memory/-ignored.md`

Workflow sources read:

- `tools/leaser/Agents/Supervisor.md`
- `tools/leaser/Agents/Agent-B001/goal.md`
- `tools/leaser/Agents/Agent-B001/notes.md`
- `tools/leaser/Agents/Agent-B001/inference_research.md`
- `by-structure.md`

## IDA MCP Evidence

Tooling used: local IDA MCP endpoint `http://127.0.0.1:13337/mcp`, read-only calls only. No IDA edits were made.

Active session observed:

- `session_id`: `a002_goal65_20260616`
- input: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- IDB: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`
- `server_health`: status ok, imagebase `0x400000`, Hex-Rays true, strings cache true.
- `auto_analysis_ready` reported false, but functions, bytes, xrefs, and decompilation calls responded.

Function lookup facts:

| Address | IDA function state | Evidence result |
|---|---:|---|
| `0x0046da70` | no function | raw code begins with prologue and active escape-table guard |
| `0x0046dbd0` | `sub_46DBD0`, size `0x123` | active vtable-backed helper |
| `0x0046dd00` | `sub_46DD00`, size `0x196` | active vtable-backed helper |
| `0x0046dea0` | `sub_46DEA0`, size `0x3bb` | active vtable-backed helper |
| `0x0046e260` | no function | raw method-shaped teardown body |
| `0x0046e294` | no function | padding start, not code start |
| `0x0046e2a0` | `sub_46E2A0`, size `0x216` | old layout successor |
| `0x0046ee80` | no function | known old raw URL escape helper, comparison only |

Xref facts:

| Target | Xrefs found |
|---|---|
| `0x0046da70` | none |
| `0x0046dbd0` | one data xref at `0x00613620` |
| `0x0046dd00` | one data xref at `0x0061362c` |
| `0x0046dea0` | one data xref at `0x00613630` |
| `0x0046e260` | none |
| `0x0046e294` | none |
| `0x0046e2a0` | none |
| `0x0046ee80` | none |

Absolute pointer scans:

| Pointer bytes | Meaning | Matches |
|---|---|---:|
| `70 DA 46 00` | pointer to `0x0046da70` | 0 |
| `D0 DB 46 00` | pointer to `0x0046dbd0` | 1 at `0x00613620` |
| `00 DD 46 00` | pointer to `0x0046dd00` | 1 at `0x0061362c` |
| `A0 DE 46 00` | pointer to `0x0046dea0` | 1 at `0x00613630` |
| `60 E2 46 00` | pointer to `0x0046e260` | 0 |
| `A0 E2 46 00` | pointer to `0x0046e2a0` | 0 |
| `80 EE 46 00` | pointer to `0x0046ee80` | 0 |

Byte boundary facts:

- `0x0046da63-0x0046da70`: all `0xcc`.
- `0x0046dbca-0x0046dbd0`: all `0xcc`.
- `0x0046dcf3-0x0046dd00`: all `0xcc`.
- `0x0046de96-0x0046dea0`: all `0xcc`.
- `0x0046e25b-0x0046e260`: all `0xcc`.
- `0x0046e294-0x0046e2a0`: all `0xcc`.

## Child Inventory and Ownership

| Proposed child | Range | Direct owner | Emitter | Role | Score recommendation |
|---|---:|---|---|---|---:|
| `WebBoardDialogUrlEscapeHelper` | `0x0046da70-0x0046dbca` | `0000P9` | `0000P9` | active file-local raw URL escape helper | `86/89` |
| `WebBoardDialogVisualRefresh` | `0x0046dbd0-0x0046dcf3` | `0000G2` | `0000G2` | active vtable slot `+0x44`; refresh/selected-control highlight wrapper | `86/90` |
| `WebBoardDialogDrawContentArea` | `0x0046dd00-0x0046de96` | `0000G2` | `0000G2` | active vtable slot `+0x50`; content/background tile draw | `86/90` |
| `WebBoardDialogDrawFrameChrome` | `0x0046dea0-0x0046e25b` | `0000G2` | `0000G2` | active vtable slot `+0x54`; frame/chrome tile draw | `86/90` |
| `WebBoardDialogOldBrowserControlTeardownRaw` | `0x0046e260-0x0046e294` | `0000G3` | `0000G3` | old raw no-arg browser-control teardown/finalizer body | `85/86` |

Ownership rationale:

- `0x0046da70` has no `this` receiver and no function object. It uses active WebBoardDialog URL escape state (`byte_67ABA8`, `byte_67ABB0`) and active character-set data (`0x0066d430`/`0x0066d43c`). Treat it as WebBoardDialog source-file helper under `0000P9`, not as a direct class method.
- `0x0046dbd0`, `0x0046dd00`, and `0x0046dea0` are direct active `WebBoardDialog` virtual overrides. Their sole pointer xrefs are the active WebBoardDialog vtable entries at `0x00613620`, `0x0061362c`, and `0x00613630`. They clear the strict direct-child owner gate for `0000G2`.
- `0x0046e260` sits at the documented old-dialog start boundary in `by-file/WebBoardDialog.md`, is listed on `by-class/WebBoardDialogOld.md`, uses the old browser-control offset `+0x26c`, and is adjacent to accepted old no-xref functions. It should route to `0000G3`, with the no-xref/no-pointer caveat kept explicit.
- The original broad range should not emit because it merges active file helper, active class virtuals, old class raw method, and padding.

## Active Virtual Slot Role Names

The role names below are evidence-backed descriptions, not proven original C++ symbol names.

BrowserDialog comparison establishes the slot map:

| BrowserDialog slot | BrowserDialog target | Browser role | WebBoardDialog target | Recommended role name |
|---|---:|---|---:|---|
| `+0x44` | `0x0046aeb0` | visual refresh helper | `0x0046dbd0` | `WebBoardDialogVisualRefresh` |
| `+0x50` | `0x0046b030` | title/content draw helper | `0x0046dd00` | `WebBoardDialogDrawContentArea` |
| `+0x54` | `0x0046b0d0` | frame/chrome tile helper | `0x0046dea0` | `WebBoardDialogDrawFrameChrome` |

Slot-specific behavior:

- `0x0046dbd0`: clears pending browser/control state at `dword_67A764+0x104`, calls the receiver vslot `+0x54`, handles selected child/control index at `this+0x200`/`this+0x1fc`, expands the child rectangle, writes `this+0x70 = 0`, and draws resource/control ids `0x84` or `0x86`.
- `0x0046dd00`: loads EPF tile resources through `g_pEPFLib`, `off_60DB5C`, and `off_60DB78`; sets `this+0x70 = 1`; insets the dialog rect by `+11`, `+42`, `-11`, `-40`; tiles the interior.
- `0x0046dea0`: draws frame/chrome only when the child/browser-control state at `this+0x260` is clear; loads resources through `off_60DB94` and `off_60DBB0`; draws top, bottom, left, right, and corner tile runs.

The resource handle globals `off_60DB5C`, `off_60DB78`, `off_60DB94`, and `off_60DBB0` remain source-quality blockers for final variable names. Existing resource docs only prove `WEBBOARD.EPD/PAD` for old constructor resources and do not resolve final active render handle names.

## Raw Helper Liveness and Compiler Treatment

`0x0046da70` liveness:

- Investigated with IDA `xrefs_to`: no xrefs.
- Investigated with byte scan for absolute pointer `70 DA 46 00`: no matches.
- The body is not compiler padding or a thunk: it has a normal prologue, initializes active WebBoardDialog escape table state, reads active character-set bytes, and formats escaped bytes with `%%%2X`.
- Conclusion: retained source-shaped raw helper, but live reachability is not proven. It may be unreachable/dead-retained, indirectly computed, or a duplicate helper whose entry was lost by decompiler function recognition. Do not write final C++ until source name/liveness is proven or project policy accepts reconstructing raw no-xref retained helpers.

`0x0046e260` liveness:

- Investigated with IDA `xrefs_to`: no xrefs.
- Investigated with byte scan for absolute pointer `60 E2 46 00`: no matches.
- Raw disassembly is method-shaped:

```asm
0x46e260 push esi
0x46e261 mov esi, ecx
0x46e263 mov ecx, [esi+26Ch]
0x46e269 call sub_46BA90
0x46e26e mov eax, [esi]
0x46e270 mov ecx, esi
0x46e272 mov dword ptr [esi+26Ch], 0
0x46e27c call dword ptr [eax+38h]
0x46e27f mov eax, [esi]
0x46e281 mov ecx, esi
0x46e283 call dword ptr [eax+40h]
0x46e286 mov ecx, dword_67A74C
0x46e28c push esi
0x46e28d call sub_469180
0x46e292 pop esi
0x46e293 retn
```

- The body is not compiler padding or a thunk: it closes the embedded browser-control pointer, clears the field, invokes two virtual hooks, and unregisters the pane.
- Compared against active close/teardown `0x0046d360` and old close callback `0x0046e8f0`, it is a no-arg teardown body variant. It lacks the argument checks and active/old callback wrapper scaffolding but shares the teardown core.
- Conclusion: source-shaped old-dialog raw method/helper with no proven call path. It should be split and routed to `0000G3`, but final C++ stays blank.

IDA function creation/naming recommendation:

- Do not make IDA DB edits in this B001 report pass.
- If a future IDA normalization pass accepts raw retained helper promotion, candidates are `0x0046da70-0x0046dbca` and `0x0046e260-0x0046e294`. Current evidence is sufficient for documentation split pages, not for final names.

## Coverage and Padding Findings

Current `by-memory/-coverage-report.md` has one broad row for UID `000210` and two external padding rows:

- `0x0046da63-0x0046da70`
- `0x0046e294-0x0046e2a0`

Current `by-memory/-ignored.md` has the same two external padding rows, but does not currently have internal padding rows for:

- `0x0046dbca-0x0046dbd0`
- `0x0046dcf3-0x0046dd00`
- `0x0046de96-0x0046dea0`
- `0x0046e25b-0x0046e260`

The target page currently implies internal padding is already recorded in `-ignored.md`; live repo text contradicts that. The split should add those four ledger rows and corresponding coverage rows.

## Exact Recommended Edits

These are recommendations for the supervisor to apply. B001 did not edit any by-* docs and did not edit `by-memory/-coverage-report.md`.

### 1. Parent Page Replacement

File:

`by-memory/0x0046da70-0x0046e294.WebBoardDialogRenderEscapeAndOldTeardownHelpers.md`

Recommended header replacement:

```text
*** UID:000210 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000P9 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Recommended status replacement:

```text
## Status

- Disposition: reviewed non-emitting split index over adjacent WebBoardDialog executable helpers
- Entity kind: mixed source-neighborhood inventory / split index
- Current owner hypothesis: semantic file neighborhood is [UID:0000P9][WebBoardDialog](by-file/WebBoardDialog.md); exact active class helpers route to [UID:0000G2][WebBoardDialog](by-class/WebBoardDialog.md), the old teardown raw helper routes to [UID:0000G3][WebBoardDialogOld](by-class/WebBoardDialogOld.md), and internal gaps route to [UID:0000VN][-ignored](by-memory/-ignored.md)
- Rebuild handling: parent is `RECONSTRUCTABLE:FALSE`; exact child pages carry reconstructable source evidence; parent C++ remains blank

## Split Children

| Range | Child page | Owner | Evidence summary |
|---|---|---|---|
| `0x0046da70-0x0046dbca` | `0x0046da70-0x0046dbca.WebBoardDialogUrlEscapeHelper.md` | [UID:0000P9][WebBoardDialog](by-file/WebBoardDialog.md) | Raw no-function active URL escape helper; initializes active state at `byte_67ABA8`/`byte_67ABB0` and reads active character sets at `0x0066d430`/`0x0066d43c`; no direct xrefs or pointer constants found. |
| `0x0046dbca-0x0046dbd0` | [UID:0000VN][-ignored](by-memory/-ignored.md) | none | Confirmed `0xcc` alignment padding. |
| `0x0046dbd0-0x0046dcf3` | `0x0046dbd0-0x0046dcf3.WebBoardDialogVisualRefresh.md` | [UID:0000G2][WebBoardDialog](by-class/WebBoardDialog.md) | Active vtable slot `+0x44`, pointer at `0x00613620`; visual refresh/selected-control highlight wrapper. |
| `0x0046dcf3-0x0046dd00` | [UID:0000VN][-ignored](by-memory/-ignored.md) | none | Confirmed `0xcc` alignment padding. |
| `0x0046dd00-0x0046de96` | `0x0046dd00-0x0046de96.WebBoardDialogDrawContentArea.md` | [UID:0000G2][WebBoardDialog](by-class/WebBoardDialog.md) | Active vtable slot `+0x50`, pointer at `0x0061362c`; content/background tile draw using `off_60DB5C`/`off_60DB78`. |
| `0x0046de96-0x0046dea0` | [UID:0000VN][-ignored](by-memory/-ignored.md) | none | Confirmed `0xcc` alignment padding. |
| `0x0046dea0-0x0046e25b` | `0x0046dea0-0x0046e25b.WebBoardDialogDrawFrameChrome.md` | [UID:0000G2][WebBoardDialog](by-class/WebBoardDialog.md) | Active vtable slot `+0x54`, pointer at `0x00613630`; frame/chrome tile draw using `off_60DB94`/`off_60DBB0`. |
| `0x0046e25b-0x0046e260` | [UID:0000VN][-ignored](by-memory/-ignored.md) | none | Confirmed `0xcc` alignment padding. |
| `0x0046e260-0x0046e294` | `0x0046e260-0x0046e294.WebBoardDialogOldBrowserControlTeardownRaw.md` | [UID:0000G3][WebBoardDialogOld](by-class/WebBoardDialogOld.md) | Raw no-function no-xref old-dialog teardown body; closes `[this+0x26c]`, clears it, calls vslots `+0x38` and `+0x40`, and unregisters through `dword_67A74C`/`sub_469180`. |
```

### 2. New Child Page Text

The supervisor/validator should allocate real UIDs for `UID_DA70`, `UID_DBD0`, `UID_DD00`, `UID_DEA0`, and `UID_E260` before applying. Keep C++ blocks blank.

Create:

`by-memory/0x0046da70-0x0046dbca.WebBoardDialogUrlEscapeHelper.md`

```text
*** UID:UID_DA70 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000P9 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000P9 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# 0x0046da70-0x0046dbca WebBoardDialog URL Escape Helper

## Status

- Disposition: reconstructable NexusTK project code; final C++ blank pending raw-helper liveness/source-name proof
- Entity kind: raw file-local helper
- Current owner hypothesis: [UID:0000P9][WebBoardDialog](by-file/WebBoardDialog.md)
- Rebuild handling: source-authored raw helper candidate

## Evidence

- IDA MCP reports no function object at `0x0046da70` and no direct xrefs to the entry.
- Absolute pointer scan for `70 DA 46 00` found no matches.
- Raw disassembly starts with a normal prologue, checks `byte_67ABA8`, initializes `byte_67ABB0`, reads active character-set bytes at `0x0066d430` and `0x0066d43c`, sets the active guard, then copies allowed input bytes or emits escaped bytes through the `%%%2X` formatting helper.
- The helper uses active WebBoardDialog URL escape state documented in [UID:0002AG][0x0067aba8-0x0067acb0.WebBoardDialogUrlEscapeState](by-memory/0x0067aba8-0x0067acb0.WebBoardDialogUrlEscapeState.md) and active character sets documented in [UID:000278][0x0066d430-0x0066d468.BrowserUrlEscapeCharacterSets](by-memory/0x0066d430-0x0066d468.BrowserUrlEscapeCharacterSets.md).

## Source-Quality Notes

- Treat as a retained source-shaped raw helper, not padding or compiler glue.
- Do not write final C++ until the project accepts raw no-xref helper reconstruction or a source-quality name/call path is proven.
```

Create:

`by-memory/0x0046dbd0-0x0046dcf3.WebBoardDialogVisualRefresh.md`

```text
*** UID:UID_DBD0 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000G2 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000G2 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# 0x0046dbd0-0x0046dcf3 WebBoardDialog Visual Refresh

## Status

- Disposition: reconstructable NexusTK project code; final C++ blank pending final source name and field/resource naming
- Entity kind: active WebBoardDialog virtual method
- Current owner hypothesis: [UID:0000G2][WebBoardDialog](by-class/WebBoardDialog.md)
- Rebuild handling: source-authored virtual method

## Evidence

- IDA MCP reports `sub_46DBD0`, size `0x123`.
- The only entry xref is active WebBoardDialog vtable data at `0x00613620`.
- BrowserDialog comparison maps this vtable position to slot `+0x44`, the visual refresh helper slot.
- Decompiled behavior clears pending state at `dword_67A764+0x104`, calls the receiver vslot `+0x54`, resolves the selected child/control index through `this+0x1fc`/`this+0x200`, expands the child rectangle, writes `this+0x70 = 0`, and draws state around resource/control ids `0x84` or `0x86`.

## Source-Quality Notes

- `WebBoardDialogVisualRefresh` is a role name, not a proven original symbol.
- Final C++ should wait for field names and resource/control id names.
```

Create:

`by-memory/0x0046dd00-0x0046de96.WebBoardDialogDrawContentArea.md`

```text
*** UID:UID_DD00 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000G2 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000G2 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# 0x0046dd00-0x0046de96 WebBoardDialog Draw Content Area

## Status

- Disposition: reconstructable NexusTK project code; final C++ blank pending final source name and resource handle names
- Entity kind: active WebBoardDialog virtual method
- Current owner hypothesis: [UID:0000G2][WebBoardDialog](by-class/WebBoardDialog.md)
- Rebuild handling: source-authored virtual method

## Evidence

- IDA MCP reports `sub_46DD00`, size `0x196`.
- The only entry xref is active WebBoardDialog vtable data at `0x0061362c`.
- BrowserDialog comparison maps this vtable position to slot `+0x50`, the content/title-area draw slot family.
- Decompiled behavior loads EPF/image resources through `g_pEPFLib`, `off_60DB5C`, and `off_60DB78`, sets `this+0x70 = 1`, insets the dialog rectangle by `+11`, `+42`, `-11`, `-40`, computes tile counts, and repeats draw calls across the interior/background.

## Source-Quality Notes

- `WebBoardDialogDrawContentArea` is a role name, not a proven original symbol.
- Existing resource docs do not resolve final names for `off_60DB5C` or `off_60DB78`.
```

Create:

`by-memory/0x0046dea0-0x0046e25b.WebBoardDialogDrawFrameChrome.md`

```text
*** UID:UID_DEA0 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000G2 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000G2 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# 0x0046dea0-0x0046e25b WebBoardDialog Draw Frame Chrome

## Status

- Disposition: reconstructable NexusTK project code; final C++ blank pending final source name and resource handle names
- Entity kind: active WebBoardDialog virtual method
- Current owner hypothesis: [UID:0000G2][WebBoardDialog](by-class/WebBoardDialog.md)
- Rebuild handling: source-authored virtual method

## Evidence

- IDA MCP reports `sub_46DEA0`, size `0x3bb`.
- The only entry xref is active WebBoardDialog vtable data at `0x00613630`.
- BrowserDialog comparison maps this vtable position to slot `+0x54`, the frame/chrome draw slot family.
- Decompiled behavior draws only when the child/browser-control state at `this+0x260` is clear, loads resource handles through `off_60DB94` and `off_60DBB0`, and emits top, bottom, left, right, and corner tile runs based on the dialog rectangle.

## Source-Quality Notes

- `WebBoardDialogDrawFrameChrome` is a role name, not a proven original symbol.
- Existing resource docs do not resolve final names for `off_60DB94` or `off_60DBB0`.
```

Create:

`by-memory/0x0046e260-0x0046e294.WebBoardDialogOldBrowserControlTeardownRaw.md`

```text
*** UID:UID_E260 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000G3 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000G3 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# 0x0046e260-0x0046e294 WebBoardDialogOld Browser Control Teardown Raw

## Status

- Disposition: reconstructable NexusTK project code; final C++ blank pending raw-helper liveness/source-name proof
- Entity kind: raw old WebBoardDialogOld method-shaped teardown helper
- Current owner hypothesis: [UID:0000G3][WebBoardDialogOld](by-class/WebBoardDialogOld.md)
- Rebuild handling: source-authored raw helper/method candidate

## Evidence

- IDA MCP reports no function object at `0x0046e260` and no direct xrefs to the entry.
- Absolute pointer scan for `60 E2 46 00` found no matches.
- Raw disassembly closes the browser-control pointer at `[this+0x26c]` through `sub_46BA90`, clears `[this+0x26c]`, calls receiver virtual slots `+0x38` and `+0x40`, and unregisters through `dword_67A74C`/`sub_469180`.
- `by-file/WebBoardDialog.md` places the old dialog range start at `0x0046e260`, and `by-class/WebBoardDialogOld.md` already records this helper as old-dialog raw teardown-like code.
- The active close/teardown body at `0x0046d360` and old close callback at `0x0046e8f0` share the browser-control shutdown and unregister pattern, but this raw helper is a no-argument variant and does not have a proven dispatch path.

## Source-Quality Notes

- Treat as retained source-shaped old-dialog raw code, not padding or compiler glue.
- Direct old-class ownership is strong enough for documentation routing, but final C++ should remain blank until source name/liveness is proven or the project accepts raw no-xref helper reconstruction.
```

### 3. `by-memory/-ignored.md` Recommendations

Replace the owner-doc line for `0x0046da63-0x0046da70`:

```text
  - Owner docs: [UID:0000Z9][0x0046d580-0x0046da63.WebBoardDialogHandleBoardResponse](by-memory/0x0046d580-0x0046da63.WebBoardDialogHandleBoardResponse.md), [UID:UID_DA70][0x0046da70-0x0046dbca.WebBoardDialogUrlEscapeHelper](by-memory/0x0046da70-0x0046dbca.WebBoardDialogUrlEscapeHelper.md).
```

Insert the following internal padding rows in address order after the `0x0046da63-0x0046da70` row:

```text
- `0x0046dbca-0x0046dbd0` - WebBoardDialog URL escape/visual-refresh alignment padding.
  - Why ignored: confirmed `0xcc` alignment bytes after the raw active URL escape helper and before the vtable-backed visual refresh helper at `0x0046dbd0`.
  - Evidence: 2026-06-16 B001 IDA MCP byte audit reports raw helper body ending at `0x0046dbca`, `sub_46DBD0` beginning at `0x0046dbd0`, and only alignment bytes between them.
  - Owner docs: [UID:UID_DA70][0x0046da70-0x0046dbca.WebBoardDialogUrlEscapeHelper](by-memory/0x0046da70-0x0046dbca.WebBoardDialogUrlEscapeHelper.md), [UID:UID_DBD0][0x0046dbd0-0x0046dcf3.WebBoardDialogVisualRefresh](by-memory/0x0046dbd0-0x0046dcf3.WebBoardDialogVisualRefresh.md).

- `0x0046dcf3-0x0046dd00` - WebBoardDialog visual-refresh/content-draw alignment padding.
  - Why ignored: confirmed `0xcc` alignment bytes after `sub_46DBD0` and before the vtable-backed content draw helper at `0x0046dd00`.
  - Evidence: 2026-06-16 B001 IDA MCP byte audit reports `sub_46DBD0` ending at `0x0046dcf3`, `sub_46DD00` beginning at `0x0046dd00`, and only alignment bytes between them.
  - Owner docs: [UID:UID_DBD0][0x0046dbd0-0x0046dcf3.WebBoardDialogVisualRefresh](by-memory/0x0046dbd0-0x0046dcf3.WebBoardDialogVisualRefresh.md), [UID:UID_DD00][0x0046dd00-0x0046de96.WebBoardDialogDrawContentArea](by-memory/0x0046dd00-0x0046de96.WebBoardDialogDrawContentArea.md).

- `0x0046de96-0x0046dea0` - WebBoardDialog content-draw/frame-draw alignment padding.
  - Why ignored: confirmed `0xcc` alignment bytes after `sub_46DD00` and before the vtable-backed frame/chrome draw helper at `0x0046dea0`.
  - Evidence: 2026-06-16 B001 IDA MCP byte audit reports `sub_46DD00` ending at `0x0046de96`, `sub_46DEA0` beginning at `0x0046dea0`, and only alignment bytes between them.
  - Owner docs: [UID:UID_DD00][0x0046dd00-0x0046de96.WebBoardDialogDrawContentArea](by-memory/0x0046dd00-0x0046de96.WebBoardDialogDrawContentArea.md), [UID:UID_DEA0][0x0046dea0-0x0046e25b.WebBoardDialogDrawFrameChrome](by-memory/0x0046dea0-0x0046e25b.WebBoardDialogDrawFrameChrome.md).

- `0x0046e25b-0x0046e260` - WebBoardDialog frame-draw/old-teardown alignment padding.
  - Why ignored: confirmed `0xcc` alignment bytes after `sub_46DEA0` and before the raw old WebBoardDialogOld teardown body at `0x0046e260`.
  - Evidence: 2026-06-16 B001 IDA MCP byte audit reports `sub_46DEA0` ending at `0x0046e25b`, raw method-shaped code beginning at `0x0046e260`, and only alignment bytes between them.
  - Owner docs: [UID:UID_DEA0][0x0046dea0-0x0046e25b.WebBoardDialogDrawFrameChrome](by-memory/0x0046dea0-0x0046e25b.WebBoardDialogDrawFrameChrome.md), [UID:UID_E260][0x0046e260-0x0046e294.WebBoardDialogOldBrowserControlTeardownRaw](by-memory/0x0046e260-0x0046e294.WebBoardDialogOldBrowserControlTeardownRaw.md).
```

Replace the owner-doc line for `0x0046e294-0x0046e2a0`:

```text
  - Owner docs: [UID:UID_E260][0x0046e260-0x0046e294.WebBoardDialogOldBrowserControlTeardownRaw](by-memory/0x0046e260-0x0046e294.WebBoardDialogOldBrowserControlTeardownRaw.md), [UID:0000ZA][0x0046e2a0-0x0046e4b6.WebBoardDialogOldLayoutRefresh](by-memory/0x0046e2a0-0x0046e4b6.WebBoardDialogOldLayoutRefresh.md).
```

### 4. `by-memory/-coverage-report.md` Recommendations

Replace the existing single UID `000210` row with this address-ordered block. The supervisor should substitute allocated real UIDs for placeholders before applying.

```text
    - [UID:000210][0x0046da70-0x0046e294.WebBoardDialogRenderEscapeAndOldTeardownHelpers](by-memory/0x0046da70-0x0046e294.WebBoardDialogRenderEscapeAndOldTeardownHelpers.md) 0x0046da70-0x0046e294 | split-index | WebBoardDialogRenderEscapeAndOldTeardownHelpers : ignored/non-emitting : 88% : strong : B001 2026-06-16 reclassifies this broad range as a reviewed non-emitting split index over active WebBoardDialog URL escape/render helpers, internal padding, and a raw WebBoardDialogOld teardown helper; exact child pages carry source ownership and parent C++ remains blank.
        - [UID:UID_DA70][0x0046da70-0x0046dbca.WebBoardDialogUrlEscapeHelper](by-memory/0x0046da70-0x0046dbca.WebBoardDialogUrlEscapeHelper.md) 0x0046da70-0x0046dbca | raw file-local helper | WebBoardDialogUrlEscapeHelper : reconstructable : 86% : strong : Raw active WebBoardDialog URL escape helper; IDA MCP confirms no function object, no direct xrefs, no absolute pointer constants, active state refs to `byte_67ABA8`/`byte_67ABB0`, active character-set reads at `0x0066d430`/`0x0066d43c`, and percent-escape formatting behavior. Final C++ remains blank pending raw-helper liveness/source-name proof.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0046dbca-0x0046dbd0 | padding | WebBoardDialog URL escape/visual-refresh alignment : ignored : 100% : strong : Confirmed `0xcc` alignment bytes after raw helper `0x0046da70-0x0046dbca` and before active vtable helper `sub_46DBD0`.
        - [UID:UID_DBD0][0x0046dbd0-0x0046dcf3.WebBoardDialogVisualRefresh](by-memory/0x0046dbd0-0x0046dcf3.WebBoardDialogVisualRefresh.md) 0x0046dbd0-0x0046dcf3 | class method | WebBoardDialogVisualRefresh : reconstructable : 86% : strong : Active WebBoardDialog vtable slot `+0x44` at `0x00613620`; clears pending browser/control state, invokes the frame draw vslot, resolves selected child/control geometry, and draws the selected-control highlight using ids `0x84`/`0x86`. Final source name remains provisional.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0046dcf3-0x0046dd00 | padding | WebBoardDialog visual-refresh/content-draw alignment : ignored : 100% : strong : Confirmed `0xcc` alignment bytes after active helper `sub_46DBD0` and before active helper `sub_46DD00`.
        - [UID:UID_DD00][0x0046dd00-0x0046de96.WebBoardDialogDrawContentArea](by-memory/0x0046dd00-0x0046de96.WebBoardDialogDrawContentArea.md) 0x0046dd00-0x0046de96 | class method | WebBoardDialogDrawContentArea : reconstructable : 86% : strong : Active WebBoardDialog vtable slot `+0x50` at `0x0061362c`; loads content/background resources through `off_60DB5C`/`off_60DB78`, insets the dialog rect, computes tile counts, and tiles the content area. Final source/resource names remain provisional.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0046de96-0x0046dea0 | padding | WebBoardDialog content-draw/frame-draw alignment : ignored : 100% : strong : Confirmed `0xcc` alignment bytes after active helper `sub_46DD00` and before active helper `sub_46DEA0`.
        - [UID:UID_DEA0][0x0046dea0-0x0046e25b.WebBoardDialogDrawFrameChrome](by-memory/0x0046dea0-0x0046e25b.WebBoardDialogDrawFrameChrome.md) 0x0046dea0-0x0046e25b | class method | WebBoardDialogDrawFrameChrome : reconstructable : 86% : strong : Active WebBoardDialog vtable slot `+0x54` at `0x00613630`; draws frame/chrome tiles from `off_60DB94`/`off_60DBB0` when browser-control state at `this+0x260` is clear. Final source/resource names remain provisional.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0046e25b-0x0046e260 | padding | WebBoardDialog frame-draw/old-teardown alignment : ignored : 100% : strong : Confirmed `0xcc` alignment bytes after active helper `sub_46DEA0` and before raw old-dialog teardown body `0x0046e260`.
        - [UID:UID_E260][0x0046e260-0x0046e294.WebBoardDialogOldBrowserControlTeardownRaw](by-memory/0x0046e260-0x0046e294.WebBoardDialogOldBrowserControlTeardownRaw.md) 0x0046e260-0x0046e294 | raw class helper | WebBoardDialogOldBrowserControlTeardownRaw : reconstructable : 85% : strong : Raw no-function no-xref WebBoardDialogOld teardown body at the old-dialog boundary; closes and clears `[this+0x26c]`, calls vslots `+0x38`/`+0x40`, and unregisters through `dword_67A74C`/`sub_469180`. Final C++ remains blank pending raw-helper liveness/source-name proof.
```

Also update the existing external padding coverage rows after UID substitution:

```text
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0046da63-0x0046da70 | padding | WebBoardDialog response/URL-escape alignment : ignored : 100% : strong : Confirmed alignment padding before the raw URL escape helper at `0x0046da70`; owner-doc context should point to [UID:0000Z9][0x0046d580-0x0046da63.WebBoardDialogHandleBoardResponse](by-memory/0x0046d580-0x0046da63.WebBoardDialogHandleBoardResponse.md) and [UID:UID_DA70][0x0046da70-0x0046dbca.WebBoardDialogUrlEscapeHelper](by-memory/0x0046da70-0x0046dbca.WebBoardDialogUrlEscapeHelper.md).
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0046e294-0x0046e2a0 | padding | WebBoardDialogOld teardown/layout alignment : ignored : 100% : strong : Confirmed alignment padding after raw old teardown helper `0x0046e260-0x0046e294` and before `sub_46E2A0`; owner-doc context should point to [UID:UID_E260][0x0046e260-0x0046e294.WebBoardDialogOldBrowserControlTeardownRaw](by-memory/0x0046e260-0x0046e294.WebBoardDialogOldBrowserControlTeardownRaw.md) and [UID:0000ZA][0x0046e2a0-0x0046e4b6.WebBoardDialogOldLayoutRefresh](by-memory/0x0046e2a0-0x0046e4b6.WebBoardDialogOldLayoutRefresh.md).
```

## Blockers and Residual Risk

- Original source names are not proven for any of the three active virtual helpers. The recommended filenames are role names based on slot position, decompilation, and BrowserDialog comparison.
- Raw helper live reachability for `0x0046da70` and `0x0046e260` is not proven. IDA xrefs and absolute pointer scans were negative for both.
- Active resource handle names/types for `off_60DB5C`, `off_60DB78`, `off_60DB94`, and `off_60DBB0` remain unresolved.
- UID allocation for new child pages is pending supervisor/validator action.
- No IDA naming/function-definition changes were made; raw function promotion should be handled only by a deliberate IDA normalization pass.

## Work Performed in This Turn

Changed files:

- Created `tools/leaser/Agents/Agent-B001/research/000210-webboard-render-escape-source-split.md`.

Leases:

- None. No leased by-* files were edited.

Validation:

- Not run, because no by-* documentation files were edited. If supervisor applies the recommended by-* edits, run:

> Executable block R001 was removed from this report and preserved verbatim in [000210-webboard-render-escape-source-split-removed.md](000210-webboard-render-escape-source-split-removed.md). The archived block is non-authoritative and must not be executed.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/000210-webboard-render-escape-source-split.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:20","uid":"000210"} -->
<!-- {"agent":"B001","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 000210-webboard-render-escape-source-split-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B001/000210-webboard-render-escape-source-split.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"000210"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
