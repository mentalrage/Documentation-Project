** TARGET-REPORT-UID:0002TD **
** AUTHOR-AGENT-ID:B008 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | Medium **

# UID0002TD SoftwareRenderCompatAlphaLookupBlitCallback Source-Quality Report

## Finalized Report / Current Recommendation

UID0002TD remains a Surface-owned, reconstructable, Surface-emitted software-render callback target. B008 completed the accepted implementation callback by refreshing the target metadata/evidence to `COMPLETION:87`, `CONFIDENCE:90`, keeping `CANONICAL_OWNER:0000OC`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000OC`, blank emitter position, and the formal `RECONSTRUCTION_CPP CODE` block blank. The remaining source-quality/C++ readiness issue is not an ownership failure: the callback typedef, source alpha descriptor, source-facing helper names, and final field names are not yet source-quality enough for a formal body.

Accepted callback disposition applied:

- Raise target metadata from `COMPLETION:85`, `CONFIDENCE:89` to `COMPLETION:87`, `CONFIDENCE:90`.
- Keep `CANONICAL_OWNER:0000OC`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000OC`, and blank emitter position.
- Keep the formal `RECONSTRUCTION_CPP CODE` block exactly blank.
- Replace stale broad blocker wording with the current target-specific no-code proof: the body is a real source-authored callback selected through `dword_69B3F4`, but formal C++ remains unsafe until the alpha-map callback typedef, source descriptor layout, helper names, and Surface/GrafPort field names are resolved across the compat/RGB555 and RGB565 slot-5 pair.
- Incorporated current MCP session `3a33af0b` evidence at report-level detail and validated the edited target with scoped validator command `000000005850`.

## Supporting Research

This artifact began as B008 report-only research for target UID0002TD. After supervisor Gate 1 acceptance, B008 completed the implementation callback for the accepted by-* scope. The target by-memory doc was edited and scoped validation ran; support docs were reviewed read-only and found already-present at same-or-greater detail for the accepted support claims. B008 did not run `execute_report`, lifecycle/archive commands, registry commands, manual report moves, manual coverage edits, validator-state edits, generated-file edits, or supervisor-ledger edits.

Historical report-only context: the queue row in `auto-generated/-ag-research-tracker.md` listed UID0002TD as score `85/89`, combined `87.0`, reconstructable `true`, report count `0`; generated output `auto-generated/NexusTK/render/Surface.cpp` emitted UID0002TD as an `Empty Emitter Marker` at `Completion:85 | Confidence:89`. B008 did not manually edit generated/tracker files during the callback. The scoped validator recorded `completion_update:1`, `confidence_update:1`, `projected_stats_update:1`, `stats_row_remove:1`, `stats_rescore_recommended:1`, and `generated_refresh: deferred`.

Relevant local docs checked read-only:

- `by-memory/0x004bdf40-0x004be0db.SoftwareRenderCompatAlphaLookupBlitCallback.md`
- `by-memory/0x004bb8d0-0x004c069e.SoftwareRenderCompatCallbacks.md`
- `by-memory/0x004c3cf0-0x004c3e93.SoftwareRenderRgb565AlphaLookupBlitCallback.md`
- `by-file/Surface.md`
- `by-global/SurfaceRenderCallbackTable.md`
- `by-memory/0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable.md`
- `by-memory/0x0069b3d8-0x0069b3e0.SurfaceAlphaLookupTablePointers.md`
- `by-file/SoftwareBlend16.md`
- `by-memory/0x0045fa00-0x004604f4.Rgb555565BlitHelpers.md`
- `auto-generated/NexusTK/render/Surface.cpp`
- `auto-generated/-ag-research-tracker.md`

Prior report/support leads checked read-only:

- `executed-b-agent-research/B001/00016J-SoftwareRenderCompatCallbacks.md`
- `executed-b-agent-research/B001/00016L-SoftwareRenderRgb565Callbacks.md`
- `executed-b-agent-research/B005/0000OC-Surface-empty-emitter-family-source-quality.md`
- `executed-b-agent-research/B013/0002TB-SoftwareRenderCompatRleFillCallback-source-quality.md`
- `executed-b-agent-research/B012/0002PH-SoftwareRenderCompatSpriteBlitCallback-source-quality.md`

## Target

- Target UID: `0002TD`
- Target path: `by-memory/0x004bdf40-0x004be0db.SoftwareRenderCompatAlphaLookupBlitCallback.md`
- Range: `0x004bdf40-0x004be0db`
- Current IDA name: `sub_4BDF40`
- Current generated-name candidate if emitted: `RankingEventListPane::BlitAlphaBlend_555`
- Current source role: compat/RGB555 alpha/color lookup blit callback installed into `SurfaceRenderCallbackTable` slot 5 / `dword_69B3F4`.

## Current Target State

Current target metadata:

| Field | Current value |
| --- | --- |
| `COMPLETION` | `85` |
| `CONFIDENCE` | `89` |
| `CANONICAL_OWNER` | `0000OC` |
| `RECONSTRUCTABLE` | `TRUE` |
| `EMITTER_UIDS` | `0000OC` |
| `EMITTER_POSITION_OPTIONAL` | blank |
| formal C++ | blank |

Current state is mostly correct. The function already has a valid direct Surface owner/emitter route, is live through callback-table assignment, and is not a no-owner or padding target. The report gap is direct B-report coverage and a fresh MCP-backed source-quality decision for why formal C++ remains blank.

## Executive Recommendation

Apply a target-page evidence and score refresh, not a reroute.

Recommended target state:

| Field | Recommended value |
| --- | --- |
| `COMPLETION` | `87` |
| `CONFIDENCE` | `90` |
| `CANONICAL_OWNER` | `0000OC` |
| `RECONSTRUCTABLE` | `TRUE` |
| `EMITTER_UIDS` | `0000OC` |
| `EMITTER_POSITION_OPTIONAL` | blank |
| formal C++ | blank |

The target should remain an empty generated marker for now, but with explicit target-specific no-code proof rather than open-ended wording. It should not be moved to `RankingEventListPane`, `SoftwareBlend16`, `SurfaceRenderCallbackTable`, the compat aggregate, or a new one-off by-file owner.

## Supervisor Active Recheck

MCP was available and schema-current for this pass. No `PAUSED_MCP_UNAVAILABLE` condition occurred.

- Endpoint: `http://127.0.0.1:13337/mcp`
- `initialize`: succeeded; server `ida-pro-mcp`, protocol `2025-06-18`.
- `idb_list`: one active NexusTK session, `3a33af0b`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, active worker PID `8596`, `is_analyzing:false`.
- `server_health(database=3a33af0b)`: `status:ok`, module `NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready, string cache size `2067`.
- Narrow MCP tools used: `lookup_funcs`, `int_convert`, `get_bytes`, `xref_query`, `callees`, `func_profile`, `analyze_function`, `decompile`, and bounded `disasm`.

## Inference Research Guidance Check

The target has strong binary facts and support-doc agreement, but final C++ would still require inference beyond the evidence.

Resolved:

- Exact function range and padding.
- Runtime reachability through callback-table slot `dword_69B3F4`.
- Surface/render-dispatch ownership.
- RGB555/compat role and RGB565 peer.
- Callee set and body behavior.
- Lookup-table dependencies at `0x0069b3d8` and `0x0069b3dc`.

Still inferred:

- Original callback typedef spelling and return type.
- Exact source name for this callback.
- Exact source descriptor type behind the `a3` argument passed to `sub_462300`.
- Final names for destination Surface/GrafPort fields at `+0x20`, `+0x28`, and `+0x71` in this target's context.
- Whether final source should live in broad `Surface.cpp` or a future whole-family `SoftwareRenderCallbacks.cpp`. Current by-* ownership should stay with Surface unless a future family-wide report creates and validates a better source root.

## Heuristic / Inference Reanalysis And Validation

The historical generated `RankingEventListPane::BlitAlphaBlend_555` candidate is callsite-biased. Current MCP and support docs show no ordinary direct caller to `0x004bdf40`; the only target-address xrefs are data refs from the raw initializer neighborhood and the Surface initializer function. Runtime dispatch uses the callback table slot `dword_69B3F4`, whose direct refs are shared render infrastructure, not Ranking UI ownership.

The body is also not a stateless `SoftwareBlend16` helper. It consumes destination receiver state, clips through GrafPort rectangle helpers, computes destination row pointers, uses a source setup helper, calls the SoftwareBlend16-owned `ApplyAlphaMap555` helper for an aligned prefix, and then performs callback-local scalar tail repacking through Surface lookup globals. `SoftwareBlend16` is therefore dependency/helper context only.

The RGB565 peer `0x004c3cf0-0x004c3e93` is already scored `87/90` with the same slot, same no-direct-caller state, same clip/setup/scalar-tail shape, and blank formal C++. Current MCP shows UID0002TD now has equivalent evidence density for the compat/RGB555 side. Matching the peer at `87/90` is warranted.

## Evidence Standards Used

- Current MCP evidence is preferred over stale historical MCP sessions.
- Exact-address MCP calls were used before any interpretation.
- Bounded calls only: target-specific function lookup, xrefs, bytes, callees, profile, decompile, and disassembly with `max_instructions:180`.
- Existing by-* docs and executed reports were treated as support leads and checked against current MCP.
- Generated output and tracker files were read only during research to understand the uncovered state; B008 did not manually edit generated or tracker files during callback.
- During implementation, only the target by-memory doc was edited. Support docs were checked read-only and recorded as already-present. The scoped validator ran only for the edited target by-* file.

## Evidence Checked

MCP calls and results:

- `idb_list`: active session `3a33af0b`, `NexusTK.exe.i64`, worker PID `8596`, `is_analyzing:false`.
- `server_health(database=3a33af0b)`: healthy, Hex-Rays ready.
- `lookup_funcs`: checked target, endpoint, successor, RGB565 peer, helper callees, slot runtime function, raw initializer neighborhood, and Surface initializer.
- `get_bytes`: checked exact target bytes, successor padding, table slot storage, and lookup pointer storage.
- `xref_query`: checked refs to `0x004bdf40`, `0x0069b3f4`, `0x0069b3d8`, and `0x0069b3dc`.
- `callees`: checked direct callee set for `0x004bdf40`.
- `func_profile`: checked instruction count, block count, prototype, caller count, callees, and constants.
- `decompile` and bounded `disasm`: checked source-shape behavior, draw guard, clipping, setup, bulk prefix, scalar tail, and stack cleanup.

Implementation callback checks:

- Scoped validator ran for `by-memory/0x004bdf40-0x004be0db.SoftwareRenderCompatAlphaLookupBlitCallback.md` with `--apply --queue-timeout 240`.
- `execute_report`, dry-run/probing equivalents, lifecycle/archive commands, registry commands, manual report moves, manual coverage edits, generated-file edits, validator-state edits, and supervisor-ledger edits were not run.
- Broad unbounded IDA searches were not used, per MCP output discipline.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C-0002TD-001 | UID0002TD is exactly `sub_4BDF40` at `0x004bdf40-0x004be0db`, size `0x19b` / 411 bytes; `0x004be0db` is not a function; successor `sub_4BE0E0` starts at `0x004be0e0`. | high | MCP `lookup_funcs`, `int_convert`, `get_bytes`; current target doc | `by-memory/0x004bdf40-0x004be0db.SoftwareRenderCompatAlphaLookupBlitCallback.md` / Address Range and IDA MCP Evidence | incorporate | applied: target now records current MCP session `3a33af0b`, range, size, non-function endpoint, successor, and RGB565 peer |
| C-0002TD-002 | The exact byte stream for the body and the five-byte `0xcc` padding at `0x004be0db-0x004be0e0` are current. | high | MCP `get_bytes 0x004bdf40 size 411`, `get_bytes 0x004be0db size 5` | Target IDA MCP Evidence / Address Range | incorporate | applied: target records body bytes as captured in the B008 report and padding bytes `cc cc cc cc cc` |
| C-0002TD-003 | The function start has exactly two target-address data refs, `0x005586fe` and `0x00558bb2`, and no ordinary direct callers. | high | MCP `xref_query 0x004bdf40`, `func_profile caller_count:0` | Target IDA MCP Evidence / Ownership Notes | incorporate | applied: target records refs `0x005586fe`/`0x00558bb2`, `caller_count:0`, and data/table reachability |
| C-0002TD-004 | Slot `dword_69B3F4` has four refs: runtime data ref at `0x0050a267` in `sub_5094B0`, raw initializer/table ref `0x00558791`, Surface initializer compat ref `0x00558bb2`, and RGB565 assignment ref `0x00558ece`. | high | MCP `xref_query 0x0069b3f4`; callback table docs | Target IDA MCP Evidence; support table docs | incorporate | applied: target records all four slot refs; support docs already had slot 5 mapping/storage |
| C-0002TD-005 | Direct callees are `0x004b96c0`, `0x004b7cc0`, `0x004b7eb0`, `0x00462300`, `0x0045faa0`, and `@__security_check_cookie@4`. | high | MCP `callees 0x004bdf40`; bounded disasm | Target IDA MCP Evidence / Behavior Notes | incorporate | applied: target records helper callee set and source role of clip/setup/bulk/security-cookie calls |
| C-0002TD-006 | The decompiler prototype is an artifact: `char __userpurge@<al>(int@<ecx>, __m64@<mm1>, int, __m64 *, int *)`. | high | MCP `func_profile`, target decompile | Target IDA MCP Evidence / Reconstruction Notes | incorporate | applied: target explicitly rejects the artifact prototype as source callback typedef proof |
| C-0002TD-007 | The body has 147 instructions, 9 basic blocks, no string refs, and 15 constants; this is a compact but nontrivial callback, not a trivial leaf. | high | MCP `func_profile`; bounded disasm | Target IDA MCP Evidence / Behavior Notes / Score Rationale | incorporate | applied: target records `func_profile` counts in IDA MCP Evidence and Behavior Notes |
| C-0002TD-008 | Body behavior: draw-enabled guard at `this+0x71`, clip/intersect setup through the three rect helpers, source setup through `0x00462300`, prefix call to `ApplyAlphaMap555` / `0x0045faa0`, then scalar RGB555 lookup-tail repack through `0x0069b3d8` and `0x0069b3dc`. | high | MCP decompile/disasm; helper and lookup docs | Target IDA MCP Evidence / Behavior Notes / Touched State | incorporate | applied: target records guard, destination fields, clip/setup helpers, prefix helper, lookup roots, scalar tail, and RGB555 repack |
| C-0002TD-009 | `Surface` / UID0000OC remains the direct owner and emitter; `SurfaceRenderCallbackTable` is storage/support, `SoftwareBlend16` is helper/math support, and the compat aggregate is a non-emitting inventory. | high | Current MCP no-direct-caller/table evidence; Surface, callback table, SoftwareBlend16, compat aggregate docs | Target Ownership Notes / Assignment Gate; support docs | incorporate | applied: target records Surface owner/emitter and support-role boundaries; support docs were checked already-present |
| C-0002TD-010 | Generated `RankingEventListPane::BlitAlphaBlend_555` is callsite/generator pollution and must not drive ownership. | high | No direct feature-pane callers, Surface/table support docs, compat aggregate docs | Target Ownership Notes | incorporate | applied: target rejects RankingEventListPane and preserves no-direct-feature-caller evidence |
| C-0002TD-011 | No range split, merge, padding reclassification, or successor merge is needed. | high | MCP lookup, bytes, support docs | Target Address Range / Reconstruction Notes / Ownership Notes | incorporate | applied: target records five-byte padding, successor boundary, and rejection of padding/range-extension alternatives |
| C-0002TD-012 | Score should move to `87/90`, owner/emitter remain `0000OC`, and formal C++ remains blank with target-specific no-code proof. | medium-high | Current MCP refresh, RGB565 peer score `87/90`, unresolved typedef/source layout | Target metadata / Reconstruction Notes / Score Rationale | incorporate | applied: target metadata now `87/90`; owner/emitter/reconstructable/blank emitter position and blank formal C++ preserved |
| C-0002TD-013 | Support docs are already consistent at same-or-greater detail for Surface ownership, callback-table slot 5, lookup roots, SoftwareBlend16 helper-only role, and compat aggregate inventory. | medium-high | Read-only support-doc review | `by-file/Surface.md`; compat aggregate; global/memory callback table docs | already-present | already-present: `by-file/Surface.md` UID0002TD row records Surface route and `dword_69B3F4`; compat aggregate records UID0002TD slot membership, non-emitting aggregate, Surface ownership, and Ranking rejection; table docs map slot 5 to `0x004bdf40`/`0x004c3cf0`; no support edit needed |

## Positive Evidence Summary

- Exact range and size are current: `sub_4BDF40`, `0x004bdf40-0x004be0db`, size `0x19b` / 411 bytes.
- The successor boundary is clean: `0x004be0db` is not a function, and `0x004be0db-0x004be0e0` is five bytes of `0xcc` padding before `sub_4BE0E0`.
- Target-address reachability is callback-table based: refs to `0x004bdf40` are data refs at `0x005586fe` and `0x00558bb2`; `func_profile` reports `caller_count:0`.
- Slot reachability is shared render infrastructure: refs to `dword_69B3F4` are `0x0050a267`, `0x00558791`, `0x00558bb2`, and `0x00558ece`.
- The function checks destination draw-enabled state at receiver offset `+0x71`.
- It obtains/intersects a clip rectangle through `0x004b96c0`, `0x004b7cc0`, and `0x004b7eb0`.
- It calls `0x00462300` to build source setup state from the third stack argument.
- It computes a destination pointer from receiver fields at `+0x20` and `+0x28`, source offsets from rect deltas, and a row stride from setup state.
- It rounds a horizontal prefix down with `& 0xfffffffc` and sends that aligned prefix to `0x0045faa0` / `ApplyAlphaMap555`.
- The scalar tail reads an 8-bit alpha/source byte and a 16-bit RGB555 destination pixel, then uses `g_surfaceColorLookup5Bit` / `0x0069b3d8` for low/high 5-bit channels and `g_surfaceColorLookup6Bit` / `0x0069b3dc` as the middle-channel root before writing a repacked RGB555 word.
- The RGB565 peer `0x004c3cf0-0x004c3e93` has already documented parallel source-family behavior and score `87/90`.

## IDA MCP Facts

Current session:

```text
database: 3a33af0b
idb_path: E:\NTK\Resources\NexusTK\NexusTK.exe.i64
module: NexusTK.exe
imagebase: 0x400000
auto_analysis_ready: true
hexrays_ready: true
strings_cache_ready: true
```

Function lookup:

| Query | Result |
| --- | --- |
| `0x004bdf40` | `sub_4BDF40`, size `0x19b` |
| `0x004be0db` | not a function |
| `0x004be0e0` | `sub_4BE0E0`, size `0x58e` |
| `0x004c3cf0` | `sub_4C3CF0`, size `0x1a3` |
| `0x004c3e93` | not a function |
| `0x0045faa0` | `sub_45FAA0`, size `0xd4` |
| `0x00462300` | `sub_462300`, size `0x17` |
| `0x004b96c0` | `sub_4B96C0`, size `0xa8` |
| `0x004b7cc0` | `sub_4B7CC0`, size `0xa9` |
| `0x004b7eb0` | `sub_4B7EB0`, size `0x1d` |
| `0x005094b0` | `sub_5094B0`, size `0x104d` |
| `0x00558690` | not a function |
| `0x00558840` | `sub_558840`, size `0x723` |

Size conversion:

| Value | Decimal |
| --- | ---: |
| `0x19b` | `411` |
| `0x1a3` | `419` |
| `0x5` | `5` |

Exact target byte stream from `get_bytes 0x004bdf40 size 411`:

```text
55 8b ec 83 ec 54 a1 24 2f 67 00 33 c5 89 45 fc
8b 45 08 53 8b d9 89 45 d0 56 8b 75 0c 57 80 7b
71 00 8b 7d 10 89 75 d8 0f 84 5a 01 00 00 8d 45
ec 50 e8 49 b7 ff ff 8d 45 dc 50 8d 45 ec 57 50
e8 3b 9d ff ff 8d 45 dc 50 e8 22 9f ff ff 83 c4
10 84 c0 0f 85 2f 01 00 00 8b 55 d8 8d 45 ac 8b
36 2b 37 8b 4d d0 8b 52 04 2b 57 04 8b 7d e0 03
75 dc 03 fa 50 e8 46 43 fa ff 8b 45 b8 0f af f8
89 45 c4 8b 43 20 03 fe 8b 73 28 8b ce 03 7d ac
0f af 4d e0 03 4d dc 8d 04 48 8b 4d e8 2b 4d e0
89 45 d8 8b 45 e4 2b 45 dc 99 83 e2 03 51 8d 1c
02 83 e3 fc 8d 04 36 8b 75 d8 53 ff 75 c4 89 45
c0 57 50 56 e8 97 1a fa ff 01 5d dc 8d 04 5e 03
fb 89 45 d0 8b 5d e8 83 c4 18 2b 5d e0 89 7d d4
89 5d d8 85 db 0f 8e 9d 00 00 00 8b 75 dc 66 90
8b d0 8b cf 8b 45 e4 2b c6 89 4d cc 89 55 c8 85
c0 7e 6a 0f b6 19 48 0f b7 12 8b 35 d8 b3 69 00
8b ca c1 e9 0a 83 e1 1f c1 ea 05 83 e2 1f 8b 0c
8e 0f b6 3c 19 8b 0d dc b3 69 00 66 c1 e7 05 8b
0c 91 8b 55 c8 0f b6 0c 19 66 0b f9 0f b7 0a 83
e1 1f 66 c1 e7 05 8b 0c 8e 0f b6 0c 19 66 0b f9
8b 4d cc 66 89 3a 41 83 c2 02 89 4d cc 89 55 c8
85 c0 7f 9f 8b 7d d4 8b 5d d8 8b 75 dc 8b 45 d0
4b 03 7d c4 03 45 c0 89 7d d4 89 45 d0 89 5d d8
85 db 0f 8f 68 ff ff ff 8b 4d fc 5f 5e 33 cd 5b
e8 5a 96 10 00 8b e5 5d c2 0c 00
```

Padding and adjacent storage:

| Region | Bytes |
| --- | --- |
| `0x004be0db`, size `5` | `cc cc cc cc cc` |
| `0x0069b3f4`, size `4` | `00 00 00 00` in the live IDB image read |
| `0x0069b3d8`, size `8` | `00 00 00 00 00 00 00 00` in the live IDB image read |

The current live IDB byte read for globals reports zeroes for the two storage ranges. Existing docs record initialized-image `ff` bytes historically; this report does not require changing the global pages because the UID0002TD target evidence depends on refs and behavior, not on rewriting global initial bytes.

Function profile for `0x004bdf40`:

- Prototype: `char __userpurge@<al>(int@<ecx>, __m64@<mm1>, int, __m64 *, int *)`
- Instruction count: `147`
- Basic block count: `9`
- Caller count: `0`
- Callee count in profile: `7` including the function label itself; external callee tool reports six direct callees.
- String refs: `0`
- Constants include `0x54`, `0x10`, `0x3`, `0xfffffffc`, `0x18`, `0xa`, `0x1f`, `0x5`, `0x2`, and stack-cleanup `0xc`.

## Function / Child Inventory

| Item | Range / address | Relationship | Recommendation |
| --- | --- | --- | --- |
| UID0002TD | `0x004bdf40-0x004be0db` | compat/RGB555 slot-5 alpha/color lookup blit callback | Keep exact target; Surface-owned/emitted; raise to `87/90`; keep formal C++ blank. |
| Successor padding | `0x004be0db-0x004be0e0` | five bytes of `0xcc` alignment | Keep as padding; do not merge into successor. |
| UID0002TE | `0x004be0e0-0x004be66e` | next compat callback table target / bitmask blit callback | No split or merge with UID0002TD. |
| UID0002TH | `0x004c3cf0-0x004c3e93` | RGB565 peer for same `dword_69B3F4` slot | Use as support comparison; no direct edit needed from this report. |
| UID0004BC | `0x0045faa0-0x0045fb74` | `ApplyAlphaMap555` helper called by UID0002TD prefix path | SoftwareBlend16-owned dependency, not UID0002TD owner. |
| UID00029V | `0x0069b3d8-0x0069b3e0` | lookup pointer roots read by UID0002TD scalar tail | Already source-ready globals through Surface; no direct edit needed. |
| UID0000TN / UID0001PI | `dword_69B3F4` slot | table/global storage and dispatch context | Already records slot 5 mapping and table role; no direct edit needed unless supervisor wants a current UID0002TD echo note. |

## Direct Xref / Caller Inventory

Target-address refs to `0x004bdf40`:

| From | Type | Function context |
| --- | --- | --- |
| `0x005586fe` | data | raw initializer neighborhood, no function record at `0x00558690` |
| `0x00558bb2` | data | `sub_558840`, size `0x723` |

Slot refs to `0x0069b3f4`:

| From | Type | Function context | Meaning |
| --- | --- | --- | --- |
| `0x0050a267` | data | `sub_5094B0`, size `0x104d` | runtime slot consumer/data ref |
| `0x00558791` | data | raw initializer neighborhood | table/setup ref |
| `0x00558bb2` | data | `sub_558840` | compat target assignment to slot 5 |
| `0x00558ece` | data | `sub_558840` | RGB565 peer assignment to slot 5 |

Lookup-root refs relevant to UID0002TD:

| Root | UID0002TD refs |
| --- | --- |
| `0x0069b3d8` | `0x004be04a` inside `sub_4BDF40` |
| `0x0069b3dc` | `0x004be065` inside `sub_4BDF40` |

No ordinary direct code caller to `0x004bdf40` was found.

## Documentation Evidence And IDA Status

Current docs are broadly consistent:

- `by-file/Surface.md` already lists UID0002TD as an exact compat/RGB555 alpha lookup blit callback selected through `dword_69B3F4`, rejects Ranking ownership, and keeps Surface as the direct render callback context.
- `by-memory/0x004bb8d0-0x004c069e.SoftwareRenderCompatCallbacks.md` already inventories UID0002TD under slot `dword_69B3F4` and explains the compat aggregate is non-emitting while exact child pages own source-bearing callback targets.
- `by-global/SurfaceRenderCallbackTable.md` and `by-memory/0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable.md` already map slot 5 to compat target `0x004bdf40` and RGB565 target `0x004c3cf0`.
- `by-memory/0x0069b3d8-0x0069b3e0.SurfaceAlphaLookupTablePointers.md` already emits the lookup-root globals and records UID0002TD read sites `0x004be04a` and `0x004be065`.
- `by-file/SoftwareBlend16.md` already limits direct ownership to stateless helpers and explicitly says the larger callback families are Surface/render-dispatch implementations that consume SoftwareBlend16 helpers.
- `by-memory/0x004c3cf0-0x004c3e93.SoftwareRenderRgb565AlphaLookupBlitCallback.md` already carries the parallel score/source-blocker model for the RGB565 peer.

The target page itself is the main stale/incomplete artifact: it still has no direct B-report coverage, remains lower-scored than the peer, and should carry current MCP session `3a33af0b` facts.

## Ranked Ownership Analysis

1. [UID:0000OC] `Surface` / `NexusTK/render/Surface.cpp`: best current owner/emitter. Evidence: target is installed by Surface initializer refs, the callback table belongs to Surface render infrastructure, there are no ordinary direct callers, the function operates on Surface/GrafPort render receiver state, and Surface clears the direct parent gate.
2. [UID:0000TN] / [UID:0001PI] `SurfaceRenderCallbackTable`: support context only. The table pages own storage/slot semantics, not this callback body.
3. [UID:0000NT] `SoftwareBlend16`: dependency context only. `ApplyAlphaMap555` and other blend helpers are SoftwareBlend16-owned, but UID0002TD is a table-installed stateful callback body.
4. `by-memory/0x004bb8d0-0x004c069e.SoftwareRenderCompatCallbacks`: correct non-emitting family inventory, not a direct emitter for this exact child.
5. `RankingEventListPane`: rejected. Current and historical generated labels are callsite/generator pollution; no direct feature-pane caller is present.
6. New `SoftwareRenderCallbacks.cpp` style by-file owner: plausible future family-wide source-root question, but not a safe single-target change. No current by-file page exists or clears a stronger gate than Surface.
7. No-owner/non-emitting: rejected for metadata. The function is live source-authored project code reached through a table slot; only the formal C++ body remains blank for source-quality reasons.

## Source Placement

Keep source placement through UID0000OC, generated path `NexusTK/render/Surface.cpp`.

The most likely original source shape is a Surface software-render implementation block or a sibling renderer callback source containing both compat/RGB555 and RGB565 callback families. Current docs do not justify creating a new by-file owner for one callback. If a future whole-family source-root report creates a validated `SoftwareRenderCallbacks.cpp` or equivalent page, UID0002TD should move only with the complete callback table/family, not as an isolated row.

## Range / Split / Padding / Reclassification Analysis

No range or split change is recommended.

- Keep `0x004bdf40-0x004be0db` as the exact UID0002TD function body.
- Keep `0x004be0db-0x004be0e0` as five bytes of `0xcc` alignment.
- Keep successor `0x004be0e0-0x004be66e` as UID0002TE.
- Do not extend backward into UID0002TC; the target starts cleanly at `0x004bdf40`.
- Do not split the prefix helper call or scalar tail into child by-memory pages; they are control-flow regions of one modeled function.

## Negative Evidence Summary

- Not a direct RankingEventListPane method: no direct code caller and only table/initializer refs.
- Not a `SoftwareBlend16` source body: the function is not a stateless math helper and consumes receiver/clip/source setup state.
- Not direct callback-table storage: `dword_69B3F4` is the storage/dispatch slot, while UID0002TD is one installed callback target.
- Not the compat aggregate owner: UID00016J is non-emitting inventory.
- Not padding or local jump data: `lookup_funcs` models a real function at `0x004bdf40`.
- Not a range-extension candidate: endpoint `0x004be0db` is followed by five `0xcc` bytes and successor `sub_4BE0E0`.
- Not ready for raw decompiler C++: current prototype and names are Hex-Rays artifacts.
- Not safe to invent final names for callback typedef, source descriptor, field names, or helper wrappers.

## IDA Rename / Type / Comment Recommendations

No IDA rename, type application, or IDB write was performed or recommended by B008 for this callback.

If a future supervisor-owned IDB label batch wants descriptive labels, `SoftwareRenderCompatAlphaLookupBlitCallback` is suitable as a documentation label for `sub_4BDF40`, but this report does not prove an original symbol. The current decompiler prototype should not be promoted to a source typedef.

## First-Draft C++ Recommendation

Do not insert formal C++ for UID0002TD in this pass.

The exact formal block to preserve in the target is:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Target-specific no-code proof:

- The current prototype is non-source-quality: `char __userpurge@<al>(int@<ecx>, __m64@<mm1>, int, __m64 *, int *)`.
- The function is a real callback body, not compiler glue, but it depends on unresolved source concepts: callback typedef, source setup descriptor, final helper names, source alpha-map pointer layout, and receiver field names.
- The prefix helper `0x0045faa0` already has a SoftwareBlend16 source route; reimplementing it inline in this callback would duplicate helper ownership.
- The scalar tail is understandable but still parameter-name and field-name dependent. Emitting it now would either preserve decompiler temporaries or invent final names.
- The RGB565 peer carries the same blank-C++ policy despite stronger score, so this target should match that family policy rather than prematurely emitting a partial body.

## Final Recommendation

Final disposition: UID0002TD should be accepted for a target evidence/metadata refresh, not for formal C++ emission.

Exact recommended changes:

- Target `by-memory/0x004bdf40-0x004be0db.SoftwareRenderCompatAlphaLookupBlitCallback.md`: set `COMPLETION:87`, `CONFIDENCE:90`.
- Keep `CANONICAL_OWNER:0000OC`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000OC`, and blank `EMITTER_POSITION_OPTIONAL`.
- Keep the formal `RECONSTRUCTION_CPP CODE` block blank.
- Add current MCP session `3a33af0b` evidence for exact range, exact bytes, no-direct-caller state, target refs, slot refs, helper callees, profile/prototype, lookup-root refs, prefix/tail behavior, and padding.
- Replace stale or open-ended "not final source quality" wording with the target-specific no-code proof above.

Parent assignment disposition:

- Keep direct owner/emitter as UID0000OC `Surface`.
- Treat UID0000TN/UID0001PI as support/table context only.
- Treat UID00016J as non-emitting aggregate inventory only.
- Treat UID0000NT `SoftwareBlend16` as helper/math dependency context only.

No-owner/non-emitting disposition:

- No-owner is rejected for metadata because UID0002TD is live via `dword_69B3F4` and has a valid Surface route.
- Formal C++ remains blank, but this is not a no-owner finding and not a "covered by" marker.

Future work outside this report scope:

- Whole-family callback typedef/source-root audit for compat and RGB565 slot 5.
- Final source names for `sub_462300`, `sub_45FAA0`, receiver fields, and callback argument types.
- Optional future migration to a dedicated software-render callback source root only if the whole callback family is modeled together.

## Recommended Target Doc Changes

For `by-memory/0x004bdf40-0x004be0db.SoftwareRenderCompatAlphaLookupBlitCallback.md`, these accepted changes were applied during the B008 implementation callback:

- Set `COMPLETION:87`.
- Set `CONFIDENCE:90`.
- Keep `CANONICAL_OWNER:0000OC`.
- Keep `RECONSTRUCTABLE:TRUE`.
- Keep `EMITTER_UIDS:0000OC`.
- Keep `EMITTER_POSITION_OPTIONAL:` blank.
- Keep formal `RECONSTRUCTION_CPP CODE` blank.
- Add current MCP session `3a33af0b` facts:
  - active IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, server health OK;
  - `sub_4BDF40` range `0x004bdf40-0x004be0db`, size `0x19b` / 411;
  - exact body bytes and five `0xcc` padding bytes after the endpoint;
  - `0x004be0db` not a function, successor `0x004be0e0` / `sub_4BE0E0`;
  - target refs at `0x005586fe` and `0x00558bb2`;
  - zero ordinary direct callers;
  - four `dword_69B3F4` refs at `0x0050a267`, `0x00558791`, `0x00558bb2`, and `0x00558ece`;
  - direct callees `0x004b96c0`, `0x004b7cc0`, `0x004b7eb0`, `0x00462300`, `0x0045faa0`, and `@__security_check_cookie@4`;
  - profile facts `147` instructions, `9` blocks, no strings, artifact prototype;
  - lookup-root reads at `0x004be04a` and `0x004be065`;
  - draw guard, clipping, setup helper, aligned prefix, scalar RGB555 lookup-tail repack.
- Add ownership notes explicitly rejecting RankingEventListPane, SoftwareBlend16 direct ownership, callback-table storage ownership, aggregate ownership, no-owner, padding, and range extension.
- Add score rationale explaining why `87/90` is justified and why the target should not go higher until formal callback/source layout is resolved.

## Recommended Support Doc Changes

B008 reviewed the accepted support scope and found the required facts already present at same-or-greater detail; no support by-* files were edited.

- `by-file/Surface.md`: already-present for UID0002TD owner/emitter/source-route facts. Its UID0002TD row records exact compat/RGB555 alpha lookup blit selected through `dword_69B3F4`, no direct code callers, only Surface initializer/table target refs, alpha/source setup, and bulk/tail lookup behavior.
- `by-memory/0x004bb8d0-0x004c069e.SoftwareRenderCompatCallbacks.md`: already-present for slot membership, Surface ownership, aggregate non-emitting disposition, and Ranking rejection. Its table row maps `dword_69B3F4` to UID0002TD / `sub_4BDF40`, and Evidence Notes record no direct callers, target-address refs `0x005586fe`/`0x00558bb2`, 4 slot refs, source setup, bulk helper use, and scalar alpha lookup-tail behavior.
- `by-global/SurfaceRenderCallbackTable.md`: already-present for slot 5 mapping to compat `0x004bdf40` and RGB565 `0x004c3cf0`, with alpha/color-LUT blit behavior, setup helper use, four-pixel bulk prefix, and scalar lookup-tail repack.
- `by-memory/0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable.md`: already-present for raw slot storage. Its storage table maps `dword_69B3F4` to compat `0x004bdf40` and RGB565 `0x004c3cf0`; no table C++ change was needed.
- `by-memory/0x0069b3d8-0x0069b3e0.SurfaceAlphaLookupTablePointers.md`: already-present for lookup-root names and UID0002TD read sites. No change was made based only on live zero-byte image reads from this target report.
- `by-file/SoftwareBlend16.md`: already-present for helper-only role and callback-family exclusion. No edit.
- `by-memory/0x0045fa00-0x004604f4.Rgb555565BlitHelpers.md` and child `by-memory/0x0045faa0-0x0045fb74.ApplyAlphaMap555.md`: already-present for helper dependency. No direct UID0002TD ownership change.
- `by-memory/0x004c3cf0-0x004c3e93.SoftwareRenderRgb565AlphaLookupBlitCallback.md`: already-present peer evidence and source-blocker model. No edit.

## Score And Metadata Recommendation

| Field | Before callback | Applied | Rationale |
| --- | ---: | ---: | --- |
| `COMPLETION` | `85` | `87` | Current MCP refresh closes the direct B-report coverage gap, reconfirms exact bytes/range/padding, zero direct callers, target refs, slot refs, helper callees, profile counts, lookup-root refs, and detailed prefix/tail behavior. It matches the RGB565 peer's evidence level but remains below final C++ readiness. |
| `CONFIDENCE` | `89` | `90` | Current MCP aligns with target/support docs and the peer page. Confidence rises to very strong for binary facts and ownership, but does not exceed final-audit range while names, typedefs, and source layout remain inferred. |
| `CANONICAL_OWNER` | `0000OC` | `0000OC` | Surface remains the direct semantic owner. |
| `RECONSTRUCTABLE` | `TRUE` | `TRUE` | Real source-authored callback implementation. |
| `EMITTER_UIDS` | `0000OC` | `0000OC` | Valid Surface output route. |
| formal C++ | blank | blank | Target-specific source-quality blocker remains active. |

## Open Questions With Attempted Resolution

| Question | Attempted resolution and evidence checked | Current disposition | Score / C++ impact | Evidence needed to resolve |
| --- | --- | --- | --- | --- |
| What is the final source callback typedef and return type for slot `dword_69B3F4`? | Checked MCP `func_profile` prototype `char __userpurge@<al>(int@<ecx>, __m64@<mm1>, int, __m64 *, int *)`, bounded decompile/disasm, `SurfaceRenderCallbackTable` slot docs, UID0002TH peer docs, and SoftwareBlend16 helper docs. The binary proves `ecx` receiver dispatch, three stack arguments, MMX/register artifact participation, and `retn 0x0c`, but not a source-safe typedef spelling. | Unresolved; keep raw prototype as evidence only. | Caps completion at `87`; blocks formal C++ because a source body would need a real callback signature rather than `__userpurge` artifact arguments. | Whole slot-5 compat/RGB565 typedef audit across caller dispatch sites and both installed targets, ideally with source-shaped parameter names validated against slot use. |
| What final source-facing name should UID0002TD and peer UID0002TH use? | Checked target/peer docs, callback table slot summary, Surface file row, generated `RankingEventListPane::BlitAlphaBlend_555` / peer generated names, and current MCP reachability. The role is proven as compat/RGB555 alpha/color-LUT blit, but generated Ranking naming is rejected as callsite pollution. | Partially resolved to descriptive documentation name `SoftwareRenderCompatAlphaLookupBlitCallback`; original symbol remains unproven. | Does not block metadata/score refresh, but blocks formal source emission if the function name would be presented as original-quality C++. | Family-wide naming pass for Surface software-render callbacks, including slot names, peer naming, and any source/header evidence. |
| What source descriptor type and field names are behind `sub_462300` and the third stack argument? | Checked MCP lookup for `0x00462300`, decompile evidence showing `sub_462300(v36, localState)`, UID0002TD source-pointer calculations, UID0002TH peer page, and SoftwareBlend16 helper relationships. Evidence proves source base/stride style setup but not the descriptor's source type or field names. | Unresolved; document as source setup helper only. | Blocks formal C++ because the body would otherwise invent descriptor, stride, and source-alpha names. | Dedicated report on `0x00462300` / source setup helper and its callers, plus cross-check against sprite/alpha-map callback source descriptors. |
| Should this eventually move from `Surface.cpp` to a dedicated `SoftwareRenderCallbacks.cpp` source root? | Checked `by-file/Surface.md`, B005 Surface family report, compat/RGB565 aggregate reports, callback table docs, and SoftwareBlend16 docs. Current project has a valid Surface route and no narrower by-file owner. B005 explicitly rejected creating a one-off `SoftwareRenderCallbacks.cpp` for selected callback work. | Resolved for this pass: do not move; keep UID0000OC owner/emitter. Future whole-family source-root audit remains outside scope. | No block for target metadata; C++ would still be blocked by typedef/source-layout issues even if a future source root existed. | A supervisor-assigned whole-family source-placement report that models the complete callback table initializer plus compat/RGB565 callback families and creates a validated by-file owner if justified. |
| Are `g_surfaceColorLookup5Bit` and `g_surfaceColorLookup6Bit` final names for `0x0069b3d8` / `0x0069b3dc`? | Checked UID00029V, Surface docs, current MCP xrefs, and B005 Surface implementation report. UID00029V already emits these as descriptive first-draft globals and records UID0002TD read sites `0x004be04a` / `0x004be065`. | Resolved enough for dependency references; not proven original names. | Does not block UID0002TD score refresh. It still contributes to C++ caution because using these names inside a full callback body would imply more source certainty than the callback signature currently supports. | Original source/header evidence or whole-family accepted naming policy for Surface lookup roots. |
| How should the live zero-byte reads for `0x0069b3d8` / `0x0069b3f4` be interpreted against older docs recording `ff` initial bytes? | Checked current MCP `get_bytes` for `0x0069b3d8` and `0x0069b3f4`, UID00029V, UID0001PI, and SurfaceRenderCallbackTable docs. The current report relies on xrefs and behavior, not changing global initial-byte claims. | Evidence recorded as a current observation only; no support doc change recommended from this target pass. | No score/C++ impact for UID0002TD because callback identity and behavior come from function bytes/xrefs/callees. | A separate global-storage freshness audit comparing IDB image state, loader-applied state, validator docs, and initializer effects for the callback table and lookup roots. |

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

No manual coverage, tracker, lifecycle, archive, registry, or generated-file edit was performed or recommended by B008. Supervisor-owned report execution/archive state is authoritative outside this callback.

## Follow-Up Actions

B008 implementation callback completed these actions:

1. Leased only the target by-memory file selected for editing and released it after validation.
2. Applied the target metadata/evidence/no-code-proof refresh to UID0002TD.
3. Checked support docs and marked same-or-greater detail as already-present rather than duplicating.
4. Ran the scoped validator for the edited target by-* file.
5. Updated this report's ledger/checklist with applied and already-present states.

B008 did not run `execute_report` or lifecycle/archive commands.

## Confidence

Overall report confidence: high for ownership, range, reachability, slot identity, helper callees, lookup-root dependencies, and score recommendation; medium-high for final source-placement wording because original file names and callback typedefs remain unresolved.

## Validator Results

- Target validator command:
  - Command: `python .\tools\validator.py --mode file --file by-memory/0x004bdf40-0x004be0db.SoftwareRenderCompatAlphaLookupBlitCallback.md --apply --queue-timeout 240`
  - Working directory: `E:\NTK\GhidraBridge\source-3\project-documentation`
  - `command_id`: `000000005850`
  - `command_timestamp`: `2026-07-03T23:17:58-04:00`
  - Exit code: `0`
  - `ok`: `1`
  - Warnings/errors: none reported.
  - Updates reported: `completion_update:1`, `confidence_update:1`, `projected_stats_update:1`, `stats_row_remove:1`, `stats_rescore_recommended:1`.
  - UID updates: `completion_update 0002TD ... 87`, `confidence_update 0002TD ... 90`.
  - Generated refresh: `deferred`; `generated_refresh_command_id: 000000005850`, `generated_refresh_timestamp: 2026-07-03T23:17:58-04:00`.

## Changed Files

Manual B008 edits:

- `by-memory/0x004bdf40-0x004be0db.SoftwareRenderCompatAlphaLookupBlitCallback.md`
- `tools/leaser/Agents/Agent-B008/research/0002TD-SoftwareRenderCompatAlphaLookupBlitCallback-source-quality.md`

Validator-owned side effect:

- `project-level/-auto-completion-stats.md` projected path completion section updated; validator reported generated refresh as deferred.

No support by-* docs, generated source files, coverage reports, validator state, report lifecycle state, archives, or supervisor ledgers were manually edited by B008.

## Lease State

- Leased: `by-memory/0x004bdf40-0x004be0db.SoftwareRenderCompatAlphaLookupBlitCallback.md` by `B008`, lease command returned `Success`.
- Released: same target by `B008`, unlease command returned `Success` immediately after validation.
- No support-doc leases were taken because support docs were already-present and read-only.

## Implementation Tracking Checklist

- [x] Update target metadata to `COMPLETION:87`, `CONFIDENCE:90`; keep owner/emitter/reconstructable/blank emitter position unchanged. Proof: target header now has `87/90`, `CANONICAL_OWNER:0000OC`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000OC`, blank emitter position.
- [x] Preserve the blank formal `RECONSTRUCTION_CPP CODE` block exactly. Proof: target formal block remains header, `BEGIN`, immediate `END` with no inserted C++.
- [x] Add current MCP session `3a33af0b` facts: health, range, exact bytes, padding, xrefs, slot refs, callee set, profile counts, prototype, decompile/disasm behavior, lookup-root refs. Proof: target IDA MCP Evidence and Behavior Notes record these details.
- [x] Replace broad source-shape blocker wording with the target-specific no-code proof from this report. Proof: target Reconstruction Notes now names unresolved typedef/return type, source-facing callback name, descriptor type/field names, and family-wide callback source layout.
- [x] Preserve rejected alternatives: not RankingEventListPane, not SoftwareBlend16 direct owner, not callback-table storage owner, not compat aggregate emitter, not no-owner, not padding, not range extension. Proof: target Ownership Notes and Reconstruction Notes preserve all rejected alternatives.
- [x] Check support docs listed in `Recommended Support Doc Changes`; mark same-or-greater detail as `already-present` rather than duplicating. Proof: support review recorded in ledger C-0002TD-013 and Recommended Support Doc Changes.
- [x] Run scoped validator from `source-3/project-documentation` for every edited by-* file after implementation. Proof: validator command `000000005850` exited `0`, `ok:1`.
- [x] Update this ledger/checklist during implementation callback with exact destination proof and validator command data.
- [x] Callback boundaries observed: no support by-* edits, no generated source edits, no coverage edits, no validator-state edits, no lifecycle/archive/execute commands, no supervisor-ledger edits. One validator-owned projected stats side effect was reported by scoped validation.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B008","command_id":"000000005864","destination_path":"executed-b-agent-research/B008/0002TD-SoftwareRenderCompatAlphaLookupBlitCallback-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B008/research/0002TD-SoftwareRenderCompatAlphaLookupBlitCallback-source-quality.md","timestamp":"2026-07-03T23:27:47-04:00","uid":"0002TD"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
