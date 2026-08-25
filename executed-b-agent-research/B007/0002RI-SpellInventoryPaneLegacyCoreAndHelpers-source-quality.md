** TARGET-REPORT-UID:0002RI **
** AUTHOR-AGENT-ID:B007 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# [UID:0002RI] SpellInventoryPaneLegacyCoreAndHelpers Source-Quality Reanalysis

Agent: Agent-B007
Assignment: B007 new report-only source-quality pass
Target: `by-memory/0x0057c2d0-0x0057cf6b.SpellInventoryPaneLegacyCoreAndHelpers.md`
Report path: `tools/leaser/Agents/Agent-B007/research/0002RI-SpellInventoryPaneLegacyCoreAndHelpers-source-quality.md`
Date: 2026-06-19

## Final Recommendation

`0002RI` is reconstructable as a source-quality legacy `SpellInventoryPane` method/helper island, but it should remain formal-C++ blank at the aggregate level until it is split into exact method/helper children. The current documentation is directionally correct about the legacy spell inventory ownership and dispatcher role, but it under-documents several raw helper bodies and contains one important stale span claim: `0x0057cc42-0x0057ccd0` is not only jump-table material. It contains dispatcher alignment, an eight-entry jump table, padding, and a retained no-route direct-spell packet helper at `0x0057cc70-0x0057ccd0`.

Recommended metadata after implementation:

```text
*** COMPLETION:88
*** CONFIDENCE:89
*** CANONICAL_OWNER:0000DN
*** RECONSTRUCTABLE:TRUE
*** EMITTER_UIDS:0000DN
```

`0000DN` (`SpellInventoryPane`) is the best direct owner because the target is a legacy class method/helper island. `0000O1` (`SpellInventoryPane.cpp`) remains the source-file route and support documentation home for file placement. `SpellInputPanes.cpp` and `TargetSelectionInputPanes.cpp` own constructed prompt panes and target-selection helpers; they do not own this dispatcher or its local geometry/packet helpers.

## Scope And Inputs

Report-only constraints were observed for this pass. No `by-*` documentation file and no `by-memory/-coverage-report.md` file should be edited by this report task. The implementation callback can apply the recommendations if accepted.

Instructions checked:

- `tools/leaser/Agents/Supervisor.md`
- `.codex/AGENTS.md`
- `tools/leaser/Agents/Agent-B007/goal.md`
- `project-documentation/by-structure.md`
- `project-documentation/inference_research.md`

Evidence checked:

- Target doc `by-memory/0x0057c2d0-0x0057cf6b.SpellInventoryPaneLegacyCoreAndHelpers.md`
- Parent aggregate `by-memory/0x0057c2d0-0x0057f742.SpellInventoryPanes.md`
- `by-class/SpellInventoryPane.md`
- `by-file/SpellInventoryPane.md`
- `by-file/SpellInputPanes.md`
- `by-file/TargetSelectionInputPanes.md`
- Input pane constructor pages for string/who/four/three/two/one/slot spell input panes
- `by-memory/0x0057c430-0x0057c43f.SpellInputPaneStateSetFlag.md`
- `by-memory/0x005af4f0-0x005af57b.SendTargetedActionPacket.md`
- `by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md`
- `by-global/g_packetSender.md`
- `by-global/g_pCollectionData.md` and `by-memory/0x0067a748-0x0067a74c.g_pCollectionData.md`
- `by-memory/0x0062cfd8-0x0062d418.SpellInventoryMacroReadOnlyData.md`
- `by-project-structure/proposed-source-tree.md`

IDA MCP was unavailable during this pass (`Unable to connect to the remote server`). I used the local PE image `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` and local PE/Capstone disassembly for byte and range verification. This is sufficient for range/padding/xref-local proof but should still be cross-checked in IDA during implementation if the MCP is restored.

## Current Target State

Current target metadata:

```text
*** UID: 0002RI
*** COMPLETION: 85
*** CONFIDENCE: 87
*** CANONICAL_OWNER: 0000O1
*** RECONSTRUCTABLE: TRUE
*** EMITTER_UIDS: 0000O1
```

Current coverage row is stale relative to the target metadata and the raw helper evidence:

```text
- [UID:0002RI][0x0057c2d0-0x0057cf6b.SpellInventoryPaneLegacyCoreAndHelpers](by-memory/0x0057c2d0-0x0057cf6b.SpellInventoryPaneLegacyCoreAndHelpers.md) 0x0057c2d0-0x0057cf6b | method/helper-group | SpellInventoryPaneLegacyCoreAndHelpers : reconstructable : 76% : strong : Legacy spell inventory constructor/draw/input/message helpers, spell dispatcher, row geometry, and switch-table evidence documented.
```

The target currently treats `0x0057cc42-0x0057ccd0` as a jump-table span with alignment. The byte recheck shows that the span also includes a real helper body at `0x0057cc70-0x0057ccd0`. That helper cannot be collapsed into padding or jump-table data.

## Exact Function, Data, And Padding Inventory

The exact half-open inventory for `0x0057c2d0-0x0057cf6b` is:

| Range | Kind | Best-supported name | Evidence and source-quality notes |
|---|---:|---|---|
| `0x0057c2d0-0x0057c39f` | function | `SpellInventoryPane::SpellInventoryPane()` | Legacy constructor. Calls `0x00545090`, allocates via `0x004f4aa0`, calls `0x004e97b0`, writes legacy spell inventory vtables at `0x0062cfdc`, `0x0062d02c`, and `0x0062d05c`, and uses `dword_672f24`/`dword_69b368`. No direct rel32 caller or raw pointer to the constructor start was found; construction route is not directly proved by local xref scan. |
| `0x0057c39f-0x0057c3a0` | padding | none | Single `cc` byte. |
| `0x0057c3a0-0x0057c401` | function | `SpellInventoryPane::~SpellInventoryPane()` | Direct destructor/non-scalar cleanup. Calls `0x00544690` and `0x005450d0`, restores the same vtable family, and cleans legacy pane owned members. |
| `0x0057c401-0x0057c410` | padding | none | Fifteen `cc` bytes. |
| `0x0057c410-0x0057c425` | function | `SpellInventoryPane::ResetPage()` | Writes `word ptr [this+0xf8] = 0`, then calls a virtual/invalidation style method via `[vtable+0x20]` with `this+0x44`. Best name is page reset rather than generic accessor because it clears both current-page and next-page gate bytes. |
| `0x0057c425-0x0057c430` | padding | none | Eleven `cc` bytes. |
| `0x0057c430-0x0057c440` | function | `SpellInventoryPane::SetSpellInputActiveFlag(bool active)` | Pure setter for byte `[this+0xfa]`. Existing pages call this `SpellInputPaneState::SetInputModeFlag`; reanalysis supports a legacy `SpellInventoryPane` pending-input flag interpretation or at least a caveated generated-state helper name. |
| `0x0057c440-0x0057c44b` | function | `SpellInventoryPane::GetSpellEffectInterface()` or `SpellInventoryPane::ForwardSpellEffect()` | Loads `[this+0xfc]` into `ecx` and jumps to `0x004e9950`. Exact callee name remains unresolved; the field is best documented as the constructor-created spell effect/interface pointer. |
| `0x0057c44b-0x0057c450` | padding | none | Five `cc` bytes. |
| `0x0057c450-0x0057c710` | function | `SpellInventoryPane::DrawSpells()` | Draws the legacy spell list and paging controls. Uses `g_pCollectionData`, `SPELLINV.EPD`, `%c: %s`, 13 visible rows, and `0x148` spell-record stride. |
| `0x0057c710-0x0057c78c` | function | `SpellInventoryPane::OnKeyDown()` | Handles page up/down key behavior, calls key-state helper `0x004a8b10`, uses current-page/no-next-page bytes, and triggers redraw/invalidation through the pane vtable. |
| `0x0057c78c-0x0057c790` | padding | none | Four `cc` bytes. |
| `0x0057c790-0x0057c979` | function | `SpellInventoryPane::OnMouseDown()` | Hit-tests visible spell rows and page buttons. Calls `0x0057ce70`, `0x0057cf10`, `0x0057c9b0`, and `0x0057ccd0`. The old `0x0057c790-0x0057c9a8` mouse/message lump should be split at `0x0057c979`. |
| `0x0057c979-0x0057c980` | padding | none | Seven `cc` bytes. |
| `0x0057c980-0x0057c9a8` | function | `SpellInventoryPane::OnMessage()` | Message/close handler for legacy pane state; separate from mouse handler. |
| `0x0057c9a8-0x0057c9b0` | padding | none | Eight `cc` bytes. |
| `0x0057c9b0-0x0057cc42` | function | `SpellInventoryPane::CastSpell(uint8_t spellSlot)` | Dispatcher for spell activation. Validates slot `1..52`, reads spell record/type from `g_pCollectionData`, allocates the proper input pane or sends a direct packet/targeted action. |
| `0x0057cc42-0x0057cc44` | alignment | none | Two-byte NOP/alignment (`66 90`). |
| `0x0057cc44-0x0057cc64` | jump table | dispatcher table for `SpellInventoryPane::CastSpell` | Eight dword entries: `0x0057ca2c`, `0x0057ca60`, `0x0057cae8`, `0x0057cb1c`, `0x0057cb50`, `0x0057cb98`, `0x0057cbc5`, `0x0057cbf2`. |
| `0x0057cc64-0x0057cc70` | padding | none | Twelve `cc` bytes. |
| `0x0057cc70-0x0057ccd0` | raw helper body | `SendDirectSpellCastPacketRaw` / file-local `SendSpellCastPacket(uint8_t spellSlot)` | Builds packet bytes `{0x0f, spellSlot}` with a cleared local third byte that is not transmitted, then calls `QueueAndSendPacket(g_packetSender, packet, 2)`. No direct rel32/pointer reference to this helper start was found. It is retained no-route helper code, not padding. |
| `0x0057ccd0-0x0057cd51` | function | `BuildPageButtonRect()` / `GetPageButtonRect()` | Called by `OnMouseDown` at `0x0057c887`. Builds two page-button rectangles and writes `-1` rects for invalid index. |
| `0x0057cd51-0x0057cd60` | padding | none | Fifteen `cc` bytes. |
| `0x0057cd60-0x0057cdb3` | raw helper body | `BuildSpellRowRectRaw()` | Builds row rectangle for row `0..12`: left `0x16`, top `0x33 + 13 * row`, right `0xaa`, bottom `0x40 + 13 * row`; invalid rows receive `-1` rect coordinates. No direct caller was found. |
| `0x0057cdb3-0x0057cdc0` | padding | none | Thirteen `cc` bytes. |
| `0x0057cdc0-0x0057ce68` | raw helper body | `HitTestPageButtonRaw()` | Loops the two page-button rectangles and calls `PointInRect`/`0x004b7e80`. No direct caller was found. Retained local helper code. |
| `0x0057ce68-0x0057ce70` | padding | none | Eight `cc` bytes. |
| `0x0057ce70-0x0057cf03` | function | `HitTestSpellRow()` | Called from `OnMouseDown` at `0x0057c80d` and `0x0057c902`. Loops rows `0..12`, builds row rects in-line, tests point through `0x004b7e80`, returns row or `-1`. |
| `0x0057cf03-0x0057cf10` | padding | none | Thirteen `cc` bytes. |
| `0x0057cf10-0x0057cf6b` | function | `FindSpellSlotForVisibleRow()` / `VisibleRowToSpellSlot()` | Called from `OnMouseDown` at `0x0057c836` and `0x0057c923`. Iterates candidate spell slots `1..52`, counts learned/visible entries, and returns the actual one-based spell slot whose visible ordinal matches the requested row/page ordinal, else `-1`. |
| `0x0057cf6b-0x0057cf70` | outside target padding | none | Five `cc` bytes before the next NewSpellInventoryPane constructor range. |

## Jump Table Span Recheck

Required span `0x0057cc42-0x0057ccd0` resolves as:

```text
0x0057cc42-0x0057cc44  alignment: 66 90
0x0057cc44-0x0057cc64  8-entry dword jump table
0x0057cc64-0x0057cc70  cc padding
0x0057cc70-0x0057ccd0  real helper body
```

The old wording that treats the whole interval as switch/jump-table data and alignment is incomplete. The helper at `0x0057cc70` is source-relevant because it is a complete packet emitter:

- local packet byte 0 receives opcode `0x0f`
- local packet byte 1 receives the selected spell slot
- local packet byte 2 is cleared but not sent
- `QueueAndSendPacket(g_packetSender, packet, 2)` transmits exactly two bytes

No direct call/jump/xref was found to `0x0057cc70`. That makes it a retained no-route helper body, not a live routed method. It should stay documented in the aggregate or become its own no-route child if the range is split.

## Dispatcher, Input Pane Allocation, And Packet Flow

`0x0057c9b0-0x0057cc42` is best named `SpellInventoryPane::CastSpell(uint8_t spellSlot)` or `SpellInventoryPane::ActivateSpellSlot(uint8_t spellSlot)`. I recommend `CastSpell` because current file/class docs already describe this dispatcher as the spell-cast activation path.

Behavior:

- Rejects slots outside `1..52` by testing `slot - 1 > 0x33`.
- Computes the spell record from `g_pCollectionData` with a `0x148` stride and the legacy spell table base used by this dispatcher.
- Rejects empty/unlearned records before dispatch.
- Reads the spell type/disposition from the spell record, decrements it, and dispatches cases `0..7` through the table at `0x0057cc44`.
- Opens an input pane for prompt-driven spell types and sets `[this+0xfa] = 1`.
- Sends direct packet or targeted action routes without creating a prompt pane.

Case inventory:

| Case entry | Route | Behavior |
|---:|---|---|
| `0x0057ca2c` | `SpellStringInputPane` | Allocates `0x10c` bytes and calls `0x005adf40`; sets pending-input flag. |
| `0x0057ca60` | targeted action or `SpellWhoInputPane` | If active map/target state is available, obtains target/object data and calls `SendTargetedActionPacket` at `0x005af4f0`; otherwise allocates `0x10c` bytes and calls `SpellWhoInputPane` constructor `0x005ae2a0`; prompt path sets pending-input flag. |
| `0x0057cae8` | `SpellFourArgsInputPane` | Allocates `0x10c` bytes and calls `0x005b0780`; sets pending-input flag. |
| `0x0057cb1c` | `SpellThreeArgsInputPane` | Allocates `0x10c` bytes and calls `0x005b0ac0`; sets pending-input flag. |
| `0x0057cb50` | direct spell packet | In-line direct-send route: writes opcode `0x0f`, writes spell slot, clears a third local byte that is not transmitted, calls `QueueAndSendPacket(g_packetSender, packet, 2)`, and clears pending-input flag. |
| `0x0057cb98` | `SpellTwoArgsInputPane` | Allocates `0x10c` bytes and calls `0x005b0da0`; sets pending-input flag. |
| `0x0057cbc5` | `SpellOneArgInputPane` | Allocates `0x10c` bytes and calls `0x005b1030`; sets pending-input flag. |
| `0x0057cbf2` | `SpellSlotInputPane` | Allocates `0x10c` bytes and calls `0x005b1280`; sets pending-input flag. |

Constructed pane ownership:

- `SpellStringInputPane`, `SpellFourArgsInputPane`, `SpellThreeArgsInputPane`, `SpellTwoArgsInputPane`, `SpellOneArgInputPane`, and `SpellSlotInputPane` remain under `SpellInputPanes.cpp`.
- `SpellWhoInputPane` remains better supported under `TargetSelectionInputPanes.cpp` because its constructor and behavior are target-selection oriented.
- The dispatcher itself remains in `SpellInventoryPane.cpp` and under class owner `SpellInventoryPane`.

## Spell Record And Field Naming

Recommended field/global names:

| Address/offset | Current/generated references | Best-supported source-facing name or description |
|---|---|---|
| `dword_67A748` | `g_pCollectionData`, sometimes older generated spell-manager labels | Keep `g_pCollectionData` / local-player or UserPane state pointer. Do not rename this to `SpellManager`; the global is broad and cross-domain. |
| `g_pCollectionData + 0x13a6ec + 0x148 * slot` | older target prose references `+0x13a82c` | Legacy spell slot record base used by this dispatcher and the visible-row lookup. Slots are one-based for the tested loop/callers. The older `+0x13a82c` claim is not supported for this body and should be removed unless an IDA recheck proves a separate access not observed here. |
| `record + 0x00` | learned/active/empty flag | `learned` or `isLearned` is best supported by row filtering and dispatcher rejection. |
| `record + 0x04` | spell type id / prompt route id | `inputType` or `castRoute` is best supported; it is decremented and used as the `0..7` dispatch selector. |
| `record + 0xa8` in supporting constructor docs | prompt/name pointer region | Existing input pane docs support prompt lookup around `g_pCollectionData + 0x13a794 + slot * 0x148`; keep this as prompt/name, not dispatcher owner data. |
| `this + 0xf8` | page byte | `m_currentPage`. Reset writes a word at `+0xf8`, clearing this byte and `+0xf9`. |
| `this + 0xf9` | next-page guard byte | `m_noNextPage` or `m_isLastPage`. Draw/key/mouse code uses this to prevent advancing past the last visible page. |
| `this + 0xfa` | input flag | `m_spellInputActive` or `m_pendingSpellInput`. This is the byte set by prompt allocations and cleared by direct-send routes. |
| `this + 0xfc` | pointer forwarded by `0x0057c440` | `m_spellEffect` / `m_interfaceEfx`; exact class name remains unresolved. |
| `dword_67A7EC` | `g_packetSender` | Keep `g_packetSender`, source-facing type `Socket *`, used by direct spell packet path through `QueueAndSendPacket`. |
| `dword_67A764` | active map pane | Active map pane singleton used by targeted action special case. |

The spell table evidence for this body supports `g_pCollectionData + 0x13a6ec + 0x148 * slot`, one-based slot iteration, a learned/empty byte at record offset `0`, a route/type dword at record offset `4`, and prompt/name material at record offset `0xa8` as documented by the constructor pages. The old `+0x13a82c` prose should be treated as stale for `0002RI`.

## Caller, Reachability, And Raw Helper Evidence

Direct local references found or rejected:

- No direct rel32 call/jump or raw pointer to constructor start `0x0057c2d0` was found. Construction may be vtable/factory/indirect routed or created by a parent aggregate not visible through direct static scan.
- No direct rel32 call/jump or raw pointer to destructor start `0x0057c3a0` was found, but destructor slot references exist through the class vtable region in `.rdata`.
- Vtable pointers exist for `0x0057c410`, `0x0057c450`, `0x0057c710`, `0x0057c790`, and `0x0057c980`, supporting class-method placement.
- `0x0057c9b0` has two direct call sites from `OnMouseDown`: `0x0057c84f` and `0x0057c934`.
- `0x0057ccd0` has one direct call site from `OnMouseDown`: `0x0057c887`.
- `0x0057ce70` has two direct call sites from `OnMouseDown`: `0x0057c80d` and `0x0057c902`.
- `0x0057cf10` has two direct call sites from `OnMouseDown`: `0x0057c836` and `0x0057c923`.
- No direct rel32 call/jump, VA pointer, RVA pointer, or raw-offset pointer was found for raw helper starts `0x0057cc70`, `0x0057cd60`, and `0x0057cdc0`.
- A naive byte scan candidate near `0x0057c950` was rejected as an instruction immediate/displacement byte inside the mouse handler, not a real branch to `0x0057c9b0`.

Positive controls:

- The legacy spell inventory vtable/read-only data range in `0x0062cfd8-0x0062d418` points into this executable island.
- `g_packetSender` references are easy to find elsewhere, and the direct packet route here uses the same `QueueAndSendPacket` funnel documented under Socket.
- Input pane constructor docs independently record the dispatcher calls from this island, matching the route table above.

## Heuristic / Inference Reanalysis And Validation

### Raw span heuristic

The old target inference treated the broad `0x0057cc42-0x0057ccd0` interval as switch data plus alignment. That was too coarse. The byte pattern has three distinct non-code/data/padding units followed by a complete helper:

1. `66 90` alignment at `0x0057cc42`.
2. Eight dword table entries at `0x0057cc44`.
3. `cc` padding at `0x0057cc64`.
4. A normal function prologue/security-cookie helper at `0x0057cc70`.

This validates the target as a mixed method/helper aggregate and invalidates any "all jump-table data" description for that interval.

### Ownership heuristic

Rejected owner alternatives:

- `SpellInputPanes.cpp`: rejected as direct owner. The dispatcher allocates spell input panes, but the dispatcher state, page fields, draw/mouse/key handlers, and row geometry are legacy inventory-pane behavior.
- `TargetSelectionInputPanes.cpp`: rejected as direct owner. One case uses target-selection behavior and the `SpellWhoInputPane` constructor, but that does not own the inventory dispatcher.
- `Socket`/packet subsystem: rejected as direct owner. It owns `QueueAndSendPacket` and `g_packetSender`, not the inventory activation policy.
- `g_pCollectionData`/collection-data subsystem: rejected as direct owner. It supplies spell table state but does not own UI dispatch and hit testing.
- File owner `0000O1` as canonical direct owner: acceptable as a broad source route, but less precise than class owner `0000DN` for this legacy class island.

Accepted owner:

- `SpellInventoryPane` class owner `0000DN` as canonical owner, with source file route `0000O1` (`NexusTK/ui/inventory/SpellInventoryPane.cpp`).

### Name heuristic

Names should prefer source-facing behavior over generated `sub_` labels:

- Constructor/destructor/draw/key/mouse/message names are class methods and match existing class docs.
- `CastSpell` is better than a generic `SpellDispatcher` because the function consumes an activated spell slot and either opens a prompt pane or sends a cast packet/action.
- Geometry helpers should be named by UI object: page buttons and spell rows, not generic rect helpers.
- `0x0057c430` should not remain unqualified as `SpellInputPaneState::SetInputModeFlag` without a caveat. The function is a pure setter on the legacy pane state byte used by this dispatcher; `SetSpellInputActiveFlag` or `SetPendingSpellInputFlag` is better supported for this target.

### Source-quality confidence check

High-confidence facts:

- Exact code/data/padding boundaries inside the target.
- The dispatcher jump-table entries and allocation/send route table.
- The direct opcode `0x0f` packet shape and two-byte send length.
- The row/page geometry constants.
- The `g_pCollectionData + 0x13a6ec + 0x148 * slot` spell table base, `0x148` stride, and one-based slot iteration/filtering behavior.
- The no-direct-route status for `0x0057cc70`, `0x0057cd60`, and `0x0057cdc0`.

Moderate-confidence facts:

- Exact source spelling for `CastSpell`, `BuildPageButtonRect`, and `FindSpellSlotForVisibleRow`. These are behavior-accurate names, but source symbol spellings are not externally confirmed.
- Exact class name behind `this+0xfc` and callee `0x004e9950`.
- Whether `0x0057c430` should be reparented from its current state-helper page or documented as a shared/cross-source setter with a better local name. The byte behavior is certain; the class ownership label needs supervisor consistency.

Low-confidence or rejected facts:

- A blanket `+0x13a82c` spell-record base for this dispatcher is not supported by the local recheck and should not be retained without byte proof.
- Treating `0x0057cc70-0x0057ccd0` as padding/alignment/switch data is rejected.
- Emitting aggregate-level C++ is rejected until child split, despite the reconstructable status.

## Best-Supported Names For Former `sub_` Helpers

| Current/raw name | Recommended name | Rationale |
|---|---|---|
| `sub_57C2D0` | `SpellInventoryPane::SpellInventoryPane()` | Vtable writes, legacy pane initialization, allocation of pane-owned helper/interface. |
| `sub_57C3A0` | `SpellInventoryPane::~SpellInventoryPane()` | Cleanup/destructor pattern and vtable restoration. |
| `sub_57C410` | `SpellInventoryPane::ResetPage()` | Clears page state and invalidates/refreshes. |
| `sub_57C430` | `SpellInventoryPane::SetSpellInputActiveFlag(bool)` | Pure setter for `[this+0xfa]`, used around prompt/input state. Existing generated state name should be revisited. |
| `sub_57C440` | `SpellInventoryPane::ForwardSpellEffect()` | Loads `[this+0xfc]` and tail-jumps to effect/interface method. |
| `sub_57C450` | `SpellInventoryPane::DrawSpells()` | Draws legacy spell inventory rows/buttons. |
| `sub_57C710` | `SpellInventoryPane::OnKeyDown()` | Handles page key input. |
| `sub_57C790` | `SpellInventoryPane::OnMouseDown()` | Hit-tests rows/buttons and activates spells. |
| `sub_57C980` | `SpellInventoryPane::OnMessage()` | Message/close handler. |
| `sub_57C9B0` | `SpellInventoryPane::CastSpell(uint8_t)` | Dispatches activated spell slot to prompt/direct send route. |
| raw `0x0057cc70` | `SendDirectSpellCastPacketRaw(uint8_t)` | No-route helper that emits opcode `0x0f` + spell slot. |
| `sub_57CCD0` | `BuildPageButtonRect(int, Rect *)` | Builds prev/next page button rectangles. |
| raw `0x0057cd60` | `BuildSpellRowRectRaw(int, Rect *)` | No-route helper that builds visible row rectangles. |
| raw `0x0057cdc0` | `HitTestPageButtonRaw(Point)` | No-route helper that tests page buttons. |
| `sub_57CE70` | `HitTestSpellRow(Point)` | Called row hit-test helper. |
| `sub_57CF10` | `FindSpellSlotForVisibleRow(int visibleOrdinal)` | Maps visible row ordinal to actual spell slot `1..52`. |

## First-Draft C++ Eligibility And No-Code Proof

The target passes the broad numeric gate if the recommended score is accepted: it is reconstructable, it has a supported class/file route, and `(COMPLETION + CONFIDENCE) / 2` is above 85. Formal aggregate C++ should still be deferred.

Exact no-code proof:

1. The target is not one source function. It contains constructor, destructor, reset helper, setter, effect forwarder, draw, key, mouse, message, dispatcher, jump table data, raw packet helper, page-button helper, row helper, button hit-test helper, row hit-test helper, and visible-row mapping helper.
2. The target contains non-code bytes that matter to control flow: dispatcher alignment and an eight-entry jump table at `0x0057cc42-0x0057cc64`.
3. The target contains retained no-route helper bodies at `0x0057cc70`, `0x0057cd60`, and `0x0057cdc0`. These should not be silently folded into the caller or emitted as if direct call routes were proved.
4. At least one subrange, `0x0057c430-0x0057c440`, already has a separate helper page and a contested/stale generated ownership label. Emitting aggregate C++ before resolving that split would bake in a questionable source model.
5. A single `RECONSTRUCTION_CPP` block would either mix unrelated class methods and file-local static helpers or hide the jump-table/raw-helper boundaries. That would reduce source quality even though individual children are reconstructable.

Recommendation: keep the aggregate `RECONSTRUCTION_CPP` blank with this no-code proof. If the implementation chooses to split the aggregate, individual children such as `CastSpell`, `SendDirectSpellCastPacketRaw`, `HitTestSpellRow`, and `FindSpellSlotForVisibleRow` can receive first-draft C++ after their exact ranges are established.

## Open Questions And Closure

| Question | Resolution |
|---|---|
| Is `0x0057cc42-0x0057ccd0` entirely jump-table/alignment material? | Closed. No. It contains alignment, the eight-entry jump table, padding, and a complete helper body at `0x0057cc70-0x0057ccd0`. |
| Does `0x0057cc70` have a live direct caller? | Closed for local static evidence. No rel32 call/jump/conditional branch, VA pointer, RVA pointer, or raw-offset pointer was found. Treat as retained no-route helper. |
| Are `0x0057cd60` and `0x0057cdc0` padding or helper bodies? | Closed. They are helper bodies: row-rect builder and page-button hit-test helper. No direct callers were found. |
| Is the dispatcher owned by `SpellInputPanes.cpp` because it constructs input panes? | Closed. No. It is owned by legacy `SpellInventoryPane`; input pane files own constructed prompt classes only. |
| Is the direct send route a Socket-owned helper? | Closed. No. Socket owns the send funnel and global sender, but the opcode/slot packet decision is legacy spell inventory behavior. |
| Should the target emit formal first-draft C++ now? | Closed. No, not at aggregate level. Split children first. |
| What is the exact source name for `0x0057c430`? | Partially closed. Byte behavior is a pure `[this+0xfa]` setter. Best local name is `SetSpellInputActiveFlag` or `SetPendingSpellInputFlag`; current `SpellInputPaneState::SetInputModeFlag` label should be corrected or explicitly caveated in support docs. |
| What is the exact source class behind `this+0xfc`/`0x004e9950`? | Remains open. Evidence supports a spell-effect/interface pointer, but exact type name is not defensibly proved here. This does not lower reconstructability of the target inventory. |
| What exact source spelling did the original code use for `CastSpell` and geometry helpers? | Remains open. Behavior names are strong, but symbol spellings are inferred. This affects naming confidence only, not range or behavior proof. |

## Proposed Score Rationale

Recommended score: `COMPLETION:88`, `CONFIDENCE:89`.

Why completion increases:

- Exact function, padding, jump-table, and raw-helper boundaries are now known.
- Dispatcher allocation/send cases are fully enumerated.
- Direct packet and targeted action routes are separated from prompt pane allocation.
- Stale `0x0057cc42-0x0057ccd0` wording is corrected.
- Source placement under `SpellInventoryPane` is stronger than current broad file-owner metadata.

Why not above low 90s:

- IDA MCP was unavailable, so this pass relies on local PE/Capstone and existing docs rather than an IDA function/xref database.
- Exact original source spellings are inferred, not symbol-proved.
- `this+0xfc` concrete type remains unresolved.
- Aggregate C++ remains deferred pending child split.

## Exact Supervisor-Owned Coverage Row

Do not edit `by-memory/-coverage-report.md` during this report task. If accepted, supervisor or implementation callback should replace the current row with:

```text
        - [UID:0002RI][0x0057c2d0-0x0057cf6b.SpellInventoryPaneLegacyCoreAndHelpers](by-memory/0x0057c2d0-0x0057cf6b.SpellInventoryPaneLegacyCoreAndHelpers.md) 0x0057c2d0-0x0057cf6b | method/helper-group | SpellInventoryPaneLegacyCoreAndHelpers : reconstructable : 88% : strong : Source-quality reanalysis validates the legacy SpellInventoryPane constructor/destructor/reset/draw/key/mouse/message/cast-dispatch island, corrects the 0x0057cc42-0x0057ccd0 span into dispatcher alignment, eight-entry jump table, padding, and retained no-route direct-cast packet helper at 0x0057cc70-0x0057ccd0, adds raw helper ranges at 0x0057cd60-0x0057cdb3 and 0x0057cdc0-0x0057ce68, documents page/row geometry and visible-row-to-slot helpers through 0x0057cf6b, resolves prompt-pane allocation and direct opcode 0x0f/targeted-action send routes, recommends class owner [UID:0000DN] with source file [UID:0000O1], and keeps formal C++ deferred until exact child split because the aggregate mixes multiple methods, jump-table data, and raw no-route helpers.
```

## Target Implementation Checklist

For accepted implementation, update only with leases and normal validator flow:

- Update target metadata to `COMPLETION:88`, `CONFIDENCE:89`, `CANONICAL_OWNER:0000DN`, `EMITTER_UIDS:0000DN`, with source-file route still documented as `0000O1`.
- Replace the old `0x0057cc42-0x0057ccd0` description with the exact alignment/table/padding/helper breakdown.
- Add exact function/padding inventory from this report, including corrected `OnMouseDown` end at `0x0057c979`, `OnMessage` at `0x0057c980-0x0057c9a8`, `HitTestSpellRow` end at `0x0057cf03`, and raw helper ranges.
- Add the exact eight-entry jump table values.
- Document direct opcode `0x0f` packet route: opcode byte, spell slot byte, cleared non-transmitted local byte, `QueueAndSendPacket(g_packetSender, packet, 2)`.
- Document targeted action route through `SendTargetedActionPacket` and active map/target checks.
- Replace or caveat old spell-record offset prose that cannot be supported by this recheck, especially the old `+0x13a82c` claim.
- Rename/cross-reference helpers currently left as `sub_` using the best-supported names table above.
- Keep aggregate `RECONSTRUCTION_CPP` blank and insert the exact no-code proof, or split into exact children first before emitting C++ for individual functions.
- Resolve `0x0057c430` support docs so the pure setter is not misleadingly documented as a generic input-pane state method without the legacy `SpellInventoryPane` field evidence.

Suggested future child split if implementation scope allows:

```text
0x0057c2d0-0x0057c39f  SpellInventoryPaneConstructor
0x0057c3a0-0x0057c401  SpellInventoryPaneDestructor
0x0057c410-0x0057c425  SpellInventoryPaneResetPage
0x0057c430-0x0057c440  SpellInventoryPaneSetSpellInputActiveFlag
0x0057c440-0x0057c44b  SpellInventoryPaneForwardSpellEffect
0x0057c450-0x0057c710  SpellInventoryPaneDrawSpells
0x0057c710-0x0057c78c  SpellInventoryPaneOnKeyDown
0x0057c790-0x0057c979  SpellInventoryPaneOnMouseDown
0x0057c980-0x0057c9a8  SpellInventoryPaneOnMessage
0x0057c9b0-0x0057cc42  SpellInventoryPaneCastSpell
0x0057cc42-0x0057cc70  SpellInventoryPaneCastSpellJumpTableAndAlignment
0x0057cc70-0x0057ccd0  SendDirectSpellCastPacketRaw
0x0057ccd0-0x0057cd51  BuildPageButtonRect
0x0057cd60-0x0057cdb3  BuildSpellRowRectRaw
0x0057cdc0-0x0057ce68  HitTestPageButtonRaw
0x0057ce70-0x0057cf03  HitTestSpellRow
0x0057cf10-0x0057cf6b  FindSpellSlotForVisibleRow
```

Padding intervals should be added to `by-memory/-ignored.md` only during accepted implementation, not during this report-only pass.

## Support Documentation Checklist

If accepted, update these support docs at report-level detail:

- `by-memory/0x0057c2d0-0x0057cf6b.SpellInventoryPaneLegacyCoreAndHelpers.md`: full metadata/range/name/field/jump-table/packet-flow update and formal C++ defer proof.
- `by-memory/0x0057c2d0-0x0057f742.SpellInventoryPanes.md`: update `0002RI` child summary, correct child non-padding spans, and record raw helper bodies at `0x0057cc70`, `0x0057cd60`, and `0x0057cdc0`.
- `by-class/SpellInventoryPane.md`: update method inventory and field map for `+0xf8`, `+0xf9`, `+0xfa`, `+0xfc`; include dispatcher route table and row/page helper names.
- `by-file/SpellInventoryPane.md`: keep source file placement in `NexusTK/ui/inventory/SpellInventoryPane.cpp`; add exact legacy dispatcher behavior, raw helper no-route evidence, and corrected jump-table span.
- `by-file/SpellInputPanes.md`: document that the legacy inventory dispatcher allocates the string/four/three/two/one/slot prompt panes but does not transfer dispatcher ownership to this file.
- `by-file/TargetSelectionInputPanes.md`: document the `SpellWhoInputPane` allocation route and targeted-action special case as dependencies of legacy spell inventory dispatch, not direct ownership of `0002RI`.
- `by-class/SpellInputPaneState.md` and `by-memory/0x0057c430-0x0057c43f.SpellInputPaneStateSetFlag.md`: correct or caveat the current `SpellInputPaneState::SetInputModeFlag` name using the pure `[this+0xfa]` legacy `SpellInventoryPane` pending-input flag evidence.
- `by-memory/0x005af4f0-0x005af57b.SendTargetedActionPacket.md`: add or verify the `0x0057caa7` legacy `SpellInventoryPane::CastSpell` caller and clarify that it is the targeted spell action route.
- `by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md` and `by-global/g_packetSender.md`: add legacy direct spell packet examples if needed: inline case at `0x0057cb50` and retained raw helper at `0x0057cc70`.
- `by-global/g_pCollectionData.md` and `by-memory/0x0067a748-0x0067a74c.g_pCollectionData.md`: add the spell table usage with `0x148` stride, learned flag, route/type field, and one-based slot iteration; avoid unsupported `SpellManager` naming.
- `by-memory/0x0062cfd8-0x0062d418.SpellInventoryMacroReadOnlyData.md`: no required ownership change; optional cross-reference to the validated legacy vtable entries.
- `by-memory/-ignored.md`: only during accepted implementation, add padding corrections if child split occurs. Do not edit this in report-only mode.
- `by-memory/-coverage-report.md`: supervisor-owned only. Use the exact row above if accepted.

## Scoped Validator Baseline

Command run:

> Executable block R001 was removed from this report and preserved verbatim in [0002RI-SpellInventoryPaneLegacyCoreAndHelpers-source-quality-removed.md](0002RI-SpellInventoryPaneLegacyCoreAndHelpers-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Result:

```text
exit code: 0
mode: file
apply: False
scanned markdown files: 1
ok: 1
ok 0002RI by-memory/0x0057c2d0-0x0057cf6b.SpellInventoryPaneLegacyCoreAndHelpers.md UID header exists
dry run only; pass --apply to write changes
```

The validator also reported a dry-run generated coverage update target (`auto-generated/-ag-memory-coverage.md`). No files were written because `--apply` was not used.

## Rejected Alternatives

- `0x0057cc70-0x0057ccd0` as padding: rejected by complete function body and packet-send behavior.
- `0x0057cd60-0x0057cdb3` and `0x0057cdc0-0x0057ce68` as padding: rejected by valid helper bodies.
- `SpellInputPanes.cpp` as owner: rejected because constructed prompt panes are dependencies, not dispatcher owner.
- `TargetSelectionInputPanes.cpp` as owner: rejected because only the who/targeted-action branch belongs there.
- `Socket` as owner: rejected because direct packet content and spell activation policy are inventory-pane behavior.
- `SpellManager`/`g_pSpellMan` naming for `dword_67A748`: rejected by broad global documentation and cross-domain usage.
- Formal aggregate first-draft C++: rejected until exact child split because the target mixes class methods, data table, padding, and retained no-route helpers.

## Report-Only Status

This file is the only intended output of the current pass. The accepted implementation should apply the target/support documentation changes with leases and scoped validation. No `by-*` documentation file or `by-memory/-coverage-report.md` should be changed by this report-only assignment.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B007","command_id":"000000004165","destination_path":"executed-b-agent-research/B007/0002RI-SpellInventoryPaneLegacyCoreAndHelpers-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:32","uid":"0002RI"} -->
<!-- {"agent":"B007","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002RI-SpellInventoryPaneLegacyCoreAndHelpers-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B007/0002RI-SpellInventoryPaneLegacyCoreAndHelpers-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002RI"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
