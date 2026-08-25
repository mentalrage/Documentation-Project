** TARGET-REPORT-UID:0001B7 **
** AUTHOR-AGENT-ID:B007 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B007 Report - [UID:0001B7] Md5BytesHex Source Quality

Report-only pass for `B007-report-0001B7-md5-bytes-hex-source-quality-20260626`.

Target: `by-memory/0x00515310-0x00515375.Md5BytesHex.md`

Report path: `tools/leaser/Agents/Agent-B007/research/0001B7-Md5BytesHex-source-quality.md`

## Recommendation

Update [UID:0001B7] from `85/88` to `89/91`, keep `CANONICAL_OWNER:0000L6`, keep `RECONSTRUCTABLE:TRUE`, and keep `EMITTER_UIDS:0000L6`.

Insert formal first-draft C++ into the target's managed `RECONSTRUCTION_CPP CODE` block. The old blank-C++ reason is now stale: the raw start still has no IDA function object and no caller route, but the sibling [UID:0001B8] file-path helper has already established that the raw/no-route condition is a liveness and confidence cap when the body is complete, unique, source-shaped, and owner-routed. This target meets that same standard with a smaller and more direct body.

Do not raise the aggregate MD5 helper page or broad MD5 file page to final C++. They should remain blank at aggregate/file level because `Md5BytesRaw` still needs a source-quality representation of the transient stack-digest return, the endian encode/decode helpers remain no-route/no-signature helpers, and exact original `MD5Context`/method/member spelling is still inferred.

## Evidence Sources

- Project instructions: project-level `ntk-b-agent-workflow` skill, `by-structure.md`, `by-memory/-guidance.md`, `by-file/-guidance.md`, and `by-item/-guidance.md`.
- Target and support docs read in this pass:
  - `by-memory/0x00515310-0x00515375.Md5BytesHex.md`
  - `by-memory/0x005151f0-0x00515f48.MD5HashHelpers.md`
  - `by-file/MD5.md`
  - `by-item/PacketDigest_00515380.md`
  - `by-memory/0x00515450-0x00515568.Md5FilePathHex.md`
  - `by-memory/0x0061ead4-0x0061eadc.Md5HexFormatString.md`
  - `by-memory/0x0066ddd8-0x0066de18.Md5PaddingBlock.md`
  - `by-memory/0x00515f50-0x00515ff2.MD5EndianEncodeDecodeHelpers.md`
- Mandatory IDA MCP: session `80de0a67`, database path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.
- Supplemental read-only PE route scan: `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`.
- Numeric conversions marked below were verified with `tools/int_convert.py` using `python .\tools\int_convert.py --text <value> --size 2 --single`.

## MCP Session

`server_health` on session `80de0a67` returned `status:"ok"` for module `NexusTK.exe`, IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, and `strings_cache_ready:true`.

MCP tools used for this report: `server_health`, `lookup_funcs`, `xrefs_to`, `get_bytes`, `decompile`, `insn_query`, `analyze_function`, `make_signature_for_range`, `get_string`, and `int_convert`.

## Current Target State

Current target metadata:

- `COMPLETION:85`
- `CONFIDENCE:88`
- `CANONICAL_OWNER:0000L6`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000L6`
- Formal C++ block: blank.

The page already records strong raw-body evidence, but the reconstruction notes still say to keep C++ blank until a stable source-level signature and caller caveat are resolved. That is the main stale assumption. Current MCP evidence and the accepted [UID:0001B8] raw-helper policy support target-level emission while preserving the no-function/no-route caveat as a score cap.

## Function And Boundary Evidence

`lookup_funcs` reconfirmed the exact MD5 island split:

| Address | MCP result | Meaning |
| --- | --- | --- |
| `0x005151f0` | `sub_5151F0`, size `0x94` = 148 bytes (Verified with `tools/int_convert.py`) | `Md5DigestToHexString` modeled helper. |
| `0x00515290` | `sub_515290`, size `0x7a` = 122 bytes (Verified with `tools/int_convert.py`) | `Md5StringHex` modeled helper. |
| `0x0051530a` | not a function | Start of alignment after `Md5StringHex`. |
| `0x00515310` | not a function | Raw target start. |
| `0x00515374` | not a function | Raw target `retn` byte. |
| `0x00515375` | not a function | First post-body alignment byte. |
| `0x00515380` | `sub_515380`, size `0x5c` = 92 bytes (Verified with `tools/int_convert.py`) | Packet-facing raw digest helper. |
| `0x005153e0` | `sub_5153E0`, size `0x65` = 101 bytes (Verified with `tools/int_convert.py`) | Bytes-to-caller-buffer digest helper. |
| `0x00515450` | not a function | Raw file-path-to-hex sibling. |
| `0x00515570` | `sub_515570`, size `0xeb` = 235 bytes (Verified with `tools/int_convert.py`) | Stream-to-hex modeled sibling. |
| `0x00515690` | `sub_515690`, size `0xb4` = 180 bytes (Verified with `tools/int_convert.py`) | `Md5Update` context method. |
| `0x00515750` | `sub_515750`, size `0xe1` = 225 bytes (Verified with `tools/int_convert.py`) | `Md5Final` context method. |
| `0x00515840` | `sub_515840`, size `0x708` = 1800 bytes (Verified with `tools/int_convert.py`) | `Md5Transform`. |
| `0x00515f50` | not a function | Raw endian-helper sibling, outside this target. |

`get_bytes` and `insn_query` prove this exact boundary:

| Range | Bytes/instructions | Conclusion |
| --- | --- | --- |
| `0x00515300-0x00515309` | tail of `sub_515290`: `pop esi`, security-cookie check, `mov esp, ebp`, `pop ebp`, `retn` | Previous modeled string wrapper ends before the target. |
| `0x0051530a-0x00515310` | six `0xcc` bytes, rendered as `align 10h` | Pre-target padding; not part of target. |
| `0x00515310-0x00515375` | raw prologue/body/epilogue, unique range signature, size `0x65` = 101 bytes (Verified with `tools/int_convert.py`) | Complete function-shaped `Md5BytesHex` body. |
| `0x00515374` | `retn` | Last instruction in target body. |
| `0x00515375-0x00515380` | eleven `0xcc` bytes, `0x0b` = 11 (Verified with `tools/int_convert.py`) | Post-target padding before `PacketDigest_00515380`; not source logic. |
| `0x00515380` | modeled `sub_515380` start | Next helper is separate. |

`make_signature_for_range 0x00515310-0x00515375` returned a unique IDA signature:

`55 8B EC 83 EC 70 A1 ? ? ? ? 33 C5 89 45 ? FF 75 ? 8B 45 ? 8D 4D ? 0F 57 C0 C7 45 ? ? ? ? ? 50 66 0F D6 45 ? C7 45 ? ? ? ? ? C7 45 ? ? ? ? ? C7 45 ? ? ? ? ? E8 ? ? ? ? 8D 4D ? E8 ? ? ? ? 8D 45 ? 50 E8 ? ? ? ? 8B 4D ? 83 C4 04 33 CD E8 ? ? ? ? 8B E5 5D C3`

`make_signature_for_range 0x00515375-0x00515380` returned `CC CC CC CC CC CC CC CC CC CC CC` and `unique:false`, proving the post-body bytes are normal alignment padding.

## Target Instruction Facts

`insn_query 0x0051530a-0x00515380` produced the target stream with `fn:null` for every target instruction:

| Address | Instruction | Source meaning |
| --- | --- | --- |
| `0x00515310` | `push ebp`; `mov ebp, esp`; `sub esp, 70h` | Stack frame `0x70` = 112 bytes (Verified with `tools/int_convert.py`). |
| `0x00515316-0x0051531d` | security-cookie load/xor/store | Compiler artifact; omit from source C++. |
| `0x00515320` | `push dword ptr [ebp+0Ch]` | Pushes byte count argument. |
| `0x00515323` | `mov eax, [ebp+8]` | Loads source byte pointer argument. |
| `0x00515326` | `lea ecx, [ebp-70h]` | `this` pointer for stack `MD5Context`. |
| `0x00515329` | `xorps xmm0, xmm0` | Prepares zero. |
| `0x0051532c` | `mov [ebp-70h], 67452301h` | MD5 state word 0. |
| `0x00515333` | `push eax` | Pushes source byte pointer. |
| `0x00515334` | `movq [ebp-60h], xmm0` | Clears bit-count pair. Offset `0x10` = 16 bytes from context base (Verified with `tools/int_convert.py`). |
| `0x00515339` | `mov [ebp-6Ch], 0EFCDAB89h` | MD5 state word 1. |
| `0x00515340` | `mov [ebp-68h], 98BADCFEh` | MD5 state word 2. |
| `0x00515347` | `mov [ebp-64h], 10325476h` | MD5 state word 3. |
| `0x0051534e` | `call sub_515690` | Calls `Md5Update(context, bytes, byteCount)`. |
| `0x00515353-0x00515356` | `lea ecx, [ebp-70h]`; `call sub_515750` | Calls `Md5Final(context)`. |
| `0x0051535b-0x0051535f` | `lea eax, [ebp-18h]`; `push eax`; `call sub_5151F0` | Passes final digest at context offset `0x58` = 88 bytes (Verified with `tools/int_convert.py`) to `Md5DigestToHexString`. |
| `0x00515364-0x0051536c` | stack-cookie check setup and call | Compiler artifact; omit from source C++. |
| `0x00515371-0x00515374` | epilogue and `retn` | End of source helper. |

`decompile 0x00515310` failed with `Decompilation failed at 0x515310`, which is expected because IDA has no function object at the target start. This is not a behavior blocker because `insn_query`, `get_bytes`, xrefs into the callees, and sibling decompilations prove the body.

## Xrefs And Route Evidence

MCP `xrefs_to`:

- `xrefs_to 0x00515310`: none.
- `xrefs_to 0x00515374`: one local code xref at `0x515373` because the raw epilogue falls through to `retn`; this is not an inbound function route.
- `xrefs_to 0x00515375`: none.
- `xrefs_to 0x00515380`: one modeled caller at `0x00578da5` inside `sub_578C40`, proving the next helper is independently live.
- `xrefs_to 0x005151f0`: four call sites: `0x005152f3` from `Md5StringHex`, `0x0051535f` from this raw target with `fn:null`, `0x00515540` from the raw file-path helper with `fn:null`, and `0x00515630` from `Md5StreamHex`.
- `xrefs_to 0x00515690`: includes `0x0051534e` from this raw target with `fn:null`, plus modeled and raw sibling calls.
- `xrefs_to 0x00515750`: includes `0x00515356` from this raw target with `fn:null`, plus modeled and raw sibling calls.

Supplemental read-only PE route scan found:

| Target | VA pointer hits | RVA pointer hits | Direct `E8/E9` rel32 hits |
| --- | --- | --- | --- |
| `0x00515310` | none | none | none |
| `0x00515450` | none | none | none |
| `0x00515380` | none | none | `0x00578da5:E8` |
| `0x00515570` | none | none | `0x00558278:E8` |
| `0x005151f0` | none | none | `0x005152f3:E8`, `0x0051535f:E8`, `0x00515540:E8`, `0x00515630:E8` |
| `0x00515690` | none | none | all expected MD5 update calls, including `0x0051534e:E8` |
| `0x00515750` | none | none | all expected MD5 final calls, including `0x00515356:E8` |

This scan is meaningful negative evidence: it finds the normal direct routes for modeled live siblings and for this raw body's outgoing calls, but finds no inbound call, jump, absolute VA pointer, or RVA pointer to the raw start `0x00515310`.

## Modeled Sibling Evidence

`analyze_function 0x005151f0` decompiles `sub_5151F0` as `char *__cdecl(int)`:

- It clears a 256-byte local source buffer, iterates `i < 16`, formats each digest byte with `%02x`, appends with `strncat_s`, and returns `_strdup(Source)`.
- MCP `get_string` confirms `0x0061ead4` is `%02x`.
- `xrefs_to 0x0061ead4` reports the only direct data xref at `0x00515235` inside this formatter.

`analyze_function 0x00515290` decompiles `sub_515290` as `char *__cdecl(char *Src)`:

- It initializes the same MD5 state constants and count pair, calls `sub_515690(v2, Src, strlen(Src))`, calls `sub_515750(v2)`, and returns `sub_5151F0((int)v4)`.
- This is the string-to-hex sibling and establishes the heap-hex return convention.

`analyze_function 0x00515380` decompiles `sub_515380` as `char *__cdecl(char *Src, unsigned int)`:

- It initializes the same MD5 state constants and count pair, calls `sub_515690(v3, Src, a2)`, calls `sub_515750(v3)`, and returns `&v5`.
- This proves the byte pointer plus unsigned length signature shape, while also showing the separate raw-digest return behavior that remains unsafe/unresolved for final C++.

`analyze_function 0x005153e0` decompiles `sub_5153E0` as `void *__cdecl(char *Src, unsigned int, _OWORD *)`:

- It initializes the same MD5 state constants and count pair, updates/finalizes, copies the 16-byte digest to a caller output buffer, and returns the finalization result.
- This is the bytes-to-caller-buffer sibling and confirms the byte pointer plus unsigned length convention.

`analyze_function 0x00515570` decompiles `sub_515570` as `char *__cdecl(FILE *Stream)`:

- It initializes the same MD5 state constants and count pair, zeroes a `0x400` = 1024-byte file buffer (Verified with `tools/int_convert.py`), reads chunks with `fread`, calls `sub_515690`, calls `sub_515750`, and returns `sub_5151F0((int)v5)`.
- It returns the fallback literal when `Stream` is null. MCP `get_string` confirms `0x0061eadc` is `"000011112222333344445555666677778888"`, and `xrefs_to 0x0061eadc` reports only `0x00515559` in the raw file helper and `0x0051564a` in `Md5StreamHex`.

`analyze_function 0x00515690` decompiles `sub_515690` as `void *__thiscall(int *this, char *Src, unsigned int)`:

- It updates bit count at context dwords 4 and 5, buffers partial input at context offset `0x18` = 24 bytes (Verified with `tools/int_convert.py`), calls `sub_515840` for complete `0x40` = 64-byte blocks (Verified with `tools/int_convert.py`), and memmoves remaining bytes into the context buffer.

`analyze_function 0x00515750` decompiles `sub_515750` as `void *__thiscall(int *this)`:

- It serializes the bit count, computes MD5 padding length, calls `sub_515690(this, byte_66DDD8, v6)`, calls `sub_515690(this, Src, 8)`, writes the final digest into context storage, clears state/count/buffer, and returns `memset`.
- MCP `xrefs_to 0x0066ddd8` reports the single data xref at `0x005157bb` inside `Md5Final`.

## Source Shape Decision

The best supported source-facing target signature is:

`char *Md5BytesHex(char *bytes, unsigned int byteCount)`

Why:

- The raw target argument order is exactly byte count at `[ebp+0x0c]` and source pointer at `[ebp+0x08]`.
- `Md5BytesRaw` and `Md5BytesToBuffer` both decompile with the same `char *Src, unsigned int` argument shape.
- The target returns the heap string produced by `Md5DigestToHexString`, matching `Md5StringHex`, `Md5FilePathHex`, and `Md5StreamHex`.
- `char *` is a conservative decompiler-compatible source-facing type. `const`, `void *`, or `unsigned char *` may be semantically reasonable, but exact original constness and signedness are not proven. Do not claim those stronger spellings in the target formal C++.
- The source-facing `MD5Context`, `state`, `count`, `digest`, `Update`, and `Final` spellings remain inferred, matching the accepted [UID:0001B8] first-draft style. They should be documented as inferred names, not original-source proof.

Security-cookie setup/checks are compiler artifacts and must not appear in formal C++.

## Exact Formal RECONSTRUCTION_CPP CODE Content

This is exact formal target-block replacement/insertion content for `by-memory/0x00515310-0x00515375.Md5BytesHex.md`.

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
char *Md5BytesHex(char *bytes, unsigned int byteCount)
{
    MD5Context context;

    context.state[0] = 0x67452301;
    context.state[1] = 0xefcdab89;
    context.state[2] = 0x98badcfe;
    context.state[3] = 0x10325476;
    context.count[0] = 0;
    context.count[1] = 0;

    context.Update(bytes, byteCount);
    context.Final();
    return Md5DigestToHexString(context.digest);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

This is not a sample. It is the accepted first-draft source representation if the supervisor approves implementation. It preserves exact runtime behavior at source level: initialize MD5 state/count, update from caller bytes and byte count, finalize into context digest storage, and return the heap lower-case hex string from `Md5DigestToHexString`.

## Owner And Source Placement

Keep owner and emitter as [UID:0000L6] `by-file/MD5.md`, proposed source path `NexusTK/util/MD5.cpp`.

Positive owner evidence:

- The target is physically inside the MD5 helper island between `Md5StringHex` and `Md5BytesRaw`.
- It uses only MD5 utility callees plus the compiler security-cookie check.
- It shares state initialization, context layout, `Md5Update`, `Md5Final`, and `Md5DigestToHexString` with modeled MD5 wrappers.
- The hex string return path belongs to the MD5 formatter, not to packet, registry, startup, or screenshot code.
- The parent by-file page already owns the sibling source-ready [UID:0001B8] raw helper and the completed MD5 padding data child.

Rejected owners and placements:

- Not `PacketTransform` and not `Socket`: packet code calls `0x00515380`, the next raw-digest helper, and never calls this heap-hex helper in current MCP/PE evidence.
- Not `RegistryConfig`: registry uses `0x005153e0`, the bytes-to-caller-buffer helper.
- Not `StartupWindow`: startup callers use `Md5StringHex` at `0x00515290`.
- Not `ScreenshotCapture`: screenshot proof uses `Md5StreamHex` at `0x00515570`.
- Not a data item or fallback literal page: this body has executable prologue/calls/epilogue and no xrefs to the fallback literal.
- Not a no-owner/non-emitting helper: the body is a complete utility function with a valid [UID:0000L6] emitter route and already clears the active reconstruction-code gate after the recommended score.

## Split And Boundary Decisions

Keep the target as the exact half-open raw function body `0x00515310-0x00515375`.

Rejected split/merge candidates:

- Do not merge `0x0051530a-0x00515310`: it is six bytes of `0xcc` alignment after `Md5StringHex`.
- Do not extend through `0x00515380`: `0x00515375-0x00515380` is eleven bytes of `0xcc` padding and `0x00515380` is the modeled `PacketDigest_00515380` function.
- Do not merge with `0x00515380-0x005153dc`: the next helper returns raw digest bytes for `Socket::BuildEncryptedPacket`, has one direct caller, and does not return a hex string.
- Do not merge with `0x005153e0-0x00515445`: that helper writes a 16-byte digest to a caller buffer.
- Do not merge with [UID:0001B8] `0x00515450-0x00515569`: that raw helper opens a file path and loops over `fread`; it is a different API.
- Do not extend backward into `0x00515290-0x0051530a`: that modeled wrapper hashes NUL-terminated strings by `strlen(Src)`.

## Positive Evidence Summary

- Current MCP health is ready for the NexusTK IDB.
- `lookup_funcs` proves the target is not an IDA function object while immediate modeled neighbors remain stable.
- `get_bytes`, `insn_query`, and range signatures prove a complete unique raw function body at `0x00515310-0x00515375`.
- The target body performs exactly one MD5 update with caller bytes/count, one finalization, and one digest-to-hex conversion.
- Target-side xrefs into `Md5Update`, `Md5Final`, and `Md5DigestToHexString` show this raw body as `fn:null`, proving IDA sees the call instructions even without a function object.
- Modeled siblings prove the byte-pointer plus unsigned-count wrapper family and the heap-hex return convention.
- The target has a valid owner/emitter route through [UID:0000L6] `MD5`.
- The accepted [UID:0001B8] implementation establishes that raw/no-route MD5 helpers can receive target-level first-draft C++ when the source shape is complete and explicit liveness caveats remain documented.

## Negative Evidence Summary

- `lookup_funcs` still reports no function at `0x00515310`, `0x00515374`, or `0x00515375`.
- `decompile 0x00515310` still fails because there is no function object.
- `xrefs_to 0x00515310` remains empty.
- The read-only PE scan found no direct call, direct jump, absolute VA pointer, or RVA pointer route to `0x00515310`.
- Exact original constness/signedness of the byte pointer is not proven; use `char *bytes` and document the stronger spellings as rejected/unproven.
- Exact original `MD5Context`, `Update`, `Final`, `state`, `count`, and `digest` spellings are inferred source-facing names, not original-source proof.
- The post-body bytes `0x00515375-0x00515380` are padding, not hidden logic or a second helper.
- The no-route condition remains a real liveness/confidence cap. It should be retained in docs, not erased.

## Score Rationale

Recommended target score: `COMPLETION:89`, `CONFIDENCE:91`.

| Metric | Rationale |
| --- | --- |
| Completion `89` | The target would document exact raw boundary, padding, unique signature, instruction-by-instruction behavior, stack frame, context layout, source-facing name/signature, owner/emitter route, no-route caveat, sibling comparisons, rejected split/owner candidates, and formal first-draft C++. It remains below final-audit range because IDA still has no function object, no inbound route exists, and exact original type/member spellings remain inferred. |
| Confidence `91` | Confidence is strong for the written claims because MCP body bytes, instruction xrefs, modeled sibling decompilations, string/data xrefs, and PE route scanning all agree. Confidence remains capped by no function object, no direct caller/pointer route, and unproven original constness/type names. |

## Required Implementation Edits If Accepted

Implementation callback completed by B007 on 2026-06-26. Leases were taken only for the three edited by-* docs, validators were run from `E:\NTK\GhidraBridge\source-3\project-documentation`, and B007 had no active leases after the edit/validator batch.

- [x] Edited `by-memory/0x00515310-0x00515375.Md5BytesHex.md`.
  - Applied `COMPLETION:89`, `CONFIDENCE:91`.
  - Preserved `CANONICAL_OWNER:0000L6`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000L6`.
  - Replaced stale blank-C++ rationale with target-level source-ready status while retaining the no-function/no-route liveness caveat.
  - Replaced the formal `RECONSTRUCTION_CPP CODE` marker/block with the exact accepted content from this report, including marker lines and the full `char *Md5BytesHex(char *bytes, unsigned int byteCount)` body.
  - Carried over MCP session `80de0a67` evidence: health-ready IDB, no function at `0x00515310`/`0x00515374`/`0x00515375`, modeled neighbors, decompile failure, target-side callee xrefs at `0x0051534e`/`0x00515356`/`0x0051535f`, and no raw-start xrefs.
  - Carried over the range/padding table: `0x0051530a-0x00515310` six `0xcc` bytes, target `0x00515310-0x00515375`, `retn` at `0x00515374`, `0x00515375-0x00515380` eleven `0xcc` bytes, next helper at `0x00515380`.
  - Carried over size/layout conversions with `(Verified with tools/int_convert.py)`: `0x65` = 101, `0x70` = 112, `0x10` = 16, `0x18` = 24, `0x40` = 64, `0x58` = 88, `0x0b` = 11, and referenced sibling sizes.
  - Carried over source-shape, inferred-name policy, PE route-scan negative evidence, rejected owners, rejected split candidates, boundary/padding exclusions, and score rationale.
  - Validator: `python .\tools\validator.py --mode file --file by-memory/0x00515310-0x00515375.Md5BytesHex.md --apply --queue-timeout 240`
  - Validator result: `command_id: 000000002435`, `command_timestamp: 2026-06-26T05:19:28-04:00`, exit code `0`, `ok: 1`, generated refresh `deferred` (`generated_refresh_command_id: 000000002435`, `generated_refresh_timestamp: 2026-06-26T05:19:28-04:00`). Observed validator-owned updates: `autogen_registry_update: 4`, `canonical_owner_update: 1`, `completion_update: 1`, `confidence_update: 1`, `insert_header_blank: 1`, `projected_stats_update: 1`, `reference_index_add: 1`, `stats_incremental_noop: 1`, `uid_link_insert: 1`.

- [x] Edited `by-memory/0x005151f0-0x00515f48.MD5HashHelpers.md`.
  - Updated the [UID:0001B7] range row from raw blank-C++ bytes-to-hex to source-ready first-draft `Md5BytesHex(char *bytes, unsigned int byteCount)` with retained no-function/no-route caveat.
  - Updated status/reconstruction notes so aggregate C++ remains blank because `Md5BytesRaw`, endian helper signatures/liveness, and exact `MD5Context`/helper spelling still cap aggregate output, not because [UID:0001B7] lacks target-level source-ready C++.
  - Updated `Data Issues` and `Reconstruction Notes` to remove stale unresolved-signature wording for `0x00515310`.
  - Added the B007/session `80de0a67` change note with unique `0x65` raw body, `0x70` frame, target-side update/final/hex xrefs, no raw-start xrefs, no PE call/pointer route, and formal child C++ readiness.
  - Applied support score `COMPLETION:87`, `CONFIDENCE:90`; aggregate formal C++ remains blank.
  - Validator: `python .\tools\validator.py --mode file --file by-memory/0x005151f0-0x00515f48.MD5HashHelpers.md --apply --queue-timeout 240`
  - Validator result: `command_id: 000000002436`, `command_timestamp: 2026-06-26T05:19:36-04:00`, exit code `0`, `ok: 1`, generated refresh `deferred` (`generated_refresh_command_id: 000000002436`, `generated_refresh_timestamp: 2026-06-26T05:19:36-04:00`). Observed validator-owned updates: `completion_update: 1`, `confidence_update: 1`, `projected_stats_update: 1`, `stats_incremental_noop: 1`, `uid_link_insert: 1`.

- [x] Edited `by-file/MD5.md`.
  - Updated `Status`, `Contents`, `Evidence`, `Caveats`, and `Changes` so [UID:0001B7] is source-ready with formal child C++ through `NexusTK/util/MD5.cpp`.
  - Removed stale wording that final MD5 module C++ is capped by `Md5BytesHex` lacking target-level source-ready C++; retained the remaining blockers: `Md5BytesRaw` stack-digest return representation, endian helper no-route/signature, and exact `MD5Context`/method/member spelling.
  - Preserved `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/"`, broad file-level C++ blank policy, and the distinction between MD5 utility ownership and packet/startup/registry/screenshot consumers.
  - Applied support score `COMPLETION:89`, `CONFIDENCE:88`.
  - Validator: `python .\tools\validator.py --mode file --file by-file/MD5.md --apply --queue-timeout 240`
  - Validator result: `command_id: 000000002438`, `command_timestamp: 2026-06-26T05:19:45-04:00`, exit code `0`, `ok: 1`, generated refresh `deferred` (`generated_refresh_command_id: 000000002438`, `generated_refresh_timestamp: 2026-06-26T05:19:45-04:00`). Observed validator-owned updates: `completion_update: 1`, `confidence_update: 1`, `projected_stats_update: 1`, `stats_incremental_noop: 1`. Warning retained for supervisor context: `missing_ref_uid: 4` for UID `0003J1` in `by-file/MD5.md`; the referenced page exists at `by-memory/0x0061ead4-0x0061eadc.Md5HexFormatString.md`, so no validator state/cache edits were made.

- [x] No edit required for `by-item/PacketDigest_00515380.md`.
  - Proof: spot-check confirms the page keeps [UID:0001B7] separate from packet-facing raw digest helper `0x00515380`, retains owner [UID:0000L6] `MD5` rather than `PacketTransform`, records exactly one Socket caller for `0x00515380`, and keeps its own C++ blank because of the unresolved stack-return digest representation, not because [UID:0001B7] lacks target C++.

- [x] No edit required for `by-memory/0x00515450-0x00515568.Md5FilePathHex.md`.
  - Proof: spot-check confirms the page already has formal `Md5FilePathHex(const char *path)` C++, documents raw/no-route as a liveness/confidence cap rather than a blank-C++ blocker, and does not depend on [UID:0001B7] remaining unresolved.

- [x] No edit required for `by-memory/0x0061ead4-0x0061eadc.Md5HexFormatString.md`.
  - Proof: spot-check confirms the page already documents ASCII `%02x`, parent `0000L6`, and direct xref at `0x00515235`; [UID:0001B7] reaches formatting through `Md5DigestToHexString`, not by directly owning the literal.

- [x] No edit required for `by-memory/0x0066ddd8-0x0066de18.Md5PaddingBlock.md`.
  - Proof: spot-check confirms the page remains final-audit `95/95`, documents `byte_66DDD8` as the 64-byte MD5 padding table consumed by `Md5Final`, and has no direct target-specific dependency on [UID:0001B7].

- [x] No edit required for `by-memory/0x00515f50-0x00515ff2.MD5EndianEncodeDecodeHelpers.md`.
  - Proof: spot-check confirms the page still records no-function/no-xref endian helpers as MD5 siblings and intentionally keeps C++ blank until exact source signatures and live-use disposition are proven; [UID:0001B7] becoming source-ready does not resolve those blockers.

- [x] No manual edits were made to generated files, project-level generated files, validator state/cache, tool state, IDA DB state, or any `-coverage-report.md`.
  - Proof: manual edits were limited to the three scoped by-* docs and this Agent-B007 research report. Validator-owned observations were recorded above; generated refresh was deferred for all three scoped validators.

- [x] Leased only the files being edited during implementation, and released/cleared leases after the edit/validator batch.
  - Proof: B007 leased exactly `by-memory/0x00515310-0x00515375.Md5BytesHex.md`, `by-memory/0x005151f0-0x00515f48.MD5HashHelpers.md`, and `by-file/MD5.md` before editing. After validation, `python .\leaser.py B007 unlease` reported `B007: No active leases`, and `tools/leaser/Agents/current_leases.md` contained no B007 row and reported `No active leases.`

## Report-Only Checklist

- [x] Read B007 `goal.md`.
- [x] Used the project-level `ntk-b-agent-workflow` skill.
- [x] Used mandatory IDA MCP session `80de0a67`; MCP was available and health-ready.
- [x] Read target and required support docs.
- [x] Verified raw body, padding, xrefs, modeled siblings, data literals, and no-route state.
- [x] Verified numeric conversions with `tools/int_convert.py`.
- [x] Wrote report only in the Agent-B007 research folder.
- [x] Did not edit by-* docs, generated files, project-level generated files, validator/tool state, IDA DB, or coverage reports.
- [x] Did not spawn subagents.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B007","command_id":"000000004165","destination_path":"executed-b-agent-research/B007/0001B7-Md5BytesHex-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B007/research/0001B7-Md5BytesHex-source-quality.md","timestamp":"2026-06-26T05:26:28","uid":"0001B7"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
