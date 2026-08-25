*** UID:0001Y0 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# Look Pane Vtable Family

## Status

- Disposition: non-emitting cross-source vtable inventory for NexusTK look/status/profile panel code.
- Covered source owners: [UID:0000NL][SelfLookPane](by-file/SelfLookPane.md), [UID:0000NZ][SpelledPane](by-file/SpelledPane.md), [UID:0000KM][LegendPane](by-file/LegendPane.md), and [UID:0000P0][UserLookPane](by-file/UserLookPane.md).
- Confidence: strong for table bases, RTTI presence, key slot targets, and store xrefs; medium-high for final original source-file split between standalone child panes and broader look-pane sources.
- Verification: IDA MCP `list_globals` checks on 2026-05-26; IDA MCP `py_eval`/`list_globals` recheck on 2026-05-31; A004 live IDA MCP `py_eval` refresh on 2026-06-11.
- Assignment blocker: keep `AUTOGEN_PARENT_UID` blank. This page is a multi-owner vtable-family inventory spanning self-look, spelled, legend, and user-look classes; assigning the aggregate to any one source file or class would violate direct-owner rules. Source-local child pages now carry the attachable ownership surfaces.

## Source-Local Split Pages

| Source-local page | UID | Scope | Parent status |
| --- | --- | --- | --- |
| [UID:00038M][SelfLookPaneFamilyVtables](by-type/by-vtable/SelfLookPaneFamilyVtables.md) | `00038M` | `SelfLookPane` and `SelfLookPane2` vtable layouts. | Parent [UID:0000NL][SelfLookPane](by-file/SelfLookPane.md) after the SelfLookPane source-family gate repair. |
| [UID:00038O][SpelledPaneVtables](by-type/by-vtable/SpelledPaneVtables.md) | `00038O` | `SpelledPane` four-view vtable layout. | Parent [UID:0000DK][SpelledPane](by-class/SpelledPane.md), with [UID:0000NZ][SpelledPane](by-file/SpelledPane.md) as the source file. |
| [UID:00038P][LegendPaneVtables](by-type/by-vtable/LegendPaneVtables.md) | `00038P` | `LegendPane` three-view vtable layout. | Parent [UID:000074][LegendPane](by-class/LegendPane.md), with [UID:0000KM][LegendPane](by-file/LegendPane.md) as the source file. |
| [UID:00038Q][UserLookPaneFamilyVtables](by-type/by-vtable/UserLookPaneFamilyVtables.md) | `00038Q` | `UserLookPane`, `MoreInfoPane`, and `ProfilePane` local vtable layouts. | Parent [UID:0000P0][UserLookPane](by-file/UserLookPane.md), which clears `88/85`. |

The broad page remains useful as an audit/index page, but it must not be used as the direct autogen parent for exact `.rdata` children.

## Self-Look And Shared Child Tables

| Class | Primary vtable | Secondary vtable | Tertiary vtable | Extra view | Proposed file |
| --- | --- | --- | --- | --- | --- |
| `SelfLookPane` | `0x00624188` | `0x006241d8` | `0x00624208` | none | [UID:0000NL][SelfLookPane](by-file/SelfLookPane.md) |
| `SpelledPane` | `0x006242c8` | `0x00624340` | `0x00624370` | `0x0062437c` | [UID:0000NZ][SpelledPane](by-file/SpelledPane.md) |
| `LegendPane` | `0x00624388` | `0x00624400` | `0x00624430` | none | [UID:0000KM][LegendPane](by-file/LegendPane.md) |
| `SelfLookPane2` | `0x006246f8` | `0x00624748` | `0x00624778` | none | [UID:0000NL][SelfLookPane](by-file/SelfLookPane.md) |

`SpelledPane` exposes an extra vtable view beyond the common primary/secondary/tertiary pane layout. Current behavioral docs tie one callback path to a frame-handler-style subobject at `0x0056c300`; keep the extra view as layout evidence until the final class declaration is reconstructed.

## User-Look Tables

| Class | Primary vtable | Secondary vtable | Tertiary vtable | Proposed file |
| --- | --- | --- | --- | --- |
| `UserLookPane` | `0x0062eccc` | `0x0062ed1c` | `0x0062ed4c` | [UID:0000P0][UserLookPane](by-file/UserLookPane.md) |
| `MoreInfoPane` | `0x0062ed58` | `0x0062edd0` | `0x0062ee00` | [UID:0000P0][UserLookPane](by-file/UserLookPane.md) |
| `ProfilePane` | `0x0062ee0c` | `0x0062ee84` | `0x0062eeb4` | [UID:0000P0][UserLookPane](by-file/UserLookPane.md) |

## Layout Evidence

- `SelfLookPane` and `SelfLookPane2` are separate panel classes but belong to the same self-look/status source family.
- `SpelledPane` is constructed by `SelfLookPane`, `SelfLookPane2`, and a system-message/new-system-message path, so it should not be duplicated into only one self-look source.
- `LegendPane` is constructed by `SelfLookPane`, `SelfLookPane2`, and `UserLookPane`, so it remains a shared look/status child source candidate.
- `MoreInfoPane` and `ProfilePane` are tiny user-look child panes with their own vtables, but current caller evidence keeps them local to [UID:0000P0][UserLookPane](by-file/UserLookPane.md).
- The adjustor-thunk strip at `0x005732b5-0x00573302` is compiler-generated layout glue for `SelfLookPane2`, `SelfLookPane`, and `SpelledPane`; final source should model normal inheritance/destructors instead of reconstructing those stubs as handwritten methods.

## Generated Metadata Caveat

Generated class metadata has previously underreported these vtable counts even though IDA exposes complete decorated vtable and RTTI records for every class listed above. This page uses IDA and existing project-documentation evidence as authority, not generated vtable-count metadata.

## Current IDA Recheck

2026-05-31 IDA MCP `py_eval` walked every listed vtable base using IDA names, dword reads, function containment, and data xrefs. The pass confirmed:

- `SelfLookPane`, `SpelledPane`, `LegendPane`, `SelfLookPane2`, `UserLookPane`, `MoreInfoPane`, and `ProfilePane` all have the documented decorated vtable names at their primary, secondary, and tertiary table bases;
- `SpelledPane` has the documented fourth/extra view table at `0x0062437c`, with slot `+0x04 -> 0x0056c300` and data refs from the `SpelledPane` constructor/raw setup path;
- primary tables point to scalar deleting destructor families or inherited pane destructors, while secondary and tertiary first slots point to the expected compiler adjustor thunks;
- key owner/action slots line up with documented executable ranges: `SelfLookPane` primary `+0x48 -> 0x00565890`, `SelfLookPane2` primary `+0x48 -> 0x005700e0`, `UserLookPane` primary `+0x48 -> 0x0059f610`, and the user-look child panes reuse common child-pane behavior;
- store xrefs match the constructor/destructor-reset paths already documented in the executable by-memory pages, including `SelfLookPane` `0x00565610/0x005657e0/0x00573730`, `SelfLookPane2` `0x0056fe80/0x00570030/0x00573640`, `SpelledPane` `0x0056bb20` plus raw setup stores, and `UserLookPane` `0x0059f260/0x0059f500/0x005a23f0`;
- by-memory aggregate coverage exists at [UID:00026E][0x00624188-0x00624c60.LookGroupCollectionReadOnlyData](by-memory/0x00624188-0x00624c60.LookGroupCollectionReadOnlyData.md) and [UID:00026V][0x0062eccc-0x0062ef0c.UserLookReadOnlyData](by-memory/0x0062eccc-0x0062ef0c.UserLookReadOnlyData.md); exact vtable-data children now carry the source-local ownership and this broad page remains only the cross-source index.

2026-06-11 A004 live IDA MCP `py_eval` recheck:

- Decorated IDA names still resolve at every table base listed in the two tables above, including `??_7SelfLookPane@@6B@`, `??_7SpelledPane@@6B@`, `??_7LegendPane@@6B@`, `??_7SelfLookPane2@@6B@`, `??_7UserLookPane@@6B@`, `??_7MoreInfoPane@@6B@`, and `??_7ProfilePane@@6B@`.
- Primary table first slots still point to the expected destructor families: `SelfLookPane -> 0x00573730`, `SpelledPane -> 0x00573820`, `SelfLookPane2 -> 0x00573640`, and `UserLookPane -> 0x005a23f0`; small child panes reuse inherited/common text-pane destructor targets.
- Key action slots remain stable: `SelfLookPane` primary `+0x48 -> 0x00565890`, `SelfLookPane2` primary `+0x48 -> 0x005700e0`, and `UserLookPane` primary `+0x48 -> 0x0059f610`.
- Store xrefs still match constructor/destructor-reset paths: `SelfLookPane` at `0x00565640`, `0x0056580b`, `0x00573762`; `SelfLookPane2` at `0x0056feb3`, `0x0057005b`, `0x00573672`; `SpelledPane` at `0x0056bb92` plus raw setup refs; `LegendPane` at `0x0056c466`; `UserLookPane` at `0x0059f297`, `0x0059f52c`, `0x005a2423`; and local `MoreInfoPane`/`ProfilePane` stores inside `UserLookPane::UserLookPane`.

## Assignment And Score Rationale

- Completion rises to `88` because B001-048 and the supervisor split the source-local ownership layers into separate by-vtable pages and exact missing by-memory children while preserving this page as the broad index.
- Confidence rises to `91` because the live IDA evidence now has explicit source-local routing for SelfLookPane/SelfLookPane2, SpelledPane, LegendPane, and UserLookPane-family vtables. Confidence remains below final-source level because the original translation-unit shape for shared child panes and inherited/common virtual slot names still need final class-declaration reconstruction.
- `RECONSTRUCTABLE` is now `FALSE`: this page is an audit/index over multiple source owners, not a source-emitting type page.
- `AUTOGEN_PARENT_UID` remains blank. Candidate source owners have mixed readiness and, more importantly, no single direct parent owns the aggregate: `SelfLookPane` covers `SelfLookPane`/`SelfLookPane2`, `SpelledPane` covers its four-view child pane, `LegendPane` is shared by self-look and user-look callers, and `UserLookPane` covers `UserLookPane` plus local `MoreInfoPane`/`ProfilePane`.

## Cross-References

- [UID:0001H7][0x00565610-0x0056a373.SelfLookPane](by-memory/0x00565610-0x0056a373.SelfLookPane.md)
- [UID:0001HK][0x0056fe80-0x005729c3.SelfLookPane2](by-memory/0x0056fe80-0x005729c3.SelfLookPane2.md)
- [UID:0001HA][0x0056bb20-0x0056c3f1.SpelledPane](by-memory/0x0056bb20-0x0056c3f1.SpelledPane.md)
- [UID:0001HB][0x0056c400-0x0056c493.LegendPane](by-memory/0x0056c400-0x0056c493.LegendPane.md)
- [UID:0001KK][0x0059f260-0x005a2523.UserLookPaneAndProfilePanes](by-memory/0x0059f260-0x005a2523.UserLookPaneAndProfilePanes.md)
- [UID:0001HN][0x005732b5-0x00573302.LookPaneAdjustorThunks](by-memory/0x005732b5-0x00573302.LookPaneAdjustorThunks.md)
- [UID:00026E][0x00624188-0x00624c60.LookGroupCollectionReadOnlyData](by-memory/0x00624188-0x00624c60.LookGroupCollectionReadOnlyData.md)
- [UID:00026V][0x0062eccc-0x0062ef0c.UserLookReadOnlyData](by-memory/0x0062eccc-0x0062ef0c.UserLookReadOnlyData.md)

## Changes

### 2026-05-31 - Scored IDA-verified look-pane vtable family

- Before: validator metadata marked this page `COMPLETION:0`, `CONFIDENCE:0`, and left `RECONSTRUCTABLE` blank despite a documented vtable inventory.
- Changed to: `COMPLETION:80`, `CONFIDENCE:87`, and `RECONSTRUCTABLE:TRUE`. No parent attachment or C++ reconstruction code was added because final source-file split and exact by-memory child splits for every vtable island are still incomplete.
- Evidence: IDA MCP `py_eval` and `list_globals` on 2026-05-31 confirmed decorated vtable names, slot targets, store xrefs, the `SpelledPane` extra view table, and the aggregate read-only-data ownership boundaries.

### 2026-06-11 - A004 Batch 173 vtable-family refresh

- Before: `COMPLETION:80`, `CONFIDENCE:87`, no autogen parent.
- Changed to: `COMPLETION:85`, `CONFIDENCE:89`, still no autogen parent.
- Evidence: live IDA MCP `py_eval` rechecked every listed table base, representative first slots, key action slots, and constructor/destructor store xrefs. The page now explicitly documents that parent assignment is structurally blocked because this is a multi-owner aggregate; exact per-owner vtable-data children are needed before any class/file attachment.

### 2026-06-11 - B001-048 source-local split implementation

- Before: this page still looked like a reconstructable vtable family even though it crossed several source owners.
- Changed to: `COMPLETION:88`, `CONFIDENCE:91`, `RECONSTRUCTABLE:FALSE`, parent blank. Added source-local by-vtable split pages [UID:00038M][SelfLookPaneFamilyVtables](by-type/by-vtable/SelfLookPaneFamilyVtables.md), [UID:00038O][SpelledPaneVtables](by-type/by-vtable/SpelledPaneVtables.md), [UID:00038P][LegendPaneVtables](by-type/by-vtable/LegendPaneVtables.md), and [UID:00038Q][UserLookPaneFamilyVtables](by-type/by-vtable/UserLookPaneFamilyVtables.md), plus exact missing by-memory children for `SelfLookPane2`, collection neighbors, `LineIterator`, user-look vtable groups, and user-look resource strings.
- Evidence: B001-048 live IDA MCP table-base and store-ref evidence proves the broad page spans SelfLookPane/SelfLookPane2, SpelledPane, LegendPane, UserLookPane, MoreInfoPane, and ProfilePane. Keeping the broad page parentless avoids false ownership while the exact split pages carry source-local ownership.

### 2026-06-22 - Rule 26 closeout for B001-048 older report

- Updated stale source-local split status after later gate repairs: `SelfLookPaneFamilyVtables`, `SpelledPaneVtables`, `LegendPaneVtables`, and `UserLookPaneFamilyVtables` now have their documented direct parents, while this broad [UID:0001Y0] page stays parentless and non-emitting.
- Replaced the older "children not yet split" note with the current ownership model: exact vtable-data children now carry source-local routes and the mixed `.rdata` aggregates remain containment/index pages.
