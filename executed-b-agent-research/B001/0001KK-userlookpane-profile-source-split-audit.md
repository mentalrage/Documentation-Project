** TARGET-REPORT-UID:0001KK **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B001 Goal 2 Research: [UID:0001KK] UserLookPane/Profile Source Split Audit

Assignment: `B001-goal2-memory-tool-userlookpane-profile-source-split-0001KK-20260616`

Target: [UID:0001KK] `by-memory/0x0059f260-0x005a2523.UserLookPaneAndProfilePanes.md`

Report date: 2026-06-16

## Final Recommendation

Split [UID:0001KK][0x0059f260-0x005a2523.UserLookPaneAndProfilePanes](../../../../../by-memory/0x0059f260-0x005a2523.UserLookPaneAndProfilePanes.md) into exact method/raw-helper children, then reclassify the parent as a non-emitting `UserLookPane.cpp` source-family split index.

Recommended parent metadata after child pages exist:

```text
COMPLETION:88
CONFIDENCE:90
CANONICAL_OWNER:0000P0
RECONSTRUCTABLE:FALSE
EMITTER_UIDS:
```

The current file owner [UID:0000P0][UserLookPane](../../../../../by-file/UserLookPane.md) should remain the parent route because the physical span contains the `UserLookPane` class methods, local `MoreInfoPane` and `ProfilePane` bodies, two file-local raw packet helpers with no `this` receiver, and compiler adjustor thunks. A single class owner is too narrow for the aggregate, and emitting final C++ from the aggregate would duplicate the exact child pages.

Do not write parent final C++. Child final C++ should also remain blank until field names, protocol names, helper names, and raw-helper liveness/source names reach final-output quality.

No IDA DB edits are recommended. IDA already models the normal functions. The raw starts have no direct xrefs or hidden VA/RVA/rel32 routes, so creating IDA functions at those starts would improve navigation but would encode speculative liveness.

## Current State Checked

- Target [UID:0001KK] is currently `84/86`, `CANONICAL_OWNER:0000P0`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000P0`, blank final C++.
- `auto-generated/by-memory-tool-report.md` lists this as a 12,995-byte reconstructable leaf at rank 19.
- `by-memory/-coverage-report.md` still has one reconstructable aggregate row between existing ignored padding rows `0x0059f25b-0x0059f260` and `0x005a2523-0x005a2530`.
- `by-memory/-ignored.md` currently records only the outer alignment spans for this neighborhood; it has no internal UserLookPane thunk entry.

## Evidence Checked

### Existing Documentation

- Target [UID:0001KK] documents the constructor, destructor helper, packet/parser body, render body, input/key handlers, action-button geometry, view-switch helpers, local `MoreInfoPane` and `ProfilePane` virtual stubs, adjustor thunks, scalar deleting destructor, vtable/read-only data, singleton slot, and source-placement blockers.
- [UID:0000P0][UserLookPane](../../../../../by-file/UserLookPane.md) already routes `UserLookPane`, local `MoreInfoPane`, local `ProfilePane`, profile/biography/legend switching, packet parsing, rendering, and [UID:0002A8][MoreInfoPaneSingletonSlot](../../../../../by-memory/0x0069bed4-0x0069bed8.MoreInfoPaneSingletonSlot.md) through `NexusTK/ui/panels/UserLookPane.cpp`.
- [UID:0000FP][UserLookPane](../../../../../by-class/UserLookPane.md) covers the primary class methods and vtable route but is not broad enough for the whole range because the range also includes local child classes and file-local raw helpers.
- [UID:00008Q][MoreInfoPane](../../../../../by-class/MoreInfoPane.md) is already at `85/88` and routes the two false-return virtual methods to `UserLookPane.cpp`.
- [UID:0000AV][ProfilePane](../../../../../by-class/ProfilePane.md) is `82/88`; its owner/source route is right, but it needs a small support update before exact ProfilePane executable children are attached.
- [UID:00026V][UserLookReadOnlyData](../../../../../by-memory/0x0062eccc-0x0062ef0c.UserLookReadOnlyData.md), [UID:00038Q][UserLookPaneFamilyVtables](../../../../../by-type/by-vtable/UserLookPaneFamilyVtables.md), [UID:00038R][UserLookPaneVtableData](../../../../../by-memory/0x0062eccc-0x0062ed58.UserLookPaneVtableData.md), [UID:00038S][MoreInfoPaneVtableData](../../../../../by-memory/0x0062ed58-0x0062ee0c.MoreInfoPaneVtableData.md), and [UID:00038T][ProfilePaneVtableData](../../../../../by-memory/0x0062ee0c-0x0062eebc.ProfilePaneVtableData.md) already provide strong vtable/source-family support.
- [UID:000074][LegendPane](../../../../../by-class/LegendPane.md) and [UID:0000KM][LegendPane](../../../../../by-file/LegendPane.md) remain separate shared look-pane source. UserLookPane calls `LegendPane` construction and view switching but should not own `LegendPane`.
- [UID:0000MR][ProfileDialog](../../../../../by-file/ProfileDialog.md) explicitly separates `ProfilePane` from `ProfileDialog`; no route to `ProfileDialog.cpp` is supported.
- [UID:0000JQ][GeneralPurposePanel](../../../../../by-file/GeneralPurposePanel.md) constructs `UserLookPane` but does not own its parser/render/view source.
- [UID:0001KL][UserPane](../../../../../by-memory/0x005a2530-0x005b8395.UserPane.md) starts after thirteen `0xcc` bytes at `0x005a2530`; no UserPane merge is supported.

### Live IDA/MCP

Live IDA session: `b001_selflookpane_0001H7_20260616`, image `NexusTK.exe`, imagebase `0x400000`.

IDA function inventory for `0x0059f250-0x005a2540`:

```text
0x0059f260 sub_59F260 size 0x29d  end 0x0059f4fd  UserLookPane constructor
0x0059f500 sub_59F500 size 0x104  end 0x0059f604  non-deleting destructor helper
0x0059f610 sub_59F610 size 0x1016 end 0x005a0626  look/profile packet parser
0x005a0630 nullsub_63 size 0x1    end 0x005a0631  no-op stub
0x005a0640 sub_5A0640 size 0xf3d  end 0x005a157d  render body
0x005a1580 sub_5A1580 size 0x405  end 0x005a1985  mouse/input handler
0x005a19a0 sub_5A19A0 size 0xcf   end 0x005a1a6f  key handler
0x005a1a70 sub_5A1A70 size 0xdd   end 0x005a1b4d  action-button rect helper
0x005a1b70 sub_5A1B70 size 0x13f  end 0x005a1caf  action-button hit-test helper
0x005a1cd0 sub_5A1CD0 size 0x11e  end 0x005a1dee  show MoreInfo view
0x005a1df0 sub_5A1DF0 size 0x126  end 0x005a1f16  show Profile view
0x005a1f20 sub_5A1F20 size 0xc3   end 0x005a1fe3  show biography view
0x005a1ff0 sub_5A1FF0 size 0x198  end 0x005a2188  show Legend view
0x005a2340 sub_5A2340 size 0x5    end 0x005a2345  MoreInfoPane false virtual
0x005a2350 sub_5A2350 size 0x5    end 0x005a2355  MoreInfoPane false virtual
0x005a23c0 sub_5A23C0 size 0x5    end 0x005a23c5  ProfilePane false virtual
0x005a23d0 sub_5A23D0 size 0x5    end 0x005a23d5  ProfilePane false virtual
0x005a23d5 sub_5A23D5 size 0xb    end 0x005a23e0  adjustor thunk
0x005a23e0 sub_5A23E0 size 0xb    end 0x005a23eb  adjustor thunk
0x005a23f0 sub_5A23F0 size 0x133  end 0x005a2523  scalar deleting destructor
0x005a2530 sub_5A2530 size 0x72b  successor UserPane constructor
```

IDA has no function objects at `0x005a2190`, `0x005a2280`, `0x005a22e0`, or `0x005a2360`.

Important xrefs:

- Constructor `0x0059f260`: one code xref from `0x004b8477` in `GeneralPurposePanel` construction.
- Non-deleting destructor `0x0059f500`: no direct xrefs; vtable reset/cleanup shape matches constructor and scalar destructor evidence.
- Vtable/data refs prove virtual routing for parser/render/input/key and stubs:
  - `0x0059f610` from `0x0062ed14`
  - `0x005a0640` from `0x0062ed10`
  - `0x005a1580` from `0x0062ed20`
  - `0x005a19a0` from `0x0062ed24`
  - `0x005a2340` from `0x0062edd8`
  - `0x005a2350` from `0x0062edb8`
  - `0x005a23c0` from `0x0062ee8c`
  - `0x005a23d0` from `0x0062ee6c`
  - `0x005a23d5` from `0x0062ed1c`
  - `0x005a23e0` from `0x0062ed4c`
  - `0x005a23f0` from `0x0062eccc` plus thunk jumps.
- Internal call graph supports exact split:
  - `0x0059f610` calls `0x005a1cd0`.
  - `0x005a0640` calls `0x005a1a70`.
  - `0x005a1580` calls `0x005a1b70`, `0x005a1a70`, `0x005a1cd0`, `0x005a1df0`, `0x005a1f20`, and `0x005a1ff0`.
  - `0x005a19a0` calls `0x005a1cd0`, `0x005a1df0`, `0x005a1f20`, and `0x005a1ff0`.
- Vtable base refs:
  - `0x0062eccc` refs from constructor/destructor/scalar destructor contexts.
  - `0x0062ed58` refs from the inline `MoreInfoPane` construction in `UserLookPane` constructor and the raw `MoreInfoPane` constructor body.
  - `0x0062ee0c` refs from the inline `ProfilePane` construction in `UserLookPane` constructor and the raw `ProfilePane` constructor body.
- `0x0069bed4` has one xref at `0x0059f35c`, storing the just-created `MoreInfoPane` pointer.
- Raw starts `0x005a2190`, `0x005a2280`, `0x005a22e0`, and `0x005a2360` have zero IDA xrefs.

### Raw-Byte and Boundary Checks

- `0x0059f25b-0x0059f260` is five `0xcc` bytes before the target.
- `0x005a2523-0x005a2530` is thirteen `0xcc` bytes before `UserPane`.
- `0x005a2188-0x005a2190` is `0xcc` alignment after `ShowLegendView`.
- `0x005a2190-0x005a2272` is a raw no-function packet helper. It takes a wide-string argument, checks it through `sub_516030`, sends opcode byte `0x2e`, converts through `WideCharToMultiByte`, copies through `sub_516220`, and sends through `dword_67A7EC`/`sub_574BB0`. It returns with `retn 4`; a range-check failure tail calls the runtime failure path.
- `0x005a2272-0x005a2280` is alignment.
- `0x005a2280-0x005a22da` is a raw no-function packet helper. It builds opcode `0x4a`, writes a zero byte, sends the argument through `sub_5753F0`, and transmits six bytes through `dword_67A7EC`/`sub_574BB0`.
- `0x005a22da-0x005a22e0` is alignment.
- `0x005a22e0-0x005a233d` is a raw `MoreInfoPane` constructor-shaped body. It calls pane base/setup helpers, then stores `MoreInfoPane` vtables at `[this]`, `[this+0xa0]`, and `[this+0xa4]`.
- `0x005a233d-0x005a2340` is alignment.
- `0x005a2340-0x005a2345` and `0x005a2350-0x005a2355` are five-byte false-return virtual stubs.
- `0x005a2355-0x005a2360` is alignment.
- `0x005a2360-0x005a23bd` is a raw `ProfilePane` constructor-shaped body with the same vtable-store pattern for `ProfilePane`.
- `0x005a23bd-0x005a23c0` is alignment.
- `0x005a23c0-0x005a23c5` and `0x005a23d0-0x005a23d5` are five-byte false-return virtual stubs.
- `0x005a23d5-0x005a23eb` is two 11-byte secondary/tertiary destructor adjustor thunks. They subtract `0xa0` or `0xa4` from `ecx` and jump to `0x005a23f0`.
- `0x005a23eb-0x005a23f0` is alignment.

### Local PE Scan

I scanned `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` for little-endian VA dwords, RVA dwords, and `.text` relative `call`/`jmp` hits.

Important results:

- `0x0059f260` has the expected relative call from `0x004b8477` and no VA/RVA dword hits.
- Vtable-routed functions have the expected VA dword hits from the UserLook/MoreInfo/Profile vtable records.
- Internally called helpers have the same relative call hits reported by IDA.
- `0x0059f500`, `0x005a0630`, `0x005a2190`, `0x005a2280`, `0x005a22e0`, `0x005a2360`, and `0x005a2523` have no VA hits, no RVA hits, and no relative `call`/`jmp` hits.
- `0x005a2530` has the expected successor `UserPane` constructor call hits from `0x004f84e2` and `0x004f8a49`.

This rules out hidden pointer-table or direct-branch evidence for the raw helper and raw constructor entry points. It supports leaving those as blank-final-C++ evidence rather than asserting live standalone source calls.

## Rejected Alternatives

- Keep [UID:0001KK] as one reconstructable aggregate: rejected. The span crosses `UserLookPane`, source-local child panes, file-local raw helpers, and compiler thunks. Exact functions are already identifiable, and aggregate final C++ would duplicate or blur source ownership.
- Reclassify the whole range as dead/non-emitting evidence only: rejected. Vtable refs, constructor caller, internal calls, scalar destructor refs, and support docs prove active `UserLookPane` source behavior across most of the range.
- Use [UID:0000FP] `UserLookPane` as the aggregate owner: rejected for the parent only. `UserLookPane` should own most executable child methods, but the aggregate also includes `MoreInfoPane`, `ProfilePane`, and file-local raw packet helpers.
- Reroute to `ProfileDialog.cpp`: rejected. `ProfileDialog` docs and code-role evidence separate the dialog from `ProfilePane` child display behavior under `UserLookPane.cpp`.
- Merge into `UserPane`: rejected. `UserPane` starts at `0x005a2530` after verified padding and has independent constructor xrefs.
- Move shared `LegendPane` ownership into `UserLookPane`: rejected. `UserLookPane` constructs/uses `LegendPane`, but `LegendPane` is shared by the look-pane family and remains under [UID:0000KM]/[UID:000074].
- Repair IDA by creating raw functions: rejected for now. The raw bytes are source-shaped, but no IDA xrefs or local PE hidden routes prove live standalone entry points.

## Proposed Child Inventory

Use real UIDs allocated by the supervisor. Placeholder UIDs below are only for implementation planning and coverage-row text.

| Placeholder | Planned file | Range | Kind | Metadata |
| --- | --- | --- | --- | --- |
| `NEW-1KK01` | `0x0059f260-0x0059f4fd.UserLookPaneConstructor.md` | `0x0059f260-0x0059f4fd` | constructor | `86/90`, owner/emitter `0000FP`, reconstructable |
| `NEW-1KK02` | `0x0059f500-0x0059f604.UserLookPaneNonDeletingDestructor.md` | `0x0059f500-0x0059f604` | destructor helper | `85/89`, owner/emitter `0000FP`, reconstructable |
| `NEW-1KK03` | `0x0059f610-0x005a0626.UserLookPaneParseLookPacket.md` | `0x0059f610-0x005a0626` | parser/packet method | `86/90`, owner/emitter `0000FP`, reconstructable |
| `NEW-1KK04` | `0x005a0630-0x005a0631.UserLookPaneNullStub.md` | `0x005a0630-0x005a0631` | no-op stub | `85/88`, owner `0000FP`, `RECONSTRUCTABLE:FALSE`, blank emitters |
| `NEW-1KK05` | `0x005a0640-0x005a157d.UserLookPaneRenderUserLook.md` | `0x005a0640-0x005a157d` | render method | `86/90`, owner/emitter `0000FP`, reconstructable |
| `NEW-1KK06` | `0x005a1580-0x005a1985.UserLookPaneHandleMouseEvent.md` | `0x005a1580-0x005a1985` | mouse/input handler | `86/90`, owner/emitter `0000FP`, reconstructable |
| `NEW-1KK07` | `0x005a19a0-0x005a1a6f.UserLookPaneHandleKeyEvent.md` | `0x005a19a0-0x005a1a6f` | key handler | `85/89`, owner/emitter `0000FP`, reconstructable |
| `NEW-1KK08` | `0x005a1a70-0x005a1b4d.UserLookPaneGetActionButtonRect.md` | `0x005a1a70-0x005a1b4d` | geometry helper | `86/90`, owner/emitter `0000FP`, reconstructable |
| `NEW-1KK09` | `0x005a1b70-0x005a1caf.UserLookPaneHitTestActionButton.md` | `0x005a1b70-0x005a1caf` | hit-test helper | `86/90`, owner/emitter `0000FP`, reconstructable |
| `NEW-1KK10` | `0x005a1cd0-0x005a1dee.UserLookPaneShowMoreInfoView.md` | `0x005a1cd0-0x005a1dee` | view helper | `86/90`, owner/emitter `0000FP`, reconstructable |
| `NEW-1KK11` | `0x005a1df0-0x005a1f16.UserLookPaneShowProfileView.md` | `0x005a1df0-0x005a1f16` | view helper | `86/90`, owner/emitter `0000FP`, reconstructable |
| `NEW-1KK12` | `0x005a1f20-0x005a1fe3.UserLookPaneShowBioView.md` | `0x005a1f20-0x005a1fe3` | view helper | `85/89`, owner/emitter `0000FP`, reconstructable |
| `NEW-1KK13` | `0x005a1ff0-0x005a2188.UserLookPaneShowLegendView.md` | `0x005a1ff0-0x005a2188` | view helper | `86/90`, owner/emitter `0000FP`, reconstructable |
| `NEW-1KK14` | `0x005a2190-0x005a2272.UserLookPaneRawWideTextPacketSender.md` | `0x005a2190-0x005a2272` | raw file-local packet helper | `85/88`, owner/emitter `0000P0`, reconstructable |
| `NEW-1KK15` | `0x005a2280-0x005a22da.UserLookPaneRawOpcode4aPacketSender.md` | `0x005a2280-0x005a22da` | raw file-local packet helper | `85/88`, owner/emitter `0000P0`, reconstructable |
| `NEW-1KK16` | `0x005a22e0-0x005a233d.MoreInfoPaneRawConstructor.md` | `0x005a22e0-0x005a233d` | raw constructor-shaped body | `85/89`, owner/emitter `00008Q`, reconstructable |
| `NEW-1KK17` | `0x005a2340-0x005a2345.MoreInfoPaneAlwaysFalseVirtualA.md` | `0x005a2340-0x005a2345` | false virtual stub | `85/90`, owner/emitter `00008Q`, reconstructable |
| `NEW-1KK18` | `0x005a2350-0x005a2355.MoreInfoPaneAlwaysFalseVirtualB.md` | `0x005a2350-0x005a2355` | false virtual stub | `85/90`, owner/emitter `00008Q`, reconstructable |
| `NEW-1KK19` | `0x005a2360-0x005a23bd.ProfilePaneRawConstructor.md` | `0x005a2360-0x005a23bd` | raw constructor-shaped body | `85/89`, owner/emitter `0000AV`, reconstructable |
| `NEW-1KK20` | `0x005a23c0-0x005a23c5.ProfilePaneAlwaysFalseVirtualA.md` | `0x005a23c0-0x005a23c5` | false virtual stub | `85/90`, owner/emitter `0000AV`, reconstructable |
| `NEW-1KK21` | `0x005a23d0-0x005a23d5.ProfilePaneAlwaysFalseVirtualB.md` | `0x005a23d0-0x005a23d5` | false virtual stub | `85/90`, owner/emitter `0000AV`, reconstructable |
| `NEW-1KK22` | `0x005a23d5-0x005a23eb.UserLookPaneAdjustorThunks.md` | `0x005a23d5-0x005a23eb` | compiler adjustor thunks | `85/90`, owner `NONE`, `RECONSTRUCTABLE:FALSE`, blank emitters |
| `NEW-1KK23` | `0x005a23f0-0x005a2523.UserLookPaneScalarDeletingDestructor.md` | `0x005a23f0-0x005a2523` | scalar deleting destructor | `87/91`, owner/emitter `0000FP`, reconstructable |

Notes on raw helpers and constructors:

- `NEW-1KK14` and `NEW-1KK15` should stay blank-final-C++ because no caller or hidden branch/pointer route was found. They are real source-shaped file-local packet helpers, but final source names and live routing remain unresolved.
- `NEW-1KK16` and `NEW-1KK19` should stay reconstructable raw constructor evidence with blank final C++. They are not proof that the final source needs standalone constructor definitions; the live `UserLookPane` constructor also performs inline child construction. This is evidence retention, not a final emission decision.
- `NEW-1KK22` should be non-emitting compiler glue, matching [UID:0001HN][LookPaneAdjustorThunks](../../../../../by-memory/0x005732b5-0x00573302.LookPaneAdjustorThunks.md).

## Exact Supervisor Actions

1. Create the 23 child pages listed above. Allocate real UIDs. Keep every `RECONSTRUCTION_CPP` block blank.
2. Update [UID:0001KK][target parent](../../../../../by-memory/0x0059f260-0x005a2523.UserLookPaneAndProfilePanes.md):
   - Change metadata to `COMPLETION:88`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000P0`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`.
   - Change the status text from reconstructable aggregate to non-emitting `UserLookPane.cpp` source-family split index.
   - Replace the contents table with child links and keep a note that final C++ belongs only to exact child pages.
3. Update [UID:0000P0][UserLookPane file](../../../../../by-file/UserLookPane.md):
   - Recommended metadata: `COMPLETION:89`, `CONFIDENCE:88`.
   - Add the new executable child inventory under the existing UserLookPane/ProfilePane/MoreInfoPane section.
   - Add the two raw file-local packet helpers as file-owned evidence with blank final C++ and unresolved source names.
4. Update [UID:0000FP][UserLookPane class](../../../../../by-class/UserLookPane.md):
   - Recommended metadata: `COMPLETION:88`, `CONFIDENCE:90`.
   - Add links to `NEW-1KK01` through `NEW-1KK13` and `NEW-1KK23`.
   - Mention `NEW-1KK22` only as compiler-generated destructor adjustor context, not as a source method.
5. Update [UID:00008Q][MoreInfoPane class](../../../../../by-class/MoreInfoPane.md):
   - Recommended metadata: `COMPLETION:86`, `CONFIDENCE:89`.
   - Add links to `NEW-1KK16`, `NEW-1KK17`, and `NEW-1KK18`.
   - Note that the raw constructor has no start xref and should keep blank final C++.
6. Update [UID:0000AV][ProfilePane class](../../../../../by-class/ProfilePane.md):
   - Recommended metadata: `COMPLETION:85`, `CONFIDENCE:89`.
   - Add links to `NEW-1KK19`, `NEW-1KK20`, and `NEW-1KK21`.
   - This support update should be applied before assigning the ProfilePane child pages to [UID:0000AV], because the current class page is below the 85 completion gate.
7. Update [UID:00026V][UserLookReadOnlyData](../../../../../by-memory/0x0062eccc-0x0062ef0c.UserLookReadOnlyData.md), [UID:00038Q][UserLookPaneFamilyVtables](../../../../../by-type/by-vtable/UserLookPaneFamilyVtables.md), and exact vtable child docs only with cross-links if desired. No score or owner change is required there.
8. Do not change [UID:000074]/[UID:0000KM] `LegendPane`, [UID:0000MR] `ProfileDialog`, [UID:0000JQ] `GeneralPurposePanel`, [UID:0001KL] `UserPane`, or [UID:0002A8] `MoreInfoPaneSingletonSlot` metadata.
9. Do not edit the IDA DB for this assignment.

## Coverage Report Replacement

Placement context: replace the current single [UID:0001KK] row between these unchanged rows:

```text
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0059f25b-0x0059f260 | padding | UserList dialog family to UserLookPane alignment : ignored : 100% : strong : IDA MCP/raw-byte check shows five `0xcc` alignment bytes.
    - [UID:0001KK][0x0059f260-0x005a2523.UserLookPaneAndProfilePanes](by-memory/0x0059f260-0x005a2523.UserLookPaneAndProfilePanes.md) 0x0059f260-0x005a2523 | class-method aggregate | UserLookPaneAndProfilePanes : reconstructable : 84% : strong : UserLookPane executable aggregate attached to UserLookPane.cpp, with constructor/destructor/parser/render/input/view-switch methods, local MoreInfo/Profile child-pane stubs, thunk exclusion, read-only vtable/string-data and singleton/decode links, UserPane/LegendPane boundary caveats, and blank-C++ gate documented.
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x005a2523-0x005a2530 | padding | UserLook/profile panes to UserPane alignment : ignored : 100% : strong : IDA MCP/raw-byte check shows thirteen `0xcc` alignment bytes.
```

Replacement text after real UIDs are allocated:

```text
    - [UID:0001KK][0x0059f260-0x005a2523.UserLookPaneAndProfilePanes](by-memory/0x0059f260-0x005a2523.UserLookPaneAndProfilePanes.md) 0x0059f260-0x005a2523 | source-family split index | UserLookPaneAndProfilePanes : not_reconstructable : 88% : strong : Reclassified non-emitting UserLookPane.cpp source-family split index after exact child pages cover UserLookPane constructor/destructor/parser/render/input/key/action/view-switch/scalar-destructor methods, local MoreInfoPane/ProfilePane constructor and virtual stubs, file-local raw packet senders, and compiler adjustor thunks; direct source owner remains [UID:0000P0][UserLookPane](by-file/UserLookPane.md). Parent C++ remains blank; exact children carry source evidence or compiler-glue exclusion.
        - [UID:NEW-1KK01][0x0059f260-0x0059f4fd.UserLookPaneConstructor](by-memory/0x0059f260-0x0059f4fd.UserLookPaneConstructor.md) 0x0059f260-0x0059f4fd | constructor | UserLookPaneConstructor : reconstructable : 86% : strong : Exact UserLookPane constructor with GeneralPurposePanel construction xref, UserLookPane/MoreInfoPane/ProfilePane vtable stores, LegendPane construction, MoreInfoPane singleton-slot write, and source route through [UID:0000FP][UserLookPane](by-class/UserLookPane.md); field/member names remain provisional.
        - [UID:NEW-1KK02][0x0059f500-0x0059f604.UserLookPaneNonDeletingDestructor](by-memory/0x0059f500-0x0059f604.UserLookPaneNonDeletingDestructor.md) 0x0059f500-0x0059f604 | destructor helper | UserLookPaneNonDeletingDestructor : reconstructable : 85% : strong : Non-deleting destructor/cleanup helper with vtable reset and child/state cleanup evidence; no direct start xref found.
        - [UID:NEW-1KK03][0x0059f610-0x005a0626.UserLookPaneParseLookPacket](by-memory/0x0059f610-0x005a0626.UserLookPaneParseLookPacket.md) 0x0059f610-0x005a0626 | packet parser | UserLookPaneParseLookPacket : reconstructable : 86% : strong : Vtable-routed look/profile packet parser with packet-reader, JPF decode, text/child-pane population, and ShowMoreInfoView call evidence.
        - [UID:NEW-1KK04][0x005a0630-0x005a0631.UserLookPaneNullStub](by-memory/0x005a0630-0x005a0631.UserLookPaneNullStub.md) 0x005a0630-0x005a0631 | null stub | UserLookPaneNullStub : not_reconstructable : 85% : strong : One-byte no-op stub with no caller, vtable slot, pointer-byte hit, RVA hit, or relative branch hit; retained as non-emitting evidence only.
        - [UID:NEW-1KK05][0x005a0640-0x005a157d.UserLookPaneRenderUserLook](by-memory/0x005a0640-0x005a157d.UserLookPaneRenderUserLook.md) 0x005a0640-0x005a157d | render method | UserLookPaneRenderUserLook : reconstructable : 86% : strong : Vtable-routed render body with resource/string refs, action-button rectangle calls, profile/look drawing, and source route through UserLookPane.
        - [UID:NEW-1KK06][0x005a1580-0x005a1985.UserLookPaneHandleMouseEvent](by-memory/0x005a1580-0x005a1985.UserLookPaneHandleMouseEvent.md) 0x005a1580-0x005a1985 | mouse/input handler | UserLookPaneHandleMouseEvent : reconstructable : 86% : strong : Vtable-routed input handler calling action-button hit-test/rect helpers and MoreInfo/Profile/Bio/Legend view switches.
        - [UID:NEW-1KK07][0x005a19a0-0x005a1a6f.UserLookPaneHandleKeyEvent](by-memory/0x005a19a0-0x005a1a6f.UserLookPaneHandleKeyEvent.md) 0x005a19a0-0x005a1a6f | key handler | UserLookPaneHandleKeyEvent : reconstructable : 85% : strong : Vtable-routed key handler dispatching UserLookPane view-switch helpers; exact key enum names remain unresolved.
        - [UID:NEW-1KK08][0x005a1a70-0x005a1b4d.UserLookPaneGetActionButtonRect](by-memory/0x005a1a70-0x005a1b4d.UserLookPaneGetActionButtonRect.md) 0x005a1a70-0x005a1b4d | geometry helper | UserLookPaneGetActionButtonRect : reconstructable : 86% : strong : Action-button rectangle helper with six internal call sites from render and mouse/input paths.
        - [UID:NEW-1KK09][0x005a1b70-0x005a1caf.UserLookPaneHitTestActionButton](by-memory/0x005a1b70-0x005a1caf.UserLookPaneHitTestActionButton.md) 0x005a1b70-0x005a1caf | hit-test helper | UserLookPaneHitTestActionButton : reconstructable : 86% : strong : Action-button hit-test helper called twice from the mouse/input handler.
        - [UID:NEW-1KK10][0x005a1cd0-0x005a1dee.UserLookPaneShowMoreInfoView](by-memory/0x005a1cd0-0x005a1dee.UserLookPaneShowMoreInfoView.md) 0x005a1cd0-0x005a1dee | view helper | UserLookPaneShowMoreInfoView : reconstructable : 86% : strong : MoreInfo view switch called from parser, mouse/input, and key paths.
        - [UID:NEW-1KK11][0x005a1df0-0x005a1f16.UserLookPaneShowProfileView](by-memory/0x005a1df0-0x005a1f16.UserLookPaneShowProfileView.md) 0x005a1df0-0x005a1f16 | view helper | UserLookPaneShowProfileView : reconstructable : 86% : strong : Profile view switch called from mouse/input and key paths.
        - [UID:NEW-1KK12][0x005a1f20-0x005a1fe3.UserLookPaneShowBioView](by-memory/0x005a1f20-0x005a1fe3.UserLookPaneShowBioView.md) 0x005a1f20-0x005a1fe3 | view helper | UserLookPaneShowBioView : reconstructable : 85% : strong : Biography view switch called from mouse/input and key paths; exact source-facing tab name remains provisional.
        - [UID:NEW-1KK13][0x005a1ff0-0x005a2188.UserLookPaneShowLegendView](by-memory/0x005a1ff0-0x005a2188.UserLookPaneShowLegendView.md) 0x005a1ff0-0x005a2188 | view helper | UserLookPaneShowLegendView : reconstructable : 86% : strong : Legend view switch called from mouse/input and key paths, using shared [UID:000074][LegendPane](by-class/LegendPane.md) rather than owning LegendPane source.
        - [UID:NEW-1KK14][0x005a2190-0x005a2272.UserLookPaneRawWideTextPacketSender](by-memory/0x005a2190-0x005a2272.UserLookPaneRawWideTextPacketSender.md) 0x005a2190-0x005a2272 | raw packet helper | UserLookPaneRawWideTextPacketSender : reconstructable : 85% : strong : Raw no-function file-local helper sends opcode `0x2e` with a converted wide-string payload; no direct start xref or hidden pointer/branch route was found, so final C++ stays blank.
        - [UID:NEW-1KK15][0x005a2280-0x005a22da.UserLookPaneRawOpcode4aPacketSender](by-memory/0x005a2280-0x005a22da.UserLookPaneRawOpcode4aPacketSender.md) 0x005a2280-0x005a22da | raw packet helper | UserLookPaneRawOpcode4aPacketSender : reconstructable : 85% : strong : Raw no-function file-local helper sends opcode `0x4a` with a six-byte packet body; no direct start xref or hidden pointer/branch route was found, so final C++ stays blank.
        - [UID:NEW-1KK16][0x005a22e0-0x005a233d.MoreInfoPaneRawConstructor](by-memory/0x005a22e0-0x005a233d.MoreInfoPaneRawConstructor.md) 0x005a22e0-0x005a233d | raw constructor | MoreInfoPaneRawConstructor : reconstructable : 85% : strong : Raw no-function MoreInfoPane constructor-shaped body with base/setup calls and primary/secondary/tertiary MoreInfoPane vtable stores; no direct start xref or hidden pointer/branch route was found.
        - [UID:NEW-1KK17][0x005a2340-0x005a2345.MoreInfoPaneAlwaysFalseVirtualA](by-memory/0x005a2340-0x005a2345.MoreInfoPaneAlwaysFalseVirtualA.md) 0x005a2340-0x005a2345 | virtual stub | MoreInfoPaneAlwaysFalseVirtualA : reconstructable : 85% : strong : Five-byte false-return MoreInfoPane virtual stub with vtable data xref from `0x0062edd8`.
        - [UID:NEW-1KK18][0x005a2350-0x005a2355.MoreInfoPaneAlwaysFalseVirtualB](by-memory/0x005a2350-0x005a2355.MoreInfoPaneAlwaysFalseVirtualB.md) 0x005a2350-0x005a2355 | virtual stub | MoreInfoPaneAlwaysFalseVirtualB : reconstructable : 85% : strong : Five-byte false-return MoreInfoPane virtual stub with vtable data xref from `0x0062edb8`.
        - [UID:NEW-1KK19][0x005a2360-0x005a23bd.ProfilePaneRawConstructor](by-memory/0x005a2360-0x005a23bd.ProfilePaneRawConstructor.md) 0x005a2360-0x005a23bd | raw constructor | ProfilePaneRawConstructor : reconstructable : 85% : strong : Raw no-function ProfilePane constructor-shaped body with base/setup calls and primary/secondary/tertiary ProfilePane vtable stores; no direct start xref or hidden pointer/branch route was found.
        - [UID:NEW-1KK20][0x005a23c0-0x005a23c5.ProfilePaneAlwaysFalseVirtualA](by-memory/0x005a23c0-0x005a23c5.ProfilePaneAlwaysFalseVirtualA.md) 0x005a23c0-0x005a23c5 | virtual stub | ProfilePaneAlwaysFalseVirtualA : reconstructable : 85% : strong : Five-byte false-return ProfilePane virtual stub with vtable data xref from `0x0062ee8c`.
        - [UID:NEW-1KK21][0x005a23d0-0x005a23d5.ProfilePaneAlwaysFalseVirtualB](by-memory/0x005a23d0-0x005a23d5.ProfilePaneAlwaysFalseVirtualB.md) 0x005a23d0-0x005a23d5 | virtual stub | ProfilePaneAlwaysFalseVirtualB : reconstructable : 85% : strong : Five-byte false-return ProfilePane virtual stub with vtable data xref from `0x0062ee6c`.
        - [UID:NEW-1KK22][0x005a23d5-0x005a23eb.UserLookPaneAdjustorThunks](by-memory/0x005a23d5-0x005a23eb.UserLookPaneAdjustorThunks.md) 0x005a23d5-0x005a23eb | compiler thunk strip | UserLookPaneAdjustorThunks : ignored : 85% : strong : Two compiler-generated secondary/tertiary destructor adjustor thunks that subtract `0xa0` or `0xa4` from `this` and jump to `0x005a23f0`; source reconstruction should use normal UserLookPane destructor declarations, not handwritten thunk functions.
        - [UID:NEW-1KK23][0x005a23f0-0x005a2523.UserLookPaneScalarDeletingDestructor](by-memory/0x005a23f0-0x005a2523.UserLookPaneScalarDeletingDestructor.md) 0x005a23f0-0x005a2523 | destructor | UserLookPaneScalarDeletingDestructor : reconstructable : 87% : strong : Exact UserLookPane scalar deleting destructor with primary vtable data ref, adjustor-thunk callers, vtable reset, cleanup, and conditional delete behavior.
```

Keep the existing outer padding rows unchanged.

## Ignored Ledger Addition

Recommended only if `NEW-1KK22` is created as the non-emitting thunk child. Insert this near the other look-pane compiler thunk entries in `by-memory/-ignored.md`; if the supervisor prefers address-local placement, place it after the existing UserLookPane boundary-alignment entry that already names [UID:0001KK].

```text
- `0x005a23d5-0x005a23eb` - UserLookPane secondary/tertiary destructor adjustor thunks.
  - Why ignored: compiler-generated ABI glue that adjusts `this` by `0xa0` or `0xa4` and jumps to the real UserLookPane scalar deleting destructor; it should be regenerated by inheritance/destructor declarations, not emitted as handwritten C++.
  - Evidence: 2026-06-16 B001 live IDA/raw-byte audit confirms two exact 11-byte thunk functions at `0x005a23d5` and `0x005a23e0`, vtable data refs at `0x0062ed1c` and `0x0062ed4c`, tail jumps to `0x005a23f0`, and no independent source behavior.
  - Replacement/procurement: reconstruct the real [UID:0000FP][UserLookPane](by-class/UserLookPane.md) destructor/scalar deleting destructor child and let the compiler emit any needed adjustor thunks.
  - Owner docs: [UID:0001KK][0x0059f260-0x005a2523.UserLookPaneAndProfilePanes](by-memory/0x0059f260-0x005a2523.UserLookPaneAndProfilePanes.md), [UID:NEW-1KK22][0x005a23d5-0x005a23eb.UserLookPaneAdjustorThunks](by-memory/0x005a23d5-0x005a23eb.UserLookPaneAdjustorThunks.md), [UID:NEW-1KK23][0x005a23f0-0x005a2523.UserLookPaneScalarDeletingDestructor](by-memory/0x005a23f0-0x005a2523.UserLookPaneScalarDeletingDestructor.md), and [UID:00038Q][UserLookPaneFamilyVtables](by-type/by-vtable/UserLookPaneFamilyVtables.md).
```

No separate ignored rows are required for the small internal `0xcc` gaps because the non-emitting parent index preserves full coverage and the exact child pages cover source-bearing code. Add internal padding rows only if a later `memory_ranges.py report` flags the gaps as uncovered.

## Validation Order

Recommended supervisor validation sequence:

> Executable block R001 was removed from this report and preserved verbatim in [0001KK-userlookpane-profile-source-split-audit-removed.md](0001KK-userlookpane-profile-source-split-audit-removed.md). The archived block is non-authoritative and must not be executed.

Also validate every newly created child page with `tools/validator.py --mode file --file <child-path> --apply` before refreshing `by-memory/-coverage-report.md`.

## Remaining Blockers and Disposition

- Final field/member names: not resolved. I checked target docs, class/file docs, vtable data, singleton-slot docs, IDA callees, string/resource docs, and component call graph. There is no source-name evidence strong enough for final C++. This limits child completion to 85-87 but does not block split/reclassification.
- Raw packet helper liveness/source names: not resolved. IDA xrefs and full local PE VA/RVA/rel32 scans found no direct or hidden routes to `0x005a2190` or `0x005a2280`. The bodies are source-shaped packet senders, so they should be retained as reconstructable file-local evidence with blank final C++, not deleted or assigned final C++.
- Raw `MoreInfoPane`/`ProfilePane` constructor liveness: not resolved as standalone calls. IDA xrefs and local PE scans found no routes to `0x005a22e0` or `0x005a2360`. The bodies match local child-pane constructor layout and vtable stores, but final source may rely on inline construction paths. Keep them as blank-final-C++ raw constructor evidence.
- `ProfilePane` support gate: resolved by recommendation. Current [UID:0000AV] is below 85 completion; raising it to `85/89` with the exact raw constructor/stub evidence is required before child pages use it as direct owner/emitter.
- `LegendPane` placement: resolved. Existing docs and constructor refs show UserLookPane uses shared `LegendPane`; ownership stays with [UID:000074]/[UID:0000KM].
- IDA repair: resolved as no-change. Normal functions are modeled; raw starts lack liveness routes; thunk functions are already modeled. No safe IDA edit is useful for source-quality decisions.

## No Direct Edit Confirmation

B001 made no direct edits to by-* documentation, generated reports, the IDA DB, or `by-memory/-coverage-report.md` for this assignment. This report is the only file created.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0001KK-userlookpane-profile-source-split-audit.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:19","uid":"0001KK"} -->
<!-- {"agent":"B001","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001KK-userlookpane-profile-source-split-audit-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B001/0001KK-userlookpane-profile-source-split-audit.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001KK"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
