*** UID:00009F | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:74 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000LX | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# NewUserMiscDialogPane

## Status

- Confidence: medium
- Likely source file: [UID:0000LX][NewUserMiscDialogPane](by-file/NewUserMiscDialogPane.md), pending owner review under the [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md) umbrella
- Address ranges: exact child [UID:0002Q7][0x004fb630-0x004fccee.NewUserMiscDialogPaneCoreAndPacketHelpers](by-memory/0x004fb630-0x004fccee.NewUserMiscDialogPaneCoreAndPacketHelpers.md) inside aggregate [UID:00019U][0x004fb630-0x004fe782.NewUserMiscShapeAndPasswordDialogs](by-memory/0x004fb630-0x004fe782.NewUserMiscShapeAndPasswordDialogs.md)
- Current recovered file: `source-3/simroot_v2/class_NewUserMiscDialogPane.cpp` (constructor omitted from current emitted source)
- Autogen parent: [UID:0000LX][NewUserMiscDialogPane](by-file/NewUserMiscDialogPane.md). C++ remains blank pending final destructor-boundary and source-split review.

## Class Purpose

`NewUserMiscDialogPane` appears to be a companion customization/settings dialog for the new-user flow. It manages gender, shape, and style controls and queues small packet requests through `CashShopRequest`.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `NewUserMiscDialogPane` | `0x004fb630`, size `0x99f` | Builds `DLGNEW02.EPD`, gender/body/style controls, random initial selection state, and opens the dialog. |
| `~NewUserMiscDialogPane` | `0x004fbfd0` | Wave3 destructor row; IDA does not currently define a function here. |
| `HandleCommand` | `0x004fc010`, size `0x56e` | Handles accept/cancel, gender, shape, and style-control commands. |
| `OnKeyDown` | `0x004fc5f0`, size `0x18c` | Keyboard handling. |
| `OnShowHelp` | `0x004fc780`, size `0x267` | Help/description display for controls. |
| Destructor family | `0x00502524`, `0x0050252f`, `0x005029f0` size `0x71` | Adjustor and scalar deleting destructor logic. |

## Evidence Notes

- IDA confirms `0x004fb630`, `0x004fc010`, `0x004fc5f0`, `0x004fc780`, and the destructor thunks.
- 2026-05-24 IDA MCP recheck: constructor `0x004fb630` writes vtables at `0x0061d424`, `0x0061d484`, and `0x0061d4b4`, and `callers 0x004fb630` reports `0x004fa74e` inside `0x004fa5b0`.
- 2026-05-24 IDA MCP recheck: `0x004fa5b0` is referenced from `0x004fa111` inside wrapper `0x004fa0f0`; that wrapper has a vtable/data xref at `0x0061d35c`.
- IDA does not define a function at `0x004fbfd0`; treat that start as a boundary caveat before source migration.
- 2026-05-24 IDA MCP recheck: `callers 0x004fc010` returns none and `xrefs_to 0x004fc010` reports only data xref `0x0061d46c`.
- 2026-05-24 IDA MCP recheck: `xrefs_to 0x005029f0` reports adjustor-thunk xrefs at `0x0050252a` and `0x00502535`, plus vtable data xref `0x0061d424`.
- The packet path through `CashShopRequest` makes final placement uncertain between create-user UI and a broader customization/account module.
- [UID:0002Q7][0x004fb630-0x004fccee.NewUserMiscDialogPaneCoreAndPacketHelpers](by-memory/0x004fb630-0x004fccee.NewUserMiscDialogPaneCoreAndPacketHelpers.md) resolves most of the previous aggregate uncertainty by splitting the constructor, command/key/help handlers, raw packet senders, reply handler, and local padding from neighboring shape/password dialog code.
- [UID:00029H][0x0069b480-0x0069b490.MainMenuAccountDialogSingletons](by-memory/0x0069b480-0x0069b490.MainMenuAccountDialogSingletons.md) confirms the class-specific singleton slot at `0x0069b488`.

## Reconstruction Notes

- Keep `RECONSTRUCTABLE:TRUE`: this is source-owned login/create-user UI code with constructor, virtual handlers, packet send helpers, and singleton storage.
- Keep the C++ block blank until the destructor-shaped raw island at `0x004fbfd0`, packet helper names, and final source split are resolved at final-source confidence.
- Treat [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md) as the umbrella, not an automatic merge target.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 74 | The class page now points at the exact child memory split, singleton evidence, method map, source parent, rebuild handling, and remaining final-source blockers. |
| Confidence | 80 | Constructor/handler/destructor-family evidence, vtable references, singleton storage, and login/create-user placement are strong enough for class ownership. Confidence remains capped by the raw destructor island and incomplete generated source. |
| Reconstructable | true | The class is project-owned UI code, though no final C++ should be emitted yet. |

## Cross-References

- [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md)
- [UID:0000LX][NewUserMiscDialogPane](by-file/NewUserMiscDialogPane.md)
- [UID:00009G][NewUserShapeSelectControlPane](by-class/NewUserShapeSelectControlPane.md)
- [Wave3 data issues](../wave3_data_issues.md)

## Changes

- Before: completion/confidence metadata were `0/0` despite method-map, constructor/caller, vtable, and packet-path evidence.
- Changed to: `COMPLETION:72` and `CONFIDENCE:68`.
- Evidence: IDA confirms the constructor, command, key, help, and destructor-thunk starts and records caller/vtable xrefs; confidence remains medium because current emitted source omits the constructor, the `0x004fbfd0` boundary is suspect, and final placement between create-user/customization/account code is unresolved.
- 2026-06-02 ownership/path pass:
  - What existed before: the class page still reflected older aggregate uncertainty and had blank reconstructable/autogen metadata.
  - Changed to: `COMPLETION:74`, `CONFIDENCE:80`, marked reconstructable, attached to [UID:0000LX][NewUserMiscDialogPane](by-file/NewUserMiscDialogPane.md), and added exact child/singleton evidence plus score rationale.
  - Summary/evidence: [UID:0002Q7][0x004fb630-0x004fccee.NewUserMiscDialogPaneCoreAndPacketHelpers](by-memory/0x004fb630-0x004fccee.NewUserMiscDialogPaneCoreAndPacketHelpers.md), [UID:00029H][0x0069b480-0x0069b490.MainMenuAccountDialogSingletons](by-memory/0x0069b480-0x0069b490.MainMenuAccountDialogSingletons.md), and file-level [UID:0000LX][NewUserMiscDialogPane](by-file/NewUserMiscDialogPane.md) support the stronger class ownership score.
