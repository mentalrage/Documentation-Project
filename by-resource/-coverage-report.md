*** UID:0001R2 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# by-resource Coverage Report

## Summary

- Last generated: 2026-05-26
- Folder: `by-resource`
- Coverage summary: 25 covered reconstructable rows, 0 covered ignored rows, 1 uncovered inventory placeholder row.
- Confidence summary: baseline report generated from existing documentation pages and `-ignored.md`; ignored rows are driven by the local ignored ledger, while reconstructable row confidence is heuristic until IDA/MCP or manual verification raises it.
- Ordering: alphabetic by item name, except `by-memory`, which is sorted by the first address in the row.

## Covered Items To Replicate

- [UID:0001R5][alert-dialog-resources](by-resource/alert-dialog-resources.md) : reconstructable : 72% : strong : Shared alert resources and strings; `BDFRAME.EPF`, the shared `OK` label, employee warning cross-link, owner classes, render/global alias caveats, and reconstruction boundaries documented.
- [UID:0001R6][application-startup-dat-archives](by-resource/application-startup-dat-archives.md) : reconstructable : 88% : strong : - Confidence: strong for resource names and startup call sites; medium for exact original comments/helper names and music-variant semantics.
- [UID:0001R7][backpane-background-resources](by-resource/backpane-background-resources.md) : reconstructable : 50% : medium : - Confidence: strong for named palette strings; medium for exact frame resource names passed into `BackPane`.
- [UID:0001R8][collection-ui-resources](by-resource/collection-ui-resources.md) : reconstructable : 70% : strong : - Resource family: collection list/detail UI EPF/PAL/font resources
- [UID:0001R9][employee-dialog-resources](by-resource/employee-dialog-resources.md) : reconstructable : 50% : medium : - Scope: strings and resource/data constants currently tied to the employee shop dialog family.
- [UID:0001RA][exchange-dialog-resources](by-resource/exchange-dialog-resources.md) : reconstructable : 70% : strong : - Resource family: player exchange/trade dialog UI
- [UID:0001RB][forced-inform-message-resources](by-resource/forced-inform-message-resources.md) : reconstructable : 70% : strong : - Confidence: strong for observed resource names and layout constants.
- [UID:0001RC][hourpane-time-resources](by-resource/hourpane-time-resources.md) : reconstructable : 50% : medium : - Confidence: strong for resource names and HourPane usage, medium for exact frame atlas semantics.
- [UID:0001RD][iconspane-icon-resources](by-resource/iconspane-icon-resources.md) : reconstructable : 50% : medium : - Confidence: strong for resource names and `IconsPane` usage, medium for exact icon semantics.
- [UID:0001RE][interface-efx-resources](by-resource/interface-efx-resources.md) : reconstructable : 50% : medium : - Confidence: strong for observed filenames and owning code; medium for exact DAT family/format details.
- [UID:0001RF][main-menu-history-resources](by-resource/main-menu-history-resources.md) : reconstructable : 70% : strong : - Confidence: strong for resource names and code owners.
- [UID:0001RG][main-menu-story-resources](by-resource/main-menu-story-resources.md) : reconstructable : 70% : strong : - Confidence: strong for `BackStoryDialogPane` resources and `HistoryViewingPane` story resource reuse.
- [UID:0001RH][meta-dat-metadata-cache](by-resource/meta-dat-metadata-cache.md) : reconstructable : 50% : medium : - Resource kind: loose local metadata cache file.
- [UID:0001RI][new-human-motion-tables](by-resource/new-human-motion-tables.md) : reconstructable : 50% : medium : - Resource kind: DAT-backed/new-human sprite composition tables.
- [UID:0001RJ][number-input-dialog-resources](by-resource/number-input-dialog-resources.md) : reconstructable : 70% : strong : - Confidence: strong for resource names and layout split.
- [UID:0001RK][ranking-ui-resources](by-resource/ranking-ui-resources.md) : reconstructable : 70% : strong : - Resource family: ranking board, event list, reward dialog, and custom scroll controls
- [UID:0001RL][sobj-tbl](by-resource/sobj-tbl.md) : reconstructable : 50% : medium : - Confidence: strong for loader addresses and field widths, medium for final field names.
- [UID:0001RM][staff-dialog-resources](by-resource/staff-dialog-resources.md) : reconstructable : 70% : strong : - Confidence: strong for observed names and owner.
- [UID:0001RN][startup-logo-media](by-resource/startup-logo-media.md) : reconstructable : 50% : medium : - Confidence: strong for `.LGO` static logo format and memory-backed segmented Bink payload handling; medium for final Bink helper ownership.
- [UID:0001RO][startup-update-notice-resources](by-resource/startup-update-notice-resources.md) : reconstructable : 70% : strong : - Confidence: strong for resource names and startup owner.
- [UID:0001RP][str-res-localized-strings](by-resource/str-res-localized-strings.md) : reconstructable : 70% : strong : - Resource kind: DAT-backed text resource.
- [UID:0001RQ][timerpane-number-resources](by-resource/timerpane-number-resources.md) : reconstructable : 50% : medium : - Confidence: strong for resource names and call site; medium for exact frame atlas layout.
- [UID:0001RR][totem-frame-resources](by-resource/totem-frame-resources.md) : reconstructable : 50% : medium : - Confidence: strong for resource names and call site; medium for exact frame-index semantics.
- [UID:0001RS][user-status-resources](by-resource/user-status-resources.md) : reconstructable : 70% : strong : - Confidence: strong for resource names and owner classes.
- [UID:0001RT][webboard-dialog-resources](by-resource/webboard-dialog-resources.md) : reconstructable : 50% : medium : - Confidence: strong for `WEBBOARD.EPD` / `WEBBOARD.PAD` use by WebBoardDialogOld; medium for final resource-file grouping.

## Covered Items To Ignore

- None recorded yet.

## Uncovered Items

- by-resource inventory baseline : uncovered : 0% : open : Full authoritative inventory for by-resource is not yet proven complete; compare this report against Wave3 when OPERATIONAL, simroot_v2, and IDA/MCP evidence.
