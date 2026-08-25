** TARGET-REPORT-UID:0001GM **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0001GM ScrollSpellInventoryPane Source-Quality Reanalysis

Assignment: B002 report-only source-quality pass  
Agent: Agent-B002  
Target: [UID:0001GM] `by-memory/0x0055f450-0x005608fc.ScrollSpellInventoryPane.md`  
Report path: `tools/leaser/Agents/Agent-B002/research/0001GM-ScrollSpellInventoryPane-source-quality.md`  
Date: 2026-06-19

No `by-*` documentation and no `by-memory/-coverage-report.md` file were edited by this report pass.

## Finalized Report / Current Recommendation

Current recommendation:

```text
Keep [UID:0001GM] as a source-authored ScrollSpellInventoryPane class aggregate directly owned by [UID:0000CN] ScrollSpellInventoryPane.
Keep source-file route through [UID:0000NJ] ScrollSpellInventoryPane.
Do not emit monolithic aggregate C++ from [UID:0001GM].
Use exact child pages for method bodies and raw helper bodies.
```

Recommended target metadata after implementation of this report's evidence:

```text
COMPLETION: 86
CONFIDENCE: 88
CANONICAL_OWNER: 0000CN
RECONSTRUCTABLE: TRUE
EMITTER_UIDS: 0000CN
EMITTER_POSITION_OPTIONAL:
RECONSTRUCTION_CPP CODE: blank
```

Rationale for the modest score change:

- Completion can move from `85` to `86` after the target page records the missing raw setter/disable/predicate pockets at `0x0055f500`, `0x0055f530`, `0x0055f610`, and `0x0055f630`, the exact padding inventory, and the aggregate no-code proof.
- Confidence can move from `87` to `88` after the target records the current local PE and IDA-listing baseline that corroborates prior live-IDA-backed boundaries.
- Do not raise higher yet. Current-session live IDA MCP is unavailable, several raw helper source names remain descriptive rather than proven, [UID:0001GN] still lacks final C++, and many modeled methods in the aggregate do not yet have exact child pages.

Final disposition:

```text
Report-only, accepted direction should trigger an implementation callback.
Implementation should update the target/support docs at report-level detail and should not touch coverage directly.
```

Confidence in recommendation: strong for range, class ownership, file route, layout/vtable anchors, reset-helper route, and aggregate no-code policy; medium-high for the final standalone `ScrollSpellInventoryPane.cpp` versus private fold into `NewSpellInventoryPane.cpp`; medium for final source names of the early raw setters and the false-return/input bridge helpers.

## Supporting Research

## Target

- Target UID: `0001GM`
- Target path: `by-memory/0x0055f450-0x005608fc.ScrollSpellInventoryPane.md`
- Current target score: `85/87`
- Current target owner/emitter: [UID:0000CN] `ScrollSpellInventoryPane`
- Current generated source route: [UID:0000CN] -> [UID:0000NJ] -> `auto-generated/NexusTK/ui/inventory/ScrollSpellInventoryPane.cpp`
- Current generated status: `auto-generated/-ag-memory-coverage.md` lists [UID:0001GM] as `emits` with no C++ body. The generated file contains [UID:0001GO] `ResetScrollState()` plus empty markers for [UID:0000CN], [UID:0001GM], [UID:0001GN], vtable data, layout, and vtable support.

The target is an aggregate over a class method island, not one callable function. It contains modeled IDA functions, raw method-shaped pockets, internal `0xcc` alignment, and two existing exact source-bearing child pages:

- [UID:0001GN] `0x00560710-0x0056089d.ScrollSpellInventoryPaneUpdateFromDrag`
- [UID:0001GO] `0x005608a0-0x005608fc.ScrollSpellInventoryPaneResetScrollStateRaw`

## Supervisor Active Recheck

The user assigned a report-only B002 source-quality pass for [UID:0001GM] and explicitly banned edits to `by-*` docs and `by-memory/-coverage-report.md`. This report therefore records exact recommended implementation and supervisor-owned coverage text but does not apply it.

The target does not need a boundary rename. It does need a stronger child split/status section and no-code proof because the current target page still compresses several raw helper pockets into broad prose.

## Inference Research Guidance Check

Rules applied:

- Use the narrowest semantic owner. Class methods and class layout/vtable data should attach to the class when the class parent clears the gate.
- Do not treat generated source labels or generated file placement as authoritative.
- Source C++ may be recommended only when the item is reconstructable, has a valid emitter route, and `(COMPLETION + CONFIDENCE) / 2 > 85`, but that is only a minimum gate. Boundaries, source placement, names, dependencies, and no-overlap rules still control.
- A by-memory aggregate must not emit a monolithic block that duplicates child method bodies or smears multiple methods/padding/raw islands into one source body.
- For exact child bodies, prefer child pages. For class declaration C++, prefer the class page, not this memory aggregate.

Evidence classes used:

- Existing live-IDA-backed target/support documentation.
- Current local IDA listing export at `C:\Users\admin\Desktop\CTools\CPlusPlusSim\core\extra-sources\IDA-EXPORTS\NexusTK.exe.lst`.
- Current read-only PE bytes at `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
- Current generated coverage and generated source reports.
- Dry-run validator baseline for the target.

Current-session live IDA MCP was checked and is unavailable:

```text
MCP_ERROR: Unable to connect to the remote server
```

Therefore this report does not claim fresh live IDA decompilation. It uses existing IDA-backed docs plus a fresh local PE/listing corroboration.

## Heuristic / Inference Reanalysis And Validation

### Aggregate Boundary

Accepted boundary:

```text
0x0055f450-0x005608fc
```

Evidence:

- Predecessor [UID:0001GL] `ScrollablePaneCore` ends at `0x0055f44f`.
- `0x0055f44f-0x0055f450` is one `0xcc` byte.
- `0x0055f450` begins IDA-modeled `sub_55F450`, the first ScrollSpellInventoryPane constructor body.
- `0x005608fc-0x00560900` is four `0xcc` bytes.
- `0x00560900` begins the next modeled `ScrollNewGroupPane` constructor/function family.

Fresh local PE byte baseline:

```text
0x0055f44f-0x0055f450: cc
0x0056089d-0x005608a0: cc cc cc
0x005608fc-0x00560900: cc cc cc cc
```

Decision:

```text
Keep the target range.
Do not extend into ScrollablePaneCore.
Do not extend to 0x00560900.
Do not merge with ScrollNewGroupPane.
```

### Full Child / Pocket Inventory

The current target page lists the major function families but should explicitly record the following exact split inventory. Existing child pages already exist only for [UID:0001GN] and [UID:0001GO].

| Range | Current status | Best source-facing role | Split action |
| --- | --- | --- | --- |
| `0x0055f450-0x0055f4f1` | modeled function `sub_55F450` | `ScrollSpellInventoryPane::ScrollSpellInventoryPane(...)` constructor | Create exact child when implementation callback authorizes split. |
| `0x0055f4f1-0x0055f500` | padding | `0xcc` alignment | Record as ignored padding if aggregate is split into rows. |
| `0x0055f500-0x0055f527` | raw method-shaped setter | inferred `SetSizeIndex` / `SetScrollbarSizeIndex`; updates `+0xf8` word and invalidates on change | Create exact raw child; keep name descriptive until source naming settles. |
| `0x0055f527-0x0055f530` | padding | `0xcc` alignment | Record as ignored padding if split. |
| `0x0055f530-0x0055f554` | raw method-shaped setter | inferred `SetScrollStyleByte` / `SetStateByte`; updates unresolved `+0xfa` byte and invalidates on change | Create exact raw child; exact name blocked by unresolved `+0xfa` semantics. |
| `0x0055f554-0x0055f560` | padding | `0xcc` alignment | Record as ignored padding if split. |
| `0x0055f560-0x0055f5bb` | modeled function `sub_55F560` | `SetMaxRange` | Create exact method child. |
| `0x0055f5bb-0x0055f5c0` | padding | `0xcc` alignment | Record as ignored padding if split. |
| `0x0055f5c0-0x0055f5e7` | modeled function `sub_55F5C0` | `SetScrollPosition` | Create exact method child. |
| `0x0055f5e7-0x0055f5f0` | padding | `0xcc` alignment | Record as ignored padding if split. |
| `0x0055f5f0-0x0055f60a` | modeled function `sub_55F5F0` | `Activate` / `Show` | Create exact method child. |
| `0x0055f60a-0x0055f610` | padding | `0xcc` alignment | Record as ignored padding if split. |
| `0x0055f610-0x0055f62a` | raw method-shaped helper | inferred `Deactivate` / `Hide`; clears enabled byte `+0x102` and invalidates if active | Create exact raw child. |
| `0x0055f62a-0x0055f630` | padding | `0xcc` alignment | Record as ignored padding if split. |
| `0x0055f630-0x0055f64a` | raw method-shaped predicate | inferred `CanScroll` / `IsScrollable`; tests enabled byte and range | Create exact raw child. |
| `0x0055f64a-0x0055f650` | padding | `0xcc` alignment | Record as ignored padding if split. |
| `0x0055f650-0x0055f831` | modeled function `sub_55F650` | `HandleMouseEvent` / mouse handler | Create exact method child. |
| `0x0055f831-0x0055f840` | padding | `0xcc` alignment | Record as ignored padding if split. |
| `0x0055f840-0x0055f845` | modeled five-byte virtual | false-return input/event virtual | Create exact child or document as class virtual stub; source-authored override, not compiler padding. |
| `0x0055f845-0x0055f850` | padding | `0xcc` alignment | Record as ignored padding if split. |
| `0x0055f850-0x0055f883` | modeled function `sub_55F850` | `OnScrollRepeat` / timer-repeat handler | Create exact method child. |
| `0x0055f883-0x0055f890` | padding | `0xcc` alignment | Record as ignored padding if split. |
| `0x0055f890-0x0055ff70` | modeled function `sub_55F890` | `OnPaint` | Create exact method child. |
| `0x0055ff70-0x0056028d` | modeled function `sub_55FF70` | inferred `HitTestPart` / `ResolvePartAtPoint` | Create exact method child; final public name unresolved. |
| `0x0056028d-0x00560290` | padding | `0xcc` alignment | Record as ignored padding if split. |
| `0x00560290-0x00560517` | modeled function `sub_560290` | `GetPartRect(char part, RectBounds *outRect)` | Create exact method child. |
| `0x00560517-0x00560520` | padding | `0xcc` alignment | Record as ignored padding if split. |
| `0x00560520-0x00560590` | raw method-shaped helper | `SetHoverPart(char part)` | Create exact raw child; source role is strong. |
| `0x00560590-0x0056064f` | raw method-shaped helper | inferred `SetActivePartAndStartDrag` / `BeginInteraction`; sets `m_activePart`, drag anchor, schedules timer | Create exact raw child; final name descriptive. |
| `0x0056064f-0x00560650` | padding | one `0xcc` byte | Record as ignored padding if split. |
| `0x00560650-0x00560710` | modeled function `sub_560650` | input drag bridge / active-part dispatcher | Create exact method child. |
| `0x00560710-0x0056089d` | existing [UID:0001GN] | `UpdateFromDrag` | Keep exact child; consider a separate C++ pass. |
| `0x0056089d-0x005608a0` | padding | three `0xcc` bytes | Already documented in support. |
| `0x005608a0-0x005608fc` | existing [UID:0001GO] | `ResetScrollState` | Keep exact child with C++; route stays through [UID:0000CN]. |

This inventory is the main target-page gap. The current page is correct at the aggregate level but too compact for the source-quality standard because it hides early raw setters and the `0x0055f610`/`0x0055f630` disable/predicate pocket.

### Raw Helper Route Reanalysis

Fresh local PE scan checked direct rel32 call/jump targets and VA/RVA dword references for the three raw starts most relevant to this assignment:

```text
0x00560520 direct rel32 hits: 0
0x00560590 direct rel32 hits: 0
0x005608a0 direct rel32 hits: 0
0x00560520 VA dword hits: 0; RVA dword hits: 0
0x00560590 VA dword hits: 0; RVA dword hits: 0
0x005608a0 VA dword hits: 0; RVA dword hits: 0
```

Positive controls worked:

```text
0x00560710 direct rel32 hits: 2, from 0x005606ab and 0x005606d4
0x00560290 direct rel32 hits: 13
0x00560650 direct rel32 hits: 3
```

Interpretation:

- The absence of direct routes to raw starts is meaningful, not a failed scan.
- The raw hover/active/reset pockets still appear source-authored because they have complete method-shaped bodies, use class fields, call class-local helpers, and sit in aligned class method order.
- No static direct caller/table/vtable route should be claimed for those raw starts until fresh IDA or dynamic evidence proves one.
- The no-route caveat limits final-audit confidence but does not force file ownership or generic scrollbar ownership.

### Class Versus File Source Placement

Accepted direct semantic owner:

```text
[UID:0000CN] ScrollSpellInventoryPane
```

Evidence:

- The aggregate operates on a `0x110` byte object constructed as a `ScrollSpellInventoryPane`.
- Constructor stores vtables at `0x00623e94`, `0x00623ee0`, and `0x00623f10`.
- Layout offsets `+0xf8` through `+0x10f` are class tail fields.
- Existing exact children [UID:0001GN] and [UID:0001GO] are class methods.
- The raw helper pockets use `m_hoverPart`, `m_activePart`, the `+0xa4` timer view, class-local `GetPartRect`, and Pane invalidation.

Accepted source-file route:

```text
[UID:0000NJ] ScrollSpellInventoryPane
auto-generated/NexusTK/ui/inventory/ScrollSpellInventoryPane.cpp
```

Evidence:

- [UID:0000NJ] is the reviewed file root at `86/88`.
- Proposed source tree lists `ui/inventory/ScrollSpellInventoryPane.cpp`.
- [UID:0000CN] routes through [UID:0000NJ].
- Generated coverage routes this family to `auto-generated/NexusTK/ui/inventory/ScrollSpellInventoryPane.cpp`.

Rejected direct owner:

```text
[UID:0000NJ] ScrollSpellInventoryPane file
```

Reason:

- The file is the route, not the narrowest semantic owner. This aggregate and its exact children are class method bodies and class layout support. Direct file ownership would bypass the class.

Rejected direct owner:

```text
[UID:0000LU] NewSpellInventoryPane / [UID:00009A] NewSpellInventoryPane class
```

Reason:

- `NewSpellInventoryPane` is the only observed constructor caller and may be the final fold destination, but the touched fields and vtables are `ScrollSpellInventoryPane` fields and vtables. Constructor-only use proves private companion relationship, not method ownership.

Rejected direct owner:

```text
[UID:0000O1] SpellInventoryPane file family root
```

Reason:

- The broader spell-inventory file family owns the feature domain, but [UID:0000NJ] and [UID:0000CN] are narrower and already clear the gate.

Rejected direct owner:

```text
[UID:0000NF] ScrollBar / generic scrollbar infrastructure
```

Reason:

- The class resembles item, collection, group, and volume scrollbars, but this body uses spell-inventory-specific class vtables, layout offsets, and `NewSpellInventoryPane` construction. Generic scrollbar is a conceptual pattern and dependency family, not the exact source owner.

Rejected direct owner:

```text
TimerHandler / TimerMgr
```

Reason:

- `0x00597600` and `0x005975e0` are outgoing timer dependencies through the `+0xa4` view. They do not own the scroll-control state machine.

### Layout, Vtable, And Member Names

Best-supported member names for implementation docs:

| Offset | Recommended name / type | Status |
| --- | --- | --- |
| `+0xa4` | tertiary `TimerHandler` / timer-update handler view | Strong. Constructor installs vtable `0x00623f10`; repeat/reset paths schedule/remove timers through this view. |
| `+0xf8` | scrollbar size / skin-table index word | Strong role, exact source name open. Paint/geometry index the `dword_624144` size table through the low halfword. |
| `+0xfa` | unresolved style/state byte | Open. Raw setter at `0x0055f530` updates it and invalidates; existing docs correctly avoid a final name. Best descriptive phrase: `m_scrollStyleByte` or `m_scrollStateByte`, not final. |
| `+0xfb` | drag-position override flag | Medium-high. Paint/geometry test it before deriving thumb position from the drag anchor. |
| `+0xfc` | orientation | Strong. `0` vertical, nonzero horizontal. |
| `+0xfe` | current scroll position | Strong. |
| `+0x100` | max scroll range / spell count range | Strong. |
| `+0x102` | enabled/visible byte | Strong. Activation/deactivation helpers set/clear it and invalidate. |
| `+0x103` | `char m_hoverPart` | Strong. B002 reset pass resolved this; `0xff` / `-1` is no-part. |
| `+0x104` | `char m_activePart` | Strong. Begin/drag/reset paths use it as the current tracked/pressed part; generated `m_prevActivePart` wording is rejected. |
| `+0x108` | drag anchor point | Strong. Drag/update paths use `+0x108/+0x10c`. |

Vtable facts:

```text
0x00623e94 primary view at object +0x00
0x00623ee0 secondary input/event view at object +0xa0
0x00623f10 tertiary timer/update view at object +0xa4
```

Notable slot names:

- Primary `+0x44` -> `0x0055f890`, `OnPaint`.
- Secondary `+0x04` -> `0x0055f650`, mouse input handler.
- Secondary `+0x08` -> `0x0055f840`, false-return virtual.
- Secondary `+0x34` -> `0x0055f850`, repeat/timer handler.
- Tertiary `+0x04` -> `0x0055f850`, same repeat/timer handler through timer view.

Do not add a vtable route for `0x005608a0`; [UID:0001GO] is a non-virtual ordinary helper.

### Final Reset-Helper Route

Final route for [UID:0001GO] remains:

```text
CANONICAL_OWNER: 0000CN
EMITTER_UIDS: 0000CN
Source-facing method: void ScrollSpellInventoryPane::ResetScrollState()
Source-file route: 0000NJ / ScrollSpellInventoryPane.cpp
```

This is now closed. It should not be reopened as an aggregate split blocker.

What remains true:

- IDA does not model `0x005608a0` as a function.
- There is no direct static caller, VA/RVA literal, vtable slot, pointer table, or external branch into the raw reset span.
- That caveat limits final-audit scoring and IDA function creation, but it no longer blocks [UID:0001GO] C++ because the child now owns exact first-draft source.

### First-Draft C++ Eligibility / Exact No-Code Proof

[UID:0001GM] clears the numeric gate:

```text
RECONSTRUCTABLE: TRUE
EMITTER_UIDS: 0000CN
(85 + 87) / 2 = 86.0
```

However, formal aggregate C++ must remain blank.

Exact no-code proof:

- The target is not one function. It is a class aggregate containing constructor, raw setters, range/position helpers, activation/deactivation helpers, input handlers, paint, hit-test, geometry, hover/active raw helpers, update-from-drag, reset-state, and many padding spans.
- A monolithic C++ block on [UID:0001GM] would either duplicate child bodies [UID:0001GN] and [UID:0001GO] or omit source-bearing methods that are still only described in the aggregate.
- Several raw helper starts are not IDA-modeled functions and have no direct route: `0x0055f500`, `0x0055f530`, `0x0055f610`, `0x0055f630`, `0x00560520`, `0x00560590`, and `0x005608a0`.
- The exact source names for `+0xfa`, `0x0055f840`, `0x0055ff70`, and `0x00560650` are still descriptive and should not be frozen inside broad aggregate source.
- By-memory C++ must be limited to the page's own range and source shape. The correct source shape here is an inventory of child methods, not a single compilable method or declaration.
- Class declaration C++ belongs on [UID:0000CN], if and when the class declaration is ready. Method body C++ belongs on exact by-memory child pages.

Allowed future source strategy:

```text
Create exact children for every modeled/raw method pocket.
Put first-draft C++ on children that clear the code gate and source-quality checks.
Optionally give [UID:0000CN] a declaration-level class shell with [[CHILDREN]] after class/header source questions settle.
Keep [UID:0001GM] as a blank aggregate/source inventory page.
```

Rejected aggregate C++ alternatives:

- `[[CHILDREN]]` directly in [UID:0001GM]: rejected for now because exact children already route through the class [UID:0000CN]. The class page, not this by-memory aggregate, is the right declaration/insertion point if a marker is needed.
- One giant class implementation block in [UID:0001GM]: rejected because it would mix multiple methods, padding, and children in one memory page.
- Emitting only the reset/update children from [UID:0001GM]: rejected because those already have their own pages/routes.

### Open Questions

Closed by this pass:

- Aggregate boundary: keep `0x0055f450-0x005608fc`.
- Direct owner: [UID:0000CN] class, not file root or NewSpellInventoryPane.
- File route: [UID:0000NJ] `ScrollSpellInventoryPane.cpp`, with fold caveat preserved.
- Reset-helper route: [UID:0001GO] class-owned, emitted, source-facing `ResetScrollState`.
- Raw hover/reset direct-route issue: no static direct/VA/RVA route found for representative raw starts; no-route caveat remains documented.
- Vtable route to reset helper: rejected.

Still open with exact impact:

- `+0xfa` source name: evidence proves a byte setter/invalidation role but not semantic name. Cap target/source declaration confidence; use descriptive `scroll state/style byte` wording only.
- Exact source names for `0x0055f500`, `0x0055f530`, `0x0055f610`, `0x0055f630`, `0x0055f840`, `0x0055ff70`, and `0x00560650`: high-probability roles exist, exact original spelling does not.
- `ScrollSpellInventoryPane.cpp` versus private fold into `NewSpellInventoryPane.cpp`: current route stays standalone [UID:0000NJ]; one-constructor-caller evidence keeps fold candidate open.
- [UID:0001GN] first-draft C++: current score/emitter route is eligible, but branch-level formulas and final helper/field names should be rechecked in a focused pass before inserting code.
- Class declaration C++ for [UID:0000CN]: possible future support pass, but not required to resolve this aggregate.
- Fresh live IDA: unavailable in this session; no current decompile/body edits are claimed.

## Evidence Standards Used

Evidence considered strong:

- Existing target/support pages with repeated live IDA MCP evidence.
- IDA listing export showing exact `proc` starts, raw starts, `align 10h`, returns, and successor boundaries.
- Read-only PE byte checks proving padding and raw start boundaries.
- Read-only PE route checks with positive controls.
- Validator dry-run for the target.

Evidence considered inference:

- Descriptive source names for raw setters and input helpers.
- Final standalone file versus private fold.
- Class declaration readiness.

Evidence rejected:

- Generated source ownership pollution.
- Consumer-only `NewSpellInventoryPane` constructor evidence as direct ownership.
- Generic scrollbar similarity as exact owner.
- Timer helper calls as TimerHandler ownership of scroll state.

## IDA / PE Facts

Current-session MCP:

```text
tools/list at http://127.0.0.1:13337/mcp failed: Unable to connect to the remote server.
```

Local PE baseline:

```text
File: E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe
MD5: 4247e04e20b65d6414c7238aa8ff5515
SHA1: c285b73dc7b54c9a0e28ff7591a9bdde2ac55f9a
Image base: 0x00400000
.text: 0x00401000-0x0060c600
```

IDA listing export corroborates modeled starts:

```text
sub_55F450 at 0x0055f450
sub_55F560 at 0x0055f560
sub_55F5C0 at 0x0055f5c0
sub_55F5F0 at 0x0055f5f0
sub_55F650 at 0x0055f650
sub_55F840 at 0x0055f840
sub_55F850 at 0x0055f850
sub_55F890 at 0x0055f890
sub_55FF70 at 0x0055ff70
sub_560290 at 0x00560290
sub_560650 at 0x00560650
sub_560710 at 0x00560710
sub_560900 at 0x00560900
```

IDA listing export also shows raw method-shaped pockets:

```text
0x0055f500 raw setter, returns at 0x0055f524 and aligns at 0x0055f527
0x0055f530 raw setter, returns at 0x0055f551 and aligns at 0x0055f554
0x0055f610 raw enabled/disable helper, returns at 0x0055f629 and aligns at 0x0055f62a
0x0055f630 raw predicate, returns at 0x0055f649 and aligns at 0x0055f64a
0x00560520 raw hover helper, returns `retn 4` at 0x0056058d
0x00560590 raw active/drag helper, returns `retn 0Ch` at 0x0056064c
0x005608a0 raw reset helper, returns at 0x005608fb and aligns at 0x005608fc
```

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0055f450-0x005608fc` | [UID:0001GM] target | class aggregate | TRUE | [UID:0000CN] | proposed `86/88` | Keep aggregate, no formal C++. |
| `0x00560710-0x0056089d` | [UID:0001GN] | `UpdateFromDrag` | TRUE | [UID:0000CN] | `87/89` | Exact child exists; C++ still blank. |
| `0x005608a0-0x005608fc` | [UID:0001GO] | `ResetScrollState` | TRUE | [UID:0000CN] | `87/89` | Exact child exists; C++ populated. |
| all other method/raw pockets | pending children | constructor, setters, range/position, input, paint, geometry, hover/active helpers | likely TRUE | [UID:0000CN] | not scored individually | Need split implementation callback before child scoring. |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0055f450` | one documented direct caller at `0x0057d013` inside `NewSpellInventoryPane::NewSpellInventoryPane` | Constructor-private spell scrollbar companion. |
| `0x0055f5f0` | activation caller in `NewSpellInventoryPane` constructor path | New pane constructs and activates child scrollbar. |
| `0x00560710` | direct calls from `0x005606ab` and `0x005606d4` | `UpdateFromDrag` is live through input bridge. |
| `0x00560290` | 13 direct rel32 hits in local PE scan | Shared within class for part-rect invalidation/geometry. |
| `0x00560520` | zero direct rel32/VA/RVA hits in local scan | Raw helper remains no-static-route. |
| `0x00560590` | zero direct rel32/VA/RVA hits in local scan | Raw helper remains no-static-route. |
| `0x005608a0` | zero direct rel32/VA/RVA hits in local scan | Reset child remains no-static-route. |

## Documentation Evidence And IDA Status

Supporting docs:

- [UID:0000CN] `ScrollSpellInventoryPane` class is `86/88`, owner/emitter [UID:0000NJ].
- [UID:0000NJ] `ScrollSpellInventoryPane` file is `86/88`, projected to `NexusTK/ui/inventory/`.
- [UID:0001W1] layout is `85/88`, owner/emitter [UID:0000CN].
- [UID:0001YS] vtables are `85/90`, owner/emitter [UID:0000CN].
- [UID:0001GO] reset child is `87/89`, owner/emitter [UID:0000CN], C++ populated.
- [UID:0000LU] `NewSpellInventoryPane` is `86/88` and records the child scrollbar as a private companion/fold candidate.

Stale/incomplete target points:

- The target's covered-range table should explicitly include the early raw setters and `0x0055f610`/`0x0055f630` raw helpers.
- The target's broad "range and activation helpers" phrase hides source-bearing raw code.
- The target should replace older no-code wording with current child-split/no-code proof under the active code-entry gate.

Generated/coverage state:

- [UID:0001GM] appears in `auto-generated/-ag-memory-coverage.md` as `emits`, no C++.
- [UID:0001GN] appears as `emits`, no C++.
- [UID:0001GO] appears as `coded`, yes C++.
- Generated `ScrollSpellInventoryPane.cpp` contains [UID:0001GO] C++ and empty markers for [UID:0000CN], [UID:0001GM], [UID:0001GN], [UID:0003CM], [UID:0001W1], and [UID:0001YS].

## Ranked Ownership Analysis

### 1. [UID:0000CN] ScrollSpellInventoryPane

Evidence for:

- Exact class field and vtable usage.
- Existing child ownership pattern.
- Class parent clears gate at `86/88`.
- Source-file route clears gate through [UID:0000NJ].

Evidence against:

- Only one observed constructor caller from `NewSpellInventoryPane`.
- Some raw starts have no static route.

Decision:

```text
Accepted direct owner/emitter.
```

### 2. [UID:0000NJ] ScrollSpellInventoryPane File

Evidence for:

- Current generated route and source-tree placement.
- Reviewed `86/88` file page.
- Dedicated file hypothesis consistent with sibling `InventoryScrollPane`.

Evidence against:

- Not the narrowest semantic owner for class methods.

Decision:

```text
Accepted route, rejected direct canonical owner for target/method children.
```

### 3. [UID:0000LU] NewSpellInventoryPane

Evidence for:

- Sole documented constructor caller allocates and activates the scrollbar.
- Final source may have folded private scrollbar implementation into the new pane source.

Evidence against:

- Fields, vtables, and helper bodies are `ScrollSpellInventoryPane`.
- Current reviewed file root [UID:0000NJ] exists and clears the gate.

Decision:

```text
Keep as fold candidate only. Reject direct owner.
```

### 4. [UID:0000NF] ScrollBar / Generic Scroll Infrastructure

Evidence for:

- Repeated scrollbar pattern across item/spell/group/collection/volume panes.

Evidence against:

- Class-specific vtables, fields, constructor caller, and helper bodies.
- Generic helper similarity does not prove shared source.

Decision:

```text
Reject as direct owner. Keep as conceptual/sibling evidence only.
```

### 5. Reclassify [UID:0001GM] As Non-Reconstructable Index

Evidence for:

- Exact child pages can carry source bodies.
- Some comparable pages become non-emitting indices after full split.

Evidence against:

- Most source-bearing methods inside [UID:0001GM] do not yet have exact child pages.
- The sibling [UID:0001GZ] `ScrollInventoryPane` remains a reconstructable class aggregate with blank C++ while child splitting continues.
- The aggregate still records source-authored class code, not merely padding or a mixed-owner convenience index.

Decision:

```text
Reject for now. Keep RECONSTRUCTABLE:TRUE until the source-bearing method set is fully split and re-evaluated.
```

## Negative Evidence Summary

Checked and rejected:

- Raw helper direct route: no rel32, VA, or RVA route for `0x00560520`, `0x00560590`, or `0x005608a0` in fresh local PE scan.
- Vtable reset route: no vtable slot for `0x005608a0`; [UID:0001YS] explicitly maps the class slots elsewhere.
- NewSpell direct ownership: only constructor-consumer evidence.
- Generic scrollbar ownership: similarity without direct source ownership evidence.
- Monolithic aggregate C++: violates exact child/body separation and would duplicate existing child pages.

## Final Recommendation

Recommended target changes in a future implementation callback:

```text
1. Update [UID:0001GM] score to 86/88.
2. Keep CANONICAL_OWNER:0000CN.
3. Keep RECONSTRUCTABLE:TRUE.
4. Keep EMITTER_UIDS:0000CN.
5. Keep formal C++ blank.
6. Add this report's full child/pocket inventory, boundary evidence, source-placement reasoning, and no-code proof.
7. Record the early raw setters and disable/predicate helpers explicitly.
8. Preserve [UID:0001GO] reset route as closed and class-owned.
```

Recommended split follow-up:

```text
Create exact child pages for each modeled/raw source-bearing method pocket listed in the child inventory.
Score and route each child individually through [UID:0000CN] when evidence clears the gate.
Populate first-draft C++ only on exact child pages whose branch behavior and names are source-quality.
```

Recommended support changes:

```text
[UID:0000CN] ScrollSpellInventoryPane:
- Add the early raw setter/disable/predicate inventory to method notes.
- Keep class owner/emitter route through [UID:0000NJ].
- Do not add declaration-level C++ until inheritance/field/interface naming is ready for a class shell.

[UID:0000NJ] ScrollSpellInventoryPane file:
- Add the missing raw setter/disable/predicate pockets to proposed contents.
- Preserve standalone route with NewSpellInventoryPane fold caveat.

[UID:0001W1] layout:
- Keep current `m_hoverPart`, `m_activePart`, and TimerHandler view names.
- Add or strengthen the unresolved `+0xfa` note using the raw setter at `0x0055f530`.

[UID:0001YS] vtables:
- Keep no-vtable-route note for reset helper.
- No score or metadata change required.

[UID:0001GN] UpdateFromDrag:
- Separate source-quality follow-up should decide whether to populate first-draft C++.
```

## Exact Supervisor-Owned Coverage Row

Current active row:

```text
    - [UID:0001GM][0x0055f450-0x005608fc.ScrollSpellInventoryPane](by-memory/0x0055f450-0x005608fc.ScrollSpellInventoryPane.md) 0x0055f450-0x005608fc | class aggregate | ScrollSpellInventoryPane : reconstructable : 85% : strong : Attached to [UID:0000CN][ScrollSpellInventoryPane](by-class/ScrollSpellInventoryPane.md) `ScrollSpellInventoryPane`; broad aggregate over constructor/mouse/repeat/paint/update/reset helpers, with source-file route through [UID:0000NJ][ScrollSpellInventoryPane](by-file/ScrollSpellInventoryPane.md). B002 confirms [UID:0001GO][0x005608a0-0x005608fc.ScrollSpellInventoryPaneResetScrollStateRaw](by-memory/0x005608a0-0x005608fc.ScrollSpellInventoryPaneResetScrollStateRaw.md) raw reset should remain a child rather than an aggregate split blocker.
```

Exact replacement row if supervisor accepts this report's metadata recommendation:

```text
    - [UID:0001GM][0x0055f450-0x005608fc.ScrollSpellInventoryPane](by-memory/0x0055f450-0x005608fc.ScrollSpellInventoryPane.md) 0x0055f450-0x005608fc | class aggregate | ScrollSpellInventoryPane : reconstructable : 86% : strong : B002 2026-06-19 source-quality reanalysis keeps direct class owner/emitter [UID:0000CN][ScrollSpellInventoryPane](by-class/ScrollSpellInventoryPane.md) and source-file route [UID:0000NJ][ScrollSpellInventoryPane](by-file/ScrollSpellInventoryPane.md); local PE/listing baseline and existing live-IDA-backed docs confirm the exact `0x0055f450-0x005608fc` aggregate boundary, predecessor padding `0x0055f44f-0x0055f450`, successor padding `0x005608fc-0x00560900`, modeled constructor/range/position/activation/mouse/repeat/paint/hit-test/part-rect/input/update methods, raw setter pockets at `0x0055f500` and `0x0055f530`, raw disable/predicate pockets at `0x0055f610` and `0x0055f630`, raw hover/active/reset pockets at `0x00560520`, `0x00560590`, and `0x005608a0`, class layout fields including `+0xa4` TimerHandler view, `+0x103` `m_hoverPart`, `+0x104` `m_activePart`, and the unresolved `+0xfa` byte; [UID:0001GO][0x005608a0-0x005608fc.ScrollSpellInventoryPaneResetScrollStateRaw](by-memory/0x005608a0-0x005608fc.ScrollSpellInventoryPaneResetScrollStateRaw.md) remains the exact class-owned reset child with C++, while the broad aggregate formal C++ remains blank because method bodies must be split/emitted through exact child pages and a monolithic aggregate block would duplicate children and mix padding/raw no-route helpers.
```

Placement context:

```text
After:
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0055f44f-0x0055f450 | padding | ScrollablePaneCore to ScrollSpellInventoryPane alignment : ignored : 100% : strong : Live IDA MCP and raw bytes confirm a single `0xcc` byte after `sub_55F250` and before the `ScrollSpellInventoryPane` successor at `0x0055f450`; no source replacement needed.

Before:
    - [UID:0001GN][0x00560710-0x0056089d.ScrollSpellInventoryPaneUpdateFromDrag](by-memory/0x00560710-0x0056089d.ScrollSpellInventoryPaneUpdateFromDrag.md) ...
```

Do not edit `by-memory/-coverage-report.md` from Agent-B002. If exact child pages are later created, child coverage rows should be generated after validator assigns real UIDs; this report intentionally does not invent UIDs for future children.

## Target / Support Implementation Checklist

Target [UID:0001GM]:

```text
[ ] Change score to 86/88 if incorporating this report's evidence.
[ ] Keep direct owner/emitter [UID:0000CN].
[ ] Keep source-file route [UID:0000NJ].
[ ] Keep RECONSTRUCTABLE:TRUE.
[ ] Keep formal C++ blank.
[ ] Add current-session MCP-unavailable caveat.
[ ] Add PE/listing baseline facts with MD5/SHA1.
[ ] Replace compact Covered Ranges table with the full child/pocket inventory from this report.
[ ] Add exact padding inventory, including the raw-code exception in 0x0055f60a-0x0055f650.
[ ] Add raw-route scan for 0x00560520, 0x00560590, and 0x005608a0 with positive controls.
[ ] Add aggregate no-code proof.
[ ] Preserve [UID:0001GO] reset child route and C++ status.
```

Support [UID:0000CN]:

```text
[ ] Add or update method inventory rows for raw setters at 0x0055f500/0x0055f530 and raw disable/predicate helpers at 0x0055f610/0x0055f630.
[ ] Preserve direct class ownership for existing and future children.
[ ] Add a note that class declaration C++ remains a separate support decision, not target aggregate C++.
```

Support [UID:0000NJ]:

```text
[ ] Add missing raw helper pockets to Proposed Contents.
[ ] Keep `ScrollSpellInventoryPane.cpp` as reviewed route.
[ ] Preserve `NewSpellInventoryPane.cpp` private-fold caveat.
```

Support [UID:0001W1]:

```text
[ ] Keep `+0xa4` TimerHandler view, `+0x103` m_hoverPart, and `+0x104` m_activePart.
[ ] Strengthen `+0xfa` as unresolved style/state byte with raw setter evidence at 0x0055f530.
```

Support [UID:0001YS]:

```text
[ ] No metadata change required.
[ ] Keep no-vtable-route note for 0x005608a0.
```

Existing children:

```text
[ ] Keep [UID:0001GO] as class-owned and coded.
[ ] Consider a separate source-quality implementation pass for [UID:0001GN] C++.
```

Future split callback:

```text
[ ] Create exact child pages for every source-bearing modeled/raw pocket listed in this report if supervisor accepts a split pass.
[ ] Add ignored padding rows only after the child pages exist or when supervisor applies coverage.
[ ] Validate each created/updated child and support doc.
[ ] Do not edit by-memory/-coverage-report.md directly; supply exact row text after new UIDs exist.
```

## Validator Results

Scoped validator baseline was run in dry-run mode only:

> Executable block R001 was removed from this report and preserved verbatim in [0001GM-ScrollSpellInventoryPane-source-quality-removed.md](0001GM-ScrollSpellInventoryPane-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Result summary:

```text
Exit code: 0
apply: False
scanned markdown files: 1
ok: 1
ok 0001GM by-memory/0x0055f450-0x005608fc.ScrollSpellInventoryPane.md UID header exists
stats_incremental_skip: dry run; pass --apply to update generated stats rows
autogen_report_noop: 7
dry run only; no by-* or coverage files written
```

The dry run also reported unrelated global autogen diagnostics such as existing emitter-with-no-code and C++ conflict counts. No target-specific validator error was reported for [UID:0001GM].

## Changed Files

Created:

```text
tools/leaser/Agents/Agent-B002/research/0001GM-ScrollSpellInventoryPane-source-quality.md
```

Modified:

```text
None outside Agent-B002 research.
```

Not edited:

```text
by-memory/0x0055f450-0x005608fc.ScrollSpellInventoryPane.md
by-memory/-coverage-report.md
all by-* docs
generated reports/source
IDA database
```

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/0001GM-ScrollSpellInventoryPane-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:24","uid":"0001GM"} -->
<!-- {"agent":"B002","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001GM-ScrollSpellInventoryPane-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B002/0001GM-ScrollSpellInventoryPane-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001GM"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
