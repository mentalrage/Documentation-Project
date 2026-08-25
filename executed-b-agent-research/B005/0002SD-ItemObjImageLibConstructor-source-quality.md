** TARGET-REPORT-UID:0002SD **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002SD ItemObjImageLibConstructor Source-Quality Report

## Executive Recommendation

Recommendation: update [UID:0002SD][0x004dec30-0x004dee1b.ItemObjImageLibConstructor](../../../../../by-memory/0x004dec30-0x004dee1b.ItemObjImageLibConstructor.md) from `84/88` to `87/90`, keep `CANONICAL_OWNER:0000KH`, keep `EMITTER_UIDS:0000KH`, and populate the formal first-draft C++ block.

The earlier blank-C++ blocker is no longer strong enough. Local IDA exports, current support docs, sibling LightObjImageLib precedent, and a direct `memory.bin` byte scan resolve the generated helper names to `DATFile` lifecycle/open plus encoded scalar table reads. The remaining `ItemInfo +0x00/+0x0c` names are not original-symbol proven, but they are bounded enough for first-draft source using descriptive names. They should cap confidence below final audit, not block emission.

No split, rename, owner change, or range edit is recommended. Do not edit `by-memory/-coverage-report.md` directly; exact replacement row text is below.

## Evidence Sources Checked

- Target page: [0x004dec30-0x004dee1b.ItemObjImageLibConstructor.md](../../../../../by-memory/0x004dec30-0x004dee1b.ItemObjImageLibConstructor.md).
- Support docs: [ItemObjImageLib file](../../../../../by-file/ItemObjImageLib.md), [ItemObjImageLib class](../../../../../by-class/ItemObjImageLib.md), [ItemObjImageLibLocalMethodCluster](../../../../../by-memory/0x004dec30-0x004df500.ItemObjImageLibLocalMethodCluster.md), [ItemObjImageLibLoadItemInfoTable](../../../../../by-memory/0x004df500-0x004df668.ItemObjImageLibLoadItemInfoTable.md), [ItemObjImageLibRefreshItemFrameAvailability](../../../../../by-memory/0x004df670-0x004df7d2.ItemObjImageLibRefreshItemFrameAvailability.md), [ItemInfo](../../../../../by-type/by-struct/ItemInfo.md), [ItemObjImageLibLayout](../../../../../by-type/by-struct/ItemObjImageLibLayout.md), [DATFile](../../../../../by-file/DATFile.md), [DATFile class](../../../../../by-class/DATFile.md), [DATFile aggregate](../../../../../by-memory/0x0049c130-0x0049d2cc.DATFile.md), and [LightObjImageLibConstructor](../../../../../by-memory/0x004df7e0-0x004dfaa6.LightObjImageLibConstructor.md).
- Executed B report checked as precedent: `Agent-B003/research/executed/older/0003LZ-LightInfoTableLoader.md`.
- Local IDA/export artifacts checked: `C:\Users\admin\Desktop\CTools\Output\ida\decompile\0x004dec30.json`, `0x004df500.json`, `0x0049c4a0.json`, symbol decompile JSON for `sub_49C130`, `sub_49C160`, `sub_49C180`, `sub_49C4F0`, and combined export `resources/exported_data/functions/0x004dec30.json`.
- Direct byte scan checked: `C:\Users\admin\Desktop\CTools\Output\ida\memory\memory.bin`, base `0x401000`.
- Generated coverage/source checked as a lead only: `auto-generated/-ag-memory-coverage.md` and `auto-generated/NexusTK/render/ItemObjImageLib.cpp`.
- IDA MCP live endpoint checked on 2026-06-18: unavailable at `http://127.0.0.1:13337/mcp`. This report therefore uses local IDA export JSON and direct bytes instead of new live MCP results.

Numeric conversions used in this report for `0x1eb`, `0x14`, `0x0a`, `0x4000`, `0x3f53`, `0x0972`, `0x0a20`, and `0x0a56` were verified with `tools/int_convert.py`.

## Target Validation

The constructor range remains exact: `0x004dec30-0x004dee1b`, half-open. Local IDA/Ghidra combined export agrees on size `0x1eb` / 491 bytes (Verified with `int_convert.py`) and a `ItemObjImageLib * __thiscall ItemObjImageLib::ItemObjImageLib(ItemObjImageLib *this)` source shape. Direct bytes show a normal prolog at `0x004dec30`, normal return at `0x004dee1a`, and five `0xcc` alignment bytes at `0x004dee1b-0x004dee20` before the raw ordinary destructor prolog.

Reachability remains startup-only. Local export reports one caller: `0x004f602f` in `sub_4F5FB0` / Ghidra `InitializeSubsystems`. This matches the target page's `Application::Startup` startup singleton construction path. No evidence supports a virtual, callback, pointer-table, or ad hoc caller route for the constructor start.

Direct byte scan confirms the constructor operands:

| Operand | Evidence |
| --- | --- |
| `g_pItemObjImageLib` / `0x0067a758` | Operand hits at `0x004dec7c` and `0x004dec84`; store-this or clear-zero paths. |
| `ItemObjImageLib` vtable / `0x0061b73c` | Operand hit at `0x004dec8e`; compiler vptr store. |
| `ProtectedArray<ItemInfo>` vtable / `0x0061b734` | Operand hit at `0x004dec94`; embedded protected-array vptr store. |
| `ITEM.TBL` / `0x0061c260` | Operand hit at `0x004decf8`; UTF-16 string bytes decode to `ITEM.TBL`. |
| `ITEM.TBD` / `0x0061c274` | Operand hit at `0x004decff`; UTF-16 string bytes decode to `ITEM.TBD`. |

The `ITEM.TBL` / `ITEM.TBD` run is immediately followed by `ITEM.EPF` / `ITEM.EPD` in the same read-only string neighborhood. The constructor uses only the table pair; draw and availability helpers use the archive pair.

## Helper Family Resolution

The current target open question lists generated names `sub_49C130`, `sub_49C180`, `sub_49C4A0`, `sub_49C4F0`, and `sub_49C160`. Current evidence resolves their source roles:

| Address | Source-facing role | Evidence |
| --- | --- | --- |
| `0x0049c130` | `DATFile::DATFile` constructor | Local IDA symbol export initializes base `File`, installs `DATFile::vftable`, clears `this[1]` and `this[2]`; DATFile docs list exact range `0x0049c130-0x0049c15a`. |
| `0x0049c180` | `DATFile::Open(const wchar_t *)` | Local export has vtable slot `3` for class `DATFile`, resolves a named entry through `_DATFileMgr::FindEntryByName`, and throws `FileError` on miss. |
| `0x0049c4a0` | DAT encoded integer/scalar table read; local draft alias `ReadEncodedTableInt` | Local export calls `GetSize() >> 1`, reads an 8-byte header through the stream read slot, and dispatches to `ParseEntries`. DAT docs retain owner name `ReadAllEntries` but explicitly allow image-library local aliasing. |
| `0x0049c4f0` | DAT encoded float/scalar table read; local draft alias `ReadEncodedTableFloat` | Local export has the same wrapper shape and six image-table callers, including ItemObj constructor and helper, Effect loader, and LightObj constructor. Sibling LightObj constructor already uses `ReadEncodedTableFloat` in accepted first-draft C++. |
| `0x0049c160` | `DATFile::~DATFile` destructor | Local export clears active slots, restores `File::vftable`, and calls base teardown. |

Rejected alternatives:

- Keep raw `sub_*` names: rejected; project DAT docs and local exports already resolve the class/method family.
- Globally rename `DATFile::ReadAllEntries` / `ReadAllEntriesAlt`: rejected in this report. DATFile owner docs intentionally retain those names pending a DATFile owner pass. The correct action here is local source-facing aliases, matching the accepted LightObjImageLib constructor.
- Move table helpers into `ItemObjImageLib`: rejected. They are broad DATFile archive helpers with many callers across image, palette, sound, and map/resource code. ItemObjImageLib is a consumer, not the helper owner.

## ItemInfo Field Reanalysis

The constructor and `0x004df500` table helper load the same five fields in the same order:

| Offset | Read | Best descriptive name | Evidence and caveat |
| --- | --- | --- | --- |
| `+0x00` | encoded int | `itemTableId` | Fallback default is `-1`, and the field is loaded from `ITEM.TBL` / `ITEM.TBD`. Current draw paths copy it but do not visibly use it for resource lookup, so `resourceKeyOrId` overclaims. `itemTableId` is descriptive, not original-symbol proven. |
| `+0x04` | encoded int | `paletteSlot` | Draw and availability helpers pass this field to `PaletteLib` category `10`; high confidence. |
| `+0x08` | encoded float | `alpha` | Draw paths branch on this float and choose alpha/blend callback mode; high confidence for alpha/blend semantics, exact original spelling unproven. |
| `+0x0c` | encoded int | `renderFlagsOrMode` | Loaded and copied with each record but not visibly consumed by current draw decompilation. Keep a conservative descriptive name rather than inventing a specific mode. |
| `+0x10` | encoded int collapsed to byte/bool | `allowPaletteFilter` | Draw paths gate rendering with `PaletteLib::HasCurrentPalette` and this byte; raw availability helper writes the same byte after frame/palette checks. |

This resolves the final-C++ blocker enough for first-draft code because the constructor only initializes, loads, and stores these fields. It does not depend on a precise consumer meaning for `+0x00` or `+0x0c`. Those two names should remain documented as descriptive/provisional and keep the score below final-audit quality.

## Ownership And Source Placement

Keep the target's current direct owner/emitter route: [UID:0000KH][ItemObjImageLib](../../../../../by-file/ItemObjImageLib.md), generated to `NexusTK/render/ItemObjImageLib.cpp`.

Accepted evidence:

- The body is the `ItemObjImageLib` startup constructor and writes the ItemObj singleton/vtable.
- It initializes the `ItemObjImageLib` layout: `ProtectedArray<ItemInfo>` at `this+0x04`, count at `+0x08`, entries at `+0x0c`, growth/default capacity at `+0x10`, and fallback row at `+0x14`.
- It opens `ITEM.TBL` or `ITEM.TBD`, matching the ItemObj post-cluster table loader and not any LightObj or EffectObj resource.
- The target already has a valid emitting route in `auto-generated/-ag-memory-coverage.md`: `emits`, owner `0000KH`, emitter `0000KH`, output `auto-generated/NexusTK/render/ItemObjImageLib.cpp`.
- `auto-generated/NexusTK/render/ItemObjImageLib.cpp` currently contains only the ItemObj remap constants, proving the constructor is missing only because the formal C++ block is blank, not because the route is dead.

Rejected owner/source routes:

- [UID:00006W] `ItemObjImageLib` class as direct owner: semantically valid, but unnecessary for this constructor page and inconsistent with the accepted LightObj constructor precedent, which routes the constructor through the file owner while recording the class in prose.
- `DATFile` / `DATArchive`: rejected; DATFile owns the helper API, not the ItemObj object initialization or `ItemInfo` table destination.
- `ProtectedArray`: rejected; the constructor initializes one embedded specialization but source ownership is ItemObjImageLib. The reusable template docs stay under [UID:0000MU][ProtectedArray](../../../../../by-file/ProtectedArray.md).
- `ItemInfo` type page: rejected as direct owner; the row POD is owned by ItemObjImageLib, but the function body is the constructor.
- `LightObjImageLib`: rejected by resource names, singleton/vtable operands, `0x14` row stride, and constructor boundary before the true LightObj start at `0x004df7e0`.
- `ImageLib` / `ResourceLayoutTable` / `PaletteLib`: rejected; these are draw/helper dependencies and do not participate in this constructor's table parse except indirectly through sibling helpers.
- New helper file/grouping: rejected. Existing `ItemObjImageLib.cpp` already owns the singleton, table resources, draw helpers, table loader, availability refresh helper, remap constants, and constructor/destructor family.

## Resource Selection Semantics

Use source-facing `g_useEpfAssets` for `byte_66DA97`. The existing project-level resolved report already maps this global as `g_useEpfAssets`. In this constructor, `g_useEpfAssets == true` selects `ITEM.TBL`; false selects `ITEM.TBD`. In draw/availability helpers, the same flag selects `ITEM.EPF` versus `ITEM.EPD`.

The fallback row is not an error record allocated from the DAT table. It is a built-in safe `ItemInfo` default at `this+0x14`: `-1`, `-1`, `0.0f`, `-1`, and `false`. It is selected when an index is outside the current protected-array count.

## First-Draft C++ Recommendation

Supervisor should populate the target's formal `RECONSTRUCTION_CPP CODE` block with this first-draft source. It intentionally omits vtable writes, SEH/security-cookie machinery, and compiler cleanup state.

```cpp
ItemObjImageLib::ItemObjImageLib()
{
    g_pItemObjImageLib = this;

    itemInfoCount = 0;
    itemInfoEntries = 0;
    itemInfoCapacity = 10;

    fallbackItemInfo.itemTableId = -1;
    fallbackItemInfo.paletteSlot = -1;
    fallbackItemInfo.alpha = 0.0f;
    fallbackItemInfo.renderFlagsOrMode = -1;
    fallbackItemInfo.allowPaletteFilter = false;

    DATFile itemTable;
    itemTable.Open(g_useEpfAssets ? L"ITEM.TBL" : L"ITEM.TBD");

    int itemCount = 0;
    ReadEncodedTableInt(&itemTable, &itemCount);

    if (itemCount > 0 && itemInfoCount != itemCount) {
        ItemInfo *newEntries =
            static_cast<ItemInfo *>(operator new(sizeof(ItemInfo) * itemCount));

        if (itemInfoEntries != 0) {
            int copyCount = itemCount;
            if (itemInfoCount < copyCount) {
                copyCount = itemInfoCount;
            }

            memmove(newEntries, itemInfoEntries, sizeof(ItemInfo) * copyCount);
            free(itemInfoEntries);
        }

        itemInfoCount = itemCount;
        itemInfoEntries = newEntries;
    }

    for (int index = 0; index < itemCount; ++index) {
        ItemInfo itemInfo;
        ReadEncodedTableInt(&itemTable, &itemInfo.itemTableId);
        ReadEncodedTableInt(&itemTable, &itemInfo.paletteSlot);
        ReadEncodedTableFloat(&itemTable, &itemInfo.alpha);
        ReadEncodedTableInt(&itemTable, &itemInfo.renderFlagsOrMode);

        int allowPaletteFilter = 0;
        ReadEncodedTableInt(&itemTable, &allowPaletteFilter);
        itemInfo.allowPaletteFilter = allowPaletteFilter != 0;

        ItemInfo *slot = &fallbackItemInfo;
        if (index >= 0 && index < itemInfoCount) {
            slot = &itemInfoEntries[index];
        }

        *slot = itemInfo;
    }
}
```

Notes for incorporation:

- `ReadEncodedTableInt` and `ReadEncodedTableFloat` are local source-facing aliases for DATFile-owned helpers at `0x0049c4a0` and `0x0049c4f0`, not a global DATFile rename.
- If the supervisor prefers not to introduce `itemTableId` / `renderFlagsOrMode` into formal type docs yet, the constructor C++ can still use those names as first-draft field labels. Exact original spelling remains below final audit.
- Do not emit explicit assignments to vtable pointers or `ProtectedArray<ItemInfo>` vtable storage. Those are compiler-generated from the class/template declarations.

## Heuristic / Inference Reanalysis And Validation

| Issue | Evidence checked | Rejected alternatives | Final inference and impact |
| --- | --- | --- | --- |
| Exact range and padding | Target page, local IDA export size `0x1eb`, `memory.bin` bytes at `0x004dec30`, `0x004dee0b`, `0x004dee1b`, and `0x004dee20`. | Extending into destructor; shortening before SEH/security-cookie epilogue. | Range stays `0x004dec30-0x004dee1b`; `0x004dee1b-0x004dee20` remains padding. No split/range change. |
| Startup reachability | Local export caller list and target docs report only `0x004f602f` in startup initializer. | Treating constructor as virtual/callback/pointer-table reached. | Startup singleton constructor. Does not affect owner; supports source-authored body. |
| `sub_4F4A80` | Local export/Ghidra names base initializer as `LObject`. | Leave generated name in constructor C++. | Source constructor should rely on base construction, not call `sub_4F4A80` explicitly. |
| `sub_49C130` / `sub_49C160` | Local symbol exports and DAT docs. | Unknown table/path helper; ItemObj-owned helper. | `DATFile` constructor/destructor. Removes target's generated-helper blocker. |
| `sub_49C180` | Local export vtable slot and DAT docs. | Generic resource path helper; static free function. | `DATFile::Open(const wchar_t *)`. Use `itemTable.Open(...)` in C++. |
| `sub_49C4A0` / `sub_49C4F0` | Local exports, DAT aggregate, LightObj accepted report and constructor C++. | Global DATFile rename in this report; leaving raw names; calling them only `ReadAllEntries`. | Use local aliases `ReadEncodedTableInt` and `ReadEncodedTableFloat` for ItemObj first-draft C++; DATFile docs retain owner names pending owner pass. |
| `ItemInfo +0x00` | Constructor/helper load order, draw-method exports, fallback defaults, ItemInfo docs. | `resourceKeyOrId` as final name; `frameId` as proven field. | Best descriptive name `itemTableId`. It is not original-symbol proven and is not visibly used by draw lookup, so it caps confidence but does not block constructor code. |
| `ItemInfo +0x04` | Draw methods pass `SDWORD1(record)` / field `+0x04` to palette category `10`; raw availability helper uses same field. | Generic integer field. | `paletteSlot`, source-ready. |
| `ItemInfo +0x08` | Constructor/helper use float reader; draw methods branch on `> 0.0` to select alpha/blend callback modes. | Integer flags; unknown float. | `alpha`, source-ready enough for draft. |
| `ItemInfo +0x0c` | Constructor/helper load and store; draw decompilation copies but does not visibly consume. | Specific `frameId`, `blendMode`, or `resourceFlags` as final proof. | `renderFlagsOrMode` as conservative descriptive name. Still a residual field-name caveat, but not a no-code blocker. |
| `ItemInfo +0x10` | Constructor/helper collapse final int to bool; draw methods allow render when palette availability is missing but byte is true; raw helper writes refreshed result. | Padding-only byte; generic availability field without palette context. | `allowPaletteFilter`, strong. |
| `g_useEpfAssets` | Project-level resolved entry for `byte_66DA97`, target and sibling docs, string branch operands. | Leave `byte_66DA97`; call it item-table-only flag. | Use `g_useEpfAssets`; true selects `ITEM.TBL`/`ITEM.EPF`, false selects `ITEM.TBD`/`ITEM.EPD`. |
| Owner route | Target metadata, file/class docs, generated coverage output, singleton/vtable operands. | Class direct owner, DATFile owner, LightObj owner, new helper file. | Keep owner/emitter `0000KH`. Class is semantic owner in prose; file route is valid and consistent with constructor precedent. |
| C++ readiness | Current gate: reconstructable true, emitter nonblank, average score already above 85; LightObj precedent; helper and field reanalysis above. | Keep blank solely because original field spellings are imperfect. | Populate first-draft C++; residual name uncertainty caps score at `87/90`, not no-code. |
| Generated output pollution | `auto-generated/NexusTK/render/ItemObjImageLib.cpp` currently only emits constants; constructor coverage row says `emits` but `coded=no`. | Treat route as dead or generated source as source proof. | Route is live but target block blank. Generated output is a lead only; formal C++ population should produce constructor output. |

## Open Questions / Blockers Closed Or Retained

Closed for this target:

- Helper names are no longer blockers: the direct callees have accepted DATFile/base/CRT roles.
- `g_pItemObjImageLib`, `g_useEpfAssets`, vtable operands, and resource path selection are resolved enough for source code.
- Owner/emitter source placement is resolved; no split or new file is needed.
- First-draft C++ is safe for the constructor.

Retained but downgraded:

- Exact original spelling for `ItemInfo +0x00` and `+0x0c` remains unproven. This should be called out in `ItemInfo.md` and target caveats, but it should not keep the constructor below the code gate because the constructor only transfers table fields into a POD row.
- Exact DATFile owner method names for `0x0049c4a0` / `0x0049c4f0` remain a DATFile owner-pass issue. This report recommends local aliases only.

## Recommended Target Metadata

Replace the target metadata header values with:

```markdown
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000KH | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000KH | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Recommended score rationale:

- Completion `87`: exact boundary, startup caller, singleton/vtable/protected-array stores, fallback row, `ITEM.TBL`/`ITEM.TBD` branch, DATFile helper family, row allocation/load loop, field order, local source aliases, first-draft C++, and padding are all documented. It remains below final because two `ItemInfo` field spellings and DAT scalar-reader final method names are descriptive/inferred.
- Confidence `90`: local IDA exports, existing IDA-backed docs, direct bytes, support docs, and LightObj precedent agree. Confidence remains below final audit because IDA MCP was unavailable live and exact original source spellings are not recovered.

## Exact Coverage Row Recommendation

Placement context: replace the current nested `0002SD` row under [UID:00017N] in `by-memory/-coverage-report.md`, currently near the ItemObjImageLib local method cluster block.

```markdown
        - [UID:0002SD][0x004dec30-0x004dee1b.ItemObjImageLibConstructor](by-memory/0x004dec30-0x004dee1b.ItemObjImageLibConstructor.md) 0x004dec30-0x004dee1b | constructor | ItemObjImageLibConstructor : reconstructable : 87% : very strong : Startup ItemObjImageLib constructor with local IDA-export and byte-scan confirmation of the `0x1eb`-byte body, sole startup caller at `0x004f602f`, singleton/vtable and `ProtectedArray<ItemInfo>` setup, `g_useEpfAssets` `ITEM.TBL`/`ITEM.TBD` selector, fallback `ItemInfo` defaults, DATFile ctor/Open/destructor and encoded int/float reader aliases, 20-byte row allocation/load loop, first-draft C++ recommendation, and `0x004dee1b-0x004dee20` padding boundary.
```

No other coverage row is required for this target.

## Recommended Support-Doc Changes

These are report-only recommendations; do not apply them without supervisor authorization.

### Target Page Open Questions

Replace the target page `## Open Questions` section with:

```markdown
## Source-Quality Notes

- The former generated helper-name blocker is resolved for first-draft source: `sub_49C130`, `sub_49C180`, and `sub_49C160` are the `DATFile` constructor, `Open`, and destructor; `sub_49C4A0` and `sub_49C4F0` are DATFile encoded scalar table readers. First-draft ItemObjImageLib source may use local aliases `ReadEncodedTableInt` and `ReadEncodedTableFloat`, matching the accepted LightObjImageLib constructor precedent, while DATFile docs retain their owner names pending a DATFile-specific pass.
- Recommended descriptive `ItemInfo` field names are `itemTableId`, `paletteSlot`, `alpha`, `renderFlagsOrMode`, and `allowPaletteFilter`. `paletteSlot`, `alpha`, and `allowPaletteFilter` are strongly consumed by draw/availability helpers. `itemTableId` and `renderFlagsOrMode` remain descriptive rather than original-symbol proven, so they cap final-audit confidence but do not block first-draft constructor C++.
- Source C++ should omit compiler-generated vtable stores, SEH state, security-cookie checks, and raw `operator new` overflow checks except where expressing the visible allocation/copy/free behavior is needed.
```

### ItemInfo Layout

In [ItemInfo.md](../../../../../by-type/by-struct/ItemInfo.md), replace the `## Layout` code block with:

````markdown
```text
ItemInfo
  +0x00  int itemTableId
  +0x04  int paletteSlot
  +0x08  float alpha
  +0x0c  int renderFlagsOrMode
  +0x10  uint8 allowPaletteFilter
  +0x11  uint8[3] padding
```
````

Then replace the sentence "Current draw methods do not visibly consume every field in IDA pseudocode; final semantic names for `+0x00` and `+0x0c` remain provisional." with:

```markdown
Current draw methods do not visibly consume `+0x00` or `+0x0c` beyond copying the row, so `itemTableId` and `renderFlagsOrMode` are descriptive first-draft names rather than proven original spellings. `paletteSlot`, `alpha`, and `allowPaletteFilter` are supported by draw and availability-helper consumers.
```

### DATFile Alias Note

In [DATFile aggregate](../../../../../by-memory/0x0049c130-0x0049d2cc.DATFile.md), replace the current consumer-alias bullet:

```markdown
- Consumer-facing image-library constructors use `0x0049c4a0` as an encoded integer/scalar table read and `0x0049c4f0` as an encoded float/scalar table read. Existing names `ReadAllEntries` and `ReadAllEntriesAlt` are retained pending a DATFile owner pass, but LightObjImageLib first-draft C++ may use local aliases `ReadEncodedTableInt` and `ReadEncodedTableFloat` to express the caller semantics.
```

with:

```markdown
- Consumer-facing image-library constructors use `0x0049c4a0` as an encoded integer/scalar table read and `0x0049c4f0` as an encoded float/scalar table read. Existing DATFile-owner names `ReadAllEntries` and `ReadAllEntriesAlt` are retained pending a DATFile owner pass, but ItemObjImageLib and LightObjImageLib first-draft C++ may use local aliases `ReadEncodedTableInt` and `ReadEncodedTableFloat` to express the caller semantics.
```

The same wording should be mirrored in [DATFile class](../../../../../by-class/DATFile.md) if the supervisor wants class/file/aggregate text synchronized.

### ItemObjImageLib Class/File Status

In [ItemObjImageLib class](../../../../../by-class/ItemObjImageLib.md), update the parent/C++ status sentence to stop saying the constructor is blocked by helper names. Suggested replacement:

```markdown
- Parent/C++ status: attached to [UID:0000KH][ItemObjImageLib](by-file/ItemObjImageLib.md), the `NexusTK/render/ItemObjImageLib.cpp` source root that owns the item sprite singleton, layout, `ItemInfo` row, global, constructor/destructor, draw paths, and related helpers. The constructor now has a first-draft C++ recommendation; broader class C++ remains blank until draw-method child pages, exact helper signatures, and final original field spellings are source-quality.
```

## Validation And Side Effects

Actions performed:

- Read all assignment-required docs and relevant support docs.
- Tested IDA MCP endpoint; it was unavailable.
- Used existing local IDA export/decompile artifacts and `memory.bin` direct byte scan instead.
- Verified numeric conversions with `tools/int_convert.py`.
- Read generated coverage/source output as a lead only.
- Created this report only.

No direct edits were made to target docs, support docs, generated files, or `by-memory/-coverage-report.md`.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000004165","destination_path":"executed-b-agent-research/B005/0002SD-ItemObjImageLibConstructor-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:31","uid":"0002SD"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
