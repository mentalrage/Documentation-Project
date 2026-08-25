** TARGET-REPORT-UID:0003IO **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003IO **
# Final Recommendation

Keep [UID:0003IO][0x0061e6f8-0x0061e700.SharedGmWideString](../../../../../by-memory/0x0061e6f8-0x0061e700.SharedGmWideString.md) as a reconstructable pooled literal with `CANONICAL_OWNER:NONE` and `EMITTER_UIDS:0000L3,0000KU,0000M4`.

No canonical owner, emitter change, split, merge, reclassification, IDA repair, child-page creation, or shared coverage-report edit is justified. The live IDA MCP evidence proves one physical UTF-16 `GM` literal at `0x0061e6f8`, 20 direct code xrefs split across MapPane, LivingObjectPane, and ObjectList consumers, and no references to the interior or end boundary. Under the current by-structure rules, this is exactly the valid "no declaration owner, multiple proven source-use emitters" case for a compiler-pooled source literal.

Recommended metadata remains:

```text
CANONICAL_OWNER:NONE
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000L3,0000KU,0000M4
RECONSTRUCTION_CPP: blank
```

`by-memory/-coverage-report.md` replacement row: none required. The current shared row should remain unchanged.

# Research

## Target And Scope

- Agent: Agent-B002
- Verification date: 2026-06-14
- Target UID: `0003IO`
- Target file: `by-memory/0x0061e6f8-0x0061e700.SharedGmWideString.md`
- Coverage source checked: `auto-generated/-ag-memory-coverage.md`
- Prior report used only as evidence lead: `Agent-B001/research/executed/0003IO-SharedGmWideString-live-goal2-no-owner-pass.md`
- Shared edit policy: no direct edit to `by-memory/-coverage-report.md`; no by-* edits made, so no lease was required.

This was a fresh verification pass using the current target page, current file/class/memory docs, the current no-owner tracker context, and live IDA MCP evidence from database `a001_goal2_class_batch`.

## Current Documentation State

The current target page records:

- UID `0003IO`
- Address range `0x0061e6f8-0x0061e700`
- Completion/confidence `88/93`
- `CANONICAL_OWNER:NONE`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000L3,0000KU,0000M4`
- Blank reconstruction C++ block

The page describes the bytes as a source-authored UTF-16 `GM` string literal pooled into `.rdata`. The containing index page [UID:0003C1][0x0061e6c0-0x0061e700.MapNameMiniMapResourceStrings](../../../../../by-memory/0x0061e6c0-0x0061e700.MapNameMiniMapResourceStrings.md) remains a non-emitting mixed string-data index. Its exact children route independently:

| Child | Bytes | Current routing |
| --- | --- | --- |
| `0003IL` | `MAPNAME.EPF` | MapNamePane |
| `0003IM` | `MMAPBUT.EPF` | MiniMapButtonPane |
| `0003IN` | `CMAP` | MapPane |
| `0003IO` | UTF-16 `GM` | no owner, emitters `0000L3,0000KU,0000M4` |

The current by-structure rules permit `CANONICAL_OWNER:NONE` with multiple `EMITTER_UIDS` for pooled string literals and shared constants when no single semantic declaration owner is proven but multiple source-use contexts are proven. They also say not to invent a standalone global/helper page solely to avoid `NONE`.

## Current Consumer Documentation

### MapPane route: `0000L3`

[UID:0000L3][MapPane](../../../../../by-file/MapPane.md) is the current file-level route for `NexusTK/map/MapPane.cpp`, and the MapPane class/file docs still clear the ownership gate for MapPane helper code. [UID:0001AP][0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore](../../../../../by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md) includes `0x00505430-0x005055ca sub_505430` as a MapPane movement collision/nation-mask helper.

The `GM` literal reference at `0x00505505` sits inside that MapPane helper. This proves a MapPane source-use emitter, but only one of the 20 literal uses.

### LivingObjectPane route: `0000KU`

[UID:0000KU][LivingObjectPane](../../../../../by-file/LivingObjectPane.md) is the current file-level route for `map/LivingObjectPane.cpp`. [UID:000233][0x00514ea0-0x00514edd.LivingObjectPaneGmNameSuffixCheck](../../../../../by-memory/0x00514ea0-0x00514edd.LivingObjectPaneGmNameSuffixCheck.md) is attached to LivingObjectPane and documents the suffix check against `L"GM"` through `__wcsicmp`.

The `GM` literal reference at `0x00514ec5` is inside this exact LivingObjectPane method. This proves the LivingObjectPane source-use emitter, but it does not own the MapPane or ObjectList references.

### ObjectList route: `0000M4`

[UID:0000M4][ObjectList](../../../../../by-file/ObjectList.md) is the current file-level route for `NexusTK/map/ObjectList.cpp`. [UID:00023F][0x00532f70-0x0053728e.ObjectListExtendedTypeLookupHelpers](../../../../../by-memory/0x00532f70-0x0053728e.ObjectListExtendedTypeLookupHelpers.md) is the current ObjectList extended lookup aggregate. It is attached through the ObjectList class/source chain and documents six modeled helper starts from `0x00533170` through `0x00533d00`.

The remaining 18 `GM` literal references are inside those ObjectList helpers. This proves the ObjectList source-use emitter, but ObjectList does not own the MapPane or LivingObjectPane uses.

## Live IDA MCP Evidence

IDA MCP `server_health` for `a001_goal2_class_batch` reported:

- Module: `NexusTK.exe`
- Input path: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- IDB path: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`
- Imagebase: `0x400000`
- Auto-analysis ready: true
- Hex-Rays ready: true
- Strings cache ready: true

### Literal bytes and neighboring boundary

`get_bytes` for `0x0061e6f0-0x0061e708` returned:

```text
0x0061e6f0: 43 4d 41 50 00 00 00 00 47 00 4d 00 00 00 00 00 d4 b2 64 00 50 4d 51 00
```

Interpretation:

- `0x0061e6f0`: ANSI `CMAP` plus padding.
- `0x0061e6f8`: UTF-16LE `GM` plus terminator and padding.
- `0x0061e700`: no string start.
- `0x0061e704`: successor string/value `PMQ`, outside this target.

`get_string` returned:

| Address | Result |
| --- | --- |
| `0x0061e6f0` | `CMAP` |
| `0x0061e6f8` | `GM` |
| `0x0061e6fc` | no string |
| `0x0061e700` | no string |
| `0x0061e704` | `PMQ` |

This confirms the target is an exact eight-byte child and does not need a boundary split.

### Xrefs to the target

`xrefs_to` for `0x0061e6f8` returned exactly 20 direct data xrefs:

| Consumer function | Xref addresses | Source-use route |
| --- | --- | --- |
| `sub_505430 @ 0x00505430` | `0x00505505` | `0000L3` MapPane |
| `sub_514EA0 @ 0x00514ea0` | `0x00514ec5` | `0000KU` LivingObjectPane |
| `sub_533170 @ 0x00533170` | `0x0053321a`, `0x005332b5`, `0x0053334c` | `0000M4` ObjectList |
| `sub_5333B0 @ 0x005333b0` | `0x00533445`, `0x00533515`, `0x005335b7` | `0000M4` ObjectList |
| `sub_533600 @ 0x00533600` | `0x005336a5`, `0x00533738`, `0x005337d7` | `0000M4` ObjectList |
| `sub_533850 @ 0x00533850` | `0x005338dc`, `0x0053397a`, `0x00533a1b` | `0000M4` ObjectList |
| `sub_533A90 @ 0x00533a90` | `0x00533b3a`, `0x00533bfa`, `0x00533ca5` | `0000M4` ObjectList |
| `sub_533D00 @ 0x00533d00` | `0x00533d9a`, `0x00533e6a`, `0x00533f19` | `0000M4` ObjectList |

Boundary xref checks:

| Address | Xref count | Interpretation |
| --- | ---: | --- |
| `0x0061e6f8` | 20 | Valid literal start used by three consumer families. |
| `0x0061e6fc` | 0 | No interior pointer or alternate child needed. |
| `0x0061e700` | 0 | No end-boundary pointer or trailing child needed. |
| `0x0061e704` | 5 | Successor data/string, not part of this target. |

### Representative instruction evidence

The MapPane consumer at `0x00505505`:

```text
5054ff: add ecx, 93h
505505: push offset aGm; "GM"
50550a: lea eax, [esi+ecx*2]
50550d: push eax; String1
50550e: call __wcsicmp
```

The LivingObjectPane consumer at `0x00514ec5`:

```text
514ebb: sub eax, esi
514ebd: add edx, 126h
514ec3: sar eax, 1
514ec5: push offset aGm; "GM"
514eca: lea eax, [edx+eax*2]
514ecd: push eax; String1
514ece: call __wcsicmp
514ed8: setz al
```

The ObjectList consumer at `0x0053321a`:

```text
533214: add ecx, 93h
53321a: push offset aGm; "GM"
53321f: lea eax, [edx+ecx*2]
533222: push eax; String1
533223: call __wcsicmp
```

The instructions prove in-place source uses of the same pooled literal, not a shared source declaration or helper function.

## Independent PE Byte Scan

The raw `NexusTK.exe` scan found:

| Pattern | Count | Notes |
| --- | ---: | --- |
| `47 00 4d 00 00 00 00 00` | 1 | Exact UTF-16LE `GM` bytes occur once, raw offset `0x21d0f8`. |
| VA `0x0061e6f8` as `f8 e6 61 00` | 20 | Matches the 20 IDA xrefs. |
| VA `0x0061e6fc` as `fc e6 61 00` | 0 | No interior pointer. |
| VA `0x0061e700` as `00 e7 61 00` | 0 | No end pointer. |
| VA `0x0061e704` as `04 e7 61 00` | 5 | Successor data only. |
| RVA `0x0021e6f8` | 0 | No RVA-style reference to the literal. |
| RVA `0x0021e6fc` | 0 | No RVA-style interior reference. |
| RVA `0x0021e700` | 0 | No RVA-style end reference. |
| RVA `0x0021e704` | 0 | No RVA-style successor reference. |

This independently supports the IDA boundary and xref model.

## Candidate Owner And Emitter Analysis

### Keep `CANONICAL_OWNER:NONE`

This is correct. The physical bytes are one compiler-pooled literal used by three independent source families. No current evidence shows a named global declaration, a common source helper, a resource table owner, or a single class/file whose semantic boundary covers all 20 uses.

Assigning a canonical owner would overclaim:

- MapPane owns only `sub_505430` and the nearby map-resource context.
- LivingObjectPane owns only the suffix-check method at `0x00514ea0`.
- ObjectList owns the 18 type lookup helper uses but not the MapPane or LivingObjectPane use sites.
- The parent string-index page `0003C1` is intentionally non-emitting and mixed-owner.

Under current project rules, reconstructable source data can remain `CANONICAL_OWNER:NONE` when it is source-authored but compiler-pooled and the only reconstructable action is to place equivalent literal text at each proven use site.

### Keep `EMITTER_UIDS:0000L3,0000KU,0000M4`

This is also correct. The item should not be non-emitting. The live xrefs prove three actual source-use routes:

- `0000L3` emits the MapPane use in `NexusTK/map/MapPane.cpp`.
- `0000KU` emits the LivingObjectPane use in `map/LivingObjectPane.cpp`.
- `0000M4` emits the ObjectList uses in `NexusTK/map/ObjectList.cpp`.

The emitter set should not be reduced to one UID because each route covers only part of the direct use set. It should not be expanded because no fourth consumer family appears in the live xrefs.

### Keep blank reconstruction C++

The blank C++ block is appropriate. A standalone reconstruction snippet would imply a source-level declaration such as a global `const wchar_t[]`, but the evidence supports local literal use at each consumer site. The actual source reconstruction belongs in the emitted methods that compare against or otherwise use `L"GM"`.

## Rejected Alternatives

| Alternative | Rejection reason |
| --- | --- |
| Assign canonical owner `0000L3` MapPane | Only one direct xref is in MapPane. It cannot own the LivingObjectPane suffix method or ObjectList helper family. |
| Assign canonical owner `0000KU` LivingObjectPane | The LivingObjectPane use is a single exact suffix check. It does not cover MapPane or ObjectList. |
| Assign canonical owner `0000M4` ObjectList | ObjectList has most xrefs, but majority use count is not semantic ownership. It does not cover the MapPane and LivingObjectPane uses. |
| Assign parent/container `0003C1` as owner | `0003C1` is a mixed physical string index, not a source declaration owner. |
| Create a shared GM global/helper child | No direct declaration, helper, or named source table is evidenced. Creating one would be a documentation artifact. |
| Split `0x0061e6f8-0x0061e700` | IDA and PE checks show one exact literal, zero interior xrefs, and zero end-boundary xrefs. |
| Reclassify as ignored/non-reconstructable | The literal is source-authored and directly used by reconstructable code paths; it is reconstructable through source-use emitters. |
| Drop emitters and make it non-emitting | Incorrect because the xrefs prove direct source-use routes. |

## Exact Recommended Changes

No file changes are recommended for the target or shared coverage report.

If this row is reviewed during a future shared report sync, retain the current meaning:

```text
- [UID:0003IO][0x0061e6f8-0x0061e700.SharedGmWideString](by-memory/0x0061e6f8-0x0061e700.SharedGmWideString.md) 0x0061e6f8-0x0061e700 | string-data | SharedGmWideString : reconstructable : 88% : very strong : UTF-16LE `GM` pooled source literal with `CANONICAL_OWNER:NONE` and `EMITTER_UIDS:0000L3,0000KU,0000M4`; ownership reviews confirm 20 direct code xrefs across MapPane, LivingObjectPane, and ObjectList consumers, with no single semantic declaration owner.
```

This is a retain row, not a requested replacement.

## Validation Notes

- No dry runs used.
- No by-* documentation files edited.
- No lease acquired because only this Agent-B002 research report was created.
- No `by-memory/-coverage-report.md` edit made.
- IDA MCP evidence used live database `a001_goal2_class_batch`.
- Independent PE scan used `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.

## Confidence

Confidence: high.

The literal identity, byte uniqueness, exact boundary, direct xref count, consumer grouping, and current source-file routes all agree. The only remaining uncertainty is original source spelling/style around each consumer method, which does not affect the ownership or emitter decision for this pooled literal page.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003IO","source_path":"executed-b-agent-research/B002/0003IO-SharedGmWideString-goal2-verification.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
