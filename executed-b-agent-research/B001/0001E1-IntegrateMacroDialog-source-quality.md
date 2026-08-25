** TARGET-REPORT-UID:0001E1 **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B001 0001E1 IntegrateMacroDialog Source-Quality Report

## Assignment And Scope

- Agent: B001.
- Assignment ID: `B001-report-0001E1-integrate-macro-dialog-source-quality-20260626`.
- Target UID/path: [UID:0001E1] `by-memory/0x00541b30-0x00542265.IntegrateMacroDialog.md`.
- Queue source: `auto-generated/-ag-research-tracker.md` -> `## by-memory` -> `### Not-Covered Files - Reconstructable`. The queue row is stale (`80/84`) relative to the current source doc (`85/88`).
- Starting target metadata: `COMPLETION:85`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000KY`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000KY`, blank formal C++.
- Required report path: `tools/leaser/Agents/Agent-B001/research/0001E1-IntegrateMacroDialog-source-quality.md`.
- Report-only pass: no target/support by-* docs, generated files, project-level files, validator/tool state, IDA DB files, `by-memory/-coverage-report.md`, or any other `-coverage-report.md` were edited.
- Mandatory MCP provenance: current active IDB session `80de0a67` for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.

## Evidence Sources Checked

- Current assignment source: `tools/leaser/Agents/Agent-B001/goal.md`.
- Project workflow/reference source: `ntk-b-agent-workflow`, `references/b-agent-research-and-implementation-workflow.md`, `references/supervisor-rule26-review-and-incorporation-standard.md`, and `by-structure.md`.
- Current target and support docs:
  - `by-memory/0x00541b30-0x00542265.IntegrateMacroDialog.md`
  - `by-class/IntegrateMacroDialog.md`
  - `by-file/MacroDialogs.md`
  - `by-class/IntegrateMacroEditControlPane.md`
  - `by-memory/0x0057f750-0x005807c5.MacroEditControlPanes.md`
  - `by-type/by-struct/MacroHotkeyRecord.md`
  - `by-type/by-vtable/MacroDialogFamilyVtables.md`
  - `by-memory/0x00542740-0x00542795.IntegrateMacroDialogScalarDeletingDestructor.md`
  - `by-memory/0x00542270-0x0054259f.TargetOptionDialog.md`
  - `by-memory/-ignored.md` for predecessor/successor padding context only.
- Prior related evidence checked as leads only:
  - `tools/leaser/Agents/Agent-A004/notes.md`
  - `executed-b-agent-research/B001/00023K-DialogPaneScalarDeletingDestructorIsland.md`
  - `by-project-structure/proposed-source-tree.md`
- Live MCP tools used against session `80de0a67`: `server_health`, `lookup_funcs`, `decompile`, `callees`, `xrefs_to`, `xref_query`, `get_bytes`, `insn_query`, `find_bytes`, `get_int`, `get_string`, and `tools/list`.
- Supplemental local read-only PE scan used `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe` only to check raw direct `call`/`jmp` and VA/RVA pointer encodings for the two raw helper entries. This was supplemental to live MCP xref/byte evidence and did not write files.
- MCP health was checked before and after target research. `server_health` command ids `11` and `65` both reported `status: ok`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, and strings cache ready.
- One intentionally broad `insn_query` command id `64` timed out while scanning the whole image for operands. This was not MCP unavailability: the previous MCP `find_bytes` command id `63` completed, follow-up `server_health` command id `65` was immediately `ok`, and the same reachability question was resolved through MCP xrefs plus a local read-only PE direct-branch scan.

## Current MCP Function And Range Evidence

`lookup_funcs` command id `21` confirms the current modeled function inventory inside and around `0x00541b30-0x00542265`:

| Address | Current MCP result |
| --- | --- |
| `0x00541b30` | `sub_541B30`, size `0x2f9`, constructor-shaped, ends at `0x00541e29`. |
| `0x00541e29` | Not a function; seven-byte padding begins. |
| `0x00541e30` | `sub_541E30`, size `0x1f`, non-deleting destructor helper. |
| `0x00541e4f` | Not a function; one-byte padding. |
| `0x00541e50` | `sub_541E50`, size `0x146`, draw handler. |
| `0x00541f96` | Not a function; ten-byte padding. |
| `0x00541fa0` | `sub_541FA0`, size `0x111`, button/action handler. |
| `0x005420b1` | Not a function; fifteen-byte padding. |
| `0x005420c0` | `sub_5420C0`, size `0x9`, key handler/forwarder. |
| `0x005420c9` | Not a function; seven-byte padding. |
| `0x005420d0` | `sub_5420D0`, size `0x2d`, clear macro edit fields. |
| `0x005420fd` | Not a function; three-byte padding. |
| `0x00542100` | Not a function; raw advance-page helper body starts. |
| `0x00542172` | Not a function; fourteen-byte padding. |
| `0x00542180` | Not a function; raw retreat-page helper body starts. |
| `0x005421e3` | Not a function; thirteen-byte padding. |
| `0x005421f0` | `sub_5421F0`, size `0x75`, refresh macro edit fields. |
| `0x00542265` | Not a function; successor padding before `TargetOptionDialog`. |
| `0x00542270` | `sub_542270`, successor `TargetOptionDialog` constructor, size `0x21e`. |

`get_bytes` command id `50` confirms all documented padding bytes are `0xcc`:

| Padding range | Bytes |
| --- | --- |
| `0x00541e29-0x00541e30` | 7 bytes `0xcc`. |
| `0x00541e4f-0x00541e50` | 1 byte `0xcc`. |
| `0x00541f96-0x00541fa0` | 10 bytes `0xcc`. |
| `0x005420b1-0x005420c0` | 15 bytes `0xcc`. |
| `0x005420c9-0x005420d0` | 7 bytes `0xcc`. |
| `0x005420fd-0x00542100` | 3 bytes `0xcc`. |
| `0x00542172-0x00542180` | 14 bytes `0xcc`. |
| `0x005421e3-0x005421f0` | 13 bytes `0xcc`. |
| `0x00542265-0x00542270` | 11 bytes `0xcc`, already represented in `by-memory/-ignored.md` with neighboring option/macro/target padding. |

The exact source-bearing child body ranges are therefore:

| Proposed child range | Role | Current route/C++ disposition |
| --- | --- | --- |
| `0x00541b30-0x00541e29` | `IntegrateMacroDialog::IntegrateMacroDialog` | Modeled function, constructor callers proven; exact child should route through [UID:00006L]. |
| `0x00541e30-0x00541e4f` | non-deleting destructor helper | Modeled destructor body; compiler/destructor support, no separate handwritten aggregate C++. |
| `0x00541e50-0x00541f96` | `OnDraw` | Vtable-routed draw handler; exact child should route through [UID:00006L]. |
| `0x00541fa0-0x005420b1` | `OnButtonClick` / action handler | Vtable-routed button handler; exact child should route through [UID:00006L]. |
| `0x005420c0-0x005420c9` | `HandleKeyInput` / key forwarder | Secondary-vtable routed; exact child should route through [UID:00006L]. |
| `0x005420d0-0x005420fd` | `ClearMacroEditFields` | Called by the action handler; exact child should route through [UID:00006L]. |
| `0x00542100-0x00542172` | `AdvanceMacroPageRaw` | Raw no-function helper, no inbound route found; exact child should record no-route status and stay blank C++ at split stage. |
| `0x00542180-0x005421e3` | `RetreatMacroPageRaw` | Raw no-function helper, no inbound route found; exact child should record no-route status and stay blank C++ at split stage. |
| `0x005421f0-0x00542265` | `RefreshMacroEditFields` | Modeled function, reached from action handler and raw helper tail-jumps; exact child should route through [UID:00006L]. |

## Positive Evidence

- Constructor reachability is live and direct. `xrefs_to` command id `60` reports exactly two code callers to `0x00541b30`: `0x005a7399` inside `sub_5A5BD0` and `0x005bd1a7` inside `sub_5BD000`. Existing class/file docs identify these as the UserPane key-event route and MenuVarietySelectPane menu route.
- IntegrateMacroDialog vtable routing is direct. `xrefs_to` command id `60` reports:
  - primary vtable base `0x00621130` refs from constructor `0x00541b73`, destructor helper `0x00541e30`, and scalar deleting destructor wrapper `0x00542746`;
  - secondary vtable base `0x00621190` refs from `0x00541b79`, `0x00541e36`, and `0x0054274c`;
  - tertiary vtable base `0x006211c0` refs from `0x00541b83`, `0x00541e40`, and `0x00542756`.
- `MacroDialogFamilyVtables.md` already records the critical IntegrateMacroDialog slots at same-or-greater detail: primary `0x00621130-0x0062118c` slot `+0x44 -> 0x00541e50` `OnDraw`, slot `+0x48 -> 0x00541fa0` `OnButtonClick`, and secondary `0x00621190-0x006211bc` slot `+0x08 -> 0x005420c0` `HandleKeyInput`.
- `xrefs_to` command id `60` reports the modeled virtual methods only through vtables where expected: `0x00541e50` from `0x00621174`, `0x00541fa0` from `0x00621178`, and `0x005420c0` from `0x00621198`.
- Constructor decompilation command id `31` shows:
  - DialogPane construction with caption literal at `aMa_5`.
  - Three IntegrateMacroDialog vtable stores at `this+0x00`, `this+0xa0`, and `this+0xa4`.
  - page count `this+0x26c = 3`, current page `this+0x270 = 0`, and first row child id/row base field `this+0x274 = 2`.
  - background/image resources `DLGMAC2.EPF`, `DLGMACRO.PAL`, and `DLGMACRO.EPF`.
  - one OK image button, ten `IntegrateMacroEditControlPane` row controls, and previous/next image buttons.
  - first-page `MacroHotkeyRecord` binding at `g_pConfig + 0x28f2ec + row * 0x108`.
- The constructor's image-button constructor arguments are frame/style ids, not dialog command ids: OK uses image id `14`, previous uses image id `18`, and next uses image id `19`. The dialog action command ids are assigned by insertion/order and consumed by `OnButtonClick`: `1` accept/save/close, `12` previous page, and `13` next page.
- Row control ids are `2..11`. Constructor creates ten row controls with rects `x=19..268`, `y=54 + 29 * row` through `y + 20`, and `RefreshMacroEditFields` fetches child ids `2..11`.
- The previous-page image button is initially disabled/hidden after construction. Constructor creates the button at rect `30,362,93,386`, then calls virtual slot `+0x50`, matching the first-page state.
- `OnButtonClick` decompilation command id `30` resolves the three action cases:
  - case `1`: calls `ClearMacroEditFields`, closes/removes the dialog via `0x0049eb90` and `0x00469180`, then calls `SaveUserSettings_50ABA0` only if `dword_67A764` is nonzero.
  - case `12`: clear current row editors, decrement `this+0x270` if it is positive, enable/reactivate next control id `13`, deactivate previous control id `12`, disable previous when new page is zero, then call `RefreshMacroEditFields`.
  - case `13`: clear current row editors, increment `this+0x270` if it is below `this+0x26c - 1`, enable/reactivate previous control id `12`, deactivate next control id `13`, disable next when new page is last, then call `RefreshMacroEditFields`.
- ImageButton virtual-slot semantics were rechecked live:
  - `get_int` command id `41` on `ImageButtonControlPane` vtable `0x00617dcc` maps slot `+0x4c` to `0x00495d10`, slot `+0x50` to `0x00495d80`, and slot `+0x58` to inherited `0x00494c10`.
  - `decompile` command id `44` shows `0x00495d10` sets byte `+0x101` to `1`, sets image state `+0x110` / decimal `272` to `0`, redraws, and is the enable/show-style operation for these buttons.
  - `decompile` command id `44` shows `0x00495d80` clears byte `+0x101`, sets image state `+0x110` / decimal `272` to `2`, redraws, and is the disable/hide-style operation.
  - `decompile` command id `44` shows `0x00494c10` clears inherited byte `+0x102` and redraws, so the action handler also deactivates the clicked direction button after a page change.
- `ClearMacroEditFields` decompilation command id `30` loops child ids `2..11` and calls virtual slot `+0x58` on each row control, matching `IntegrateMacroEditControlPane` deactivation/sync semantics.
- `RefreshMacroEditFields` decompilation command id `30` loops child ids `2..11`, calls `IntegrateMacroEditControlPane::SetMacroData` at `0x0057ff60`, then calls `0x0057ffa0` to refresh/display the row. The record address is `g_pConfig + 0x28f2ec + (currentPage * 10 + rowIndex) * 0x108`; IDA's decompiler renders this as `264 * (__int16)(v2 + 10 * this[312] - 2) + dword_67A7C8 + 2683628`.
- `xrefs_to` command id `60` reports `SetMacroData` has the expected target-side caller from `0x00542247` inside `RefreshMacroEditFields`.
- `MacroHotkeyRecord.md` already records this binding at same-or-greater detail: 30 rows, row base `g_pConfig + 0x28f2ec + index * 0x108`, ordinal at `+0x00`, state at `+0x04`, and payload at `+0x08`.
- `MacroHotkeyRecord.md` also already resolves state values at same-or-greater detail: state `1` / `.usr` `T` is text macro, state `2` / `.usr` `S` is spell-tab binding, and state `3` / `.usr` `I` is inventory/item-tab binding. The page correctly preserves the caveat that the generated runtime dispatch names around `0x005a3e30` and `0x005a4530` may be misleading.
- `OnDraw` decompilation command id `70` confirms it draws the instruction text:
  - `Spell : Select 'SPELLS' tab and press key.`
  - `Item  : Select 'ITEMS' tab and press key.`
  - raw UTF-16 bytes from `get_bytes` command id `72` decode the truncated IDA string at `0x00621734` as `Text  : Press ';' key`.
- `HandleKeyInput` decompilation command id `30` is a tiny forwarder to `0x0049e6e0`, matching the secondary vtable key hook route.
- `callees` command id `80` confirms the expected dependency shape: constructor calls DialogPane/control/resource helpers and `IntegrateMacroEditControlPane` constructor `0x0057fd10`; button handler calls `ClearMacroEditFields`, `RefreshMacroEditFields`, close/remove helpers, and `SaveUserSettings_50ABA0`; refresh calls `SetMacroData` and the row refresh helper; draw calls text/draw helpers only.
- The scalar deleting destructor support page [UID:00038B] is already correct for this class: exact wrapper `0x00542740-0x00542795`, direct class parent [UID:00006L], primary vtable `0x00621130`, adjustor thunk refs `0x005425cb`/`0x005425d6`, base teardown `0x0049d9f0`, and delete helper `0x004f4ac0`.
- The successor boundary is clean. `TargetOptionDialog.md` starts at `0x00542270` and already records `0x00542265-0x00542270` as preceding padding after IntegrateMacroDialog.

## Raw Page-Advance And Page-Retreat Helper Resolution

The prior blocker was the `0x005420fc-0x005421f0` internal span. Current evidence resolves it into padding plus two source-shaped raw helper bodies:

| Range | Current evidence |
| --- | --- |
| `0x005420fd-0x00542100` | Three `0xcc` bytes after `ClearMacroEditFields`. |
| `0x00542100-0x00542172` | Raw advance-page helper. `lookup_funcs` says not a function; `insn_query` command id `51` decodes a normal `thiscall`-shaped body that checks `currentPage < pageCount - 1`, increments `this+0x270`, updates controls `12` and `13`, disables next at the last page, and tail-jumps to `RefreshMacroEditFields`. |
| `0x00542172-0x00542180` | Fourteen `0xcc` bytes. |
| `0x00542180-0x005421e3` | Raw retreat-page helper. `lookup_funcs` says not a function; `insn_query` command id `51` decodes a normal `thiscall`-shaped body that checks `currentPage > 0`, decrements `this+0x270`, updates controls `13` and `12`, disables previous at page zero, and tail-jumps to `RefreshMacroEditFields`. |
| `0x005421e3-0x005421f0` | Thirteen `0xcc` bytes before modeled refresh. |

Reachability is negative in the current binary:

- `xrefs_to` command id `60` reports zero cross-references to `0x00542100`.
- `xrefs_to` command id `60` reports zero cross-references to `0x00542180`.
- `find_bytes` command id `63` reports zero absolute VA or RVA pointer encodings for `0x00542100` and `0x00542180`: patterns `00 21 54 00`, `80 21 54 00`, `00 21 14 00`, and `80 21 14 00` all have zero matches.
- The local read-only PE scan reports zero direct `E8`/`E9` rel32 calls or jumps to `0x00542100` and `0x00542180`, and zero absolute VA/RVA pointer encodings to either target.
- `xrefs_to 0x005421f0` command id `60` reports three inbound refs: one modeled call from `OnButtonClick` at `0x0054207b`, plus two raw tail-jumps from `0x0054216b` and `0x005421dc`. This proves the raw helpers fall through into the live refresh function but does not prove an inbound route to the raw helper entries themselves.

Conclusion: the two helpers are real source-shaped executable bodies in the IntegrateMacroDialog island, but no current route reaches their entries. Treat them as exact no-route raw helper children, not as proof that aggregate C++ is safe. Their bodies duplicate the active `OnButtonClick` previous/next page cases closely enough that they are most likely retained out-of-line page helper bodies or optimizer/source duplication, not unrelated code.

## Field, Command, And Row-Control Names

Current implementation-ready descriptive names:

| Offset / id | Source-facing role | Evidence |
| --- | --- | --- |
| `this+0x1fc` | dialog child-control list / child lookup table | Constructor adds controls through DialogPane helpers; `OnButtonClick`, clear, refresh, and raw helpers fetch controls through virtual slot `+0x10` on this pointer. |
| `this+0x26c` | `m_pageCount`, value `3` | Constructor writes `3`; `OnButtonClick` and raw advance compare against `pageCount - 1`. |
| `this+0x270` | `m_currentPage` / current macro page | Constructor writes `0`; button/raw helpers increment/decrement; refresh uses it for `page * 10`. |
| `this+0x274` | first macro row child id / row-control base, value `2` | Constructor writes `2`; refresh and clear hardcode/use child ids `2..11`. No current target read proves exact original field spelling, so keep this descriptive. |
| child id `1` | accept/save/close command | `OnButtonClick` case `1` clears rows, closes the dialog, removes it from the pane manager, and saves user settings when dirty. |
| child ids `2..11` | ten `IntegrateMacroEditControlPane` row controls | Constructor creates ten row controls; clear and refresh loop over ids `2..11`. |
| child id `12` | previous-page image button | Constructor places the left navigation button and disables it initially; case `12` handles previous-page action. |
| child id `13` | next-page image button | Constructor places the right navigation button; case `13` handles next-page action. |
| image id `14` | OK/accept image button style id | Passed to `ImageButtonControlPane` constructor, separate from dialog command id `1`. |
| image id `18` | previous image button style id | Passed to `ImageButtonControlPane` constructor, separate from dialog command id `12`. |
| image id `19` | next image button style id | Passed to `ImageButtonControlPane` constructor, separate from dialog command id `13`. |

Do not claim exact original field or method spellings beyond these descriptive names. The current IDB has no symbols/imports/source strings for the IntegrateMacroDialog members, and the helper names are reconstructed from behavior. This is not a remaining research blocker for the aggregate because the recommended action is non-emitting split/index plus exact child docs; it is a formal-C++ naming caveat for any later child-specific code pass.

## Ownership And Source Placement

Keep the accepted source family:

- [UID:0000KY] `MacroDialogs.cpp` remains the source file root. `proposed-source-tree.md` already places `MacroDialog`, `NewMacroDialog`, `IntegrateMacroDialog`, and the macro edit controls in `ui/dialogs/MacroDialogs.cpp`, separate from `OptionPane.cpp` and `TargetOptionDialog.cpp`.
- [UID:00006L] `IntegrateMacroDialog` should be the direct owner/emitter route for exact method children once they exist and receive validator-assigned UIDs. The class page already clears the gate at `86/90`.
- [UID:00006M] `IntegrateMacroEditControlPane` and [UID:0001IK] `MacroEditControlPanes` are dependencies/paired row-control owners, not owners of the dialog methods.
- [UID:0001V1] `MacroHotkeyRecord` owns the record layout and serializer/runtime table semantics; `IntegrateMacroDialog` edits/binds those records but does not own the profile-storage struct.
- [UID:0001Y1] `MacroDialogFamilyVtables` is source-declared/generated-binary support. It proves virtual routing but should not emit the method bodies.
- [UID:00038B] scalar deleting destructor support remains a separate exact child of the destructor-wrapper island and direct class parent.
- [UID:0001E2] `TargetOptionDialog` begins at `0x00542270`; the `0x00542265-0x00542270` padding is the only boundary relation.

Rejected alternatives:

1. `OptionPane.cpp` ownership: rejected. The adjacent `NewOptionPane` range ends at `0x00541b2b`, `0x00541b2b-0x00541b30` is padding, and the macro setup dialogs are documented as a separate MacroDialogs source family.
2. `TargetOptionDialog.cpp` ownership: rejected. The successor constructor starts at `0x00542270`; `0x00542265-0x00542270` is padding, and target-option control/config semantics are unrelated.
3. `IntegrateMacroEditControlPane` ownership for this target: rejected. The dialog constructs and controls row panes, but row-specific text/key mutation lives in the edit-control island; this target owns the dialog orchestration and page binding.
4. `RegistryConfig` / `ProfileStorage` ownership for this target: rejected. `MacroHotkeyRecord` and profile serializer docs own storage layout and `.usr` persistence; the dialog only binds/edit-controls those records.
5. Generic `ImageButtonControlPane`, `ControlPane`, or `DialogPane` ownership: rejected. Those are dependency/helper classes for button state, child lookup, drawing, and closure; the target behavior is class-specific IntegrateMacroDialog source.
6. No-owner/padding classification for the raw helpers: rejected for the bytes themselves. They are executable, source-shaped, and class-field-specific. The correct negative conclusion is no direct inbound route and no aggregate C++, not "padding".

## C++ Readiness Decision

Do not insert formal C++ into [UID:0001E1].

The current target is an aggregate over multiple method bodies, compiler/destructor support, raw no-route helper bodies, and eight internal padding ranges. It is not a clean single source-emission unit. The stale "final C++ remains blank below 95/95 gate" wording should be replaced, but the correct replacement is not aggregate C++. The correct source-quality action is:

- split exact method/helper children first;
- validate those new child docs so the validator assigns UIDs before adding UID links;
- convert [UID:0001E1] into a non-emitting split/container index;
- leave [UID:0001E1] formal C++ blank;
- leave initial child formal C++ blocks blank during the split callback with a split-stage/no-code rationale unless the supervisor explicitly asks for child-specific first-draft C++ in the callback.

No formal `RECONSTRUCTION_CPP CODE` content is proposed for [UID:0001E1] in this report. The exact formal aggregate block should remain empty between `BEGIN` and `END`.

Reasoning:

- `OnButtonClick` alone contains three command cases and calls `ClearMacroEditFields`, `RefreshMacroEditFields`, dialog close/remove helpers, and settings save. Emitting it inside an aggregate would duplicate or obscure exact child ownership.
- The raw page helpers have no direct route in the current binary. They should be documented as exact no-route raw helper children before any source-level decision about retained helper definitions is made.
- Exact original member/helper spellings remain unproven. Descriptive names are implementation-ready for documentation and later child-specific draft code, but not strong enough to justify a large aggregate formal block.
- Internal padding must be preserved as padding coverage, not silently hidden inside emitted source.

## Score And Metadata Recommendation

Recommended target metadata after accepted implementation:

| Field | Current | Recommended |
| --- | --- | --- |
| `COMPLETION` | `85` | `90` |
| `CONFIDENCE` | `88` | `91` |
| `CANONICAL_OWNER` | `0000KY` | `0000KY` |
| `RECONSTRUCTABLE` | `TRUE` | `FALSE` |
| `EMITTER_UIDS` | `0000KY` | blank |
| Formal C++ | blank | blank, with explicit non-emitting split/container rationale |

Recommended score rationale:

- Completion can rise because the previously open internal span is now resolved into exact raw helper/padding boundaries, the page/current-page/command-id/row-control model is implementation-ready, and support docs already back the MacroHotkeyRecord/vtable/destructor relationships.
- Confidence can rise because the current MCP session reconfirmed all function boundaries, padding bytes, vtable routes, caller/callee sets, raw helper disassembly, and no-route evidence.
- The score should remain below final-audit levels because exact original member/helper spellings are still descriptive, the raw helper entries remain no-route, and exact child C++ has not been accepted.
- `RECONSTRUCTABLE:FALSE` applies only to the broad parent after split. Exact child method pages can remain reconstructable under [UID:00006L] as appropriate.

## Required Implementation Changes If Accepted

1. Create exact child by-memory docs, without guessing UIDs:
   - `by-memory/0x00541b30-0x00541e29.IntegrateMacroDialogConstructor.md`
   - `by-memory/0x00541e30-0x00541e4f.IntegrateMacroDialogNonDeletingDestructor.md`
   - `by-memory/0x00541e50-0x00541f96.IntegrateMacroDialogOnDraw.md`
   - `by-memory/0x00541fa0-0x005420b1.IntegrateMacroDialogOnButtonClick.md`
   - `by-memory/0x005420c0-0x005420c9.IntegrateMacroDialogHandleKeyInput.md`
   - `by-memory/0x005420d0-0x005420fd.IntegrateMacroDialogClearMacroEditFields.md`
   - `by-memory/0x00542100-0x00542172.IntegrateMacroDialogAdvanceMacroPageRaw.md`
   - `by-memory/0x00542180-0x005421e3.IntegrateMacroDialogRetreatMacroPageRaw.md`
   - `by-memory/0x005421f0-0x00542265.IntegrateMacroDialogRefreshMacroEditFields.md`
2. For source-authored modeled method children, use [UID:00006L] as direct owner/emitter route and [UID:0000KY] as the source file route through the class. Keep formal C++ blank at split stage unless a later supervisor callback asks for child-specific formal code.
3. For raw helper children at `0x00542100` and `0x00542180`, record `lookup_funcs: Not a function`, zero `xrefs_to`, zero VA/RVA pointer hits, zero local PE direct rel32 hits, their decoded instruction bodies, and tail-jumps to `RefreshMacroEditFields`. Keep formal C++ blank at split stage because there is no proven inbound route.
4. Add or update internal padding coverage in the appropriate ignored/padding documentation, not in any `-coverage-report.md`:
   - `0x00541e29-0x00541e30`
   - `0x00541e4f-0x00541e50`
   - `0x00541f96-0x00541fa0`
   - `0x005420b1-0x005420c0`
   - `0x005420c9-0x005420d0`
   - `0x005420fd-0x00542100`
   - `0x00542172-0x00542180`
   - `0x005421e3-0x005421f0`
   The external `0x00541b2b-0x00541b30` and `0x00542265-0x00542270` padding rows already exist in `by-memory/-ignored.md`.
5. Validate the new child docs first. Only after validator-assigned UIDs exist, update [UID:0001E1] and support docs with UID links.
6. Convert [UID:0001E1] into a split/container index:
   - `COMPLETION:90`
   - `CONFIDENCE:91`
   - `CANONICAL_OWNER:0000KY`
   - `RECONSTRUCTABLE:FALSE`
   - blank `EMITTER_UIDS`
   - blank formal C++
   - updated item summary covering exact children, internal padding, raw helper no-route proof, command ids, fields, row binding, vtable route, scalar destructor support, and TargetOptionDialog boundary.
7. Update [UID:00006L] `by-class/IntegrateMacroDialog.md` after child UIDs exist:
   - replace broad method-map rows with exact child UID links;
   - add field evidence for `+0x1fc`, `+0x26c`, `+0x270`, and `+0x274`;
   - add command ids `1`, `12`, `13`, row ids `2..11`, and image ids `14`, `18`, `19`;
   - record raw helper no-route status as resolved evidence, not an open blocker.
8. Update [UID:0000KY] `by-file/MacroDialogs.md` only as needed:
   - keep MacroDialogs source placement;
   - add exact IntegrateMacroDialog split-child summary after child UIDs exist;
   - remove stale "final-C++ gate" phrasing if present.
9. Update [UID:00006M] `IntegrateMacroEditControlPane` and [UID:0001IK] `MacroEditControlPanes` only if a child UID cross-link is needed. Their row pointer/state/payload and `SetMacroData` evidence is already same-or-greater detail.
10. Update [UID:0001V1] `MacroHotkeyRecord` only if a child UID cross-link is needed. The layout, state values, and refresh binding are already same-or-greater detail.
11. Update [UID:0001Y1] `MacroDialogFamilyVtables` only if child UID links are added. The vtable slots are already same-or-greater detail.
12. Update [UID:00038B] `IntegrateMacroDialogScalarDeletingDestructor` only if a parent/sibling link needs to point to the new split children. Its owner/range evidence is already same-or-greater detail.
13. Do not edit generated/project-level/manual coverage/tool-state/IDA DB files. Run scoped validators for every new/changed by-* file from `source-3/project-documentation`.

## Support Doc Same-Or-Greater-Detail Notes

- `by-type/by-struct/MacroHotkeyRecord.md`: already same-or-greater detail for row base `g_pConfig + 0x28f2ec + index * 0x108`, state/payload fields, state values `T/S/I`, constructor/refresh binding, and runtime dispatch caveats. No mandatory edit unless adding child UID links.
- `by-class/IntegrateMacroEditControlPane.md`: already same-or-greater detail for `SetMacroData`, bound record pointer at row control `+0x108`, state `1` text display, payload `+0x08`, and source tab state writes. No mandatory edit unless adding child UID links.
- `by-memory/0x0057f750-0x005807c5.MacroEditControlPanes.md`: already same-or-greater detail for the IntegrateMacroEditControlPane method inventory, `SetMacroData`, `SyncEditControl`, and MacroHotkeyRecord state semantics. No mandatory edit unless adding child UID links.
- `by-type/by-vtable/MacroDialogFamilyVtables.md`: already same-or-greater detail for IntegrateMacroDialog vtable bases and slots. No mandatory edit unless adding child UID links.
- `by-memory/0x00542740-0x00542795.IntegrateMacroDialogScalarDeletingDestructor.md`: already same-or-greater detail for the scalar deleting destructor route. No mandatory edit unless adding child/sibling links.
- `by-project-structure/proposed-source-tree.md`: already same-or-greater detail for keeping MacroDialogs separate from OptionPane/TargetOptionDialog. No implementation edit needed for this assignment.
- `by-memory/0x00542270-0x0054259f.TargetOptionDialog.md`: already same-or-greater detail for the successor boundary. No implementation edit needed.

## Implementation Callback Results

- Implementation date: 2026-06-26.
- Required pre-edit MCP health recheck: JSON-RPC `server_health(database='80de0a67')` with request id `b001-health-throttled-0001e1` returned `status: ok`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, and strings cache ready.
- Child UIDs assigned by scoped validator before parent/support UID links were added:
  - [UID:00045D] `by-memory/0x00541b30-0x00541e29.IntegrateMacroDialogConstructor.md`
  - [UID:00045E] `by-memory/0x00541e30-0x00541e4f.IntegrateMacroDialogNonDeletingDestructor.md`
  - [UID:00045F] `by-memory/0x00541e50-0x00541f96.IntegrateMacroDialogOnDraw.md`
  - [UID:00045G] `by-memory/0x00541fa0-0x005420b1.IntegrateMacroDialogOnButtonClick.md`
  - [UID:00045H] `by-memory/0x005420c0-0x005420c9.IntegrateMacroDialogHandleKeyInput.md`
  - [UID:00045I] `by-memory/0x005420d0-0x005420fd.IntegrateMacroDialogClearMacroEditFields.md`
  - [UID:00045J] `by-memory/0x00542100-0x00542172.IntegrateMacroDialogAdvanceMacroPageRaw.md`
  - [UID:00045K] `by-memory/0x00542180-0x005421e3.IntegrateMacroDialogRetreatMacroPageRaw.md`
  - [UID:00045L] `by-memory/0x005421f0-0x00542265.IntegrateMacroDialogRefreshMacroEditFields.md`
- Parent [UID:0001E1] before/after metadata: `85/88`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000KY` -> `90/91`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`; owner remains `0000KY`, formal C++ remains blank.
- Lease proof: child creation/validation lease batch was released after validator work. Parent/support/padding leases for `by-memory/0x00541b30-0x00542265.IntegrateMacroDialog.md`, `by-class/IntegrateMacroDialog.md`, `by-file/MacroDialogs.md`, and `by-memory/-ignored.md` had already expired by release cleanup; final `current_leases.md` check reported no active leases.
- Validator side effects: scoped validators updated validator registry/autogen metadata and reported deferred generated refreshes; no generated/project-level/manual coverage file was manually edited. `by-memory/-ignored.md` still reports pre-existing unrelated registry warnings (`missing_ref_target:154`, `missing_ref_uid:418`) while returning `ok:1` for this file.

## Validator Proof

| Scope | Command id / timestamp | Result |
| --- | --- | --- |
| Initial child UID assignment | `000000003174`-`000000003182`, `2026-06-26T19:11:55-04:00` through `2026-06-26T19:12:07-04:00` | Assigned UIDs `00045D`-`00045L` before parent/support links. |
| Child metadata validation | `000000003183`, `000000003185`-`000000003191`, `2026-06-26T19:14:15-04:00` through `2026-06-26T19:14:28-04:00` | Each returned `ok:1`; modeled method children route through [UID:00006L], raw helper children keep blank emitter route. |
| Scalar destructor registry/support check | `000000003192`, `2026-06-26T19:14:47-04:00` | Returned `ok:1`; registered [UID:00038B] in validator state so destructor-child support links validate. No manual support-doc content edit. |
| Destructor child recheck | `000000003193`, `2026-06-26T19:14:58-04:00` | Returned `ok:1`; previous missing [UID:00038B] warning cleared. |
| Parent split/container | `000000003194`, `2026-06-26T19:20:16-04:00` | Returned `ok:1`; [UID:0001E1] now non-emitting split/container with child links. |
| Class support doc | `000000003195`, `2026-06-26T19:20:18-04:00` | Returned `ok:1`; [UID:00006L] now has child links, field/control map, and raw-helper no-route proof. |
| Source-file support doc final check | `000000003198`, `2026-06-26T19:20:48-04:00` | Returned `ok:1`; [UID:0000KY] has exact IntegrateMacroDialog split summary. |
| Padding/ignored doc final check | `000000003199`, `2026-06-26T19:20:57-04:00` | Returned `ok:1`; new IntegrateMacroDialog internal padding row validates, with unrelated pre-existing missing-ref warnings still present. |

## Implementation Tracking Checklist

- [x] Create the nine exact child by-memory docs listed above without guessing UIDs. Proof: created the nine exact files and validator assigned UIDs [UID:00045D] through [UID:00045L].
- [x] Run scoped validation so the validator assigns UIDs to the new child docs before adding UID links. Proof: commands `000000003174`-`000000003182` assigned UIDs before parent/class/file/padding docs were edited.
- [x] Convert [UID:0001E1] to `COMPLETION:90`, `CONFIDENCE:91`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank formal C++, and split/container wording. Proof: `by-memory/0x00541b30-0x00542265.IntegrateMacroDialog.md` header/body updated and validator command `000000003194` returned `ok:1`.
- [x] Add the exact internal padding coverage listed above to padding/ignored documentation, not any coverage report. Proof: `by-memory/-ignored.md` now has the IntegrateMacroDialog internal alignment padding row for all eight spans; validator command `000000003199` returned `ok:1`.
- [x] Update [UID:00006L] `IntegrateMacroDialog` with child links, command ids, field offsets, raw no-route proof, and row-control binding. Proof: `by-class/IntegrateMacroDialog.md` method map and field/control map updated; validator command `000000003195` returned `ok:1`.
- [x] Update [UID:0000KY] `MacroDialogs` with the exact IntegrateMacroDialog split summary after child UIDs exist. Proof: `by-file/MacroDialogs.md` now has `IntegrateMacroDialog Split Children`; validator command `000000003198` returned `ok:1`.
- [x] Add only necessary child UID cross-links to [UID:00006M], [UID:0001IK], [UID:0001V1], [UID:0001Y1], and [UID:00038B], or record same-or-greater-detail no-edit proof. Proof: no content edits were needed for [UID:00006M], [UID:0001IK], [UID:0001V1], or [UID:0001Y1] because the accepted report found same-or-greater row pointer/state/payload, SetMacroData, record layout/state, and vtable-slot detail already present. [UID:00038B] also had same-or-greater scalar destructor detail; only scoped validator command `000000003192` was run to register its existing UID mapping after a missing-registry warning.
- [x] Run scoped validators for every new/changed by-* file from `source-3/project-documentation`. Proof: command table above covers all new child files, changed parent/class/file/padding docs, and the validator-normalized [UID:00038B] support file.
- [x] Do not edit generated/project-level/manual coverage/tool-state/IDA DB files or any `-coverage-report.md`. Proof: no manual edits were made outside by-* docs and this B001 report; `by-memory/-coverage-report.md` and all other `-coverage-report.md` files were untouched. Validator-owned registry/generated side effects were tool-produced by scoped validation only.

Unchecked blockers: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0001E1-IntegrateMacroDialog-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B001/research/0001E1-IntegrateMacroDialog-source-quality.md","timestamp":"2026-06-26T19:28:09","uid":"0001E1"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
