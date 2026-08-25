** TARGET-REPORT-UID:0001H7 **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0001H7 SelfLookPane Source Split Audit

## Finalized Report / Current Recommendation

- Current recommendation: split [UID:0001H7][0x00565610-0x0056a373.SelfLookPane](../../../../../by-memory/0x00565610-0x0056a373.SelfLookPane.md) into exact method/raw-helper children, then reclassify [UID:0001H7] as a non-emitting `SelfLookPane` main-span split index.
- Final disposition: [UID:0001H7] should not remain the source-emitting reconstructable leaf once child pages exist. It should become `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, direct owner [UID:0000CU][SelfLookPane](../../../../../by-class/SelfLookPane.md), and blank final C++.
- Required action: supervisor should create the child pages listed below, update the parent/support docs and coverage row, validate, then rerun the memory tool report.
- Confidence: high for class/file ownership and split shape; medium-high for exact final method names because field names, packet names, and some raw-helper liveness remain below final-C++ quality.

## Target

- Target UID: [UID:0001H7]
- Target path: `by-memory/0x00565610-0x0056a373.SelfLookPane.md`
- Assignment: `B001-goal2-memory-tool-selflookpane-source-split-0001H7-20260616`
- Current state checked: `82/88`, `CANONICAL_OWNER:0000NL`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000NL`, blank final C++.
- Generated queue state: `auto-generated/by-memory-tool-report.md` still lists this as the 19,811-byte reconstructable leaf at rank 11.
- Current coverage row: one reconstructable `class aggregate` row between existing ignored padding rows `0x00565608-0x00565610` and `0x0056a373-0x0056a380`.

## Executive Recommendation

The best source-placement model is:

- `0x00565610-0x0056a373` is one linked contiguous `SelfLookPane` class-method span from `SelfLookPane.cpp`, not a mixed file-level source body.
- Exact method/raw-helper children should carry source ownership through direct class owner [UID:0000CU][SelfLookPane](../../../../../by-class/SelfLookPane.md), with final emission ultimately routing through [UID:0000NL][SelfLookPane](../../../../../by-file/SelfLookPane.md).
- The aggregate [UID:0001H7] should become the non-emitting index, matching the already-executed pattern used by adjacent [UID:00023V][SelfLookPanePacketUpdateHelpers](../../../../../by-memory/0x0056a380-0x0056ba99.SelfLookPanePacketUpdateHelpers.md).
- Raw non-IDA bodies at `0x005670c0`, `0x00567180`, `0x005671a0`, and `0x005672b0` should remain reconstructable child evidence with blank final C++; local PE scans found no hidden pointer/relative-branch routes, but the bodies are real source-shaped class helpers and match the packet/view helper family.
- The one-byte `nullsub_51` at `0x00566f30-0x00566f31` should be split as non-emitting code-stub evidence, not treated as a source method, unless a fresh supervisor xref/vtable pass proves a real caller or slot.

Do not reclassify the parent before child pages exist. Until the split is applied, the current reconstructable aggregate is still the only source-bearing coverage for the span.

## Evidence Standards Used

Evidence checked:

- Existing target/support docs: by-memory target, [UID:0000CU] class page, [UID:0000NL] file page, [UID:00023V] adjacent helper index, exact helper children [UID:0002RA]-[UID:0002RG], `SelfLookPane2`, vtable data, hover-slot global, GeneralPurposePanel accessors, and `g_pGeneralPurposePanel`.
- Live IDA/MCP facts from session `b001_selflookpane_0001H7_20260616`: function inventory, lookup status for raw starts/tables, bytes for padding/tables, xrefs, vtable stores, caller/callee component analysis, and active-child callsite disassembly.
- Local raw PE scan on `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`: VA/RVA pointer-byte and relative call/jump searches for raw/no-op starts.
- Generated and coverage state: `by-memory/-coverage-report.md` and `auto-generated/by-memory-tool-report.md`.

This is strong enough for ownership and split decisions. It is not strong enough for final C++ because exact original field names, packet enum names, child-pane member names, and several helper method names are still inferred.

## IDA MCP Facts

### Function and Boundary Facts

Live function inventory for `0x00565600-0x0056a380`:

| Start | Current IDA name | Size / end | Split role |
| --- | --- | --- | --- |
| `0x00565610` | `sub_565610` | `0x1c2` / `0x005657d2` | constructor |
| `0x005657e0` | `sub_5657E0` | `0xa7` / `0x00565887` | non-deleting destructor helper |
| `0x00565890` | `sub_565890` | `0x1694` / `0x00566f24` | character-data parser / receive handler |
| `0x00566f30` | `nullsub_51` | `0x1` / `0x00566f31` | no-op code stub |
| `0x00566f40` | `sub_566F40` | `0xba` / `0x00566ffa` | packet toggle helper |
| `0x00567000` | `sub_567000` | `0xba` / `0x005670ba` | packet toggle helper |
| `0x005671c0` | `sub_5671C0` | `0x1e` / `0x005671de` | refresh helper |
| `0x005671e0` | `sub_5671E0` | `0x11` / `0x005671f1` | child refresh helper |
| `0x00567200` | `sub_567200` | `0x80` / `0x00567280` | reset/refresh helper |
| `0x00567280` | `sub_567280` | `0x30` / `0x005672b0` | activate helper |
| `0x00567380` | `sub_567380` | `0xf2` / `0x00567472` | deactivate helper |
| `0x00567480` | `sub_567480` | `0x1734` / `0x00568bb4` | paint body, followed by switch data |
| `0x00568bd0` | `sub_568BD0` | `0xd9` / `0x00568ca9` | key handler |
| `0x00568cb0` | `sub_568CB0` | `0x69a` / `0x0056934a` | mouse handler, followed by switch data |
| `0x005693d0` | `sub_5693D0` | `0x3e5` / `0x005697b5` | packet/event handler, followed by switch data |
| `0x00569860` | `sub_569860` | `0x3da` / `0x00569c3a` | help handler, followed by switch data |
| `0x00569c80` | `sub_569C80` | `0x4e` / `0x00569cce` | rectangle getter |
| `0x00569cd0` | `sub_569CD0` | `0xa5` / `0x00569d75` | rectangle transform |
| `0x00569d80` | `sub_569D80` | `0x141` / `0x00569ec1` | number drawing helper |
| `0x00569ed0` | `sub_569ED0` | `0x3ce` / `0x0056a29e` | slot-color/rect helper, followed by switch data |
| `0x0056a300` | `sub_56A300` | `0x73` / `0x0056a373` | hit-test helper |

IDA does not model functions at raw starts `0x005670c0`, `0x00567180`, `0x005671a0`, and `0x005672b0`. Byte checks show normal prologue/epilogue code bodies at those starts, not padding. IDA also does not model switch-table starts `0x00568bb4`, `0x0056934a`, `0x005697b5`, `0x00569c3a`, or `0x0056a29e` as functions; those bytes are method-owned jump/switch data plus alignment.

Boundary checks:

- `0x00565608-0x00565610` is eight `0xcc` bytes before the constructor.
- `0x0056a373-0x0056a380` is thirteen `0xcc` bytes before adjacent [UID:00023V].
- Raw helper starts are bounded by `0xcc` alignment except `0x00567280-0x005672b0`, which flows directly into the raw helper at `0x005672b0`.
- The `0x00568bb4` table has a local VA hit from `0x00567cc7` inside `OnPaint`; this is local switch-table ownership, not an external table pointer.

### Xref and Caller Facts

Important xrefs:

- Constructor `0x00565610`: code xref from `0x004b844e` in `GeneralPurposePanel` construction, matching child index 0 self-look creation.
- Destructor helper `0x005657e0`: no direct code xrefs, but vtable restore refs match constructor/scalar destructor evidence.
- Virtual/event methods:
  - `0x00565890`, `0x00567480`, `0x00568bd0`, `0x00568cb0`, `0x005693d0`, `0x00569860`, `0x00569c80`, and `0x00569cd0` have vtable data refs from [UID:0002UY][SelfLookPane Vtable Data](../../../../../by-memory/0x00624188-0x00624210.SelfLookPaneVtableData.md).
  - `0x00569d80` has twelve code xrefs from `OnPaint`.
  - `0x00569ed0` has eighteen code xrefs from packet toggles, raw stats toggle, paint, mouse, and hit-test paths.
  - `0x0056a300` has three code xrefs from `OnMouseClick`.
- Raw starts `0x005670c0`, `0x00567180`, `0x005671a0`, and `0x005672b0`: no IDA xrefs.
- Adjacent helper children:
  - `0x0056a640` is called from `0x00569588` inside `0x005693d0`.
  - `0x0056b7c0` is called from `0x0056972f` inside `0x005693d0`.

External caller caveat resolved:

- `0x00566f40` and `0x00567000` are called from `0x005a5bd0`, but the callsite first loads [UID:0000R0][g_pGeneralPurposePanel](../../../../../by-global/g_pGeneralPurposePanel.md), calls [UID:00015W][GeneralPurposePanel::GetActiveChildPane](../../../../../by-memory/0x004b85f0-0x004b8643.GeneralPurposePanelChildAccessors.md), then calls the returned active child pane. This is a `UserPane`/input dispatcher using the active `GeneralPurposePanel` child, not ownership by `UserPane`.
- The same callsite has an inline fallback packet-send branch when the active-child route is not used. That explains the external xrefs without moving these helpers out of `SelfLookPane`.

### Vtable and Global Facts

- [UID:0002UY] lists the primary/secondary/tertiary `SelfLookPane` vtable views at `0x00624188`, `0x006241d8`, and `0x00624208`.
- Vtable stores occur at constructor `0x00565640`, destructor helper `0x0056580b`, and scalar destructor `0x00573762`.
- The vtable slots map the in-range virtual methods to `SelfLookPane`, including `OnGetRect`, `OnTransformRect`, `OnPaint`, `OnReceiveCharacterData`, `OnMouseClick`, `OnKeyPress`, packet/event handler, and `OnShowHelp`.
- [UID:0002CG][g_selfLookLastHoverEquipmentSlotId](../../../../../by-global/g_selfLookLastHoverEquipmentSlotId.md) and [UID:000283][exact storage](../../../../../by-memory/0x0066fe40-0x0066fe44.SelfLookPaneLastHoverEquipmentSlotId.md) have exactly two xrefs, compare `0x005692c7` and write `0x00569310`, both inside `SelfLookPane::OnMouseClick`. This supports `SelfLookPane.cpp` file ownership and does not imply a separate owner.

### Raw PE Scan Facts

Local PE scan checked full-file VA/RVA pointer-byte hits and `.text` relative `call`/`jmp` hits for:

| Target | VA hits | RVA hits | Relative call/jmp hits |
| --- | --- | --- | --- |
| `0x00566f30` | none | none | none |
| `0x005670c0` | none | none | none |
| `0x00567180` | none | none | none |
| `0x005671a0` | none | none | none |
| `0x005672b0` | none | none | none |

Earlier local PE scan also found no `.pdb`, `.cpp`, or `RSDS` debug/source metadata strings in the binary. Therefore there is no hidden source path or pointer-table evidence that would reroute raw helper ownership.

## Proposed Child Inventory

Create these children in address order. For all reconstructable children, use `CANONICAL_OWNER:0000CU`, `EMITTER_UIDS:0000CU`, and blank final C++. The class parent clears the gate through [UID:0000CU] `85/88` today and should be raised after the child links are applied.

| Proposed filename | Range | Role | Metadata |
| --- | --- | --- | --- |
| `0x00565610-0x005657d2.SelfLookPaneConstructor.md` | `0x00565610-0x005657d2` | constructor, child pane setup, vtable stores | `86/90`, reconstructable, owner/emitter `0000CU` |
| `0x005657e0-0x00565887.SelfLookPaneNonDeletingDestructor.md` | `0x005657e0-0x00565887` | destructor/cleanup helper, vtable restore | `85/90`, reconstructable, owner/emitter `0000CU` |
| `0x00565890-0x00566f24.SelfLookPaneOnReceiveCharacterData.md` | `0x00565890-0x00566f24` | character data receive/parser/update handler | `85/89`, reconstructable, owner/emitter `0000CU` |
| `0x00566f30-0x00566f31.SelfLookPaneNullStub.md` | `0x00566f30-0x00566f31` | one-byte no-op code stub | `85/88`, `RECONSTRUCTABLE:FALSE`, owner `0000CU`, blank emitters |
| `0x00566f40-0x00566ffa.SelfLookPaneSendToggleLook.md` | `0x00566f40-0x00566ffa` | active-child callable packet toggle | `86/89`, reconstructable, owner/emitter `0000CU` |
| `0x00567000-0x005670ba.SelfLookPaneSendToggleEquip.md` | `0x00567000-0x005670ba` | active-child callable packet toggle | `86/89`, reconstructable, owner/emitter `0000CU` |
| `0x005670c0-0x0056717a.SelfLookPaneSendToggleStatsRaw.md` | `0x005670c0-0x0056717a` | raw stats/spelled-view toggle body | `85/89`, reconstructable, owner/emitter `0000CU` |
| `0x00567180-0x0056719a.SelfLookPaneSpelledEntryUpdateForwarderRaw.md` | `0x00567180-0x0056719a` | raw forwarder through `this+0xfc` to `0x0056bca0` | `85/88`, reconstructable, owner/emitter `0000CU` |
| `0x005671a0-0x005671b7.SelfLookPaneSpelledEntryRemoveForwarderRaw.md` | `0x005671a0-0x005671b7` | raw forwarder through `this+0xfc` to `0x0056be20` | `85/88`, reconstructable, owner/emitter `0000CU` |
| `0x005671c0-0x005671de.SelfLookPaneRefreshWorldMapPane.md` | `0x005671c0-0x005671de` | small refresh helper | `85/89`, reconstructable, owner/emitter `0000CU` |
| `0x005671e0-0x005671f1.SelfLookPaneRefreshSpelledChild.md` | `0x005671e0-0x005671f1` | child refresh helper | `85/88`, reconstructable, owner/emitter `0000CU` |
| `0x00567200-0x00567280.SelfLookPaneResetAndRefresh.md` | `0x00567200-0x00567280` | reset/refresh helper | `86/89`, reconstructable, owner/emitter `0000CU` |
| `0x00567280-0x005672b0.SelfLookPaneActivateView.md` | `0x00567280-0x005672b0` | activate current view child | `85/89`, reconstructable, owner/emitter `0000CU` |
| `0x005672b0-0x0056737f.SelfLookPaneDeactivateResetRaw.md` | `0x005672b0-0x0056737f` | raw deactivate/reset child-pane body | `85/89`, reconstructable, owner/emitter `0000CU` |
| `0x00567380-0x00567472.SelfLookPaneDeactivateView.md` | `0x00567380-0x00567472` | deactivate helper | `85/89`, reconstructable, owner/emitter `0000CU` |
| `0x00567480-0x00568bd0.SelfLookPaneOnPaint.md` | `0x00567480-0x00568bd0` | paint body plus owned switch table `0x00568bb4-0x00568bd0` | `86/90`, reconstructable, owner/emitter `0000CU` |
| `0x00568bd0-0x00568ca9.SelfLookPaneOnKeyPress.md` | `0x00568bd0-0x00568ca9` | key handler | `85/89`, reconstructable, owner/emitter `0000CU` |
| `0x00568cb0-0x005693d0.SelfLookPaneOnMouseClick.md` | `0x00568cb0-0x005693d0` | mouse handler plus owned switch table `0x0056934a-0x005693d0` | `86/90`, reconstructable, owner/emitter `0000CU` |
| `0x005693d0-0x00569860.SelfLookPanePacketEventHandler.md` | `0x005693d0-0x00569860` | packet/event helper plus owned switch table `0x005697b5-0x00569860` | `86/90`, reconstructable, owner/emitter `0000CU` |
| `0x00569860-0x00569c80.SelfLookPaneOnShowHelp.md` | `0x00569860-0x00569c80` | help/tooltip handler plus owned switch table `0x00569c3a-0x00569c80` | `85/89`, reconstructable, owner/emitter `0000CU` |
| `0x00569c80-0x00569cce.SelfLookPaneOnGetRect.md` | `0x00569c80-0x00569cce` | rectangle getter virtual | `85/89`, reconstructable, owner/emitter `0000CU` |
| `0x00569cd0-0x00569d75.SelfLookPaneOnTransformRect.md` | `0x00569cd0-0x00569d75` | rectangle transform virtual | `85/89`, reconstructable, owner/emitter `0000CU` |
| `0x00569d80-0x00569ec1.SelfLookPaneDrawNumberString.md` | `0x00569d80-0x00569ec1` | numeric drawing helper | `85/89`, reconstructable, owner/emitter `0000CU` |
| `0x00569ed0-0x0056a300.SelfLookPaneGetSlotColors.md` | `0x00569ed0-0x0056a300` | slot geometry/color helper plus owned switch table `0x0056a29e-0x0056a300` | `86/90`, reconstructable, owner/emitter `0000CU` |
| `0x0056a300-0x0056a373.SelfLookPaneHitTestSlot.md` | `0x0056a300-0x0056a373` | slot hit-test helper | `85/90`, reconstructable, owner/emitter `0000CU` |

These children all clear `85/85` except the no-op stub is intentionally non-emitting. The raw forwarder scores stay at `85` completion because no xrefs/pointer routes were found; that does not block the split because owner and boundaries are strong and the adjacent [UID:0002RA] raw helper precedent uses the same evidence standard.

## Documentation Evidence and IDA Status

Existing docs that support the recommendation:

- [UID:0000NL][SelfLookPane](../../../../../by-file/SelfLookPane.md) already places `SelfLookPane`, `SelfLookPane2`, vtables, static hover state, and adjacent helpers under `NexusTK/ui/panels/`.
- [UID:0000CU][SelfLookPane](../../../../../by-class/SelfLookPane.md) already inventories the same main-span methods and documents raw bodies at `0x005670c0`, `0x00567180`, `0x005671a0`, and `0x005672b0`.
- [UID:00023V][SelfLookPanePacketUpdateHelpers](../../../../../by-memory/0x0056a380-0x0056ba99.SelfLookPanePacketUpdateHelpers.md) is already a non-emitting helper-island map after exact child pages [UID:0002RA]-[UID:0002RG] were created. That is the correct precedent for [UID:0001H7].
- [UID:0002UY][SelfLookPane Vtable Data](../../../../../by-memory/0x00624188-0x00624210.SelfLookPaneVtableData.md) maps the virtual slots and vtable stores to `SelfLookPane`.
- [UID:0002CG] and [UID:000283] localize the hover-slot global to `SelfLookPane` mouse handling.

Docs that need repair:

- [UID:0001H7] still says raw helper spans remain aggregate-owned rather than child pages. That should be replaced by child links after the split.
- [UID:0001H7] current raw-stub range text ends `0x00567198` and `0x005671b5`; B001's raw-body accounting supports `0x0056719a` and `0x005671b7` for complete `retn` immediates. Supervisor should byte-confirm during creation and use the corrected end addresses if validation agrees.
- [UID:0000CU] currently reports [UID:00023V] as `76/84` in one support table even though the executed helper index is now `88/89`; refresh that stale support score while adding [UID:0001H7] child links.
- The coverage row for [UID:0001H7] is stale after the split because it marks the full 19 KB span reconstructable.

## Ranked Ownership Analysis

### 1. Direct class owner [UID:0000CU] SelfLookPane - accepted

Evidence for:

- Constructor, destructor helper, virtual methods, vtable stores, slot/global state, raw helper field access, and adjacent helper calls all use `SelfLookPane` object state.
- External `UserPane` calls route through `GeneralPurposePanel::GetActiveChildPane`; the receiver is the active child pane, not a `UserPane` object.
- Adjacent [UID:00023V] and children already route exact helper ownership to [UID:0000CU].
- [UID:0000CU] and [UID:0000NL] both clear the `85/85` gate.

Evidence against:

- Some exact method names are inferred and final member fields are not fully named.
- Raw starts have no direct xrefs or pointer hits.

Decision: accepted for child owner/emitter. The negatives cap completion/confidence and keep final C++ blank; they do not block ownership.

### 2. File owner [UID:0000NL] SelfLookPane - source route, not direct child owner

Evidence for:

- Proposed source tree and file doc place `SelfLookPane.cpp` in `NexusTK/ui/panels/`.
- The file owns `SelfLookPane`, `SelfLookPane2`, source-local vtable family, hover global, and helper islands.

Evidence against:

- The main span is not a mixed file aggregate after exact child split; every executable body inside the target belongs to the `SelfLookPane` class or a no-op code stub adjacent to it.
- Prior executed splits for `ItemHelpPaneCore` and `SelfLookPanePacketUpdateHelpers` prefer direct class ownership for exact method children and non-emitting class-owned parent maps.

Decision: keep as source file route and support page, but change [UID:0001H7] and children to direct class owner [UID:0000CU].

### 3. Keep [UID:0001H7] as one reconstructable aggregate - rejected after split

Evidence for:

- Current aggregate is coherent enough to preserve source evidence before child pages exist.
- It is not mixed across unrelated owners.

Evidence against:

- The span contains many independent methods, raw code bodies, no-op stub, switch data, and padding. A single final C++ body would be artificial.
- The adjacent helper island already demonstrates the correct shape: parent index plus exact children.
- The memory-tool queue flags this as a large reconstructable leaf precisely because method-level child pages are absent.

Decision: do not keep as reconstructable once child pages exist. Until then, leave current page unchanged.

### 4. UserPane, GeneralPurposePanel, SpelledPane, LegendPane, or UserLookPane ownership - rejected

Evidence for:

- `0x00566f40` and `0x00567000` have external callers from a large `UserPane` input dispatcher.
- Constructor calls `SpelledPane` and `LegendPane` constructors.
- SpelledPane forwarding stubs call methods through `this+0xfc`.

Evidence against:

- The external caller obtains the active child pane from `g_pGeneralPurposePanel` before invoking the methods.
- `g_pGeneralPurposePanel` and child accessors are already correctly documented as GeneralPurposePanel infrastructure, not method ownership.
- `SpelledPane` and `LegendPane` constructors have additional xrefs from `SelfLookPane2` and `UserLookPane`, so construction/use does not make them children of this memory span.
- Raw forwarders use the `SelfLookPane` child pointer field and are glue methods on the `SelfLookPane` object.

Decision: rejected as direct owners. They should remain cross-reference/support evidence.

### 5. Treat raw helpers as ignored/dead duplicate code - rejected except for the one-byte no-op stub

Evidence for:

- Local PE scans and IDA xrefs found no callers/pointers for `0x005670c0`, `0x00567180`, `0x005671a0`, or `0x005672b0`.

Evidence against:

- They are normal source-shaped functions, use `SelfLookPane` fields, call the same packet/view helper family, and sit inside the class method run.
- `0x005670c0` sends the same packet family as live `0x00566f40`, `0x00567000`, and the mouse handler.
- Adjacent [UID:0002RA] raw packet helpers are already accepted as reconstructable child evidence under the same no-xref/raw-start pattern.

Decision: keep raw bodies reconstructable as exact child evidence with blank final C++. The one-byte `nullsub_51` is different because no slot/caller/semantics were found, so it should be a non-emitting stub child.

## Remaining Blockers Resolved or Scoped

- One-file vs class-level source placement: resolved to class-owned children under `SelfLookPane.cpp`. Evidence checked: file/class docs, vtable data, constructor caller, active-child caller, adjacent helper split, `SelfLookPane2` placement.
- Raw helper reachability: checked IDA xrefs and local VA/RVA/relative-branch PE scans. No hidden routes were found. This limits completion but does not justify ignoring source-shaped class bodies.
- Final field/type names: not resolved. Evidence checked includes callee sets, field offsets, vtable slots, hover global, and packet helper patterns. Exact names for fields at `this+0xfc`, `this+0x100`, `this+0x104`, `this+0x1655`, `this+0x1f1c`, `this+0x1f20`, and `this+0x1f26` remain below final-C++ quality.
- Packet/protocol names: partially resolved by packet byte patterns (`0x1b` option family and subtypes used by toggles) and adjacent helper docs. Exact enum names remain inferred.
- Switch table ownership: resolved. Switch data is local to owning methods and should be included in the method child ranges listed above.
- IDA DB repair: not recommended. IDA already models the true function starts except the raw bodies; creating function objects for no-xref raw spans would be speculative and not required for documentation. The no-op stub should remain as IDA models it unless future xrefs prove a source slot.

## Exact Supervisor Actions

### 1. Create child pages

Create the 25 child pages listed in "Proposed Child Inventory". Allocate real UIDs. Use direct owner/emitter [UID:0000CU] for every reconstructable child. Use direct owner [UID:0000CU], `RECONSTRUCTABLE:FALSE`, and blank `EMITTER_UIDS` for `SelfLookPaneNullStub`.

Each child page should include:

- exact range and role;
- IDA function/no-function status;
- caller/callee or vtable/xref evidence;
- raw-byte/range evidence for raw helpers and switch-table children;
- owner/emitter rationale through [UID:0000CU] and [UID:0000NL];
- blank final C++;
- score rationale matching the proposed score.

### 2. Reclassify the parent after children exist

Update `by-memory/0x00565610-0x0056a373.SelfLookPane.md`:

```text
COMPLETION:88
CONFIDENCE:91
CANONICAL_OWNER:0000CU
RECONSTRUCTABLE:FALSE
EMITTER_UIDS:
```

Replace the aggregate-owned raw-helper language with a split-index explanation:

```text
This page is the non-emitting main-span index for the SelfLookPane class methods at 0x00565610-0x0056a373. Exact child pages carry the reconstructable source evidence for the constructor/destructor, character parser, packet toggles, raw forwarders, view helpers, paint/input/event/help methods, geometry helpers, slot-color helper, and hit-test helper. The parent preserves the contiguous class-method layout, owned switch-table spans, raw no-function evidence, and padding boundaries; final C++ belongs only on exact children after their field/protocol names are final-quality.
```

### 3. Update support docs

Update [UID:0000CU][SelfLookPane](../../../../../by-class/SelfLookPane.md):

- add links to the new child pages in the method inventory;
- change [UID:0001H7] description from reconstructable aggregate to non-emitting main-span index;
- refresh the stale [UID:00023V] support score shown as `76/84` to current `88/89`;
- record the active-child `UserPane` caller caveat for `SendToggleLook` and `SendToggleEquip`;
- recommended metadata after update: `COMPLETION:88`, `CONFIDENCE:90`.

Update [UID:0000NL][SelfLookPane](../../../../../by-file/SelfLookPane.md):

- add the exact main-span child split summary;
- keep `SelfLookPane2`, `SpelledPane`, and `LegendPane` caveats unchanged unless independently researched;
- recommended metadata after update: `COMPLETION:86`, `CONFIDENCE:90`.

No change is recommended for [UID:0002UY], [UID:0002CG], [UID:000283], [UID:00015W], or [UID:0000R0] beyond optional cross-reference additions.

### 4. Coverage report replacement block

Do not edit `by-memory/-coverage-report.md` manually as B001. Supervisor should replace the existing single [UID:0001H7] row at the current placement between ignored `0x00565608-0x00565610` and ignored `0x0056a373-0x0056a380` with this block. Replace `UID:NEW-H7*` placeholders with allocated child UIDs.

```markdown
    - [UID:0001H7][0x00565610-0x0056a373.SelfLookPane](by-memory/0x00565610-0x0056a373.SelfLookPane.md) 0x00565610-0x0056a373 | class method split index | SelfLookPane : not_reconstructable : 88% : strong : Reclassified non-emitting SelfLookPane main-span split index after exact method-child pages cover constructor/destructor, character-data parser, packet toggles/raw stubs, view activation/deactivation, paint/input/event/help/geometry/number/slot helpers, and owned switch tables; direct source owner is [UID:0000CU][SelfLookPane](by-class/SelfLookPane.md), with source-file route through [UID:0000NL][SelfLookPane](by-file/SelfLookPane.md). Parent C++ remains blank; exact children carry reconstruction evidence.
        - [UID:NEW-H7A][0x00565610-0x005657d2.SelfLookPaneConstructor](by-memory/0x00565610-0x005657d2.SelfLookPaneConstructor.md) 0x00565610-0x005657d2 | constructor | SelfLookPaneConstructor : reconstructable : 86% : strong : Exact SelfLookPane constructor child with GeneralPurposePanel construction xref, primary/secondary/tertiary vtable stores, SpelledPane/LegendPane child construction, local pane setup, and source route through [UID:0000CU][SelfLookPane](by-class/SelfLookPane.md); final field names and constructor C++ remain below final-output quality.
        - [UID:NEW-H7B][0x005657e0-0x00565887.SelfLookPaneNonDeletingDestructor](by-memory/0x005657e0-0x00565887.SelfLookPaneNonDeletingDestructor.md) 0x005657e0-0x00565887 | destructor helper | SelfLookPaneNonDeletingDestructor : reconstructable : 85% : strong : Exact destructor/cleanup helper child with SelfLookPane vtable restore stores and cleanup callees; no direct caller beyond destructor-chain evidence, so final C++ stays blank.
        - [UID:NEW-H7C][0x00565890-0x00566f24.SelfLookPaneOnReceiveCharacterData](by-memory/0x00565890-0x00566f24.SelfLookPaneOnReceiveCharacterData.md) 0x00565890-0x00566f24 | character data handler | SelfLookPaneOnReceiveCharacterData : reconstructable : 85% : strong : Large SelfLookPane receive/parser child mapped by vtable slot, callee set, child-pane updates, activation/deactivation helper calls, and field-state writes; unresolved exact field/protocol names cap completion.
        - [UID:NEW-H7D][0x00566f30-0x00566f31.SelfLookPaneNullStub](by-memory/0x00566f30-0x00566f31.SelfLookPaneNullStub.md) 0x00566f30-0x00566f31 | no-op code stub | SelfLookPaneNullStub : not_reconstructable : 85% : strong : One-byte `retn` stub between SelfLookPane methods; no vtable slot, code caller, pointer-byte hit, RVA hit, or relative branch hit was found, so keep as non-emitting stub evidence rather than a source method.
        - [UID:NEW-H7E][0x00566f40-0x00566ffa.SelfLookPaneSendToggleLook](by-memory/0x00566f40-0x00566ffa.SelfLookPaneSendToggleLook.md) 0x00566f40-0x00566ffa | packet toggle helper | SelfLookPaneSendToggleLook : reconstructable : 86% : strong : Packet toggle helper called through the GeneralPurposePanel active-child path and sharing SelfLookPane slot-color/packet-send behavior; external UserPane dispatcher callsites are receiver dispatch, not ownership evidence.
        - [UID:NEW-H7F][0x00567000-0x005670ba.SelfLookPaneSendToggleEquip](by-memory/0x00567000-0x005670ba.SelfLookPaneSendToggleEquip.md) 0x00567000-0x005670ba | packet toggle helper | SelfLookPaneSendToggleEquip : reconstructable : 86% : strong : Packet toggle helper called through the GeneralPurposePanel active-child path, matching SelfLookPane packet-family senders and slot-color refresh behavior; final packet enum names remain provisional.
        - [UID:NEW-H7G][0x005670c0-0x0056717a.SelfLookPaneSendToggleStatsRaw](by-memory/0x005670c0-0x0056717a.SelfLookPaneSendToggleStatsRaw.md) 0x005670c0-0x0056717a | raw packet toggle helper | SelfLookPaneSendToggleStatsRaw : reconstructable : 85% : strong : Raw no-function SelfLookPane stats/spelled toggle body with packet subtype match, timestamp/rate-limit fields, slot-color redraw, and no hidden pointer/branch routes; retained as reconstructable raw source evidence with blank final C++.
        - [UID:NEW-H7H][0x00567180-0x0056719a.SelfLookPaneSpelledEntryUpdateForwarderRaw](by-memory/0x00567180-0x0056719a.SelfLookPaneSpelledEntryUpdateForwarderRaw.md) 0x00567180-0x0056719a | raw child forwarder | SelfLookPaneSpelledEntryUpdateForwarderRaw : reconstructable : 85% : strong : Raw no-function forwarder through SelfLookPane child pointer `this+0xfc` to the SpelledPane update helper; no direct xrefs or pointer hits were found, so liveness remains capped but owner/range are class-local.
        - [UID:NEW-H7I][0x005671a0-0x005671b7.SelfLookPaneSpelledEntryRemoveForwarderRaw](by-memory/0x005671a0-0x005671b7.SelfLookPaneSpelledEntryRemoveForwarderRaw.md) 0x005671a0-0x005671b7 | raw child forwarder | SelfLookPaneSpelledEntryRemoveForwarderRaw : reconstructable : 85% : strong : Raw no-function forwarder through SelfLookPane child pointer `this+0xfc` to the SpelledPane remove/clear helper; no direct xrefs or pointer hits were found, so final source use remains blank.
        - [UID:NEW-H7J][0x005671c0-0x005671de.SelfLookPaneRefreshWorldMapPane](by-memory/0x005671c0-0x005671de.SelfLookPaneRefreshWorldMapPane.md) 0x005671c0-0x005671de | refresh helper | SelfLookPaneRefreshWorldMapPane : reconstructable : 85% : strong : Small SelfLookPane refresh helper with live code xrefs from the surrounding pane/update flow and class-local receiver behavior; exact original helper name remains provisional.
        - [UID:NEW-H7K][0x005671e0-0x005671f1.SelfLookPaneRefreshSpelledChild](by-memory/0x005671e0-0x005671f1.SelfLookPaneRefreshSpelledChild.md) 0x005671e0-0x005671f1 | child refresh helper | SelfLookPaneRefreshSpelledChild : reconstructable : 85% : strong : Tiny class-local child refresh helper with caller evidence and direct child-pane dispatch; final member names remain unresolved.
        - [UID:NEW-H7L][0x00567200-0x00567280.SelfLookPaneResetAndRefresh](by-memory/0x00567200-0x00567280.SelfLookPaneResetAndRefresh.md) 0x00567200-0x00567280 | reset/refresh helper | SelfLookPaneResetAndRefresh : reconstructable : 86% : strong : Reset/refresh child called by key and mouse paths, tied to SelfLookPane view activation/deactivation state; final field names remain provisional.
        - [UID:NEW-H7M][0x00567280-0x005672b0.SelfLookPaneActivateView](by-memory/0x00567280-0x005672b0.SelfLookPaneActivateView.md) 0x00567280-0x005672b0 | activate helper | SelfLookPaneActivateView : reconstructable : 85% : strong : Small activate-current-view helper called from receive/key/mouse paths with class-local child-pane behavior; final source spelling remains unresolved.
        - [UID:NEW-H7N][0x005672b0-0x0056737f.SelfLookPaneDeactivateResetRaw](by-memory/0x005672b0-0x0056737f.SelfLookPaneDeactivateResetRaw.md) 0x005672b0-0x0056737f | raw deactivate/reset helper | SelfLookPaneDeactivateResetRaw : reconstructable : 85% : strong : Raw no-function body that hides/shows SelfLookPane child panes, formats a rect, attaches a resource, and invalidates the pane; no hidden pointer/branch routes were found, so final C++ stays blank.
        - [UID:NEW-H7O][0x00567380-0x00567472.SelfLookPaneDeactivateView](by-memory/0x00567380-0x00567472.SelfLookPaneDeactivateView.md) 0x00567380-0x00567472 | deactivate helper | SelfLookPaneDeactivateView : reconstructable : 85% : strong : Deactivate helper called from receive/key/mouse paths and paired with the raw deactivate/reset helper; final field names remain provisional.
        - [UID:NEW-H7P][0x00567480-0x00568bd0.SelfLookPaneOnPaint](by-memory/0x00567480-0x00568bd0.SelfLookPaneOnPaint.md) 0x00567480-0x00568bd0 | paint method and switch table | SelfLookPaneOnPaint : reconstructable : 86% : strong : Vtable-mapped paint method with owned switch table at `0x00568bb4-0x00568bd0`, repeated calls to number/slot helpers, and class-local render state; exact field/resource names cap final source readiness.
        - [UID:NEW-H7Q][0x00568bd0-0x00568ca9.SelfLookPaneOnKeyPress](by-memory/0x00568bd0-0x00568ca9.SelfLookPaneOnKeyPress.md) 0x00568bd0-0x00568ca9 | key handler | SelfLookPaneOnKeyPress : reconstructable : 85% : strong : Vtable-mapped key handler calling reset/activate/deactivate helpers; exact key/action names remain provisional.
        - [UID:NEW-H7R][0x00568cb0-0x005693d0.SelfLookPaneOnMouseClick](by-memory/0x00568cb0-0x005693d0.SelfLookPaneOnMouseClick.md) 0x00568cb0-0x005693d0 | mouse handler and switch table | SelfLookPaneOnMouseClick : reconstructable : 86% : strong : Vtable-mapped mouse handler with owned switch data at `0x0056934a-0x005693d0`, hover-slot global compare/write, hit-test calls, packet send branches, and timer scheduling behavior; exact event/field names remain below final-C++ quality.
        - [UID:NEW-H7S][0x005693d0-0x00569860.SelfLookPanePacketEventHandler](by-memory/0x005693d0-0x00569860.SelfLookPanePacketEventHandler.md) 0x005693d0-0x00569860 | packet/event handler and switch table | SelfLookPanePacketEventHandler : reconstructable : 86% : strong : Vtable-mapped packet/event child with owned switch data at `0x005697b5-0x00569860`, calls to exact adjacent helper children at `0x0056a640` and `0x0056b7c0`, packet readers, and SpelledPane dispatch; final protocol names remain provisional.
        - [UID:NEW-H7T][0x00569860-0x00569c80.SelfLookPaneOnShowHelp](by-memory/0x00569860-0x00569c80.SelfLookPaneOnShowHelp.md) 0x00569860-0x00569c80 | help method and switch table | SelfLookPaneOnShowHelp : reconstructable : 85% : strong : Vtable-mapped help/tooltip method with owned switch data at `0x00569c3a-0x00569c80`, active-child/GeneralPurposePanel context, and class-local slot/help behavior; exact help text/source names remain unresolved.
        - [UID:NEW-H7U][0x00569c80-0x00569cce.SelfLookPaneOnGetRect](by-memory/0x00569c80-0x00569cce.SelfLookPaneOnGetRect.md) 0x00569c80-0x00569cce | geometry virtual | SelfLookPaneOnGetRect : reconstructable : 85% : strong : Vtable-mapped rectangle getter with exact class slot and compact behavior; final field names remain provisional.
        - [UID:NEW-H7V][0x00569cd0-0x00569d75.SelfLookPaneOnTransformRect](by-memory/0x00569cd0-0x00569d75.SelfLookPaneOnTransformRect.md) 0x00569cd0-0x00569d75 | geometry virtual | SelfLookPaneOnTransformRect : reconstructable : 85% : strong : Vtable-mapped rectangle transform method with exact bounds and class-local receiver behavior; final source spelling remains unresolved.
        - [UID:NEW-H7W][0x00569d80-0x00569ec1.SelfLookPaneDrawNumberString](by-memory/0x00569d80-0x00569ec1.SelfLookPaneDrawNumberString.md) 0x00569d80-0x00569ec1 | drawing helper | SelfLookPaneDrawNumberString : reconstructable : 85% : strong : Numeric drawing helper called repeatedly by OnPaint with exact helper bounds and render behavior; exact font/color/member names remain provisional.
        - [UID:NEW-H7X][0x00569ed0-0x0056a300.SelfLookPaneGetSlotColors](by-memory/0x00569ed0-0x0056a300.SelfLookPaneGetSlotColors.md) 0x00569ed0-0x0056a300 | slot geometry/color helper and switch table | SelfLookPaneGetSlotColors : reconstructable : 86% : strong : Shared SelfLookPane slot geometry/color helper called by toggles, paint, mouse, hit-test, and raw stats helper, with owned switch data at `0x0056a29e-0x0056a300`; exact record/field names remain provisional.
        - [UID:NEW-H7Y][0x0056a300-0x0056a373.SelfLookPaneHitTestSlot](by-memory/0x0056a300-0x0056a373.SelfLookPaneHitTestSlot.md) 0x0056a300-0x0056a373 | hit-test helper | SelfLookPaneHitTestSlot : reconstructable : 85% : strong : Slot hit-test helper called from mouse handling, iterating slot ids through GetSlotColors and returning `0xffff` on miss; exact slot enum names remain unresolved.
```

Keep the existing ignored padding rows immediately before and after this block. Do not add internal ignored padding rows unless validator/memory-range refresh requires it; the non-emitting parent index can preserve the internal alignment evidence. If explicit internal padding rows are later required, byte-confirm each `0xcc` range first instead of deriving rows only from function sizes.

### 5. Validation order

Recommended order after supervisor applies the split:

1. Validate every new child page:
   `python .\tools\validator.py --mode file --file by-memory\<child>.md --apply --lock-timeout -1`
2. Validate parent:
   `python .\tools\validator.py --mode file --file by-memory\0x00565610-0x0056a373.SelfLookPane.md --apply --lock-timeout -1`
3. Validate support docs:
   `python .\tools\validator.py --mode file --file by-class\SelfLookPane.md --apply --lock-timeout -1`
   `python .\tools\validator.py --mode file --file by-file\SelfLookPane.md --apply --lock-timeout -1`
4. Validate shared coverage report after applying the replacement block:
   `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`
5. Rerun memory tool:
   `python .\tools\memory_ranges.py report`
6. Confirm `auto-generated/by-memory-tool-report.md` no longer lists `0x00565610-0x0056a373.SelfLookPane.md` as a large reconstructable leaf and that Barrier/General/Filename/Advanced scans remain clean.

## IDA DB Recommendation

Do not edit the IDA DB for this assignment.

Reason:

- IDA already has accurate function objects for the modeled methods.
- Raw bodies have no direct xrefs or pointer/relative-branch evidence; creating functions at those starts would be a speculative database mutation.
- The documentation split can preserve raw-body evidence without requiring IDA function creation.
- Switch tables are local method data and do not need IDA retyping before documentation can be correct.

## No-Direct-Edit Confirmation

B001 did not edit by-* docs, generated reports, IDA DB, or `by-memory/-coverage-report.md`. This report is the only file created for the assignment.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B001/research/0001H7-selflookpane-source-split-audit.md`
- Modified: none outside the report.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0001H7-selflookpane-source-split-audit.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:19","uid":"0001H7"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
