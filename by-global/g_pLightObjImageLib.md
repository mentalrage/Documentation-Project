*** UID:0000RD | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000KP | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pLightObjImageLib

## Status

- Confidence: very strong for address, lifetime, and owner; medium-high for final original symbol spelling because generated shutdown output still shows the `g_pLightObjectImageLib` alias.
- Kind: process-wide singleton pointer.
- Backing storage: [UID:0001PR][0x0069b450-0x0069b454.g_pLightObjImageLib](by-memory/0x0069b450-0x0069b454.g_pLightObjImageLib.md), IDA `dword_69B450`.
- Canonical owner: [UID:000076][LightObjImageLib](by-class/LightObjImageLib.md) in [UID:0000KP][LightObjImageLib](by-file/LightObjImageLib.md).
- Autogen parent: [UID:0000KP][LightObjImageLib](by-file/LightObjImageLib.md), because the file page clears the parent gate and records this singleton as the primary runtime instance for the light image library.
- Current generated aliases: `g_pLightObjImageLib`; unresolved Application shutdown output also uses `g_pLightObjectImageLib`.
- Reconstruction status: attach as source-declared `LightObjImageLib*` singleton storage in the light image-library source unit; leave final C++ blank until the class source rewrite settles the original declaration spelling and helper names.

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

2026-06-10 live MCP recheck reconfirmed the active singleton evidence after the newer parent/vtable work:

- `lookup_funcs` reports modeled functions for `0x004df7e0` size `0x2c6`, `0x004dfb40` size `0x70`, `0x004dfbb0` size `0xaa`, `0x004dfc60` size `0xaa`, `0x004e5bb0` size `0xb`, `0x004e65e0` size `0xbd`, and `Application::Startup` at `0x004f5fb0` size `0x4e0`; `0x004dfab0` remains intentionally raw/not an IDA function.
- `xrefs_to 0x0069b450` reports 19 data references: constructor store/clear at `0x004df82b`/`0x004df832`, raw ordinary-destructor clear at `0x004dfb23`, singleton-clear helper at `0x004e5bb0`, scalar deleting destructor clear at `0x004e665d`, shutdown read at `0x004f6642`, attached-object/light render readers from `0x005373fa` through `0x0053c9f3`, and the two raw non-function references at `0x0053c6bc` and `0x0053c9f3`.
- `xrefs_to 0x0061b754` reports the constructor, raw ordinary destructor, and scalar deleting destructor vtable writes/reads at `0x004df83c`, `0x004dfab9`, and `0x004e65ec`, matching the exact [UID:00031S][0x0061b750-0x0061b768.LightObjImageLibVtableData](by-memory/0x0061b750-0x0061b768.LightObjImageLibVtableData.md) child.
- `callers` reports the constructor is called only from startup at `0x004f6139`, the bounds helper only from `0x0053c82b`, and the two draw modes remain virtual-dispatch targets with no direct callers.

## Consumer Evidence

Representative readers include:

- `0x004f6642` in `Application::Shutdown`, which checks the singleton during image-library teardown.
- `0x005373fa`, `0x0053754b`, and `0x00537618` in attached-object related draw paths.
- `0x00538162`, `0x005381f6`, `0x0053834d`, `0x005383e0`, `0x00538488`, and `0x00538527` in neighboring light/attached-object render variants.
- `0x0053c81d` and `0x0053c9c3` in later render helper paths.

## Ownership Decision

`g_pLightObjImageLib` is source-owned by `LightObjImageLib`, not by `Application`, attached-object panes, or any caller that only consumes light masks.

When rewriting generated source, preserve the singleton as the canonical global for `0x0069b450` and avoid confusing it with nearby image-library globals at `0x0069b448` and `0x0069b44c`.

## Parent Attachment Guidance

Use [UID:0000KP][LightObjImageLib](by-file/LightObjImageLib.md) as the autogen parent for this singleton. That file is now `87/85` and documents the `LIGHT.TBL` constructor path, ordinary and scalar deleting cleanup paths, light bounds/draw helpers, exact vtable-data child, `LightObjImageLibLayout`, `LightInfo`, and exact singleton storage. The class parent [UID:000076][LightObjImageLib](by-class/LightObjImageLib.md) is now `86/86`, so the strict `85/85` source-owner gate is satisfied. This attachment is an ownership link only; it does not close the unresolved Wave3 global-data memory-range omission or the Application-side alias spelling.

## Cross-References

- [UID:0000KP][LightObjImageLib](by-file/LightObjImageLib.md)
- [UID:000076][LightObjImageLib](by-class/LightObjImageLib.md)
- [UID:00017P][0x004df7e0-0x004e669d.LightObjImageLib](by-memory/0x004df7e0-0x004e669d.LightObjImageLib.md)
- [UID:0001PR][0x0069b450-0x0069b454.g_pLightObjImageLib](by-memory/0x0069b450-0x0069b454.g_pLightObjImageLib.md)
- [UID:0001XY][LightObjImageLibVtable](by-type/by-vtable/LightObjImageLibVtable.md)
- [UID:0001UX][LightObjImageLibLayout](by-type/by-struct/LightObjImageLibLayout.md)
- [UID:0001UW][LightInfo](by-type/by-struct/LightInfo.md)

## Changes

### 2026-05-30 completion/confidence evidence pass

- What existed before: the page had `0` completion/confidence values and listed only `g_pLightObjImageLib` as the current generated alias.
- What changed: completion/confidence were raised to `82/82`, and the evidence now records current generated constructor/destructor/declaration behavior, active Wave3 global-data metadata, the unresolved metadata memory-range caveat, and the unresolved Application alias `g_pLightObjectImageLib`.
- Summary and evidence: existing IDA-backed docs establish the singleton storage, write sites, and representative readers. Current generated code confirms the constructor/destructor lifecycle and `LIGHT.TBL` owner, but active metadata still lacks a resolved global-data memory range and omits ordinary destructor/vtable inventory details, so confidence and completion remain below the stronger image-library singleton pages.

### 2026-06-07 A007 parent attachment

- What existed before: `AUTOGEN_PARENT_UID` was blank even though [UID:0000KP][LightObjImageLib](by-file/LightObjImageLib.md) is already `86/80` and names this singleton as its primary global instance.
- What changed: set `AUTOGEN_PARENT_UID:0000KP`, added explicit autogen-parent/reconstruction status bullets, and recorded parent attachment guidance.
- Summary and evidence: [UID:0000KP][LightObjImageLib](by-file/LightObjImageLib.md), [UID:000076][LightObjImageLib](by-class/LightObjImageLib.md), [UID:0001PR][0x0069b450-0x0069b454.g_pLightObjImageLib](by-memory/0x0069b450-0x0069b454.g_pLightObjImageLib.md), [UID:0001XY][LightObjImageLibVtable](by-type/by-vtable/LightObjImageLibVtable.md), and [UID:0001UX][LightObjImageLibLayout](by-type/by-struct/LightObjImageLibLayout.md) already establish the source-root chain. No score or final C++ change was made because final symbol spelling and generated metadata gaps remain open.

### 2026-06-10 A001 live singleton recheck

- What existed before: the page still scored `82/82` and described the parent attachment before the exact vtable-data child and parent gate refresh.
- What changed: raised the page to `86/88`, updated the reconstruction status and parent-attachment guidance, and added the current MCP recheck covering function boundaries, singleton xrefs, vtable xrefs, and caller evidence.
- Summary and evidence: live MCP reconfirmed 19 references to `0x0069b450`, startup-only construction, raw ordinary destructor storage clear, helper/deleting-destructor clears, shutdown/read consumers, and vtable writes through `0x0061b754`. The direct file parent is now `87/85`, the class parent is `86/86`, and exact vtable data is documented by [UID:00031S][0x0061b750-0x0061b768.LightObjImageLibVtableData](by-memory/0x0061b750-0x0061b768.LightObjImageLibVtableData.md). Scores stay below final-audit because the original spelling and Wave3 global-data range omission are still caveats.
