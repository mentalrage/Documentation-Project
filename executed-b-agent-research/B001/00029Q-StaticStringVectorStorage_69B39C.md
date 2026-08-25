** TARGET-REPORT-UID:00029Q **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# [UID:00029Q] StaticStringVectorStorage_69B39C Ownership Research

Revision: B001-049, 2026-06-11

## Final Recommendation

Keep [UID:00029Q][0x0069b39c-0x0069b3a8.StaticStringVectorStorage_69B39C](../../../../../by-memory/0x0069b39c-0x0069b3a8.StaticStringVectorStorage_69B39C.md) as an exact, parent-blank, reconstructable static-storage child:

- `RECONSTRUCTABLE:TRUE`
- current score remains defensible at `85/92`
- no `AUTOGEN_PARENT_UID`
- no split
- no `by-memory/-coverage-report.md` replacement row required from this B001 pass

This is not a shallow "unknown owner" result. The best evidence-backed source-layout inference is that `0x0069b39c-0x0069b3a8` is a file-scope static vector control block for 24-byte inline UTF-16/SSO string objects, emitted only through static-lifetime destructor registration in this binary. The binary does not expose a normal user, constructor call, pointer-table entry, vtable relationship, broad startup zeroing write, source metadata string, or neighboring owner pattern strong enough to attach the storage to an existing source owner.

Best owner inference if forced to name a source cluster: a private string/static-lifetime declaration near the same broad utility-string object-file cluster as `g_emptySimpleUString`, with [UID:0000OB][StringUtil](../../../../../by-file/StringUtil.md) as the strongest type-family context. Confidence for that as the direct declaration owner is only `60/100`, below the assignment threshold. `StringUtil` owns the string layout/helpers, but current evidence does not prove it declared this static vector. Treat it as a type dependency, not a direct parent.

Concrete supervisor/A-agent action:

- Do not attach `00029Q` to `StringUtil`, `SimpleUStringVector`, `MemoryMan`, `TimerMgr`, `MainMenuPane`, `MapPane`, `Surface`, or the static initializer/cleanup wrapper pages.
- Do not split the 12-byte range into three dword children; all three fields are one vector object.
- If a semantic by-global anchor is desired later, create a narrow parent such as `StaticStringVector_69B39C` / `g_staticStringVector_69B39C` that owns only this storage and records the static destructor evidence. Leave that new global's source-root parent blank unless new normal-use evidence appears. Do not create a standalone `StringVectorGlobals.cpp` or assign to `StringUtil.cpp` merely from string type similarity.
- Preserve the current coverage-row meaning: reviewed, reconstructable, child gate cleared, parent blank because positive evidence supports only static-lifetime string-vector storage and negative evidence rejects the plausible existing owners.

Rejected alternatives:

- `StringUtil` / `SimpleUString`: strongest type-family context, but no direct user or declaration proof; existing `SimpleUStringVector` docs model a 4-byte string-handle vector, while this target is a 24-byte inline string-element vector.
- `g_emptySimpleUString`: adjacent startup/cleanup sibling and same SSO reset semantics, but it is a different 24-byte object with many normal users and an attached StringUtil route; this target has no normal users.
- `MemoryMan` and `TimerMgr`: immediate successors in `.data` and startup order, but each has its own constructor/destructor refs and separate child pages.
- `MainMenuTextUrlStaticString`: nearby string/static-lifetime object, but it has six normal refs across MainMenu, MapPane, auth/update, startup, and cleanup; this target does not share those refs.
- static initializer/cleanup wrapper pages: compiler/linker glue, not source owners for the backing storage.

## Supporting Research

### Target

- Target UID: `00029Q`
- Target path: `by-memory/0x0069b39c-0x0069b3a8.StaticStringVectorStorage_69B39C.md`
- Supervisor status: `reviewed-85-but-ownership-unknown-under-review`
- Current child state: `RECONSTRUCTABLE:TRUE`, `COMPLETION:85`, `CONFIDENCE:92`, parent blank

### IDA MCP Environment

Live IDA MCP was used read-only against:

- Image: `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`
- Base: `0x00400000`
- MD5: `4247e04e20b65d6414c7238aa8ff5515`
- SHA-256: `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`

No by-* project docs or coverage reports were edited.

### Confirmed Binary Facts

The target bytes are exactly:

```text
0x0069b39c: ff ff ff ff ff ff ff ff ff ff ff ff
```

IDA names and field roles:

| Address | IDA name | Initial dword | Cleanup refs | Inferred role |
| --- | --- | ---: | --- | --- |
| `0x0069b39c` | `dword_69B39C` | `0xffffffff` | `0x0060c161`, `0x0060c1d3`, `0x0060c21c` | begin pointer |
| `0x0069b3a0` | `dword_69B3A0` | `0xffffffff` | `0x0060c170`, `0x0060c226` | end pointer |
| `0x0069b3a4` | `dword_69B3A4` | `0xffffffff` | `0x0060c1d9`, `0x0060c230` | capacity/end pointer |

The only operand hits for the exact target addresses are the seven instructions above in `sub_60C160`. A raw little-endian address scan over loaded segments also found the target addresses only inside those same `sub_60C160` instruction encodings. No data pointer, jump table, vtable, or other code/data reference points to the storage.

`sub_60C160` is the static cleanup body. Disassembly/decompilation shows:

- load `dword_69B39C`, return only if it is zero;
- walk `[begin, end)` in `0x18`-byte elements;
- for each element, treat offset `+0x10` as length and `+0x14` as capacity, freeing heap-backed string storage when capacity is at least `8`;
- reset each string to empty SSO state (`length = 0`, `capacity = 7`, first word cleared);
- free the backing vector allocation using `capacity - begin`;
- clear all three vector fields to zero.

This is a vector of 24-byte inline string objects, not the documented `SimpleUStringVector` 4-byte string-handle-slot layout.

### Static-Lifetime Evidence

The cleanup body has only one registration:

- `0x00419f40`: `push offset sub_60C160; call _atexit; retn`
- raw pointer to `0x0060c160`: only at `0x00419f41`
- pointer to wrapper `0x00419f40`: only startup table slot `0x0060d6b0`

Nearby startup table slots:

| Slot | Function | First action | Interpretation |
| --- | --- | --- | --- |
| `0x0060d6ac` | `0x00419f20` | constructs `dword_66DAEC`, registers `0x0060c100` | `g_emptySimpleUString` startup |
| `0x0060d6b0` | `0x00419f40` | registers `0x0060c160` only | this target's cleanup registration |
| `0x0060d6b4` | `0x00419f70` | constructs `dword_69B3A8` | MemoryMan static object |
| `0x0060d6b8` | `0x00419f90` | constructs `dword_69B3AC` | TimerMgr static object |
| `0x0060d6bc` | `0x00419f50` | constructs `dword_69B3D0` | MainMenu/auth URL static string |

The startup island is mixed. It places string-like, MemoryMan, TimerMgr, and MainMenu/auth statics next to each other, so startup order is a weak source-owner clue. It does support a string/static-lifetime type-family inference, but it does not identify the declaration owner.

The paired cleanup island is also mixed:

- `0x0060c100`: destroys `g_emptySimpleUString`.
- `0x0060c160`: destroys this 24-byte string-element vector.
- `0x0060c250`: destroys `dword_69B3D0`, the MainMenu/auth URL static string.
- `0x0060c260+`: MemoryMan/TimerMgr and later unrelated static destructor wrappers.

### Broad-Write / Hidden-Initializer Check

The all-`0xffffffff` image is important because `sub_60C160` tests `begin != 0`, not `begin != -1`. If the triple remained unchanged to normal static shutdown, the cleanup path would not treat it as empty. I checked for hidden broad writes so this report would not incorrectly claim "no initializer" from only direct xrefs.

IDA MCP checks performed:

- exact xrefs to `0x0069b39c`, `0x0069b3a0`, and `0x0069b3a4`;
- executable operand scan for the exact target fields;
- raw address scan for the three fields, `0x0060c160`, and `0x00419f40`;
- scan for `_memset`, `_memmove`, `_memcpy_s`, and related call contexts whose setup operands reference the `0x0069b300-0x0069b3af` window;
- scan of inline `rep stos*` contexts for setup operands referencing the same window;
- fixup/relocation scan around the target, wrapper, cleanup body, and startup table.

Results:

- no `_memset`/`_memmove`/`_memcpy_s` call context references the target neighborhood;
- no inline `rep stos*` context references the target neighborhood;
- no fixups/relocations were found near the target or its wrapper/cleanup contexts;
- no constructor, assignment, bulk zeroing, or pointer-table initializer was found for the vector triple.

Inference: the binary evidence supports "registered cleanup for otherwise unreferenced static vector storage" rather than "normal vector object with an IDA-missed initializer." The unresolved runtime implication should stay documented; it is not evidence for any existing source owner.

### Boundary And Split Analysis

Do not split `00029Q`:

- The three dwords are consumed together by one destructor as begin/end/capacity.
- The stride and capacity math use the full triple.
- `0x0069b381-0x0069b398` has no refs in the checked predecessor padding region.
- `0x0069b3a8` starts the separate [UID:00029R][MemoryManStaticObjectStorage](../../../../../by-memory/0x0069b3a8-0x0069b3ac.MemoryManStaticObjectStorage.md), with refs only from `0x00419f70` and `0x0060c260`.
- `0x0069b3d0` starts the separate [UID:00029T][MainMenuTextUrlStaticString](../../../../../by-memory/0x0069b3d0-0x0069b3d4.MainMenuTextUrlStaticString.md), with normal refs at startup, cleanup, MainMenu packet handling, MapPane packet handling, and auth/update URL reading.

The local `.data` region is a mixed initialized-data island. Nearby address ownership is not reliable enough to infer a parent.

### Documentation Evidence Checked

Existing docs used as leads, not authority:

- The target page already records `85/92`, all-`0xffffffff` bytes, cleanup-only refs, and parent blank. Live IDA confirmed these facts.
- [UID:00024F][StaticStringContainerCleanupThunks](../../../../../by-memory/0x0060c100-0x0060c260.StaticStringContainerCleanupThunks.md) correctly describes `0x0060c160` as vector-like cleanup and says the backing global needs owner research. Live IDA confirmed the body and registration.
- [UID:0000W9][StaticInitializerWrappersAfterOle](../../../../../by-memory/0x00419ef4-0x00419f70.StaticInitializerWrappersAfterOle.md) correctly describes `0x00419f40` as cleanup registration only. Live IDA confirmed no constructor call in that wrapper.
- [UID:0000OB][StringUtil](../../../../../by-file/StringUtil.md) is the strongest string type-family context, but its documented `SimpleUStringVector` is a 4-byte pointer-backed string-handle vector. This target's destructor walks 24-byte inline SSO string objects.
- [UID:0000PW][g_emptySimpleUString](../../../../../by-global/g_emptySimpleUString.md) is a true StringUtil global with normal users. Its adjacency to this target supports only a weak string/static-lifetime cluster inference.
- [UID:00029R][MemoryManStaticObjectStorage](../../../../../by-memory/0x0069b3a8-0x0069b3ac.MemoryManStaticObjectStorage.md), [UID:00029S][TimerMgrStaticObjectStorage](../../../../../by-memory/0x0069b3ac-0x0069b3d0.TimerMgrStaticObjectStorage.md), and [UID:00029T][MainMenuTextUrlStaticString](../../../../../by-memory/0x0069b3d0-0x0069b3d4.MainMenuTextUrlStaticString.md) show that neighboring statics receive assignment only when constructor/use evidence identifies a real owner.

No older report, proposed-source-tree entry, project-level source metadata, or A-agent note introduced an additional owner lead beyond the cleanup/static-lifetime facts.

### Source Metadata Check

IDA string/raw scans found no useful original-source metadata:

- no `RSDS`;
- no `NB10`;
- no `.pdb`;
- no `.cpp` / `.cxx` source path strings.

The only string hits from the broad debug/source token scan were generic runtime/API/resource strings such as `IsDebuggerPresent` and C runtime error text. Therefore this report cannot claim original source-file proof from PDB, CodeView, linker map, or path strings.

### Ranked Ownership Analysis

#### 1. Parent-blank static vector storage, with StringUtil as type context

Recommendation rank: best current disposition.

Evidence for:

- The storage is source-declared/static-lifetime-like because a destructor is registered through the startup table.
- The destructor proves a 24-byte string-element vector layout.
- There are no normal consumers, no constructor, no pointer table, no direct writes, and no broad write context.
- Existing assignable neighbors have stronger owner evidence; this one does not.

Evidence against:

- It leaves the parent blank, which is mechanically less satisfying than assigning an existing owner.
- The startup/cleanup position beside `g_emptySimpleUString` gives a real but weak StringUtil/source-cluster clue.

Conclusion: keep parent blank and document that the best source-layout inference is "orphan/static string-vector storage emitted for static lifetime, declaration owner not recoverable from current binary evidence."

Confidence: `85/100` for disposition, `92/100` for storage/layout, `60/100` for StringUtil-like declaration cluster.

#### 2. [UID:0000OB] StringUtil

Evidence for:

- The element destructor uses SSO-7/UTF-16 string semantics aligned with the broader StringUtil/SimpleUString family.
- The startup/cleanup wrapper is immediately after the `g_emptySimpleUString` startup/cleanup pair.
- No application-module consumer exists, which makes a utility/static support declaration plausible.

Evidence against:

- No direct user, constructor, caller, or source metadata ties this static vector to `StringUtil.cpp`.
- String type ownership is not the same as owning every static container that stores strings.
- Existing `SimpleUStringVector` docs describe a different vector representation.
- The same cleanup/startup island contains MainMenu/auth string and MemoryMan/TimerMgr statics, proving the island is not one source owner.

Conclusion: strongest type-family context, not a direct parent.

Confidence as direct parent: `60/100`.

#### 3. `g_emptySimpleUString`

Evidence for:

- Immediate startup/cleanup sibling.
- Same string reset/free family.

Evidence against:

- `g_emptySimpleUString` is a single 24-byte fallback object at `0x0066daec`, not this vector.
- It has broad normal users and a well-supported StringUtil route; this target has no normal users.
- Merging the target into that global would conflate two different static objects.

Conclusion: sibling/type lead only; reject as parent.

Confidence as direct parent: `25/100`.

#### 4. MemoryMan / TimerMgr

Evidence for:

- Immediate `.data` successors and adjacent startup table entries.

Evidence against:

- Their storage has independent constructor/destructor refs and object-specific behavior.
- No target refs occur in MemoryMan or TimerMgr methods.
- Startup order interleaves unrelated statics.

Conclusion: reject.

Confidence as direct parent: `10/100`.

#### 5. MainMenu/auth URL static string

Evidence for:

- Same broad string/static-lifetime neighborhood.
- Nearby `0x0069b3d0` is a string/static object.

Evidence against:

- `0x0069b3d0` has normal refs in MainMenu packet, MapPane packet, and auth/update URL logic; none touch this target.
- MemoryMan and TimerMgr entries sit between the target wrapper and `0x00419f50`.

Conclusion: reject.

Confidence as direct parent: `15/100`.

#### 6. Compiler/static initializer or cleanup wrapper pages

Evidence for:

- They are the only direct code touching the target.

Evidence against:

- They are compiler/linker-generated static-lifetime glue.
- The source owner of a static object is the backing declaration, not the emitted atexit wrapper.

Conclusion: reject as source parent; keep cross-links only.

Confidence as direct parent: `0/100`.

### Validation / Edit Status

- No by-* documentation page was edited.
- No `by-memory/-coverage-report.md` edit was made.
- No validator run was required for project docs because this pass only adds a B001 research report.
- Changed file: `tools/leaser/Agents/Agent-B001/research/00029Q-StaticStringVectorStorage_69B39C.md`
- Leases used: none; no existing leased project documentation file was modified.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/00029Q-StaticStringVectorStorage_69B39C.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:21","uid":"00029Q"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
