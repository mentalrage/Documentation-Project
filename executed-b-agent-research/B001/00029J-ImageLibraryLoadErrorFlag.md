** TARGET-REPORT-UID:00029J **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# [UID:00029J] ImageLibraryLoadErrorFlag Ownership Research

## Final Recommendation

Assign [UID:00029J][0x0069b420-0x0069b424.ImageLibraryLoadErrorFlag](../../../../../by-memory/0x0069b420-0x0069b424.ImageLibraryLoadErrorFlag.md) to existing source parent [UID:0000K2][ImageLib](../../../../../by-file/ImageLib.md), projected as `NexusTK/render/ImageLib.cpp`, as shared render image-library load-error / render-suspend state.

Recommended target-page metadata change:

```text
COMPLETION:88
CONFIDENCE:92
AUTOGEN_PARENT_UID:0000K2
```

Do not split the range. The page is already an exact 4-byte source-level slot: `0x0069b420` is the referenced byte, and `0x0069b421-0x0069b423` have zero direct refs and are best kept as the unused initialized tail of the same source declaration. Do not reclassify it as ignored or non-reconstructable.

The source-owner confidence is `86/100`, while storage and behavior confidence remain `92/100`. The direct declaration owner is not proven by debug symbols, but `ImageLib.cpp` is the best executable assignment because the byte is common state shared by several image-library modules. HumanImageLib and EffectObjImageLib are writers, and MapTile/Monster/Static/Item/raw render paths are consumers; none is a better declaration owner than the existing common image-library source page. A new one-global source file such as `ImageLibraryLoadState.cpp` is weaker because no source-tree, static-lifetime, or adjacent data evidence supports a separate translation unit.

Broader source-file contents under this recommendation:

- Keep `ImageLib.cpp` as the common image-library support file behind `g_pEPFLib`, resource/layout cache state, and shared image-library process state.
- Add this flag as a shared module/global declaration, with per-asset image libraries consuming it through common image-library support/header visibility.
- Do not move per-family loaders or renderers into `ImageLib.cpp`; `HumanImageLib`, `EffectObjImageLib`, `MapTileImageLib`, `MonsterImageLib`, `StaticObjImageLib`, `ItemObjImageLib`, and Riding/Light-specific modules keep their exact method ownership.
- Do not move `ImageLibVectorSupportHelpers` out of [UID:0000P3][VectorHelpers](../../../../../by-file/VectorHelpers.md); those helpers write the flag as consumers of the shared state, not as the declaration owner.

No by-* documentation or coverage file was edited by this B001 pass. The supervisor should apply the exact `by-memory/-coverage-report.md` row below and update the target page routing.

## Exact by-memory/-coverage-report.md Replacement Row

Replace only the current `00029J` row between the existing `0002XU` and `00029K` rows. Keep neighboring rows unchanged.

```markdown
    - [UID:00029J][0x0069b420-0x0069b424.ImageLibraryLoadErrorFlag](by-memory/0x0069b420-0x0069b424.ImageLibraryLoadErrorFlag.md) 0x0069b420-0x0069b424 | global flag storage | ImageLibraryLoadErrorFlag : reconstructable : 88% : strong : B001-052 assigns this shared image-library load-error/render-suspend byte to [UID:0000K2][ImageLib](by-file/ImageLib.md) as common render image-library state. Live IDA confirms all-`0xff` storage, 132 refs to the first byte, zero refs to trailing bytes, 70 read and 62 write operand refs, OR-style failure-latch writes from HumanImageLib table loading, EffectObjImageLib table loading, and Human-called ImageLibVectorSupportHelpers, read-only render guards across MapTile, human/raw, Monster, riding/raw, StaticObj, Effect, and Item image paths, no static ctor/dtor or pointer-table refs, and clean Hour/Icons/fallback-record boundaries. Human/Effect/Monster/VectorHelpers are weaker direct parents because they are writers, consumers, helper code, or adjacent storage owners rather than the common declaration owner.
```

## Supporting Research

### Target

- Target UID: `00029J`
- Target path: `by-memory/0x0069b420-0x0069b424.ImageLibraryLoadErrorFlag.md`
- Current state before this recommendation: `RECONSTRUCTABLE:TRUE`, `87/92`, parent blank.
- Supervisor status: `reviewed-85-but-ownership-unknown-under-review`.
- IDA target: `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, image base `0x00400000`, MD5 `4247e04e20b65d6414c7238aa8ff5515`.

### IDA MCP Facts

Live IDA MCP on 2026-06-12 reports:

| Fact | Value |
| --- | --- |
| Target name | `byte_69B420` |
| Bytes | `ff ff ff ff` |
| Dword value | `0xffffffff` |
| Direct refs to `0x0069b420` | `132` |
| Direct refs to `0x0069b421-0x0069b423` | `0`, `0`, `0` |
| Direct ref groups | `11` IDA function groups; `12` semantic rows below because the two no-function raw bodies are separated |
| Raw little-endian address hits | `132`, all corresponding to direct `.text` operand refs |
| Source/debug metadata scan | no `RSDS`, `NB10`, `.pdb`, `.cpp`, `.cxx`, or candidate source filename strings |

Grouped direct refs:

| Range/start | Ref split | Documentation owner lead | Meaning |
| --- | ---: | --- | --- |
| `0x004d1a20-0x004d1b72` | 1 read | MapTileImageLib | draw guard, `jnz` early exit when flag nonzero |
| `0x004d2720-0x004d4aca` | 49 reads / 49 writes | HumanImageLib constructor | old-human/equipment table reads latch failures |
| raw `0x004d5f80` | 1 read | unmodeled human-image-like render body | raw guard; no xrefs/pointers to raw start |
| `0x004db3b0-0x004db5bc` | 1 read | MonsterImageLib | render guard |
| raw `0x004dcaa0` | 1 read | unmodeled riding/monster-table-like render body | raw guard; no xrefs/pointers to raw start |
| `0x004dd2c0-0x004dd84a` | 1 read | StaticObjImageLib | render guard |
| `0x004de190-0x004de2a0` | 1 read | EffectObjImageLib | render guard |
| `0x004de7d0-0x004dec23` | 4 reads / 4 writes | EffectObjImageLib | `EFFECT.TBL` / `EFFECT.FRM` loader latches failures and count mismatches |
| `0x004dee50-0x004defba` | 1 read | ItemObjImageLib | general draw guard |
| `0x004defc0-0x004df1d4` | 1 read | ItemObjImageLib | fixed-slot draw guard |
| `0x004e6ae0-0x004e6c4c` | 4 reads / 4 writes | VectorHelpers, called only from HumanImageLib | shared table/vector loader writes the same latch |
| `0x004e6c50-0x004e6de4` | 5 reads / 5 writes | VectorHelpers, called only from HumanImageLib | record-block loader writes the same latch |

Representative writer pattern:

```text
004D2BA2  call    sub_49C4A0
004D2BA7  movzx   ecx, byte_69B420
004D2BAE  test    eax, eax
004D2BBB  cmovz   ecx, edx        ; edx = 1
004D2BC4  mov     byte_69B420, cl

004DE882  call    sub_49C4A0
004DE887  movzx   ecx, byte_69B420
004DE88E  test    eax, eax
004DE898  cmovz   ecx, edx        ; edx = 1
004DE89B  mov     byte_69B420, cl

004E6B1F  call    sub_49C4A0
004E6B24  movzx   ecx, byte_69B420
004E6B2B  test    eax, eax
004E6B35  cmovz   ecx, edx        ; edx = 1
004E6B38  mov     byte_69B420, cl
```

Representative guard pattern:

```text
004D1A4E  cmp     byte_69B420, 0
004D1A5B  jnz     loc_4D1B54

004DB3C0  cmp     byte_69B420, 0
004DB3ED  jnz     loc_4DB5A9

004DE1A0  cmp     byte_69B420, 0
004DE1CE  jnz     loc_4DE28E

004DEE60  cmp     byte_69B420, 0
004DEE7E  jnz     loc_4DEFA7
```

Inference: nonzero is the render-suspend/error polarity. The observed writes are conservative latch updates: they preserve the current byte and set it to `1` on failed reads or mismatched field counts.

### Boundary And Static-Lifetime Evidence

The address neighborhood is exact and does not support a split:

| Range | Current page | Owner result |
| --- | --- | --- |
| `0x0069b418-0x0069b41c` | [UID:00029I] `g_pHourPane` | assigned to `g_pHourPane` |
| `0x0069b41c-0x0069b420` | [UID:0002XU] `g_pIconsPane` | assigned to `g_pIconsPane` |
| `0x0069b420-0x0069b424` | this target | shared image-library flag |
| `0x0069b424-0x0069b430` | [UID:00029K] `ImageLibraryFallbackRecord` | assigned to `MonsterImageLib` |
| `0x0069b430-0x0069b43c` | [UID:0001PL] `RidingDefinitionGlobalTable` | assigned through `RidingDefinitionGlobalTable` / `RidingImageLib` |

The static initializer wrapper island proves a useful negative fact. It initializes `0x0069b424` at `0x00419fb0` and `0x0069b430` at `0x00419fd0`, and corresponding cleanup wrappers at `0x0060c280` and `0x0060c290` destroy those objects. There is no equivalent static constructor/destructor wrapper for `0x0069b420`. That argues against assigning the flag to the neighboring Monster/Riding table-object helper family by adjacency alone.

The raw unmodeled guard bodies at `0x004d5f80` and `0x004dcaa0` have source-looking prologues and image-render behavior, but IDA reports no function object, no xrefs to the raw starts, and no call/jump operands targeting the starts. They support broad consumer fanout, not direct source ownership.

### Candidate Owner Ranking

#### 1. `ImageLib` / `NexusTK/render/ImageLib.cpp` - recommended

Evidence for:

- The flag is not tied to one asset family. Writers are split across old-human table loading, effect table loading, and Human-called shared vector/table helpers. Readers guard map-tile, human/raw, monster, riding/raw, static-object, effect, and item rendering.
- [UID:0000K2][ImageLib](../../../../../by-file/ImageLib.md) is the existing gate-clearing common image-library source page (`87/86`) for process-wide image-library support. It already owns `g_pEPFLib` / central image-cache support and is documented as the common render image-library manager rather than an asset-specific renderer.
- [UID:0000J3][EPFImageResources](../../../../../by-file/EPFImageResources.md) and the proposed source tree describe a split where asset-specific image libraries remain separate, while shared render/image support lives in common render files such as `ImageLib.cpp`, `ResourceLayoutTable.cpp`, and `ImageFrameTable.cpp`. This flag is shared state, not an asset-specific table.
- A source-level global can be declared in a common file and referenced from per-family modules without the owning file containing direct instruction refs to the variable. The absence of an `ImageLib` method xref is therefore not disqualifying when no writer-only owner exists.

Evidence against:

- No debug/source metadata proves the original declaration file.
- No `ImageLib` method directly references `byte_69B420`.
- The exact original symbol name remains unknown.

Conclusion: best existing executable parent. The evidence is inferential but stronger than any per-family owner or new-file hypothesis.

#### 2. New `ImageLibraryLoadState.cpp` / by-global-only parent - rejected as primary

This is semantically clean but overfits the evidence. There is no proposed source-tree entry, no static-lifetime object, no coherent cluster of additional globals, and no direct function island that would justify a new source file. A semantic by-global page could be created later for documentation, but it is not required to fix the memory coverage row and would introduce a new UID dependency. Direct assignment to `ImageLib` is the simpler executable action.

#### 3. `HumanImageLib` - rejected

HumanImageLib has the largest writer count: 49 direct writes in the constructor, plus 9 writes in `ImageLibVectorSupportHelpers` called only from the HumanImageLib constructor. That proves HumanImageLib is the primary loader that latches the flag, but not the declaration owner. EffectObjImageLib also writes the same byte, and render guards in other image libraries depend on it. Assigning the declaration to HumanImageLib would make a process-wide image-library error flag depend on the old-human/equipment module even though non-human modules both write and read it.

#### 4. `EffectObjImageLib` - rejected

EffectObjImageLib writes the flag in `LoadEffectTables` and reads it in `RenderEffectFrame`, and [UID:00004A][EffectObjImageLib](../../../../../by-class/EffectObjImageLib.md) still has a note saying to keep the byte near effect until a broader owner is proven. That note is now stale. Effect has only 4 writes and 1 render read among 132 refs, and the class page is below the current `85/85` parent gate (`82/84`). It is a participating module, not the best shared declaration owner.

#### 5. `MonsterImageLib` / Riding table adjacency - rejected

[UID:00029K][ImageLibraryFallbackRecord](../../../../../by-memory/0x0069b424-0x0069b430.ImageLibraryFallbackRecord.md) immediately after the flag is now correctly assigned to MonsterImageLib, and [UID:0001PL][RidingDefinitionGlobalTable](../../../../../by-memory/0x0069b430-0x0069b43c.RidingDefinitionGlobalTable.md) follows it. Those are concrete 12-byte table objects with static constructor/destructor wrappers and owner-specific loader/fallback behavior. The flag lacks those static lifetime refs and is read/written across the broader image-library set, so adjacency is weaker than xref distribution.

#### 6. `VectorHelpers` - rejected

[UID:00022R][ImageLibVectorSupportHelpers](../../../../../by-memory/0x004e6ae0-0x004e70e9.ImageLibVectorSupportHelpers.md) has 18 refs to the flag, including 9 writes, but those first two helpers are called only from HumanImageLib. [UID:0000P3][VectorHelpers](../../../../../by-file/VectorHelpers.md) is a utility/template-support parent; it owns helper bodies, not the semantic process-wide image-library load state that other modules also write/read.

#### 7. `ImageFrameTable` / `ImageLoaders` - rejected

[UID:0000K1][ImageFrameTable](../../../../../by-file/ImageFrameTable.md) owns frame metadata table helpers, and [UID:0000K3][ImageLoaders](../../../../../by-file/ImageLoaders.md) owns PCX/JPF/BMP/JPEG/PNG decode wrappers. Neither has direct refs to this flag, and their roles are resource decoding/table projection rather than process-wide render-suspend state. The target is closer to common image-library state than to codec or frame-table helper ownership.

### Proposed Target-Page Edits For Supervisor

Apply these to the target page if adopting this recommendation:

- Change `COMPLETION:87` to `COMPLETION:88`.
- Keep `CONFIDENCE:92`.
- Set `AUTOGEN_PARENT_UID:0000K2`.
- Update the parent-status wording to say this is assigned to [UID:0000K2][ImageLib](../../../../../by-file/ImageLib.md) as shared image-library error/render-suspend state.
- Keep `RECONSTRUCTION_CPP` blank. The owner is now defensible for coverage, but final C++ naming/header visibility remains below final-source quality.
- Add [UID:0000K2][ImageLib](../../../../../by-file/ImageLib.md) to the cross-reference list.

### Validation And Changed Files

Changed files in this B001 pass:

- `tools/leaser/Agents/Agent-B001/research/00029J-ImageLibraryLoadErrorFlag.md`

No by-memory, by-global, by-file, or coverage files were edited. Therefore no validator command was required for project documentation pages in this pass.

Leases used: none. This pass only created a research report inside the Agent-B001 research folder and did not edit leased project documentation.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/00029J-ImageLibraryLoadErrorFlag.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:21","uid":"00029J"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
