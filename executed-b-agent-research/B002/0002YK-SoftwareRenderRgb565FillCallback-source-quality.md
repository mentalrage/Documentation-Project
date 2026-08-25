** TARGET-REPORT-UID:0002YK **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID0002YK SoftwareRenderRgb565FillCallback Source-Quality Research

## Finalized Report / Current Recommendation

- Completed callback state: [UID:0002YK] is a source-ready `90/92` Surface-owned
  RGB565 rectangle-fill callback; its earlier blank-emitter `86/90` state is historical.
- Final disposition is applied: `CANONICAL_OWNER:0000OC`, `RECONSTRUCTABLE:TRUE`,
  `EMITTER_UIDS:0000OC`, blank `EMITTER_POSITION_OPTIONAL`, and `Nested:0` are
  preserved. Only this exact child page contains Destination 1's managed C++ block.
- C01-C30 and Destinations 1-14 are complete at report-level detail. Destinations 2-11
  contain target-specific support evidence, Destinations 12-13 were verified read-only
  at same-or-greater detail, and Destination 14 completed validator-driven generation.
- Gate 2 audit of callback report SHA
  `DBB919217DE08E26246FCD19C9A2A313A2EF215B84BC651DAC46500380A9DB5B`
  found only two support-prose defects. The repair preserved the accepted target/formal
  implementation and corrected those statements: primary palette index `128` is the
  software-buffer trigger, while the forced mapped RGB565 fill pixel is value `1`,
  exactly matching C16 and `fillPixel = 1`.
- Destination 1 uses the accepted `EPFTileContext` source member
  `rowStridePixels`, takes an `unsigned char *` byte view of its `void *pixelData`
  before applying the exact byte offset, and converts only the resulting address to
  `unsigned short *`. The earlier generic `rowStride` spelling and direct `void *`
  arithmetic are superseded report-draft forms, not accepted current source.
- The callback is a live slot-7 target, not an unassigned or dead helper. Its exact
  operation is clipping a requested rectangle and filling RGB565 pixels in direct,
  color-keyed, blended, or color-keyed blended mode.
- Confidence is high for the range, ABI, two installation routes, indirect dispatch,
  field use, palette path, all four modes, pair/tail loops, blend argument direction,
  local jump-table ownership, and Surface source route. The remaining cap is stripped
  original lexical spelling, chiefly the callback/global/enum tokens.

## Supporting Research

- Mandatory live IDA MCP evidence was collected read-only on 2026-07-13 through the
  streamable endpoint after a fresh initialize and schema check. At the final evidence
  check, `idb_list` showed the adopted active database
  `supervisor_nexustk_20260713`; `server_health` reported `ok`, image base
  `0x00400000`, and ready auto-analysis, Hex-Rays, and string cache. These are
  evidence-collection-time observations and do not assert later session availability.
- The evidence IDB was `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, for module
  `NexusTK.exe` and input image
  `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`.
- The final bounded lookup reconfirmed `0x004c4380` as `sub_4C4380`, size `0x340`,
  and `0x004c46c0` as not a function. Exact target bytes have SHA256
  `0551BA6DAED2F754CA72FDAED3E94D794D32AB33AAFF0595137DB5C3E8D1673E`.
- Live work covered target lookup, full decompile, paged disassembly, exact bytes,
  basic blocks, all exits, target and slot xrefs, target-address byte-pattern search,
  raw and modeled initializer sites, representative indirect dispatchers, palette and
  blend callees, zero-initialized slot/global storage, predecessor/successor functions,
  and both neighboring switch tables.
- Read-only documentation work covered the target, Surface class/file/global/storage
  routes, RGB565 aggregate and bitmask peer, compat fill peer, SurfacePresentation and
  both initializer pages, GrafPort class/file/state/clip pages, RectBounds helpers,
  PaletteLib/DLPalette/global palette pages, both RGB565 blend helpers, current
  generated Surface.cpp, generated memory coverage, and the research tracker.
- Old-report search terms were exactly `UID0002YK`, `UID:0002YK`, `0002YK`,
  `0x004c4380`, `0x004c46c0`, `SoftwareRenderRgb565FillCallback`, `UID00016L`,
  `UID0002TI`, `UID0002EV`, `UID00011J`, `UID00011R`, `dword_69B3FC`,
  `0x0069b3fc`, `0x00558811`, and `0x00558ee2`.
- Report roots and root-specific outcomes were:
  - Central executed root `executed-b-agent-research/`, searched recursively across
    `B001/` through `B015/` and `invalidated/`: the direct target subset
    `UID0002YK|UID:0002YK|0002YK|0x004c4380|0x004c46c0|SoftwareRenderRgb565FillCallback`
    matched exactly the five reports opened and classified below. The complete broad
    search-term list matched 80 Markdown reports because slot, family, and related-UID
    terms also select many consumers; none is a dedicated UID0002YK report beyond the
    five direct-target/family/consumer inputs below.
  - Legacy executed roots
    `tools/leaser/Agents/Agent-B001/research/executed/`,
    `tools/leaser/Agents/Agent-B002/research/executed/`,
    `tools/leaser/Agents/Agent-B003/research/executed/`,
    `tools/leaser/Agents/Agent-B004/research/executed/`,
    `tools/leaser/Agents/Agent-B005/research/executed/`,
    `tools/leaser/Agents/Agent-B006/research/executed/`,
    `tools/leaser/Agents/Agent-B007/research/executed/`,
    `tools/leaser/Agents/Agent-B008/research/executed/`,
    `tools/leaser/Agents/Agent-B009/research/executed/`,
    `tools/leaser/Agents/Agent-B010/research/executed/`,
    `tools/leaser/Agents/Agent-B011/research/executed/`,
    `tools/leaser/Agents/Agent-B012/research/executed/`,
    `tools/leaser/Agents/Agent-B013/research/executed/`,
    `tools/leaser/Agents/Agent-B014/research/executed/`, and
    `tools/leaser/Agents/Agent-B015/research/executed/`: all fifteen roots were absent
    at search time, so they contained zero matching legacy reports.
  - Archived root `archived/`, including existing roots
    `archived/b-agent-reports-20260623/` and
    `archived/duplicate-loose-b-agent-reports/`: zero matching Markdown reports were
    found. Two broad slot-only matches were archived B001 scratch JSON files,
    `archived/b-agent-reports-20260623/Agent-B001/research/scratch/00011B-ida-progressbar-update-draw.json`
    and
    `archived/b-agent-reports-20260623/Agent-B001/research/scratch/000116-ida-progressbar-range-setters.json`;
    both only record ProgressBar calls to `dword_69B3FC`, are not reports, and are not
    direct UID0002YK coverage.
  - Active report roots `tools/leaser/Agents/Agent-B001/research/`,
    `tools/leaser/Agents/Agent-B002/research/`,
    `tools/leaser/Agents/Agent-B003/research/`,
    `tools/leaser/Agents/Agent-B004/research/`, and
    `tools/leaser/Agents/Agent-B005/research/`: the original pre-creation search found
    no competing UID0002YK report. The repair recheck finds this report as the expected
    self-match and B004's active
    `0003XB-GrafPortStateAndClipRawHelpers-source-quality.md` only through its broad
    UID0002EV support mention; that report targets UID0003XB and contains no
    UID0002YK/address/name coverage.
- Excluding this same B002 artifact, no other dedicated active, central executed,
  legacy executed, or archived source-quality report for UID0002YK was found. Exact
  matching central executed reports opened as research inputs were:
  - `executed-b-agent-research/B001/00016L-SoftwareRenderRgb565Callbacks.md`:
    established the twelve-child RGB565 inventory, Surface ownership, target range,
    two initializer references, 206 slot references, and prior blank-C++ blockers.
  - `executed-b-agent-research/B012/0002TI-SoftwareRenderRgb565BitmaskBlitCallback-source-quality.md`:
    established the closest accepted RGB565 callback ABI/source style, predecessor
    switch-table boundary, Surface file route, clipping/palette fields, and
    compiler-local switch-table disposition.
  - `executed-b-agent-research/B004/0002EV-ChattingPaneOnPaint-source-quality.md`:
    established three concrete slot-7 receiver-plus-rectangle consumers and accepted
    `FillRect` source-facing use at those call sites.
  - `executed-b-agent-research/B001/00011J-EPFImageControlPaneCore-empty-emitter-source-quality.md`:
    established another slot-7 receiver-plus-bounds consumer, rejected
    `g_pfnLockSurface`, and confirmed both installed fill targets.
  - `executed-b-agent-research/B005/00011R-RectangleControlPanePaint-source-quality.md`:
    supplied additional control-paint slot-7 evidence; its target mentions are
    consumer support, not direct coverage of UID0002YK.
- No `Wave2` or `Wave3` mention was found in the target, Surface owner, or direct
  support pages searched for this pass. Generated source was used only to inspect the
  current empty-emitter symptom, never as binary truth.

## Target

- Target UID: `0002YK`.
- Target path:
  `by-memory/0x004c4380-0x004c46c0.SoftwareRenderRgb565FillCallback.md`.
- Evidence-collection-time queue row: `auto-generated/-ag-research-tracker.md`,
  `## by-memory` reconstructable not-covered queue, then `86/90`, average `88.0`,
  reports `0`. Current/future tracker and report-count state is validator-owned and is
  not asserted here.
- Callback classification: reconstructable exact source function assigned semantically
  and for emission to [UID:0000OC] Surface, with one complete formal C++ body.
- Applied scores and parent state: `90/92`, owner/emitter UID0000OC, reconstructable
  true, blank position, `Nested:0`.

## Current Target State

- Applied metadata: `COMPLETION:90`, `CONFIDENCE:92`,
  `CANONICAL_OWNER:0000OC`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000OC`, blank
  `EMITTER_POSITION_OPTIONAL`, and `Nested:0`.
- Applied C++ state: the sole managed block is Destination 1 byte-for-byte. Validator
  command `000000009825` completed B002's waited Gate 2 repair refresh. A later external
  validator refresh produced current generated header command `000000009839` at
  `2026-07-13T11:56:49-04:00`; the read-only snapshot contains exactly one UID0002YK
  definition, no target Empty Emitter Marker, and exactly one `fillPixel = 1;` override.
- Historical blocker: the prior Item Summary said the child remained unassigned because
  completion was below 85 and field/signature/branch-table work was needed. That state
  is explicitly superseded; the updated target preserves the history while recording
  the resolved field, signature, branch-table, behavior, and source-form blockers.
- Valid state preserved: exact descriptive role, two setup references,
  no ordinary direct caller, broad slot fanout, Surface owner/emitter, GrafPort
  clipping/palette fields, and BlendRgb565Pixel/Pair dependencies.
- Related target/support docs checked: UID00016L, UID0002TI, UID0002YF, UID0000OC,
  UID0000TN, UID0001PI, UID00039V, UID00039W, UID00005V, UID000162, UID000163,
  UID000164, UID00015S, UID0000RW, UID00016M, UID00016N, and UID0000NT.
- Callback status: all B002 target/support edits, scoped validators, waited generated
  verification, report updates, and lease releases are complete. B002 did not run
  `execute_report` or any lifecycle/move/archive command. Current/future report path,
  count, validation, execution, move, and archive state is external validator-owned and
  is not asserted by this report.

## Executive Recommendation

- Keep the direct semantic owner and output route as [UID:0000OC] Surface. This is a
  file-local software backend callback selected with the other compatibility/RGB565
  table targets, not a GrafPort member method and not a presentation/UI method.
- Use source-facing function name `FillRgb565RectCallback`. Its logical slot ABI is a
  void-returning receiver-in-ECX callback taking one constant rectangle pointer on the
  stack. The formal free-function reconstruction uses the accepted project pattern:
  `__fastcall`, a `GrafPort *` first parameter, and an unused EDX shim.
- Preserve the exact binary behavior, including the otherwise surprising mode-3 odd
  width path: it blends ceiling(width/2) packed pairs and then blends one additional
  16-bit pixel. That is likely an original source defect, but normalizing it would not
  be behavior-identical.
- Only the target was raised to `90/92`. All support scores and metadata remain
  unchanged; target-specific evidence prose was incorporated into Destinations 2-11.
- Do not create a child for either neighboring jump table, security-cookie sequence,
  memset lowering, or duplicated epilogue. They are compiler products of this and the
  predecessor function.

## Supervisor Active Recheck

- Gate 1 accepted exact report SHA
  `A3D4AC4C5BC55BF3FEBB38C9CDF43C74D37F5CFF88BB6F151C9E07C5767771F2` and
  authorized the bounded callback. MCP database `supervisor_nexustk_20260713` remains
  an evidence-collection-time identifier only; no present availability is asserted.
- The item did not require a split repair. The exact modeled body remains one function
  at `[0x004c4380,0x004c46c0)`; its four-entry jump table is adjacent local data.
- There are no source-bearing children to create. Every source operation in the range
  is represented in Destination 1, and every compiler artifact has a precise no-child
  disposition.

## Inference Research Guidance Check

- The project inference discipline requires the highest-probability coherent source
  form after direct facts are exhausted; it does not permit retaining `sub_`, `dword_`,
  raw offsets, or a blank emitter merely because original symbols are stripped.
- Existing hypotheses rechecked rather than inherited were: callback liveness,
  `dword_69B3FC` semantics, exact range, callback return/type, field names, palette
  source, mode names, alpha direction, branch-table ownership, and Surface placement.
- Direct IDA facts are addresses, bytes, control flow, ABI mechanics, xrefs, fields,
  callees, constants, and reads/writes. Documentation evidence supplies accepted class
  layouts and helper contracts. Inference supplies original lexical spellings and the
  most plausible local enum names.
- `by-structure.md` permits formal C++ because the target is reconstructable, has a
  valid emitter route, clears the combined-score gate, and now has complete range,
  dependency, source-placement, naming, and behavior evidence. It also requires this
  page's block to contain only source represented by this exact range.
- No current Wave2/Wave3 evidence was used. Any historical generated alias such as
  `g_pfnLockSurface` is rejected unless independently supported by live binary facts;
  here it is directly contradicted by receiver-plus-rectangle fill behavior.

## Heuristic / Inference Reanalysis And Validation

### Range and compiler products

- `sub_4C4380` is exactly `0x340` bytes with 281 instructions, 47 basic blocks, and
  cyclomatic complexity 26. All exits belong to one function and pop four argument
  bytes. The security-cookie setup/check and duplicated epilogues are compiler output.
- The predecessor table at `0x004c4364-0x004c4374` belongs to UID0002TI, followed by
  twelve `0xcc` alignment bytes. The successor interval `0x004c46c0-0x004c46d0`
  consists of four pointers back into UID0002YK and belongs to this target's switch.
  Neither interval is a source child or handwritten data declaration.

### ABI, liveness, and slot

- IDA's provisional `void __thiscall(int, __int128 *)` shape is mechanically correct
  about ECX, one 16-byte rectangle object pointer, and no return, but wrong in source
  naming/types. Representative indirect callers load a GrafPort into ECX, push a
  `RectBounds *`, call slot `0x0069b3fc`, and do not consume EAX.
- The callback target has exactly two data references and no direct code call: raw
  setup `0x00558811` loads its address, while modeled initializer `0x00558ee2`
  stores it directly into slot `0x0069b3fc`. This is normal callback liveness, not dead
  code. A raw-byte search found the target VA encoding only at those two immediates.
- Live bytes show slot `0x0069b3fc` is zero-initialized in the image and populated by
  setup code. Any older all-`ff` initial-value statement for this exact slot is
  superseded; it must be preserved only as labeled historical evidence.
- The source-facing slot name `g_fillRectCallback` is descriptive/inferred, while
  consumer method spelling `FillRect` is strongly supported. Preserve raw
  `dword_69B3FC` in evidence only and reject `g_pfnLockSurface`.

### Fields, clipping, and addressing

- `+0x71` is accepted `m_drawEnabled`; false returns before any helper or write.
- `GetClipRect` writes current clip bounds. `IntersectRects` is called clip first,
  requested rectangle second, with the requested local also used as output.
  `IsRectEmptyOrInvalid` rejects right <= left or bottom <= top.
- Destination pixel address is exactly a byte view of `pixelData` plus twice
  `(clipped.left + rowStridePixels * (clipped.top - bounds.top) - bounds.left)`,
  converted to `unsigned short *` only after that byte offset is applied. Accepted
  fields are embedded `m_surfaceContext.pixelData` (`void *`) at `+0x20`,
  `m_surfaceContext.rowStridePixels` (`int`, logical pixels rather than bytes) at
  `+0x28`, and surface bounds left/top at `+0x2c/+0x30`. The unqualified
  `rowStride` token survives only as an explicitly historical alias from the earlier
  report draft; direct arithmetic on the accepted `void *pixelData` type is rejected.
- `+0x70` is signed-byte-dispatched draw mode, `+0x74` is the active draw/palette
  color, `+0x78` is inferred `m_secondaryDrawColor`, `+0x84` is borrowed
  `DLPalette *m_palette`, `+0x90` is accepted `m_alpha`, and `+0x94` is
  `m_usesSoftwareBuffer`, not a dirty flag.

### Palette and mode behavior

- The callback uses `m_palette` when non-null and otherwise calls
  `g_pPaletteLib->GetCurrentPalette()`. It maps `m_drawColor` to RGB565, then also maps
  `m_secondaryDrawColor` and discards that result. The second call remains in the
  formal body because it is observable and may have side effects.
- IDA global `dword_67A7E0` is accepted [UID:0000RW] `g_pPaletteLib`, a
  zero-initialized singleton pointer populated elsewhere; it is not a palette object or
  callback-local static.
- If software buffering is enabled and the primary palette index is exactly 128, the
  mapped fill pixel is forced to value 1.
- Mode 0 is unconditional direct fill. Mode 1 is direct fill only when the primary
  color index is nonzero. Mode 2 is unconditional alpha blend. Mode 3 is alpha blend
  only when the primary color index is nonzero. Any other byte value returns without
  pixel writes.
- Direct modes write an odd trailing 16-bit pixel at `width & ~1` and then write
  `width/2` packed pairs. Rows advance by `rowStridePixels` 16-bit pixels, equivalently
  twice that logical stride in bytes.
- Blend weight is exactly the low byte of integer conversion of
  `m_alpha * 32.0f + 0.5f`; there is no clamp. The helpers weight their first argument
  by that value and their second by `32-weight`, so `m_alpha` weights the existing
  destination, not the incoming fill color.
- Mode 2 blends only the even pair width and then blends one trailing pixel for odd
  width. Mode 3 instead loops packed pairs while x is less than the full width and
  then performs the same odd tail. For odd widths, this touches two pixels beyond the
  nominal last in-range pixel. This asymmetry is exact and intentionally retained.

### Rejected alternatives

- Rejected `GrafPort::FillRect` member definition: the installed target is selected as
  a file-local backend function, has no member call references, and uses ECX as a
  callback receiver supplied by slot dispatch.
- Rejected SurfacePresentation ownership: setup writes occur there, but the callback
  body is contiguous with the Surface RGB565 backend family and has no presentation
  receiver state.
- Rejected SoftwareBlend16 ownership: it owns BlendRgb565Pixel/Pair math, while this
  target owns clipping, GrafPort state, palette selection, and callback dispatch role.
- Rejected no-code/blank-emitter disposition: all branches, helpers, fields, ABI,
  source route, and source-operation reductions are resolved.
- Rejected compiler-shaped C++ with jump-table arrays, cookie calls, `memset32`,
  decompiler temporaries, raw offsets, or duplicated epilogues.

## Evidence Standards Used

- Highest rung: live IDA MCP function identity, exact bytes, disassembly/decompile,
  control flow, all target xrefs, slot xrefs, callers, callees, initializer stores,
  adjacent functions, and target-address pattern search.
- Corroborating rung: current accepted by-* class/layout/helper documentation, current
  generated-output state, queue state, and five classified executed reports.
- Inference rung: original callback/global/enum/local token spellings and exact source
  declaration organization. These are explicitly labeled inferred and capped below
  near-final scores.
- Binary context is strong: the target sits inside a paired compatibility/RGB565
  callback family, is installed into a fixed process-wide slot, and is dispatched by
  more than two hundred slot references.
- The evidence is sufficient for behavior-identical first-draft C++. It is not
  sufficient for `95+` because stripped symbols prevent extreme proof of original
  lexical names and exact header-level table declaration spelling.

## Evidence Checked

- The exact report-search terms were `UID0002YK`, `UID:0002YK`, `0002YK`,
  `0x004c4380`, `0x004c46c0`, `SoftwareRenderRgb565FillCallback`, `UID00016L`,
  `UID0002TI`, `UID0002EV`, `UID00011J`, `UID00011R`, `dword_69B3FC`,
  `0x0069b3fc`, `0x00558811`, and `0x00558ee2`.
- Exact report roots searched and outcomes:
  - Central executed `executed-b-agent-research/` recursively, including `B001/`
    through `B015/` and `invalidated/`: five direct UID/address/name matches, all
    opened and classified under Supporting Research; 80 Markdown hits under the full
    broad term list due incidental slot/family/related-UID mentions; no dedicated
    UID0002YK report.
  - Legacy executed roots `tools/leaser/Agents/Agent-B001/research/executed/`,
    `tools/leaser/Agents/Agent-B002/research/executed/`,
    `tools/leaser/Agents/Agent-B003/research/executed/`,
    `tools/leaser/Agents/Agent-B004/research/executed/`,
    `tools/leaser/Agents/Agent-B005/research/executed/`,
    `tools/leaser/Agents/Agent-B006/research/executed/`,
    `tools/leaser/Agents/Agent-B007/research/executed/`,
    `tools/leaser/Agents/Agent-B008/research/executed/`,
    `tools/leaser/Agents/Agent-B009/research/executed/`,
    `tools/leaser/Agents/Agent-B010/research/executed/`,
    `tools/leaser/Agents/Agent-B011/research/executed/`,
    `tools/leaser/Agents/Agent-B012/research/executed/`,
    `tools/leaser/Agents/Agent-B013/research/executed/`,
    `tools/leaser/Agents/Agent-B014/research/executed/`, and
    `tools/leaser/Agents/Agent-B015/research/executed/`: all absent, zero legacy
    report matches.
  - Archived `archived/`, including `archived/b-agent-reports-20260623/` and
    `archived/duplicate-loose-b-agent-reports/`: zero matching Markdown reports; two
    ProgressBar scratch JSON slot-only hits, neither a report nor direct coverage.
  - Active `tools/leaser/Agents/Agent-B001/research/`,
    `tools/leaser/Agents/Agent-B002/research/`,
    `tools/leaser/Agents/Agent-B003/research/`,
    `tools/leaser/Agents/Agent-B004/research/`, and
    `tools/leaser/Agents/Agent-B005/research/`: no competing UID0002YK report. On
    repair recheck, only this report self-matches directly; B004 UID0003XB is an
    incidental broad UID0002EV-term hit and contains no target UID/address/name
    coverage.
- IDA MCP/manual checks: `idb_list`, `server_health`, `lookup_funcs`, `decompile`,
  `disasm`, `analyze_function`, exact byte reads, basic blocks, xrefs to target and
  slot, setup-site disassembly, caller-site disassembly, callee lookup/decompile,
  predecessor/successor lookup, local table xrefs, and target-VA byte-pattern search.
- Exact IDA items checked: target `0x004c4380`, end `0x004c46c0`, predecessor end/table
  `0x004c4364`, successor `0x004c46d0`, setup `0x00558811` and `0x00558ee2`, shared
  raw store `0x00558770`, slot `0x0069b3fc`, palette global `0x0067a7e0`, palette
  helpers `0x00543d40`/`0x00542ac0`, clipping helpers `0x004b96c0`/
  `0x004b7cc0`/`0x004b7eb0`, and blend helpers `0x004c6050`/`0x004c60d0`.
- Representative slot dispatch sites checked: `0x0049933b`, `0x0047f951`,
  `0x0047f972`, `0x0047fab0`, `0x00494e6e`, and `0x00494e86`.
- by-* docs checked: target, Surface owner, RGB565 aggregate/peers, callback table
  global/storage, raw/modeled initializer, SurfacePresentation, GrafPort class/file and
  state/clip helpers, RectBounds geometry, PaletteLib/DLPalette/global palette, and
  BlendRgb565Pixel/Pair plus SoftwareBlend16.
- Generated/tracker read-only checks: `auto-generated/NexusTK/render/Surface.cpp`,
  `auto-generated/-ag-memory-coverage.md`, and
  `auto-generated/-ag-research-tracker.md`.
- Negative checks: no direct target code caller, no function at `0x004c46c0`, no
  extra target-pointer encoding, no strings, no vtable entry, no inline duplicate, no
  separate funclet, no source-authored switch-table child, and no target-specific old
  report.
- One typed-global query could not interpret raw floating constants as typed globals;
  raw bytes and instruction operands were read instead and directly established
  `32.0f` and `0.5f`. The bounded MCP calls and session remained healthy; this was a
  type-query limitation, not missing IDB evidence.
- During report-only evidence collection, IDA writes, source renames, implementation
  validators, leases, generated refresh, lifecycle commands, and report execution were
  intentionally skipped. The later authorized callback validators are recorded below.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | Target becomes `90/92`; owner UID0000OC, emitter UID0000OC, reconstructable true, blank position, and Nested 0 remain. | High | Current metadata plus complete blocker audit. | Destination 1 applies the score and preserves every named metadata field. | incorporate | applied |
| C02 | Exact function is `[0x004c4380,0x004c46c0)`, size `0x340`, 281 instructions, 47 blocks, complexity 26, exact byte SHA recorded. | High | Live lookup/analyze/bytes. | Destinations 1-3 contain the exact profile and hash. | incorporate | applied |
| C03 | Predecessor table `0x4c4364-0x4c4374` belongs to UID0002TI and `0x4c4374-0x4c4380` is 12-byte padding. | High | Bytes/table xrefs/accepted TI report. | Destinations 1 and 3 preserve exact predecessor boundary ownership and padding. | incorporate | applied |
| C04 | Target-local table `0x4c46c0-0x4c46d0` has four internal targets; next function begins `0x4c46d0`. | High | Bytes/xrefs/lookup. | Destinations 1 and 3 document the local table as switch lowering and create no child. | incorporate | applied |
| C05 | Security cookie, duplicated exits, jump-table lowering, and packed fill lowering are compiler products, not source children. | High | Full disassembly/control flow. | Destination 1 records the exclusion; generated output contains none as handwritten source. | reject-invalid | excluded-with-reason |
| C06 | Logical ABI is void receiver-in-ECX plus one constant RectBounds pointer and `retn 4`; formal free callback uses fastcall receiver/unused-EDX shim. | High | Prologue/exits/callers/peer. | Destinations 1, 4, and 5 contain the exact logical ABI and formal signature. | incorporate | applied |
| C07 | Target has two data refs at `0x558811` and `0x558ee2`, no direct code callers, and only two encoded target-address occurrences. | High | Xrefs and byte-pattern search. | Destinations 1, 6, and 7 contain liveness and negative pointer-route proof. | incorporate | applied |
| C08 | Slot `0x69b3fc` is zero-initialized, later assigned by setup, has 206 refs and broad indirect dispatch; current classification found 130 modeled caller functions plus 7 raw/unmodeled sites. Older all-`ff` and 131-function wording is historical/counting-method drift. | High | Slot bytes and xref enumeration. | Destinations 1, 4, and 5 contain live bytes/fanout and explicitly time-scope the older wording. | incorporate | applied |
| C09 | Raw setup loads target at `0x558811` and reaches shared slot store `0x558770`; modeled setup stores target at `0x558ee2`. | High | Setup disassembly/dataflow. | Destinations 6 and 7 contain both exact installation routes. | incorporate | applied |
| C10 | Draw-disabled `+0x71` returns before clipping or writes. | High | Target control flow. | Destinations 1 and 8-10 contain the exact early guard and field evidence. | incorporate | applied |
| C11 | Clip direction is GetClipRect, clip-first intersection into requested-local output, then empty/invalid rejection. | High | Calls and helper contracts. | Destinations 1 and 8-9 contain exact helper order/direction. | incorporate | applied |
| C12 | Destination math uses embedded `void *pixelData` at `+0x20`, `int rowStridePixels` at `+0x28`, and bounds left/top at `+0x2c/+0x30`; source must take an `unsigned char *` byte view before applying the exact doubled offset and then convert the resulting address to `unsigned short *`. | High | Target instructions plus current GrafPort and EPFTileContext declarations. | Destinations 1, 8, and 9 contain the exact formula/type route; Destination 12 verified the declarations read-only. | incorporate | applied |
| C13 | Draw state fields are mode `+0x70`, enabled `+0x71`, primary color `+0x74`, secondary color `+0x78`, palette `+0x84`, alpha `+0x90`, software-buffer flag `+0x94`; the adjacent embedded context source names remain `pixelData`, `rowStridePixels`, and `bounds`, not the historical generic `rowStride`. | High/inferred spelling | Target instructions plus accepted GrafPort and EPFTileContext support. | Destinations 1 and 8-11 contain every offset/name; Destination 12 verified the accepted context fields. | incorporate | applied |
| C14 | Palette is borrowed `m_palette` or fallback through zero-initialized singleton pointer `g_pPaletteLib` to `GetCurrentPalette()`. | High | Target calls/field, global bytes, and support docs. | Destinations 1 and 11 contain target use; Destination 12 verified same-or-greater contracts read-only. | incorporate | applied |
| C15 | Both primary and secondary colors are mapped; secondary result is discarded but call must remain. | High | Exact call sequence. | Destinations 1 and 10-11 preserve the observable second mapping call; Destination 12 verified contracts. | incorporate | applied |
| C16 | Software-buffer mode plus primary index 128 forces RGB565 pixel value 1. | High | Exact branch/store. | Destinations 1 and 8-10 now state unambiguously that index `128` is the trigger and pixel value `1` is the forced result. | incorporate | applied |
| C17 | Modes 0/1 are direct fill, with mode 1 gated by nonzero primary index. | High | Switch cases. | Destination 1 contains both direct-fill cases and gate. | incorporate | applied |
| C18 | Modes 2/3 are blends, with mode 3 gated by nonzero primary index. | High | Switch cases. | Destination 1 contains both blend cases and gate. | incorporate | applied |
| C19 | Unknown mode values return without writes. | High | Default case. | Destination 1 contains the exact default disposition. | incorporate | applied |
| C20 | Direct fill handles the odd tail first and packed pairs second, then advances the `unsigned short *` row view by `rowStridePixels`. | High | Cases 0/1 disassembly plus accepted logical-pixel stride type. | Destinations 1, 8, and 9 contain the behavior; Destination 12 verified the logical-pixel field. | incorporate | applied |
| C21 | Blend weight is the low byte of integer conversion of `alpha*32+0.5`, unclamped. | High | Instructions/constants. | Destination 1 contains the conversion/no-clamp behavior; Destination 13 verified same-or-greater helper contracts. | incorporate | applied |
| C22 | Blend helpers weight the existing typed destination pixel/pair by the supplied weight and the fill pixel/pair by the inverse weight. | High | UID00016M/UID00016N declarations/contracts. | Destination 1 preserves typed argument order/direction; Destination 13 verified the helper declarations read-only. | incorporate | applied |
| C23 | Mode 2 blends even pairs and one odd trailing pixel through typed pair/pixel views, then advances by `rowStridePixels`. | High | Case 2 loop plus accepted blend and stride declarations. | Destination 1 contains the exact loop; Destinations 12-13 verified its types/contracts read-only. | incorporate | applied |
| C24 | Mode 3 odd width blends ceil(width/2) typed pairs and then one additional typed pixel before advancing by `rowStridePixels`; the likely source bug is mandatory behavior. | High | Case 3 loop plus accepted blend and stride declarations. | Destination 1 preserves and labels the pair-plus-extra-pixel overrun; Destinations 12-13 verified types/contracts. | incorporate | applied |
| C25 | Highest-probability source name is `FillRgb565RectCallback`; slot source-facing role is FillRect, with `g_pfnLockSurface` rejected. | Medium-high lexical/high semantic | Target behavior, peers, consumers. | Destinations 1, 4, and 5 contain accepted descriptive names and stale-alias rejection. | incorporate | applied |
| C26 | Surface/Surface.cpp is direct owner/source; GrafPort is receiver type, SoftwareBlend16 is helper dependency, SurfacePresentation is initializer context. | High | Family contiguity/setup/receiver/callees. | Destinations 1-3 preserve owner/emitter and contain ranked source-placement reasoning. | incorporate | applied |
| C27 | Source order is after UID0002TI and before UID0002YL; blank metadata position remains because current child order is already deterministic and no numeric convention is established. | High | Binary order/current route. | Destinations 1-3 contain exact order while preserving blank position. | incorporate | applied |
| C28 | Destination 1 is the sole formal block; table, storage, initializer, by-file, GrafPort, palette, and blend pages receive no duplicate target body. | High | by-structure/by-file guidance. | Destinations 1-14 exclude duplicate bodies and by-file reconstruction metadata; exact-output audit confirms the result. | reject-invalid | excluded-with-reason |
| C29 | Pre-callback Empty Emitter Marker and tracker row were read-only symptoms; implementation verification must be through authorized waited generated refresh only. | High | Generated/tracker inspection. | Destination 14 completed initial waited command `000000009752` and latest Gate 2 repair command `000000009825`; no generated/tracker manual edit occurred. | incorporate | applied |
| C30 | Historical unassigned/below-85/field-signature-branch-table wording is superseded, while valid prior range/xref/owner/helper evidence remains. The earlier report draft's generic `rowStride` source alias and direct arithmetic on `void *pixelData` are also superseded; accepted current source uses `rowStridePixels` and a typed byte view. | High | Target history, current research, and current EPFTileContext declaration. | Destinations 1-9 retain old assumptions only as labeled history, apply the accepted field/type correction, and preserve provenance; Destination 12 verified declarations. | historicalize | applied |

### Callback Verification Proof

| Claims | Applied proof |
| --- | --- |
| C01-C04 | UID0002YK now records `90/92`, preserved owner/emitter/reconstructable/blank-position/Nested metadata, exact `0x340` profile/hash, predecessor padding/table ownership, and target-local table/successor disposition; UID00016L and Surface preserve the same binary order. |
| C05-C07 | Target prose excludes cookie/epilogue/jump-table/packed-lowering compiler products, emits the accepted fastcall shim, and records both exact setup refs plus zero ordinary callers/extra target-address routes. |
| C08-C09 | Global/storage pages now distinguish current zero slot bytes and 130 modeled plus seven raw routes from historical all-`ff`/131 wording; raw and modeled initializer pages record `0x00558811 -> 0x00558770` and `0x00558ee2` respectively. |
| C10-C16 | Target, GrafPort class/file, draw-state, and palette-accessor pages contain the early guard, clipping order, typed byte-to-pixel address route, accepted fields, borrowed/fallback palette path, both map calls, discarded secondary result, and the exact software-buffer rule: primary palette index `128` triggers forced mapped RGB565 fill pixel value `1`. |
| C17-C24 | Destination 1 contains all four numeric modes, unknown-mode return, direct odd-tail-before-pairs order, unclamped alpha conversion, destination-first blend direction, mode-2 pair/tail handling, and the exact mode-3 pair-plus-extra-pixel overrun. Read-only type/blend destinations already matched these signatures and required no edits. |
| C25-C28 | Target/table/storage use `FillRgb565RectCallback` and FillRect semantics, preserve Surface ownership and binary order, and keep Destination 1 as the sole formal body. Both by-file roots have zero `RECONSTRUCTION_CPP` occurrences. |
| C29 proof | Initial waited command `000000009752` and B002 repair command `000000009825` completed. A later external refresh left current header `000000009839`; its read-only `Surface.cpp` has one UID marker, one `FillRgb565RectCallback` definition, one `fillPixel = 1;` override, no target Empty Emitter Marker, and no target cookie/jump-table source. |
| C30 proof | Current source-facing text uses `rowStridePixels` and typed `void *` conversion; stale generic stride, direct void-pointer arithmetic, unassigned, and below-gate wording survives only where explicitly historical/superseded. |

## Positive Evidence Summary

- Direct facts: one exact modeled function, exact byte hash and boundaries, two target
  setup refs, 206 slot refs, representative receiver-plus-rectangle dispatchers,
  complete clipping/address/palette/mode control flow, and exact helper contracts.
- Corroboration: the accepted UID0002TI sibling uses the same Surface file-local
  callback reconstruction pattern; Surface/global/storage/consumer docs already treat
  slot 7 as FillRect/fill-invalidate infrastructure; GrafPort support resolves every
  field used by the target.
- Strongest inference chain: RGB565-family contiguity plus both initializer routes
  proves Surface source ownership; call ABI plus fill consumers proves the callback
  signature/role; every machine branch reduces to ordinary clip, palette, row-fill,
  and blend loops, so blank C++ is no longer defensible.

## IDA MCP Facts

- Function/range facts: `sub_4C4380`, `[0x004c4380,0x004c46c0)`, `0x340` bytes,
  281 instructions, 47 blocks, complexity 26, void exit with `retn 4`.
- Data/table/padding facts: predecessor local table four dwords at
  `0x004c4364-0x004c4374`, twelve `0xcc` bytes through `0x004c4380`; target local
  table four dwords at `0x004c46c0-0x004c46d0`, then function `sub_4C46D0`.
- Target local table entries: `0x004c4472`, `0x004c44d4`, `0x004c4542`, and
  `0x004c4603`, each referenced by the dispatch at `0x004c446b`.
- Xref facts: exactly two target data refs at `0x00558811` and `0x00558ee2`, zero
  target code refs, 206 refs to callback slot `0x0069b3fc`.
- Storage/setup facts: slot `0x0069b3fc` contains zero in the image and is assigned at
  runtime. The modeled RGB565 setup maps the twelve consecutive slots as follows:
  `0x69b3e0 -> 0x4c0770`, `0x69b3e4 -> 0x4c0850`,
  `0x69b3e8 -> 0x4c0f80`, `0x69b3ec -> 0x4c3190`,
  `0x69b3f0 -> 0x4c3a50`, `0x69b3f4 -> 0x4c3cf0`,
  `0x69b3f8 -> 0x4c3ea0`, `0x69b3fc -> 0x4c4380`,
  `0x69b400 -> 0x4c46d0`, `0x69b404 -> 0x4c4700`,
  `0x69b408 -> 0x4c4730`, and `0x69b40c -> 0x4c4790`.
- Callee facts: GrafPort::GetClipRect `0x004b96c0`, IntersectRects `0x004b7cc0`,
  IsRectEmptyOrInvalid `0x004b7eb0`, PaletteLib::GetCurrentPalette `0x00543d40`,
  DLPalette::MapColor `0x00542ac0`, BlendRgb565Pixel `0x004c6050`,
  BlendRgb565Pair `0x004c60d0`, and compiler security-cookie check.
- Negative IDA facts: no target string, vtable entry, ordinary direct caller, extra
  target pointer encoding, separate funclet, inline duplicate, or function at the
  local table start.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004c3ea0-0x004c4364` | UID0002TI RGB565 bitmask callback | Immediate predecessor source callback | true | UID0000OC | `89/91` | accepted emitting peer |
| `0x004c4364-0x004c4374` | no child | UID0002TI local jump table | no separate item | UID0002TI | n/a | compiler-local data |
| `0x004c4374-0x004c4380` | no child | alignment padding | false | physical family | n/a | no source emission |
| `0x004c4380-0x004c46c0` | UID0002YK target | RGB565 rectangle fill callback | true | UID0000OC | `90/92` (`86/90` historical) | formal body applied |
| `0x004c46c0-0x004c46d0` | no child | UID0002YK local jump table | no separate item | UID0002YK | n/a | represented by switch |
| `0x004c46d0-0x004c46fa` | UID0002YL RGB565 expand callback | Immediate successor source callback | true | UID0000OC | `87/91` | separate exact function |
| `0x004c6050-0x004c60c7` | UID00016M BlendRgb565Pixel | one-pixel dependency | true | UID0000NT | current support | read-only same-or-greater |
| `0x004c60d0-0x004c6151` | UID00016N BlendRgb565Pair | packed-pair dependency | true | UID0000NT | current support | read-only same-or-greater |
| `0x004c0770-0x004c5fde` | UID00016L RGB565 aggregate | non-emitting family index | false | NONE | `90/92` | retain non-emitting |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00558811` | raw initializer loads `sub_4C4380` into EDI | RGB565 fill target selection before shared store |
| `0x00558770` | raw initializer stores EDI to `0x0069b3fc` | raw setup reaches slot 7 through shared assignment |
| `0x00558ee2` | modeled `sub_558840` stores `sub_4C4380` to slot 7 | direct RGB565 initializer route |
| `0x00558812`, `0x00558ee8` | only raw `80 43 4C 00` target-VA encodings | excludes hidden table/duplicate target route |
| `0x0069b3fc` image bytes | zero before runtime setup | supersedes historical all-`ff` initial-value wording for this slot |
| `0x0049933b` | GrafPort receiver, pushed RectBounds, indirect slot call | representative EPF/control FillRect dispatch |
| `0x0047f951`, `0x0047f972`, `0x0047fab0` | three ChattingPane indirect calls | current/legacy bounds fills through slot 7 |
| `0x00494e6e`, `0x00494e86` | two control-family indirect calls | further receiver-plus-rectangle ABI proof |
| `0x0069b3fc` | 206 refs; 130 modeled functions plus 7 raw sites in current classification | process-wide FillRect/fill-invalidate dispatch storage |
| target direct callers | none | normal callback liveness; not dead code |

## Documentation Evidence And IDA Status

- UID0000OC Surface owns and emits the exact RGB565 children in
  `NexusTK/render/Surface.cpp`; it now records UID0002YK's source-ready behavior and
  formal status at report-level detail.
- UID00016L correctly remains a non-emitting inventory. Its prior report supplied
  range/setup/fanout evidence but intentionally left UID0002YK's body unresolved.
- UID0000TN and UID0001PI own/document slot storage and reject `g_pfnLockSurface`;
  both now contain exact target-side ABI/behavior and fanout classification without a
  duplicate callback body. Their old all-`ff` statement for this exact slot is labeled
  historical and superseded by exact zero-byte evidence.
- UID00039V and UID00039W retain their raw/modeled initialization scopes and independent
  no-code/source-boundary decisions; both now contain the exact slot-7 target-store routes.
- GrafPort class/file/accessor pages now include target-specific callback-consumer
  evidence; the clip/type pages were verified read-only at same-or-greater detail.
- Palette and blend-helper pages were verified read-only at same-or-greater detail;
  no concrete target-specific drift required edits.
- Pre-callback generated Surface.cpp had one UID0002YK Empty Emitter Marker, generated
  memory coverage showed the Surface route without code, and the tracker row showed
  `86/90`, reports `0`. Those observations are historical. Waited command
  `000000009752` now generates exactly one target definition and no target empty marker;
  no generated, coverage, or tracker artifact was manually edited.

## Ranked Ownership Analysis

### 1. Surface / NexusTK/render/Surface.cpp

- Evidence for: target is contiguous with the twelve-target RGB565 backend family;
  both raw and modeled Surface setup routes select it into a process-wide software
  render table; owner/emitter already route to UID0000OC; closest accepted peer emits
  as a static Surface callback.
- Evidence against: exact original file-local function and table field spellings are
  stripped. This caps lexical confidence but does not weaken module ownership.
- Decision: accepted direct semantic owner, emitter, and source file.

### 2. GrafPort / NexusTK/render/GrafPort.cpp

- Evidence for: ECX is a GrafPort receiver and every meaningful field belongs to
  GrafPort; consumers conceptually call FillRect on a port.
- Evidence against: no member call refs exist; the address is installed as one of two
  backend targets and changes with render format; family code belongs to Surface.
- Decision: receiver type and declaration dependency only, not owner or emitter.

### 3. SurfacePresentation, SoftwareBlend16, or UI consumers

- Evidence for: SurfacePresentation performs one initializer store; SoftwareBlend16
  owns the pixel/pair math; many UI methods dispatch slot 7.
- Evidence against: none owns the complete callback operation. Initializer context,
  helper calls, and consumer fanout are dependency evidence, not source ownership.
- Decision: rejected as direct owners. Preserve links only.

### Proposed new file/grouping, if applicable

- No new file or group is needed. Use existing UID0000OC Surface and
  `NexusTK/render/Surface.cpp`.
- Likely source organization: callback typedef/table declaration in the Surface render
  interface, file-local compatibility/RGB565 implementations in Surface.cpp, and
  initializer selection in Surface/ScreenPane startup code.
- No child, helper file, mode table, or compiler wrapper is created by this report.

## Source Placement

- Recommended placement: static backend callback definition in
  `NexusTK/render/Surface.cpp`, after UID0002TI's RGB565 bitmask callback and before
  UID0002YL's RGB565 expand callback, matching binary family order.
- Recommended declaration shape: the slot is logically a void receiver-in-ECX
  rectangle callback. The exact emitted definition uses the established fastcall
  receiver/unused-EDX shim so current C++ can express that machine ABI without making
  the backend a GrafPort member.
- Keep target `EMITTER_POSITION_OPTIONAL` blank. Existing child scan order already
  places this page in the RGB565 family, and no accepted numeric position scheme exists
  for these peers; inventing a number would add unsupported metadata.
- Table/global/storage and by-file pages receive prose only. Do not add duplicate
  target code to UID0000TN, UID0001PI, UID00016L, UID00039V, UID00039W, Surface.md, or
  GrafPort.md.
- Rejected placements: GrafPort.cpp member implementation, SoftwareBlend16.cpp,
  ScreenPane/SurfacePresentation source, and any UI consumer file.
- Remaining uncertainty is lexical/header organization only. It does not block the
  existing valid Surface emitter route or Destination 1.

## Range / Split / Padding / Reclassification Analysis

- Exact range: `[0x004c4380,0x004c46c0)`, one source callback function. No split.
- Predecessor boundary: UID0002TI code ends `0x004c4364`; its four-entry jump table
  occupies `0x004c4364-0x004c4374`; twelve `0xcc` bytes align UID0002YK at
  `0x004c4380`.
- Target end: all UID0002YK code ends by `0x004c46c0`; its four-entry local switch
  table occupies `0x004c46c0-0x004c46d0`; UID0002YL starts exactly at `0x004c46d0`.
- The successor table is source-authored only as the mode switch represented in
  Destination 1. It is not a separate global, child, or literal array.
- Stack cookie setup/check, duplicated epilogues, and packed-store lowering remain
  inside the compiled range but have no handwritten-source representation.
- Parent/container impact: UID00016L stays non-emitting and continues to index the
  exact child; UID0002YK alone carries this function's emitted body.

## Negative Evidence Summary

- No direct target code caller was found; this does not imply dead code because two
  startup stores and 206 indirect slot references prove liveness.
- No vtable entry, import/export, RTTI, string, independent pointer table, or target-VA
  encoding beyond the two initializers was found.
- No separate function begins at the target-local table, no out-of-line cleanup
  funclet exists, and no child range warrants creation.
- No evidence supports UI-pane, Ranking, SurfacePresentation, GrafPort-member, or
  SoftwareBlend16 ownership.
- No evidence supports stale `g_pfnLockSurface`, refresh-only, invalidation-only, or
  lock/unlock semantics. Installed targets perform clipped pixel fill.
- No evidence supports clamping alpha, skipping the secondary MapColor call, merging
  modes 2 and 3, or repairing the mode-3 odd-width overrun.
- No dedicated old report already resolves this target. Incidental mentions were
  classified and incorporated rather than counted as direct report coverage.

## IDA Rename / Type / Comment Recommendations

- Rename `sub_4C4380` descriptively to `FillRgb565RectCallback` if a future authorized
  IDA-maintenance pass chooses to write names.
- Type it as a void software-render callback with GrafPort receiver in ECX and one
  constant `RectBounds *` stack argument; document the source reconstruction's
  fastcall EDX shim as ABI adaptation, not a semantic parameter.
- Rename evidence-only `dword_69B3FC` descriptively to `g_fillRectCallback`; retain
  `FillRect` as the consumer-facing operation. This global token remains inferred and
  should not raise confidence above the lexical cap.
- Use accepted fields `m_surfaceContext.pixelData`, `rowStridePixels`, `bounds`,
  `m_drawMode`, `m_drawEnabled`, `m_drawColor`, `m_secondaryDrawColor`, `m_palette`,
  `m_alpha`, and `m_usesSoftwareBuffer` rather than raw offsets. Treat the earlier
  generic `rowStride` token as a superseded historical report-draft alias. Because
  `pixelData` is `void *`, use an `unsigned char *` local byte view for address
  arithmetic and convert the resulting address to `unsigned short *` afterward.
- Use local names `clipBounds`, `clippedBounds`, `width`, `height`, `rowPixels`,
  `fillPixel`, `packedFill`, and `destinationWeight`.
- Add a source comment at mode 3 only: preserve its odd-width pair-plus-extra-pixel
  behavior. Do not comment compiler cookies or jump-table addresses into source.
- IDA DB edits are not requested and were not performed. These are future naming/type
  recommendations only.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes. Range, ABI, liveness, fields, helpers, mode semantics,
  edge cases, source route, and compiler-artifact disposition are resolved.
- Destination 1, exact formal insertion text for UID0002YK:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
static void __fastcall FillRgb565RectCallback(
    GrafPort *port,
    int /*unused*/,
    const RectBounds *bounds)
{
    enum FillMode {
        kFillCopy = 0,
        kFillColorKey = 1,
        kFillBlend = 2,
        kFillColorKeyBlend = 3
    };

    if (!port->m_drawEnabled) {
        return;
    }

    RectBounds clipBounds;
    port->GetClipRect(&clipBounds);

    RectBounds clippedBounds = *bounds;
    IntersectRects(&clipBounds, &clippedBounds, &clippedBounds);
    if (IsRectEmptyOrInvalid(&clippedBounds)) {
        return;
    }

    const int width = clippedBounds.right - clippedBounds.left;
    const int height = clippedBounds.bottom - clippedBounds.top;
    const int rowStridePixels = port->m_surfaceContext.rowStridePixels;
    unsigned char *pixelBytes =
        static_cast<unsigned char *>(port->m_surfaceContext.pixelData);
    unsigned short *rowPixels = reinterpret_cast<unsigned short *>(
        pixelBytes +
        2 * (clippedBounds.left +
             rowStridePixels *
                 (clippedBounds.top - port->m_surfaceContext.bounds.top) -
             port->m_surfaceContext.bounds.left));

    DLPalette *palette = port->m_palette;
    if (palette == NULL) {
        palette = g_pPaletteLib->GetCurrentPalette();
    }

    unsigned short fillPixel = palette->MapColor(port->m_drawColor);
    const unsigned short secondaryPixel =
        palette->MapColor(port->m_secondaryDrawColor);
    (void)secondaryPixel;

    if (port->m_usesSoftwareBuffer && port->m_drawColor == 128) {
        fillPixel = 1;
    }

    const unsigned int packedFill =
        static_cast<unsigned int>(fillPixel) |
        (static_cast<unsigned int>(fillPixel) << 16);

    switch (port->m_drawMode) {
    case kFillCopy:
        for (int y = 0; y < height; ++y) {
            if ((width & 1) != 0) {
                rowPixels[width & ~1] = fillPixel;
            }

            unsigned int *pairs =
                reinterpret_cast<unsigned int *>(rowPixels);
            for (int x = 0; x < width / 2; ++x) {
                pairs[x] = packedFill;
            }

            rowPixels += rowStridePixels;
        }
        break;

    case kFillColorKey:
        if (port->m_drawColor == 0) {
            return;
        }

        for (int y = 0; y < height; ++y) {
            if ((width & 1) != 0) {
                rowPixels[width & ~1] = fillPixel;
            }

            unsigned int *pairs =
                reinterpret_cast<unsigned int *>(rowPixels);
            for (int x = 0; x < width / 2; ++x) {
                pairs[x] = packedFill;
            }

            rowPixels += rowStridePixels;
        }
        break;

    case kFillBlend: {
        const unsigned char destinationWeight = static_cast<unsigned char>(
            static_cast<int>(port->m_alpha * 32.0f + 0.5f));
        const int evenWidth = width & ~1;

        for (int y = 0; y < height; ++y) {
            unsigned int *pair =
                reinterpret_cast<unsigned int *>(rowPixels);
            for (int x = 0; x < evenWidth; x += 2) {
                *pair = BlendRgb565Pair(
                    *pair, packedFill, destinationWeight);
                ++pair;
            }

            if ((width & 1) != 0) {
                unsigned short *tail =
                    reinterpret_cast<unsigned short *>(pair);
                *tail = BlendRgb565Pixel(
                    *tail, fillPixel, destinationWeight);
            }

            rowPixels += rowStridePixels;
        }
        break;
    }

    case kFillColorKeyBlend: {
        if (port->m_drawColor == 0) {
            return;
        }

        const unsigned char destinationWeight = static_cast<unsigned char>(
            static_cast<int>(port->m_alpha * 32.0f + 0.5f));

        for (int y = 0; y < height; ++y) {
            unsigned int *pair =
                reinterpret_cast<unsigned int *>(rowPixels);

            // Preserve the original odd-width pair-plus-extra-pixel behavior.
            for (int x = 0; x < width; x += 2) {
                *pair = BlendRgb565Pair(
                    *pair, packedFill, destinationWeight);
                ++pair;
            }

            if ((width & 1) != 0) {
                unsigned short *extraPixel =
                    reinterpret_cast<unsigned short *>(pair);
                *extraPixel = BlendRgb565Pixel(
                    *extraPixel, fillPixel, destinationWeight);
            }

            rowPixels += rowStridePixels;
        }
        break;
    }

    default:
        return;
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- The body preserves all observed branches and side effects: early draw/clip exits,
  exact rectangle direction, destination formula, palette fallback, both MapColor
  calls, software-buffer index-128 override, four modes, row/pair/tail behavior,
  unclamped weight conversion, blend argument order, and mode-3 anomaly.
- Compile-surface re-audit against current support declarations is complete:
  `GrafPort` embeds `EPFTileContext m_surfaceContext`; that context declares
  `void *pixelData`, `int rowStridePixels`, and `RectBounds bounds`; `RectBounds`
  provides signed `int left/top/right/bottom`; `GrafPort::GetClipRect` accepts a
  `RectBounds *`; `IntersectRects` and `IsRectEmptyOrInvalid` accept the pointer forms
  used here; palette contracts provide `DLPalette *`, `GetCurrentPalette()`, and the
  16-bit `MapColor` result; and `BlendRgb565Pixel`/`BlendRgb565Pair` accept the exact
  16-/32-bit destination-first arguments shown. `Region` remains encapsulated inside
  `GetClipRect`, so this callback does not invent or depend on a direct Region layout.
- Standard C++ address arithmetic is now type-correct without changing the binary
  formula: `pixelData` is converted to `unsigned char *`, the exact byte displacement
  is applied, and only the resulting address is converted to `unsigned short *`.
  Every row then advances by the accepted logical-pixel `rowStridePixels` count.
- It is period-plausible Visual C++ source: static backend function, explicit loops,
  C-style null token, local enum, simple casts, no lambdas/templates/modern ownership,
  and the same fastcall callback shim accepted for UID0002TI.
- It replaces IDA labels with human names while keeping uncertain lexical choices
  descriptive. No jump-table array, security cookie, `memset32`, or decompiler local is
  emitted.
- No other formal C++ destination is recommended. Callback table/storage/initializer
  pages remain prose support so they cannot duplicate this exact function body.

## Final Recommendation

- C01-C30 are applied. UID0002YK is `90/92`; owner/emitter UID0000OC,
  reconstructable true, blank position, and Nested 0 are retained; Destination 1 is
  installed exactly.
- Destination 1 retains the accepted `rowStridePixels` member and the explicit
  `void *` -> `unsigned char *` byte-view -> `unsigned short *` destination-address
  sequence. The earlier `rowStride` spelling and direct `void *` arithmetic are
  historical/superseded and must not reappear as accepted source.
- Stale unassigned/below-85/needs-field-signature-branch-table wording is replaced by
  source-ready facts and preserved only as a labeled historical assumption.
- Preserve UID00016L as non-emitting and keep all callback table, storage, initializer,
  GrafPort, palette, blend, and Surface support ownership/body decisions unchanged.
- Target-specific prose is synchronized in Destinations 2-11. Destinations 12-13 were
  read-only same-or-greater checks with no concrete drift; Destination 14 is completed
  validator-driven verification, not a manual generated edit.
- Create no new report, page, child, table, wrapper, enum page, or helper body.
- Remaining future work outside this assignment: complete independent callback-table
  declaration naming and the still-blank peer callbacks under their own assignments.
  Neither blocks UID0002YK's behavior-identical body.

## Recommended Target Doc Changes

- Callback result: every Destination 1 item below is applied to the target page.
- Destination 1 target path:
  `by-memory/0x004c4380-0x004c46c0.SoftwareRenderRgb565FillCallback.md`.
- Set `COMPLETION:90` and `CONFIDENCE:92`; retain owner UID0000OC,
  reconstructable true, emitter UID0000OC, blank position, and Nested 0.
- Apply the exact managed block under `First-Draft C++ Recommendation` with no edits,
  wrappers, declarations, or duplicate body outside it.
- Use `m_surfaceContext.rowStridePixels`, not the superseded `rowStride` alias. Take
  an `unsigned char *` byte view of `m_surfaceContext.pixelData` before the exact
  doubled offset and convert the resulting address to `unsigned short *`; never apply
  arithmetic directly to the accepted `void *pixelData` member.
- Replace Item Summary with source-ready exact range/ABI/liveness, clipping/address,
  palette/mode/loop/blend, Surface owner, and formal-body status. Do not repeat fields
  that validator-generated coverage already renders unless needed for behavior.
- Add exact byte hash, instruction/block/complexity counts, predecessor padding/table,
  target-local table, successor boundary, two setup refs, 206 slot refs, representative
  indirect callers, no-direct-caller meaning, target pointer negative, and all callees.
- Add all field offsets/names and exact destination formula, palette fallback and
  discarded secondary mapping, software-buffer override, mode table, direct and blend
  loops, weight direction, mode-3 odd-width anomaly, compiler-artifact disposition,
  source placement/order, rejected alternatives, and lexical confidence cap.
- Preserve valid prior 2026-06-10 evidence and label the old unassigned/below-85 and
  needs-source-grade-pass wording historical/superseded rather than deleting provenance.

## Recommended Support Doc Changes

- Callback result: Destinations 2-11 are applied; Destinations 12-13 were verified
  read-only without drift; Destination 14 completed through command `000000009752`.
- Destination 2, `by-file/Surface.md`: add UID0002YK source-ready callback evidence at
  report-level detail, exact source order after UID0002TI/before UID0002YL, and direct
  `NexusTK/render/Surface.cpp` placement. Preserve file score/path and all unrelated
  callback/source decisions. This by-file root receives no reconstruction block.
- Destination 3,
  `by-memory/0x004c0770-0x004c5fde.SoftwareRenderRgb565Callbacks.md`: update UID0002YK
  inventory row/status with `90/92`, exact ABI/target refs/slot refs/body summary, local
  table disposition, and source-ready child state. Keep aggregate NONE/FALSE/non-emitting
  and do not paste child C++.
- Destination 4, `by-global/SurfaceRenderCallbackTable.md`: add exact slot-7 logical
  receiver-plus-rectangle void ABI, installed compat/RGB565 fill targets, current target
  behavior, zero-initialized storage/runtime setup, and descriptive FillRect naming;
  retain global owner/emitter/score and blank formal C++. Historical all-`ff` wording
  for this exact slot must be explicitly superseded rather than silently retained.
- Destination 5,
  `by-memory/0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable.md`: add UID0002YK exact
  source-ready target, zero image bytes followed by runtime assignment, and current
  206-ref classification. Explicitly time-scope older all-`ff` and 131-function text
  where live bytes/counting methodology differ. Preserve table storage body, owner,
  score, and no-duplicate-C++ policy.
- Destination 6,
  `by-memory/0x00558690-0x0055883d.SurfaceRenderCallbackInitializerRaw.md`: add the exact
  `0x00558811` target load and shared `0x00558770` slot-7 store, paired backend meaning,
  and target link. Preserve this raw range's own metadata/formal disposition and all
  unrelated setup evidence.
- Destination 7,
  `by-memory/0x00558840-0x00558f63.SurfaceMinimapRenderInitializer.md`: add the direct
  `0x00558ee2` slot-7 target assignment in the exact twelve-slot RGB565 sequence.
  Preserve this initializer's independent owner/source-boundary/no-code decision.
- Destination 8, `by-class/GrafPort.md`: add UID0002YK as exact callback consumer of
  `m_surfaceContext.pixelData`, `m_surfaceContext.rowStridePixels`,
  `m_surfaceContext.bounds`, `m_drawMode`, `m_drawEnabled`, primary/secondary colors,
  `m_palette`, `m_alpha`, and `m_usesSoftwareBuffer`; record `pixelData` as `void *`,
  `rowStridePixels` as a logical pixel count, the local typed byte/pixel views, the
  primary-index-128 trigger that forces RGB565 fill pixel value `1`, and
  destination-weight direction. Preserve class metadata and
  unrelated children; retain generic `rowStride` only if explicitly labeled history.
- Destination 9, `by-file/GrafPort.md`: add the same target-specific field/dependency
  evidence, including `void *pixelData`, `int rowStridePixels`, and the typed local
  cast route, plus the exact index-128 trigger/value-1 result, as source-layout prose
  only. Preserve GrafPort.cpp placement and do not add by-file reconstruction metadata
  or target code.
- Destination 10,
  `by-memory/0x004b95e0-0x004b969f.GrafPortDrawStateAccessors.md`: add target evidence
  for `m_drawColor`/`m_secondaryDrawColor`, including both palette mappings and the
  nonzero color-key gates. Preserve accessor formal bodies and scores.
- Destination 11,
  `by-memory/0x004b96a0-0x004b96c0.DrawContextBrushHandleHelpers.md`: add target
  evidence that `m_palette` is borrowed, used when non-null, and otherwise falls back
  to `g_pPaletteLib->GetCurrentPalette()`. Preserve GetPalette/SetPalette bodies.
- Destination 12 read-only type/dependency verification:
  `by-class/EPFTileContext.md`, `by-class/RectBounds.md`, `by-class/Region.md`,
  `by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md`, and
  `by-memory/0x004b96c0-0x004b9768.GrafPortGetClipRect.md` already establish
  `void *pixelData`, `int rowStridePixels`, `RectBounds` member types, the accepted
  clip/intersection/empty-test pointer forms, and Region encapsulation. The same
  destination also verifies `by-class/PaletteLib.md`, `by-class/DLPalette.md`,
  `by-global/g_pPaletteLib.md`, and
  `by-memory/0x00542ac0-0x00542adc.DLPaletteMapColor.md` for the exact
  singleton/current-palette/map contracts. Edit only if direct target-specific drift is
  found during callback; otherwise record no edit.
- Destination 13 read-only verification:
  `by-memory/0x004c6050-0x004c60c7.BlendRgb565Pixel.md`,
  `by-memory/0x004c60d0-0x004c6151.BlendRgb565Pair.md`, and
  `by-file/SoftwareBlend16.md` already document argument/weight contracts. Edit only
  for a concrete stale target statement; preserve helper bodies/owners/scores.
- Destination 14 generated verification only: after all ordinary-page validators, one
  authorized waited generated refresh completed. `Surface.cpp` contains exactly one
  UID0002YK definition, no target Empty Emitter Marker, and no handwritten jump table,
  cookie, or duplicate callback body. Generated/tracker/coverage were not manually edited.

## Score And Metadata Recommendation

- Historical target: `86/90`, owner/emitter UID0000OC, reconstructable true, blank
  position, blank formal C++, Nested 0.
- Applied target: `90/92`, same owner/emitter/reconstructable/position/Nested, exact
  Destination 1 formal body.
- Completion 90 is justified by exact range/hash/control flow, setup and dispatch
  liveness, full caller/callee/negative inventories, every field/helper/branch/loop,
  source order and compiler-artifact disposition, formal code, and complete support
  destinations.
- Confidence 92 is justified by direct binary behavior and accepted dependency docs.
  It stays below 95 because original function/global/enum/local spellings and exact
  header declaration organization are stripped and inferred.
- Score-improvement attempts and results:
  - Range/split blocker: removed by exact bytes, adjacent lookups, table xrefs, and
    padding classification.
  - Liveness/caller blocker: removed by two setup routes, 206 slot refs, representative
    indirect call ABI, and target pointer search.
  - Signature/return blocker: removed by caller setup, stack cleanup, all exits, and
    accepted peer ABI.
  - Field/type/compile blocker: removed through target dataflow and current GrafPort,
    EPFTileContext, RectBounds, Region/clip, palette, and blend declarations. The
    accepted source uses `void *pixelData`, `int rowStridePixels`, an
    `unsigned char *` local for byte arithmetic, and an `unsigned short *` row view;
    no direct `void *` arithmetic or current generic `rowStride` member remains.
  - Mode/loop blocker: removed by full switch disassembly, constants, pair/tail loop
    reconstruction, and explicit mode-3 anomaly preservation.
  - Palette/blend blocker: removed by callee decompilation and accepted helper contracts.
  - Owner/source blocker: removed by family contiguity, both initializer routes, current
    Surface ownership, and rejected dependency/consumer alternatives.
  - C++ blocker: removed by Destination 1's complete behavior-identical formal body.
- No support-page score or metadata changed in this target-only callback.

## Open Questions With Attempted Resolution

- Original callback name: symbols are stripped. Family names, operation, and accepted
  peer style support `FillRgb565RectCallback`; this descriptive choice is source-ready
  and the lexical uncertainty only caps confidence.
- Original slot/global token: all consumers and both installed targets prove FillRect
  semantics. `g_fillRectCallback` is the best descriptive global name, but exact
  declaration spelling remains table-family work and is not emitted by this target.
- Original mode enum tokens: values and behavior are exact. The local
  copy/color-key/blend/color-key-blend names are the strongest source-facing inference;
  numeric behavior remains explicit in the target docs.
- `m_secondaryDrawColor` mapping result: exhaustive target control flow finds no use,
  but the call executes. It is retained as likely shared source setup residue rather
  than optimized away or assigned invented semantics.
- Alpha direction: helper contracts resolve it. The supplied weight preserves existing
  destination; zero selects fill and 32 preserves destination. Existing `m_alpha`
  spelling is retained as accepted class terminology with this exact caveat.
- Mode-3 odd width: full disassembly/decompile proves pair loop over full width plus an
  extra odd tail. No evidence permits repair; behavior-identical C++ preserves it.
- Surface-context field and compile route: current GrafPort/EPFTileContext declarations
  resolve this completely. The accepted source member is `rowStridePixels` at embedded
  context `+0x0c` / GrafPort `+0x28`, while `pixelData` is `void *` at embedded
  context `+0x04` / GrafPort `+0x20`. Destination 1 therefore takes an
  `unsigned char *` byte view before applying the exact displacement and converts the
  resulting address to `unsigned short *`. The old `rowStride` spelling is retained
  only as a rejected historical report-draft alias; direct `void *` arithmetic is not
  a viable source alternative.
- Exact source order metadata: binary order is exact, but peer positions are blank.
  Preserve blank position and document the order instead of inventing a number.
- No behavior, ownership, split, ABI, dependency, or formal-C++ question remains
  unresolved. Remaining lexical uncertainty is explicitly scored and non-blocking.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Not applicable. The relevant research tracker and generated memory/source coverage
  are validator-owned `auto-generated/-ag-*` artifacts.
- No manual coverage/tracker replacement text is supplied. Destination 1's source page
  and authorized validator commands `000000009752` and `000000009825` were the valid
  initial and Gate 2 repair update routes.
- B002 made no manual generated, coverage, tracker, supervisor, registry, or
  validator-state edit.

## Follow-Up Actions

- B002's bounded callback work is complete: C01-C30, Destinations 1-14, all scoped
  validators, the waited generated verification, report synchronization, and lease
  release are finished.
- The Gate 2 repair is also complete: only the two erroneous GrafPort support sentences
  changed, both scoped validators passed, latest generated verification is current, and
  all repair leases are released.
- Independent callback-table declaration naming and still-blank peer callbacks remain
  separate future assignments; neither changes or blocks UID0002YK.
- B002 did not execute, move, archive, or lifecycle this report. Any current/future
  report path, count, validation, execution, move, or archive state remains external
  validator-owned and is not asserted here.

## Confidence

- Recommendation confidence: high. Direct binary facts prove function identity,
  liveness, behavior, dependencies, owner, and source form.
- Score confidence: high for applied `90/92`; it reflects complete source reconstruction
  while preserving lexical/header uncertainty below near-final audit levels.
- Remaining uncertainty: exact original function/global/enum/member token spelling and
  table header organization only. None changes runtime behavior or emitter selection.

## Validator Results

- Every ordinary-page command used
  `python .\tools\validator.py --mode file --file '<path>' --apply`; the final target
  command additionally used `--wait-generated --queue-timeout 240`. Every listed
  command exited `0` with `ok: 1`.

| Command ID / timestamp | Scoped page | Warnings and validator-owned side effects |
| --- | --- | --- |
| `000000009726` / `2026-07-13T11:05:09-04:00` | UID0002YK target | No warning. Completion/confidence and autogen block/hash registry synchronized; UID0002TI/UID0002YL references and projected stats updated; generated refresh deferred. |
| `000000009727` / `2026-07-13T11:06:30-04:00` | `by-file/Surface.md` | 24 pre-existing `missing_ref_uid` warnings (examples UID00039Z/00039R/00039P/00039V/0003XE; 14 suppressed); reference UID0003A4, UID0000OC stats, and projected stats updated; generated refresh deferred. |
| `000000009728` / `2026-07-13T11:07:18-04:00` | UID00016L aggregate | No warning; stats no-op/projected stats update; generated refresh deferred. |
| `000000009729` / `2026-07-13T11:09:18-04:00` | global callback table | Seven pre-existing missing-reference warnings for UID0003ZP/UID0003XE; UID0002YK reference, two UID0000TN stats rows, and projected stats updated; generated refresh deferred. |
| `000000009730` / `2026-07-13T11:10:46-04:00` | callback-table storage | Eight pre-existing missing-reference warnings for UID0003ZP/UID0003XE/UID0003PN; UID0002YK reference and projected stats updated; stats incremental no-op; generated refresh deferred. |
| `000000009731` / `2026-07-13T11:11:30-04:00` | raw initializer | No warning. Header blank, UID path/score/owner, five autogen registry fields, five reference rows including UID0002YK, and projected stats synchronized; stats incremental no-op; generated refresh deferred. |
| `000000009732` / `2026-07-13T11:12:32-04:00` | modeled initializer | Five pre-existing UID00039Z missing-reference warnings; UID0002YK reference and projected stats updated; stats incremental no-op; generated refresh deferred. |
| `000000009743` / `2026-07-13T11:14:06-04:00` | `by-class/GrafPort.md` | Three pre-existing UID0003XE missing-reference warnings; UID0002YK reference and projected stats updated; stats incremental no-op; generated refresh deferred. |
| `000000009749` / `2026-07-13T11:15:05-04:00` | `by-file/GrafPort.md` | Four pre-existing UID0003XE missing-reference warnings; UID0002YK reference and projected stats updated; stats incremental no-op; generated refresh deferred. |
| `000000009750` / `2026-07-13T11:15:58-04:00` | UID000162 draw-state accessors | No warning; UID0002YK reference and projected stats updated; stats incremental no-op; generated refresh deferred. |
| `000000009751` / `2026-07-13T11:16:23-04:00` | UID000163 palette accessors | No warning; UID0002YK reference and projected stats updated; stats incremental no-op; generated refresh deferred. |
| `000000009752` / `2026-07-13T11:16:53-04:00` | UID0002YK final waited refresh | Generated refresh completed. Global generator diagnostics were 15 child fallback inserts, 83 preferred child-marker warnings, 205 child-only emitter notices, one registry rebuild, and 281 generated metadata refreshes; none is a UID0002YK blocker. |
| `000000009819` / `2026-07-13T11:53:34-04:00` | `by-class/GrafPort.md` Gate 2 repair | Exit `0`, `ok: 1`; corrected index-128 trigger versus forced pixel-value-1 prose. Three pre-existing UID0003XE missing-reference warnings; stats incremental no-op and projected stats update; generated refresh deferred. |
| `000000009820` / `2026-07-13T11:54:03-04:00` | `by-file/GrafPort.md` Gate 2 repair | Exit `0`, `ok: 1`; corrected the same trigger/result distinction without adding by-file reconstruction metadata. Four pre-existing UID0003XE missing-reference warnings; stats incremental no-op and projected stats update; generated refresh deferred. |
| `000000009825` / `2026-07-13T11:54:33-04:00` | UID0002YK latest waited repair refresh | Exit `0`, `ok: 1`; generated refresh completed. Global diagnostics remained 15 child fallback inserts, 83 preferred child-marker warnings, 205 child-only emitter notices, one registry rebuild, and 281 metadata refreshes; none is target-specific. |

- Lease proof: each listed ordinary page was leased by B002 immediately before its
  edit and released immediately after its scoped validator. UID0002YK was briefly
  re-leased only for the final applied waited validator and immediately released.
  Final `tools/leaser/Agents/current_leases.md` contains no active lease.
- Gate 2 repair lease proof: B002 leased only `by-class/GrafPort.md` and
  `by-file/GrafPort.md`, each immediately before its one-line prose edit, and released
  each immediately after command `000000009819` or `000000009820`. The target was not
  edited or leased for command `000000009825`; final lease state is empty.
- Exact generated proof after B002 command `000000009825`, reconfirmed read-only against
  the newer external generated header `000000009839`: report/target managed body
  comparison is byte-equal after line-ending normalization (`4540` characters each);
  `Surface.cpp` has one `UID:0002YK` marker, one
  `static void __fastcall FillRgb565RectCallback(` definition, zero target Empty
  Emitter Markers, exactly one `fillPixel = 1;`, zero security-cookie tokens, and zero
  target jump-table source.
  Both edited by-file roots have zero `RECONSTRUCTION_CPP` occurrences.
- No validator error remains. Reported missing-reference and global generation warnings
  are pre-existing/unrelated diagnostics recorded above rather than suppressed.

## Changed Files

- Callback-edited ordinary pages:
  - `by-memory/0x004c4380-0x004c46c0.SoftwareRenderRgb565FillCallback.md`
  - `by-file/Surface.md`
  - `by-memory/0x004c0770-0x004c5fde.SoftwareRenderRgb565Callbacks.md`
  - `by-global/SurfaceRenderCallbackTable.md`
  - `by-memory/0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable.md`
  - `by-memory/0x00558690-0x0055883d.SurfaceRenderCallbackInitializerRaw.md`
  - `by-memory/0x00558840-0x00558f63.SurfaceMinimapRenderInitializer.md`
  - `by-class/GrafPort.md`
  - `by-file/GrafPort.md`
  - `by-memory/0x004b95e0-0x004b969f.GrafPortDrawStateAccessors.md`
  - `by-memory/0x004b96a0-0x004b96c0.DrawContextBrushHandleHelpers.md`
- Callback-updated report: this same
  `tools/leaser/Agents/Agent-B002/research/0002YK-SoftwareRenderRgb565FillCallback-source-quality.md`.
- Gate 2 repair changed only `by-class/GrafPort.md`, `by-file/GrafPort.md`, and this
  same report. Both support metadata/formal states and every other accepted callback
  detail remain unchanged.
- Read-only unchanged Destinations 12-13: EPFTileContext/RectBounds/Region/RectGeometry/
  GetClipRect/PaletteLib/DLPalette/g_pPaletteLib/MapColor and BlendRgb565Pixel/
  BlendRgb565Pair/SoftwareBlend16 pages already had same-or-greater declarations.
- Validator-generated artifacts were refreshed by B002 commands `000000009752` and
  `000000009825`; a later external validator refresh left current generated command
  header `000000009839`. None was manually edited. No coverage, tracker, supervisor,
  audit, lifecycle, or IDA file was
  manually edited. No page/report was renamed, moved, archived, or executed by B002.

## Implementation Tracking Checklist

Initial report-only pass:
- [x] Supervisor Gate 1 accepted exact SHA `A3D4AC4C5BC55BF3FEBB38C9CDF43C74D37F5CFF88BB6F151C9E07C5767771F2` before implementation.
- [x] Ledger gate confirmed before callback: every C01-C30 Action used only exact
  `incorporate`, `already-present`, `historicalize`, `reject-stale`, `reject-invalid`,
  or `not-applicable`, and every report-only Verification state was exactly `proposed`.
- [x] Destination 1 target and Destinations 2-14 support/verification scope re-read immediately before callback.
- [x] Current target state and actual evidence checked recorded in destination docs.
- [x] Claim And Incorporation Ledger updated claim-by-claim; current state cells use only `applied` or `excluded-with-reason`.
- [x] UID0002YK score changed `86/90 -> 90/92`; all support scores confirmed unchanged.
- [x] Score-limiting range, ABI, liveness, field, mode, palette, blend, source-placement, and C++ blockers incorporated as resolved.
- [x] Owner UID0000OC, emitter UID0000OC, reconstructable true, blank position, and Nested 0 preserved.
- [x] No split, rename of page, new child, compiler wrapper, jump-table page, or duplicate report created.
- [x] Source placement, range/split/padding, and IDA rename/type/comment recommendations incorporated.
- [x] C12/C13/C20-C24/C30 and Destinations 1/8/9/12 synchronized on accepted
  `void *pixelData`, `int rowStridePixels`, typed byte/pixel views, logical-pixel row
  advancement, and explicitly historical generic `rowStride` spelling.
- [x] Destination 1 exact formal C++ block applied with accepted field names,
  compile-valid byte-address arithmetic, discarded secondary MapColor call,
  software-buffer primary-index-128 trigger/forced-pixel-value-1 override, direct-fill tail ordering, destination-weight
  direction, unknown-mode return, and mode-3 odd-width pair-plus-extra overrun intact.
- [x] Third-party import directive confirmed not applicable; this is NexusTK-owned source.
- [x] Target/support facts incorporated at report-level detail without compression.
- [x] Historical stale assumptions, rejected alternatives, and negative evidence preserved and labeled.
- [x] Wave2/Wave3 evidence confirmed absent or rejected as stale if encountered during callback reread.
- [x] Every open question closed or retained only as evidence-backed non-blocking lexical uncertainty.
- [x] One short lease and one scoped validator used for each changed ordinary by-* page, with immediate release; target re-leased/released for the final waited validator.
- [x] Final authorized waited generated refresh completed and Surface.cpp exact-count/marker/compiler-artifact checks recorded.

Implementation callback pass:
- [x] Report accepted by supervisor for implementation at the exact Gate 1 SHA recorded above.
- [x] All accepted target/support details incorporated without compression.
- [x] Every C01-C30 ledger row has final destination and an allowed callback verification state.
- [x] Metadata, score, owner/emitter preservation, no-split decision, source name, and formal C++ applied exactly.
- [x] Destination 1 compile re-audited against current GrafPort, EPFTileContext,
  RectBounds, Region/clip, Palette, and blend declarations; no direct `void *`
  arithmetic or current `rowStride` member spelling remains.
- [x] Support pages receive no duplicate UID0002YK formal body and by-file roots receive no reconstruction metadata.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved.
- [x] Open questions documented with final evidence-backed resolutions and lexical caps.
- [x] Scoped validator command/id/time/exit/ok/warnings/side effects recorded for every changed page.
- [x] Generated refresh is validator-driven only; generated/coverage/tracker files were never manually edited.
- [x] Generated Surface.cpp contains exactly one UID0002YK definition, no target Empty Emitter Marker, no duplicate body, and no handwritten jump table/cookie lowering.
- [x] All accepted items are applied or excluded with exact reason, and every B002 lease is released.

Gate 2 repair pass:
- [x] `by-class/GrafPort.md` now distinguishes primary palette index `128` as the trigger from forced mapped RGB565 fill pixel value `1` as the result.
- [x] `by-file/GrafPort.md` contains the same exact distinction and still has no reconstruction metadata or target body.
- [x] Scoped commands `000000009819` and `000000009820` exited `0` with `ok: 1`; all warnings and validator-owned side effects are recorded above.
- [x] B002 waited command `000000009825` exited `0` with `ok: 1`; the newer external header `000000009839` was checked read-only and still has one target definition containing one `fillPixel = 1;` override and no target Empty Emitter Marker.
- [x] No generated, coverage, tracker, audit, lifecycle, supervisor, or IDA file was manually edited; no execute/move/archive command ran.
- [x] Both repair leases were released and final current lease state is empty.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000009848","destination_path":"executed-b-agent-research/B002/0002YK-SoftwareRenderRgb565FillCallback-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B002/research/0002YK-SoftwareRenderRgb565FillCallback-source-quality.md","timestamp":"2026-07-13T12:10:44-04:00","uid":"0002YK"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
