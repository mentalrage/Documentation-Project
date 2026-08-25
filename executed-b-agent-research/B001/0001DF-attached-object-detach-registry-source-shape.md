** TARGET-REPORT-UID:0001DF **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0001DF AttachedObject Detach Registry Source-Shape Research

## Finalized Report / Current Recommendation

- Current recommendation: reroute [UID:0001DF] from [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md) to direct class owner/emitter [UID:00007B][LivingObjectPane](by-class/LivingObjectPane.md).
- Final disposition: keep the target reconstructable and source-bearing, but treat it as a `LivingObjectPane` attached-overlay deregistration method called by `AttachedObjectPane::~AttachedObjectPane`, not as an `AttachedObjectPane.cpp` private helper.
- Required action: update target metadata, owner/emitter wording, support docs, and the exact `by-memory/-coverage-report.md` row below. Leave final C++ blank.
- Confidence: high. The only direct caller is still the attached-pane destructor, but receiver type, field initialization, field cleanup/replacement methods, address locality, and registration caller clusters all point to `LivingObjectPane`.

## Supporting Research

## Target

- Target UID: [UID:0001DF]
- Target path: `by-memory/0x0053aec0-0x0053b011.AttachedObjectDetachRegistry.md`
- Source queue/report row: Goal 2 B001 assignment `B001-goal2-attached-object-detach-registry-source-shape-0001DF-20260616`.
- Current supervisor classification: heavy heuristic source-shape follow-up from A001.
- Current scores and parent state checked: `COMPLETION:86`, `CONFIDENCE:89`, `CANONICAL_OWNER:0000HJ`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000HJ`, final C++ blank.
- Current generated route checked: `auto-generated/-ag-memory-coverage.md` reports [UID:0001DF] as emitting through [UID:0000HJ] to `auto-generated/NexusTK/map/AttachedObjectPane.cpp`.

## Executive Recommendation

[UID:0001DF] should become a direct [UID:00007B][LivingObjectPane](by-class/LivingObjectPane.md) method child and emit through that class. The best source-level shape is:

```cpp
// name still provisional
LivingObjectPane::DetachAttachedObject(AttachedObjectPane *attachedObject)
```

The exact final method name should remain open, but the owner/source route should no longer be open. The function's `this` pointer is the living-object registry owner. `AttachedObjectPane` stores that owner pointer at offset `+0x128` and calls this method during destruction to remove itself from the owner's attachment lists or singleton slots. Consumer/caller evidence alone should not outweigh the receiver and field-owner evidence.

Do not reclassify the target as non-emitting, dead, duplicate, or a standalone generated helper class. Do not merge it into the broad [UID:0001DE][LivingObjectPaneCore](by-memory/0x0053a110-0x0053d818.LivingObjectPaneCore.md) aggregate; keep the exact method page. Do not add final C++ yet because source-quality field names, attachment-type enum names, and the final method spelling are still not proven.

## Supervisor Active Recheck

- Triggering instruction confirmed: decide whether [UID:0001DF] remains an `AttachedObjectPane.cpp` private destructor helper or reroutes as a `LivingObjectPane` registry method.
- Split repair required before report: no. The target body is an exact IDA function range, `0x0053aec0-0x0053b012` exclusive. It has compiler switch tables immediately after the function body, but those are generated-binary support data, not source-authored code to merge into this page.
- Direct edits performed: none outside this B001 report.

## Inference Research Guidance Check

`by-structure.md` says `CANONICAL_OWNER` should point to the narrowest true semantic owner, not merely the final source root or nearest caller. Applying that rule changes the answer: the function is called from `AttachedObjectPane`, but it mutates `LivingObjectPane` fields through a `LivingObjectPane` receiver. [UID:00007B] and [UID:0000KU][LivingObjectPane](by-file/LivingObjectPane.md) both clear the current gate, and nearby exact LivingObjectPane children already use class-level ownership/emission.

`inference_research.md` cautions that consumer xrefs alone do not prove ownership. Here, the single consumer xref is real, but the stronger evidence is the receiver object, write/cleanup cluster, and source-address locality inside the LivingObjectPane method island.

Existing documentation assumptions treated as uncertain:

- Current [UID:0001DF] owner/emitter route through [UID:0000HJ] was treated as a prior hypothesis, not proof.
- The pseudo-class/file pages [UID:00000N] and [UID:0000HK] were treated as rejected generated identities, not source-layout evidence.
- The [UID:0001TR][AttachedObjectRegistryLayout](by-type/by-struct/AttachedObjectRegistryLayout.md) move to [UID:00007B] was treated as a strong lead and rechecked against fresh IDA evidence.

## Evidence Standards Used

Evidence checked:

- Live IDA MCP session opened for this report: `b001_attached_object_0001DF_20260616`, `NexusTK.exe`, image base `0x400000`, Hex-Rays ready.
- IDA function boundaries, xrefs, callees, decompilation, entity maps, and rendered-listing searches.
- Raw PE section mapping, hash, function bytes, pointer/branch scans, and immediate switch-table bytes.
- Existing by-memory, by-class, by-file, by-type, by-global, generated coverage, and proposed source-tree documentation.
- Negative evidence for hidden pointer/table routes, standalone helper identity, MapPane ownership, AttachmentAnchorResolver ownership, and IDA DB repair.

The evidence is strong enough to change owner/emitter routing because multiple independent routes agree: machine-code receiver semantics, field writes/clears, neighboring method ordering, MapPane registration paths, and support-type ownership all point to `LivingObjectPane`.

## IDA MCP Facts

### Function and Range Facts

- `lookup_funcs` confirms:
  - `0x00538100` -> `sub_538100`, size `0x1f8`.
  - `0x0053aec0` -> `sub_53AEC0`, size `0x152`.
  - `0x0053b011` still resolves inside `sub_53AEC0`.
  - `0x0053b012` is not a function.
  - `0x0053a110` -> `sub_53A110`, size `0x24d`.
  - `0x0053a360` -> `sub_53A360`, size `0x23d`.
  - `0x0053a5a0` -> `sub_53A5A0`, size `0x106`.
- `entity_query` over `0x0053a6a0-0x0053b200` places `sub_53AEC0` between adjacent LivingObjectPane helper methods:
  - `0x0053ab40` linked/attached-object cleanup.
  - `0x0053ada0`, `0x0053adb0`, `0x0053ae10`, `0x0053ae70`, `0x0053ae80`, `0x0053ae90` setters/list-registration helpers.
  - `0x0053aec0` detach/deregister helper.
  - `0x0053b130` effect clearing.

### Xref Facts

- `xrefs_to 0x0053aec0` returns exactly one code xref: `0x005382b0` inside `sub_538100`, the `AttachedObjectPane` non-deleting destructor.
- `callees 0x0053aec0` returns no ordinary callees; list operations are virtual calls through list objects stored in the receiver.
- `xrefs_to 0x0053a110` returns one constructor call at `0x0050609b`.
- `xrefs_to 0x0053a360` returns one constructor call at `0x005a256b`.
- `xrefs_to 0x0053a5a0` returns cleanup/unwind refs at `0x005a2d5f`, `0x005b8336`, and `0x0060a343`.
- `xrefs_to 0x005385c0`, `0x005385d0`, and `0x005385f0` returns zero refs; the small `AttachedObjectPane +0x128` accessors/setter exist but do not explain the live source route.

### Receiver and Field Facts

- `decompile 0x00538100` shows the destructor call as `sub_53AEC0(v12, this)` at `0x005382b0`, where `v12` is loaded from the attached pane's `+0x128` owner/registry field.
- `decompile 0x005380b0` shows the base `AttachedObjectPane` constructor stores its third argument into `this[74]`, the same `+0x128` field.
- Derived attached-overlay constructors pass the owner pointer into that field:
  - `0x004682c0` calls `sub_5380B0(..., a2, ...)` and then writes `a2` to `this + 296`.
  - `0x00538d50`, `0x00539230`, and `0x005395b0` store their owner argument into `this + 296`.
- `decompile 0x0053a110` and `0x0053a360` show LivingObjectPane constructor variants allocating and initializing the same registry/list group:
  - `+0x174` and `+0x170` receive allocated list pointers.
  - `+0x1d8`, `+0x1dc`, `+0x1e0`, and `+0x1e4` are initialized to zero.
- `search_text` over `0x0053a000-0x0053b200` confirms the same field group is repeatedly used only inside the LivingObjectPane neighboring cluster:
  - `+0x170` hits in constructors, `sub_53AB40`, `sub_53ADB0`, and `sub_53AEC0`.
  - `+0x174` hits in constructors, `sub_53AB40`, `sub_53AE10`, and `sub_53AEC0`.
  - `+0x1d8`, `+0x1dc`, `+0x1e0`, `+0x1e4` hits in constructors, `sub_53AB40`, setter helpers, and `sub_53AEC0`.
- `decompile 0x0053ab40` shows the broader LivingObjectPane cleanup destroys objects in the two lists, clears each attached object's owner slot (`result[74] = 0`), releases singleton slots, releases the two lists, and zeroes `this[93]` / `this[92]`.
- `decompile 0x0053ada0`, `0x0053ae70`, `0x0053ae80`, and `0x0053ae90` shows small LivingObjectPane setters for singleton fields `+0x1d8`, `+0x1dc`, `+0x1e0`, and `+0x1e4`.
- `decompile 0x0053adb0` and `0x0053ae10` shows list insertion/replacement helpers for the two list fields.

### Registration Caller Facts

MapPane packet/update handlers construct attached overlays and then call the LivingObjectPane registry setters/list helpers:

- `callees 0x0050e100` includes `0x004682c0` and `0x0053ada0`.
- `callees 0x0050e4c0` includes `0x00538dc0` and `0x0053ae70`.
- `callees 0x0050e690` includes `0x00538dc0` and `0x0053ae70`.
- `callees 0x0050ea30` includes `0x005387b0`, `0x0053adb0`, and `0x0053ae10`.
- `callees 0x0050ef00` includes `0x00539230` and `0x0053ae80`.

This gives the expected lifecycle pairing: MapPane creates an attached overlay and registers it on the owning LivingObjectPane; the attached overlay destructor later calls back to its owner to deregister itself.

### Data/Table/Padding Facts

- IDA names `jpt_53AEEE` at `0x0053b014` and `jpt_53AF69` at `0x0053b034`, each data-referenced only from `sub_53AEC0`.
- Raw PE bytes confirm those are the two switch tables for the two `byte_66DA97` branches:
  - `0x0053b014`: `0x53aef5, 0x53b00c, 0x53af29, 0x53b00c, 0x53af70, 0x53aff2, 0x53af59, 0x53b002`.
  - `0x0053b034`: `0x53af80, 0x53b00c, 0x53afc2, 0x53b00c, 0x53af70, 0x53aff2, 0x53b00c, 0x53b002`.
- These switch tables should not drive source ownership. They are compiler-generated support for the method body.

## Raw PE Facts

Raw PE scan used `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`:

- File size: `0x28e200`.
- MD5: `4247e04e20b65d6414c7238aa8ff5515`.
- SHA256: `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`.
- `.text`: `0x00401000-0x0060c600`, raw `0x400-0x20ba00`.
- `0x0053aec0-0x0053b012` maps to `.text` file offset `0x13a2c0`, length `338`, matching IDA's `0x152` function size.
- Absolute VA and RVA dword scans found zero pointer encodings for:
  - `0x0053aec0`
  - `0x00538100`
  - `0x0053a110`
  - `0x0053a360`
  - `0x0053a5a0`
  - `0x005385c0`
  - `0x005385d0`
  - `0x005385f0`
- Direct `E8`/`E9` rel32 scan found:
  - exactly one branch to `0x0053aec0`, at `0x005382b0`;
  - one branch to `0x0053a110`, at `0x0050609b`;
  - one branch to `0x0053a360`, at `0x005a256b`;
  - three branches to `0x0053a5a0`, at `0x005a2d5f`, `0x005b8336`, and `0x0060a343`;
  - zero branches to `0x005385c0`, `0x005385d0`, or `0x005385f0`.

This resolves reachability: `0x0053aec0` is live code, but there is no hidden pointer/table route that would make it a standalone callback, virtual slot, or external helper.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0053aec0-0x0053b011` | [UID:0001DF] `by-memory/0x0053aec0-0x0053b011.AttachedObjectDetachRegistry.md` | Attached overlay deregistration method on the owning living object | TRUE | Recommend [UID:00007B] | Recommend `88/91` | Reroute |
| `0x0053b014-0x0053b053` | no exact page | Two compiler switch tables for [UID:0001DF] | FALSE / generated-binary | none needed now | n/a | Do not emit |
| `0x0053a110-0x0053a6a6` | [UID:0002R0] `LivingObjectPaneConstructionAndCleanup` | Constructor/setup for the same registry fields | TRUE | [UID:00007B] | `86/88` | Supports reroute |
| `0x0053ab40` | contained in [UID:0001DE] | LivingObjectPane linked/attached object cleanup | TRUE | [UID:00007B] by aggregate evidence | aggregate | Supports reroute |
| `0x0053ada0-0x0053ae90` | contained in [UID:0001DE] | LivingObjectPane list/singleton registration helpers | TRUE | [UID:00007B] by aggregate evidence | aggregate | Supports reroute |

## Ranked Ownership Analysis

### 1. LivingObjectPane / [UID:00007B] - accepted

Evidence for:

- The helper's `this` pointer is the registry owner object, not the attached object.
- Constructor variants `0x0053a110` and `0x0053a360` initialize the same receiver fields.
- Neighboring LivingObjectPane methods `0x0053ab40`, `0x0053ada0`, `0x0053adb0`, `0x0053ae10`, `0x0053ae70`, `0x0053ae80`, and `0x0053ae90` clean, replace, insert, or store the same fields.
- MapPane registration callers pair attached overlay construction with calls to these LivingObjectPane registration helpers.
- Physical address locality places `0x0053aec0` inside the LivingObjectPane linked-object/attachment method island, not in the earlier `0x005380b0-0x005387a3` AttachedObjectPane local cluster.
- [UID:0001TR] already correctly assigns the layout to [UID:00007B].

Evidence against:

- The only direct call is from `AttachedObjectPane::~AttachedObjectPane`.
- The name `AttachedObjectDetachRegistry` and old pseudo-class pages can make the helper look attached-pane-local.

Decision: accepted. The sole caller explains why the method exists, but not where the method belongs. Receiver/field ownership is stronger source-ownership evidence than consumer-only xrefs.

### 2. AttachedObjectPane / [UID:0000HJ] - rejected as owner, retained as caller context

Evidence for:

- The only live call is `AttachedObjectPane::~AttachedObjectPane` at `0x005382b0`.
- `AttachedObjectPane` stores the owner pointer at `+0x128`, and the destructor uses that field to call the helper.
- Existing [UID:0000HJ] docs group the attached overlay classes and currently own the route.

Evidence against:

- The helper mutates fields of the receiver object, not fields of the destroyed attached pane.
- Those fields are constructed, cleaned, and replaced by LivingObjectPane methods.
- Attached overlay constructors receive a living-object owner pointer and store it; they do not own the registry storage.
- Source adjacency favors LivingObjectPane; [UID:0001DF] sits among LivingObjectPane methods, not among AttachedObjectPane's local methods.

Decision: reject as canonical owner/emitter. [UID:0000HJ] should remain documented as the call-site/source-use context only.

### 3. AttachedObjectPaneHelper_53AEC0 pseudo-class/file - rejected

Evidence for:

- Historical generated output isolated the function as a one-method helper.

Evidence against:

- There is no constructor, vtable, data object, separate source cluster, or extra caller for a standalone helper class.
- [UID:00000N] and [UID:0000HK] already classify this identity as non-standalone.
- Raw PE pointer scans found no function-pointer route to `0x0053aec0`.

Decision: keep both pseudo-class/file pages as non-emitting quarantine indexes, but update their wording to say the exact helper reroutes to [UID:00007B].

### 4. MapPane / [UID:0000L3] - rejected

Evidence for:

- MapPane packet/update handlers construct attached overlays and call the registration helpers.

Evidence against:

- MapPane is a creator/controller consumer. It does not own the receiver fields.
- The actual registry storage is in LivingObjectPane, and attached overlays store the living-object owner pointer.

Decision: reject. MapPane call paths are lifecycle evidence for LivingObjectPane ownership, not MapPane ownership.

### 5. ObjectPane or AttachmentAnchorResolver - rejected

Evidence for:

- The code is in the broader map-object family and some adjacent attachment helpers sit near anchor/placement code.

Evidence against:

- ObjectPane is the base map-object pane and does not initialize the `+0x170/+0x174/+0x1d8...` registry group.
- AttachmentAnchorResolver owns placement/bounds helpers, not list/singleton attachment registry state.
- No xrefs, fields, or callees tie `0x0053aec0` to the anchor resolver's source role.

Decision: reject.

## Negative Evidence Summary

- No hidden pointer route: raw PE scan found zero VA/RVA pointer encodings for `0x0053aec0`.
- No callback/table route: rel32 scan found exactly one branch to `0x0053aec0`, the attached-pane destructor call.
- No standalone source unit: IDA found no additional callers, no data xrefs except switch tables, no vtable refs, and no constructor/setup object for a pseudo-helper class.
- No IDA repair need: IDA already has the correct function object for `0x0053aec0`; the source-shape issue is documentation routing, not a database boundary problem.
- No dead/duplicate evidence: the function is directly called from a live destructor and participates in the attached-overlay lifecycle. Treating it as dead would be incorrect.
- No final C++ readiness: IDA proves type values and slot offsets, but not source-quality names for the method, list fields, singleton fields, or attachment-type enum values. No strings, symbols, debug metadata, or docs recovered exact original names.

## Final Recommendation

Exact recommended target metadata:

```text
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00007B | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00007B | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Keep:

- Current target filename. `AttachedObjectDetachRegistry` is behavior-descriptive and avoids inventing a final method name.
- `RECONSTRUCTION_CPP CODE` blank.
- `RECONSTRUCTABLE:TRUE`.
- No split/merge/reclassification.
- No IDA DB edit.

Recommended target body edits:

- Change primary owner/source wording from [UID:0000HJ] to [UID:00007B] / [UID:0000KU].
- State that [UID:0000HJ] is the sole caller/source-use context, not the canonical source owner.
- Add B001 evidence summary: fresh IDA session, exact xrefs, receiver setup, neighboring LivingObjectPane field helpers, raw PE branch/pointer scan, and compiler switch-table caveat.
- Update final-source blocker from "AttachedObjectPane helper versus LivingObjectPane method undecided" to "LivingObjectPane method accepted; exact method/field/type names still block final C++."

Recommended support-doc actions:

- [UID:00000M] `by-class/AttachedObjectPane.md`: revise evidence notes to say the destructor calls the owning `LivingObjectPane` deregistration method through the stored `+0x128` owner pointer. Do not describe [UID:0001DF] as folded into `AttachedObjectPane.cpp`.
- [UID:0000HJ] `by-file/AttachedObjectPane.md`: remove [UID:0001DF] from proposed owned contents or mark it explicitly as a consumed LivingObjectPane method. Keep the destructor-call note.
- [UID:00000N] `by-class/AttachedObjectPaneHelper_53AEC0.md`: keep `RECONSTRUCTABLE:FALSE`, `CANONICAL_OWNER:NONE`, blank emitters, but mark the B-agent source-shape question resolved: exact body [UID:0001DF] belongs to [UID:00007B], not this pseudo-class and not [UID:0000HJ].
- [UID:0000HK] `by-file/AttachedObjectPaneHelper_53AEC0.md`: keep `PROPOSED_RECONSTRUCTION_PATH:"NONE"` and `CANONICAL_OWNER:NONE`; change "Proposed owner: AttachedObjectPane" to "Exact helper body rerouted to LivingObjectPane; this page remains a rejected generated one-method file split."
- [UID:0001TR] `by-type/by-struct/AttachedObjectRegistryLayout.md`: update "Detach helper source context" and naming notes to say helper placement is now resolved to [UID:00007B], while the caller context remains AttachedObjectPane destruction. No metadata change required.
- [UID:00007B] `by-class/LivingObjectPane.md`: add [UID:0001DF] to the linked object/effect ownership or construction/destruction family as the attached-overlay deregistration method.
- [UID:0000KU] `by-file/LivingObjectPane.md`: add [UID:0001DF] to Proposed Contents / Major Method Families as the attached-overlay registry detach method.
- [UID:0001DE] `by-memory/0x0053a110-0x0053d818.LivingObjectPaneCore.md`: add [UID:0001DF] to exact LivingObjectPane child/source-bearing items or core anchors and note the switch tables at `0x0053b014`/`0x0053b034` are compiler-generated support for this method.
- [UID:0002R0] `by-memory/0x0053a110-0x0053a6a6.LivingObjectPaneConstructionAndCleanup.md`: update touched-state wording for `+0x170/+0x174/+0x1d8/+0x1dc/+0x1e0/+0x1e4` so it matches [UID:0001TR] and [UID:0001DF].

No support score changes are required to execute this report. The support docs are already above gate; the target score/route is the material change.

## Exact `by-memory/-coverage-report.md` Replacement Row

Placement context: replace the existing [UID:0001DF] row under `Covered Items To Replicate`, currently after the [UID:0002R2] / [UID:0003NW] LivingObjectPane render-frame children and before [UID:0001DG] `LightingObjectPaneLifecycle`.

Replacement row:

```text
    - [UID:0001DF][0x0053aec0-0x0053b011.AttachedObjectDetachRegistry](by-memory/0x0053aec0-0x0053b011.AttachedObjectDetachRegistry.md) 0x0053aec0-0x0053b011 | helper-method | AttachedObjectDetachRegistry : reconstructable : 88% : very strong : LivingObjectPane attached-overlay deregistration method with recommended owner/emitter route through [UID:00007B][LivingObjectPane](by-class/LivingObjectPane.md); B001 2026-06-16 live IDA and raw PE checks reconfirmed exact `0x152` body, sole call from `AttachedObjectPane::~AttachedObjectPane` at `0x005382b0`, zero ordinary callees, zero VA/RVA pointer encodings and one rel32 branch, constructor/list setup in `sub_53A110`/`sub_53A360`, same-field cleanup/replacement in neighboring LivingObjectPane methods `0x0053ab40`, `0x0053ada0`, `0x0053adb0`, `0x0053ae10`, `0x0053ae70`, `0x0053ae80`, and `0x0053ae90`, attached-overlay constructors storing the owner pointer at `+0x128`, and compiler switch tables at `0x0053b014`/`0x0053b034`; final C++ remains blank pending source-quality method/field/attachment-type names.
```

## IDA DB Recommendation

No IDA DB edit is recommended.

Reason:

- Function boundary for `0x0053aec0` is already correct.
- The missing source name is not proven enough for a durable IDA rename.
- The switch tables are already recognized as `jpt_53AEEE` and `jpt_53AF69`.
- The source-shape fix is a documentation metadata/ownership change, not an IDA analysis repair.

A later C-agent naming pass may safely consider a name such as `LivingObjectPane_DetachAttachedObject` or `LivingObjectPane_UnregisterAttachedOverlay`, but this report does not recommend saving that rename because exact original naming remains unknown.

## Validation Order

After supervisor applies accepted edits:

> Executable block R001 was removed from this report and preserved verbatim in [0001DF-attached-object-detach-registry-source-shape-removed.md](0001DF-attached-object-detach-registry-source-shape-removed.md). The archived block is non-authoritative and must not be executed.

Expected validation outcome: target should route through [UID:00007B] to [UID:0000KU] / `NexusTK/map/LivingObjectPane.cpp`; no generated dead-end should be introduced.

## Remaining Blockers

- Final method name: unresolved. Evidence checked: IDA xrefs, decompilation, neighboring setter/list methods, support docs, and generated alias pages. No source symbol/debug string proves whether the original name was `DetachAttachedObject`, `RemoveAttachedObject`, `UnregisterAttachedObject`, or similar.
- Attachment type enum names: unresolved. Evidence checked: helper switch values and registration callers. Values `2`, `4`, `6`, `7`, `8`, and `9` are behaviorally mapped, but source-facing names are not proven.
- Field names: partly resolved by role, not final-source. Evidence checked: constructor setup, cleanup, setter/list helpers, and [UID:0001TR]. `type2Attachments`, `type4Attachments`, and singleton slot names remain documentation aliases, not recovered names.
- Final C++: blocked by the above names. This is not deferred without investigation; the evidence was checked and is insufficient for a one-shot final source body.
- Neighboring raw code at `0x0053b060`: outside this target. `lookup_funcs` reports no function at `0x0053b060`; `xrefs_to` found no incoming refs to `0x0053b060` or `0x0053b0c0`. This does not block [UID:0001DF] ownership, but a future LivingObjectPaneCore raw-child audit can review it if memory coverage demands exact child pages.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B001/research/0001DF-attached-object-detach-registry-source-shape.md`
- Modified: none.
- Renamed: none.
- Moved to executed: none.

No direct edits were made to by-* documentation, generated reports, IDA DB, or `by-memory/-coverage-report.md`.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0001DF-attached-object-detach-registry-source-shape.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:19","uid":"0001DF"} -->
<!-- {"agent":"B001","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001DF-attached-object-detach-registry-source-shape-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B001/0001DF-attached-object-detach-registry-source-shape.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001DF"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
