*** UID:0000RW | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000MB | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000MB | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:20 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
PaletteLib *g_pPaletteLib = 0;

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
extern PaletteLib *g_pPaletteLib;
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_pPaletteLib

## Status

- Confidence: very strong for exact storage, type, one-definition ownership, source route, complete lifetime, and the exhaustive consumer set.
- Type: `PaletteLib*`.
- IDA address: `0x0067a7e0` (`dword_67A7E0`).
- Source file: focused [UID:0000MB][PaletteLib](by-file/PaletteLib.md) at `NexusTK/render/PaletteLib.cpp`; broad [UID:0000MA][Palette](by-file/Palette.md) is umbrella support, not a second definition owner.

## Role

`g_pPaletteLib` is the process-wide palette manager singleton. Rendering, image-library, map, UI, and text paths use it to resolve named palettes, current/base palettes, slot palettes, super palettes, and runtime palette-filter state.

## Evidence Notes

- IDA MCP recheck on 2026-05-25 identifies the storage as `0x0067a7e0` and reports 83 data references.
- `PaletteLib::PaletteLib` stores the constructed object in this global around `0x00543743-0x0054374a`.
- `PaletteLib::~PaletteLib` clears the global at `0x00543cfe`.
- The constructor-unwind cleanup stub at `0x005443a0` also clears this global and is referenced only from constructor unwind metadata at `0x00605944`.
- Map render code loads this global before calling [UID:0001E9][0x00543f60-0x005440f0.PaletteLibPaletteFilterHelpers](by-memory/0x00543f60-0x005440f0.PaletteLibPaletteFilterHelpers.md), confirming those helpers are `PaletteLib` methods. B014's 2026-06-26 source-quality pass names the current uses: `sub_5094B0` calls `UpdatePaletteFilterTables` at `0x00509595` and brackets rendering with `SetPaletteFilterActive` at `0x005096e7` / `0x0050a277`, `sub_50A8B0` calls the updater at `0x0050a918`, and `sub_50D8E0` toggles the filtered-bank selector at `0x0050d94f` / `0x0050d99f`.

## 2026-05-30 Review Notes

- IDA MCP `py_eval` on 2026-05-30 confirms `0x0067a7e0` is `dword_67A7E0`, size `4`, in `.data`, with 83 data xrefs.
- Live IDA xrefs include early application/render consumers at `0x004562c0`, `0x00464bef`, `0x00467f8f`, UI/image paths around `0x0048373f`, `0x004966e0`, `0x00499365`, text/draw helper neighborhoods from `0x004b9989` through `0x004c4417`, and late render/UI consumers including `0x00570fff`, `0x00588dad`, `0x00599346`, `0x005a06b1`, and the `0x005c2ac0` function family.
- Existing IDA-backed notes identify the constructor write, destructor clear, constructor-unwind clear helper, and palette-filter helper ownership. B001's 2026-07-20 pass then semantically classified all 83 xrefs without truncation.
- Live IDA decompilation on 2026-06-05 confirms `0x00543700` stores `this` into `dword_67A7E0` and installs the `PaletteLib` vtable, while `0x00543af0` and `0x005443a0` clear the singleton during cleanup/destruction.
- The high-fanout consumer set is now exhaustively grouped and named below.

## Assignment Decision

`AUTOGEN_PARENT_UID` remains [UID:0000MB][PaletteLib](by-file/PaletteLib.md). This global is `92/94`, the direct focused file is `91/92`, and exact storage child [UID:00028T][0x0067a7e0-0x0067a7e4.g_pPaletteLib](by-memory/0x0067a7e0-0x0067a7e4.g_pPaletteLib.md) is `92/94`. The parent gate, one-definition route, zero storage, complete lifetime, and exhaustive consumer classification are closed.

## Score Rationale

- Completion `92`: exact storage/type, singleton role, one-definition contract, complete constructor/destructor/EH/scalar lifecycle, exhaustive 83-reference inventory, full object relationship, and focused source/header placement are documented.
- Confidence `94`: direct bytes, all xrefs, RTTI PMD/EBO, allocation/field arithmetic, constructor/destructor order, and the exact physical child agree. The remaining sub-95 gap is limited to unavailable original private spellings and physical header-name symbols.

## Ownership Decision

Define the pointer exactly once in focused `NexusTK/render/PaletteLib.cpp` and declare it `extern` from `NexusTK/render/PaletteLib.h`. Do not duplicate it from the physical storage child, broad Palette umbrella, DAT/archive code, or a consumer family; palette files are DAT-backed resources, but this singleton owns render palette policy.

## B001 UID00028T One-Definition And Lifetime Closure - 2026-07-20

### Definition, Header, And Physical Storage

- The sole source definition is the managed `PaletteLib *g_pPaletteLib = 0;` above. [UID:0000A1][PaletteLib](by-class/PaletteLib.md) carries the matching `extern` declaration; [UID:00028T][0x0067a7e0-0x0067a7e4.g_pPaletteLib](by-memory/0x0067a7e0-0x0067a7e4.g_pPaletteLib.md) carries only a no-duplicate physical marker for exact zero storage `[0x0067a7e0,0x0067a7e4)`.
- The physical bytes are four zeros with SHA256 `DF3F619804A92FDB4057192DC43DD748EA778ADC52BC498CE80524C014B81119`; adjacent named globals end at `0x0067a7e0` and begin at `0x0067a7e4`, so no split, padding, merge, alias, or second definition is required.
- Focused declaration/definition order is class 10, global 20, screen-state methods 25, filter helpers 30, and physical marker 40. Broad Palette remains a dependency umbrella and does not emit this definition.

### Source And Compiler Lifetime

- Startup allocates exactly `0x25c8` bytes at `0x004f619e`, then the sole constructor caller at `0x004f61bb` enters `PaletteLib::PaletteLib` (`0x00543700-0x00543ae2`, SHA256 `4D0167964629D7508741AC76C84F93F784EF1FAD6CD0419768959F0EB61D53EF`).
- RTTI proves primary `LObject` and empty `Singleton<PaletteLib>` bases; Singleton PMD is `mdisp=4,pdisp=-1,vdisp=0`. Constructor publication at `0x00543743` and adjusted-null fallback clear at `0x0054374a` are compiler-lowered empty-base operations.
- The ordinary destructor (`0x00543af0-0x00543d1f`, SHA256 `78644D04D1EE355921700539862369179B3D9AD1C9FE8BC3559D2102777E73B9`) clears the Singleton at `0x00543cfe` after source-authored list cleanup and before `LObject` teardown. EH-only `0x005443a0-0x005443ab` performs the same compiler clear during constructor unwind. Application cleanup reads the global at `0x00464bef` and invokes vtable slot zero with deleting flag 1.
- These publication/clear instructions, scalar wrapper, EH clear, vtable/RTTI, embedded-object teardown, vptr stores, and vector iterators are compiler lowering. No guarded manual-global logic or duplicate source body is emitted.

### Exhaustive Consumer Classification

Fresh MCP returned 83 direct xrefs with `more:false`: four writes/clears and 79 reads. Exact grouped addresses are: MiniMap `0x004562c0`; lifetime `0x00464bef`, `0x00543743`, `0x0054374a`, `0x00543cfe`, `0x005443a0`; Balloon `0x00467f8f`; Chatting `0x0048373f`; Button `0x004966e0`; EPFImageControlPane `0x00499365`; GrafPort/direct Surface `0x004b9989`, `0x004b99c9`, `0x004ba5be`, `0x004ba796`, `0x004bb282`; software callbacks `0x004bb912`, `0x004bba02`, `0x004bc0d4`, `0x004bd4e4`, `0x004be1d8`, `0x004be70a`, `0x004c07b2`, `0x004c08a2`, `0x004c0fd0`, `0x004c1334`, `0x004c1885`, `0x004c1ed6`, `0x004c3254`, `0x004c3f98`, `0x004c4417`; MapTile `0x004d1a66`, `0x004d1b13`; Human `0x004d56ad`, `0x004d57da`, `0x004d618b`, `0x004d6552`; Monster `0x004db4f0`; image-family gap `0x004dcbf1`; StaticObject `0x004dd533`; EffectObject `0x004de20d`; ItemObject `0x004dee8f`, `0x004df045`, `0x004df20f`, `0x004df331`, `0x004df69c`, `0x004df737`; NewHuman `0x004e2331`, `0x004e2c1d`, `0x004e2f41`, `0x004e4e29`; InterfaceEffect `0x004e9811`; ScrolledPicture `0x004ff876`; appearance selectors `0x0050145b`, `0x0050193b`, `0x00502018`, `0x005022d8`; map/filter `0x0050958a`, `0x005096df`, `0x0050a26f`, `0x0050a90d`, `0x0050d947`, `0x0050d997`; TextMenu `0x00518f31`; Power `0x0054b3d4`; Screen `0x00556dbd`, `0x005593b1`; ScreenEffecter `0x0055b70f`; SelfLook `0x00567596`; Group panes `0x0056c6dd`, `0x0056c98d`, `0x0056ceb3`; Collection panes `0x0056ee1d`, `0x0056fded`; SelfLookPane2 `0x00570fff`; SystemMessage `0x00588dad`; TransferServer `0x00599346`; UserLook `0x005a06b1`, `0x005a06da`, `0x005a1438`; WorldMap `0x005c2ec4`, `0x005c2f97`, `0x005c3192`, `0x005c3265`.

All consumer families read the singleton for palette operations. None writes a competing definition or demonstrates DAT, resource-provider, broad Palette, or consumer ownership.

### Complete Object Relationship And Historical Corrections

- Allocation and exact member use close [UID:0000A1][PaletteLib](by-class/PaletteLib.md) at `0x25c8`: `LObject` at `+0x000`; empty Singleton/screen mode at `+0x004`; loaded list at `+0x008`; embedded palettes at `+0x00c/+0x238/+0x464`; source/runtime banks at `+0x690/+0x6f4`; selector at `+0x758`; natural alignment to float at `+0x75c`; and seven-palette arrays at `+0x760/+0x1694`.
- Historical notes that treated the constructor/destructor stores as manually authored global logic, left all 83 consumers unclassified, or kept broad Palette/DAT/consumer ownership open are superseded by direct RTTI, bytes, xrefs, and the focused one-definition route.

## Cross-References

- [UID:0000MA][Palette](by-file/Palette.md)
- [UID:0000MB][PaletteLib](by-file/PaletteLib.md)
- [UID:0000A1][PaletteLib](by-class/PaletteLib.md)
- [UID:0001E6][0x005431c0-0x005443ab.PaletteLibMethodCluster](by-memory/0x005431c0-0x005443ab.PaletteLibMethodCluster.md)
- [UID:0001E9][0x00543f60-0x005440f0.PaletteLibPaletteFilterHelpers](by-memory/0x00543f60-0x005440f0.PaletteLibPaletteFilterHelpers.md)

## Changes

- 2026-08-16 B003 UID0003F8 header-closure callback: added one `extern PaletteLib *g_pPaletteLib;` at H position 20 immediately after the complete UID0000A1 class declaration. The existing `PaletteLib *g_pPaletteLib = 0;` plus `[[CHILDREN]]` CPP remains the sole definition and storage route. No duplicate extern, class declaration, definition, layout change, or score change was introduced; metadata stays `92/94`.

- 2026-07-20 B001: Applied accepted UID00028T callback: raised to `92/94`, set position 20, installed the sole zero-initialized definition, and incorporated exact storage/header/one-definition, full Singleton lifetime, exhaustive 83-xref classification, complete object relationship, negative ownership evidence, and historical corrections.
- Before: completion/confidence were ungraded at `0/0`, and Status contained weak provenance wording.
- Changed to: completion `80`, confidence `88`; weak provenance wording was removed from Status.
- Summary/evidence: live IDA MCP on 2026-05-30 verified exact storage, size, segment, 83 xrefs, and broad consumer fan-out; existing IDA-backed notes identify lifecycle writes/clears and PaletteLib filter-helper ownership. Completion remains below full until all consumer clusters are semantically classified.

- 2026-06-05 autogen classification:
  - What existed before: autogen metadata was blank, so the singleton was reported as unclassified.
  - Changed to: `RECONSTRUCTABLE:TRUE` with `AUTOGEN_PARENT_UID:0000MB`; `RECONSTRUCTION_CPP CODE` remains empty.
  - Summary/evidence: live IDA MCP `xrefs_to 0x0067a7e0` and decompilation of `0x00543700`, `0x00543af0`, and `0x005443a0` prove NexusTK-owned `PaletteLib` singleton storage owned by [UID:0000MB][PaletteLib](by-file/PaletteLib.md). No final C++ body was added because the page is below the 95/95 reconstruction gate.
- 2026-06-10 A001 strict gate repair:
  - Changed completion from `80` to `86`.
  - Summary/evidence: the direct PaletteLib file parent now scores `88/85`, and the exact storage child [UID:00028T][0x0067a7e0-0x0067a7e4.g_pPaletteLib](by-memory/0x0067a7e0-0x0067a7e4.g_pPaletteLib.md) scores `86/90`. The global page already carried live IDA evidence for exact `0x0067a7e0` storage, 83 xrefs, constructor publish/guard clear, destructor and constructor-unwind clears, and PaletteLib filter-helper ownership; the new rationale documents why the child/direct-parent gate clears while keeping C++ blank below the 95/95 source-code threshold.
- 2026-06-26 B014 palette-filter source-quality sync:
  - Score unchanged.
  - Evidence: [UID:0001E9][0x00543f60-0x005440f0.PaletteLibPaletteFilterHelpers](by-memory/0x00543f60-0x005440f0.PaletteLibPaletteFilterHelpers.md) now records the current MapPane render callsites that load this singleton before `SetPaletteFilterActive` / `UpdatePaletteFilterTables`, preserving `g_pPaletteLib` as the singleton receiver rather than a separate helper owner.
