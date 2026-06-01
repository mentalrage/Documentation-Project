*** UID:0000SD | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pStaticObjImageLib

## Status

- Confidence: strong for storage address, owner, lifecycle, and consumer set; medium-high for final source-facing name.
- Backing storage: [UID:0001PP][0x0069b448-0x0069b44c.g_pStaticObjImageLib](by-memory/0x0069b448-0x0069b44c.g_pStaticObjImageLib.md), IDA `dword_69B448`.
- Owner file: [UID:0000O7][StaticObjImageLib](by-file/StaticObjImageLib.md).
- Alias decision: `g_pStaticObjImageLib` is the preferred canonical documentation name. `dword_69B448` is the live IDA auto-name; generated names such as `g_pStaticObjectManager` should be treated as aliases unless later source-level evidence proves otherwise.

## Role

`g_pStaticObjImageLib` is the process-wide pointer to the static map-object image library. Map object creation, static-object pane rendering, and photo composition read this pointer before resolving `SOBJ.TBL` object records into layered `TILEC` frame draws.

## IDA Xref Summary

Live IDA MCP on 2026-05-30 reports `0x0069b448` as a 4-byte `.data` item named `dword_69B448` with 13 data xrefs.

| Site | Role |
| --- | --- |
| `0x004dcfa3` / `0x004dcfaa` | [UID:00017H][0x004dcf60-0x004e6aa6.StaticObjImageLib](by-memory/0x004dcf60-0x004e6aa6.StaticObjImageLib.md) writes the singleton. |
| `0x004dd29b` | [UID:00017I][0x004dd1e0-0x004dd2bd.StaticObjImageLibDestructor](by-memory/0x004dd1e0-0x004dd2bd.StaticObjImageLibDestructor.md) clears the singleton. |
| `0x004e5c00` | [UID:000184][0x004e5c00-0x004e5c0b.StaticObjImageLibSingletonClearHelper](by-memory/0x004e5c00-0x004e5c0b.StaticObjImageLibSingletonClearHelper.md) clears the singleton. |
| `0x004e6a5e` | Scalar deleting destructor clears the singleton. |
| `0x004f65e2` | `Application::Shutdown` reads the singleton for teardown. |
| `0x0050f064` / `0x0050f0b0` | Map/object creation code reads the singleton for bounds and setup. |
| `0x00530d30` | Additional map/static-object consumer reads the singleton. |
| `0x00537960` / `0x0053797a` / `0x005379ad` | [UID:0000O6][StaticObjectPane](by-file/StaticObjectPane.md) reads the singleton. |
| `0x0054977d` | [UID:0000MK][PhotoPane](by-file/PhotoPane.md) reads the singleton during map-photo composition. |

## Ownership

`g_pStaticObjImageLib` is source-owned by `StaticObjImageLib`, not by `MapPane`, `StaticObjectPane`, or `PhotoPane`. Those classes are consumers.

## Cross-References

- [UID:0000O7][StaticObjImageLib](by-file/StaticObjImageLib.md)
- [UID:0000E2][StaticObjImageLib](by-class/StaticObjImageLib.md)
- [UID:00017H][0x004dcf60-0x004e6aa6.StaticObjImageLib](by-memory/0x004dcf60-0x004e6aa6.StaticObjImageLib.md)
- [UID:0001PP][0x0069b448-0x0069b44c.g_pStaticObjImageLib](by-memory/0x0069b448-0x0069b44c.g_pStaticObjImageLib.md)
- [UID:0001YX][StaticObjImageLibVtable](by-type/by-vtable/StaticObjImageLibVtable.md)
- [UID:0001W9][StaticObjImageLibLayout](by-type/by-struct/StaticObjImageLibLayout.md)

## Changes

- What existed before: this page had a correct xref table but unevaluated completion/confidence metadata and a generated-tool status line as part of the alias decision.
- What changed to: the page now uses live IDA MCP as the evidence source, includes the full 13-xref set including `0x00530d30`, and scopes generated names as aliases only. Completion/confidence were set to `80/88`.
- Summary and evidence: IDA MCP on 2026-05-30 verified `0x0069b448` / `dword_69B448` as a 4-byte `.data` singleton pointer with constructor assignment/fallback at `0x004dcfa3`/`0x004dcfaa`, destructor/clear helpers at `0x004dd29b`, `0x004e5c00`, and `0x004e6a5e`, shutdown read at `0x004f65e2`, map/static-object consumers at `0x0050f064`, `0x0050f0b0`, `0x00530d30`, `0x00537960`, `0x0053797a`, and `0x005379ad`, and photo composition read at `0x0054977d`.
