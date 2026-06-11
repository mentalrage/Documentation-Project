*** UID:00006Z | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000KJ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# KeySpeedMgr

## Status

- Confidence: strong.
- Likely source file: [UID:0000KJ][KeySpeedMgr](by-file/KeySpeedMgr.md)
- Main address range: [UID:00018O][0x004efea0-0x004f0008.KeySpeedMgr](by-memory/0x004efea0-0x004f0008.KeySpeedMgr.md)
- Type anchors: [UID:0001UV][KeySpeedMgrLayout](by-type/by-struct/KeySpeedMgrLayout.md), [UID:0001XX][KeySpeedMgrVtable](by-type/by-vtable/KeySpeedMgrVtable.md)
- Generated parent: attached to [UID:0000KJ][KeySpeedMgr](by-file/KeySpeedMgr.md); both pages clear the 80/80 parent gate and the file page owns the proposed `NexusTK/input/` source root.

## Class Purpose

`KeySpeedMgr` is a tiny singleton that stores and restores Windows keyboard repeat settings. It reads keyboard delay/speed through `SystemParametersInfoW`, allows the client to force fast repeat settings, and restores saved values during teardown or deactivation paths.

## Method Notes

| Method/helper | Address | Role |
| --- | --- | --- |
| [UID:0002IP][0x004efea0-0x004efedd.KeySpeedMgrConstructor](by-memory/0x004efea0-0x004efedd.KeySpeedMgrConstructor.md) | `0x004efea0-0x004efedd` | Constructs `LObject` base, stores singleton, initializes delay/speed to `0xffffffff`, installs vtable. |
| [UID:0002IQ][0x004efee0-0x004efef5.KeySpeedMgrDestructor](by-memory/0x004efee0-0x004efef5.KeySpeedMgrDestructor.md) | `0x004efee0-0x004efef5` | Clears singleton and destroys `LObject` base. |
| [UID:0002IR][0x004eff00-0x004eff25.KeySpeedMgrLoadSystemKeyboardSettings](by-memory/0x004eff00-0x004eff25.KeySpeedMgrLoadSystemKeyboardSettings.md) | `0x004eff00-0x004eff25` | Reads `SPI_GETKEYBOARDDELAY` and `SPI_GETKEYBOARDSPEED`. |
| [UID:00018P][0x004eff30-0x004eff5d.KeySpeedMgrRestoreSystemKeyboardSettings](by-memory/0x004eff30-0x004eff5d.KeySpeedMgrRestoreSystemKeyboardSettings.md) | `0x004eff30-0x004eff5d` | Restores delay if `0..3` and speed if `0..31` using `SPIF_UPDATEINIFILE`. |
| [UID:0002IS][0x004eff60-0x004eff91.KeySpeedMgrApplyKeyboardRepeatSettingsRaw](by-memory/0x004eff60-0x004eff91.KeySpeedMgrApplyKeyboardRepeatSettingsRaw.md) | `0x004eff60-0x004eff91` | Raw unreferenced helper that applies caller-supplied delay/speed values after range checks. |
| [UID:00018Q][0x004effa0-0x004effbd.ApplyFastKeyboardRepeatSettings](by-memory/0x004effa0-0x004effbd.ApplyFastKeyboardRepeatSettings.md) | `0x004effa0-0x004effbd` | Sets delay `0` and speed `31`. |
| [UID:0002IT][0x004effc0-0x004f0008.KeySpeedMgrScalarDeletingDestructor](by-memory/0x004effc0-0x004f0008.KeySpeedMgrScalarDeletingDestructor.md) | `0x004effc0-0x004f0008` | Clears singleton, destroys base, optionally frees memory. |

## Data Notes

- [UID:0000RB][g_pKeySpeedMgr](by-global/g_pKeySpeedMgr.md) is at [UID:0001P7][0x0067ab48-0x0067ab4c.g_pKeySpeedMgr](by-memory/0x0067ab48-0x0067ab4c.g_pKeySpeedMgr.md).
- Stored fields at offsets `0x4` and `0x8` are keyboard delay and keyboard speed.
- IDA confirms the object allocation size is `0x0c`: vptr at `+0x00`, saved delay at `+0x04`, and saved speed at `+0x08`.
- IDA confirms the RTTI-backed primary vtable at `0x0061c9c8`.
- 2026-06-06 live IDA refresh reconfirms all exact method/helper boundaries, ten `g_pKeySpeedMgr` data xrefs, and the `0x0061c9c8` vtable stores from constructor, ordinary destructor, and scalar deleting destructor.
- The exact by-memory method pages are the authority for migration; do not rely on generated-source omissions or historical metadata grades for the final source shape.

## Cross-References

- [UID:0000KJ][KeySpeedMgr](by-file/KeySpeedMgr.md)
- [UID:00018O][0x004efea0-0x004f0008.KeySpeedMgr](by-memory/0x004efea0-0x004f0008.KeySpeedMgr.md)
- [UID:0001UV][KeySpeedMgrLayout](by-type/by-struct/KeySpeedMgrLayout.md)
- [UID:0001XX][KeySpeedMgrVtable](by-type/by-vtable/KeySpeedMgrVtable.md)
- [UID:00018P][0x004eff30-0x004eff5d.KeySpeedMgrRestoreSystemKeyboardSettings](by-memory/0x004eff30-0x004eff5d.KeySpeedMgrRestoreSystemKeyboardSettings.md)
- [UID:0002IS][0x004eff60-0x004eff91.KeySpeedMgrApplyKeyboardRepeatSettingsRaw](by-memory/0x004eff60-0x004eff91.KeySpeedMgrApplyKeyboardRepeatSettingsRaw.md)
- [UID:00018Q][0x004effa0-0x004effbd.ApplyFastKeyboardRepeatSettings](by-memory/0x004effa0-0x004effbd.ApplyFastKeyboardRepeatSettings.md)
- [UID:0000RB][g_pKeySpeedMgr](by-global/g_pKeySpeedMgr.md)
- [UID:0001P7][0x0067ab48-0x0067ab4c.g_pKeySpeedMgr](by-memory/0x0067ab48-0x0067ab4c.g_pKeySpeedMgr.md)
- [UID:0000HG][Application](by-file/Application.md)
- [UID:0001QD][client_input_and_text_entry](by-meta/client_input_and_text_entry.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `82/86`. Summary: the class has highly detailed singleton purpose, layout, method, helper, global, vtable, and migration caveat documentation, but not a final source-level rewrite. Evidence: IDA-confirmed `SystemParametersInfoW` helper behavior, object size, vtable, singleton global, and linked by-memory pages.

### 2026-05-31 - Split method inventory and raw setter helper

- What existed before: the method inventory listed several ranges as bare names and did not include the raw `0x004eff60-0x004eff91` setter/helper.
- What changed: constructor, destructor, load, raw setter, and scalar deleting destructor entries now point to exact by-memory UID references; class scores were raised to `86/88` and marked reconstructable.
- Summary/evidence: IDA MCP reports exact function boundaries for `0x004efea0`, `0x004efee0`, `0x004eff00`, and `0x004effc0`, plus raw non-padding setter bytes at `0x004eff60-0x004eff91` and confirmed padding around each child range.

### 2026-06-06 - Attached class to source root

- What existed before: the class was reconstructable but had a blank autogen parent, leaving class-owned children with no generated-source root chain.
- What changed: `AUTOGEN_PARENT_UID` now points to [UID:0000KJ][KeySpeedMgr](by-file/KeySpeedMgr.md), and generated-source provenance caveats were removed from the class status notes.
- Summary/evidence: the by-file page is scored `90/88`, this class is scored `86/88`, and live IDA reconfirms the class method cluster, singleton slot, layout, and vtable evidence that place the class in `NexusTK/input/KeySpeedMgr.cpp`.
