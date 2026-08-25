** TARGET-REPORT-UID:0001HK **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B001 Goal 2 Research: [UID:0001HK] SelfLookPane2 Source Split Audit

Assignment: `B001-goal2-memory-tool-selflookpane2-source-split-0001HK-20260616`

Target: [UID:0001HK] `by-memory/0x0056fe80-0x005729c3.SelfLookPane2.md`

Report date: 2026-06-16

## Final Recommendation

Split [UID:0001HK] into exact `SelfLookPane2` method/helper child pages and reclassify the parent as a non-emitting class-method split index.

Recommended parent metadata after the split:

```text
COMPLETION:88
CONFIDENCE:90
CANONICAL_OWNER:0000CV
RECONSTRUCTABLE:FALSE
EMITTER_UIDS:
```

The current direct owner/emitter [UID:0000NL] `SelfLookPane` is a valid source-file route, but it is too coarse for the executable class method span. The direct source owner should be [UID:0000CV] `SelfLookPane2`, with [UID:0000NL] retained as the file parent route.

Do not write parent final C++. Exact children should carry reconstructable evidence, and all child final C++ should remain blank until field names, packet enum names, and helper names are final-quality.

No IDA DB edits are recommended. IDA already models the normal functions, and the raw helper starts have no direct xrefs or hidden branch/pointer routes. Creating IDA functions at those raw starts would improve navigation but would encode speculative liveness.

## Current State Checked

- Target [UID:0001HK] is currently `82/86`, `CANONICAL_OWNER:0000NL`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000NL`, blank final C++.
- `auto-generated/by-memory-tool-report.md` was already refreshed after the [UID:0001H7] SelfLookPane split and reports Barrier Crossings, General Errors, Filename Errors, and Advanced-Error-Scan as `None`; [UID:0001HK] remains a largest reconstructable leaf.
- `by-memory/-coverage-report.md` still has a stale [UID:0001HK] row at `78%` and a separate ignored row for `0x005729c3-0x005729e0`.
- The executed [UID:0001H7] SelfLookPane split is the closest local precedent: exact child pages carry source-bearing evidence, while the contiguous main span is a `not_reconstructable` class method split index.

## Evidence Checked

### Live IDA/MCP

Live IDA session: `b001_selflookpane_0001H7_20260616`, image `NexusTK.exe`, imagebase `0x400000`.

IDA function inventory for `0x0056fe70-0x005729e0`:

```text
0x0056fe70 sub_56FE70 size 0x5      preceding CollectionPane2 false stub
0x0056fe80 sub_56FE80 size 0x1ac    SelfLookPane2 constructor
0x00570030 sub_570030 size 0xa7     non-deleting destructor helper
0x005700e0 sub_5700E0 size 0x84c    draw/parse/update method
0x00570930 nullsub_52 size 0x1      no-op stub
0x00570c00 sub_570C00 size 0x80     default-view switch
0x00570c80 sub_570C80 size 0x197    spelled-view switch
0x00570ef0 sub_570EF0 size 0xc3     legend-view switch
0x00570fc0 sub_570FC0 size 0xc45    paint
0x00571c10 sub_571C10 size 0xa2     key handler
0x00571cc0 sub_571CC0 size 0x43f    input/event handler
0x00572120 sub_572120 size 0x4cd    packet/event helper
0x005726a0 sub_5726A0 size 0xd1     stat text draw helper
0x00572780 sub_572780 size 0x105    button rect helper
0x005728a0 sub_5728A0 size 0x123    button hit-test helper
```

IDA has no function objects at raw helper starts `0x00570940`, `0x00570a00`, `0x00570ac0`, `0x00570b80`, `0x00570ba0`, `0x00570bc0`, or `0x00570be0`.

Xref highlights:

- `0x0056fe80` constructor: no direct xrefs found, but it stores `SelfLookPane2` vtables and constructs child panes through `SpelledPane` constructor xref `0x0056ff1e -> 0x0056bb20` and `LegendPane` constructor xref `0x0056ff6e -> 0x0056c400`.
- Vtable/data refs prove normal virtual method routing:
  - `0x005700e0` from `0x00624740`
  - `0x00570fc0` from `0x0062473c`
  - `0x00571c10` from `0x00624750`
  - `0x00571cc0` from `0x0062474c`
  - `0x00572120` from `0x00624758`
- View helpers are internally called:
  - `0x00570c00` from `0x00571c5b`, `0x00571f97`
  - `0x00570c80` from `0x00570904`, `0x00571c9d`, `0x00571f89`, `0x00571fcc`
  - `0x00570ef0` from `0x005708fb`, `0x00571c86`, `0x00571fda`
- Geometry helpers are internally called:
  - `0x005726a0` from `0x005719c6`, `0x00571a7f`, `0x00571b3f`
  - `0x00572780` from 13 call sites including the three raw toggles, paint, and input handling
  - `0x005728a0` from `0x00571d20`, `0x00571e1e`

### Raw helper evidence

Raw-byte inspection confirms source-shaped bodies, not padding:

- `0x00570940-0x005709fa`: stack-cookie packet toggle body. It rate-limits through `this+0x970/0x974`, toggles byte `this+0x979`, sends opcode `0x1b` subtype `0x08`, redraws button `0` through `0x00572780`, and returns.
- `0x00570a00-0x00570aba`: same shape, toggles `this+0x978`, sends subtype `0x02`, redraws button `1`, and returns.
- `0x00570ac0-0x00570b7a`: same shape, toggles `this+0x97a`, sends subtype `0x0b`, redraws button `2`, and returns.
- `0x00570b80-0x00570b9a`: raw forwarder through the `SpelledPane` child at `this+0xfc` to `0x0056bca0`, `retn 8`.
- `0x00570ba0-0x00570bb7`: raw forwarder through `this+0xfc` to `0x0056be20`, `retn 4`.
- `0x00570bc0-0x00570bde`: raw child refresh/body using `this+0xfc`, `0x004b6d20`, and `0x004b6d00` against the child offset `+0x174`.
- `0x00570be0-0x00570bf1`: raw child refresh/state helper through `this+0xfc+0x174`.

These are source-bearing class-local bodies by layout and behavior, but no direct liveness route was found. They should be exact reconstructable child evidence with blank C++, matching the accepted [UID:0001H7] raw helper treatment.

### Local PE scan

I scanned `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` for little-endian VA dwords, RVA dwords, and `.text` rel32 call/jump targets.

Important results:

- No VA hits, RVA hits, or rel32 call/jump hits for `0x0056fe80`, `0x00570030`, `0x00570930`, `0x00570940`, `0x00570a00`, `0x00570ac0`, `0x00570b80`, `0x00570ba0`, `0x00570bc0`, `0x00570be0`, `0x005729c3`, or `0x005729e0`.
- Vtable/data VA hits match IDA for `0x005700e0`, `0x00570fc0`, `0x00571c10`, `0x00571cc0`, and `0x00572120`.
- rel32 hits match IDA for `0x00570c00`, `0x00570c80`, `0x00570ef0`, `0x005726a0`, `0x00572780`, and `0x005728a0`.

This rules out hidden pointer-table or direct-branch evidence for raw helper entry points. It also supports leaving IDA untouched.

### Tail data/alignment

The current ignored row `0x005729c3-0x005729e0` is not unrelated padding. It contains the local jump-table tail for the `SelfLookPane2` hit-test helper plus final `0xcc` alignment before [UID:00023X] `LookPanePacketAndEntryVectorHelpers` at `0x005729e0`.

Because this span is outside the current [UID:0001HK] target range and is compiler output rather than handwritten source, it should remain ignored. Its row and `by-memory/-ignored.md` text should be updated to reference the new `SelfLookPane2HitTestButton` child rather than the unsplit parent.

### Support docs checked

- [UID:0000CV] `by-class/SelfLookPane2.md`: confirms `SelfLookPane2` class role, source-file route through [UID:0000NL], existing children [UID:00039L], [UID:00039M], [UID:00039N], and [UID:00039E].
- [UID:0000NL] `by-file/SelfLookPane.md`: confirms both `SelfLookPane` and `SelfLookPane2` live under the same file route. It already notes that the `SelfLookPane2` toggle helper names need audit.
- [UID:0001H7] `by-memory/0x00565610-0x0056a373.SelfLookPane.md`: executed split precedent, with direct class owner, non-emitting parent, exact method children, raw no-function children, and ignored padding retained separately.
- [UID:00039L], [UID:00039M], [UID:00039N], [UID:00039E]: existing exact `SelfLookPane2` children outside the main span. Their owner/emitter routing to [UID:0000CV] remains correct.
- [UID:00039O] `SpelledPaneEntryVectorInsert`: remains [UID:0000DK] `SpelledPane`, not `SelfLookPane2`.
- `SelfLookPaneFamilyVtables` and `SelfLookPane2VtableData`: vtable data anchors the class route and destructor relationships.
- `SelfLookPane2` resource-string children `0x00624b74-0x00624b90` and `0x00624ba8-0x00624bd0`: confirm source-local resource use by `0x00570fc0`; no owner change needed.

## Rejected Alternatives

### Keep [UID:0001HK] as a reconstructable aggregate

Rejected. The range now has enough exact boundary, xref, raw-body, vtable, and precedent evidence for a safe split. Keeping it as one reconstructable leaf preserves stale completion debt and forces final C++ blockers at the parent level even though exact children can carry the evidence.

### Treat raw helper starts as dead/duplicate non-emitting bodies

Rejected. The raw starts are not padding, thunks, or simple compiler artifacts. They are complete class-local packet and child-forwarder bodies, match accepted `SelfLookPane` raw helper patterns, and call class-local geometry/redraw or `SpelledPane` child helpers. The missing direct xrefs cap liveness confidence and final C++ readiness, but do not justify discarding them as dead evidence.

### Move raw forwarders to `SpelledPane`

Rejected. The bodies receive `SelfLookPane2 this`, load the `SpelledPane` child pointer from `this+0xfc`, and forward into `SpelledPane`. They are wrapper methods in the `SelfLookPane2` source surface, not `SpelledPane` implementation bodies.

### Keep direct owner/emitter as [UID:0000NL] file

Partially rejected. [UID:0000NL] is the right source-file route, but the direct executable method owner should be [UID:0000CV] `SelfLookPane2`, matching the executed [UID:0001H7] class-owned split.

### Merge [UID:0001HK] with [UID:00023X] or existing [UID:00039L]/[UID:00039M]/[UID:00039N]

Rejected. `0x005729e0` is an exact boundary where the later mixed helper island begins. [UID:00023X] is already a non-emitting mixed inventory with exact child pages. The `0x005729c3-0x005729e0` tail is compiler output associated with the preceding hit-test helper, not evidence that the two ranges should merge.

### IDA function creation at raw starts

Rejected for now. IDA function creation would be navigational only. The PE scan found no direct pointers or branch targets to those raw starts, so adding functions could make retained/no-xref code look more live than the evidence supports.

## Recommended Child Inventory

Allocate new UIDs for the placeholders below. Every reconstructable child clears a defensible `85/85` gate; the one-byte null stub is intentionally non-reconstructable.

All reconstructable children should use:

```text
CANONICAL_OWNER:0000CV
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000CV
```

The null stub should use:

```text
CANONICAL_OWNER:0000CV
RECONSTRUCTABLE:FALSE
EMITTER_UIDS:
```

| Placeholder UID | New page | Score | Role |
| --- | --- | ---: | --- |
| `NEW-HK01` | `by-memory/0x0056fe80-0x0057002c.SelfLookPane2Constructor.md` | `86/90` | Constructor, vtable stores, `SpelledPane`/`LegendPane` child construction, no direct constructor xref. |
| `NEW-HK02` | `by-memory/0x00570030-0x005700d7.SelfLookPane2NonDeletingDestructor.md` | `86/90` | Non-deleting destructor/cleanup helper, vtable restore path, no direct xref. |
| `NEW-HK03` | `by-memory/0x005700e0-0x0057092c.SelfLookPane2OnDraw.md` | `86/89` | Vtable-routed draw/update method, calls view switch helpers. |
| `NEW-HK04` | `by-memory/0x00570930-0x00570931.SelfLookPane2NullStub.md` | `85/88` | One-byte `retn` null stub, non-emitting evidence only. |
| `NEW-HK05` | `by-memory/0x00570940-0x005709fa.SelfLookPane2SendToggleLookRaw.md` | `85/89` | Raw no-function packet toggle, subtype `0x08`, redraw button `0`. |
| `NEW-HK06` | `by-memory/0x00570a00-0x00570aba.SelfLookPane2SendToggleEquipRaw.md` | `85/89` | Raw no-function packet toggle, subtype `0x02`, redraw button `1`. |
| `NEW-HK07` | `by-memory/0x00570ac0-0x00570b7a.SelfLookPane2SendToggleStatsRaw.md` | `85/89` | Raw no-function packet toggle, subtype `0x0b`, redraw button `2`. |
| `NEW-HK08` | `by-memory/0x00570b80-0x00570b9a.SelfLookPane2SpelledEntryUpdateForwarderRaw.md` | `85/88` | Raw forwarder through `this+0xfc` to `SpelledPane` update helper `0x0056bca0`. |
| `NEW-HK09` | `by-memory/0x00570ba0-0x00570bb7.SelfLookPane2SpelledEntryRemoveForwarderRaw.md` | `85/88` | Raw forwarder through `this+0xfc` to `SpelledPane` remove helper `0x0056be20`. |
| `NEW-HK10` | `by-memory/0x00570bc0-0x00570bde.SelfLookPane2RefreshSpelledChildRaw.md` | `85/88` | Raw child refresh/body using `this+0xfc` and `this+0xfc+0x174`. |
| `NEW-HK11` | `by-memory/0x00570be0-0x00570bf1.SelfLookPane2RefreshSpelledChildStateRaw.md` | `85/88` | Raw refresh/state helper through the `SpelledPane` child state area. |
| `NEW-HK12` | `by-memory/0x00570c00-0x00570c80.SelfLookPane2ShowDefaultView.md` | `86/89` | Default-view switch helper, internally called from key/event paths. |
| `NEW-HK13` | `by-memory/0x00570c80-0x00570e17.SelfLookPane2ShowSpelledView.md` | `86/89` | Spelled-view switch helper, called from draw/key/event paths. |
| `NEW-HK14` | `by-memory/0x00570ef0-0x00570fb3.SelfLookPane2ShowLegendView.md` | `85/89` | Legend-view switch helper, called from draw/key/event paths. |
| `NEW-HK15` | `by-memory/0x00570fc0-0x00571c05.SelfLookPane2OnPaint.md` | `86/90` | Vtable-routed paint method, resource string refs, calls stat text and button rect helpers. |
| `NEW-HK16` | `by-memory/0x00571c10-0x00571cb2.SelfLookPane2HandleKeyEvent.md` | `85/89` | Vtable-routed key handler, routes view switching. |
| `NEW-HK17` | `by-memory/0x00571cc0-0x005720ff.SelfLookPane2HandleEvent.md` | `86/90` | Vtable-routed input/event handler, hit-tests buttons and sends toggle packets. |
| `NEW-HK18` | `by-memory/0x00572120-0x005725ed.SelfLookPane2PacketEventHelper.md` | `86/90` | Vtable-routed packet/event helper, packet readers, state writes, `SpelledPane` add/remove dispatch. |
| `NEW-HK19` | `by-memory/0x005726a0-0x00572771.SelfLookPane2DrawStatText.md` | `85/89` | Stat text drawing helper called by paint. |
| `NEW-HK20` | `by-memory/0x00572780-0x00572885.SelfLookPane2GetButtonRect.md` | `86/90` | Button rectangle helper called by raw toggles, paint, and input. |
| `NEW-HK21` | `by-memory/0x005728a0-0x005729c3.SelfLookPane2HitTestButton.md` | `86/90` | Button hit-test helper called by input; successor `0x005729c3-0x005729e0` remains ignored compiler table/alignment. |

## Exact Supervisor Actions

### 1. Create exact child pages

Create the 21 pages listed in the child inventory. Use the metadata values and evidence in this report. Keep every `RECONSTRUCTION_CPP` block blank. Mark only `NEW-HK04` `RECONSTRUCTABLE:FALSE`; all other child pages should be reconstructable.

Each child page should cross-reference:

- [UID:0001HK] parent split index.
- [UID:0000CV] `SelfLookPane2`.
- [UID:0000NL] `SelfLookPane` source file route.
- Relevant helpers:
  - `SelfLookPane2VtableData` for vtable-routed methods.
  - [UID:0000DK] `SpelledPane` for raw child forwarders.
  - [UID:000074] `LegendPane` for constructor/view evidence.
  - [UID:00039L], [UID:00039M], [UID:00039N] for adjacent `SelfLookPane2` packet/update helper continuity where useful.

### 2. Update [UID:0001HK] parent page

Edit `by-memory/0x0056fe80-0x005729c3.SelfLookPane2.md`:

- Set metadata to `88/90`, `CANONICAL_OWNER:0000CV`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`.
- Replace aggregate reconstructable language with non-emitting class method split-index language.
- Add the child split table above.
- Preserve the raw helper no-xref caveat and constructor no-direct-xref caveat.
- State that `0x005729c3-0x005729e0` remains an ignored compiler jump-table/alignment tail associated with `SelfLookPane2HitTestButton`, not a source-bearing child.

### 3. Update support docs

Edit `by-class/SelfLookPane2.md`:

- Add the 21 new child links.
- Raise to `COMPLETION:88`, `CONFIDENCE:90`.
- Keep source-file route through [UID:0000NL].
- Note that [UID:00039L], [UID:00039M], [UID:00039N], and [UID:00039E] remain existing exact `SelfLookPane2` children outside the main span.

Edit `by-file/SelfLookPane.md`:

- Add a short note that [UID:0001HK] now follows the executed [UID:0001H7] model: non-emitting main-span index plus exact `SelfLookPane2` child methods.
- Raise to `COMPLETION:87`, keep `CONFIDENCE:90`.
- Keep the file-level route for both [UID:0000CU] `SelfLookPane` and [UID:0000CV] `SelfLookPane2`.

Edit `by-type/by-vtable/SelfLookPaneFamilyVtables.md` and `by-memory/0x006246f4-0x00624780.SelfLookPane2VtableData.md` only if the supervisor wants cross-reference completeness:

- Add cross-links from the `SelfLookPane2` vtable slots to the newly created child pages.
- No score change is required.

No changes are recommended for [UID:00039L], [UID:00039M], [UID:00039N], [UID:00039O], or [UID:00039E].

### 4. Update ignored-tail documentation

Edit `by-memory/-ignored.md` in the existing list entry that includes `0x005729c3-0x005729e0`.

Replace the current explanation phrase:

```text
except `0x005729c3-0x005729e0`, which is a switch/jump-table tail plus alignment after `SelfLookPane2` code.
```

with:

```text
except `0x005729c3-0x005729e0`, which is the compiler switch/jump-table tail plus alignment immediately after `SelfLookPane2HitTestButton` and before [UID:00023X][0x005729e0-0x00573232.LookPanePacketAndEntryVectorHelpers](by-memory/0x005729e0-0x00573232.LookPanePacketAndEntryVectorHelpers.md).
```

Add evidence text:

```text
2026-06-16 B001 SelfLookPane2 split audit reconfirmed the `0x005729c3-0x005729e0` bytes as hit-test switch/jump-table data plus alignment, with no VA/RVA pointer hits or rel32 branch targets to the tail start.
```

### 5. Update `by-memory/-coverage-report.md`

Placement context: replace the existing [UID:0001HK] row and the immediately following [UID:0000VN] `0x005729c3-0x005729e0` ignored row between these existing rows:

```text
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0056fe75-0x0056fe80 | padding | CollectionPane to SelfLookPane2 alignment : ignored : 100% : strong : IDA confirms `0xcc` alignment bytes.
    ...
    - [UID:00023X][0x005729e0-0x00573232.LookPanePacketAndEntryVectorHelpers](by-memory/0x005729e0-0x00573232.LookPanePacketAndEntryVectorHelpers.md) 0x005729e0-0x00573232 | mixed helper island | LookPanePacketAndEntryVectorHelpers : ignored : 88% : strong : Confidence 91; reviewed non-emitting mixed helper index after exact split. Exact children carry source ownership: SelfLookPane2 packet/update/dispatch children attach to `0000CV`, and SpelledPane vector insertion attaches to `0000DK`; aggregate remains parentless because no single direct semantic parent is correct.
```

Use this replacement block after assigning real UIDs:

```text
    - [UID:0001HK][0x0056fe80-0x005729c3.SelfLookPane2](by-memory/0x0056fe80-0x005729c3.SelfLookPane2.md) 0x0056fe80-0x005729c3 | class method split index | SelfLookPane2 : not_reconstructable : 88% : strong : Reclassified non-emitting SelfLookPane2 main-span split index after exact method-child pages cover constructor/destructor, draw/update, raw packet toggles, raw SpelledPane forwarders, view switching, paint/key/input/packet handling, stat drawing, button geometry, and hit-test helpers; direct source owner is [UID:0000CV][SelfLookPane2](by-class/SelfLookPane2.md), with source-file route through [UID:0000NL][SelfLookPane](by-file/SelfLookPane.md). Parent C++ remains blank; exact children carry reconstruction evidence.
        - [UID:NEW-HK01][0x0056fe80-0x0057002c.SelfLookPane2Constructor](by-memory/0x0056fe80-0x0057002c.SelfLookPane2Constructor.md) 0x0056fe80-0x0057002c | constructor | SelfLookPane2Constructor : reconstructable : 86% : strong : Constructor with SelfLookPane2 vtable stores, SpelledPane/LegendPane child construction, and class-local state setup; no direct constructor caller found, so final source naming/lifetime remains blank.
        - [UID:NEW-HK02][0x00570030-0x005700d7.SelfLookPane2NonDeletingDestructor](by-memory/0x00570030-0x005700d7.SelfLookPane2NonDeletingDestructor.md) 0x00570030-0x005700d7 | destructor helper | SelfLookPane2NonDeletingDestructor : reconstructable : 86% : strong : Non-deleting destructor/cleanup helper with vtable restore and child/state cleanup evidence; no direct start xref found.
        - [UID:NEW-HK03][0x005700e0-0x0057092c.SelfLookPane2OnDraw](by-memory/0x005700e0-0x0057092c.SelfLookPane2OnDraw.md) 0x005700e0-0x0057092c | draw/update method | SelfLookPane2OnDraw : reconstructable : 86% : strong : Vtable-routed draw/update method calling SelfLookPane2 view-switch helpers and resource/text helpers; exact field and helper names remain provisional.
        - [UID:NEW-HK04][0x00570930-0x00570931.SelfLookPane2NullStub](by-memory/0x00570930-0x00570931.SelfLookPane2NullStub.md) 0x00570930-0x00570931 | null stub | SelfLookPane2NullStub : not_reconstructable : 85% : strong : One-byte `retn` stub with no caller, vtable slot, pointer-byte hit, RVA hit, or relative branch hit; retained as non-emitting evidence only.
        - [UID:NEW-HK05][0x00570940-0x005709fa.SelfLookPane2SendToggleLookRaw](by-memory/0x00570940-0x005709fa.SelfLookPane2SendToggleLookRaw.md) 0x00570940-0x005709fa | raw packet toggle | SelfLookPane2SendToggleLookRaw : reconstructable : 85% : strong : Raw no-function packet toggle sends opcode `0x1b` subtype `0x08`, toggles `this+0x979`, redraws button 0, and has no direct start xref or hidden pointer/branch route.
        - [UID:NEW-HK06][0x00570a00-0x00570aba.SelfLookPane2SendToggleEquipRaw](by-memory/0x00570a00-0x00570aba.SelfLookPane2SendToggleEquipRaw.md) 0x00570a00-0x00570aba | raw packet toggle | SelfLookPane2SendToggleEquipRaw : reconstructable : 85% : strong : Raw no-function packet toggle sends opcode `0x1b` subtype `0x02`, toggles `this+0x978`, redraws button 1, and has no direct start xref or hidden pointer/branch route.
        - [UID:NEW-HK07][0x00570ac0-0x00570b7a.SelfLookPane2SendToggleStatsRaw](by-memory/0x00570ac0-0x00570b7a.SelfLookPane2SendToggleStatsRaw.md) 0x00570ac0-0x00570b7a | raw packet toggle | SelfLookPane2SendToggleStatsRaw : reconstructable : 85% : strong : Raw no-function packet toggle sends opcode `0x1b` subtype `0x0b`, toggles `this+0x97a`, redraws button 2, and has no direct start xref or hidden pointer/branch route.
        - [UID:NEW-HK08][0x00570b80-0x00570b9a.SelfLookPane2SpelledEntryUpdateForwarderRaw](by-memory/0x00570b80-0x00570b9a.SelfLookPane2SpelledEntryUpdateForwarderRaw.md) 0x00570b80-0x00570b9a | raw child forwarder | SelfLookPane2SpelledEntryUpdateForwarderRaw : reconstructable : 85% : strong : Raw forwarder through the SelfLookPane2 `SpelledPane` child pointer at `this+0xfc` to `0x0056bca0`; no direct start xref or hidden pointer/branch route.
        - [UID:NEW-HK09][0x00570ba0-0x00570bb7.SelfLookPane2SpelledEntryRemoveForwarderRaw](by-memory/0x00570ba0-0x00570bb7.SelfLookPane2SpelledEntryRemoveForwarderRaw.md) 0x00570ba0-0x00570bb7 | raw child forwarder | SelfLookPane2SpelledEntryRemoveForwarderRaw : reconstructable : 85% : strong : Raw forwarder through the SelfLookPane2 `SpelledPane` child pointer at `this+0xfc` to `0x0056be20`; no direct start xref or hidden pointer/branch route.
        - [UID:NEW-HK10][0x00570bc0-0x00570bde.SelfLookPane2RefreshSpelledChildRaw](by-memory/0x00570bc0-0x00570bde.SelfLookPane2RefreshSpelledChildRaw.md) 0x00570bc0-0x00570bde | raw child refresh helper | SelfLookPane2RefreshSpelledChildRaw : reconstructable : 85% : strong : Raw refresh helper operating on `this+0xfc` and child offset `+0x174`; no direct start xref or hidden pointer/branch route.
        - [UID:NEW-HK11][0x00570be0-0x00570bf1.SelfLookPane2RefreshSpelledChildStateRaw](by-memory/0x00570be0-0x00570bf1.SelfLookPane2RefreshSpelledChildStateRaw.md) 0x00570be0-0x00570bf1 | raw child refresh helper | SelfLookPane2RefreshSpelledChildStateRaw : reconstructable : 85% : strong : Raw state refresh helper through the SelfLookPane2 `SpelledPane` child state area; no direct start xref or hidden pointer/branch route.
        - [UID:NEW-HK12][0x00570c00-0x00570c80.SelfLookPane2ShowDefaultView](by-memory/0x00570c00-0x00570c80.SelfLookPane2ShowDefaultView.md) 0x00570c00-0x00570c80 | view helper | SelfLookPane2ShowDefaultView : reconstructable : 86% : strong : Default-view switch helper called by key and input/event paths.
        - [UID:NEW-HK13][0x00570c80-0x00570e17.SelfLookPane2ShowSpelledView](by-memory/0x00570c80-0x00570e17.SelfLookPane2ShowSpelledView.md) 0x00570c80-0x00570e17 | view helper | SelfLookPane2ShowSpelledView : reconstructable : 86% : strong : Spelled-view switch helper called by draw, key, and input/event paths.
        - [UID:NEW-HK14][0x00570ef0-0x00570fb3.SelfLookPane2ShowLegendView](by-memory/0x00570ef0-0x00570fb3.SelfLookPane2ShowLegendView.md) 0x00570ef0-0x00570fb3 | view helper | SelfLookPane2ShowLegendView : reconstructable : 85% : strong : Legend-view switch helper called by draw, key, and input/event paths.
        - [UID:NEW-HK15][0x00570fc0-0x00571c05.SelfLookPane2OnPaint](by-memory/0x00570fc0-0x00571c05.SelfLookPane2OnPaint.md) 0x00570fc0-0x00571c05 | paint method | SelfLookPane2OnPaint : reconstructable : 86% : strong : Vtable-routed paint method with SelfLookPane2 resource-string refs, stat text drawing, button rectangle calls, and provisional field/helper names.
        - [UID:NEW-HK16][0x00571c10-0x00571cb2.SelfLookPane2HandleKeyEvent](by-memory/0x00571c10-0x00571cb2.SelfLookPane2HandleKeyEvent.md) 0x00571c10-0x00571cb2 | key handler | SelfLookPane2HandleKeyEvent : reconstructable : 85% : strong : Vtable-routed key handler that dispatches view-switch helpers; exact key enum names remain unresolved.
        - [UID:NEW-HK17][0x00571cc0-0x005720ff.SelfLookPane2HandleEvent](by-memory/0x00571cc0-0x005720ff.SelfLookPane2HandleEvent.md) 0x00571cc0-0x005720ff | input/event handler | SelfLookPane2HandleEvent : reconstructable : 86% : strong : Vtable-routed input/event handler that hit-tests buttons, routes view switches, sends toggle packets, and calls button-rect/hit-test helpers.
        - [UID:NEW-HK18][0x00572120-0x005725ed.SelfLookPane2PacketEventHelper](by-memory/0x00572120-0x005725ed.SelfLookPane2PacketEventHelper.md) 0x00572120-0x005725ed | packet/event helper | SelfLookPane2PacketEventHelper : reconstructable : 86% : strong : Vtable-routed packet/event helper using packet readers, state writes, text/resource helpers, and SpelledPane add/remove dispatch.
        - [UID:NEW-HK19][0x005726a0-0x00572771.SelfLookPane2DrawStatText](by-memory/0x005726a0-0x00572771.SelfLookPane2DrawStatText.md) 0x005726a0-0x00572771 | draw helper | SelfLookPane2DrawStatText : reconstructable : 85% : strong : Stat text drawing helper called from paint; exact label/field names remain provisional.
        - [UID:NEW-HK20][0x00572780-0x00572885.SelfLookPane2GetButtonRect](by-memory/0x00572780-0x00572885.SelfLookPane2GetButtonRect.md) 0x00572780-0x00572885 | geometry helper | SelfLookPane2GetButtonRect : reconstructable : 86% : strong : Button rectangle helper with thirteen call sites from raw toggles, paint, and input/event handling.
        - [UID:NEW-HK21][0x005728a0-0x005729c3.SelfLookPane2HitTestButton](by-memory/0x005728a0-0x005729c3.SelfLookPane2HitTestButton.md) 0x005728a0-0x005729c3 | hit-test helper | SelfLookPane2HitTestButton : reconstructable : 86% : strong : Button hit-test helper called by input/event handling; successor `0x005729c3-0x005729e0` is compiler switch/jump-table data plus alignment.
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x005729c3-0x005729e0 | compiler data/padding | SelfLookPane2 HitTestButton switch tail : ignored : 85% : strong : B001 live IDA/raw-byte audit shows this is local switch/jump-table data plus final alignment after SelfLookPane2HitTestButton and before [UID:00023X][0x005729e0-0x00573232.LookPanePacketAndEntryVectorHelpers](by-memory/0x005729e0-0x00573232.LookPanePacketAndEntryVectorHelpers.md); no source/emitter row is appropriate.
```

## Validation Order

After supervisor applies accepted changes:

1. Run targeted validator passes for every new child page, the edited parent page, `by-class/SelfLookPane2.md`, `by-file/SelfLookPane.md`, and `by-memory/-ignored.md`:

> Executable block R001 was removed from this report and preserved verbatim in [0001HK-selflookpane2-source-split-audit-removed.md](0001HK-selflookpane2-source-split-audit-removed.md). The archived block is non-authoritative and must not be executed.

2. Apply the `by-memory/-coverage-report.md` replacement block only after the new UIDs exist, then run:

> Executable block R002 was removed from this report and preserved verbatim in [0001HK-selflookpane2-source-split-audit-removed.md](0001HK-selflookpane2-source-split-audit-removed.md). The archived block is non-authoritative and must not be executed.

3. Run the supervisor's normal memory-tool report refresh and confirm [UID:0001HK] is no longer listed as a largest reconstructable leaf, with no Barrier/General/Filename/Advanced errors.

4. Spot-check that [UID:00023X], [UID:00039L], [UID:00039M], [UID:00039N], [UID:00039O], and [UID:00039E] still validate unchanged.

## Remaining Blockers

- Exact original names for toggle helpers, state fields, packet enum values, and child-pane member fields remain unresolved. Evidence checked: live IDA callees/xrefs, raw helper bytes, support class/file docs, resource-string children, and local PE scans. No debug/source strings or typed layout evidence was found that safely resolves those names. This blocks final C++ on children but does not block exact split/source ownership.
- Constructor liveness remains unresolved. Evidence checked: IDA xrefs to `0x0056fe80`, local VA/RVA pointer scan, and rel32 branch scan all found no direct route. Vtable stores, child constructor calls, and class-local layout are sufficient for class ownership, but not for final lifetime-source wording.
- Raw helper liveness remains unresolved. Evidence checked: IDA xrefs, local VA/RVA pointer scan, and rel32 branch scan for all raw starts. No route was found. They should remain reconstructable evidence with blank C++, not IDA-created live functions.

## No Direct Edit Confirmation

B001 made no direct edits to by-* docs, generated reports, IDA DB, or `by-memory/-coverage-report.md` for this assignment. This report is the only file created.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0001HK-selflookpane2-source-split-audit.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:19","uid":"0001HK"} -->
<!-- {"agent":"B001","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001HK-selflookpane2-source-split-audit-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B001/0001HK-selflookpane2-source-split-audit.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001HK"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
