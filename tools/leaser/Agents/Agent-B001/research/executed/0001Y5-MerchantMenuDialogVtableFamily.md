# 0001Y5 MerchantMenuDialogVtableFamily Ownership Research

## Finalized Report / Current Recommendation

- Target: [UID:0001Y5] `by-type/by-vtable/MerchantMenuDialogVtableFamily.md`.
- Current recommendation: keep the master family page reconstructable but unparented as an owner-split vtable inventory; do not assign it to a single source owner.
- Recommended status/classification: `reviewed-85-ownership-split`, not `ownership-unknown`.
- Confidence: high, `91/100`, for the split decision. IDA MCP confirms all 42 vtable bases, complete-object-locator pointers, constructor/store xrefs, inherited slot `0x00517d80`, and the `0x0061f588` successor boundary.
- Concrete next action: supervisor/A-agents should accept the master as a mixed split index and use the five exact child vtable pages for assignment:
  - [UID:00031W] `MerchantDialogPaneVtables.md` -> [UID:0000L9] `MerchantDialogPane`, `86/90`.
  - [UID:00031Y] `TextMenuDialogVtables.md` -> [UID:0000OP] `TextMenuDialogs`, `87/91`.
  - [UID:00031Z] `ItemMenuDialogVtables.md` -> [UID:0000KF] `ItemMenuDialogs`, `88/92`.
  - [UID:00031X] `SpellMenuDialogVtables.md` -> [UID:0000O2] `SpellMenuDialogs`, `88/92`.
  - [UID:000320] `ArgumentedMenuDialogVtables.md` -> [UID:0000HI] `ArgumentedMenuDialogs`, `86/90`.
- Report state: final. Targeted validator scans completed successfully after the split and cleanup edits.

## Supporting Research

### Scope And Rule Applied

B001-008 asked whether [UID:0001Y5] is a valid single source-owned type page or an overbroad mixed family. Under the updated B001 goal and by-structure rules, current documentation is prior inference only. The controlling evidence for ownership is IDA MCP evidence: decorated vtable names, RTTI complete-object locators, vtable store xrefs, executable cluster placement, and neighboring boundaries.

The answer is split ownership. The master page is a valid high-level inventory, but it is not a valid single direct source-owned item. Five exact owner-specific vtable children are needed and were created under `by-type/by-vtable`.

### IDA MCP Evidence

Raw evidence files:

- `tools/leaser/Agents/Agent-B001/research/scratch/0001Y5-ida-vtables.json`
- `tools/leaser/Agents/Agent-B001/research/scratch/0001Y5-ida-vtables-summary.json`

IDA target:

- IDB: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`
- Input: `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`
- MD5: `4247e04e20b65d6414c7238aa8ff5515`

Facts from live IDA MCP `py_eval`:

- The family begins at `0x0061ec10` with `??_7MerchantDialogPane@@6B@`.
- The last in-family vtable base is `0x0061f57c`, `??_7ArgumentedMenuMenuItemList@@6B@_1`.
- The next named vtable is `0x0061f588`, `??_7ArgumentedItemQuantityInputDialogPane@@6B@`, outside this family.
- All 42 documented bases have decorated `??_7...` names and complete-object-locator pointers at `base - 4`.
- Shared inherited secondary slots contain `0x00517d80` at `0x0061ec80`, `0x0061ed1c`, `0x0061ee7c`, `0x0061ef18`, `0x0061f078`, `0x0061f1d8`, `0x0061f338`, and `0x0061f498`.
- The broader `.rdata` successor after the larger read-only aggregate is `??_7Message@@6B@` at `0x0061fa3c`.

### Owner Clusters

Merchant base:

- Class: `MerchantDialogPane`.
- Vtable bases: `0x0061ec10`, `0x0061ec70`, `0x0061eca0`.
- COLs: `0x0064b774`, `0x0064b7d4`, `0x0064b7e8`.
- Store refs: `0x00517d53`, `0x00517d59`, `0x00517d63` in raw/no-function constructor-shaped code.
- Best owner: [UID:0000L9] `by-file/MerchantDialogPane.md`.

Text menu:

- Classes: `TextMenuDialog`, `TextMenuItemList`, `TextInputMenuDialog`.
- Vtable bases: `0x0061ecac`, `0x0061ed0c`, `0x0061ed3c`, `0x0061ed48`, `0x0061edd0`, `0x0061ee00`, `0x0061ee0c`, `0x0061ee6c`, `0x0061ee9c`.
- Store refs: `0x00517fa0-0x00517fb0` in `sub_517F30`, `0x00519560-0x00519570` in `sub_519520`, `0x00519950-0x00519960` in `sub_5198E0`.
- Best owner: [UID:0000OP] `by-file/TextMenuDialogs.md`.

Item menu:

- Classes: `ServerItemMenuDialog`, `ServerItemMenuItemList`, `ClientItemMenuDialog`, `ClientItemMenuItemList`.
- Vtable base span: `0x0061eea8-0x0061f15c`.
- Store refs: `0x0051a596-0x0051a5a6`, `0x0051a6ff-0x0051a70f`, raw list stores near `0x0051aedb-0x0051af13`, `0x0051b8e9-0x0051b8f9`, `0x0051c4a7-0x0051c4b7`, and destructor refs including `0x00520ce6-0x00520cf6`.
- Best owner: [UID:0000KF] `by-file/ItemMenuDialogs.md`.

Spell menu:

- Classes: `ServerSpellMenuDialog`, `ServerSpellMenuItemList`, `ClientSpellMenuDialog`, `ClientSpellMenuItemList`.
- Vtable base span: `0x0061f168-0x0061f41c`.
- Store refs: `0x0051ca95-0x0051caa5`, `0x0051d736-0x0051d746`, `0x0051db95-0x0051dba5`, `0x0051e68b-0x0051e69b`.
- Best owner: [UID:0000O2] `by-file/SpellMenuDialogs.md`.

Argumented menu:

- Classes: `ArgumentedMenuMenuDialog`, `ArgumentedMenuMenuItemList`.
- Vtable bases: `0x0061f428`, `0x0061f488`, `0x0061f4b8`, `0x0061f4c4`, `0x0061f54c`, `0x0061f57c`.
- Store refs: `0x0051ea16-0x0051ea26`, `0x0051eb7f-0x0051eb8f`, `0x0051f2b6-0x0051f2c6`, raw list stores near `0x0051f35b-0x0051f393`, and destructor stores `0x00520bb6-0x00520bc6`.
- Successor boundary: `0x0061f588` starts `ArgumentedItemQuantityInputDialogPane`, which belongs to the adjacent argumented input-dialog family, not this menu child.
- Best owner: [UID:0000HI] `by-file/ArgumentedMenuDialogs.md`.

### Candidate Owner Ranking

1. Owner-specific split children: selected. This preserves the master as a type-family inventory while assigning exact subfamilies to their direct file owners. It is the only option that matches the five IDA constructor/store clusters and by-structure gate.
2. Assign master to `TextMenuDialogs`: rejected. Text owns only the text/text-input subfamily. IDA shows item, spell, merchant-base, and argumented constructors outside the text executable cluster.
3. Assign master to `MerchantDialogPane`: rejected. MerchantDialogPane supplies the shared base and inherited virtual `0x00517d80`, but not the concrete text/item/spell/argumented constructors.
4. Assign master to `MerchantMenuDialogReadOnlyData` [UID:00025U]: rejected. It is a broader memory aggregate crossing this family plus argumented input, object-image vtables, strings, and later `.rdata` records.
5. Create a new broad `MerchantMenuDialogs.cpp` owner: rejected for documentation ownership. It is a possible final source consolidation choice, but current IDA evidence and existing file roots support five stronger direct owners. Creating a broad owner would hide proven direct ownership and make child routing less accurate.

### Documentation Changes Made

New exact child pages:

- `by-type/by-vtable/MerchantDialogPaneVtables.md` [UID:00031W], `86/90`, parent [UID:0000L9].
- `by-type/by-vtable/TextMenuDialogVtables.md` [UID:00031Y], `87/91`, parent [UID:0000OP].
- `by-type/by-vtable/ItemMenuDialogVtables.md` [UID:00031Z], `88/92`, parent [UID:0000KF].
- `by-type/by-vtable/SpellMenuDialogVtables.md` [UID:00031X], `88/92`, parent [UID:0000O2].
- `by-type/by-vtable/ArgumentedMenuDialogVtables.md` [UID:000320], `86/90`, parent [UID:0000HI].

Related parent docs raised or clarified:

- `by-file/MerchantDialogPane.md`: `84/82` -> `85/86`, with B001 IDA refresh and assigned vtable child.
- `by-file/TextMenuDialogs.md`: `90/82` -> `90/86`, with argumented-menu split clarified and assigned text vtable child.
- `by-file/ArgumentedMenuDialogs.md`: `82/86` -> `85/88`, with argumented vtable evidence and `0x0061f588` boundary.

Master and coverage cleanup:

- `by-type/by-vtable/MerchantMenuDialogVtableFamily.md`: `85/88` -> `88/91`, status changed from passive ownership-unknown to owner-split inventory.
- `by-type/by-vtable/-coverage-report.md`: added the five child rows and updated the master row.
- `by-file/-coverage-report.md`: updated rows for `MerchantDialogPane`, `TextMenuDialogs`, and `ArgumentedMenuDialogs`.
- `by-memory/0x00520abb-0x00520e2b.MenuDialogDestructorThunks.md` and `by-memory/-coverage-report.md`: corrected stale parent-score language. The destructor-thunk island remains unassigned because it is still `80/86` and mixed compiler glue, not because the refreshed parent docs fail the gate.

### Validation

Initial child validation was run during the split creation and assigned stable UIDs [UID:00031W], [UID:00031X], [UID:00031Y], [UID:00031Z], and [UID:000320].

Final targeted validator scans were run with `--mode file --apply` and exited `0` for all 13 files:

- `by-type/by-vtable/MerchantMenuDialogVtableFamily.md`
- `by-type/by-vtable/MerchantDialogPaneVtables.md`
- `by-type/by-vtable/TextMenuDialogVtables.md`
- `by-type/by-vtable/ItemMenuDialogVtables.md`
- `by-type/by-vtable/SpellMenuDialogVtables.md`
- `by-type/by-vtable/ArgumentedMenuDialogVtables.md`
- `by-file/MerchantDialogPane.md`
- `by-file/TextMenuDialogs.md`
- `by-file/ArgumentedMenuDialogs.md`
- `by-type/by-vtable/-coverage-report.md`
- `by-file/-coverage-report.md`
- `by-memory/0x00520abb-0x00520e2b.MenuDialogDestructorThunks.md`
- `by-memory/-coverage-report.md`

Validator output included `ok: 1` for each scan and ended with `VALIDATION_OK 13 files`. The scan for the master page confirmed `completion_update 0001Y5 ... 88` and `confidence_update 0001Y5 ... 91`, plus reference-index entries for all five child UIDs.

### Remaining Limits

- The master page should not receive `AUTOGEN_PARENT_UID`; that would be a false single-owner assertion.
- `simroot_v2` still reports `vtable_count: 0` for these classes, so generated metadata cannot be treated as authoritative for this target.
- Exact class pages could be further improved in future, but this target no longer depends on them because the selected direct owners are by-file roots that clear `85/85`.
- The compiler-generated destructor-thunk island [UID:0001BX] remains below gate and mixed; it should be handled as a separate future cleanup, not as a blocker for [UID:0001Y5].
