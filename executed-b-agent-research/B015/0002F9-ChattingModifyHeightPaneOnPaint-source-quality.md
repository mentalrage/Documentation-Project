** TARGET-REPORT-UID:0002F9 **
** AUTHOR-AGENT-ID:B015 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002F9 ChattingModifyHeightPaneOnPaint Source-Quality Reanalysis

Agent: Agent-B015  
Assignment: `B015 new report-only assignment, per current supervisor rules`  
Target: [UID:0002F9] `by-memory/0x00480bb0-0x00480c45.ChattingModifyHeightPaneOnPaint.md`  
Report path: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B015\research\0002F9-ChattingModifyHeightPaneOnPaint-source-quality.md`  
Mode: report-only. No by-* documentation file and no `by-memory/-coverage-report.md` were edited by this pass.

## Final Recommendation

- Keep [UID:0002F9] as a source-authored `ChattingModifyHeightPane::OnPaint` virtual method.
- Keep direct owner/emitter [UID:00001W] `ChattingModifyHeightPane`; source file route remains [UID:0000I5] `Chatting`, `NexusTK/social/Chatting.cpp`.
- Raise target metadata from `COMPLETION:84`, `CONFIDENCE:90` to `COMPLETION:88`, `CONFIDENCE:92`.
- Keep `RECONSTRUCTABLE:TRUE`, `CANONICAL_OWNER:00001W`, `EMITTER_UIDS:00001W`.
- Emit first-draft C++ on the target. The method now clears the current report's C++ gate: it is reconstructable, has a valid emitter route, and the existing average `(84 + 90) / 2 = 87` is already above the current `>85` code-entry threshold.
- Source-facing helper names are strong enough for a draft:
  - `0x00457a60`: `EPFTileContext::Initialize` / `InitTileContext`
  - `0x004d02f0`: `ResourceLayoutTable::LookupLayoutEntry`
  - `0x004b9980`: shared Surface/GrafPort `RenderTileFrame`
  - `0x005446b0`: `Pane::SetMode`
  - `0x004b9660`: `GrafPort::SetDrawColor` / active draw-fill color setter
  - `0x0069b3fc`: Surface callback-table slot 7, source-facing `FillRect` / rectangle fill-refresh in this call shape
- The disabled branch should be documented as an active clear/suppression path: it sets pane mode `1`, sets draw color `0`, and calls the rectangle fill/refresh callback over `this+0x44`. It is not merely "skip drawing", not a destructor/unlink path, and not evidence for toggling the Pane visible byte.

## Evidence Checked

Read directly for this report:

- Rules and assignment context:
  - `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Supervisor.md`
  - `E:\NTK\GhidraBridge\.codex\AGENTS.md`
  - Agent-B015 `goal.md`, `notes.md`, current assignment messages, and prior B015 report style.
- Target/support documentation:
  - [UID:0002F9] `by-memory/0x00480bb0-0x00480c45.ChattingModifyHeightPaneOnPaint.md`
  - [UID:00001W] `by-class/ChattingModifyHeightPane.md`
  - [UID:0000I5] `by-file/Chatting.md`
  - [UID:000104] `by-memory/0x0047efb0-0x00483ef7.ChattingUI.md`
  - Sibling methods [UID:0002F6] `ChattingModifyHeightPaneOnMouseEvent`, [UID:0002F7] `CancelHotkeys`, and [UID:0002F8] `SetLineCount`
  - [UID:0002F3] `ChattingBackPaneUpdateVisibility`
  - [UID:0002FD] `ChattingVarietyPaneOnPaint`
  - [UID:0003AT] `ChattingVtableData`
  - [UID:0003AU] `ChattingStringResourceData`
  - [UID:0002XE] / [UID:0002XF] `g_pChattingHandlePane`
- Shared helper/global/type docs:
  - [UID:0000XY] `EPFTileContext`
  - [UID:0002KP] `ResourceLayoutTableLookupLayoutEntry`
  - [UID:000165] `SurfacePaintHelpers`
  - [UID:000162] `GrafPortDrawStateAccessors`
  - [UID:0002V7] `PaneSetMode`
  - [UID:0001PI] and [UID:0000TN] `SurfaceRenderCallbackTable`
  - [UID:0000QU] `g_pEPFLib`
  - `by-type/by-struct/PaneLayout.md`
  - `by-type/by-struct/RegistryConfigUserProfileBlock.md`
- Current coverage row:
  - `by-memory/-coverage-report.md`, line 875 for [UID:0002F9].
- Raw binary:
  - `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`
  - Size: `2679296`
  - SHA-256: `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`

IDA MCP was not available as a direct live tool in this session. Existing by-* docs include IDA-backed facts. Fresh validation here used a local PE parser and Capstone disassembly over the executable above, plus current project documentation and validator output.

## Exact Range, Padding, And Raw PE Recheck

Target range is exact:

```text
VA start: 0x00480bb0
VA end:   0x00480c45 exclusive
Length:   0x95 / 149 bytes
PE raw:   0x0007ffb0-0x00080045
Section:  .text
Target bytes SHA-256: be3b5b7def9e1dbfe1d0e0ccc2039407ad00e694af5e1ecc5df9002c7af42a2f
```

Padding/alignment:

```text
0x00480ba3-0x00480bb0: 13 bytes, all cc
0x00480c45-0x00480c50: 11 bytes, all cc
```

The predecessor body [UID:0002F8] `ChattingModifyHeightPaneSetLineCount` ends at `0x00480ba3`. The successor ChattingVarietyPane cluster starts at `0x00480c50`. There is no unclaimed executable body in either gap.

Full target disassembly from the raw PE:

```asm
00480bb0  55                    push    ebp
00480bb1  8b ec                 mov     ebp, esp
00480bb3  83 ec 2c              sub     esp, 0x2c
00480bb6  a1 24 2f 67 00        mov     eax, dword ptr [0x672f24]
00480bbb  33 c5                 xor     eax, ebp
00480bbd  89 45 fc              mov     dword ptr [ebp - 4], eax
00480bc0  a1 e0 ad 67 00        mov     eax, dword ptr [0x67ade0]
00480bc5  56                    push    esi
00480bc6  8b f1                 mov     esi, ecx
00480bc8  57                    push    edi
00480bc9  80 b8 18 01 00 00 00  cmp     byte ptr [eax + 0x118], 0
00480bd0  8d 7e 44              lea     edi, [esi + 0x44]
00480bd3  74 47                 je      0x00480c1c
00480bd5  8d 4d d4              lea     ecx, [ebp - 0x2c]
00480bd8  e8 83 6e fd ff        call    0x00457a60
00480bdd  8b 0d 44 a7 67 00     mov     ecx, dword ptr [0x67a744]
00480be3  8d 45 d4              lea     eax, [ebp - 0x2c]
00480be6  50                    push    eax
00480be7  6a 00                 push    0
00480be9  68 00 53 61 00        push    0x00615300
00480bee  e8 fd f6 04 00        call    0x004d02f0
00480bf3  6a 00                 push    0
00480bf5  68 18 53 61 00        push    0x00615318
00480bfa  6a 00                 push    0
00480bfc  57                    push    edi
00480bfd  8d 45 e4              lea     eax, [ebp - 0x1c]
00480c00  8b ce                 mov     ecx, esi
00480c02  50                    push    eax
00480c03  8d 45 d4              lea     eax, [ebp - 0x2c]
00480c06  50                    push    eax
00480c07  e8 74 8d 03 00        call    0x004b9980
00480c0c  5f                    pop     edi
00480c0d  5e                    pop     esi
00480c0e  8b 4d fc              mov     ecx, dword ptr [ebp - 4]
00480c11  33 cd                 xor     ecx, ebp
00480c13  e8 17 6b 14 00        call    0x005c772f
00480c18  8b e5                 mov     esp, ebp
00480c1a  5d                    pop     ebp
00480c1b  c3                    ret
00480c1c  6a 01                 push    1
00480c1e  e8 8d 3a 0c 00        call    0x005446b0
00480c23  6a 00                 push    0
00480c25  8b ce                 mov     ecx, esi
00480c27  e8 34 8a 03 00        call    0x004b9660
00480c2c  57                    push    edi
00480c2d  8b ce                 mov     ecx, esi
00480c2f  ff 15 fc b3 69 00     call    dword ptr [0x0069b3fc]
00480c35  8b 4d fc              mov     ecx, dword ptr [ebp - 4]
00480c38  5f                    pop     edi
00480c39  33 cd                 xor     ecx, ebp
00480c3b  5e                    pop     esi
00480c3c  e8 ee 6a 14 00        call    0x005c772f
00480c41  8b e5                 mov     esp, ebp
00480c43  5d                    pop     ebp
00480c44  c3                    ret
```

Stack/cookie shape:

- The method is a `thiscall` body with `this` in `ecx`.
- It saves `this` in `esi`.
- It stores `this + 0x44` in `edi`; this is the inherited pane bounds/current rectangle.
- It uses a 0x28-byte local `EPFTileContext` at `ebp-0x2c`; `ebp-0x1c` is `localContext + 0x10`, the context bounds/source-rect field.
- It has duplicated compiler security-cookie epilogues through `0x005c772f`, one per branch.

## Caller, Reachability, Vtable, And Source Route

Fresh range-wide raw scan:

- Absolute VA dword hits into `0x00480bb0-0x00480c45`: exactly one.
  - File offset `0x0021385c`, VA `0x00614e5c`, value `0x00480bb0`.
  - This is the `ChattingModifyHeightPane` primary vtable slot.
- Direct rel32 `E8` calls to `0x00480bb0`: zero.
- Direct rel32 `E9` jumps or long conditional branches into the range: zero.
- Range-wide naive RVA dword hits are false positives in instruction immediates and unrelated `.rdata` bytes; they do not correspond to loaded code pointers.
- Naive short-branch scan found one true internal branch at `0x00480bd3 -> 0x00480c1c` and one unaligned false positive inside instruction bytes. There is no external short-branch route.

Vtable context from raw `.rdata`:

```text
ChattingModifyHeightPane primary vtable: 0x00614e18
slot 00 0x00614e18 -> 0x00483c00  scalar deleting destructor
slot 01 0x00614e1c -> 0x004f4b10
slot 02 0x00614e20 -> 0x0041b6c0
slot 03 0x00614e24 -> 0x004b8e20
slot 04 0x00614e28 -> 0x0041d680
slot 05 0x00614e2c -> 0x00544730
slot 06 0x00614e30 -> 0x00544750
slot 07 0x00614e34 -> 0x005447a0
slot 08 0x00614e38 -> 0x00544800  Pane::InvalidateRect
slot 09 0x00614e3c -> 0x00544a20
slot 10 0x00614e40 -> 0x00544b80
slot 11 0x00614e44 -> 0x00544bd0
slot 12 0x00614e48 -> 0x00544c70
slot 13 0x00614e4c -> 0x00544cb0
slot 14 0x00614e50 -> 0x00544ce0
slot 15 0x00614e54 -> 0x00544d30
slot 16 0x00614e58 -> 0x00544d70
slot 17 0x00614e5c -> 0x00480bb0  ChattingModifyHeightPane::OnPaint

ChattingModifyHeightPane secondary vtable: 0x00614e64
slot 01 0x00614e68 -> 0x00480890  OnMouseEvent
slot 04 0x00614e74 -> 0x00480a80  OnKeyEvent/cancel helper

ChattingModifyHeightPane tertiary vtable: 0x00614e94
slot 00 0x00614e94 -> 0x00483a4e  destructor adjustor thunk
```

This is the source route. The method is source-authored virtual `OnPaint`, reached through `Pane`/chat UI virtual dispatch from the `ChattingModifyHeightPane` class declaration. It is not a raw callback island and not an address-taken free helper. The only data pointer is the compiler-emitted vtable entry.

Rejected source routes:

- Not `ChattingHandlePane`: this method reads `g_pChattingHandlePane->m_secondaryChatEnabled`, but the receiver and vtable slot are `ChattingModifyHeightPane`.
- Not `Surface`/`GrafPort`: the method calls shared render helpers, but its receiver, vtable, fields, resource literals, and neighboring methods are chat height-handle code.
- Not `EPFTileContext` or `ResourceLayoutTable`: those are dependencies only.
- Not compiler-generated glue: the body has ordinary branch/resource/render logic, unlike nearby destructor thunks and forwarders.

## Branch Behavior And Render Path

### Enabled branch

Condition:

```asm
mov eax, [0x0067ade0]       ; g_pChattingHandlePane
cmp byte ptr [eax+0x118], 0 ; m_secondaryChatEnabled
je disabled
```

The method intentionally does not null-check `g_pChattingHandlePane`. The source draft should not add a null guard. Existing construction/source context indicates the chat singleton is expected to exist when this pane is painted.

Enabled behavior:

1. Initialize a 0x28-byte `EPFTileContext` local through `0x00457a60`.
2. Load `g_pEPFLib` from `0x0067a744`.
3. Call `ResourceLayoutTable::LookupLayoutEntry(L"CHATSC.EPF", 0, &tileContext)`.
4. Call `RenderTileFrame(&tileContext, &tileContext.m_bounds, &this->m_bounds, 0, L"invenbut.pal", 0)`.

Important argument detail:

- The `RenderTileFrame` source rectangle is `lea eax, [ebp-0x1c]`.
- The local tile context starts at `ebp-0x2c`.
- Therefore `ebp-0x1c` is `tileContext + 0x10`, matching the `EPFTileContext` bounds rectangle populated by `LookupLayoutEntry`.
- Do not document this as an independent temporary rectangle.

Resource literals:

| Address | Text | Evidence |
| --- | --- | --- |
| `0x00615300` | `CHATSC.EPF` | pushed at `0x00480be9`; documented in `ChattingStringResourceData` |
| `0x00615318` | `invenbut.pal` | pushed at `0x00480bf5`; shared palette literal documented in `ChattingStringResourceData` |

### Disabled branch

Disabled path starts at `0x00480c1c` when `g_pChattingHandlePane->m_secondaryChatEnabled == 0`:

```asm
push 1
call 0x005446b0              ; Pane::SetMode(1)
push 0
mov ecx, esi
call 0x004b9660              ; GrafPort active draw/fill color = 0
push edi                     ; this + 0x44
mov ecx, esi
call dword ptr [0x0069b3fc]  ; surface slot 7 fill/refresh callback
```

Best source-facing interpretation:

- This branch suppresses and clears the resize handle when the secondary chat UI is disabled.
- `Pane::SetMode(1)` changes the pane draw/mode byte at `this+0xb5`, invalidating `this+0x44` only if the mode changes.
- `GrafPort::SetDrawColor(0)` writes the active draw/fill color field at `this+0x74`.
- The slot-7 callback at `0x0069b3fc` then fills/refreshes the pane bounds. In control-source language, this is best drafted as `FillRect(&m_bounds)` or `RefreshRect(&m_bounds)` after setting draw color `0`.

What the disabled branch is not:

- It is not a no-op skip path; it actively sets mode/color and refreshes/fills.
- It is not a `Show(false)`/visibility-byte write. No write to `Pane+0xb4` occurs.
- It is not a destructor/remove/unregister path. No layer/event-handler teardown occurs.
- It is not sufficient evidence to name pane mode value `1` as an original `Hidden` enum constant. The strongest safe wording is inactive/disabled/suppressed draw mode.

Sibling evidence:

- [UID:0002F3] `ChattingBackPaneUpdateVisibility` uses the same `g_pChattingHandlePane` root and checks both `+0x114` and `+0x118`; its inactive branch also calls `Pane::SetMode(1)`, `SetDrawColor(0)`, and `dword_69B3FC(this, this+0x44)`.
- [UID:0002F6] `ChattingModifyHeightPaneOnMouseEvent` gates input on `g_pChattingHandlePane->m_secondaryChatEnabled`. That proves the same state suppresses both input and visible handle rendering.
- The paint method itself checks only `+0x118`, so `+0x114` must not be inserted into this target's draft.

## Helper, Global, Field, And Type Names

| Raw/generated name | Best source-facing name | Owner/source placement | Evidence and caveat |
| --- | --- | --- | --- |
| `sub_480BB0` | `ChattingModifyHeightPane::OnPaint` | [UID:00001W] `ChattingModifyHeightPane`, emitted through `Chatting.cpp` | Primary vtable slot `0x00614e5c`; no ordinary direct callers; exact chat-height-handle cluster. |
| `dword_67ADE0` | `g_pChattingHandlePane` | [UID:0000I5] `Chatting.cpp` global singleton | Storage docs show constructor/destructor lifecycle and 15 xrefs; target reads it at `0x00480bc0`. |
| `g_pChattingHandlePane + 0x118` | `ChattingHandlePane::m_secondaryChatEnabled` / `m_isSecondaryChatEnabled` | [UID:00001V] `ChattingHandlePane` layout, used by chat panes | Matches config `m_secondaryChatEnabled` at `g_pConfig + 0x28de80`; controls secondary chat handle/backpane/mouse gating. |
| `dword_67A744` | `g_pEPFLib` | Resource/image library global | Receiver for `LookupLayoutEntry`; target reads it at `0x00480bdd`. |
| `0x00457a60` | `EPFTileContext::Initialize` / `InitTileContext` | [UID:00004I] `EPFTileContext` / render helper source | Initializes 0x28-byte tile context, including bounds at `+0x10`; no target ownership. |
| `0x004d02f0` | `ResourceLayoutTable::LookupLayoutEntry` | [UID:0000BY] `ResourceLayoutTable` | Signature in this target: receiver `g_pEPFLib`, args `resourceName`, `frameIndex`, `outContext`; frame index is `0`. |
| `0x004b9980` | `RenderTileFrame` / shared tile-frame blit wrapper | [UID:0000OC] `Surface` with GrafPort facade evidence | This wrapper resolves palette through `g_pPaletteLib` (`0x0067a7e0`) then dispatches slot `0x0069b3e8`; generated `FittingRoomDownloadControlPane::RenderTileFrame` owner is caller-biased pollution. |
| `0x005446b0` | `Pane::SetMode(unsigned char)` | [UID:0000A2] `Pane` | Writes mode byte `this+0xb5` and invalidates `this+0x44` through vtable slot `+0x20` if changed. |
| `0x004b9660` | `GrafPort::SetDrawColor(int)` / active draw-fill color setter | [UID:0000JR] `GrafPort` draw-state helpers | Leaf setter writes `ecx+0x74`; generated `FittingRoomListPane::SetTextColor` label is rejected. |
| `dword_69B3FC` / `g_pfnLockSurface` | Surface callback-table slot 7; source-facing `FillRect` or rectangle fill-refresh | [UID:0000TN] `SurfaceRenderCallbackTable` / [UID:0000OC] `Surface` | Broad callback slot with 206 xrefs. In this target it is called as `slot7(this, &m_bounds)` after `SetDrawColor(0)`, matching fill/clear/refresh behavior. Generated `g_pfnLockSurface` alias is rejected for control-source prose. |
| `this + 0x44` | `Pane::m_bounds` / current pane rectangle | [UID:0000A2] `Pane` layout | Used as draw destination and fill/refresh rectangle. |
| local `ebp-0x2c` | `EPFTileContext tileContext` | stack local | 0x28-byte local initialized by `0x00457a60`; source rect arg is `tileContext + 0x10`. |

Best source field wording for this target:

- Use `m_bounds` or `m_rect` for `this+0x44`; current `Pane` docs prefer bounds/local rectangle language.
- Use `m_secondaryChatEnabled` for `g_pChattingHandlePane+0x118`.
- Do not invent target-specific fields; the paint method does not read `ChattingModifyHeightPane` drag fields at `+0xf8/+0xfc/+0x100`.

## Heuristic / Inference Reanalysis And Validation

### Source-facing method identity

Best inference: `void ChattingModifyHeightPane::OnPaint()`.

Validation:

- The only real external reference is the primary vtable slot `0x00614e5c`.
- The class docs already place constructor/destructor/mouse/key/set-line-count/paint in the exact `0x004807b0-0x00480c45` cluster.
- The receiver is `ecx=this`; the body reads `this+0x44` and calls inherited pane/render helpers.
- The method's behavior is pure paint/render state handling.

Rejected alternatives:

- `Render`/`Draw` as final source name: possible in isolation, but sibling UI docs and vtable role consistently use `OnPaint`.
- `ChattingHandlePane` method: rejected by vtable and receiver.
- Static helper: rejected by thiscall receiver and vtable reachability.

### `g_pChattingHandlePane + 0x118`

Best inference: `m_secondaryChatEnabled` / `m_isSecondaryChatEnabled`.

Validation:

- `RegistryConfigUserProfileBlock` documents persisted `m_secondaryChatEnabled` at `+0x28de80`.
- `g_pChattingHandlePane` docs identify the singleton as `ChattingHandlePane *`.
- `ChattingBackPaneUpdateVisibility` uses `+0x118` with `+0x114` to decide active chat background rendering.
- `ChattingModifyHeightPaneOnMouseEvent` uses `+0x118` to suppress input.
- This paint method uses `+0x118` alone to decide whether to draw or clear the resize handle.

Rejected alternatives:

- `m_chatVisibleLineCount`: rejected; line count is config dword `+0x28de78` and `ChattingModifyHeightPane::SetLineCount` data, not this runtime byte.
- `m_handleModeIndex`: rejected; config dword `+0x28de7c` and handle mode/state docs are separate from this boolean gate.
- `m_leftToggle`: rejected; adjacent config byte `+0x28de81` is not the xrefed runtime offset here.

### Enabled render path

Best inference: draw frame `0` of `CHATSC.EPF` into the handle pane using palette `invenbut.pal`.

Validation:

- The `LookupLayoutEntry` call pushes `0` as frame index.
- The `RenderTileFrame` call passes `&tileContext`, `&tileContext.bounds`, `&this->m_bounds`, draw mode `0`, palette literal `invenbut.pal`, and flags/options `0`.
- `ChattingStringResourceData` records `CHATSC.EPF` at `0x00615300` with target xref `0x00480be9`, and `invenbut.pal` at `0x00615318` with target xref `0x00480bf5`.
- No alternate frame table or mode state is referenced by this target.

Rejected alternatives:

- Multi-frame or state-dependent scroll handle art: rejected; frame index is literal `0`.
- Separate temporary source rect: rejected; the source rect pointer is `tileContext + 0x10`.
- `CHATVAR`/chat mode button art: rejected; that is sibling [UID:0002FD].

### Disabled branch meaning

Best inference: inactive secondary-chat state clear/suppression of the height-handle rectangle.

Validation:

- The branch calls `Pane::SetMode(1)`, not a visibility setter.
- The branch calls `GrafPort::SetDrawColor(0)` before the slot-7 callback.
- The slot-7 callback shape matches fill/refresh calls in `ChattingBackPaneUpdateVisibility`, `IconsPaneOnPaint`, `ParcelPaneOnPaint`, and progress/control draw paths.
- Input is separately disabled by `OnMouseEvent`; paint is responsible for clearing/suppressing the visual.

Rejected alternatives:

- "Transparent mode" as a final original enum name: plausible but not proven. The safe source-quality statement is mode `1` = inactive/suppressed draw mode in this context.
- "Hidden pane" as a final enum name: too strong because no `Show(false)` or visible-byte write occurs.
- "Disabled branch just invalidates": incomplete because it also sets draw color and calls the fill/refresh callback.

### Helper ownership and generated-name cleanup

Best inference:

- Keep target source under `ChattingModifyHeightPane`.
- Keep helpers in their shared owners.
- Use descriptive helper names without pretending stripped-binary evidence proves exact original spellings.

Validation:

- `0x004b9980` has 311 callers in docs and dispatches through Surface callback slot 2 after palette lookup. It is not fitting-room code despite old generated owner labels.
- `0x004b9660` has broad GrafPort draw-state fan-in and simply writes `ecx+0x74`.
- `0x0069b3fc` has broad callback-table fan-in and generated aliases are callsite-biased.
- `0x00457a60` and `0x004d02f0` are shared render/resource dependencies with existing owner pages above the assignment gate.

Rejected alternatives:

- Moving helper ownership into `Chatting`: rejected because caller breadth crosses many UI/render modules.
- Leaving names as `sub_4B9980`, `sub_4B9660`, or `dword_69B3FC` in source-facing prose: unnecessary now; role and owners are sufficiently documented.
- Using generated `g_pfnLockSurface` in target C++: rejected because this call is not lock-style source behavior; it is fill/refresh of the current bounds after setting draw color.

### First-draft C++ eligibility

Best inference: emit first-draft C++ on the target.

Validation:

- Current target metadata clears the current code gate: `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00001W`, average score `87 > 85`.
- Exact range, branch behavior, all direct callees, all globals, string literals, and local context layout are known.
- The only remaining uncertainty is final original spelling of shared helper wrappers and pane mode enum names. That is not a target-specific no-code blocker under current supervisor rules; it should be reflected with conservative helper names.

Rejected alternative:

- Keeping C++ blank because shared render helpers are not 95/95 final: stale. The current rule no longer requires a 95/95 source gate, and this method can be accurately drafted with descriptive helper names.

## Proposed First-Draft C++

Recommended emitter metadata for target [UID:0002F9]:

```text
COMPLETION:88
CONFIDENCE:92
CANONICAL_OWNER:00001W
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:00001W
EMITTER_POSITION_OPTIONAL:
Source route: [UID:00001W] ChattingModifyHeightPane -> [UID:0000I5] Chatting.cpp
Generated output: auto-generated/NexusTK/social/Chatting.cpp
```

Proposed first-draft body:

```cpp
void ChattingModifyHeightPane::OnPaint()
{
    if (g_pChattingHandlePane->m_secondaryChatEnabled)
    {
        EPFTileContext tileContext;
        tileContext.Initialize();

        g_pEPFLib->LookupLayoutEntry(L"CHATSC.EPF", 0, &tileContext);
        RenderTileFrame(&tileContext,
                        &tileContext.m_bounds,
                        &m_bounds,
                        0,
                        L"invenbut.pal",
                        0);
        return;
    }

    SetMode(1);
    SetDrawColor(0);
    FillRect(&m_bounds);
}
```

Notes for implementation:

- Do not add `if (g_pChattingHandlePane != NULL)`. The binary dereferences the singleton unconditionally.
- Do not add `g_pChattingHandlePane->m_handleModeState` / `+0x114` checks. This target checks only `+0x118`.
- If the implemented codebase uses `Rect`/`RECT`/`RectBounds`, substitute the local standard name for `m_bounds` and `tileContext.m_bounds`.
- If the implemented codebase standardizes the slot-7 wrapper as `RefreshRect` instead of `FillRect`, use that local wrapper name. The raw effect remains `SetDrawColor(0)` followed by `dword_69B3FC(this, &m_bounds)`.
- If the implemented codebase standardizes `RenderTileFrame` as a `GrafPort` method, keep it as an inherited call; do not route it through `Chatting`.

## Open-Question Closure

Open question: "Name the render helper sequence."

- Closed for target incorporation. Use `EPFTileContext::Initialize`, `ResourceLayoutTable::LookupLayoutEntry`, and shared Surface/GrafPort `RenderTileFrame`. Keep exact original spelling descriptive, but do not leave `sub_457A60`, `sub_4D02F0`, or `sub_4B9980` unexplained.

Open question: "Confirm disabled branch hidden/transparent/both."

- Closed as far as binary evidence allows. The disabled branch sets `Pane` mode `1`, sets draw/fill color `0`, and fills/refreshes `this+0x44`. It suppresses/clears the visible handle for disabled secondary chat. The exact original enum name for mode `1` cannot be proven from this target alone; use inactive/suppressed draw mode, not final `Hidden` or `Transparent` naming.

Open question: "Field names."

- Closed for this target. Use `g_pChattingHandlePane->m_secondaryChatEnabled` for `0x0067ade0 + 0x118`; use inherited `m_bounds` / `Pane::m_bounds` for `this+0x44`. No `ChattingModifyHeightPane` drag fields are touched by this paint body.

Open question: "Owner/source placement."

- Closed. Direct owner/emitter remains [UID:00001W] `ChattingModifyHeightPane`; source file route remains [UID:0000I5] `Chatting.cpp`. Helper dependencies remain in render/resource/core owners.

Open question: "Is first-draft C++ eligible?"

- Closed. Yes. Emit on [UID:0002F9] with conservative shared-helper names and the C++ body above.

## Exact Target / Support Implementation Checklist

If accepted, the implementation callback should apply the following scope.

1. Target [UID:0002F9] `by-memory/0x00480bb0-0x00480c45.ChattingModifyHeightPaneOnPaint.md`
   - Change metadata to `COMPLETION:88`, `CONFIDENCE:92`; keep `CANONICAL_OWNER:00001W`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00001W`.
   - Replace stale "below 95/95 gate" no-code rationale with the current code-gate result and first-draft C++.
   - Add raw PE facts: raw offset `0x7ffb0`, raw end `0x80045`, length `0x95`, target byte SHA-256, predecessor/successor `cc` padding, and full branch/callee summary.
   - Add vtable reachability: only absolute VA pointer into range is `0x00614e5c -> 0x00480bb0`; no direct external branch/call route.
   - Add explicit source-facing names for every helper/global:
     `g_pChattingHandlePane`, `m_secondaryChatEnabled`, `g_pEPFLib`, `EPFTileContext::Initialize`, `ResourceLayoutTable::LookupLayoutEntry`, `RenderTileFrame`, `Pane::SetMode`, `GrafPort::SetDrawColor`, and slot-7 `FillRect`/refresh.
   - Add disabled-branch wording: active clear/suppression path with mode `1`, draw color `0`, and bounds fill/refresh; not only skip drawing and not visibility-byte proof.
   - Populate the reconstruction C++ block with the draft above, adapted to local type/wrapper names.

2. Support [UID:00001W] `by-class/ChattingModifyHeightPane.md`
   - Update the `OnPaint` method row to mention `g_pChattingHandlePane->m_secondaryChatEnabled`, `CHATSC.EPF` frame `0`, `invenbut.pal`, and the disabled clear path.
   - Add B015 source-quality note that `OnPaint` is now code-eligible and should emit through the class.
   - Keep drag fields unchanged: `m_dragActive`, `m_dragAnchorY`, and `m_handleRect` are not used by this paint method.
   - Optional score adjustment: raise class from `87/91` to `88/92` only if the class page incorporates the paint-method source-quality details; otherwise leave score unchanged.

3. Support [UID:0000I5] `by-file/Chatting.md`
   - Update the `ChattingModifyHeightPane` row/change notes to include B015 `OnPaint` source-quality execution and first-draft C++.
   - Keep source path `NexusTK/social/Chatting.cpp`.
   - Do not move `RenderTileFrame`, draw-state accessors, or callback-table ownership into `Chatting`.
   - Optional score adjustment: raise from `85/88` to `86/89` only if the file page incorporates the new code-ready child note.

4. Support [UID:000104] `by-memory/0x0047efb0-0x00483ef7.ChattingUI.md`
   - Update the covered range row for `0x00480bb0-0x00480c45` to name the helper sequence and disabled clear path.
   - Keep the aggregate owner/emitter unchanged; no aggregate C++ is needed.

5. Support [UID:0003AT] `by-memory/0x00614cdc-0x00615284.ChattingVtableData.md`
   - Optional targeted support update: add the exact `ChattingModifyHeightPane` primary slot mapping `0x00614e5c -> 0x00480bb0 OnPaint` if slot-level entries are expanded.
   - No metadata change required solely for this target.

6. Support [UID:0003AU] `by-memory/0x00615284-0x00615460.ChattingStringResourceData.md`
   - Existing string rows for `CHATSC.EPF` and `invenbut.pal` are correct.
   - Optional note: `CHATSC.EPF` frame `0` is consumed by `ChattingModifyHeightPane::OnPaint`.
   - No metadata change required.

7. Support [UID:0002XE] / [UID:0002XF] `g_pChattingHandlePane`
   - Optional support note: [UID:0002F9] reads runtime byte `+0x118` as secondary-chat-enabled paint gate.
   - Ensure prose distinguishes `+0x118` from target-selection cleanup byte `+0x111`.
   - No ownership change.

8. Support [UID:000162] `GrafPortDrawStateAccessors`
   - No required score change. If touched, add [UID:0002F9] as another concrete consumer of `0x004b9660` active draw/fill color setter with value `0`.
   - Keep rejected generated labels documented.

9. Support [UID:000165] `SurfacePaintHelpers`
   - No required score change. If touched, add [UID:0002F9] as a `RenderTileFrame` consumer using `CHATSC.EPF` / `invenbut.pal`.
   - Keep direct owner [UID:0000OC] `Surface`.

10. Support [UID:0000TN] / [UID:0001PI] `SurfaceRenderCallbackTable`
    - No required score change. If touched, add [UID:0002F9] as a slot-7 fill/refresh consumer and preserve rejection of generated `g_pfnLockSurface` as source-facing control prose.

11. Validation after implementation
    - Run the scoped validator on the target file.
    - If support docs are edited, run scoped validator on each touched support file.
    - Do not edit `by-memory/-coverage-report.md`; supervisor applies row text.

## Score / Owner / Emitter Recommendations

Target [UID:0002F9]:

```text
COMPLETION:88
CONFIDENCE:92
CANONICAL_OWNER:00001W
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:00001W
EMITTER_POSITION_OPTIONAL:
```

Rationale:

- Completion rises because the report closes the disabled-branch meaning, helper naming, field naming, vtable reachability, range/padding, and first-draft C++ eligibility.
- Confidence rises because raw PE facts independently confirm the exact 0x95-byte body, only vtable pointer route, helper call order, string arguments, and branch semantics.
- Completion remains below final-audit range because stripped binary evidence still cannot prove the original names for pane mode enum value `1`, slot-7 wrapper spelling, or the exact public spelling of `RenderTileFrame`/`FillRect`.

Support score recommendations:

- [UID:00001W] `ChattingModifyHeightPane`: optional `88/92` after incorporating this pass.
- [UID:0000I5] `Chatting`: optional `86/89` after incorporating this pass.
- [UID:000104] `ChattingUI`: optional score unchanged unless its coverage/children prose is materially refreshed.
- Shared helper pages: no required score changes; they already contain sufficient owner/name evidence for this target.

## Supervisor-Owned Coverage Row Text

Current target row:

```text
        - [UID:0002F9][0x00480bb0-0x00480c45.ChattingModifyHeightPaneOnPaint](by-memory/0x00480bb0-0x00480c45.ChattingModifyHeightPaneOnPaint.md) 0x00480bb0-0x00480c45 | paint method | ChattingModifyHeightPaneOnPaint : reconstructable : 84% : strong : Live IDA verifies exact paint bounds, vtable-only reachability, no ordinary callers, full callee set, `CHATSC.EPF` and `invenbut.pal` render assets, enabled and disabled branches, dispatcher refresh, padding, and security-cookie exits.
```

Proposed exact replacement row:

```text
        - [UID:0002F9][0x00480bb0-0x00480c45.ChattingModifyHeightPaneOnPaint](by-memory/0x00480bb0-0x00480c45.ChattingModifyHeightPaneOnPaint.md) 0x00480bb0-0x00480c45 | paint method | ChattingModifyHeightPaneOnPaint : reconstructable : 88% : strong : B015 source-quality reanalysis confirms exact 0x95-byte body at PE raw 0x0007ffb0, 13-byte/11-byte `0xcc` padding, vtable-only reachability through `0x00614e5c`, no external direct branch/call route, enabled `g_pChattingHandlePane->m_secondaryChatEnabled` render branch loading frame 0 of `CHATSC.EPF` into `EPFTileContext` and drawing `tileContext.m_bounds` to `this+0x44` with `invenbut.pal`, disabled branch as `Pane::SetMode(1)` plus `GrafPort::SetDrawColor(0)` and Surface slot-7 fill/refresh, shared helper names/owners resolved, and first-draft `ChattingModifyHeightPane::OnPaint` C++ ready for `Chatting.cpp`.
```

Do not let B015 apply this row directly while the shared `by-memory/-coverage-report.md` ban is active.

## Scoped Validator Baseline

Initial command attempted from the old expected location:

> Executable block R001 was removed from this report and preserved verbatim in [0002F9-ChattingModifyHeightPaneOnPaint-source-quality-removed.md](0002F9-ChattingModifyHeightPaneOnPaint-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Result:

```text
Exit code: 1
can't open file 'E:\NTK\GhidraBridge\source-3\tools\validator.py': [Errno 2] No such file or directory
```

Resolved validator location and scoped baseline command:

> Executable block R002 was removed from this report and preserved verbatim in [0002F9-ChattingModifyHeightPaneOnPaint-source-quality-removed.md](0002F9-ChattingModifyHeightPaneOnPaint-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Result:

```text
Exit code: 0
mode: file
scope: direct by-* folders under root
apply: False
scanned markdown files: 1
ok: 1
ok           0002F9 by-memory/0x00480bb0-0x00480c45.ChattingModifyHeightPaneOnPaint.md UID header exists
stats_incremental_skip 0002F9 project-level/-auto-completion-stats.md dry run; pass --apply to update generated stats rows
dry run only; pass --apply to write changes
```

The validator dry run also reported expected generated-output noops/empty-emitter notices outside this target. No files were changed by the validator.

## Changed Files

Created:

```text
E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B015\research\0002F9-ChattingModifyHeightPaneOnPaint-source-quality.md
```

Not edited:

```text
E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x00480bb0-0x00480c45.ChattingModifyHeightPaneOnPaint.md
E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\-coverage-report.md
any other by-* documentation file
```

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B015","command_id":"000000004165","destination_path":"executed-b-agent-research/B015/0002F9-ChattingModifyHeightPaneOnPaint-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:37","uid":"0002F9"} -->
<!-- {"agent":"B015","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002F9-ChattingModifyHeightPaneOnPaint-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B015/0002F9-ChattingModifyHeightPaneOnPaint-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002F9"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
