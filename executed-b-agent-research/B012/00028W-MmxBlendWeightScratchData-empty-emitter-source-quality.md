** TARGET-REPORT-UID:00028W **
** AUTHOR-AGENT-ID:B012 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B012-report-00028W-MmxBlendWeightScratchData-empty-emitter-source-quality-20260629

## Scope

Primary target:

- [UID:00028W] `by-memory/0x0067a7f0-0x0067a830.MmxBlendWeightScratchData.md`

Context inspected:

- [UID:0000NT] `by-file/SoftwareBlend16.md`
- [UID:0000YD] `by-memory/0x0045fa00-0x004604f4.Rgb555565BlitHelpers.md`
- [UID:000209] `by-memory/0x004609e0-0x00460af9.Rgb565TransparentAlphaBlendMmxBlocks.md`
- [UID:0000YF] `by-memory/0x00460b00-0x00460c0a.AlphaBlendSpan16Blocks.md`
- [UID:0002OO] `by-memory/0x00610e38-0x00610ed8.SoftwareBlend16ReadOnlyConstants.md`
- `auto-generated/NexusTK/render/SoftwareBlend16.cpp`
- Executed B001 SoftwareBlend16 reports for [UID:000206], [UID:0000YG], and the [UID:000209]/MMX block family.
- Active B003 report for [UID:0000YF] as a non-authoritative current lead only.

This was a report-only assignment. I did not edit by-* docs, generated files, coverage reports, validator/tool state, IDA DB, executed archives, supervisor ledgers, or lock files. I did not take leases and did not spawn subagents.

## Current State

[UID:00028W] is currently:

- `COMPLETION:85`
- `CONFIDENCE:88`
- `CANONICAL_OWNER:0000NT`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000NT`
- blank formal `RECONSTRUCTION_CPP CODE`

The target page already captures the important binary shape: a `0x40` byte writable scratch row from `0x0067a7f0-0x0067a830`, split into eight qword cells, each used by one SoftwareBlend16 MMX helper pair. It also already states the key source-form uncertainty: a clean rebuild may compute equivalent `__m64` or qword temporaries locally inside the helpers rather than preserve writable globals.

The remaining problem is not ownership or range identification. It is the empty-emitter source-disposition issue: the page is routed through [UID:0000NT] but has no formal C++ body, so generated `SoftwareBlend16.cpp` currently contains an empty emitter marker for [UID:00028W].

## MCP Evidence

Live MCP session:

- Session requested and used: `dad3692b`
- `server_health(database=dad3692b)`: `status:"ok"`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`
- IDB path: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`
- Module: `NexusTK.exe`
- Imagebase: `0x400000`

Function identities:

| Query | MCP result |
| --- | --- |
| `0x0045fff0` | `sub_45FFF0`, size `0x121` |
| `0x00460120` | `sub_460120`, size `0x10f` |
| `0x004609e0` | `sub_4609E0`, size `0x119` |
| `0x00460b00` | `sub_460B00`, size `0x10a` |
| `0x0067a7f0` through `0x0067a834` | not functions |

Xrefs to the scratch qwords:

| Cell | Xrefs | Owning helper |
| --- | --- | --- |
| `0x0067a7f0` | `0x00460003`, `0x0046002a` | `sub_45FFF0` |
| `0x0067a7f8` | `0x0046001c`, `0x00460031` | `sub_45FFF0` |
| `0x0067a800` | `0x00460133`, `0x0046015a` | `sub_460120` |
| `0x0067a808` | `0x0046014c`, `0x00460161` | `sub_460120` |
| `0x0067a810` | `0x004609f3`, `0x00460a1a` | `sub_4609E0` |
| `0x0067a818` | `0x00460a0c`, `0x00460a21` | `sub_4609E0` |
| `0x0067a820` | `0x00460b16`, `0x00460b43` | `sub_460B00` |
| `0x0067a828` | `0x00460b32`, `0x00460b4a` | `sub_460B00` |

Boundary evidence:

- `xrefs_to 0x0067a830`: no cross-references.
- `xrefs_to 0x0067a834`: two data refs from `sub_461310`, proving the next referenced global begins after the `0x0067a830-0x0067a834` gap and is outside [UID:00028W].
- MCP `int_convert` confirmed `0x40` is decimal `64` and `0x44` is decimal `68`.

Initial-byte evidence:

- Current MCP `get_bytes` for `0x0067a7f0` size `68` returned all zero bytes across `0x0067a7f0-0x0067a834`.
- This differs from the current target page's older statement that only the first pair is zero and the remaining six qwords are initialized to `0xffffffffffffffff`.
- Because the source-disposition decision is driven by write-before-read helper behavior rather than initial data values, this mismatch is not a blocker. It should be corrected or explicitly superseded during implementation: the live `dad3692b` session supports all-zero stored bytes for this row.

Instruction evidence:

- `sub_45FFF0` writes `qword_67A7F0` and `qword_67A7F8` from the alpha argument, then immediately loads them with `movq mm2, qword_67A7F0` and `movq mm3, qword_67A7F8`.
- `sub_460120` writes `0x0067a800` and `0x0067a808` from the alpha argument, then immediately loads them with `movq mm2` and `movq mm3`.
- `sub_4609E0` writes `0x0067a810` and `0x0067a818` from the alpha argument, then immediately loads them with `movq mm2` and `movq mm3`.
- `sub_460B00` writes `0x0067a820` and `0x0067a828` from the alpha argument, then immediately loads them with `movq mm2` and `movq mm3`.

In all four helpers, the scratch cells are local weight-vector materialization points: source weight and inverse weight are expanded into duplicated 16-bit lanes, loaded into MMX registers, and used by that helper's loop. No cell has an external reader, an inter-helper data dependency, or a required preserved initial value.

## Documentation Evidence

[UID:00028W] target page:

- Correctly identifies the eight qword cells and their helper pairs.
- Correctly assigns the range to [UID:0000NT] `SoftwareBlend16`.
- Correctly says the clean rebuild can fold the data concept into local intrinsic/inline-assembly temporaries inside the helpers.
- Needs a formal source-disposition marker instead of a blank emitter body.
- Needs its initial-value evidence reconciled with current `dad3692b` MCP bytes.

[UID:0000NT] `SoftwareBlend16`:

- Already has the correct file owner route and `NexusTK/render/` proposed path.
- Its MMX Source-Form Policy says the helper family should be emitted coherently, because the binary favors MSVC x86 inline assembly or assembly-backed helper bodies with `pushaw`, `popaw`, `emms`, qword MMX operations, and writable qword scratch operands.
- It already notes that [UID:00028W] records binary writable scratch qwords, while future clean source may use local `__m64` temporaries if behavior is preserved.

[UID:0000YD] `Rgb555565BlitHelpers`:

- Covers the RGB555 helpers at `0x0045fff0` and `0x00460120`, which write and read the first four [UID:00028W] qwords.
- Its aggregate/helper-island status means the first four scratch qwords should remain documented as binary facts, but they should not force a file-scope scratch declaration if those helpers later emit local MMX weight temporaries.

[UID:000209] `Rgb565TransparentAlphaBlendMmxBlocks`:

- Uses `qword_67A810` and `qword_67A818`.
- Already records that a rebuild may use local MMX temporaries while preserving the binary fact.
- Keeps formal C++ blank because source form for the MMX helper family is not fully settled.

[UID:0000YF] `AlphaBlendSpan16Blocks`:

- Uses `qword_67A820` and `qword_67A828`.
- The active B003 report, not yet treated here as executed authority, recommends local qword equivalents for these weights and support-doc synchronization with [UID:00028W]. This aligns with the MCP evidence here.

[UID:0002OO] `SoftwareBlend16ReadOnlyConstants`:

- Represents read-only qword masks that are source-authored static data candidates.
- It should remain conceptually separate from [UID:00028W]. [UID:0002OO] masks may become static constants; [UID:00028W] writable weight vectors should be represented by local helper temporaries or inline-assembly operands, not standalone global data.

Generated C++:

- `auto-generated/NexusTK/render/SoftwareBlend16.cpp` is currently fresh from validator command `000000000967`, refreshed `2026-06-29T17:32:16-04:00` with `validator-refresh-source: deferred-generated-refresh`.
- It already contains emitted [UID:0000YE] source and empty emitter markers for unresolved SoftwareBlend16 children.
- It contains an empty emitter marker for [UID:00028W] with `Completion:85 | Confidence:88`.
- The generated file now also contains emitted [UID:0000YF] source from the B003 callback; the UID00028W empty marker remains unresolved.
- A scoped generated-source search for `qword_67A7F0` and `qword_67A828` returned no matches, so the current generated output has not emitted standalone scratch globals.

## Latest-State Reconciliation 2026-06-29

This revision re-read the current target and support docs after the B003 implementation callback. The original report evidence remains useful, but the incorporation plan must account for facts that are now already present.

Current target [UID:00028W]:

- Still `85/88`, `CANONICAL_OWNER:0000NT`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000NT`.
- Still has a blank formal `RECONSTRUCTION_CPP CODE` block and therefore still generates an empty emitter marker.
- Already contains B003 support text for [UID:0000YF]: `0x0067a820/0x0067a828` are now documented as binary scratch cells whose accepted [UID:0000YF] formal C++ computes equivalent local qword vectors.
- Still contains the older A002 initializer statement that the first pair is zero and the remaining six qwords are `0xffffffffffffffff`. This is stale relative to B012 MCP session `dad3692b`, where `get_bytes 0x0067a7f0 size 0x44` returned all zero bytes.

Current [UID:0000NT] `SoftwareBlend16`:

- Still `86/88` and remains the correct owner/emitter.
- Already includes the broad policy that [UID:00028W] records binary writable scratch qwords and clean source may use local `__m64` temporaries.
- Already includes B003's accepted [UID:0000YF] policy: local qword masks and local qword source/inverse weight vectors stand in for `0x00610ea8/0x00610eb0` and `0x0067a820/0x0067a828`.
- Still lacks an explicit whole-[UID:00028W] no-standalone-source statement covering all eight scratch qwords and all three direct helper groups.

Current [UID:0000YD] `Rgb555565BlitHelpers`:

- Still `86/90`, owner/emitter [UID:0000NT], and blank formal C++.
- Current text search found no [UID:00028W] or `qword_67A7F0`/`qword_67A808` support note. The optional RGB555 scratch-policy note remains not incorporated.

Current [UID:000209] `Rgb565TransparentAlphaBlendMmxBlocks`:

- Still `86/91`, owner/emitter [UID:0000NT], and blank formal C++.
- Already states that [UID:00028W] records `qword_67A810`/`qword_67A818`, and that a clean rebuild may choose local `__m64` temporaries if behavior and source style are preserved. This is adequate support for the B012 claim; only optional wording would be needed to cite the final no-standalone-source policy after [UID:00028W] is updated.

Current [UID:0000YF] `AlphaBlendSpan16Blocks`:

- Now `88/91` with populated formal C++.
- Already records the accepted B003 source-form decision: local qword variables stand in for [UID:00028W] entries `0x0067a820/0x0067a828`, with no external dependency on the global scratch side effect. This support claim is already present and supersedes the earlier "if B003 is accepted" wording.

Current [UID:0002OO] `SoftwareBlend16ReadOnlyConstants`:

- Still `86/90`, owner/emitter [UID:0000NT], and blank formal C++.
- Already distinguishes source-level read-only masks and records B003's target-local mask representation for [UID:0000YF].
- It does not explicitly mention [UID:00028W], but the contrast is optional: [UID:0002OO] already says constants may remain source-owned data while [UID:00028W] is covered by the target and SoftwareBlend16 scratch-policy notes.

Current generated output:

- `auto-generated/NexusTK/render/SoftwareBlend16.cpp` header is `validator-command-id: 000000000967`, `validator-refreshed-at: 2026-06-29T17:32:16-04:00`.
- [UID:0000YF] emitted body is present.
- [UID:00028W] still appears as `Completion:85 | Confidence:88 | Empty Emitter Marker`.
- Standalone `qword_67A7F0`/`qword_67A828` declarations are not present.

## Source-Quality Decision

Do not emit standalone static writable globals for [UID:00028W].

Rationale:

- Each qword cell is written by exactly one helper before it is read by that helper.
- The write value is derived from the helper's alpha/source-weight argument.
- The value is immediately loaded into MMX registers and used as a loop-local weight vector.
- No other helper consumes another helper's cell.
- No external data reference targets the row.
- The current stored bytes are not semantically meaningful to the runtime helper result because the helper overwrites its cells before use.
- Preserving eight file-scope writable qwords would copy a binary scratch implementation detail into source and introduce unnecessary shared mutable state.

Best source representation:

- Keep [UID:00028W] as reconstructable, SoftwareBlend16-owned documentation of the binary writable scratch row.
- Represent the emitted source effect inside the helper bodies as local qword or `__m64` source/inverse weight temporaries, or as local operands in a coherent inline-assembly reconstruction.
- Use a formal no-standalone-source marker in [UID:00028W]'s `RECONSTRUCTION_CPP CODE` block so autogen no longer reports an empty emitter.

This is not a rare blank no-code proof. It is a covered-by/helper-local source-shape decision: the data range is real and reconstructable, but its source representation belongs inside the helper bodies rather than as a file-scope declaration.

## Recommended Target Metadata

Update [UID:00028W] to:

```text
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Keep:

```text
*** CANONICAL_OWNER:0000NT | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000NT | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Score rationale:

- Completion `88`: range, cell layout, helper ownership, xrefs, boundary, source route, generated-output impact, and no-standalone-source policy are now resolved. Remaining completion gaps are the final C++ source form of the surrounding MMX helpers and exact local-temporary spelling.
- Confidence `91`: current MCP `dad3692b` verifies the xrefs, helper identities, write-before-read pattern, and boundary. Confidence remains below final-audit level because the helper family still needs a coherent final MMX source-form pass.

## Recommended Formal C++ Block

Replace the blank formal C++ block with a minimal covered-by comment:

```cpp
// Emitted source for this writable MMX weight scratch range is covered by the
// SoftwareBlend16 helper bodies that compute local source/inverse weight
// vectors: [UID:0000YD], [UID:000209], and [UID:0000YF]. No standalone
// file-scope data declaration is emitted for [UID:00028W].
```

Expected autogen outcome:

- The [UID:00028W] empty emitter marker should disappear.
- `SoftwareBlend16.cpp` should not gain global declarations for `qword_67A7F0` through `qword_67A828`.
- The generated source should contain only the formal no-standalone-source comment for [UID:00028W] until the helper bodies emit their local weight-vector construction.

## Exact Target Page Edits

1. Raise metadata to `88/91` as above.

2. Update the initial-value evidence to reflect current MCP:

```text
- 2026-06-29 Agent-B012 MCP session `dad3692b` `get_bytes 0x0067a7f0 size 0x44` returned all zero bytes across `0x0067a7f0-0x0067a834`. Earlier notes that the later six qwords initialize to `0xffffffffffffffff` should be treated as stale unless revalidated by a later IDB/session.
```

3. Add source-disposition evidence:

```text
- 2026-06-29 Agent-B012 MCP session `dad3692b` reconfirmed each qword has only one helper-local write/load pair: `sub_45FFF0` uses `0x0067a7f0/0x0067a7f8`, `sub_460120` uses `0x0067a800/0x0067a808`, `sub_4609E0` uses `0x0067a810/0x0067a818`, and `sub_460B00` uses `0x0067a820/0x0067a828`. Each pair is written from the alpha/source-weight argument and loaded into `mm2/mm3` before the loop; there are no external readers or cross-helper dependencies.
```

4. Replace the blank formal C++ block with the covered-by comment in the previous section.

5. Add or replace score rationale:

```text
- Completion `88`: exact scratch range, eight qword cells, helper-local xrefs, no external users, boundary at `0x0067a830`, next referenced global beginning at `0x0067a834`, owner route, generated-output effect, and no-standalone-source policy are now documented. Remaining gaps are the final source form and spelling of local weight temporaries inside the MMX helper bodies.
- Confidence `91`: live MCP session `dad3692b`, target docs, SoftwareBlend16 parent policy, and sibling helper pages agree that this row is binary writable scratch for helper-local MMX weight vectors. Confidence remains below final C++ audit quality because the surrounding helper family still needs a coherent inline-assembly/intrinsics source-form pass.
```

## Support Doc Recommendations

`by-file/SoftwareBlend16.md`:

- Add a short policy note under the MMX Source-Form Policy:

```text
- [UID:00028W] is not a standalone source data declaration. Its eight writable qwords are binary scratch locations used to materialize helper-local source/inverse MMX weight vectors. Final SoftwareBlend16 source should compute those weights as local qword/`__m64` temporaries or inline-assembly operands inside [UID:0000YD], [UID:000209], and [UID:0000YF] helper bodies.
```

`by-memory/0x0045fa00-0x004604f4.Rgb555565BlitHelpers.md`:

- Add a support note for `0x0045fff0` and `0x00460120`:

```text
- [UID:00028W] records the binary scratch qword pairs used by the RGB555 block helpers at `0x0045fff0` and `0x00460120`. Future C++ should prefer local weight-vector temporaries or inline-assembly operands in these helpers rather than requiring global `qword_67A7F0` through `qword_67A808` declarations.
```

`by-memory/0x004609e0-0x00460af9.Rgb565TransparentAlphaBlendMmxBlocks.md`:

- Its existing note is already aligned. Optionally tighten it to reference the [UID:00028W] no-standalone-source policy directly.

`by-memory/0x00460b00-0x00460c0a.AlphaBlendSpan16Blocks.md`:

- If the B003 [UID:0000YF] implementation is accepted first, keep its local qword weight-vector approach and sync the [UID:00028W] note to say `0x0067a820/0x0067a828` remain binary scratch facts only.

`by-memory/0x00610e38-0x00610ed8.SoftwareBlend16ReadOnlyConstants.md`:

- Add a contrast note only if the supervisor wants the distinction explicit:

```text
- Do not model [UID:00028W] like these read-only masks. [UID:0002OO] contains reusable source-authored constants; [UID:00028W] contains writable helper-local weight scratch and should be covered by local helper temporaries rather than static declarations.
```

## Rejected Alternatives

- Emit eight `static unsigned long long` globals: rejected. The binary has writable globals, but current evidence shows they are helper-local scratch values overwritten before use. Static declarations would preserve an implementation artifact rather than a good source reconstruction.
- Mark [UID:00028W] non-reconstructable or ignored: rejected. The range is real SoftwareBlend16 data with exact helper-local xrefs and should remain documented under [UID:0000NT].
- Leave formal C++ blank: rejected. The current route emits an empty marker, and the source-disposition question is sufficiently resolved to replace that marker with a formal no-standalone-source comment.
- Move ownership away from [UID:0000NT]: rejected. All users are SoftwareBlend16/RGB555/RGB565 blend helpers and the parent file already owns the helper family.

## Claim And Incorporation Ledger

| Claim ID | Accepted claim | Action | Destination or exclusion reason | Latest state / verification state |
| --- | --- | --- | --- | --- |
| C01 | [UID:00028W] should raise from `85/88` to `88/91`. | incorporate | `by-memory/0x0067a7f0-0x0067a830.MmxBlendWeightScratchData.md` metadata header and score rationale. | Callback applied. Header now `COMPLETION:88`/`CONFIDENCE:91`; validator `000000000983` reported `completion_update 00028W ... 88` and `confidence_update 00028W ... 91`. |
| C02 | Keep `CANONICAL_OWNER:0000NT`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000NT`. | already-present | Same target metadata header; preserve values during implementation. | Callback already-present. Target header still has `CANONICAL_OWNER:0000NT`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000NT`; no owner/emitter change. |
| C03 | Current MCP session `dad3692b` supports all-zero stored bytes across `0x0067a7f0-0x0067a834`; older six-qword `0xffffffffffffffff` initializer note is stale unless later revalidated. | incorporate | Target `Evidence`, `Reconstruction Notes`, and `Changes`; replace or historicalize the A002 initializer wording without deleting the older evidence context. | Callback applied. Target `Evidence` and `Changes` now historicalize A002 and record `get_bytes 0x0067a7f0 size 0x44` all-zero current-IDB evidence; validator `000000000983` ok. |
| C04 | The exact scratch row is `0x0067a7f0-0x0067a830`, eight qwords, with `0x0067a830` unreferenced and `0x0067a834` belonging to the next referenced global. | incorporate | Target `Summary`/`Layout`/`Evidence`; preserve existing row and add B012 boundary evidence from `xrefs_to 0x0067a830` and `xrefs_to 0x0067a834`. | Callback applied. Target `Evidence` now records no xrefs to `0x0067a830` and the next referenced global beginning at `0x0067a834`; validator `000000000983` ok. |
| C05 | Each qword pair is helper-local write-before-read scratch: `sub_45FFF0` uses `0x0067a7f0/0x0067a7f8`, `sub_460120` uses `0x0067a800/0x0067a808`, `sub_4609E0` uses `0x0067a810/0x0067a818`, and `sub_460B00` uses `0x0067a820/0x0067a828`. | incorporate | Target `Evidence`; [UID:0000NT] policy note; optional support notes for [UID:0000YD], [UID:000209], [UID:0000YF]. | Callback applied. Target `Evidence` records all four write/load pairs; SoftwareBlend16 policy covers all helper groups; Rgb555565BlitHelpers records the first two RGB555 pairs; validators `000000000983`, `000000000984`, and `000000000985` ok. |
| C06 | Do not emit standalone file-scope writable globals for `qword_67A7F0` through `qword_67A828`. | incorporate | Target `Reconstruction Notes`, target formal C++ comment, [UID:0000NT] policy note. | Callback applied. Target formal C++ and Reconstruction Notes reject standalone globals; SoftwareBlend16 policy now says UID00028W is not standalone source data; generated check after autogen `000000000986` found no `qword_67A7F0` or `qword_67A828` hits. |
| C07 | Replace the blank formal `RECONSTRUCTION_CPP CODE` block with a covered-by/no-standalone-source comment. | incorporate | Target formal `RECONSTRUCTION_CPP CODE` block. Exact text is in `Recommended Formal C++ Block`. | Callback applied. Target block now contains the no-standalone-source comment; validator `000000000983` reported `autogen_registry_update 00028W ... blank -> block`. |
| C08 | Generated `SoftwareBlend16.cpp` should stop showing [UID:00028W] as an empty emitter after validator/autogen, while still not gaining scratch global declarations. | incorporate | Validator/autogen result and post-validation generated-source check, not a manual generated-file edit. | Callback applied. Autogen `000000000986` refreshed `SoftwareBlend16.cpp`; generated line now shows `UID:00028W ... Completion:88 | Confidence:91` and the formal comment, with no `Empty Emitter Marker` on UID00028W and no scratch global hits. |
| C09 | Add SoftwareBlend16 whole-range scratch policy: UID00028W is documentation of binary scratch storage; final source should compute helper-local source/inverse weight vectors inside [UID:0000YD], [UID:000209], and [UID:0000YF] helper bodies. | incorporate | `by-file/SoftwareBlend16.md` under `MMX Source-Form Policy`. | Callback applied. SoftwareBlend16 policy now states UID00028W is not standalone source data and maps all eight qwords to local qword/`__m64` temporaries or inline-assembly operands in the three helper groups; validator `000000000984` ok. |
| C10 | Add RGB555 helper support note for the first four scratch qwords. | incorporate | `by-memory/0x0045fa00-0x004604f4.Rgb555565BlitHelpers.md`, near relevant helper-island/reconstruction evidence. | Callback applied. Rgb555565BlitHelpers now records `0x0045fff0` using `qword_67A7F0/qword_67A7F8` and `0x00460120` using `qword_67A800/qword_67A808`, with local-temporary policy; validator `000000000985` ok. |
| C11 | [UID:000209] already supports the local-temporary policy for `0x0067a810/0x0067a818`. | already-present | `by-memory/0x004609e0-0x00460af9.Rgb565TransparentAlphaBlendMmxBlocks.md`; optional wording can be tightened after [UID:00028W] changes. | Callback already-present. Goal instructed not to edit [UID:000209] just to repeat already-present facts; no regression observed during latest-state reconciliation. |
| C12 | [UID:0000YF] local qword scratch policy for `0x0067a820/0x0067a828` is now accepted and should be treated as already incorporated support evidence. | already-present | `by-memory/0x00460b00-0x00460c0a.AlphaBlendSpan16Blocks.md`, target [UID:00028W] B003 note, and [UID:0000NT] policy. | Callback already-present. Goal instructed not to edit [UID:0000YF]; current page already contains B003 local qword scratch policy. |
| C13 | [UID:0002OO] read-only constants remain conceptually distinct from UID00028W writable scratch. | not-applicable | Optional contrast note in `by-memory/0x00610e38-0x00610ed8.SoftwareBlend16ReadOnlyConstants.md`. | Callback excluded-with-reason. Goal instructed to treat C13 as not-applicable unless current text regressed; current [UID:0002OO] already distinguishes read-only masks and B003 local mask handling, so no edit was made. |
| C14 | Validator commands must be scoped and run from `source-3/project-documentation` with relative by-* paths and `--queue-timeout 240`. | incorporate | Implementation procedure, not by-* prose. Use commands in `Validation Commands For Implementation`. | Callback applied. Ran all required commands from `source-3/project-documentation` with relative paths and `--queue-timeout 240`: `000000000983`, `000000000984`, `000000000985`, `000000000986`. |
| C15 | Generated freshness must be checked after implementation against validator command metadata and generated header. | incorporate | Implementation procedure and final callback report. Check `auto-generated/NexusTK/render/SoftwareBlend16.cpp` header after autogen. | Callback applied. Generated header is `validator-command-id: 000000000986`, `validator-refreshed-at: 2026-06-29T17:47:24-04:00`, matching autogen command `000000000986`. |
| C16 | No manual edits to generated reports, project-level generated reports, manual coverage reports, validator/tool state, IDA DB, executed archives, supervisor ledgers, or lock files. | not-applicable | This is a process constraint, not a by-* destination. | Callback complied. Only accepted by-* docs and this Agent-B012 report were manually edited; generated/project-level updates were validator-generated. |
| C17 | Leave implementation checklist items unchecked during report-only revision. | not-applicable | This report's checklist. | Callback not-applicable. The report-only constraint is superseded by accepted implementation callback; checklist below is now checked with proof. |

## Implementation Validator Results

| Command | command_id | command_timestamp | Exit | ok | Notes |
| --- | --- | --- | ---: | ---: | --- |
| `python .\tools\validator.py --mode file --file by-memory\0x0067a7f0-0x0067a830.MmxBlendWeightScratchData.md --apply --queue-timeout 240` | `000000000983` | `2026-06-29T17:46:59-04:00` | 0 | 1 | Updated UID00028W completion/confidence, registry hash, and blank-to-block state; generated refresh deferred. |
| `python .\tools\validator.py --mode file --file by-file\SoftwareBlend16.md --apply --queue-timeout 240` | `000000000984` | `2026-06-29T17:47:05-04:00` | 0 | 1 | Passed with existing unrelated `missing_ref_uid 0003ZP` diagnostics; generated refresh deferred. |
| `python .\tools\validator.py --mode file --file by-memory\0x0045fa00-0x004604f4.Rgb555565BlitHelpers.md --apply --queue-timeout 240` | `000000000985` | `2026-06-29T17:47:17-04:00` | 0 | 1 | Added UID00028W reference index entry; generated refresh deferred. |
| `python .\tools\validator.py --mode autogen --apply --queue-timeout 240` | `000000000986` | `2026-06-29T17:47:24-04:00` | 0 | n/a | Generated refresh completed. |

Generated freshness proof:

- `auto-generated/NexusTK/render/SoftwareBlend16.cpp` header now reports `validator-command-id: 000000000986` and `validator-refreshed-at: 2026-06-29T17:47:24-04:00`, equal to the required autogen command metadata.
- Generated UID00028W output now shows `Completion:88 | Confidence:91` and the no-standalone-source comment.
- Generated UID00028W output no longer has `Empty Emitter Marker`.
- Generated check found no standalone `qword_67A7F0` or `qword_67A828` declarations/hits.
- Other unrelated empty emitter markers remain in `SoftwareBlend16.cpp`; they are outside this callback.

## Required Implementation Checklist

- [x] Take leases only for files being edited immediately. Proof: leased only `by-memory\0x0067a7f0-0x0067a830.MmxBlendWeightScratchData.md`, `by-file\SoftwareBlend16.md`, and `by-memory\0x0045fa00-0x004604f4.Rgb555565BlitHelpers.md`.
- [x] Update [UID:00028W] metadata from `85/88` to `88/91`. Proof: target header updated; validator `000000000983` reported completion/confidence updates.
- [x] Reconcile [UID:00028W] initial-byte evidence with current `dad3692b` all-zero MCP bytes. Proof: target `Evidence` and `Changes` now record current all-zero `get_bytes` evidence and historicalize A002 initializer detail.
- [x] Add the helper-local write/load evidence and boundary evidence. Proof: target `Evidence` now records all four helper write/load pairs, no xrefs to `0x0067a830`, and next referenced global at `0x0067a834`.
- [x] Replace [UID:00028W]'s blank formal C++ block with the covered-by/no-standalone-source comment. Proof: target formal block populated; validator `000000000983` reported `blank -> block`.
- [x] Add support-policy notes to [UID:0000NT] and, if in scope, [UID:0000YD], [UID:000209], [UID:0000YF], and [UID:0002OO]. Proof: SoftwareBlend16 and Rgb555565BlitHelpers updated; C11/C12 already present per goal; C13 excluded as not-applicable per goal.
- [x] Run validator file mode on edited by-* docs with `--apply`. Proof: file validator commands `000000000983`, `000000000984`, and `000000000985` exited 0 with `ok: 1`.
- [x] Run validator autogen with `--apply`. Proof: autogen command `000000000986` exited 0 and reported `generated_refresh: completed`.
- [x] Confirm `auto-generated/NexusTK/render/SoftwareBlend16.cpp` no longer contains an empty emitter marker for [UID:00028W]. Proof: generated UID00028W line is `Completion:88 | Confidence:91` and is followed by the formal comment, not `Empty Emitter Marker`.
- [x] Confirm no global declarations for `qword_67A7F0`, `qword_67A7F8`, `qword_67A800`, `qword_67A808`, `qword_67A810`, `qword_67A818`, `qword_67A820`, or `qword_67A828` were generated. Proof: generated check found no `qword_67A7F0` or `qword_67A828` hits; the formal comment contains no global declarations.
- [x] During implementation callback, update the Claim And Incorporation Ledger verification states to `applied`, `already-present`, or `excluded-with-reason` for every accepted claim. Proof: ledger C01-C17 updated above.
- [x] Release all leases immediately after the edit/validator batch. Proof: `leaser.py B012 unlease ...` returned Success for all three leased by-* files; `current_leases.md` shows no active leases.

## Validation Commands For Implementation

When applying the recommended edits, run from `E:\NTK\GhidraBridge\source-3\project-documentation` at minimum:

> Executable block R001 was removed from this report and preserved verbatim in [00028W-MmxBlendWeightScratchData-empty-emitter-source-quality-removed.md](00028W-MmxBlendWeightScratchData-empty-emitter-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If optional sibling support notes are edited, also run file-mode validator on those exact files before autogen:

> Executable block R002 was removed from this report and preserved verbatim in [00028W-MmxBlendWeightScratchData-empty-emitter-source-quality-removed.md](00028W-MmxBlendWeightScratchData-empty-emitter-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Post-validation checks:

> Executable block R003 was removed from this report and preserved verbatim in [00028W-MmxBlendWeightScratchData-empty-emitter-source-quality-removed.md](00028W-MmxBlendWeightScratchData-empty-emitter-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Expected outcome:

- [UID:00028W] is no longer an empty emitter in generated SoftwareBlend16 output.
- [UID:00028W] remains reconstructable and owned/emitted by [UID:0000NT].
- No standalone file-scope scratch globals are emitted.
- The binary scratch row remains documented as evidence for helper-local MMX weight-vector construction.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B012","command_id":"000000004165","destination_path":"executed-b-agent-research/B012/00028W-MmxBlendWeightScratchData-empty-emitter-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B012/research/00028W-MmxBlendWeightScratchData-empty-emitter-source-quality.md","timestamp":"2026-06-29T17:51:08","uid":"00028W"} -->
<!-- {"agent":"B012","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00028W-MmxBlendWeightScratchData-empty-emitter-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B012/00028W-MmxBlendWeightScratchData-empty-emitter-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00028W"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
