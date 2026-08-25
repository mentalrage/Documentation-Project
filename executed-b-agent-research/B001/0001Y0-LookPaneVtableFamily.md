** TARGET-REPORT-UID:0001Y0 **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0001Y0 LookPaneVtableFamily Ownership And Split Research

Revision: B001-048 final, 2026-06-11

## Finalized Recommendation / Current Recommendation

- Target UID/path: [UID:0001Y0] `by-type/by-vtable/LookPaneVtableFamily.md`.
- Final disposition: keep [UID:0001Y0] parentless and reclassify it as a non-emitting cross-source vtable inventory. Recommended metadata after supervisor implementation: `COMPLETION:88`, `CONFIDENCE:91`, `RECONSTRUCTABLE:FALSE`, `AUTOGEN_PARENT_UID:` blank.
- Best ownership answer: no single class, source file, or existing physical `.rdata` aggregate owns the whole target. Live IDA proves the page spans at least four source-owner surfaces: `SelfLookPane.cpp` (`SelfLookPane`, `SelfLookPane2`), `SpelledPane.cpp` or shared text-pane source (`SpelledPane`), `LegendPane.cpp` or shared legend source (`LegendPane`), and `UserLookPane.cpp` (`UserLookPane`, `MoreInfoPane`, `ProfilePane`). Assigning [UID:0001Y0] to any one of those would overclaim.
- Required split before final source attachment: create source-local by-vtable child pages and exact missing by-memory vtable-data children. Do not use [UID:0001Y0] as an autogen parent for exact `.rdata` children; it should remain an audit/index page.
- Source-local by-vtable child pages to create:
  - `by-type/by-vtable/SelfLookPaneFamilyVtables.md`, UID TBD, `86/91`, parent blank until [UID:0000NL] `SelfLookPane` and/or direct class pages clear `85/85`.
  - `by-type/by-vtable/SpelledPaneVtables.md`, UID TBD, `86/91`, parent blank until [UID:0000NZ] / [UID:0000DK] confidence clears `85`.
  - `by-type/by-vtable/LegendPaneVtables.md`, UID TBD, `86/91`, parent blank until [UID:0000KM] / [UID:000074] clear `85/85`.
  - `by-type/by-vtable/UserLookPaneFamilyVtables.md`, UID TBD, `87/91`, parent [UID:0000P0] `UserLookPane`, because the file page is `88/85` and directly owns the local `UserLookPane`, `MoreInfoPane`, and `ProfilePane` class family.
- Existing exact by-memory child status:
  - [UID:0002UY] `0x00624188-0x00624210.SelfLookPaneVtableData` is already exact and strong. Keep parent blank until `SelfLookPaneFamilyVtables` can itself be source-parented under the strict gate.
  - [UID:0002UZ] `0x006242c4-0x00624384.SpelledPaneVtableData` is already exact and strong. Keep parent blank until `SpelledPaneVtables` can itself be source-parented under the strict gate.
  - [UID:0002V0] `0x00624384-0x00624438.LegendPaneVtableData` is already exact and strong. Keep parent blank until `LegendPaneVtables` can itself be source-parented under the strict gate.
- Missing/split by-memory pages to create:
  - Split [UID:0002V1] `0x006245dc-0x00624788.CollectionLookLineVtableData` into exact children. This is required because the current page mixes `CollectionPane`, `CollectionPane2`, `SelfLookPane2`, and `LineIterator`; only the `SelfLookPane2` child belongs to the look-pane family.
  - Split [UID:00026V] `0x0062eccc-0x0062ef0c.UserLookReadOnlyData` into exact `UserLookPane`, `MoreInfoPane`, and `ProfilePane` vtable-data children plus a resource-string tail. The broad aggregate may stay reconstructable and attached to [UID:0000P0] because every contained item routes through `UserLookPane.cpp`.
- Confidence: `91/100` for the non-emitting aggregate recommendation; `92/100` for the exact IDA vtable/range boundaries; `86/100` for the source-local by-vtable split plan. The remaining uncertainty is original translation-unit shape for shared `SpelledPane`/`LegendPane`, not the fact that [UID:0001Y0] is multi-owner.
- Report-only scope: no by-memory, by-type, coverage, supervisor, or target documentation pages were edited in this B001 run. All implementation and coverage changes below are pending supervisor actions.

## Concrete Supervisor Actions

1. Lease the existing by-type target and any existing by-memory pages before editing. Do not edit `by-memory/-coverage-report.md` directly unless the temporary ban has been lifted.
2. Update [UID:0001Y0] `by-type/by-vtable/LookPaneVtableFamily.md` to be a parentless non-emitting index:
   - `COMPLETION:88`
   - `CONFIDENCE:91`
   - `RECONSTRUCTABLE:FALSE`
   - `AUTOGEN_PARENT_UID:` blank
   - Keep the page as a cross-source inventory and link to the new source-local by-vtable pages.
3. Create these by-type child pages:
   - `by-type/by-vtable/SelfLookPaneFamilyVtables.md`
   - `by-type/by-vtable/SpelledPaneVtables.md`
   - `by-type/by-vtable/LegendPaneVtables.md`
   - `by-type/by-vtable/UserLookPaneFamilyVtables.md`
4. Split [UID:0002V1] `by-memory/0x006245dc-0x00624788.CollectionLookLineVtableData.md` into exact child pages:
   - `by-memory/0x006245dc-0x00624668.CollectionPaneVtableData.md`
   - `by-memory/0x00624668-0x006246f4.CollectionPane2VtableData.md`
   - `by-memory/0x006246f4-0x00624780.SelfLookPane2VtableData.md`
   - `by-memory/0x00624780-0x00624788.LineIteratorVtableData.md`
   - Reclassify [UID:0002V1] itself to `RECONSTRUCTABLE:FALSE` as a split inventory.
5. Split [UID:00026V] `by-memory/0x0062eccc-0x0062ef0c.UserLookReadOnlyData.md` into exact children:
   - `by-memory/0x0062eccc-0x0062ed58.UserLookPaneVtableData.md`
   - `by-memory/0x0062ed58-0x0062ee0c.MoreInfoPaneVtableData.md`
   - `by-memory/0x0062ee0c-0x0062eebc.ProfilePaneVtableData.md`
   - `by-memory/0x0062eebc-0x0062ef0c.UserLookPaneResourceStringData.md`
   - Keep [UID:00026V] reconstructable and parented to [UID:0000P0] unless the supervisor decides to convert all fully split `.rdata` containers to non-emitting indexes.
6. Parent assignments after page creation:
   - `UserLookPaneFamilyVtables.md` should parent to [UID:0000P0] `UserLookPane`.
   - The three new user-look vtable-data children should parent to the new `UserLookPaneFamilyVtables` UID after that page exists and validates.
   - `SelfLookPaneFamilyVtables.md`, `SpelledPaneVtables.md`, and `LegendPaneVtables.md` should remain parent blank for now because their direct source/class parent chains do not currently clear `85/85`.
   - Existing [UID:0002UY], [UID:0002UZ], [UID:0002V0], and new `SelfLookPane2VtableData` should remain parent blank until their source-local by-vtable parents are source-parented under the strict gate. This avoids a generated coverage failure like the earlier `GroupPaneFamilyVtables` parent-registration issue.

## Proposed New Page Metadata

UIDs are not known until the validator assigns them. Use `UID:TBD` only in planning text; actual files need generated unique UIDs.

| Proposed path | Completion | Confidence | Reconstructable | Autogen parent | Direct scope |
| --- | ---: | ---: | --- | --- | --- |
| `by-type/by-vtable/SelfLookPaneFamilyVtables.md` | 86 | 91 | TRUE | blank | `SelfLookPane` and `SelfLookPane2` vtable layouts only. |
| `by-type/by-vtable/SpelledPaneVtables.md` | 86 | 91 | TRUE | blank | `SpelledPane` four-view vtable layout. |
| `by-type/by-vtable/LegendPaneVtables.md` | 86 | 91 | TRUE | blank | `LegendPane` three-view vtable layout. |
| `by-type/by-vtable/UserLookPaneFamilyVtables.md` | 87 | 91 | TRUE | `0000P0` | `UserLookPane`, `MoreInfoPane`, and `ProfilePane` local vtable layouts in `UserLookPane.cpp`. |
| `by-memory/0x006245dc-0x00624668.CollectionPaneVtableData.md` | 86 | 91 | TRUE | blank pending separate collection audit | Exact collection table child, not a [UID:0001Y0] child. |
| `by-memory/0x00624668-0x006246f4.CollectionPane2VtableData.md` | 86 | 91 | TRUE | blank pending separate collection audit | Exact collection table child, not a [UID:0001Y0] child. |
| `by-memory/0x006246f4-0x00624780.SelfLookPane2VtableData.md` | 88 | 92 | TRUE | blank for now | Exact `SelfLookPane2` table child; future parent should be `SelfLookPaneFamilyVtables` after source gate repair. |
| `by-memory/0x00624780-0x00624788.LineIteratorVtableData.md` | 86 | 91 | TRUE | blank pending [UID:0001XZ] / LineIterator gate audit | Exact `LineIterator` one-slot table, not a [UID:0001Y0] child. |
| `by-memory/0x0062eccc-0x0062ed58.UserLookPaneVtableData.md` | 88 | 92 | TRUE | new `UserLookPaneFamilyVtables` UID | Exact `UserLookPane` table child. |
| `by-memory/0x0062ed58-0x0062ee0c.MoreInfoPaneVtableData.md` | 88 | 92 | TRUE | new `UserLookPaneFamilyVtables` UID | Exact `MoreInfoPane` table child; [UID:00008Q] also clears `85/85`, but the by-vtable page is the direct layout parent if created. |
| `by-memory/0x0062ee0c-0x0062eebc.ProfilePaneVtableData.md` | 88 | 92 | TRUE | new `UserLookPaneFamilyVtables` UID | Exact `ProfilePane` table child; this avoids relying on [UID:0000AV] while it remains `82/88`. |
| `by-memory/0x0062eebc-0x0062ef0c.UserLookPaneResourceStringData.md` | 85 | 90 | TRUE | `0000P0` | User-look/profile resource literals `USERLOOK.PAL`, `PFLOOK.EPF`, and `NATION.EPF` tail. |

## IDA MCP Evidence Basis

Live IDA MCP database used:

- Module: `NexusTK.exe`
- Path: `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`
- Image base: `0x400000`
- Size: `0x2b3000`
- MD5: `4247e04e20b65d6414c7238aa8ff5515`
- SHA256: `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`

The live `py_eval` pass confirmed the following exact owner-separated table groups and store xrefs:

| Owner group | Exact range | RTTI/vtable starts | Store/xref evidence |
| --- | --- | --- | --- |
| `SelfLookPane` | `0x00624188-0x00624210` | COLs at `0x00624184`, `0x006241d4`, `0x00624204`; vtables at `0x00624188`, `0x006241d8`, `0x00624208` | Vtable bases stored from `0x00565640`, `0x0056564c`, `0x00565658` in constructor `sub_565610`; from `0x0056580b`, `0x00565811`, `0x0056581b` in cleanup `sub_5657E0`; and from `0x00573762`, `0x00573768`, `0x00573772` in scalar deleting destructor `sub_573730`. |
| `SpelledPane` | `0x006242c4-0x00624384` | COLs at `0x006242c4`, `0x0062433c`, `0x0062436c`, `0x00624378`; vtables at `0x006242c8`, `0x00624340`, `0x00624370`, `0x0062437c` | Stores from constructor `sub_56BB20` at `0x0056bb92`, `0x0056bb98`, `0x0056bba2`, `0x0056bbac`; destructor-neighborhood stores at `0x0056bc26`, `0x0056bc2c`, `0x0056bc36`, `0x0056bc40`. |
| `LegendPane` | `0x00624384-0x00624438` | COLs at `0x00624384`, `0x006243fc`, `0x0062442c`; vtables at `0x00624388`, `0x00624400`, `0x00624430` | Stores from constructor `sub_56C400` at `0x0056c466`, `0x0056c46e`, `0x0056c478`; first slots target common inherited/destructor thunk bodies `0x0048c4d0`, `0x0048c2e9`, `0x0048c2f4`. |
| `SelfLookPane2` | `0x006246f4-0x00624780` | COLs at `0x006246f4`, `0x00624744`, `0x00624774`; vtables at `0x006246f8`, `0x00624748`, `0x00624778` | Stores from constructor `sub_56FE80` at `0x0056feb3`, `0x0056febc`, `0x0056fec8`; cleanup `sub_570030` at `0x0057005b`, `0x00570061`, `0x0057006b`; scalar deleting destructor `sub_573640` at `0x00573672`, `0x00573678`, `0x00573682`. |
| `UserLookPane` | `0x0062eccc-0x0062ed58` | COLs at `0x0062ecc8`, `0x0062ed18`, `0x0062ed48`; vtables at `0x0062eccc`, `0x0062ed1c`, `0x0062ed4c` | Stores from constructor `sub_59F260` at `0x0059f297`, `0x0059f29d`, `0x0059f2a9`; cleanup `sub_59F500` at `0x0059f52c`, `0x0059f532`, `0x0059f53c`; scalar deleting destructor `sub_5A23F0` at `0x005a2423`, `0x005a2429`, `0x005a2433`. |
| `MoreInfoPane` | `0x0062ed58-0x0062ee0c` | COLs at `0x0062ed54`, `0x0062edcc`, `0x0062edfc`; vtables at `0x0062ed58`, `0x0062edd0`, `0x0062ee00` | Constructor stores from `sub_59F260` at `0x0059f338`, `0x0059f33e`, `0x0059f348`; additional destructor-neighborhood refs at `0x005a231c`, `0x005a2324`, `0x005a232e`. |
| `ProfilePane` | `0x0062ee0c-0x0062eebc` | COLs at `0x0062ee08`, `0x0062ee80`, `0x0062eeb0`; vtables at `0x0062ee0c`, `0x0062ee84`, `0x0062eeb4` | Constructor stores from `sub_59F260` at `0x0059f3ce`, `0x0059f3d4`, `0x0059f3de`; additional destructor-neighborhood refs at `0x005a239c`, `0x005a23a4`, `0x005a23ae`. |

The same live pass also proves why [UID:0002V1] must be split rather than parented wholesale to the look-pane family:

| Adjacent owner in [UID:0002V1] | Exact range | Evidence |
| --- | --- | --- |
| `CollectionPane` | `0x006245dc-0x00624668` | COL/vtable bases at `0x006245dc`, `0x006245e0`, `0x0062462c`, `0x00624630`, `0x0062465c`, `0x00624660`; stores from `sub_56E940` and scalar destructor `sub_573370`. |
| `CollectionPane2` | `0x00624668-0x006246f4` | COL/vtable bases at `0x00624668`, `0x0062466c`, `0x006246b8`, `0x006246bc`, `0x006246e8`, `0x006246ec`; stores from `0x0056fd7f`, `sub_56FDA0`, and scalar destructor `sub_573310`. |
| `SelfLookPane2` | `0x006246f4-0x00624780` | This is the only look-pane-family subrange in [UID:0002V1]. |
| `LineIterator` | `0x00624780-0x00624788` | One-slot vtable at `0x00624784`, first slot `0x00573540`, refs from `sub_56C0E0`, `sub_573240`, and `sub_573540`. |

The resource tail under [UID:00026V] was live-checked by byte decoding from `0x0062eebc-0x0062ef0c`; decoded UTF-16LE literals include `USERLOOK.PAL` at `0x0062eebc`, `PFLOOK.EPF` at `0x0062eed8`, and `NATION.EPF` at `0x0062eef0`.

## Documentation Evidence Cross-Check

- [UID:0001Y0] already states the same class list and leaves parent blank because the page is a multi-owner aggregate. Live IDA confirms that conclusion and strengthens it by giving the exact store refs for each local group.
- [UID:0001XP] `GroupPaneFamilyVtables` is the controlling precedent. It is a reconstructable by-vtable family page because its exact children belong to one source root, [UID:0000JS] `Group`, which clears `89/85`. The look-pane page is different: it crosses multiple source roots, so the broad page cannot play the same parent role.
- [UID:0002UY], [UID:0002UZ], and [UID:0002V0] already provide exact class-local `.rdata` children for `SelfLookPane`, `SpelledPane`, and `LegendPane`. Their parent blanks are mechanical gate results, not evidence that the vtable owners are unknown.
- [UID:0002V1] already documents the mixed `CollectionPane`, `CollectionPane2`, `SelfLookPane2`, `LineIterator` composition. Live IDA confirms the exact boundaries and proves it must not be assigned wholesale to the look-pane family.
- [UID:00026V] already attaches to [UID:0000P0] `UserLookPane` and documents the three local user-look vtable groups plus resource strings. Live IDA confirms the group boundaries and store refs; the page just needs exact children before final routing.
- [UID:0000P0] `UserLookPane` is `88/85` and directly owns the local `MoreInfoPane`/`ProfilePane` grouping. This is the only source root in the target set that currently clears the strict file parent gate.

## Ranked Owner Candidates

1. Cross-source non-emitting index [UID:0001Y0] itself - accepted for the broad page. This is the only honest treatment of the full current target because it preserves the evidence without assigning the bytes to a false source owner.
2. Source-local by-vtable family pages - accepted as the next ownership layer. This matches the `GroupPaneFamilyVtables` pattern while avoiding cross-source overclaim.
3. [UID:0000P0] `UserLookPane` - accepted only for the new `UserLookPaneFamilyVtables` child and [UID:00026V] user-look read-only data. It owns `UserLookPane`, `MoreInfoPane`, and `ProfilePane`; it does not own `SelfLookPane`, `SpelledPane`, or `LegendPane`.
4. [UID:0000NL] `SelfLookPane` - accepted as the best source candidate for `SelfLookPane` and `SelfLookPane2`, but not as an immediate parent because [UID:0000NL] is `82/88`, [UID:0000CU] is `80/86`, and [UID:0000CV] is `86/82`.
5. [UID:0000NZ] `SpelledPane` - accepted as the best source candidate for `SpelledPane`, but not as an immediate parent because [UID:0000NZ] and [UID:0000DK] are `86/80`.
6. [UID:0000KM] `LegendPane` - accepted as the best source candidate for `LegendPane`, but not as an immediate parent because [UID:0000KM] is `82/84` and [UID:000074] is `82/86`.
7. Existing physical aggregates [UID:00026E] and [UID:00026V] - rejected as direct type owners. They are `.rdata` containers, not source/type declarations. [UID:00026V] remains a valid file-owned `.rdata` aggregate for UserLookPane; [UID:00026E] remains mixed and parent blank.

## Rejected Alternatives

- Assign [UID:0001Y0] to [UID:0000NL] `SelfLookPane`: rejected because the target also contains `SpelledPane`, `LegendPane`, and user-look/profile vtables, with IDA-confirmed stores from their own constructors/destructors.
- Assign [UID:0001Y0] to [UID:0000P0] `UserLookPane`: rejected because this would overclaim the earlier self-look/spelled/legend vtable data at `0x00624188-0x00624438` and `0x006246f4-0x00624780`.
- Assign [UID:0001Y0] to [UID:0000NZ] or [UID:0000KM]: rejected because each covers only one shared child-pane class and neither currently clears `85/85`.
- Assign [UID:0001Y0] to [UID:0000JQ] `GeneralPurposePanel`: rejected because `GeneralPurposePanel` constructs pane instances but does not own their class declarations or vtable layouts.
- Assign [UID:0001Y0] to [UID:0001XP] `GroupPaneFamilyVtables`: rejected because IDA boundaries explicitly separate group panes from look/spelled/legend/user-look owners. `GroupPaneFamilyVtables` is a precedent, not a parent.
- Create a new top-level `LookPaneVtables.cpp` or `LookPaneVtableFamily.cpp`: rejected. No IDA source metadata, constructor clustering, or documentation evidence supports a single original source file for all listed classes. The broad page is a documentation index.
- Attach exact children to [UID:0001Y0]: rejected because [UID:0001Y0] is multi-owner and should become `RECONSTRUCTABLE:FALSE`; exact data children should attach to source-local by-vtable pages or stay blank until their direct source gate is repaired.

## Coverage-Report Text For Supervisor

Do not apply these rows to `by-memory/-coverage-report.md` while the temporary ban is active. They are exact pending text with `UID:TBD` placeholders for new files; replace placeholders with real UIDs after file creation/validation.

### by-type/by-vtable/-coverage-report.md

Replace the existing [UID:0001Y0] row with:

```text
- [UID:0001Y0][LookPaneVtableFamily](by-type/by-vtable/LookPaneVtableFamily.md) : ignored : 88% : strong : B001-048 live IDA MCP recheck confirms this is a non-emitting cross-source vtable inventory spanning SelfLookPane/SelfLookPane2, SpelledPane, LegendPane, UserLookPane, MoreInfoPane, and ProfilePane. Keep parent blank and split source-local ownership through SelfLookPaneFamilyVtables, SpelledPaneVtables, LegendPaneVtables, and UserLookPaneFamilyVtables; do not use this broad aggregate as a direct autogen parent.
```

Insert immediately after that row once new by-vtable pages exist:

```text
- [UID:TBD][SelfLookPaneFamilyVtables](by-type/by-vtable/SelfLookPaneFamilyVtables.md) : reconstructable : 86% : strong : Source-local vtable layout page for SelfLookPane and SelfLookPane2; live IDA confirms COL/vtable groups at 0x00624184/0x00624188 through 0x00624208 and 0x006246f4/0x006246f8 through 0x00624778 with constructor/cleanup/scalar-destructor stores. Parent remains blank until SelfLookPane.cpp and direct class pages clear the corrected 85/85 gate.
- [UID:TBD][SpelledPaneVtables](by-type/by-vtable/SpelledPaneVtables.md) : reconstructable : 86% : strong : Exact SpelledPane four-view vtable layout at 0x006242c4-0x00624384; live IDA confirms constructor stores at 0x0056bb92/0x0056bb98/0x0056bba2/0x0056bbac and destructor-neighborhood stores at 0x0056bc26/0x0056bc2c/0x0056bc36/0x0056bc40. Parent remains blank until SpelledPane class/file confidence clears 85.
- [UID:TBD][LegendPaneVtables](by-type/by-vtable/LegendPaneVtables.md) : reconstructable : 86% : strong : Exact LegendPane three-view vtable layout at 0x00624384-0x00624438; live IDA confirms constructor stores at 0x0056c466/0x0056c46e/0x0056c478 and shared child-pane use. Parent remains blank until LegendPane class/file pages clear 85/85.
- [UID:TBD][UserLookPaneFamilyVtables](by-type/by-vtable/UserLookPaneFamilyVtables.md) : reconstructable : 87% : strong : Source-local UserLookPane.cpp vtable layout page for UserLookPane, MoreInfoPane, and ProfilePane; live IDA confirms exact groups at 0x0062eccc-0x0062eebc with constructor/cleanup/destructor store refs. Assigned to [UID:0000P0][UserLookPane](by-file/UserLookPane.md), which clears 88/85 and owns the local child-pane family.
```

### by-memory/-coverage-report.md, [UID:00026E] area

Replace the [UID:0002UY], [UID:0002UZ], [UID:0002V0], and [UID:0002V1] rows under [UID:00026E] with:

```text
        - [UID:0002UY][0x00624188-0x00624210.SelfLookPaneVtableData](by-memory/0x00624188-0x00624210.SelfLookPaneVtableData.md) 0x00624188-0x00624210 | vtable-data | SelfLookPaneVtableData : reconstructable : 88% : strong : Exact SelfLookPane COL/vtable data; B001-048 live IDA reconfirmed constructor, cleanup, and scalar-deleting-destructor stores. Keep parent blank until the new SelfLookPaneFamilyVtables page can be source-parented under the corrected 85/85 gate.
        - [UID:0002UZ][0x006242c4-0x00624384.SpelledPaneVtableData](by-memory/0x006242c4-0x00624384.SpelledPaneVtableData.md) 0x006242c4-0x00624384 | vtable-data | SpelledPaneVtableData : reconstructable : 86% : strong : Exact SpelledPane four-view COL/vtable data; B001-048 live IDA reconfirmed constructor and destructor-neighborhood stores. Keep parent blank until the new SpelledPaneVtables page can be source-parented under the corrected 85/85 gate.
        - [UID:0002V0][0x00624384-0x00624438.LegendPaneVtableData](by-memory/0x00624384-0x00624438.LegendPaneVtableData.md) 0x00624384-0x00624438 | vtable-data | LegendPaneVtableData : reconstructable : 86% : strong : Exact LegendPane three-view COL/vtable data; B001-048 live IDA reconfirmed constructor stores and inherited destructor/thunk slot targets. Keep parent blank until the new LegendPaneVtables page can be source-parented under the corrected 85/85 gate.
        - [UID:0002V1][0x006245dc-0x00624788.CollectionLookLineVtableData](by-memory/0x006245dc-0x00624788.CollectionLookLineVtableData.md) 0x006245dc-0x00624788 | vtable-data split inventory | CollectionLookLineVtableData : not_reconstructable : 88% : strong : B001-048 live IDA reconfirmed this is a mixed non-emitting inventory over CollectionPane, CollectionPane2, SelfLookPane2, and LineIterator vtable children. Keep parent blank; exact children carry or await their own owners.
            - [UID:TBD][0x006245dc-0x00624668.CollectionPaneVtableData](by-memory/0x006245dc-0x00624668.CollectionPaneVtableData.md) 0x006245dc-0x00624668 | vtable-data | CollectionPaneVtableData : reconstructable : 86% : strong : Exact CollectionPane COL/vtable child split out of mixed [UID:0002V1]; live IDA confirms three table views and constructor/destructor store refs. Parent pending separate CollectionPane gate audit.
            - [UID:TBD][0x00624668-0x006246f4.CollectionPane2VtableData](by-memory/0x00624668-0x006246f4.CollectionPane2VtableData.md) 0x00624668-0x006246f4 | vtable-data | CollectionPane2VtableData : reconstructable : 86% : strong : Exact CollectionPane2 COL/vtable child split out of mixed [UID:0002V1]; live IDA confirms three table views and constructor/destructor store refs. Parent pending separate CollectionPane2 gate audit.
            - [UID:TBD][0x006246f4-0x00624780.SelfLookPane2VtableData](by-memory/0x006246f4-0x00624780.SelfLookPane2VtableData.md) 0x006246f4-0x00624780 | vtable-data | SelfLookPane2VtableData : reconstructable : 88% : strong : Exact SelfLookPane2 COL/vtable child; live IDA confirms constructor stores from sub_56FE80, cleanup stores from sub_570030, and scalar-deleting-destructor stores from sub_573640. Parent remains blank until SelfLookPaneFamilyVtables and its source chain clear 85/85.
            - [UID:TBD][0x00624780-0x00624788.LineIteratorVtableData](by-memory/0x00624780-0x00624788.LineIteratorVtableData.md) 0x00624780-0x00624788 | vtable-data | LineIteratorVtableData : reconstructable : 86% : strong : Exact LineIterator one-slot COL/vtable child; live IDA confirms vtable 0x00624784, first slot 0x00573540, and boundary before LOOKEXT.EPF. Parent pending LineIterator_vtable/direct owner gate audit.
```

### by-memory/-coverage-report.md, [UID:00026V] area

Replace the current [UID:00026V] row with:

```text
    - [UID:00026V][0x0062eccc-0x0062ef0c.UserLookReadOnlyData](by-memory/0x0062eccc-0x0062ef0c.UserLookReadOnlyData.md) 0x0062eccc-0x0062ef0c | vtable/string-data | UserLookReadOnlyData : reconstructable : 86% : strong : Attached to [UID:0000P0][UserLookPane](by-file/UserLookPane.md); B001-048 live IDA reconfirmed exact UserLookPane, MoreInfoPane, and ProfilePane COL/vtable groups, constructor/cleanup/destructor store refs, and resource tail literals USERLOOK.PAL, PFLOOK.EPF, and NATION.EPF. Exact children route through the new UserLookPaneFamilyVtables layout parent or directly to UserLookPane.cpp for resource strings.
        - [UID:TBD][0x0062eccc-0x0062ed58.UserLookPaneVtableData](by-memory/0x0062eccc-0x0062ed58.UserLookPaneVtableData.md) 0x0062eccc-0x0062ed58 | vtable-data | UserLookPaneVtableData : reconstructable : 88% : strong : Exact UserLookPane COL/vtable data; live IDA confirms constructor stores at 0x0059f297/0x0059f29d/0x0059f2a9, cleanup stores at 0x0059f52c/0x0059f532/0x0059f53c, and scalar-deleting-destructor stores at 0x005a2423/0x005a2429/0x005a2433. Assign to new UserLookPaneFamilyVtables UID after that page is created and parented to [UID:0000P0].
        - [UID:TBD][0x0062ed58-0x0062ee0c.MoreInfoPaneVtableData](by-memory/0x0062ed58-0x0062ee0c.MoreInfoPaneVtableData.md) 0x0062ed58-0x0062ee0c | vtable-data | MoreInfoPaneVtableData : reconstructable : 88% : strong : Exact MoreInfoPane COL/vtable data for the UserLookPane-local child; live IDA confirms constructor stores at 0x0059f338/0x0059f33e/0x0059f348 and destructor-neighborhood refs at 0x005a231c/0x005a2324/0x005a232e. Assign to new UserLookPaneFamilyVtables UID after that page is created and parented to [UID:0000P0].
        - [UID:TBD][0x0062ee0c-0x0062eebc.ProfilePaneVtableData](by-memory/0x0062ee0c-0x0062eebc.ProfilePaneVtableData.md) 0x0062ee0c-0x0062eebc | vtable-data | ProfilePaneVtableData : reconstructable : 88% : strong : Exact ProfilePane COL/vtable data for the UserLookPane-local profile/bio child; live IDA confirms constructor stores at 0x0059f3ce/0x0059f3d4/0x0059f3de and destructor-neighborhood refs at 0x005a239c/0x005a23a4/0x005a23ae. Assign to new UserLookPaneFamilyVtables UID after that page is created and parented to [UID:0000P0].
        - [UID:TBD][0x0062eebc-0x0062ef0c.UserLookPaneResourceStringData](by-memory/0x0062eebc-0x0062ef0c.UserLookPaneResourceStringData.md) 0x0062eebc-0x0062ef0c | resource-string-data | UserLookPaneResourceStringData : reconstructable : 85% : strong : Exact user-look/profile resource string tail containing USERLOOK.PAL at 0x0062eebc, PFLOOK.EPF at 0x0062eed8, and NATION.EPF at 0x0062eef0. Assign to [UID:0000P0][UserLookPane](by-file/UserLookPane.md).
```

## Low-Confidence Facts And Remaining Blockers

- Original source-file shape for `SpelledPane` and `LegendPane` remains unresolved: they may be standalone small source files or local/shared classes in a broader look/status source. That uncertainty blocks source-parenting their by-vtable child pages today, but it does not block exact child creation.
- `SelfLookPane.cpp` is the best owner for both `SelfLookPane` and `SelfLookPane2`, but the file page is only `82/88`, and the direct class pages are `80/86` and `86/82`. Do not attach the new self-look vtable family until that chain is repaired.
- Generated coverage historically required the `GroupPaneFamilyVtables` by-type page to be source-parented before memory children stopped reporting parent problems. For that reason, this report recommends leaving self/spelled/legend memory children blank until their source-local by-vtable pages have gate-clearing source parents.
- The proposed new by-vtable page UIDs are unknown. Coverage text uses `UID:TBD` placeholders and must be updated after creation.
- `LineIteratorVtableData` and the two collection vtable children are split-repair consequences, not part of the [UID:0001Y0] ownership target. Their final parent decisions should be handled by the relevant owner audits.

## Validation Plan After Supervisor Implementation

1. Validate each newly created by-type page and ensure new UIDs are registered.
2. Validate each new by-memory exact child page and confirm no overlap errors against [UID:0002V1] or [UID:00026V].
3. Regenerate or re-run the project documentation coverage checks for `by-type/by-vtable` and `by-memory`.
4. Confirm [UID:0001Y0] appears as a parentless ignored/non-emitting index, not as a reconstructable source-owned family.
5. Confirm the three user-look vtable children resolve through the new `UserLookPaneFamilyVtables` UID and that this by-vtable page resolves to [UID:0000P0].
6. Confirm self-look, spelled, and legend exact children remain intentionally parent blank until their direct source/type parent chains clear the corrected `85/85` gate.

## Scope Notes

- No final project documentation pages were edited in this run.
- No leases were required because the only file created is this report under `tools/leaser/Agents/Agent-B001/research`.
- The banned `by-memory/-coverage-report.md` file was not edited. Exact pending replacement/insert rows are included above for supervisor application.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0001Y0-LookPaneVtableFamily.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:20","uid":"0001Y0"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
