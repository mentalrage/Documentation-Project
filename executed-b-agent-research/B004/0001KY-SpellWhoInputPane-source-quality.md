** TARGET-REPORT-UID:0001KY **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# Agent-B004 Report - [UID:0001KY] SpellWhoInputPane

Report path: `tools/leaser/Agents/Agent-B004/research/0001KY-SpellWhoInputPane-source-quality.md`

Target path: `by-memory/0x005ae2a0-0x005aeb1f.SpellWhoInputPane.md`

Assignment id: `B004-report-0001KY-spell-who-input-pane-source-quality-20260626`

Revision assignment id: `B004-revise-0001KY-spell-who-input-pane-source-quality-20260626`

Mode: report-only research/revision. I did not edit target/support `by-*` docs, generated/project-level files, validator/tool state, IDA DB files, or any `-coverage-report.md` file.

## Summary Recommendation

Convert [UID:0001KY] from an emitting reconstructable aggregate to a reviewed non-emitting split index:

```md
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000DX | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Keep the formal `RECONSTRUCTION_CPP CODE` block blank and add an explicit parent no-code proof. The range is not one original source function or one source declaration. It is an index over multiple exact `SpellWhoInputPane` source methods, one file-local helper, compiler switch-support data, padding, and non-contiguous destructor/thunk evidence. Parent-level C++ would either duplicate child source bodies or create a fake decompiler-shaped wrapper that the original source would not have contained.

Recommended direct owner remains [UID:0000DX] `SpellWhoInputPane`, because the aggregate is a class browsing/index page for the SpellWho target-selection pane. The source file route remains [UID:0000OH] `TargetSelectionInputPanes.cpp`. The file-local clear helper [UID:0001L3] remains directly owned by [UID:0000OH], not the class, and is listed as a support child inside this aggregate range.

The exact source-bearing homes are:

- [UID:0001KX] constructor `0x005ae2a0-0x005ae372`.
- [UID:0001KZ] non-deleting destructor `0x005ae380-0x005ae403`.
- [UID:0001L0] key handler `0x005ae410-0x005ae68a`.
- [UID:0001L1] pointer/mouse handler `0x005ae730-0x005aea53`.
- [UID:0001L2] object-list virtual `0x005aea60-0x005aeaf3`.
- [UID:0001L3] file-local `ClearSpellWhoTarget` / `ClearSavedSpellWhoTarget` helper `0x005aeb00-0x005aeb1f`.
- [UID:0001NK] scalar deleting destructor wrapper `0x005b8100-0x005b81c4` remains support evidence with ordinary destructor source belonging to [UID:0001KZ].
- [UID:0001NA] adjustor thunks remain `RECONSTRUCTABLE:FALSE` compiler output.

Revision resolution: those child homes are now implementation-ready in this report. [UID:0001KX], [UID:0001KZ], [UID:0001L0], [UID:0001L1], [UID:0001L2], and [UID:0001L3] should receive exact formal `RECONSTRUCTION_CPP CODE` content listed below. [UID:0001NK] should receive explicit no-source-C++ scalar-wrapper wording. [UID:0001NA] is already an adequate false/non-emitting compiler-thunk page and needs no metadata, C++, or support-wording change.

## Current Target State

Expected live target metadata from `goal.md` was verified in the source page:

```md
COMPLETION:85
CONFIDENCE:88
CANONICAL_OWNER:0000DX
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000DX
```

The body already describes the page as an aggregate/index, but the metadata still routes it as an emitting reconstructable item. That is the main defect. Its formal C++ block is blank, and generated output currently emits an empty marker for [UID:0001KY].

Read-only generated state is stale compared with the live `by-*` metadata: `auto-generated/NexusTK/ui/dialogs/TargetSelectionInputPanes.cpp` has header `validator-command-id: 000000003154`, `validator-refreshed-at: 2026-06-26T18:11:12-04:00`, but still shows [UID:0001KY] as `Completion:80 | Confidence:84` and [UID:0000DX] as `86/80` empty emitter markers. Do not edit generated output manually; implementation validators should refresh generated state through the validator.

## Evidence Checked

Instructions and workflow:

- `tools/leaser/Agents/Agent-B004/goal.md`
- `tools/leaser/Agents/Agent-B004/notes.md`
- `.codex/skills/ntk-b-agent-workflow/SKILL.md`
- `.codex/skills/ntk-b-agent-workflow/references/b-agent-research-and-implementation-workflow.md`
- `.codex/skills/ntk-b-agent-workflow/references/supervisor-rule26-review-and-incorporation-standard.md`
- `by-structure.md`

Target and support docs:

- [UID:0001KY] `by-memory/0x005ae2a0-0x005aeb1f.SpellWhoInputPane.md`
- [UID:0000DX] `by-class/SpellWhoInputPane.md`
- [UID:0000OH] `by-file/TargetSelectionInputPanes.md`
- [UID:0000O0] `by-file/SpellInputPanes.md`
- [UID:0001KX] constructor page
- [UID:0001KZ] non-deleting destructor page
- [UID:0001L0] key handler page
- [UID:0001L1] pointer handler page
- [UID:0001L2] object-list virtual page
- [UID:0001L3] saved-target clear helper page
- [UID:0001NA] adjustor thunk page
- [UID:0001NK] scalar deleting destructor page
- [UID:0002AB] saved target global cluster page
- [UID:0001L9] `SendTargetedActionPacket`
- [UID:0001L4] `ItemWhoInputPane` index page as accepted non-emitting sibling precedent

Executed B-agent lead reports, rechecked against live IDA before use:

- B004 `00036R-TargetObjectWithKeyboardPaneObjectListHelper-source-quality.md`
- B013 `0001L4-ItemWhoInputPane-source-quality.md`
- B007 `0002RI-SpellInventoryPaneLegacyCoreAndHelpers-source-quality.md`
- B008 `0002RK-SpellInventoryPane2CoreAndHelpers-source-quality.md`
- B010 `0003UC-LivingObjectPaneUseCommandSlotDispatch-source-quality.md`

IDA MCP session:

- Endpoint: `http://127.0.0.1:13337/mcp`
- `initialize` / `tools/list` / `idb_list`: `B004-0001KY-init`, `B004-0001KY-tools-list`, `B004-0001KY-idb-list`, timestamp `2026-06-26T18:57:57.9648194-04:00`
- Active session: `80de0a67`, backend `worker`, PID/worker PID `26892`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`
- `server_health`: `B004-0001KY-health`, timestamp `2026-06-26T18:58:06.5257955-04:00`, status `ok`, auto-analysis ready, Hex-Rays ready, strings cache ready
- A broad `xrefs_to` batch `B004-0001KY-xrefs-functions` timed out at `2026-06-26T19:00:40.4906534-04:00`; immediate `server_health` retry `B004-0001KY-health-after-xref-timeout` at `2026-06-26T19:01:52.6085234-04:00` returned `ok`, and the narrowed `xref_query` replacement succeeded. This was a heavy-request timeout, not MCP unavailability.

Live IDA MCP requests used:

- `B004-0001KY-lookup-boundaries`, `lookup_funcs`, timestamp `2026-06-26T19:00:12.5303411-04:00`
- `B004-0001KY-bytes-boundaries`, `get_bytes`, timestamp `2026-06-26T19:00:12.9897682-04:00`
- `B004-0001KY-xrefs-global`, `xref_query`, timestamp `2026-06-26T19:01:30.7279214-04:00`
- `B004-0001KY-callees`, `callees`, timestamp `2026-06-26T19:01:32.2373901-04:00`
- `B004-0001KY-xrefs-starts-narrow`, `xref_query`, timestamp `2026-06-26T19:01:53.1486477-04:00`
- `B004-0001KY-decompile-constructor`, `decompile`, timestamp `2026-06-26T19:02:11.0240309-04:00`
- `B004-0001KY-decompile-key`, `decompile`, timestamp `2026-06-26T19:02:11.5075789-04:00`
- `B004-0001KY-decompile-pointer`, `decompile`, timestamp `2026-06-26T19:02:11.7245861-04:00`
- `B004-0001KY-decompile-objectlist-clear`, `analyze_batch`, timestamp `2026-06-26T19:02:11.8873341-04:00`
- `B004-0001KY-decompile-destructors`, `analyze_batch`, timestamp `2026-06-26T19:02:25.9982189-04:00`
- `B004-0001KY-disasm-thunks`, `disasm`, timestamp `2026-06-26T19:02:26.7374012-04:00`
- `B004-0001KY-disasm-thunk2`, `disasm`, timestamp `2026-06-26T19:02:26.8507716-04:00`
- `B004-0001KY-vtable-ints`, `get_int`, timestamp `2026-06-26T19:02:40.9420536-04:00`
- `B004-0001KY-vtable-bytes`, `get_bytes`, timestamp `2026-06-26T19:02:41.3963792-04:00`

Revision MCP requests used after supervisor rejection:

- `B004-0001KY-resume-idb-list`, `idb_list`, timestamp `2026-06-26T19:11:22.7164686-04:00`, active session `80de0a67`, worker PID `26892`.
- `B004-0001KY-resume-health-db`, `server_health` with `database='80de0a67'`, timestamp `2026-06-26T19:11:36.2352085-04:00`, status `ok`, auto-analysis ready, Hex-Rays ready, strings cache ready.
- `B004-0001KY-revision-idb-list`, `idb_list`, timestamp `2026-06-26T19:15:47.5529573-04:00`, active session still `80de0a67`.
- `B004-0001KY-revision-health-db`, `server_health`, timestamp `2026-06-26T19:15:47.9969355-04:00`, status `ok`.
- `B004-0001KY-revision-lookup-children`, `lookup_funcs`, timestamp `2026-06-26T19:15:48.0329295-04:00`, reconfirmed the six source child starts, scalar/thunk starts, `0x005aeb20` as `Not a function`, and `0x005aec60` as the ItemWho constructor start.
- `B004-0001KY-revision-decompile-children` and `B004-0001KY-revision-disasm-successor` used the older plural `addrs` shape and returned `Invalid params: missing required parameters: ['addr']`; this was a request-shape/schema issue, not MCP unavailability.
- Singular-`addr` retry succeeded for `B004-0001KY-revision-decompile-ctor`, `-dtor`, `-key`, `-mouse`, `-objlist`, `-clear`, and `-scalar` at `2026-06-26T19:16:06-04:00` through `2026-06-26T19:16:07-04:00`.
- `B004-0001KY-revision-disasm-successor-db`, `disasm`, timestamp `2026-06-26T19:16:07.4028741-04:00`, showed executable-looking bytes at `0x005aeb20` outside any modeled IDA function, beginning `push ebp; mov ebp, esp; mov ecx, dword_67A764; ... push dword ptr unk_69BF20; call sub_506970`.

## Boundary And Split Reanalysis

Live `lookup_funcs` confirms the modeled children and negative function starts:

| Range / address | Live IDA result | Recommendation |
| --- | --- | --- |
| `0x005ae2a0` | `sub_5AE2A0`, size `0xd2` | constructor child [UID:0001KX] |
| `0x005ae372` | not a function | padding start |
| `0x005ae380` | `sub_5AE380`, size `0x83` | non-deleting destructor child [UID:0001KZ] |
| `0x005ae403` | not a function | padding start |
| `0x005ae410` | `sub_5AE410`, size `0x27a` | key handler child [UID:0001L0] |
| `0x005ae68a`, `0x005ae690`, `0x005ae700` | not functions | key-handler switch/jump-table support plus trailing padding |
| `0x005ae730` | `sub_5AE730`, size `0x323` | pointer/mouse handler child [UID:0001L1] |
| `0x005aea53` | not a function | padding start |
| `0x005aea60` | `sub_5AEA60`, size `0x93` | object-list virtual child [UID:0001L2] |
| `0x005aeaf3` | not a function | padding start |
| `0x005aeb00` | `sub_5AEB00`, size `0x1f` | file-local clear helper [UID:0001L3] |
| `0x005aeb1f` | not a function | exact target end after helper |
| `0x005aeb20` | not an IDA function, but bytes begin `55 8b ec ...` after one `0xcc` | successor raw target-selection island outside [UID:0001KY]; no exact current UID exists |

Live bytes confirm:

- `0x005ae372-0x005ae380`: fourteen `0xcc` bytes.
- `0x005ae403-0x005ae410`: thirteen `0xcc` bytes.
- `0x005ae68a-0x005ae730`: switch-support bytes beginning `66 90 64 e4 5a 00 ...` and ending with seven `0xcc` bytes before the pointer handler.
- `0x005aea53-0x005aea60`: thirteen `0xcc` bytes.
- `0x005aeaf3-0x005aeb00`: thirteen `0xcc` bytes.
- `0x005aeb1f`: one `0xcc`; bytes at `0x005aeb20` then begin executable-looking successor code. The aggregate half-open end remains `0x005aeb1f`.
- `0x005b81c4-0x005b81d0`: twelve `0xcc` bytes after the scalar deleting destructor.

This means [UID:0001KY] is structurally equivalent to the accepted [UID:0001L4] `ItemWhoInputPane` non-emitting index, except [UID:0001KY] currently includes the file-local `0x005aeb00` clear helper inside its half-open range. That mixed class/file-helper ownership is another reason not to emit parent-level C++.

Successor-span repair recommendation: `0x005aeb20` is not covered by [UID:0001KY] because the parent ends at the one-byte `0xcc` after [UID:0001L3]. Current `rg` over `by-memory`, `by-class`, `by-file`, executed reports, archived reports, and this report found no exact by-memory page or UID for `0x005aeb20`. Live `lookup_funcs` confirms `0x005aeb20` is not an IDA function and `0x005aec60` starts the existing ItemWho constructor [UID:0002S1]. Live disassembly shows `0x005aeb20` reads `dword_67A764`, pushes `s_spellWhoTargetId` / `unk_69BF20`, and calls `MapPane::FindObjectPaneById`-style lookup. Because this raw island is outside [UID:0001KY]'s half-open range, it does not change the parent reclassification, child C++ disposition, or [UID:0001KY] metadata. It should be assigned as a separate raw-helper investigation/split target, proposed range `0x005aeb20-0x005aec60` and working title `SpellWhoTargetSelectionRawHelperIsland`, before any C++ is emitted for that successor island.

## Live Xref, Vtable, And Data Evidence

Constructor reachability:

- `xref_query` to `0x005ae2a0` reports three code callers:
  - `0x0057cade` in `sub_57C9B0`
  - `0x0057e3f8` in `sub_57E2D0`
  - `0x0057f109` in `sub_57F030`
- Executed B007/B008 spell inventory reports show these are spell-inventory allocation/dispatch paths. They prove construction/use, not source ownership by `SpellInputPanes.cpp`.

Virtual and helper reachability:

- `0x005ae410` has one data xref from `0x0062f268`.
- `0x005ae730` has one data xref from `0x0062f264`.
- `0x005aea60` has one data xref from `0x0062f270`.
- `0x005aeb00` has four code xrefs: `0x005ae48e`, `0x005ae4f9`, `0x005ae90b`, and `0x005ae994` from the key and pointer handlers.
- `0x005ae380` has no direct static xrefs.

Vtable bytes and values:

- Primary table `0x0062f210` begins with `0x005b8100` scalar deleting destructor.
- Secondary table `0x0062f260` begins with `0x005b78fc`, then `0x005ae730`, `0x005ae410`, inherited `0x004f2580`, `0x005aea60`, and `0x00544df0`.
- Tertiary table `0x0062f290` begins with `0x005b7907`.
- `xref_query` to `0x0062f210`, `0x0062f260`, and `0x0062f290` shows stores from `0x005a4530`, constructor `0x005ae2a0`, destructor `0x005ae380`, and scalar destructor `0x005b8100`. This confirms the out-of-line class bodies and the inlined LivingObject command-slot construction path share the same vtable set.

Saved-target global:

- `xref_query` to `0x0069bf20` reports 32 refs. SpellWho-local refs are:
  - constructor `0x005ae319` and `0x005ae357`;
  - key handler `0x005ae46e`, `0x005ae4de`, `0x005ae51b`, `0x005ae558`, `0x005ae5bc`, `0x005ae632`, `0x005ae679`;
  - pointer handler `0x005ae79e`, `0x005ae7d9`, `0x005ae85d`, `0x005ae8e5`;
  - object-list virtual `0x005aea9b` and `0x005aead6`;
  - clear helper `0x005aeb00`;
  - unmodeled successor bytes at `0x005aeb2b` through `0x005aec58`, outside this aggregate;
  - ItemWho constructor/destructor/scalar-wrapper refs that copy/share SpellWho target state.
- The correct source-facing name for `0x0069bf20` is `s_spellWhoTargetId` / `s_spellWhoSavedTargetId`, matching [UID:0002AB] and the accepted ItemWho report.

## Behavior And Source-Quality Names

### Constructor [UID:0001KX]

Live decompilation:

- Calls `sub_4F1C00(this, 0)` at `0x005ae2cd`, the LineInputPane base constructor path.
- Stores vtables `0x0062f210`, `0x0062f260`, and `0x0062f290`.
- Computes prompt data from `dword_67A748 + 0x13a794 + 0x148 * spellIndex`.
- Stores the byte argument at full object `+0x108`.
- Resolves `s_spellWhoTargetId` through `g_activeMapPane` / `sub_506970`.
- Accepts the saved target only if the object exists, object byte `+0xf8 == 3`, and byte `+0x1d0 == 0`.
- Falls back to the local-player object at `dword_67A748`, highlights it, and writes its object id from `+0xfc` to `s_spellWhoTargetId`.

Best source-facing names:

- `SpellWhoInputPane::SpellWhoInputPane(unsigned char spellIndex)` or `spellSlot`; `spellIndex` is preferred for docs because the value indexes the spell table and is stored at `m_spellIndex`.
- `m_spellIndex` for full object `+0x108`.
- `s_spellWhoTargetId` for `0x0069bf20`.
- `g_activeMapPane->FindObjectPaneById(...)` for `0x00506970`.
- `LivingObjectPane::SetTargetHighlight(bool)` for `0x0053b1b0`.

Rejected alternatives:

- `SpellInputPanes.cpp` as direct owner: constructor call sites come from spell inventory, but behavior is target selection and uses target-selection shared state.
- `SpellManager` / `g_pSpellMan` naming for `dword_67A748`: B010 and current support docs reject this; it is broad local-player/UserPane state.
- Raw `this+0x108`, `unk_69BF20`, and `sub_` names in final source-facing docs.

### Destructor And Scalar Wrapper [UID:0001KZ] / [UID:0001NK]

Live decompilation shows both the non-deleting destructor and scalar deleting wrapper restore the same three vtable views, branch on `byte_66DA97`, look up GeneralPurposePanel child `3` through `0x004b85f0`, clear either [UID:0001IJ] `ItemWhoInputPaneState::SetInputModeFlag(false)` or [UID:0001II] `SpellInputPaneState::SetInputModeFlag(false)`, and call `LineInputPane` base cleanup `0x004f2010`.

The non-deleting destructor is the source destructor home. The scalar deleting destructor remains useful binary evidence for delete flags, operator delete, vtable/thunk refs, and object size `0x10c`, but formal ordinary source C++ should not be duplicated there.

### Key Handler [UID:0001L0]

Live decompilation confirms:

- `event+0x08` is the key byte, narrowed through `std::ctype<char>::do_narrow`.
- `event+0x10a` is the modifier/IME flags byte; low bits `0x03` gate the switch body, and bit `0x04` selects the alternate target traversal option pair.
- `event+0x04` is the key event kind/state; handled Enter/Escape/self/navigation paths require value `8`.
- Enter (`13`) resolves `s_spellWhoTargetId`, clears highlight through `0x005aeb00`, reads object id `+0xfc`, obtains two target words through `0x005374d0`, sends through `SendTargetedActionPacket` at `0x005af4f0`, and forwards/closes through `LineInputPane` path `0x004f25a0`.
- Escape (`27`) clears the current target when present and forwards/closes.
- Self-target key (`-111`) switches to the local player.
- Previous/up keys `104`, `107`, `-128`, and `-127`, and next/down keys `106`, `108`, `-126`, and `-125`, use config option pairs at `g_pConfig+0x2911dc` or `g_pConfig+0x2911de` to derive target traversal direction `-1`, `0`, or `1`.
- Traversal calls `MapPane::FindPreviousSelectableObject` style helper `0x00506c20` or `MapPane::FindNextSelectableObject` style helper `0x00506c70`, updates highlight, and writes the new id or zero to `s_spellWhoTargetId`.

Best source-facing names:

- `bool SpellWhoInputPane::OnKeyEvent(KeyEvent *event)` is the recommended method name. The current `OnKeyNavigationInput` page title is descriptive but less consistent with accepted sibling naming.
- `event->kind`, `event->key`, and `event->modifierFlags` for offsets `+0x04`, `+0x08`, and `+0x10a`.
- `m_spellIndex` for the packet action byte read at adjusted `this+0x68`.
- `g_pConfig->targetTraversalOrder` / `g_pConfig->alternateTargetTraversalOrder` as descriptive names for the two-byte option pairs. Exact original config field names remain not symbol-proven, but the binary role is resolved.

Rejected alternatives:

- Raw key handler "input" names that omit the vtable event route.
- Treating config pair names as unresolved blockers. Their source-facing names can be descriptive; no behavior remains unknown.
- PacketBuffer or Socket ownership of the handler because `SendTargetedActionPacket` is a dependency only.

### Pointer / Mouse Handler [UID:0001L1]

Live decompilation confirms:

- `event+0x04` is the mouse subtype: `1` target hit-test/selection, `2` confirm/click; other subtypes return false.
- `event+0x08` and `event+0x0c` are coordinates.
- The method obtains pane origin through adjusted `this-0xa0`, map origin through `g_activeMapPane`, and uses rectangle/hit-test helpers `0x004b8e00`, `0x004b7e80`, and `0x00506ce0`.
- Subtype `2` confirms the current saved target only when the point is inside the map rectangle and the saved target resolves.
- Subtype `1` hit-tests a new target, clears/highlights old/new targets, writes `s_spellWhoTargetId`, and gates immediate send/close through config byte `g_pConfig+0x28de5a`.
- Send paths clear local pending state at `dword_67A748+0x210`, call `SendTargetedActionPacket`, and close/defer removal through `0x00469180`.

Best source-facing names:

- `bool SpellWhoInputPane::OnMouseEvent(MouseEvent *event)` is preferred over `OnPointerSelectionInput` for source consistency.
- `event->subtype`, `event->x`, `event->y`.
- `g_pConfig->targetClickPolicy` / `g_pConfig->doubleClick` for `+0x28de5a`, matching ItemWho support docs. Do not conflate this with the separate target-save/share-target byte `+0x28de6c`.

### Object-List Virtual [UID:0001L2]

Live `analyze_batch` confirms:

- Prototype decompiler shape is `char __stdcall(int)` because the hidden `this` register is unused, but the vtable data ref at `0x0062f270` proves this is a class virtual.
- Reads payload pointer from `event+0x0c`.
- Requires leading underscore byte `0x5f`.
- Reads count byte at `payload+1` through runtime character-traits `0x00575470`; source should use `payload[1]`, not a project helper call.
- Starts object id scanning at payload offset `2`.
- Decodes each four-byte id through `0x005754c0`, documented as `PacketBufferReadUInt32BE`.
- Falls back only when a decoded id equals `s_spellWhoTargetId`; if the loop exhausts without equality, it returns false with no state change.
- On equality, resolves the old target through `g_activeMapPane->FindObjectPaneById`, switches `s_spellWhoTargetId` to the local player's object id, clears old highlight, highlights the local player, and returns false.

Recommended source-facing signature: `bool SpellWhoInputPane::OnObjectListMessage(const PacketEvent *event)`. This keeps the TargetObject/ItemWho object-list virtual role while making the packet message source explicit; do not leave alternate object-list method names in the implementation.

The current SpellWho page already describes equality/fallback mostly correctly. Keep the neutral payload wording used by [UID:00036R]: do not say "no longer appears from active list" unless a protocol dispatch pass proves the upstream message is an active-object list. The binary only proves fallback when the payload contains the current saved id.

### Clear Helper [UID:0001L3]

Live decompilation and xrefs:

- No receiver argument; decompiler prototype `char sub_5AEB00()`.
- Reads `s_spellWhoTargetId`, resolves through `g_activeMapPane->FindObjectPaneById`, and calls `LivingObjectPane::SetTargetHighlight(false)` only when lookup succeeds.
- Direct callers are key Enter, key Escape, pointer changed-target send, and pointer same/current-target send paths.

Recommended source-facing name: `ClearSpellWhoTarget()` or `ClearSavedSpellWhoTarget()`. Existing `DeactivateSavedSpellWhoTarget` is descriptive and acceptable as a historical alias, but `ClearSpellWhoTarget` matches the accepted `ClearItemWhoTarget` and target-selection helper style better.

Keep canonical owner [UID:0000OH] because the helper is file-local and receiver-free, even though it is inside the [UID:0001KY] aggregate range and only serves SpellWho flows.

### Adjustor Thunks [UID:0001NA]

Live disassembly:

- `0x005b78fc`: `sub ecx, 0A0h; jmp sub_5B8100`
- `0x005b7907`: `sub ecx, 0A4h; jmp sub_5B8100`

Live xrefs:

- `0x005b78fc` has data ref from `0x0062f260`.
- `0x005b7907` has data ref from `0x0062f290`.

These are compiler-generated destructor adjustor thunks and should remain [UID:0001NA] `RECONSTRUCTABLE:FALSE`, `CANONICAL_OWNER:NONE`, blank emitter, blank C++.

## Source Placement And Rejected Alternatives

Accepted source route:

- Direct class owner for the aggregate index and class methods: [UID:0000DX] `SpellWhoInputPane`.
- Source file route: [UID:0000OH] `TargetSelectionInputPanes.cpp`.
- File-local helper owner for [UID:0001L3] and packet helper dependencies: [UID:0000OH].

Rejected alternatives:

- [UID:0000O0] `SpellInputPanes.cpp` as direct owner: rejected. Spell inventory and command-slot code construct or inline SpellWho setup, but the class behavior is target selection: saved target globals, active map lookup, object highlight toggles, object-list payload handling, mouse hit-test, and target traversal.
- `SpellInventoryPane.cpp`: rejected. The B007/B008 reports show dispatcher/allocation call sites and pending-input state, not ownership of target-selection virtual methods.
- `LivingObjectPane.cpp`: rejected. B010 shows `0x005a4530` can inline SpellWho construction for command-slot dispatch, but the dispatcher remains a caller/dependency. `SpellWhoInputPane`, `s_spellWhoTargetId`, and `SendTargetedActionPacket` remain target-selection dependencies, not the dispatcher's source body.
- `MapPane`, `LivingObjectPane`, PacketBuffer, Socket/ProtocolSend: rejected as direct owners. They provide object lookup, highlight, payload decode, and packet send helpers only.
- Parent aggregate as emitter: rejected. It mixes multiple source bodies, a file-local helper, switch-support data, padding, and compiler-generated non-contiguous destructor/thunk evidence.

## Score And Metadata Rationale

Recommended target metadata:

| Field | Before | After | Rationale |
| --- | ---: | ---: | --- |
| `COMPLETION` | `85` | `88` | Current pass resolves the parent-vs-child emission defect, exact range/split map, vtable route, saved-target names, event field roles, object-list payload semantics, file helper ownership, thunk/scalar-wrapper disposition, and generated empty-emitter issue. |
| `CONFIDENCE` | `88` | `90` | Live IDA confirms exact child starts, negative starts, padding/switch bytes, xrefs, vtable slots, constructor callers, saved-target refs, callees, and decompiled behavior. Confidence stays below final-audit because exact original event/config/helper spellings are inferred source-facing names rather than symbol-proven. |
| `CANONICAL_OWNER` | `0000DX` | `0000DX` | The aggregate is a SpellWho class index. |
| `RECONSTRUCTABLE` | `TRUE` | `FALSE` | The aggregate itself is not a source-level object/body. Exact children carry source reconstruction. |
| `EMITTER_UIDS` | `0000DX` | blank | Parent should not emit empty markers or duplicate child source. |

## Formal C++ Disposition

### Parent [UID:0001KY]

Formal parent C++ should remain blank. No `RECONSTRUCTION_CPP CODE` block is proposed for [UID:0001KY].

Exact no-code proof:

- The parent range contains separate source bodies with separate starts and return sites.
- It contains compiler padding at `0x005ae372-0x005ae380`, `0x005ae403-0x005ae410`, `0x005aea53-0x005aea60`, `0x005aeaf3-0x005aeb00`, and one byte at `0x005aeb1f`.
- It contains key-handler switch/jump-table support at `0x005ae68a-0x005ae730`, not human-authored standalone source.
- It includes a file-local receiver-free helper [UID:0001L3] directly owned by [UID:0000OH], not by the class.
- Related destructor/thunk evidence is non-contiguous and partly compiler-generated.
- Exact child pages are the correct formal C++ homes. Parent C++ would be a synthetic wrapper over unrelated functions and binary support data.

### Child C++ Readiness

The parent false/non-emitting recommendation is only safe if exact source-bearing children carry the source burden. This revision resolves that burden now:

- [UID:0001KX], [UID:0001KZ], [UID:0001L0], [UID:0001L1], [UID:0001L2], and [UID:0001L3] should be updated to `COMPLETION:88`, `CONFIDENCE:90`, with existing owner/emitter routes preserved, and the exact formal `RECONSTRUCTION_CPP CODE` content below inserted.
- [UID:0001NK] should be updated to `COMPLETION:88`, `CONFIDENCE:90`, keep owner/emitter [UID:0000DX], keep blank formal C++, and replace stale final-threshold wording with explicit scalar-wrapper no-source-C++ policy. Ordinary destructor source belongs on [UID:0001KZ].
- [UID:0001NA] already has the correct implementation-ready disposition: `RECONSTRUCTABLE:FALSE`, `CANONICAL_OWNER:NONE`, blank emitter, blank C++, and concrete thunk proof. No C++ or metadata edit is required.

#### [UID:0001KX] Constructor Exact Formal C++

Insert exactly this content into [UID:0001KX]'s formal `RECONSTRUCTION_CPP CODE` block:

```cpp
SpellWhoInputPane::SpellWhoInputPane(unsigned char spellIndex)
    : LineInputPane(NULL),
      m_spellIndex(spellIndex)
{
    SetPromptText(g_pUserPane->GetSpellPromptText(spellIndex));

    LivingObjectPane *target =
        g_activeMapPane->FindObjectPaneById(s_spellWhoTargetId);
    if (target == NULL ||
        target->ObjectType() != kLivingObjectType ||
        target->IsTargetingDisabled()) {
        target = g_pUserPane->GetLocalPlayerObject();
    }

    target->SetTargetHighlight(true);
    s_spellWhoTargetId = target->ObjectId();
}
```

Evidence and source-shape notes: `g_pUserPane->GetSpellPromptText(spellIndex)` is the source-facing wrapper for the binary address calculation `dword_67A748 + 0x13a794 + 0x148 * spellIndex` passed to `LineInputPane::SetPromptText`. `m_spellIndex` is full-object `+0x108`. `ObjectType() == kLivingObjectType` and `IsTargetingDisabled()` represent the `+0xf8 == 3` and `+0x1d0 == 0` validity gates.

#### [UID:0001KZ] Destructor Exact Formal C++

Insert exactly this content into [UID:0001KZ]'s formal `RECONSTRUCTION_CPP CODE` block:

```cpp
SpellWhoInputPane::~SpellWhoInputPane()
{
    if (g_targetInputStateUsesItemWho) {
        ItemWhoInputPaneState *state =
            static_cast<ItemWhoInputPaneState *>(g_pGeneralPurposePanel->GetChildPaneByIndex(3));
        if (state != NULL)
            state->SetInputModeFlag(false);
    } else {
        SpellInputPaneState *state =
            static_cast<SpellInputPaneState *>(g_pGeneralPurposePanel->GetChildPaneByIndex(3));
        if (state != NULL)
            state->SetInputModeFlag(false);
    }
}
```

Evidence and source-shape notes: `g_targetInputStateUsesItemWho` is the source-facing name for `byte_66DA97 == 1`; `g_pGeneralPurposePanel->GetChildPaneByIndex(3)` is the state slot lookup through `dword_67A874` / `sub_4B85F0`; the two state calls are [UID:0001IJ] `ItemWhoInputPaneState::SetInputModeFlag(false)` and [UID:0001II] `SpellInputPaneState::SetInputModeFlag(false)`. The `LineInputPane` base cleanup call is compiler-emitted destructor chaining and does not need an explicit source statement in the ordinary destructor body.

#### [UID:0001L0] Key Handler Exact Formal C++

Insert exactly this content into [UID:0001L0]'s formal `RECONSTRUCTION_CPP CODE` block:

```cpp
bool SpellWhoInputPane::OnKeyEvent(KeyEvent *event)
{
    const unsigned char key = NarrowKey(event->key);
    const unsigned char flags = event->modifierFlags;

    if ((flags & 0x03) != 0)
        return true;

    if (key == kKeyEnter) {
        if (event->kind == kKeyPressed) {
            LivingObjectPane *target =
                g_activeMapPane->FindObjectPaneById(s_spellWhoTargetId);
            if (target != NULL) {
                ClearSpellWhoTarget();

                ObjectListPosition position;
                target->GetObjectListPosition(&position);
                SendTargetedActionPacket(m_spellIndex, target->ObjectId(),
                    position.x, position.y);
            }
        }
        return LineInputPane::OnKeyEvent(event);
    }

    if (key == kKeyEscape) {
        if (event->kind == kKeyPressed) {
            LivingObjectPane *target =
                g_activeMapPane->FindObjectPaneById(s_spellWhoTargetId);
            if (target != NULL)
                ClearSpellWhoTarget();
        }
        return LineInputPane::OnKeyEvent(event);
    }

    if (event->kind != kKeyPressed)
        return true;

    LivingObjectPane *current =
        g_activeMapPane->FindObjectPaneById(s_spellWhoTargetId);

    if (key == kKeySelfTarget) {
        LivingObjectPane *selfTarget = g_pUserPane->GetLocalPlayerObject();
        if (current != selfTarget) {
            if (current != NULL)
                current->SetTargetHighlight(false);
            selfTarget->SetTargetHighlight(true);
            s_spellWhoTargetId = selfTarget->ObjectId();
        }
        return true;
    }

    const TargetTraversalOrder *order =
        ((flags & 0x04) != 0)
            ? &g_pConfig->alternateTargetTraversalOrder
            : &g_pConfig->targetTraversalOrder;

    int traversalDirection;
    if (order->first == 1) {
        if (order->second == 1) {
            traversalDirection = -1;
        } else if (order->second == 0) {
            traversalDirection = 0;
        } else {
            return true;
        }
    } else {
        if (order->first != 0 || order->second != 1)
            return true;
        traversalDirection = 1;
    }

    LivingObjectPane *nextTarget = NULL;
    if (IsPreviousTargetKey(key)) {
        nextTarget = current != NULL
            ? g_activeMapPane->FindPreviousSelectableObject(current, traversalDirection)
            : g_pUserPane->GetLocalPlayerObject();
    } else if (IsNextTargetKey(key)) {
        nextTarget = current != NULL
            ? g_activeMapPane->FindNextSelectableObject(current, traversalDirection)
            : g_pUserPane->GetLocalPlayerObject();
    } else {
        return true;
    }

    if (nextTarget == current)
        return true;

    if (current != NULL)
        current->SetTargetHighlight(false);

    if (nextTarget != NULL) {
        nextTarget->SetTargetHighlight(true);
        s_spellWhoTargetId = nextTarget->ObjectId();
    } else {
        s_spellWhoTargetId = 0;
    }

    return true;
}
```

Evidence and source-shape notes: this preserves the low-bit modifier gate, event kind `8` gate for handled state-changing paths, Enter/Escape base `LineInputPane::OnKeyEvent` fallback, self-target key `-111`, previous/up keys `104`, `107`, `-128`, `-127`, next/down keys `106`, `108`, `-126`, `-125`, traversal option pairs at config offsets `+0x2911dc` and `+0x2911de`, `sub_506C20` / `sub_506C70` traversal with signed direction, and opcode `0x0f` targeted-action send through [UID:0001L9]. `ObjectListPosition` maps the documented `sub_5374D0` output to source-facing `position.x` / `position.y`.

#### [UID:0001L1] Mouse Handler Exact Formal C++

Insert exactly this content into [UID:0001L1]'s formal `RECONSTRUCTION_CPP CODE` block:

```cpp
bool SpellWhoInputPane::OnMouseEvent(MouseEvent *event)
{
    if (event->kind != kMouseTargetChange &&
        event->kind != kMouseTargetConfirm) {
        return false;
    }

    Point paneOrigin;
    Point mapOrigin;
    Rect mapRect;

    GetOrigin(&paneOrigin);
    g_activeMapPane->GetOrigin(&mapOrigin);

    const int mapX = event->x + paneOrigin.x - mapOrigin.x;
    const int mapY = event->y + paneOrigin.y - mapOrigin.y;

    g_activeMapPane->GetBoundsRect(&mapRect);
    LivingObjectPane *current =
        g_activeMapPane->FindObjectPaneById(s_spellWhoTargetId);

    if (event->kind == kMouseTargetConfirm) {
        if (current == NULL || !PointInRect(mapX, mapY, mapRect))
            return false;

        current->SetTargetHighlight(false);
        g_pUserPane->ClearPendingTargetObject();

        ObjectListPosition position;
        current->GetObjectListPosition(&position);
        SendTargetedActionPacket(m_spellIndex, current->ObjectId(),
            position.x, position.y);

        g_pApplicationCleanupQueue->QueuePaneForDeferredDeletion(this);
        return true;
    }

    LivingObjectPane *hitTarget =
        g_activeMapPane->HitTestObjectAtPoint(mapX, mapY);

    if (hitTarget != NULL && hitTarget != current) {
        if (current != NULL)
            current->SetTargetHighlight(false);
        hitTarget->SetTargetHighlight(true);
        s_spellWhoTargetId = hitTarget->ObjectId();

        if (g_pConfig->doubleClick)
            return true;

        if (current == NULL)
            return false;

        ClearSpellWhoTarget();
        g_pUserPane->ClearPendingTargetObject();

        ObjectListPosition position;
        hitTarget->GetObjectListPosition(&position);
        SendTargetedActionPacket(m_spellIndex, hitTarget->ObjectId(),
            position.x, position.y);

        g_pApplicationCleanupQueue->QueuePaneForDeferredDeletion(this);
        return true;
    }

    if (!PointInRect(mapX, mapY, mapRect))
        return false;

    if (g_pConfig->doubleClick || current == NULL)
        return true;

    ClearSpellWhoTarget();
    g_pUserPane->ClearPendingTargetObject();

    ObjectListPosition position;
    current->GetObjectListPosition(&position);
    SendTargetedActionPacket(m_spellIndex, current->ObjectId(),
        position.x, position.y);

    g_pApplicationCleanupQueue->QueuePaneForDeferredDeletion(this);
    return true;
}
```

Evidence and source-shape notes: this preserves event subtype `1` target-change and subtype `2` confirm/click, pane/map origin conversion, map rectangle containment, `MapPane::HitTestObjectAtPoint`, saved-target update, highlight clear/set effects, config byte `+0x28de5a` as `g_pConfig->doubleClick`, `g_pUserPane->ClearPendingTargetObject()` for `dword_67A748+0x210 = 0`, and close/deferred-deletion through `dword_67A74C` / `sub_469180`.

#### [UID:0001L2] Object-List Virtual Exact Formal C++

Insert exactly this content into [UID:0001L2]'s formal `RECONSTRUCTION_CPP CODE` block:

```cpp
bool SpellWhoInputPane::OnObjectListMessage(const PacketEvent *event)
{
    const unsigned char *payload = event->payload;
    if (payload == NULL || payload[0] != '_')
        return false;

    const unsigned char count = payload[1];
    bool containsCurrentTarget = false;

    for (unsigned char i = 0; i < count; ++i) {
        const unsigned int objectId =
            PacketBufferReadUInt32BE(payload + 2 + i * 4);
        if (objectId == s_spellWhoTargetId) {
            containsCurrentTarget = true;
            break;
        }
    }

    if (!containsCurrentTarget)
        return false;

    LivingObjectPane *oldTarget =
        g_activeMapPane->FindObjectPaneById(s_spellWhoTargetId);
    LivingObjectPane *selfTarget = g_pUserPane->GetLocalPlayerObject();

    s_spellWhoTargetId = selfTarget->ObjectId();

    if (oldTarget != NULL)
        oldTarget->SetTargetHighlight(false);

    selfTarget->SetTargetHighlight(true);
    return false;
}
```

Evidence and source-shape notes: this follows the accepted ItemWho object-list source shape with `s_spellWhoTargetId`. `payload[1]` is the runtime char-traits byte load and `PacketBufferReadUInt32BE` is `sub_5754C0`. The fallback is only proven when the payload contains the current saved id; do not describe it as absence from an active-object list.

#### [UID:0001L3] Clear Helper Exact Formal C++

Insert exactly this content into [UID:0001L3]'s formal `RECONSTRUCTION_CPP CODE` block:

```cpp
static void ClearSpellWhoTarget()
{
    LivingObjectPane *target =
        g_activeMapPane->FindObjectPaneById(s_spellWhoTargetId);
    if (target != NULL)
        target->SetTargetHighlight(false);
}
```

Evidence and source-shape notes: this is a file-local helper under [UID:0000OH]. It has no receiver argument, reads `s_spellWhoTargetId`, resolves through `g_activeMapPane`, and clears highlight only when lookup succeeds. The implementation should document `ClearSpellWhoTarget` as the source-facing helper name; filename/title cleanup is not required because the UID is the durable identity.

## Recommended Target Doc Changes

For `by-memory/0x005ae2a0-0x005aeb1f.SpellWhoInputPane.md`:

1. Change metadata to `88/90`, keep `CANONICAL_OWNER:0000DX`, set `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, and keep blank formal C++.
2. Change the status/disposition to "non-emitting split index / aggregate for exact SpellWho child pages and support evidence."
3. Add a `Formal C++ Status` or equivalent section with the no-code proof above.
4. Preserve the exact child table, but update wording so:
   - `0x005ae68a-0x005ae730` is compiler switch-support for [UID:0001L0];
   - `0x005aeb20` is successor executable-looking local target-selection code not modeled as an IDA function in current MCP;
   - [UID:0001L3] is file-local helper support owned by [UID:0000OH].
5. Add current MCP evidence:
   - session `80de0a67`;
   - lookup sizes and negative starts;
   - padding/switch bytes;
   - vtable slots `0x0062f260/264/268/270` and `0x0062f290`;
   - constructor callers;
   - saved-target xrefs and names.
6. Replace stale "final member/helper names remain blockers" wording with resolved source-facing names and the residual caveat: exact original spelling is not symbol-proven, but source-facing roles are resolved enough for child pages.
7. Add score rationale for `88/90` and generated empty-emitter cleanup.

## Recommended Support Doc Changes

### `by-class/SpellWhoInputPane.md`

Update class notes to:

- state that [UID:0001KY] is a non-emitting split index, not an emitting aggregate;
- keep direct file route through [UID:0000OH];
- preserve `s_spellWhoTargetId` / `s_spellWhoSavedTargetId` for `0x0069bf20`;
- use `m_spellIndex` for object offset `+0x108`;
- list recommended source-facing method names:
  - `SpellWhoInputPane::SpellWhoInputPane(unsigned char spellIndex)`;
  - `SpellWhoInputPane::~SpellWhoInputPane()`;
  - `bool SpellWhoInputPane::OnKeyEvent(KeyEvent *event)`;
  - `bool SpellWhoInputPane::OnMouseEvent(MouseEvent *event)`;
  - `bool SpellWhoInputPane::OnObjectListMessage(const PacketEvent *event)`;
  - file-local `ClearSpellWhoTarget()` / `ClearSavedSpellWhoTarget()`.
- note that [UID:0001NA] is compiler-generated thunk output and [UID:0001NK] is scalar wrapper support, not ordinary source destructor C++.
- state that exact source C++ now belongs on child pages [UID:0001KX], [UID:0001KZ], [UID:0001L0], [UID:0001L1], [UID:0001L2], and [UID:0001L3], while [UID:0001KY] remains blank/no-code.

### `by-file/TargetSelectionInputPanes.md`

Update file notes to:

- list [UID:0001KY] as a non-emitting SpellWho split index, matching [UID:0001L4] ItemWho;
- keep exact SpellWho child pages as source bodies under [UID:0000DX] and [UID:0000OH];
- document that `s_spellWhoTargetId` is the preferred source-facing name for `dword_69BF20`;
- mention the object-list virtual parity with TargetObject/ItemWho/SelectObject: payload contains the saved id -> fallback to local player; protocol meaning remains unresolved;
- note that `0x005aeb20-0x005aec60` is an out-of-range raw target-selection island with SpellWho saved-target refs, no current IDA function model, and no current by-memory UID; it does not affect [UID:0001KY] metadata, but should be assigned separately as `SpellWhoTargetSelectionRawHelperIsland` before any source C++ is emitted for that successor island.

### Child Pages

Required child/support edits after supervisor acceptance:

- Update [UID:0001KX] `by-memory/0x005ae2a0-0x005ae372.SpellWhoInputPaneConstructor.md` to `COMPLETION:88`, `CONFIDENCE:90`, keep owner/emitter [UID:0000DX], replace stale final-code-threshold wording, document `m_spellIndex`, `s_spellWhoTargetId`, `GetSpellPromptText(spellIndex)`, and insert the exact constructor formal C++ from this report.
- Update [UID:0001KZ] `by-memory/0x005ae380-0x005ae403.SpellWhoInputPaneDestructor.md` to `COMPLETION:88`, `CONFIDENCE:90`, keep owner/emitter [UID:0000DX], replace stale threshold wording, document `g_targetInputStateUsesItemWho`, state-slot index `3`, item/spell state helper branch, and insert the exact destructor formal C++ from this report.
- Update [UID:0001L0] `by-memory/0x005ae410-0x005ae68a.SpellWhoInputPaneKeyNavigationInput.md` to `COMPLETION:88`, `CONFIDENCE:90`, keep owner/emitter [UID:0000DX], rename source-facing method to `SpellWhoInputPane::OnKeyEvent`, preserve key/event/flag gates and traversal-pair logic, and insert the exact key-handler formal C++ from this report.
- Update [UID:0001L1] `by-memory/0x005ae730-0x005aea53.SpellWhoInputPanePointerSelectionInput.md` to `COMPLETION:88`, `CONFIDENCE:90`, keep owner/emitter [UID:0000DX], rename source-facing method to `SpellWhoInputPane::OnMouseEvent`, preserve subtype `1`/`2`, map-coordinate conversion, `g_pConfig->doubleClick`, pending-target clear, send/close paths, and insert the exact mouse-handler formal C++ from this report.
- Update [UID:0001L2] `by-memory/0x005aea60-0x005aeaf3.SpellWhoInputPaneObjectListVirtual.md` to `COMPLETION:88`, `CONFIDENCE:90`, keep owner/emitter [UID:0000DX], use source-facing method `SpellWhoInputPane::OnObjectListMessage`, preserve neutral payload wording and `PacketBufferReadUInt32BE`, and insert the exact object-list formal C++ from this report.
- Update [UID:0001L3] `by-memory/0x005aeb00-0x005aeb1f.DeactivateSavedSpellWhoTarget.md` to `COMPLETION:88`, `CONFIDENCE:90`, keep owner/emitter [UID:0000OH], use source-facing file-local helper `ClearSpellWhoTarget`, replace stale threshold wording, and insert the exact helper formal C++ from this report. A filename/title rename is optional; the UID is the durable identity and the accepted implementation can keep the current filename while documenting the source-facing helper name.
- Update [UID:0001NK] `by-memory/0x005b8100-0x005b81c4.SpellWhoInputPaneScalarDeletingDestructor.md` to `COMPLETION:88`, `CONFIDENCE:90`, keep owner/emitter [UID:0000DX], keep blank formal C++, and add explicit no-source-C++ proof: the page documents compiler scalar deleting destructor flags, delete paths, vtable/thunk reachability, and duplicate cleanup, while ordinary source destructor C++ belongs on [UID:0001KZ].
- No edit is required for [UID:0001NA] `by-memory/0x005b78fc-0x005b7912.SpellWhoInputPaneAdjustorThunks.md`: existing metadata `RECONSTRUCTABLE:FALSE`, owner `NONE`, blank emitter, blank C++, disassembly proof, vtable refs, and compiler-generated adjustor-thunk rationale are adequate.

### Generated / Coverage State

- Do not manually edit `auto-generated/*`, `project-level/*`, `by-memory/-coverage-report.md`, or any `-coverage-report.md`.
- Implementation validators should refresh generated state. If generated C++ still shows empty emitter markers for [UID:0001KY] after target implementation, run only the scoped validator/autogen command authorized by the supervisor/validator workflow, not manual generated edits.

## Validators Expected After Implementation

Run scoped validators for every edited file. Expected validators for this accepted callback are:

> Executable block R001 was removed from this report and preserved verbatim in [0001KY-SpellWhoInputPane-source-quality-removed.md](0001KY-SpellWhoInputPane-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

## Remaining Issues And Impact

Resolved in this pass:

- Parent aggregate should not emit code.
- Exact child ranges and switch/padding spans are confirmed.
- `s_spellWhoTargetId` / `s_spellWhoSavedTargetId` is the correct saved-target slot name.
- `m_spellIndex` is the correct class field role for `this+0x108`.
- Event fields are identified as `kind`, `key`/coordinates, and `modifierFlags`.
- `0x00575470` is runtime character-traits byte load, not project object-list logic.
- `0x005754c0` should be treated as `PacketBufferReadUInt32BE`.
- Spell inventory and LivingObject command-slot paths are constructor/use dependencies, not source owners.
- [UID:0001NA] thunks remain compiler-generated.
- Source-bearing child C++ is now supplied for [UID:0001KX], [UID:0001KZ], [UID:0001L0], [UID:0001L1], [UID:0001L2], and [UID:0001L3], so the parent false/non-emitting reclassification no longer hides source code.

Residual caveats:

- Exact original spelling of `KeyEvent`, `MouseEvent`, `PacketEvent`, config traversal fields, and target-click config field remains inferred. This caps confidence below final-audit but does not block the parent reclassification.
- `0x005aeb20-0x005aec60` is outside [UID:0001KY] and has no current exact by-memory UID. It should be assigned as a separate raw-helper island; this does not block [UID:0001KY] or its exact children because the parent half-open end and all in-range source homes are already resolved.

## Implementation Tracking Checklist

Implementation callback applied on 2026-06-26 by B004. Checked items include proof for supervisor verification.

- [x] Update [UID:0001KY] `by-memory/0x005ae2a0-0x005aeb1f.SpellWhoInputPane.md` metadata to `COMPLETION:88`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000DX`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, and blank formal C++. Proof: metadata updated; validator `000000003212` at `2026-06-26T19:40:44-04:00` exited `0`, `ok: 1`.
- [x] Add [UID:0001KY] parent no-code proof: the range is a non-emitting split index over exact source child methods, a file-local helper, switch-support bytes, padding, scalar destructor support, and compiler adjustor-thunk evidence; it has no one-to-one original source body. Proof: `Formal C++ Status` section added to target; validator `000000003212` exited `0`, `ok: 1`.
- [x] Add current [UID:0001KY] MCP proof: session `80de0a67`, boundary `lookup_funcs`, negative starts, padding/switch bytes, vtable slots, constructor callers, saved-target xrefs, decompile facts, the broad-xref timeout plus healthy retry, and the revision singular-`addr` retry after schema mismatch. Proof: target `IDA MCP Evidence` includes B004 2026-06-26 refresh; validator `000000003212` exited `0`, `ok: 1`.
- [x] Update [UID:0001KY] source-quality names and rejected alternatives: `s_spellWhoTargetId` / `s_spellWhoSavedTargetId`, `m_spellIndex`, `OnKeyEvent`, `OnMouseEvent`, `OnObjectListMessage`, `ClearSpellWhoTarget` / `ClearSavedSpellWhoTarget`, `PacketBufferReadUInt32BE`, `MapPane::FindObjectPaneById`, `LivingObjectPane::SetTargetHighlight`, traversal config pairs, target-click config byte caveat, and rejection of SpellInputPanes/spell manager/raw-label ownership. Proof: target `Source-Quality Resolution` section added; validator `000000003212` exited `0`, `ok: 1`.
- [x] Add [UID:0001KY] successor-span note: `0x005aeb20-0x005aec60` is outside the parent half-open range, has no exact current by-memory UID, is not an IDA function, begins executable-looking target-selection bytes, and should be assigned separately as `SpellWhoTargetSelectionRawHelperIsland` before any C++ is emitted for that successor island. Proof: target child table and MCP refresh include the successor raw-island note; validator `000000003212` exited `0`, `ok: 1`.
- [x] Update [UID:0000DX] `by-class/SpellWhoInputPane.md` to mark [UID:0001KY] as a non-emitting split index and record the source-facing method/global/field names, direct file route, child-page C++ homes, scalar-wrapper policy, and adjustor-thunk policy. Proof: `B004 Source-Quality Routing` section and method table updated; validator `000000003213` at `2026-06-26T19:40:46-04:00` exited `0`, `ok: 1`.
- [x] Update [UID:0000OH] `by-file/TargetSelectionInputPanes.md` to mirror the SpellWho non-emitting index policy, source route, exact SpellWho child homes, saved-target name, object-list payload semantics, and `0x005aeb20-0x005aec60` successor raw-island recommendation. Proof: file role, Proposed Contents, Boundary Notes, and Changes updated; validator `000000003214` at `2026-06-26T19:40:48-04:00` exited `0`, `ok: 1`.
- [x] Update [UID:0001KX] `by-memory/0x005ae2a0-0x005ae372.SpellWhoInputPaneConstructor.md` to `COMPLETION:88`, `CONFIDENCE:90`, keep owner/emitter [UID:0000DX], replace stale threshold wording, document `m_spellIndex`, `s_spellWhoTargetId`, prompt/target fallback/highlight behavior, and insert the exact constructor formal C++ from this report. Proof: exact formal constructor block inserted; validator `000000003215` at `2026-06-26T19:40:59-04:00` exited `0`, `ok: 1`.
- [x] Update [UID:0001KZ] `by-memory/0x005ae380-0x005ae403.SpellWhoInputPaneDestructor.md` to `COMPLETION:88`, `CONFIDENCE:90`, keep owner/emitter [UID:0000DX], replace stale threshold wording, document `g_targetInputStateUsesItemWho`, state-slot index `3`, item/spell state cleanup branches, and insert the exact destructor formal C++ from this report. Proof: exact formal destructor block inserted; validator `000000003216` at `2026-06-26T19:41:01-04:00` exited `0`, `ok: 1`.
- [x] Update [UID:0001L0] `by-memory/0x005ae410-0x005ae68a.SpellWhoInputPaneKeyNavigationInput.md` to `COMPLETION:88`, `CONFIDENCE:90`, keep owner/emitter [UID:0000DX], use source-facing method `SpellWhoInputPane::OnKeyEvent`, preserve Ctrl/modifier gate, event-kind gate, Enter/Escape base fallback, self-target/navigation keys, traversal config pairs, packet send path, and insert the exact key-handler formal C++ from this report. Proof: exact formal key-handler block inserted; validator `000000003217` at `2026-06-26T19:41:09-04:00` exited `0`, `ok: 1`.
- [x] Update [UID:0001L1] `by-memory/0x005ae730-0x005aea53.SpellWhoInputPanePointerSelectionInput.md` to `COMPLETION:88`, `CONFIDENCE:90`, keep owner/emitter [UID:0000DX], use source-facing method `SpellWhoInputPane::OnMouseEvent`, preserve subtype `1`/`2`, pane/map coordinate conversion, hit-test/rectangle checks, `g_pConfig->doubleClick`, pending-target clear, send/close paths, and insert the exact mouse-handler formal C++ from this report. Proof: exact formal mouse-handler block inserted; validator `000000003218` at `2026-06-26T19:41:11-04:00` exited `0`, `ok: 1`.
- [x] Update [UID:0001L2] `by-memory/0x005aea60-0x005aeaf3.SpellWhoInputPaneObjectListVirtual.md` to `COMPLETION:88`, `CONFIDENCE:90`, keep owner/emitter [UID:0000DX], use source-facing method `SpellWhoInputPane::OnObjectListMessage`, preserve neutral payload wording, `PacketBufferReadUInt32BE`, saved-id containment test, local-player fallback highlight, and insert the exact object-list formal C++ from this report. Proof: exact formal object-list block inserted; validator `000000003219` at `2026-06-26T19:41:12-04:00` exited `0`, `ok: 1`.
- [x] Update [UID:0001L3] `by-memory/0x005aeb00-0x005aeb1f.DeactivateSavedSpellWhoTarget.md` to `COMPLETION:88`, `CONFIDENCE:90`, keep owner/emitter [UID:0000OH], use source-facing file-local helper `ClearSpellWhoTarget`, replace stale threshold wording, preserve no-receiver/helper ownership proof, and insert the exact helper formal C++ from this report. Proof: exact formal clear-helper block inserted; validator `000000003220` at `2026-06-26T19:41:14-04:00` exited `0`, `ok: 1`.
- [x] Update [UID:0001NK] `by-memory/0x005b8100-0x005b81c4.SpellWhoInputPaneScalarDeletingDestructor.md` to `COMPLETION:88`, `CONFIDENCE:90`, keep owner/emitter [UID:0000DX], keep blank formal C++, and add explicit no-source-C++ proof that this page documents compiler scalar deleting destructor flags/delete paths/vtable-thunk reachability while ordinary destructor source C++ belongs on [UID:0001KZ]. Proof: scalar wrapper no-source-C++ proof added; formal C++ block remains blank; validator `000000003221` at `2026-06-26T19:41:21-04:00` exited `0`, `ok: 1`.
- [x] Confirm [UID:0001NA] `by-memory/0x005b78fc-0x005b7912.SpellWhoInputPaneAdjustorThunks.md` already has adequate `RECONSTRUCTABLE:FALSE`, owner `NONE`, blank emitter, blank C++, disassembly proof, vtable refs, and compiler-generated adjustor-thunk rationale; no edit is required. Proof: page inspected during implementation; no contradiction found and no edit made.
- [x] Do not edit generated/project-level/manual coverage/tool-state/IDA DB files or any `-coverage-report.md`. Proof: no manual edits made to those files. Validator-generated/projected stats side effects were tool-owned (`projected_stats_update`; generated refresh deferred).
- [x] Run scoped validators for every changed `by-*` file: [UID:0001KY], [UID:0000DX], [UID:0000OH], [UID:0001KX], [UID:0001KZ], [UID:0001L0], [UID:0001L1], [UID:0001L2], [UID:0001L3], and [UID:0001NK]. Proof: validators `000000003212` through `000000003221` all exited `0` with `ok: 1`.
- [x] Report each validator command, command id, timestamp, exit code, ok count, validator side effects, and generated-refresh state; confirm generated files are refreshed only through validator workflow. Proof: implementation result records all ten commands. Each validator initially returned `generated_refresh: deferred` with matching command id/timestamp; follow-up queue status `000000003222` at `2026-06-26T19:43:28-04:00` showed zero queued/processing jobs, and `auto-generated/NexusTK/ui/dialogs/TargetSelectionInputPanes.cpp` refreshed to `validator-command-id: 000000003221`, `validator-refreshed-at: 2026-06-26T19:41:21-04:00`. By-file validator `000000003214` also reported pre-existing `missing_ref_uid` diagnostics for unrelated TargetObject/prompt refs while still returning `ok: 1`.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000004165","destination_path":"executed-b-agent-research/B004/0001KY-SpellWhoInputPane-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B004/research/0001KY-SpellWhoInputPane-source-quality.md","timestamp":"2026-06-26T19:56:10","uid":"0001KY"} -->
<!-- {"agent":"B004","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001KY-SpellWhoInputPane-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B004/0001KY-SpellWhoInputPane-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001KY"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
