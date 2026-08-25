** TARGET-REPORT-UID:0002E8 **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002E8 FittingRoomCatalogTransformPersistedBuffer Source-Quality Report

Agent: B005  
Date: 2026-06-19  
Target: [UID:0002E8] `by-memory/0x00422b30-0x00422b93.FittingRoomCatalogTransformPersistedBuffer.md`  
Assignment type: report-only B-preferred source-quality / heuristic-inference pass

## Final Recommendation

Raise [UID:0002E8] from `84/90` to `88/91`, keep `RECONSTRUCTABLE:TRUE`, keep direct owner/emitter [UID:000051] `FittingRoomDialogItemState`, and populate first-draft C++ for a source-authored private item-state helper:

```cpp
void FittingRoomDialogItemState::TransformPersistedBuffer(char* buffer, int byteCount)
{
    const int keyLength = static_cast<int>(m_encodeKey.length());

    for (int index = 0; index < byteCount; ++index) {
        const int keyIndex = index % keyLength;
        buffer[index] ^= m_encodeKey[keyIndex];
        buffer[index] ^= m_decodeKey[keyIndex];
    }
}
```

`TransformPersistedBuffer` is still a descriptive source-facing name rather than an original symbol proof, but it is the strongest current name because the helper is used both for decoding cache reads and encoding cache writes. `XOR_DecodeWithDualKey` and decode-only names are rejected because the save helper calls the same body before writing `ItemShop.jbn`.

The old target blocker that final C++ must wait for field names, key-length names, and buffer type should be retired. Sibling support docs now resolve `m_encodeKey` at `+0x250`, `m_decodeKey` at `+0x268`, `std::string` SSO length/capacity offsets, `m_cacheLoaded` at `+0x24c`, and cache-path/file-flow context. The only remaining uncertainty is exact original spelling of the helper and whether the length parameter was written as `int`, `long`, or another 32-bit signed byte count in source. That is a confidence caveat, not a no-code proof.

Do not edit `by-memory/-coverage-report.md` directly. Exact replacement row text is provided below.

## Current Target State

- Target page metadata: `COMPLETION:84`, `CONFIDENCE:90`, `CANONICAL_OWNER:000051`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000051`.
- Refreshed auto-completion row: `84/90`, average `87.0`.
- Generated output route: `auto-generated/NexusTK/cashshop/FittingRoom.cpp`; current generated file contains an empty emitter marker for [UID:0002E8].
- Current target blocker: stale "95/95" style wording saying source-facing names for encode/decode fields, key length field, and buffer parameter type are not proven.

The target already clears the active code-entry average numerically. This pass resolves the source-shape blockers enough to populate a first draft while retaining non-final caveats.

## Evidence Reviewed

Read/revalidated:

- Target [UID:0002E8] page.
- [UID:000051] `FittingRoomDialogItemState`.
- [UID:0000WU] `FittingRoomItemShopCatalogState` aggregate.
- [UID:0000JE] `FittingRoom` file page.
- Constructor [UID:0002E7].
- Save helper [UID:0002EF].
- Reload helper [UID:0002EG].
- Parser [UID:0002E9].
- Dialog action caller [UID:0002CT].
- Test loader [UID:0002ED].
- [UID:0003AM] `FittingRoomReadOnlyData`.
- [UID:0000WN] `MsvcStringSupportHelpers` and [UID:0002CZ] `SmallStringStorageAssign`.
- [UID:0000KD]/[UID:00006T] `ItemCatalog` file/class pages for rejected owner context.
- Generated `auto-generated/NexusTK/cashshop/FittingRoom.cpp`.
- Exported function JSON for `0x00422b30`, `0x004225a0`, and `0x004229f0`.
- Refreshed stats and memory coverage rows.

Live IDA MCP was probed at `http://127.0.0.1:13337/mcp` and was unavailable in this environment (`Unable to connect to the remote server`). I therefore used current exported IDA/Ghidra function JSON, existing accepted by-* documentation, and a fresh raw PE byte/route audit against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.

## Boundary / Bytes / Padding

Fresh PE byte audit against `NexusTK.exe` confirms the target half-open range is exact.

| Fact | Evidence |
| --- | --- |
| Target VA range | `0x00422b30-0x00422b93` |
| Raw offset | `0x21f30` |
| Length | `0x63` / 99 bytes |
| SHA1 of body bytes | `7637d0c6b5786a55a155b959eb947f9d76b0e993` |
| Previous padding | `0x00422b25-0x00422b30`, eleven `cc` bytes |
| Successor padding | `0x00422b93-0x00422ba0`, thirteen `cc` bytes |
| Next function | `0x00422ba0`, category loader [UID:0002E6] |

Body bytes:

```text
55 8b ec 51 8b 81 60 02 00 00 56 33 f6 89 45 fc
39 75 0c 7e 47 53 57 8d b9 50 02 00 00 8d 99 68
02 00 00 8b c6 99 f7 7d fc 83 7f 14 10 8b c7 72
02 8b 07 8a 0c 10 8b 45 08 32 0c 06 88 0c 06 8b
c3 83 7b 14 10 72 02 8b 03 8a 04 10 32 c1 8b 4d
08 88 04 0e 46 3b 75 0c 7c c9 5f 5b 5e 8b e5 5d
c2 08 00
```

The first byte after the target is `cc`, not code or data. No split, merge, or range repair is recommended.

## Function Model / Reachability

Exported function JSON for `resources/exported_data/functions/0x00422b30.json` confirms:

- IDA name: `sub_422B30`.
- Ghidra name: `meth_0x422b30`.
- GhidrAssist suggestion: `XOR_DecodeWithDualKey`.
- IDA and Ghidra size: `99`.
- Calling convention: `__thiscall` in Ghidra; IDA decompile is consistent with `thiscall`.
- IDA decompile signature shape: `char __thiscall(_DWORD *this, int buffer, int length)`.
- Ghidra decompile signature shape: `void __thiscall meth_0x422b30(cls_0x427990 *this, int param_1, int param_2)`.
- Callees: none.
- Code callers: three.
- Data refs from the helper: none.
- Xrefs from the helper: none.
- Thunk/library flags: false.

Fresh raw route scan over `.text` found exactly three `E8 rel32` call hits to `0x00422b30`:

- `0x00422292` in [UID:0002E7] constructor cache-load path.
- `0x00422618` in [UID:0002EF] save helper.
- `0x00422a9b` in [UID:0002EG] standalone reload helper.

The same scan found no literal VA `0x00422b30` or RVA `0x00022b30` pointer hits. That revalidates the current "ordinary direct private helper" model: it is not a vtable slot, callback table target, jump-table entry, or compiler-generated pooled helper.

## Behavior Reanalysis

The body is a leaf in-place byte transform:

1. Loads the encode-key length from `this + 0x260`.
2. If the byte count argument is `<= 0`, returns without touching the buffer.
3. For `index = 0 .. byteCount - 1`, computes `keyIndex = index % keyLength` with signed `idiv`.
4. Selects encode-key character storage at `this + 0x250`, using inline storage when capacity at `+0x264` is below `0x10`, otherwise heap pointer at `+0x250`.
5. XORs `buffer[index]` with `m_encodeKey[keyIndex]` and writes the intermediate byte back.
6. Selects decode-key character storage at `this + 0x268`, using inline storage when capacity at `+0x27c` is below `0x10`, otherwise heap pointer at `+0x268`.
7. XORs the intermediate byte with `m_decodeKey[keyIndex]` and writes the final byte back.
8. Returns with `retn 8`; the apparent IDA `char` return is the last transformed byte in `AL`, not a source return value.

The two key literals are initialized by [UID:0002E7]:

- `m_encodeKey`: `CASHEncodeDecodeByChris`.
- `m_decodeKey`: `sirhCyBedoceDedocnEHSAC`.

The second literal is the reverse spelling of the first. Both have the same length, and the helper intentionally uses only `m_encodeKey.length()` at `+0x260` as the modulo divisor. This is safe for the constructed object because the constructor seeds both strings together.

The transform is reversible because XOR with the same two per-index key bytes is its own inverse. Calling the helper on encoded `ItemShop.jbn` bytes decodes them; calling it on plaintext bytes encodes them for persistence.

## Field / Type Resolution

| Evidence | Best source-facing name/type | Validation |
| --- | --- | --- |
| `this + 0x250` storage, `this + 0x260` length, `this + 0x264` capacity | `std::string m_encodeKey` | [UID:0002E7] constructor initializes it from `CASHEncodeDecodeByChris`; [UID:000051] records this as resolved. |
| `this + 0x268` storage, `this + 0x278` length, `this + 0x27c` capacity | `std::string m_decodeKey` | Constructor initializes it from `sirhCyBedoceDedocnEHSAC`; target body uses its storage and capacity but reuses encode length. |
| `this + 0x260` | `m_encodeKey.length()` | Not an independent key-length field. It is the `std::string` length slot for the first key. |
| capacity checks `< 0x10` | MSVC/Dinkumware SSO-15 byte-string layout | [UID:0000WN] and [UID:0002CZ] document the same 24-byte string layout and broad runtime/library helper ownership. |
| first explicit argument | `char* buffer` | All three callers pass mutable heap byte buffers, and the helper writes in place. `unsigned char*` is possible but less source-consistent with `std::string` and file-byte caller code. |
| second explicit argument | `int byteCount` | The body uses signed compare `byteCount > 0` and signed modulo (`idiv`). Callers pass non-negative file/string lengths, but the callee's compiled control flow supports a signed source parameter. |
| return value | `void` | Three direct callers ignore `AL`; IDA's `char` return is a decompiler artifact. |

Rejected field interpretations:

- `this+0x260` as a standalone `m_keyLength`: rejected because it is exactly the length slot of `m_encodeKey` in the documented 24-byte string layout.
- `this+0x268` as a second independent transform object: rejected because constructor, target body, and class page all treat it as the second string field in the same item-state object.
- `size_t byteCount` as strongest source type: rejected for first-draft binary shape because the helper uses signed `jle` and signed `idiv`. It remains plausible at a high-level call-site interface because callers derive sizes from `ftell`, `fread`, and string lengths, but the target-specific source-shaped declaration should preserve the signed byte-count behavior.
- `const char* buffer`: rejected because the buffer is mutated in place.

## Caller Path Revalidation

### Constructor [UID:0002E7]

The constructor opens `m_cacheFilePath` in `rb`, reads the entire `ItemShop.jbn` file into a null-terminated heap buffer, calls this helper at `0x00422292`, assigns the transformed bytes into a local `std::string`, then calls `LoadEncodedStateBuffer`. This is decode-on-read.

The existing first-draft constructor already calls `TransformPersistedBuffer(fileBytes, static_cast<size_t>(fileLength))`. Recommended follow-up: after [UID:0002E8] is populated, adjust that call-site draft to pass the helper's signed byte count:

```cpp
TransformPersistedBuffer(fileBytes, static_cast<int>(fileLength));
```

This is a support-doc/source consistency tweak, not a target blocker.

### Save Helper [UID:0002EF]

The save helper opens `m_cacheFilePath` in `wb`, allocates a temporary copy of the passed source buffer, copies the source bytes, calls this helper at `0x00422618`, writes exactly the original byte count, closes/frees, then sets `m_cacheLoaded = true`.

The helper is encode-on-write, proving decode-only source names are wrong. [UID:0002EF] should no longer list the transform helper signature/name as a blocker; its remaining blockers are the consumed source-buffer parameter spelling, the `_wfopen` dispatch wrapper spelling, and whether to express the unconditional cache flag store exactly.

### Reload Helper [UID:0002EG]

The standalone cache-file helper opens the same path in `rb`, reads the entire file, calls this helper at `0x00422a9b`, assigns the transformed bytes into a local string, and calls `LoadEncodedStateBuffer`. It has no direct caller, literal pointer, vtable route, or generated-source route in current evidence.

This target remains a valid dependency of [UID:0002EG], but [UID:0002EG]'s no-caller/source-retention blocker does not block [UID:0002E8]. The transform body itself has live direct callers from the constructor and save path.

## Owner / Source Placement Ranking

### 1. [UID:000051] FittingRoomDialogItemState - Accepted

Evidence:

- All direct callers are item-state methods/helpers or item-state paths.
- The touched fields are all resolved fields of `FittingRoomDialogItemState`.
- `FittingRoomDialogItemState` is the class that owns the cache path, category storage, `m_cacheLoaded`, and encode/decode keys.
- Existing generated route already emits through [UID:000051] into `NexusTK/cashshop/FittingRoom.cpp`.

Direct owner/emitter should remain `000051`.

### 2. [UID:0000JE] FittingRoom file - Source-file route only

Accepted as the file/module route. `cashshop/FittingRoom.cpp` groups the item-state cache/parser code with the fitting-room feature. It should not be the direct owner because by-structure rules prefer the narrowest semantic owner, and the class page is already above gate.

### 3. [UID:0000WU] FittingRoomItemShopCatalogState aggregate - Support aggregate only

Rejected as direct owner. The aggregate is an address container spanning constructor, parser, raw no-caller helpers, lookup methods, transform, and category loader. It is useful for coverage nesting and file-level context, but the transform helper belongs to the item-state class.

### 4. [UID:0000KD] ItemCatalog / [UID:00006T] ItemCatalog - Rejected

Rejected. ItemCatalog is the count/index facade over category lookup storage. It does not touch `ItemShop.jbn`, encode/decode keys, cache file bytes, or persistence transforms.

### 5. Generic crypto/encoding helper - Rejected

Rejected. The helper is a leaf transform, but no non-fitting-room callers, function-pointer refs, or shared utility docs reach it. Both key strings are initialized by the item-state constructor and used only in this cache path.

### 6. Runtime/compiler helper or ignored support - Rejected

Rejected. The body reads product object fields, consumes product key strings, and has direct product callers. It is not MSVC string support, a thunk, padding, or a library helper.

## First-Draft C++ Recommendation

Populate [UID:0002E8]'s formal C++ block with:

```cpp
void FittingRoomDialogItemState::TransformPersistedBuffer(char* buffer, int byteCount)
{
    const int keyLength = static_cast<int>(m_encodeKey.length());

    for (int index = 0; index < byteCount; ++index) {
        const int keyIndex = index % keyLength;
        buffer[index] ^= m_encodeKey[keyIndex];
        buffer[index] ^= m_decodeKey[keyIndex];
    }
}
```

Reasons this is safe under the active code-entry gate:

- The target is reconstructable and has average `87.0` before this pass.
- The direct owner and emitter are already valid and above gate.
- The helper has exact bytes, exact three-call reachability, no callee complications, and no unresolved object ownership.
- The current support docs already resolve the class fields and cache context.
- The binary has no null-buffer guard and no zero-key guard; the draft intentionally does not add one.
- The binary mutates the buffer with two sequential XOR statements; the draft keeps two source statements instead of collapsing them into one combined-key XOR expression.

Source declaration note: `char*` and `int` are recommended for the formal method body. If the supervisor prefers external API polish, `std::size_t` may remain in caller prose, but the target body itself should document the signed byte-count behavior because the compiled helper uses signed comparison and signed modulo.

## Heuristic / Inference Reanalysis And Validation

### Compiler/generated names

Checked evidence:

- Exported function JSON names: `sub_422B30`, `meth_0x422b30`, `XOR_DecodeWithDualKey`.
- Generated `FittingRoom.cpp`, which currently omits this method and only contains an empty emitter marker.
- Target/support docs naming it `FittingRoomCatalogTransformPersistedBuffer` and constructor draft calling `TransformPersistedBuffer`.

Rejected alternatives:

- `sub_422B30` / `meth_0x422b30`: address-derived, not source-facing.
- `XOR_DecodeWithDualKey`: behaviorally incomplete because save calls encode through the same helper; "dual key" is descriptive but tool-generated.
- `DecodePersistedBuffer` / `DecodeCacheBuffer`: rejected because [UID:0002EF] uses the helper before writing.
- `EncryptPersistedBuffer`: rejected because it is not cryptographic strength and the helper also decodes.

Best defensible inference:

- Use `FittingRoomDialogItemState::TransformPersistedBuffer` as a descriptive neutral source name. It matches current support C++ and covers both directions of the reversible transform.

Impact:

- Score can rise above the old blocker. Original spelling remains inferred, so confidence should stop at `91`, not final-symbol quality.

### Field and type names

Checked evidence:

- [UID:0002E7] constructor key initialization.
- [UID:000051] field list.
- [UID:0000WN]/[UID:0002CZ] SSO-15 string support layout.
- Exported decompilation using `this+0x250`, `this+0x260`, `this+0x264`, `this+0x268`, and `this+0x27c`.

Rejected alternatives:

- Standalone key-length field at `+0x260`.
- Raw `char[24]` fields instead of `std::string`.
- Decode-key length as active modulo source.

Best defensible inference:

- `+0x250` is `std::string m_encodeKey`; `+0x260` is its length; `+0x264` is its capacity; `+0x268` is `std::string m_decodeKey`; `+0x27c` is its capacity. The body uses `m_encodeKey.length()` for both streams because the constructor gives equal-length strings.

Impact:

- Field/type blockers are resolved for this target. No source placement or split change required.

### Buffer and count signature

Checked evidence:

- IDA decompile: `_DWORD *this, int a2, int a3`.
- Ghidra decompile: `int param_1, int param_2`.
- Raw bytes: signed `cmp`/`jle` and signed `idiv`.
- Caller docs: constructor/reload pass heap file buffers; save passes a temporary mutable copy of a source string.

Rejected alternatives:

- `std::string&`: rejected because the helper receives a raw buffer pointer and byte count, not a string object.
- `const char*`: rejected because bytes are mutated in place.
- `size_t byteCount` as target-specific formal type: less faithful to the signed comparison/modulo in the target body.
- Non-void return: rejected because no callers consume the decompiler's `AL` artifact.

Best defensible inference:

- `void TransformPersistedBuffer(char* buffer, int byteCount)`.

Impact:

- Formal C++ is ready. The constructor draft should be adjusted from `static_cast<size_t>(fileLength)` to `static_cast<int>(fileLength)` for consistency.

### Caller/reachability

Checked evidence:

- Exported function JSON caller/xref set.
- Fresh raw `.text` `E8 rel32` scan.
- Fresh VA/RVA literal pointer scan.
- Existing target/caller pages.

Rejected alternatives:

- Callback/table-dispatched helper: no pointer/table hits.
- Dead helper: rejected because constructor and save have direct calls.
- Compiler/string helper: no broad caller set and no runtime helper shape.

Best defensible inference:

- Private product helper with exactly three direct call sites: constructor decode, save encode, no-caller reload decode.

Impact:

- Liveness is strong enough for source emission. [UID:0002EG]'s no-caller status remains its own source-shape issue, but it does not cap this helper.

### Owner/source route

Checked evidence:

- [UID:000051], [UID:0000WU], [UID:0000JE], [UID:0000KD]/[UID:00006T].
- Generated route in `auto-generated/NexusTK/cashshop/FittingRoom.cpp`.
- All direct callers and touched fields.

Rejected alternatives:

- Direct file owner [UID:0000JE]: too broad for direct owner.
- Aggregate [UID:0000WU]: address container, not semantic class owner.
- `ItemCatalog`: lookup facade only.
- Generic utility/crypto owner: no cross-feature route.
- Non-reconstructable/ignored: source-authored product helper.

Best defensible inference:

- Keep direct owner/emitter [UID:000051]; keep source-file route through [UID:0000JE] `NexusTK/cashshop/FittingRoom.cpp`.

Impact:

- Metadata owner/emitter do not change.

### Split/range decisions

Checked evidence:

- Fresh body bytes and SHA1.
- Pre-padding `0x00422b25-0x00422b30`.
- Post-padding `0x00422b93-0x00422ba0`.
- Successor category loader start at `0x00422ba0`.

Rejected alternatives:

- Merge into reload helper: rejected by eleven bytes of padding before and three independent callers.
- Merge into category loader: rejected by thirteen bytes of padding after and unrelated category-loader behavior.
- Split inside helper: no interior entry/xref, leaf loop is one coherent function.

Best defensible inference:

- Keep exact half-open range unchanged.

Impact:

- No split/rename/range repair recommended.

### First-draft C++ readiness

Checked evidence:

- Active code-entry gate in Supervisor policy.
- Target average `87.0`.
- Existing class/file/aggregate support docs.
- Sibling pages with first-draft constructor/parser C++ already using `TransformPersistedBuffer`.

Rejected alternatives:

- Withhold because exact original method name is unknown: rejected under current policy; descriptive names are allowed when evidence is strong and caveats are stated.
- Withhold because [UID:0002EF] remains blank: rejected; save helper's remaining consumed-buffer/wide-dispatch blockers are separate from this leaf helper.
- Emit no-code proof: no target-specific hard blocker remains.

Best defensible inference:

- Populate formal C++ for this target now.

Impact:

- Completion should increase to `88`; confidence to `91`. Generated output should include this method instead of an empty marker after supervisor incorporation/regeneration.

## Score / Metadata Recommendation

Recommended target metadata:

```text
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:000051 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:000051 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

No owner/emitter/range split changes are recommended.

Projected refreshed stats row:

```text
| `0002E8` | 88 | 91 | 89.5 | `by-memory/0x00422b30-0x00422b93.FittingRoomCatalogTransformPersistedBuffer.md` |
```

No class/file coverage score changes are required. [UID:000051], [UID:0000WU], and [UID:0000JE] are already high enough and mostly need support text cleanup rather than score movement.

## Support-Doc Update Plan

### Target [UID:0002E8]

Populate the formal C++ block with the first-draft code above.

Replace the current `Reconstruction Notes` section with:

```text
## Reconstruction Notes

Source should express this as `void FittingRoomDialogItemState::TransformPersistedBuffer(char* buffer, int byteCount)`. The helper mutates caller-owned bytes in place and returns no meaningful value; IDA's `char` return is only the last byte left in `AL`, and none of the three direct callers consume it.

Use the item-state fields resolved by the class and constructor pages: `m_encodeKey` at `+0x250`, `m_decodeKey` at `+0x268`, and `m_encodeKey.length()` at `+0x260`. The source draft should not introduce null-buffer or zero-key guards because the binary does not have them; constructed item-state objects seed both keys to equal-length non-empty strings.

The helper is source-ready under the active code-entry gate. Exact original spelling remains inferred, but the behavior, owner, signature shape, field names, caller set, and range are now source-quality.
```

Replace the current `Score Rationale` section with:

```text
## Score Rationale

- Completion is `88` because B005 2026-06-19 resolves the source-facing helper signature, field names, key-length interpretation, caller-owned buffer type, return policy, owner/source route, and first-draft C++ readiness while preserving exact range, padding, leaf/no-callee behavior, and three-call reachability.
- Confidence is `91` because the transform is corroborated by exported IDA/Ghidra function JSON, accepted constructor/save/reload docs, class field documentation, raw PE bytes, direct `E8` call scanning, no VA/RVA pointer hits, and current generated-output route. It remains below final-symbol quality because the original method spelling and exact source typedef for the signed byte count are inferred.
```

Add a `Changes` entry:

```text
- 2026-06-19 B005 source-quality pass: Raise to `88/91`, populate first-draft `FittingRoomDialogItemState::TransformPersistedBuffer(char* buffer, int byteCount)` C++, resolve `m_encodeKey`/`m_decodeKey`/`m_encodeKey.length()` field interpretation, confirm signed byte-count and void-return policy, validate raw PE bytes/SHA1, re-scan direct calls and VA/RVA pointer routes, keep owner/emitter [UID:000051], and retire the stale field/signature C++ blocker.
```

### [UID:000051] FittingRoomDialogItemState

Placement: after the existing source-facing item-state fields bullet in `Notable Data`, add:

```text
- [UID:0002E8][0x00422b30-0x00422b93.FittingRoomCatalogTransformPersistedBuffer](by-memory/0x00422b30-0x00422b93.FittingRoomCatalogTransformPersistedBuffer.md) is source-ready as `void TransformPersistedBuffer(char* buffer, int byteCount)`. It mutates caller-owned `ItemShop.jbn` bytes in place, uses `m_encodeKey.length()` at `+0x260` as the modulo divisor, selects SSO/heap storage for `m_encodeKey` and `m_decodeKey`, and applies the same reversible two-key XOR transform for decode-on-read and encode-on-write.
```

### [UID:0000WU] FittingRoomItemShopCatalogState

Placement: in `B001 2026-06-18 Source-Quality Incorporation`, after the paragraph listing populated method-child C++ pages, add:

```text
B005 2026-06-19 resolves [UID:0002E8][0x00422b30-0x00422b93.FittingRoomCatalogTransformPersistedBuffer](by-memory/0x00422b30-0x00422b93.FittingRoomCatalogTransformPersistedBuffer.md) as source-ready `FittingRoomDialogItemState::TransformPersistedBuffer(char* buffer, int byteCount)`. The helper remains an item-state child, not an aggregate-owned monolithic body; aggregate blockers remain raw no-caller cache helper liveness at `0x00422920`/`0x004229f0`, optional `ItemCatalog` facade split, and exact original typedef spelling.
```

### [UID:0000JE] FittingRoom

Placement: after the `FittingRoomDialogItemState` bullet in `Likely Contents`, add:

```text
- 2026-06-19 B005 source-quality reanalysis resolves the item-state cache transform helper [UID:0002E8][0x00422b30-0x00422b93.FittingRoomCatalogTransformPersistedBuffer](by-memory/0x00422b30-0x00422b93.FittingRoomCatalogTransformPersistedBuffer.md) as first-draft C++ ready under `FittingRoomDialogItemState` in this file. The helper applies the reversible encode/decode transform for `ItemShop.jbn`; it is not an `ItemCatalog`, generic crypto, or runtime helper owner.
```

### [UID:0002EF] SaveEncodedStateBuffer

Placement: append to `Reconstruction Notes`:

```text
B005 2026-06-19 resolves the transform helper signature used at `0x00422618` as `FittingRoomDialogItemState::TransformPersistedBuffer(char* buffer, int byteCount)`. This should no longer be listed as a blocker for this save helper. Remaining save-helper C++ blockers are the consumed source-buffer parameter spelling/source wrapper, the final `_wfopen` dispatch wrapper shape, and the exact source policy for the unconditional `m_cacheLoaded` store.
```

### [UID:0002EG] LoadEncodedCacheFile

Placement: append to `Reconstruction Notes`:

```text
B005 2026-06-19 resolves the decode call at `0x00422a9b` as `FittingRoomDialogItemState::TransformPersistedBuffer(char* buffer, int byteCount)`. This helper's no-caller/source-retention issue remains separate; the transform dependency itself is now source-quality and should not block [UID:0002E8]'s formal C++.
```

## Exact by-memory/-coverage-report.md Replacement Row

Placement context: replace only the [UID:0002E8] row inside the [UID:0000WU] `FittingRoomItemShopCatalogState` nested block. Keep the surrounding padding rows unchanged.

```text
            - [UID:0002E8][0x00422b30-0x00422b93.FittingRoomCatalogTransformPersistedBuffer](by-memory/0x00422b30-0x00422b93.FittingRoomCatalogTransformPersistedBuffer.md) 0x00422b30-0x00422b93 | method | FittingRoomCatalogTransformPersistedBuffer : reconstructable : 88% : very-strong : B005 2026-06-19 source-quality pass confirms exact `0x63` leaf bounds, raw bytes/SHA1, eleven-byte pre-padding and thirteen-byte post-padding, exactly three direct rel32 call sites from constructor/save/reload paths, no VA/RVA pointer refs, no callees, signed byte-count/`char *` thiscall signature, item-state-owned `m_encodeKey`/`m_decodeKey` fields at `+0x250/+0x268`, SSO length/capacity offsets, symmetric in-place two-key XOR transform for `ItemShop.jbn`, and first-draft `FittingRoomDialogItemState::TransformPersistedBuffer` C++ readiness.
```

## Generated Output Expectation

After supervisor incorporation and regeneration, `auto-generated/NexusTK/cashshop/FittingRoom.cpp` should no longer show:

```text
// UID:0002E8 | by-memory\0x00422b30-0x00422b93.FittingRoomCatalogTransformPersistedBuffer.md | Completion:84 | Confidence:90 | Empty Emitter Marker
```

It should contain the first-draft method body near the other `FittingRoomDialogItemState` methods. Existing constructor draft calls should be updated to use `static_cast<int>(fileLength)` for the transform helper's signed byte-count signature.

## Validation / Commands

Commands/evidence used:

- `rg -n "0002E8|FittingRoomCatalogTransformPersistedBuffer|FittingRoomItemShopCatalogState|ItemShop\.jbn|CASHEncodeDecodeByChris|0002E7|0002EF|0002EG" ...`
- `rg -n "UID:000051|FittingRoomDialogItemState|FittingRoom" ...`
- `rg -n "0002E8|0x00422b30|FittingRoomCatalogTransformPersistedBuffer" project-level/-auto-completion-stats.md by-memory/-coverage-report.md`
- `Get-Content` on the target and support docs listed above.
- `Get-Content` on `resources/exported_data/functions/0x00422b30.json`, `0x004225a0.json`, and `0x004229f0.json`.
- Direct MCP endpoint probe: unavailable.

> The removed literal PowerShell command is preserved only in [0002E8-FittingRoomCatalogTransformPersistedBuffer-source-quality-removed.md](0002E8-FittingRoomCatalogTransformPersistedBuffer-source-quality-removed.md). The archive is non-authoritative and must not be executed.
- PowerShell PE byte audit against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`: confirmed raw offset, body bytes, SHA1, and padding.
- PowerShell `.text` `E8 rel32` and VA/RVA literal scan: confirmed call hits at `0x00422292`, `0x00422618`, `0x00422a9b`; no VA/RVA pointer hits.
- `Test-Path` confirmed no pre-existing B005 report at the required report path before writing this file.

Validation not run:

- No by-* validator was run because this is report-only and no target/support docs were edited.
- No generated-output regeneration was run because this report does not modify source docs.

## Changed Files

Report-only change:

- `tools/leaser/Agents/Agent-B005/research/0002E8-FittingRoomCatalogTransformPersistedBuffer-source-quality.md`

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000004165","destination_path":"executed-b-agent-research/B005/0002E8-FittingRoomCatalogTransformPersistedBuffer-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:31","uid":"0002E8"} -->
<!-- {"agent":"B005","command_id":"000000023047","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002E8-FittingRoomCatalogTransformPersistedBuffer-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B005/0002E8-FittingRoomCatalogTransformPersistedBuffer-source-quality.md","timestamp":"2026-08-13T02:36:38-04:00","uid":"0002E8"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
