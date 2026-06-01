*** UID:0000RD | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pLightObjImageLib

## Status

- Confidence: strong for address and owner, medium for final original symbol spelling.
- Kind: process-wide singleton pointer.
- Backing storage: [UID:0001PR][0x0069b450-0x0069b454.g_pLightObjImageLib](by-memory/0x0069b450-0x0069b454.g_pLightObjImageLib.md), IDA `dword_69B450`.
- Canonical owner: [UID:000076][LightObjImageLib](by-class/LightObjImageLib.md) in [UID:0000KP][LightObjImageLib](by-file/LightObjImageLib.md).
- Current generated aliases: `g_pLightObjImageLib`; unresolved Application shutdown output also uses `g_pLightObjectImageLib`.

## Meaning

`g_pLightObjImageLib` is the global pointer to the light-source image library. Attached-object and effect-facing render paths read it before invoking the virtual light draw modes that center prebuilt light masks over a target point.

Keep this global with `render/LightObjImageLib.cpp`. Consumers should not adopt it just because they draw light overlays.

## Write Evidence

IDA MCP on 2026-05-26 reports these writes to `0x0069b450`:

| Address | Function | Meaning |
| --- | --- | --- |
| `0x004df82b` | `LightObjImageLib::LightObjImageLib` | Stores the constructed `LightObjImageLib*` singleton. |
| `0x004df832` | `LightObjImageLib::LightObjImageLib` | Constructor fallback/guard path clears the singleton. |
| `0x004dfb23` | [UID:00017Q][0x004dfab0-0x004dfb36.LightObjImageLibDestructor](by-memory/0x004dfab0-0x004dfb36.LightObjImageLibDestructor.md) | Clears the singleton during non-deleting cleanup. |
| `0x004e5bb0` | [UID:00017Z][0x004e5bb0-0x004e5bbb.LightObjImageLibSingletonClearHelper](by-memory/0x004e5bb0-0x004e5bbb.LightObjImageLibSingletonClearHelper.md) | Tiny cleanup helper that clears the singleton. |
| `0x004e665d` | `LightObjImageLib::ScalarDeletingDestructor` | Clears the singleton during object destruction. |

The constructor also installs the [UID:0001XY][LightObjImageLibVtable](by-type/by-vtable/LightObjImageLibVtable.md), installs the adjacent `ProtectedArray<LightInfo>` vtable, opens `LIGHT.TBL`, and generates the radial [UID:0001UW][LightInfo](by-type/by-struct/LightInfo.md) frame records.

Current `simroot_v2/class_LightObjImageLib.cpp` assigns `g_pLightObjImageLib = this` in the constructor, declares `LightObjImageLib* g_pLightObjImageLib`, clears it in `ScalarDeletingDestructor`, opens `LIGHT.TBL`, and emits the two virtual draw modes.

Current `class_LightObjImageLib.meta_wave3` lists `g_pLightObjImageLib` in active `global_data` with type `LightObjImageLib*` and owner `class_LightObjImageLib.cpp`, but its global-data memory range remains unresolved in metadata. The exact `0x0069b450-0x0069b454` storage therefore remains IDA-backed documentation evidence, not a current Wave3 source-map binding.

Current `class_Application.cpp` uses generated alias `g_pLightObjectImageLib` in shutdown and has an unresolved `global-data:g_pLightObjectImageLib` entry. Treat that as a generated alias/caller-view of this singleton only when the address is confirmed by the existing IDA-backed shutdown read; do not create a separate global.

## Consumer Evidence

Representative readers include:

- `0x004f6642` in `Application::Shutdown`, which checks the singleton during image-library teardown.
- `0x005373fa`, `0x0053754b`, and `0x00537618` in attached-object related draw paths.
- `0x00538162`, `0x005381f6`, `0x0053834d`, `0x005383e0`, `0x00538488`, and `0x00538527` in neighboring light/attached-object render variants.
- `0x0053c81d` and `0x0053c9c3` in later render helper paths.

## Ownership Decision

`g_pLightObjImageLib` is source-owned by `LightObjImageLib`, not by `Application`, attached-object panes, or any caller that only consumes light masks.

When rewriting generated source, preserve the singleton as the canonical global for `0x0069b450` and avoid confusing it with nearby image-library globals at `0x0069b448` and `0x0069b44c`.

## Cross-References

- [UID:0000KP][LightObjImageLib](by-file/LightObjImageLib.md)
- [UID:000076][LightObjImageLib](by-class/LightObjImageLib.md)
- [UID:00017P][0x004df7e0-0x004e669c.LightObjImageLib](by-memory/0x004df7e0-0x004e669c.LightObjImageLib.md)
- [UID:0001PR][0x0069b450-0x0069b454.g_pLightObjImageLib](by-memory/0x0069b450-0x0069b454.g_pLightObjImageLib.md)
- [UID:0001XY][LightObjImageLibVtable](by-type/by-vtable/LightObjImageLibVtable.md)
- [UID:0001UX][LightObjImageLibLayout](by-type/by-struct/LightObjImageLibLayout.md)
- [UID:0001UW][LightInfo](by-type/by-struct/LightInfo.md)

## Changes

### 2026-05-30 completion/confidence evidence pass

- What existed before: the page had `0` completion/confidence values and listed only `g_pLightObjImageLib` as the current generated alias.
- What changed: completion/confidence were raised to `82/82`, and the evidence now records current generated constructor/destructor/declaration behavior, active Wave3 global-data metadata, the unresolved metadata memory-range caveat, and the unresolved Application alias `g_pLightObjectImageLib`.
- Summary and evidence: existing IDA-backed docs establish the singleton storage, write sites, and representative readers. Current generated code confirms the constructor/destructor lifecycle and `LIGHT.TBL` owner, but active metadata still lacks a resolved global-data memory range and omits ordinary destructor/vtable inventory details, so confidence and completion remain below the stronger image-library singleton pages.
