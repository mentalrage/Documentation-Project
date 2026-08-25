** TARGET-REPORT-UID:0002V2 **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# [UID:0002V2] LookGroupCollectionResourceStringData Ownership Research

Revision: B001-051, 2026-06-12

## Final Recommendation

Do not assign [UID:0002V2][0x00624788-0x00624c64.LookGroupCollectionResourceStringData](../../../../../by-memory/0x00624788-0x00624c64.LookGroupCollectionResourceStringData.md) to `SelfLookPane`, `Group`, `CollectionPane`, `SpelledPane`, `UserLookPane`, `UserStatusPane`, `GeneralPurposePanel`, `LineIterator`, or a new broad `LookGroupCollectionPanes.cpp` file.

The strongest executable disposition is to convert `0002V2` from a source-bearing aggregate into a parent-blank, non-emitting mixed resource/constant split inventory, matching the already-used pattern for mixed `.rdata` parents such as the Clan resource-string map:

- `RECONSTRUCTABLE:FALSE`
- `COMPLETION:88`
- `CONFIDENCE:92`
- `AUTOGEN_PARENT_UID:` blank
- no final C++ on the master page

Then create exact child pages for the source-local strings/constants and the pooled shared resource literals. Most child pages can route directly to existing gate-clearing file parents:

- [UID:0000NL] `SelfLookPane` (`85/89`) for SelfLookPane/SelfLookPane2 local strings and rectangle constants.
- [UID:0000JS] `Group` (`89/85`) for GroupPane resource strings and constants.
- [UID:0000IC] `CollectionPane` (`87/86`) for CollectionPane resource strings and constants.
- [UID:0000NZ] `SpelledPane` (`87/85`) for the separator string.

Three child ranges should remain parent-blank and non-emitting as pooled shared resource literals, because direct IDA xrefs cross unrelated source files with no common direct source owner:

- `0x006247f0-0x00624804` `COMMA.EPF`: SelfLookPane, GroupPane, and UserStatusPane2.
- `0x006248cc-0x006248e0` `COMMA.PAL`: SelfLookPane and UserStatusPane2.
- `0x00624b90-0x00624ba8` `STATBUT.EPF`: SelfLookPane2 and UserLookPane.

This is not a recommendation to leave ownership unknown. It is an executable split/reclassification recommendation: the current physical range is a linker-pooled/mixed `.rdata` island, not one original source declaration unit. Source-local children should be created and assigned; shared pooled-literal children should document why no single source parent is correct.

## Exact by-memory/-coverage-report.md Replacement Rows

Placement: replace the current `0002V2` row under [UID:00026E] `0x00624188-0x00624c64.LookGroupCollectionReadOnlyData`, immediately after [UID:00038W] `LineIteratorVtableData` and before [UID:00026F] `SimpleServerSelectReadOnlyData`.

The new child UIDs are necessarily `UID:TBD` until the supervisor creates/validates the pages. Replace `UID:TBD` with assigned UIDs after validator allocation; the ranges, names, row order, parent routing, and wording below are the intended rows.

```markdown
        - [UID:0002V2][0x00624788-0x00624c64.LookGroupCollectionResourceStringData](by-memory/0x00624788-0x00624c64.LookGroupCollectionResourceStringData.md) 0x00624788-0x00624c64 | mixed resource/constant split inventory | LookGroupCollectionResourceStringData : not_reconstructable : 88% : very-strong : B001-051 recommends converting this source-bearing aggregate to a parent-blank non-emitting map; live IDA found 74 named heads and 97 direct xrefs spanning SelfLookPane/SelfLookPane2, GroupPane, CollectionPane, SpelledPane, UserLookPane, and UserStatusPane2, with shared pooled literals `COMMA.EPF`, `COMMA.PAL`, and `STATBUT.EPF`; exact children below carry source-local or shared-literal handling.
            - [UID:TBD][0x00624788-0x006247f0.SelfLookPaneLookResourceStrings](by-memory/0x00624788-0x006247f0.SelfLookPaneLookResourceStrings.md) 0x00624788-0x006247f0 | resource-string-data | SelfLookPaneLookResourceStrings : reconstructable : 85% : strong : Assign to [UID:0000NL][SelfLookPane](by-file/SelfLookPane.md); IDA decodes `LOOKEXT.EPF`, `LOOKEXT.PAL`, `LOOK.EPF`, and `LOOKICON.PAL` string starts with 13 refs from `0x00567480` and one SelfLookPane2 ref from `0x00570fc0`, both owned by the SelfLookPane source file.
            - [UID:TBD][0x006247f0-0x00624804.SharedCommaEpfResourceString](by-memory/0x006247f0-0x00624804.SharedCommaEpfResourceString.md) 0x006247f0-0x00624804 | pooled shared resource literal | SharedCommaEpfResourceString : not_reconstructable : 85% : strong : Keep parent blank; `COMMA.EPF` has direct refs from SelfLookPane `0x00567480`, GroupPane `0x0056ce50`, and UserStatusPane2 `0x005baf80`, so assigning the pooled physical literal to one source file would overclaim ownership.
            - [UID:TBD][0x00624804-0x006248cc.SelfLookPaneLookIconNationStrings](by-memory/0x00624804-0x006248cc.SelfLookPaneLookIconNationStrings.md) 0x00624804-0x006248cc | resource/string-data | SelfLookPaneLookIconNationStrings : reconstructable : 85% : strong : Assign to [UID:0000NL][SelfLookPane](by-file/SelfLookPane.md); IDA decodes `LOOKICON.EPF`, `STATBUTS.EPF`, nation/marker fragments, and related UTF-16 starts with 14 refs all from SelfLookPane paint/render function `0x00567480`.
            - [UID:TBD][0x006248cc-0x006248e0.SharedCommaPalResourceString](by-memory/0x006248cc-0x006248e0.SharedCommaPalResourceString.md) 0x006248cc-0x006248e0 | pooled shared resource literal | SharedCommaPalResourceString : not_reconstructable : 85% : strong : Keep parent blank; `COMMA.PAL` has three refs from SelfLookPane `0x00567480` and four refs from UserStatusPane2 `0x005baf80`, matching a pooled shared resource literal rather than one source-local declaration.
            - [UID:TBD][0x006248e0-0x00624a50.SelfLookPaneEquipmentSlotLabelStrings](by-memory/0x006248e0-0x00624a50.SelfLookPaneEquipmentSlotLabelStrings.md) 0x006248e0-0x00624a50 | string-data | SelfLookPaneEquipmentSlotLabelStrings : reconstructable : 85% : strong : Assign to [UID:0000NL][SelfLookPane](by-file/SelfLookPane.md); IDA finds 14 refs all from SelfLookPane help/equipment text function `0x00569860` into the body, hand, accessory, mantle, necklace, foot, and coat label fragments.
            - [UID:TBD][0x00624a50-0x00624a84.SpelledPaneSeparatorString](by-memory/0x00624a50-0x00624a84.SpelledPaneSeparatorString.md) 0x00624a50-0x00624a84 | string-data | SpelledPaneSeparatorString : reconstructable : 85% : strong : Assign to [UID:0000NZ][SpelledPane](by-file/SpelledPane.md); IDA decodes `------------------------\n` and finds its direct ref at `0x0056bfc1` inside SpelledPane function `0x0056bea0`.
            - [UID:TBD][0x00624a84-0x00624a98.GroupPaneGroupEpfResourceString](by-memory/0x00624a84-0x00624a98.GroupPaneGroupEpfResourceString.md) 0x00624a84-0x00624a98 | resource-string-data | GroupPaneGroupEpfResourceString : reconstructable : 85% : strong : Assign to [UID:0000JS][Group](by-file/Group.md); `GROUP.EPF` has refs from GroupPane family functions `0x0056c6c0`, `0x0056c970`, and `0x0056ce50`.
            - [UID:TBD][0x00624a98-0x00624b30.CollectionPanePanelResourceStrings](by-memory/0x00624a98-0x00624b30.CollectionPanePanelResourceStrings.md) 0x00624a98-0x00624b30 | resource/string-data | CollectionPanePanelResourceStrings : reconstructable : 86% : strong : Assign to [UID:0000IC][CollectionPane](by-file/CollectionPane.md); IDA decodes `Collections`, `GroupNames`, `CLTINV.EPF`, `CLTLIST.EPF`, `CLTLIST.PAL`, and count format strings with 14 refs from CollectionPane/CollectionPane2 functions `0x0056ea30`, `0x0056edc0`, `0x0056f810`, and `0x0056fdd0`.
            - [UID:TBD][0x00624b30-0x00624b74.GroupPaneCollectionResourceStrings](by-memory/0x00624b30-0x00624b74.GroupPaneCollectionResourceStrings.md) 0x00624b30-0x00624b74 | resource/string-data | GroupPaneCollectionResourceStrings : reconstructable : 85% : strong : Assign to [UID:0000JS][Group](by-file/Group.md); IDA decodes `GROUPCOL.EPF`, `GROUPCOL.PAL`, and `%d`, all referenced from GroupPane family function `0x0056ce50`.
            - [UID:TBD][0x00624b74-0x00624b90.SelfLookPane2LookPalStringFragments](by-memory/0x00624b74-0x00624b90.SelfLookPane2LookPalStringFragments.md) 0x00624b74-0x00624b90 | string/resource-fragment data | SelfLookPane2LookPalStringFragments : reconstructable : 85% : strong : Assign to [UID:0000NL][SelfLookPane](by-file/SelfLookPane.md); IDA finds the direct ref at `0x00571005` inside SelfLookPane2 function `0x00570fc0`, and the range contains the adjacent `SE`/`LOOK.PAL` UTF-16 fragments before the shared stat-button resource.
            - [UID:TBD][0x00624b90-0x00624ba8.SharedStatButtonEpfResourceString](by-memory/0x00624b90-0x00624ba8.SharedStatButtonEpfResourceString.md) 0x00624b90-0x00624ba8 | pooled shared resource literal | SharedStatButtonEpfResourceString : not_reconstructable : 85% : strong : Keep parent blank; `STATBUT.EPF` has eight refs from SelfLookPane2 `0x00570fc0` and two refs from UserLookPane `0x005a0640`, so the physical string is shared across look-panel source owners.
            - [UID:TBD][0x00624ba8-0x00624bd0.SelfLookPane2StatButtonLabelStrings](by-memory/0x00624ba8-0x00624bd0.SelfLookPane2StatButtonLabelStrings.md) 0x00624ba8-0x00624bd0 | string-data | SelfLookPane2StatButtonLabelStrings : reconstructable : 85% : strong : Assign to [UID:0000NL][SelfLookPane](by-file/SelfLookPane.md); IDA finds two direct refs from SelfLookPane2 function `0x00570fc0` to the UTF-16 word/string starts at `0x00624ba8` and `0x00624bbc`.
            - [UID:TBD][0x00624bd0-0x00624be0.GroupPaneScaleConstant](by-memory/0x00624bd0-0x00624be0.GroupPaneScaleConstant.md) 0x00624bd0-0x00624be0 | numeric constant | GroupPaneScaleConstant : reconstructable : 85% : strong : Assign to [UID:0000JS][Group](by-file/Group.md); IDA decodes `qword_624BD0` as double `100.0` and finds two `mulsd` refs from GroupPane family function `0x0056ce50`.
            - [UID:TBD][0x00624be0-0x00624bf0.SelfLookPaneRectConstantsA](by-memory/0x00624be0-0x00624bf0.SelfLookPaneRectConstantsA.md) 0x00624be0-0x00624bf0 | packed rectangle constants | SelfLookPaneRectConstantsA : reconstructable : 85% : strong : Assign to [UID:0000NL][SelfLookPane](by-file/SelfLookPane.md); IDA decodes `[7, 63, 121, 7]` and finds the single `movaps` ref from SelfLookPane `0x00567480`.
            - [UID:TBD][0x00624bf0-0x00624c00.GroupPaneRectConstant](by-memory/0x00624bf0-0x00624c00.GroupPaneRectConstant.md) 0x00624bf0-0x00624c00 | packed rectangle constants | GroupPaneRectConstant : reconstructable : 85% : strong : Assign to [UID:0000JS][Group](by-file/Group.md); IDA decodes `[6, 14, 161, 54]` and finds the single `movaps` ref from GroupPane family function `0x0056ce50`.
            - [UID:TBD][0x00624c00-0x00624c10.SelfLookPaneRectConstantB](by-memory/0x00624c00-0x00624c10.SelfLookPaneRectConstantB.md) 0x00624c00-0x00624c10 | packed rectangle constants | SelfLookPaneRectConstantB : reconstructable : 85% : strong : Assign to [UID:0000NL][SelfLookPane](by-file/SelfLookPane.md); IDA decodes `[10, 10, 10, 62]` and finds the single `movaps` ref from SelfLookPane `0x00567480`.
            - [UID:TBD][0x00624c10-0x00624c20.CollectionPaneRectConstant](by-memory/0x00624c10-0x00624c20.CollectionPaneRectConstant.md) 0x00624c10-0x00624c20 | packed rectangle constants | CollectionPaneRectConstant : reconstructable : 85% : strong : Assign to [UID:0000IC][CollectionPane](by-file/CollectionPane.md); IDA decodes `[6, 14, 161, 62]` and finds the single `movaps` ref from CollectionPane function `0x0056edc0`.
            - [UID:TBD][0x00624c20-0x00624c64.SelfLookPaneRectConstantsC](by-memory/0x00624c20-0x00624c64.SelfLookPaneRectConstantsC.md) 0x00624c20-0x00624c64 | packed rectangle constants | SelfLookPaneRectConstantsC : reconstructable : 85% : strong : Assign to [UID:0000NL][SelfLookPane](by-file/SelfLookPane.md); IDA decodes four packed vectors `[63,121,7,63]`, `[62,62,114,114]`, `[121,7,63,121]`, and `[114,166,166,166]`, each referenced from SelfLookPane `0x00567480`.
```

## Supporting Research

### Target

- Target UID: `0002V2`
- Target path: `by-memory/0x00624788-0x00624c64.LookGroupCollectionResourceStringData.md`
- Supervisor status: `reviewed-85-but-ownership-unknown-under-review`
- Current child state before this report: `RECONSTRUCTABLE:TRUE`, `COMPLETION:87`, `CONFIDENCE:91`, parent blank
- Containing aggregate: [UID:00026E][0x00624188-0x00624c64.LookGroupCollectionReadOnlyData](../../../../../by-memory/0x00624188-0x00624c64.LookGroupCollectionReadOnlyData.md), already a parent-blank non-emitting mixed `.rdata` index

### IDA MCP Environment

Live IDA MCP evidence was collected read-only against:

- Image: `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`
- Image base: `0x00400000`
- MD5: `4247e04e20b65d6414c7238aa8ff5515`

No by-* documentation page and no coverage report was edited for this B001 assignment.

### Confirmed Binary Facts

IDA MCP `py_eval` confirms:

- Range: `0x00624788-0x00624c64`
- Segment: `.rdata`
- Previous named head: `0x00624784 ??_7LineIterator@@6B@`
- First target head: `0x00624788 aLookextEpf`
- Successor at target end: `0x00624c64 ??_7SimpleListPane@@6B@`
- Named heads in target: 74
- Direct xrefs into target: 97

Direct xref owner distribution after mapping executable ranges:

| Owner bucket | Direct refs |
| --- | ---: |
| `SelfLookPane` | 51 |
| `CollectionPane family` | 15 |
| `SelfLookPane2 family` | 12 |
| `GroupPane family` | 11 |
| `UserStatusPane2` | 5 |
| `UserLookPane` | 2 |
| `SpelledPane` | 1 |

There were no source metadata hits for `RSDS`, `NB10`, `.pdb`, `.cpp`, or `.cxx` in loaded segments. This report therefore cannot claim original source-file proof from debug records or path strings.

### Child Range Evidence

The exact child ranges above come from a byte-range xref scan over every address in `0x00624788-0x00624c64`, then grouping by named heads and direct owner sets. Important owner-local runs:

| Range | Direct owner evidence | Routing implication |
| --- | --- | --- |
| `0x00624788-0x006247f0` | SelfLookPane plus one SelfLookPane2 ref, both under [UID:0000NL] | assign to SelfLookPane file |
| `0x006247f0-0x00624804` | SelfLookPane, GroupPane, UserStatusPane2 | pooled shared literal, parent blank |
| `0x00624804-0x006248cc` | SelfLookPane only | assign to SelfLookPane file |
| `0x006248cc-0x006248e0` | SelfLookPane and UserStatusPane2 | pooled shared literal, parent blank |
| `0x006248e0-0x00624a50` | SelfLookPane only | assign to SelfLookPane file |
| `0x00624a50-0x00624a84` | SpelledPane only | assign to SpelledPane file |
| `0x00624a84-0x00624a98` | GroupPane family only | assign to Group file |
| `0x00624a98-0x00624b30` | CollectionPane family only | assign to CollectionPane file |
| `0x00624b30-0x00624b74` | GroupPane family only | assign to Group file |
| `0x00624b74-0x00624b90` | SelfLookPane2 only | assign to SelfLookPane file |
| `0x00624b90-0x00624ba8` | SelfLookPane2 and UserLookPane | pooled shared literal, parent blank |
| `0x00624ba8-0x00624bd0` | SelfLookPane2 only | assign to SelfLookPane file |
| `0x00624bd0-0x00624be0` | GroupPane only | assign to Group file |
| `0x00624be0-0x00624bf0` | SelfLookPane only | assign to SelfLookPane file |
| `0x00624bf0-0x00624c00` | GroupPane only | assign to Group file |
| `0x00624c00-0x00624c10` | SelfLookPane only | assign to SelfLookPane file |
| `0x00624c10-0x00624c20` | CollectionPane only | assign to CollectionPane file |
| `0x00624c20-0x00624c64` | SelfLookPane only | assign to SelfLookPane file |

The unreferenced suffix/interior labels inside some UTF-16 strings should be documented as suffix labels, not as separate owners. This mirrors the Clan resource-string split precedent, where IDA `off_*` or suffix labels inside full UTF-16 strings were not treated as pointer-table cells.

### Parent Gate Check

The proposed assigned child parents already clear the `85/85` direct-parent gate:

| Parent | UID | Score | Relevant child groups |
| --- | --- | ---: | --- |
| `SelfLookPane` file | `0000NL` | `85/89` | SelfLookPane/SelfLookPane2 look strings, equipment labels, stat labels, rectangle constants |
| `Group` file | `0000JS` | `89/85` | GroupPane `GROUP.EPF`, `GROUPCOL.*`, count format, scale/rectangle constants |
| `CollectionPane` file | `0000IC` | `87/86` | `Collections`, `GroupNames`, `CLTINV/CLTLIST` strings, collection rectangle constant |
| `SpelledPane` file | `0000NZ` | `87/85` | `------------------------\n` separator string |

The shared pooled-literal children deliberately have no direct parent. [UID:0000P2] `UserStatusPane` (`88/85`) and [UID:0000P0] `UserLookPane` (`88/85`) clear the gate as consumers, but they do not jointly own the pooled `COMMA.*` and `STATBUT.EPF` physical literals. A by-resource page can remain supporting evidence, but by-resource pages are not the direct autogen source parent for these physical `.rdata` cells.

### Ranked Ownership Analysis

#### 1. Reclassify `0002V2` as a mixed non-emitting split inventory

Recommendation rank: best current action.

Evidence for:

- Live IDA xrefs span at least six independent source families: SelfLookPane/SelfLookPane2, GroupPane, CollectionPane, SpelledPane, UserLookPane, and UserStatusPane2.
- Several contiguous subranges are source-local and assignable, but the physical target also contains pooled shared literals and alternating packed constants.
- The containing [UID:00026E] aggregate is already a non-emitting mixed `.rdata` map, and nearby [UID:0002V1] vtable data was already split into exact children rather than assigned wholesale.
- The Clan resource-string split provides a direct precedent: a broad resource-string aggregate becomes `RECONSTRUCTABLE:FALSE`, while exact resource-string children carry source ownership where xrefs are owner-local.

Evidence against:

- It requires supervisor work to create many smaller child pages.
- It leaves three tiny pooled-literal children parent-blank. That is intentional because the binary physical literals are shared across source owners.

Conclusion: convert the master to a non-emitting map and create the exact child pages above.

Confidence: `92/100`.

#### 2. Assign the entire range to `SelfLookPane.cpp`

Evidence for:

- SelfLookPane/SelfLookPane2 account for most direct refs: 63 of 97.
- The range begins and ends with SelfLookPane/SelfLookPane2 material.

Evidence against:

- The range also contains GroupPane, CollectionPane, SpelledPane, UserLookPane, and UserStatusPane2 direct refs.
- Assigning the whole physical island to SelfLookPane would falsely absorb `GROUP.EPF`, `GROUPCOL.*`, `Collections`, `GroupNames`, `CLTINV/CLTLIST`, the SpelledPane separator, UserStatusPane2 `COMMA.*`, and UserLookPane `STATBUT.EPF` usage.
- Physical adjacency after vtables is weak in this binary; existing docs already use xref-backed source ownership over raw `.rdata` adjacency.

Conclusion: reject for the master. Use SelfLookPane only for exact child ranges.

Confidence as whole-range parent: `45/100`.

#### 3. Create a new broad `LookGroupCollectionPanes.cpp` source owner

Evidence for:

- The code ranges around SelfLookPane, GroupPane, CollectionPane, and SelfLookPane2 are address-adjacent in the executable.
- The vtables and this resource/constant island are physically adjacent in `.rdata`.

Evidence against:

- Existing source-tree and by-file docs already split these features into `ui/panels/SelfLookPane.cpp`, `social/Group.cpp`, `ui/panels/CollectionPane.cpp`, `ui/panels/SpelledPane.cpp`, `ui/panels/UserLookPane.cpp`, and `ui/panels/UserStatusPane.cpp`.
- Direct xrefs support those feature owners better than one artificial broad file.
- The shared physical literals are explainable as linker string pooling/resource literal pooling; pooling does not prove one source file.
- No debug/source metadata or constructor/static-init evidence names a broad look/group/collection translation unit.

Conclusion: reject. It would erase established feature-source boundaries and still would not handle UserStatusPane2/UserLookPane shared literals cleanly.

Confidence as direct parent: `35/100`.

#### 4. Leave current page unchanged as reconstructable parent-blank

Evidence for:

- Current page already clears child score gate at `87/91`.
- It correctly says no single owner owns the full range.

Evidence against:

- It leaves source-bearing owner-local subranges buried in a mixed parent.
- It keeps the master marked reconstructable even though the physical range is not one source declaration unit.
- The target-specific evidence now justifies an exact child split plan, so stopping at "owner unknown" is weaker than the available action.

Conclusion: reject as final disposition.

Confidence as final state: `50/100`.

### Documentation Evidence Checked

Existing documentation was treated as lead evidence and checked against IDA:

- [UID:00026E] `LookGroupCollectionReadOnlyData` correctly identifies the broader `.rdata` aggregate as non-emitting and mixed across self-look, group, spell/legend, collection, line-iterator, and resource strings.
- [UID:0002V1] `CollectionLookLineVtableData` shows the neighboring vtable range was already split into exact children rather than assigned wholesale.
- [UID:0000NL] `SelfLookPane` places `SelfLookPane` and `SelfLookPane2` together in `NexusTK/ui/panels/SelfLookPane.cpp`; IDA xrefs into target from `0x00567480`, `0x00569860`, and `0x00570fc0` match those classes.
- [UID:0000JS] `Group` places `GroupPane`, `GroupPane2`, and `NewGroupPane` in `social/Group.cpp`; IDA xrefs into target from `0x0056c6c0`, `0x0056c970`, and `0x0056ce50` match that owner.
- [UID:0000IC] `CollectionPane` and [UID:0001R8] `collection-ui-resources` identify `Collections`, `GroupNames`, `CLTINV`, and `CLTLIST` as CollectionPane resource/metadata material; IDA xrefs from `0x0056ea30`, `0x0056edc0`, `0x0056f810`, and `0x0056fdd0` confirm it.
- [UID:0000NZ] `SpelledPane` identifies the reusable text pane; IDA confirms the separator literal is referenced from `0x0056bea0`.
- [UID:0000P0] `UserLookPane` confirms UserLookPane as a separate source owner; IDA confirms `STATBUT.EPF` refs from `0x005a0640`, which makes the physical string shared with SelfLookPane2.
- [UID:0000P2] `UserStatusPane`, [UID:0000FT] `UserStatusPane2`, and [UID:0001RS] `user-status-resources` confirm `COMMA.EPF`/`COMMA.PAL` as UserStatusPane2 compact-number resources; IDA confirms refs from `0x005baf80`, which makes those physical literals shared with look/group code.
- [UID:0001XZ] `LineIterator_vtable` and LineIterator docs confirm `0x00624788` is not a LineIterator vtable slot; it is the first string after the one-slot `LineIterator` vtable.

### Validation Results

No validator was run because this assignment did not edit by-* pages or create the proposed split children. The only changed project file for this turn is this research report. Supervisor implementation should validate each created child page and the updated `0002V2` master page with the standard file validator before applying the coverage rows.

### Changed Files

- `tools/leaser/Agents/Agent-B001/research/0002V2-LookGroupCollectionResourceStringData.md`

No direct edit was made to `by-memory/-coverage-report.md`.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0002V2-LookGroupCollectionResourceStringData.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:21","uid":"0002V2"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
