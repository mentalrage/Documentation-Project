** TARGET-REPORT-UID:0002PI **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID0002PI SoftwareRenderRgb565PixelCallback Source Quality


## Finalized Report / Current Recommendation

- Current implementation: UID0002PI is `92/94`, preserves
  `CANONICAL_OWNER:0000OC`, `RECONSTRUCTABLE:TRUE`,
  `EMITTER_UIDS:0000OC`, blank `EMITTER_POSITION_OPTIONAL`, and `Nested:4`,
  and contains the exact source-ready RGB565 pixel callback body from
  Destination 1.
- Final disposition: one complete source-authored Surface software-render
  callback, not a GrafPort member method, not a callback-table storage body,
  not SoftwareBlend16 math, not RainingLayerPane code, and not compiler glue.
- Applied bounded support action: the non-emitting RGB565 family index, Surface
  source page, callback-table global and storage pages, compat peer
  `rowStridePixels`/control-flow shape, and eleven-byte successor alignment row
  are synchronized. No split, rename, new UID, new source file, or IDA mutation
  was required.
- Strongest source signature: a file-local Surface callback using the accepted
  project MSVC-style receiver-in-ECX convention, a `GrafPort *` receiver, and
  stack arguments `int x`, `int y`, and `unsigned int colorIndex`, with source
  return type `void`.
- Confidence: very strong for bytes, range, ABI, callback dispatch, field
  offsets/types, palette and clipping routes, all four modes, owner/emitter,
  and complete behavior. Original lexical spellings and exact header placement
  are inferred rather than symbol-proven and cap the score below final-audit
  values.

## Supporting Research

- Assignment history: the initial supervisor override assigned a report-only
  pass for UID0002PI and forbade ordinary edits, leases, validators, coverage
  edits, generated refreshes, IDA mutation, report execution, lifecycle
  commands, movement, and archival. A later exact-artifact Gate 1 pass
  authorized the bounded D1-D7 implementation callback now recorded here.
- Queue source: current `auto-generated/-ag-research-tracker.md` line 1669
  records UID0002PI as `87/89`, average `88.0`, reconstructable true, report
  count zero.
- Current binary: `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`,
  MD5 `4247E04E20B65D6414C7238AA8FF5515`, SHA256
  `9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632`,
  image base `0x00400000`.
- Healthy MCP evidence session: fresh `idb_list` on 2026-07-16 returned one
  active NexusTK IDB session `64c11373`, worker PID `21508`,
  `is_analyzing:false`. `server_health` returned `status:ok`,
  `auto_analysis_ready:true`, `hexrays_ready:true`, and
  `strings_cache_ready:true`.
- Reproducible historical search roots checked:
  `tools/leaser/Agents/Agent-B001/research`,
  `tools/leaser/Agents/Agent-B002/research`,
  `tools/leaser/Agents/Agent-B003/research`,
  `tools/leaser/Agents/Agent-B004/research`,
  `tools/leaser/Agents/Agent-B005/research`,
  `executed-b-agent-research`,
  `tools/leaser/Agents/Older-Research`, and
  `tools/leaser/Agents/SpecialReports`.
- Search terms included target UID, address, name, raw label, callback slot,
  source family, generated name, field family, and initializer/caller terms:
  `0002PI`, `0x004c0770`, `SoftwareRenderRgb565PixelCallback`,
  `sub_4C0770`, `g_pfnDrawPixel`, `dword_69B3E0`,
  `SoftwareRenderRgb565`, `SurfaceRenderCallback`, `GrafPort`,
  `RainingLayerPane`, `rowStride`, `m_drawMode`, `m_drawColor`, and
  `m_alpha`.
- Path-specific historical results:
  - `executed-b-agent-research/B001/00016L-SoftwareRenderRgb565Callbacks.md`,
    SHA256 `4E79414CF207503E0CFFA18B50B0078870FB4AE559E13C5A8E20EF12381CDA5C`,
    is direct aggregate/address coverage only. It established Surface ownership
    and exact children but explicitly left UID0002PI typedef, field, mode, and
    final-C++ work open.
  - `executed-b-agent-research/B011/0002PF-SoftwareRenderCompatPixelCallback-source-quality.md`,
    SHA256 `8B4460FE3218A0D6A389DB41AC75F0A532EABE0DF7695A2E58FB19919A827E1B`,
    is the exact compat peer. It proves the shared ABI and explicitly says
    UID0002PI requires its own source-quality pass.
  - `executed-b-agent-research/B004/00039V-SurfaceRenderCallbackInitializerRaw-source-quality.md`,
    SHA256 `4AAB76A9EAF95AB0F212712F2151A5D2A06A28F5B741C6313A4CE7722FDE7106`,
    is initializer/table support. It proves the paired slot-0 targets and
    descriptive `g_pfnDrawPixel` interface, not the UID0002PI body.
  - `executed-b-agent-research/B005/0000OC-Surface-empty-emitter-family-source-quality.md`,
    SHA256 `E91B3A185201B5BD7E0669A00D5F1AE257549F472DA956EF072B5801A81C2271`,
    is Surface-family support. Its historical blank-C++/table-typedef
    conclusions were valid for that bounded batch but are superseded for slot
    0 by the current target-specific pass.
  - `executed-b-agent-research/B012/0002TI-SoftwareRenderRgb565BitmaskBlitCallback-source-quality.md`,
    SHA256 `FC217E5B4196CC840A9DA066F29AEA24779066D2A777344DF914AA7FD2FAAC65`,
    and
    `executed-b-agent-research/B002/0002YK-SoftwareRenderRgb565FillCallback-source-quality.md`,
    SHA256 `DA30F3070A44B23057602D86CFEB3C4BCAF3DA48A355A5509BEC9AB5C15BB9CF`,
    are same-family field/mode/palette/blend support, not direct target
    substitutes.
  - `tools/leaser/Agents/Older-Research/Agent-B011/00016I-GrafPortDrawGlyph-source-quality.md`
    contains only incidental Surface callback-table dependency evidence.
  - `tools/leaser/Agents/SpecialReports` returned no direct target or
    equivalent-body match.
- Conclusion from the complete search: no direct UID0002PI report existed in
  active, executed, archived, older-research, or special-report roots. The
  matching artifacts are aggregate, peer, initializer, owner, dependency, or
  incidental evidence only.

## Target

- Target UID: `0002PI`.
- Target path:
  `by-memory/0x004c0770-0x004c0845.SoftwareRenderRgb565PixelCallback.md`.
- Exact target range: `[0x004c0770,0x004c0845)`.
- Historical source queue/report row at assignment time: `87/89`,
  reconstructable true, direct report count zero.
- Current supervisor classification: accepted implementation callback complete;
  the same report is awaiting independent supervisor Gate 2 review.
- Current scores and parent state: `92/94`, owner/emitter UID0000OC Surface,
  reconstructable true, blank emitter position, populated formal C++,
  `Nested:4`.
- Current target page SHA256:
  `BE677EA06337878F42D7729DE38018A5B6F6F2BE40C914281996E02088A8CBDB`.

## Current Target State

- Current metadata and formal source are applied: Surface remains the direct
  semantic/source owner and emitter, the exact callback range remains
  reconstructable, the target remains one level beneath the non-emitting
  UID00016L family index, and the score is `92/94`.
- Callback typedef, receiver fields, RGB565 mode taxonomy, palette/helper names,
  source routing, and complete formal body are resolved and incorporated.
- Current touched-state prose records the exact stride/origin fields and
  explicitly separates unused `+0x74/+0x84/+0x90` state from direct reads.
- The target directly reads only receiver offsets `+0x20`, `+0x28`, `+0x2c`,
  `+0x30`, `+0x70`, and `+0x71`.
- Receiver `+0x74` is accepted `unsigned int m_drawColor` and receiver `+0x90`
  is accepted `float m_alpha`, but neither is read by this callback. They are
  surrounding GrafPort state used by other callback slots.
- Latest-observed terminal readback of
  `auto-generated/NexusTK/render/Surface.cpp` was external validator command
  `000000014335`, SHA256
  `3A8EF215DBBB8B9307B20919BFE26E67A73B2B308212CF0CD3569D14205C57FE`,
  24,026 bytes / 675 lines. It contains one UID0002PI marker and definition,
  zero UID0002PI Empty Emitter Markers, one UID0000TN declaration block, and
  the exact accepted behavior and source order.
- Current report artifact state: implementation is complete. B001 edited and
  scoped-validated D1-D7 under short leases, released every lease, and ran the
  authorized final waited refresh. B001 did not mutate IDA, edit manual
  coverage/generated files, run `execute_report` or any report lifecycle/probe/
  count command, move, or archive the report.

## Current Artifact Snapshot

- Callback-complete snapshot time:
  `2026-07-16T15:51:24-04:00`.
- Ordinary destination snapshots:

| Destination | SHA256 | Bytes | Physical lines |
| --- | --- | ---: | ---: |
| D1 target | `BE677EA06337878F42D7729DE38018A5B6F6F2BE40C914281996E02088A8CBDB` | 23,846 | 246 |
| D2 UID00016L aggregate | `DC639271C6954882C1DE93BC02E27A08CA05982779FE36DBBB10D221D13EE99C` | 45,724 | 260 |
| D3 Surface file | `DEACFBF623AA152451583F1BB98731C9D834117F7EC4A23544CE676F12713D3B` | 106,474 | 441 |
| D4 callback global | `4F8C7C217E67AB9A4BA9CD9693D5D13A33DEC860A8276DEB7B789A8680AC3AC6` | 58,714 | 299 |
| D5 callback storage | `B48DEBFB8E66D64082894FAF9760D7855E683DBD2D7CE945CFFBBEEC13C9CB9A` | 51,300 | 295 |
| D6 compat peer | `B4EBCDE2C0CB38BB8249D5E22C3A7CF9FE2AA7CAE29A77FA870EA5E038522F9E` | 19,622 | 185 |
| D7 ignored ranges | `C4875C9DB2BAEF070BE1E0EDFE9268918E93596311CA038F6195764F7D1BDFE9` | 1,050,647 | 5,140 |

- Latest-observed terminal generated Surface snapshot:
  `auto-generated/NexusTK/render/Surface.cpp`, validator command
  `000000014335`, refreshed `2026-07-16T16:03:19-04:00`, SHA256
  `3A8EF215DBBB8B9307B20919BFE26E67A73B2B308212CF0CD3569D14205C57FE`,
  24,026 bytes, 675 physical lines, filesystem refresh
  `2026-07-16T16:03:38.6515322-04:00`.
- B001's final waited command was `000000014303` at
  `2026-07-16T15:51:05-04:00`, SHA256
  `3DD57EEB003205FFD993A9D47D289098F2AA90B881C8E99D0102D814050A1270`.
  The later external validator refresh changed command/header provenance only:
  bytes/lines, source order, all target/global/peer counts, and exact callback
  body assertions remain unchanged. The current content after the four-line
  generated header has SHA256
  `7C2B7A487F4BF8B61AF8A642E2E4DB70F80E3185A22639E241D791A7C1CEE4BD`.
- Terminal-readback generated counts:
  one UID0002PI marker and definition; zero target Empty Emitter Markers; one
  UID0000TN marker/declaration and zero UID0000TN Empty Emitter Markers; zero
  UID0001PI and UID00016L duplicate markers; one compat definition; one RGB565
  definition; one `SurfaceDrawPixelProc g_pfnDrawPixel` definition; exactly
  two initializer assignments; compat before target before UID00039V.
- The target block has zero `m_drawColor`, `m_palette`, `m_alpha`,
  `RankingEventListPane`, or `GrafPort::` tokens; one low-byte direct expression,
  one fixed RGB565 blend call, two `rowStridePixels` references, and no cookie,
  explicit padding, aggregate, or storage duplicate.
- Manual snapshot metrics after callback readback:
  - by-memory:
    `28519EC29A329E50F26567E5AD845231716C33BA64B3B6C5F3856C635BE35CAB`,
    1,783,379 bytes, 4,267 lines;
  - by-class:
    `37519F59619A71953B1019D6175D96F19159B039CFA60763393B8DEBE918AE45`,
    230,719 bytes, 622 lines;
  - by-file:
    `28DD34838534E65F5AABA8A4E147754C5B37AB08A04C99BBFC0888F252127672`,
    132,321 bytes, 316 lines;
  - by-global:
    `CA6748C2ED56235F95727DFE7C000B30B03213EF42D1F9A93BF796B550A5DB32`,
    90,148 bytes, 212 lines.

- Verify-only dependency readback:

| Dependency | Current SHA256 | Result |
| --- | --- | --- |
| UID00039V initializer | `F37F817ADB3F87DF6848160E8EF894AEE54A70BD4686DEAB108147DB72C874CA` | Both slot-0 assignments and complete initializer formal remain present. |
| GrafPort class | `F1AD63407DAD2CCE4891E755A9F6271F259D3BEB40E9780A74A250A52B16053C` | Accepted receiver fields remain same-or-greater; no edit. |
| GrafPort file | `F1BC7F4AB313CA6CD07C66D75210C619BA9E382D4AF19ADE422EBE6DDD4F7E56` | Source dependency route unchanged; no edit. |
| SurfacePaintHelpers aggregate | `0796377809A8D6408C0C71660AE78DDFA79686855473B62F4EE937FA77F4283F` | Existing split/index facts unchanged; no edit. |
| EPFTileContext class | `7EC740D8A5B1FBA0A74EF46A75FBD6B684408E3EC42A939E4A20ABE7D9347F28` | Surface-context type/layout remains same-or-greater; no edit. |
| GrafPortGetClipRect | `0B1DE75BC1AE723E24AAAB0A09200A04C1CE0EA868CBF2E27BC514D527637A80` | Accepted clip helper/type route unchanged; no edit. |
| RectGeometryHelpers | `94449DADA6F3BF1278A7581214ADAA3026C6D71C62AD494C54B48E132A9A40EE` | `PointInRect` direction remains same-or-greater; no edit. |
| PaletteLib file | `FF3C686D877C46153746A1160EFC406DE448454047857661F6516DA1B6D0E0B4` | Current-palette ownership unchanged; no edit. |
| DLPalette class | `0B7EC54098FA2E1AEE429374F93D95EF39B4CEE86E2ED8B9201A7B6A4B0C62F6` | Palette mapping declaration unchanged; no edit. |
| DLPaletteMapColor | `EF6C793D6E64A4FB85795E1C5AAEA9E1C7B45702084C451FB43A1AD73C15BCAC` | Exact >255 behavior remains same-or-greater; no edit. |
| g_pPaletteLib | `BE17977DBDDD9461BA8C68B6EE31FF2827A2CCCF5D7820C70A4C12114A75CC8A` | Global route unchanged; no edit. |
| BlendRgb565Pixel | `990A8D450808C091DBE7766906D92DCB05AE790C4BAE4C8A5520E5338DE92DDF` | Existing-first/mapped-second fixed-weight behavior unchanged; no edit. |
| UID0003PJ rain caller | `80D32574AF8F85903FF2F93E773572DCB5C048AFF091736DEA768B48B67BF71D` | Slot-0 consumer role retained; no owner transfer/edit. |
| UID0003PK rain caller | `9C29E827D5E8645A332D02E37043AFA6EF48CCF8DB961CB7A9CD848FD83BDE2B` | Slot-0 consumer role retained; no owner transfer/edit. |

## Executive Recommendation

- The accepted callback kept the target path/title and direct Surface
  owner/emitter.
- Target metadata is now `92/94`; reconstructable true, blank target position,
  and `Nested:4` are preserved.
- Destination 1 is populated exactly.
- Current source uses file-local Surface implementation linkage and the shared
  descriptive
  slot-0 type `SurfaceDrawPixelProc`.
- UID0000TN now contains the slot-0 typedef and one global definition at
  emitter position `20`, before the positioned callback implementations and
  initializer.
- The compat peer's complete formal body now uses accepted
  `rowStridePixels` and to defer destination pointer calculation until a
  write-producing mode survives its color-key gate.
- UID0001PI remains data/storage documentation with blank formal C++; the
  source declaration belongs to the by-global symbol page, not a handwritten
  memory-table body.
- UID00016L remains non-reconstructable and non-emitting; only its UID0002PI
  child status and stale backlog wording changed.
- `[0x004c0845,0x004c0850)` is now recorded in `by-memory/-ignored.md` as
  eleven proven `0xcc` bytes.

## Supervisor Active Recheck

- The supervisor assigned a dedicated reanalysis rather than permission to
  repeat the older aggregate no-code conclusion.
- No split repair is needed. The target is one complete modeled function with
  a non-function exclusive end and clean alignment before the successor.
- Every source-bearing item in this bounded pass has an exact destination:
  the target body, compat peer body, and slot-0 global declaration/definition.
- Every non-source binary artifact in scope has an exact disposition:
  predecessor/successor alignment is ignored, the cookie is compiler-only, and
  UID0001PI remains storage evidence rather than duplicate handwritten code.

## Inference Research Guidance Check

- IDA facts are separated from source inference:
  exact bytes, instruction/control flow, xrefs, register/stack ABI, offsets,
  calls, and constant values are direct IDA/PE facts.
- Documentation evidence supplies accepted source types and names:
  `GrafPort`, `EPFTileContext`, `RectBounds`, `DLPalette`, `PaletteLib`,
  `m_surfaceContext.pixelData`, `rowStridePixels`, `bounds`,
  `m_drawMode`, `m_drawEnabled`, `m_drawColor`, and `m_alpha`.
- Source inference supplies descriptive lexical choices:
  `SoftwareRenderRgb565PixelCallback`, `SurfaceDrawPixelProc`, file-local
  linkage, and copy/color-key/blend mode labels. These are selected for
  reconstruction and are not claimed as recovered debug symbols.
- Existing assumptions treated as potentially wrong and rechecked:
  RankingEventListPane ownership, GrafPort member ownership, SoftwareBlend16
  ownership, global-table object shape, target use of `m_drawColor` or
  `m_alpha`, target palette fallback through `m_palette`, canonical mapped
  RGB565 direct writes, and physical EAX return use.
- Wave2/Wave3 mentions encountered in older broad documentation were not used
  as authority. Current binary, current docs, current generated output, and
  current executed reports control this recommendation.

## Heuristic / Inference Reanalysis And Validation

1. Callback ABI and return:
   - Direct fact: ECX is preserved as the draw receiver; the epilogue is
     `retn 0x0c`; stack arguments are x, y, and unsigned color index.
   - Direct fact: no intentional return value is established. Raining caller
     decompiles expose incidental EAX only because the final indirect call is
     textually last.
   - Decision: source return is `void`, using the accepted project
     receiver-in-ECX callback convention.

2. Receiver type:
   - Direct fact: the body calls the GrafPort clip method and reads the exact
     embedded surface/draw-state offsets documented on GrafPort.
   - Decision: strongest receiver type is `GrafPort *`, not `void *`, Surface
     object, pane-specific type, or raw integer.

3. Coordinates and color argument:
   - Direct fact: `PointInRect` receives y then x and tests
     `left <= x < right`, `top <= y < bottom`.
   - Direct fact: the destination formula uses x horizontally and y
     vertically.
   - Direct fact: all twelve recovered dynamic dispatches pass explicit color
     index `143`.
   - Decision: parameters are `int x`, `int y`, and
     `unsigned int colorIndex`.

4. Callback type/global:
   - Direct fact: slot `0x0069b3e0` is one zero-initialized dword, selected
     between two same-ABI targets, and called with ECX plus three stack args.
   - Project precedent: current source docs already use MSVC-style
     `__thiscall` function-pointer typedefs with an explicit receiver.
   - Decision: descriptive type is `SurfaceDrawPixelProc`; global is
     `g_pfnDrawPixel`. The page models one typed global, not a runtime table
     object.

5. Linkage and source placement:
   - Direct fact: the target address is referenced only by the out-of-line
     Surface initializer and its complete inline copy. No export, ordinary
     call, vtable, registration, or other name-based external route exists.
   - Decision: highest-probability implementation is a file-local Surface
     callback. The global pointer has external module storage because broad
     consumers dispatch through it.

6. Surface-context fields:
   - `+0x20`: accepted `void *m_surfaceContext.pixelData`; interpreted here as
     an array of 16-bit destination pixels.
   - `+0x28`: accepted `int m_surfaceContext.rowStridePixels`; the multiplier
     is logical pixels, not bytes.
   - `+0x2c`: `m_surfaceContext.bounds.left`.
   - `+0x30`: `m_surfaceContext.bounds.top`.
   - Decision: pointer expression is the 16-bit base plus
     `(y - top) * rowStridePixels + (x - left)`.

7. Draw-state fields:
   - `+0x70`: accepted `unsigned char m_drawMode`.
   - `+0x71`: accepted `bool m_drawEnabled`.
   - `+0x74`: accepted `unsigned int m_drawColor`, but no target instruction
     reads it.
   - `+0x90`: accepted `float m_alpha`, but no target instruction reads it.
   - Decision: the explicit `colorIndex` parameter and fixed blend weight
     replace the two surrounding-state roles for this callback only.

8. Palette route:
   - Direct fact: target always calls
     `g_pPaletteLib->GetCurrentPalette()` and then
     `DLPalette::MapColor(colorIndex)`.
   - Direct fact: it never reads GrafPort `m_palette` at `+0x84`.
   - Decision: no per-port palette fallback belongs in this body.

9. Palette-map timing:
   - Direct fact: palette lookup and MapColor occur after clipping but before
     draw-mode dispatch, including direct modes and unknown modes.
   - Decision: keep the call before the switch even when its mapped result is
     unused in direct modes.

10. Mode 0:
    - Direct fact: writes the low byte of the full color index, zero-extended
      to 16 bits.
    - Decision: source label is direct/copy; do not replace it with the mapped
      RGB565 color.

11. Mode 1:
    - Direct fact: tests the full 32-bit color index for zero, then performs
      the same low-byte direct write.
    - Decision: source label is color-keyed direct/copy. A value such as
      `0x100` passes the nonzero gate and writes zero because its low byte is
      zero.

12. Mode 2:
    - Direct fact: maps the palette color, loads the existing destination
      pixel, and calls `BlendRgb565Pixel(existing, mapped, 0x10)`.
    - Decision: unconditional half blend.

13. Mode 3:
    - Direct fact: tests the full color index for zero before the same fixed
      blend.
    - Decision: color-keyed half blend.

14. Unknown modes:
    - Direct fact: values other than 0 through 3 perform no pixel address
      calculation and no write.
    - Decision: the formal body keeps pointer calculation inside the selected
      write branch rather than precomputing it for default/no-write modes.

15. Blend direction:
    - Current UID00016M formal and direct decompile prove the third argument is
      the first/existing pixel weight in a 0..32 domain.
    - `0x10` is 16 decimal, so existing and new pixels are weighted equally.
    - Decision: fixed 50/50 blend; `m_alpha` is not consulted.

16. Compat peer:
    - The two 213-byte bodies differ at only fourteen byte positions, all in
      relative call displacements. Their instruction/control-flow templates
      are otherwise identical; the semantic backend difference is
      `BlendRgb555` versus `BlendRgb565Pixel`.
    - Decision: shared ABI/type/mode names are valid. The peer's stale
      `rowStride` token and eager pointer calculation should be corrected in a
      complete formal block.

17. Generated marker:
    - Current generated output has a valid Surface route and one UID0002PI
      Empty Emitter Marker.
    - Decision: the marker is caused solely by the blank target formal block.
      Filling the exact target body should replace that marker without owner
      rerouting or aggregate emission.

18. Rejected alternatives:
    - `RankingEventListPane::PutPixel_565`: generated/caller-biased pollution;
      no ranking direct call or state exists.
    - `GrafPort::PutPixel`: receiver-compatible but contradicted by paired
      backend selection and callback-table installation.
    - `Surface` member callback: there is no Surface object receiver.
    - `SoftwareBlend16` owner: only the reusable blend callee belongs there.
    - canonical RGB565 direct write: contradicted by `movzx ecx, bl`.
    - target use of `m_drawColor`, `m_alpha`, or `m_palette`: contradicted by
      absent offset loads.
    - hand-authored cookie/padding/table body: compiler/linker artifacts.

## Evidence Standards Used

- Primary binary evidence: fresh live IDA MCP `idb_list`, `server_health`,
  `lookup_funcs`, `get_bytes`, `disasm`, `decompile`, `analyze_function`,
  `func_profile`, `basic_blocks`, `xrefs_to`, `search_text`, and signature
  generation.
- Independent raw evidence: mapped PE section/RVA-to-file-offset read and
  SHA256 of the exact target bytes and successor padding.
- Context evidence: current target/support docs, current generated
  `Surface.cpp`, current manual coverage rows, current tracker row, and
  target-specific historical reports.
- Type/name evidence: current GrafPort, EPFTileContext, RectBounds,
  PaletteLib, DLPalette, and blend-helper docs.
- Negative evidence: no direct callers, no end xrefs, no vtable/export route,
  no reads of `+0x74/+0x84/+0x90`, no target strings, no EH route, and no
  direct feature-owner state.
- Strength assessment: exact behavior and source route are closed. Remaining
  uncertainty is lexical only and does not justify blank C++ or a lower
  source-quality disposition.

## Evidence Checked

- Fresh MCP transport:
  - `idb_list` returned active session `64c11373`.
  - `server_health(database:"64c11373")` returned `status:"ok"`.
  - Bounded target `lookup_funcs`, `get_bytes`, `decompile`, `disasm`,
    `analyze_function`, `func_profile`, `basic_blocks`, `xrefs_to`, and
    signature calls succeeded.
- Target/function checks:
  - start `0x004c0770`, size `0xd5` / 213 decimal;
  - end `0x004c0845` is not a function;
  - successor `0x004c0850` is a function of size `0x72a`;
  - 84 instructions, 11 blocks, complexity 8;
  - exact source return/arguments and `retn 0x0c`;
  - full disassembly and decompile compared.
- Raw byte checks:
  - full 213-byte target body read from MCP;
  - eleven successor bytes read from MCP;
  - independent PE mapping to `.text`, RVA `0x000c0770`, raw offset
    `0x000bfb70`;
  - MCP and PE target hashes match;
  - predecessor three-byte alignment verified in current ignored docs and PE.
- Xref checks:
  - target start refs at `0x00558833` and `0x00558e9c`;
  - no xref to target end;
  - fifteen refs to slot storage `0x0069b3e0`;
  - exact three setup/storage refs plus twelve indirect dispatch refs.
- Caller checks:
  - complete decompiles of `RainingLayerPane::OnPaint` at `0x005c1460` and
    `RainingLayerPane::DrawRainOnTarget` at `0x005c1810`;
  - all twelve dispatches use a GrafPort receiver, explicit x/y, and color
    index 143;
  - callback result is not semantically consumed.
- Callee checks:
  - GrafPort clip builder `0x004b96c0`;
  - half-open `PointInRect` `0x004b7e80`;
  - PaletteLib current-palette getter `0x00543d40`;
  - DLPalette map lookup `0x00542ac0`;
  - RGB565 blend helper `0x004c6050`;
  - compiler security-cookie check `0x005c772f`.
- Current docs checked:
  target, UID00016L aggregate, UID0002PF peer, Surface file, callback-table
  global and storage, UID00039V initializer, GrafPort class/file/aggregate,
  EPFTileContext, GetClipRect, RectGeometryHelpers, PaletteLib, DLPalette,
  g_pPaletteLib, BlendRgb565Pixel, both Raining caller pages, and
  `by-memory/-ignored.md`.
- Terminal generated check:
  read-only `auto-generated/NexusTK/render/Surface.cpp`; current command
  `000000014335`, hash
  `3A8EF215DBBB8B9307B20919BFE26E67A73B2B308212CF0CD3569D14205C57FE`,
  target/peer/global markers, exact body tokens, function counts, source order,
  assignments, and duplicate/empty-marker exclusions were inspected. B001 did
  not edit generated output; B001 command `000000014303` performed the
  authorized refresh and later external command `000000014335` advanced only
  validator-owned header provenance without semantic drift.
- Current manual coverage checks:
  read-only by-memory, by-class, by-file, and by-global manual coverage files;
  all affected existing rows and the missing successor-padding row were
  classified.
- Historical searches: all active B001-B005 roots, central executed archive,
  Older-Research, and SpecialReports.
- Tool limitations:
  - An initial PowerShell request lacked `-UseBasicParsing`; this was a local
    client issue, not MCP unavailability.
  - An initial JSON-RPC batch accidentally used PowerShell's reserved `$args`,
    stripping database arguments and producing `database is required`; valid
    retries with the exact schemas succeeded.
  - First valid `get_bytes` and signature attempts used old parameter names;
    `tools/list` supplied the current `regions` and `addrs` schemas and valid
    retries succeeded.
  - A relocatable/wildcard signature was not unique within 213 bytes because
    the compat peer is instruction-shape-identical. A non-wildcard signature
    became unique after 45 bytes. This is positive peer evidence, not a worker
    failure.
- Phase-qualified operational record:
  during the initial report-only evidence pass, ordinary edits, leases,
  validators, and generated refresh were intentionally not performed. During
  the accepted implementation callback, D1-D7 ordinary edits, short leases,
  seven scoped validators, and one final waited generated refresh were
  performed as enumerated below. IDA mutation, manual coverage edits,
  `execute_report`, report lifecycle/probe/count commands, movement, and
  archival remained unperformed by B001.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C2PI-001 | UID0002PI is exactly `[0x004c0770,0x004c0845)`, one 213-byte modeled function. | high | lookup, disasm, PE mapping | D1 target range/evidence | incorporate | applied |
| C2PI-002 | Target body SHA256 is `3562BA86A71E5D553D9394A5A511D10C9EABA6D73EE31623091BA8D25D720735`. | high | MCP bytes plus PE read | D1 exact bytes/hash | incorporate | applied |
| C2PI-003 | Binary identity is MD5 `4247...5515`, SHA256 `9AEC...A632`, image base `0x400000`. | high | server health, file hashes | D1 evidence/history | incorporate | applied |
| C2PI-004 | Predecessor UID00016K ends at `0x004c076d`; `[0x004c076d,0x004c0770)` is three `cc` bytes already present. | high | lookup, PE, ignored doc | D1 boundary; verify ignored | already-present | already-present |
| C2PI-005 | `[0x004c0845,0x004c0850)` is eleven `cc` bytes before UID0002PJ. | high | MCP/PE bytes, successor lookup | D1 boundary; D7 ignored | incorporate | applied |
| C2PI-006 | Function has 84 instructions, 11 blocks, complexity 8, no strings, and no EH. | high | profile, blocks, disasm | D1 CFG/evidence | incorporate | applied |
| C2PI-007 | Source ABI is receiver-in-ECX plus x/y/colorIndex, `retn 0x0c`, source return `void`. | high | disasm/decompile/callers | D1 ABI; D4/D5 slot | incorporate | applied |
| C2PI-008 | Target has zero ordinary callers and two address data refs, at `0x00558833` and `0x00558e9c`. | high | xrefs | D1 liveness; D2-D5 | incorporate | applied |
| C2PI-009 | Slot `0x0069b3e0` has exactly fifteen refs: three setup/storage and twelve dispatch. | high | xrefs_to slot | D1; D4/D5 | incorporate | applied |
| C2PI-010 | Raw initializer loads target at `0x00558833` and reaches the shared slot store. | high | search/disasm, UID00039V | D1; D4/D5 | incorporate | applied |
| C2PI-011 | Live modeled initializer stores target at `0x00558e9c`. | high | xrefs/search, sub_558840 | D1; D2-D5 | incorporate | applied |
| C2PI-012 | All twelve dynamic dispatch refs are in UID0003PJ/UID0003PK rain drawing. | high | slot xrefs and caller decompiles | D1 caller inventory | incorporate | applied |
| C2PI-013 | Rain calls pass explicit color index 143 and ignore callback return semantics. | high | caller decompiles | D1 caller behavior | incorporate | applied |
| C2PI-014 | `0x004b96c0` is GrafPort `GetClipRect` and supplies a 16-byte RectBounds. | high | helper decompile/current doc | D1 body; verify helper | already-present | already-present |
| C2PI-015 | `PointInRect(y,x,&rect)` uses half-open left/right and top/bottom tests. | high | helper decompile | D1 body/evidence | incorporate | applied |
| C2PI-016 | Palette route is `g_pPaletteLib->GetCurrentPalette()` with no per-port fallback. | high | target disasm/decompile | D1 body; D2-D5 | incorporate | applied |
| C2PI-017 | `DLPalette::MapColor` returns zero for index above 255 and otherwise returns mapped entry. | high | helper decompile/current doc | D1 behavior | incorporate | applied |
| C2PI-018 | `BlendRgb565Pixel` weights existing pixel first and mapped pixel second; weight 16 is 50/50. | high | helper decompile/formal | D1 behavior; verify helper | already-present | already-present |
| C2PI-019 | Receiver `+0x20` is `void *m_surfaceContext.pixelData`, interpreted as 16-bit pixels here. | high | target access/current layout | D1 fields; verify GrafPort | incorporate | applied |
| C2PI-020 | Receiver `+0x28` is `int m_surfaceContext.rowStridePixels`. | high | target access/current layout | D1; D6 peer | incorporate | applied |
| C2PI-021 | Receiver `+0x2c/+0x30` are bounds left/top and define the destination origin. | high | target formula/current layout | D1 fields/body | incorporate | applied |
| C2PI-022 | Receiver `+0x70` is `unsigned char m_drawMode`. | high | target access/current layout | D1 fields/modes | incorporate | applied |
| C2PI-023 | Receiver `+0x71` is `bool m_drawEnabled`; false exits before clipping. | high | target access/current setters | D1 body/fields | incorporate | applied |
| C2PI-024 | Receiver `+0x74` is `unsigned int m_drawColor`, but UID0002PI never reads it. | high | target negative scan/current accessors | D1 negative fields | incorporate | applied |
| C2PI-025 | Receiver `+0x90` is `float m_alpha`, but UID0002PI never reads it. | high | target negative scan/current GrafPort | D1 negative fields | incorporate | applied |
| C2PI-026 | Target never reads `m_palette` at `+0x84`; global current palette is mandatory. | high | target negative scan | D1 negative/palette | incorporate | applied |
| C2PI-027 | Mode 0 writes low eight bits of colorIndex, zero-extended to 16 bits. | high | direct store instructions | D1 behavior/body | incorporate | applied |
| C2PI-028 | Mode 1 gates on full colorIndex nonzero, then performs the same low-byte write. | high | branch/store | D1 behavior/body | incorporate | applied |
| C2PI-029 | Mode 2 always blends existing and mapped pixels with fixed weight 16. | high | branch/call | D1 behavior/body | incorporate | applied |
| C2PI-030 | Mode 3 gates on full colorIndex nonzero, then performs the same blend. | high | branch/call | D1 behavior/body | incorporate | applied |
| C2PI-031 | Other mode values do no address calculation and no write. | high | CFG | D1 behavior/body | incorporate | applied |
| C2PI-032 | Palette mapping occurs before mode dispatch even when direct/default paths do not use mappedColor. | high | instruction order | D1 behavior/body | incorporate | applied |
| C2PI-033 | Canonicalizing direct modes to mapped RGB565 would change observed behavior and is invalid. | high | `movzx ecx,bl` | D1 negative/history | reject-invalid | excluded-with-reason |
| C2PI-034 | Replacing fixed weight 16 with `m_alpha` would change observed behavior and is invalid. | high | immediate 0x10, no +0x90 read | D1 negative/history | reject-invalid | excluded-with-reason |
| C2PI-035 | Strongest target name/signature is file-local `SoftwareRenderRgb565PixelCallback` over GrafPort/x/y/colorIndex. | medium-high lexical, high semantic | peer, initializer, ABI | D1 formal/source | incorporate | applied |
| C2PI-036 | Strongest shared type/global is `SurfaceDrawPixelProc g_pfnDrawPixel`. | medium-high lexical, high semantic | slot layout, project typedef precedent | D4 formal; D5 prose | incorporate | applied |
| C2PI-037 | Direct semantic owner/emitter remains UID0000OC Surface. | high | initializer, table, family, no direct callers | D1-D5 | incorporate | applied |
| C2PI-038 | GrafPort is receiver/layout dependency, not direct source owner. | high | callback selection/no member route | D1/D3; verify GrafPort | reject-invalid | excluded-with-reason |
| C2PI-039 | UID0000TN/UID0001PI own symbol/storage documentation, not duplicate callback body. | high | by-structure, fixed globals | D4/D5 | incorporate | applied |
| C2PI-040 | SoftwareBlend16 owns BlendRgb565Pixel only, not UID0002PI. | high | callee versus target install | D1/D2/D3 | reject-invalid | excluded-with-reason |
| C2PI-041 | RankingEventListPane and RainingLayerPane are generated pollution/consumers, not owners. | high | no direct route, table calls | D1/D2/D3 | reject-stale | excluded-with-reason |
| C2PI-042 | Target emitter position stays blank so unpositioned Surface children keep address/scan order. | medium-high | current generator ordering | D1 metadata | already-present | already-present |
| C2PI-043 | UID0000TN should use emitter position 20 so slot-0 type/global precedes callback bodies and initializer. | high source integration | current positions 9/10/100..105 and generated order | D4 metadata | incorporate | applied |
| C2PI-044 | Target score should be `92/94`; original lexical spellings cap higher values. | high | complete blocker audit | D1 metadata/score | incorporate | applied |
| C2PI-045 | Destination 1 exact managed body is behavior-identical and source-ready. | high | complete evidence | D1 formal | incorporate | applied |
| C2PI-046 | Compat peer formal must use `rowStridePixels` and write-branch-local pointer calculation. | high | current declarations and identical CFG | D6 formal/prose | incorporate | applied |
| C2PI-047 | UID00016L stays `90/92`, NONE/FALSE/blank, but its UID0002PI row/backlog becomes source-ready. | high | current aggregate role | D2 prose only | incorporate | applied |
| C2PI-048 | Surface file stays `88/85` and records UID0002PI as source-ready slot-0 implementation. | high | current file role | D3 prose only | incorporate | applied |
| C2PI-049 | UID0000TN stays `89/86`, gains bounded slot-0 formal and position 20, while other slot typedef debt remains. | high | bounded source shape | D4 metadata/formal/prose | incorporate | applied |
| C2PI-050 | UID0001PI stays `89/88` with blank formal and gains exact slot-0 source-ready/storage evidence. | high | storage/source boundary | D5 prose only | incorporate | applied |
| C2PI-051 | Missing successor padding belongs in `by-memory/-ignored.md`; no target split is needed. | high | exact bytes/boundaries | D7 ignored | incorporate | applied |
| C2PI-052 | The initial generated Empty Emitter Marker was caused by blank target C++; callback validation replaced it with one definition. | high | historical/current generated file | D1/D3; generated checklist | historicalize | applied |
| C2PI-053 | Manual coverage rows are stale/absent and exact supervisor-owned text is supplied below. | high | current manual readback | coverage handoff | incorporate | already-present |
| C2PI-054 | Older reports are support evidence only; no direct target report existed before this artifact. | high | full root search | D1 history/report | incorporate | already-present |
| C2PI-055 | No rename, child UID, new file, table-object split, third-party import, or IDA edit is needed. | high | exact one-function/source route | report/checklist | not-applicable | excluded-with-reason |
| C2PI-056 | Security cookie, saved-register schedule, two epilogues, and alignment are compiler output. | high | disassembly | D1 compiler boundary | incorporate | applied |
| C2PI-057 | Exact non-wildcard 45-byte signature is unique; wildcard signature collision reflects peer similarity. | high | signature tools | D1 evidence | incorporate | applied |
| C2PI-058 | All ordinary destinations were reread; evidence-time and callback-complete hashes are recorded. | high | file hashes | report current-state table | incorporate | applied |
| C2PI-059 | Validators/generated refresh were not run during report-only research; seven scoped and one waited command were run during callback. | high | phase-qualified operational record | Validator Results/checklist | not-applicable | excluded-with-reason |
| C2PI-060 | B001 ends the callback with zero leases and performed no lifecycle/execute/move/archive action. | high | current lease file and command record | Changed Files/checklist | not-applicable | applied |

### Callback Claim Verification Notes

| Claim ID | Callback proof |
| --- | --- |
| C2PI-001 | D1 current range/title remain exact; command `000000014269` and final command `000000014303` both returned exit 0 / `ok:1`. |
| C2PI-002 | D1 `Exact Binary And Boundary Evidence` records body SHA256 `3562BA...0735`; formal/generated behavior readback agrees with the decoded body. |
| C2PI-003 | D1 preserves the accepted NexusTK MD5/SHA256/image-base evidence under the callback section. |
| C2PI-004 | D7 retained the pre-existing `[0x004c076d,0x004c0770)` entry unchanged; no duplicate predecessor row was added. |
| C2PI-005 | D7 now has one `[0x004c0845,0x004c0850)` row with exact eleven-byte hash `3682C0...0943`; command `000000014302` passed. |
| C2PI-006 | D1 records 84 instructions, 11 blocks, complexity 8, no strings, and no EH in the exact binary section. |
| C2PI-007 | D1, D4, and D5 record source `void`, GrafPort receiver in ECX, x/y/colorIndex stack arguments, and physical `retn 0x0c`. |
| C2PI-008 | D1-D5 record zero ordinary callers and exact target refs `0x00558833`/`0x00558e9c`. |
| C2PI-009 | D1, D4, and D5 record fifteen slot refs divided into three setup/storage plus twelve dispatch. |
| C2PI-010 | D1/D4/D5 preserve raw target load `0x00558833`; current UID00039V hash `F37F...74CA` retains both assignments. |
| C2PI-011 | D1/D2/D4/D5 preserve modeled initializer store `0x00558e9c`; UID00039V current formal remains unchanged. |
| C2PI-012 | D1 names both exact rain children; read-only hashes are UID0003PJ `80D325...71D` and UID0003PK `9C29E8...DE2B`. |
| C2PI-013 | D1 caller section preserves explicit color index 143 and ignored return semantics; rain pages remain consumers only. |
| C2PI-014 | Verify-only GrafPortGetClipRect hash `0B1DE7...7A80` remains unchanged; D1 formal calls `GetClipRect`. |
| C2PI-015 | D1 records half-open `PointInRect(y,x,&clipRect)` behavior; verify-only RectGeometryHelpers hash is `94449D...40EE`. |
| C2PI-016 | D1/D2/D3 record mandatory `g_pPaletteLib->GetCurrentPalette()` route with no per-port fallback. |
| C2PI-017 | D1 preserves the accepted `DLPalette::MapColor` >255-to-zero rule; verify-only map helper hash is `EF6C79...BCAC`. |
| C2PI-018 | D1 preserves existing-first/mapped-second weight-16 behavior; verify-only BlendRgb565Pixel hash is `990A8D...2DDF`. |
| C2PI-019 | D1 field table and exact body use `m_surfaceContext.pixelData`; GrafPort/EPFTileContext verify-only hashes remain recorded below. |
| C2PI-020 | D1 and D6 exact bodies use `rowStridePixels`; generated callback pair contains five total `rowStridePixels` field references. |
| C2PI-021 | D1 field table and both formal bodies preserve bounds left/top destination-origin arithmetic. |
| C2PI-022 | D1 field table and formal read `const unsigned char drawMode = port->m_drawMode`. |
| C2PI-023 | D1 field table and formal preserve the early `m_drawEnabled` guard before clip/palette work. |
| C2PI-024 | D1 negative table records `m_drawColor` as surrounding state; the generated UID0002PI block contains zero occurrences. |
| C2PI-025 | D1 negative table records `m_alpha` as surrounding state; the generated UID0002PI block contains zero occurrences. |
| C2PI-026 | D1 negative table records `m_palette` as unused; the generated UID0002PI block contains zero occurrences. |
| C2PI-027 | D1 and generated target each contain one `static_cast<unsigned char>(colorIndex)` direct-write expression. |
| C2PI-028 | D1 and generated target preserve `drawMode == 1 && colorIndex == 0`, testing the full input before low-byte write. |
| C2PI-029 | D1 and generated target contain one exact `BlendRgb565Pixel(*pixel, mappedColor, 0x10)` call. |
| C2PI-030 | D1 and generated target preserve `drawMode == 3 && colorIndex == 0` before the fixed blend. |
| C2PI-031 | D1/D6 calculate pointers only inside write branches; generated default branches contain no address calculation. |
| C2PI-032 | Both formal bodies compute `mappedColor` before reading/switching on `drawMode`, matching instruction order. |
| C2PI-033 | Canonical mapped-color direct writes are explicitly rejected in D1; generated direct writes use only input low byte. |
| C2PI-034 | Variable-alpha blending is explicitly rejected in D1; generated target uses literal `0x10` and no `m_alpha`. |
| C2PI-035 | D1 current managed block emits one file-local `static void __thiscall SoftwareRenderRgb565PixelCallback`. |
| C2PI-036 | D4 current managed block emits one `SurfaceDrawPixelProc g_pfnDrawPixel`; D5 remains blank and nonduplicating. |
| C2PI-037 | D1-D5 consistently retain Surface UID0000OC source ownership/emission and GrafPort receiver dependency. |
| C2PI-038 | D1/D3 reject GrafPort method ownership; generated output has zero `GrafPort::SoftwareRender` qualification. |
| C2PI-039 | D4 emits the declaration; D5 documents zero-initialized storage with blank C++; generated has zero UID0001PI marker. |
| C2PI-040 | D1-D3 keep SoftwareBlend16 as helper owner only; UID0002PI remains emitted through Surface. |
| C2PI-041 | D1-D3 historicalize Ranking ownership and retain rain pages as consumers; generated target has zero Ranking qualification. |
| C2PI-042 | D1 emitter position remains blank and final generated source order is stable. |
| C2PI-043 | D4 position is exactly 20; generated UID0000TN declaration precedes compat and RGB565 bodies and UID00039V. |
| C2PI-044 | D1 header is exactly `COMPLETION:92` / `CONFIDENCE:94`; command `000000014269` recorded both metadata updates. |
| C2PI-045 | D1 managed block text equals accepted Destination 1 and generated target block matches it once. |
| C2PI-046 | D6 managed block text equals accepted Destination 6, uses `rowStridePixels`, and defers pointer calculation to write branches. |
| C2PI-047 | D2 remains `90/92`, owner NONE, false, blank emitter/position/formal, `Nested:0`; only UID0002PI/backlog/history was synchronized. |
| C2PI-048 | D3 remains `88/85` at `NexusTK/render/` and contains the full accepted slot-0 source closure without unrelated route changes. |
| C2PI-049 | D4 remains `89/86`, UID0000OC owner/emitter, true, with position 20 and one bounded slot-0 formal; all other slots remain. |
| C2PI-050 | D5 remains `89/88`, UID0000TN owner/emitter, true, blank position/formal, `Nested:0`, with exact slot-0 storage/liveness prose. |
| C2PI-051 | D7 contains the exact successor alignment and no target split/new child was created. |
| C2PI-052 | Historical command `000000014262` had the target empty marker; B001 waited command `000000014303` replaced it, and terminal-readback external command `000000014335` still has one definition and zero target empty markers. |
| C2PI-053 | Current manual rows remain stale/absent; exact supervisor-owned replacement/insertion text below is unchanged and B001 edited no coverage file. |
| C2PI-054 | Active/executed/older/special search results and no-direct-prior-report conclusion remain unchanged. |
| C2PI-055 | Changed-file inventory contains no rename, new UID/file, table split, import, or IDA mutation. |
| C2PI-056 | D1 compiler boundary preserves cookie/register/epilogue/alignment exclusions; generated target contains no cookie or explicit padding. |
| C2PI-057 | D1 preserves unique 45-byte exact-signature and peer wildcard-collision evidence. |
| C2PI-058 | All D1-D7 evidence-time and callback-complete hashes are recorded; every destination was reread immediately before lease/edit. |
| C2PI-059 | Historical report-only no-validator state is phase-qualified; callback commands `14269`, `14271`, `14273`, `14278`, `14287`, `14296`, `14302`, and waited `14303` are recorded below. |
| C2PI-060 | Shared lease report shows no B001 lease; B001 ran no execute/lifecycle/probe/count/move/archive command and performed no manual/generated/IDA edit. |

## Positive Evidence Summary

- Target bytes, range, body hash, successor padding, function object, complete
  disassembly, complete decompile, CFG, and PE mapping all agree.
- ABI is independently supported by target epilogue, caller argument order,
  compat peer, callback-table docs, and initializer assignment.
- The target and compat peer have identical size, instruction count, block
  count, mode structure, field offsets, clip/palette routes, and direct-write
  behavior. Their only semantic backend difference is the RGB555 versus RGB565
  blend helper.
- All fifteen callback-slot refs are classified. There are no unexplained slot
  users or unknown direct callers.
- Current GrafPort/EPFTileContext docs resolve every accessed field and
  distinguish surrounding but unused `m_drawColor`/`m_alpha`.
- Current PaletteLib/DLPalette docs resolve both helper calls and the >255 map
  behavior.
- Current BlendRgb565Pixel formal resolves argument direction and fixed-weight
  meaning.
- Current Surface/initializer/table docs resolve owner, emitter, target pair,
  source file, and global name.
- Current generated output proves the route is live and the only target output
  blocker is blank formal C++.

## IDA MCP Facts

- Session: `64c11373`; worker PID `21508`; status ok.
- Function: `sub_4C0770`, start `0x004c0770`, size `0xd5`, end
  `0x004c0845`.
- Successor: `sub_4C0850`, start `0x004c0850`, size `0x72a`.
- Profile: 84 instructions, 11 basic blocks, complexity 8, no strings,
  no ordinary callers.
- Prototype direction: `void __thiscall(int this, int, int, unsigned int)`.
- Exact source-relevant callees:
  `0x004b96c0`, `0x004b7e80`, `0x00543d40`, `0x00542ac0`,
  `0x004c6050`; compiler-only cookie check `0x005c772f`.
- `func_profile` reports callee count 7 because its returned callee list
  includes the target itself. Disassembly/analyze_function show six external
  call targets including the cookie; this is a presentation quirk, not an
  extra recursive call.
- Target refs:
  - `0x00558833`, data, raw initializer target load;
  - `0x00558e9c`, data, inside `sub_558840`.
- End refs: none to `0x004c0845`.
- Slot `0x0069b3e0`: fifteen refs, exactly three setup/storage and twelve
  dispatch refs.
- No vtable, export, string, exception, local table, or direct feature-call
  route exists.
- Unique exact signature:
  `55 8B EC 83 EC 18 A1 24 2F 67 00 33 C5 89 45 FC 53 8B 5D 08 56 8B 75 0C 57 8B F9 89 5D E8 80 7F 71 00 74 5A 8D 45 EC 50 E8 23 8F FF FF`.
- Wildcarded operand signature did not become unique within the 213-byte
  target because the compat peer shares the same compiled control-flow
  template.

## Exact Bytes And Hash

- Section: `.text`.
- RVA: `0x000c0770`.
- Raw file offset: `0x000bfb70`.
- Length: `0xd5` / 213 bytes, verified with `tools/int_convert.py`.
- SHA256:
  `3562BA86A71E5D553D9394A5A511D10C9EABA6D73EE31623091BA8D25D720735`.

```text
0x004c0770: 55 8b ec 83 ec 18 a1 24 2f 67 00 33 c5 89 45 fc
0x004c0780: 53 8b 5d 08 56 8b 75 0c 57 8b f9 89 5d e8 80 7f
0x004c0790: 71 00 74 5a 8d 45 ec 50 e8 23 8f ff ff 8d 45 ec
0x004c07a0: 50 53 56 e8 d8 76 ff ff 83 c4 0c 84 c0 74 3f 8b
0x004c07b0: 5d 10 8b 0d e0 a7 67 00 53 e8 82 35 08 00 8b c8
0x004c07c0: e8 fb 22 08 00 0f b7 c8 8a 47 70 84 c0 74 08 3c
0x004c07d0: 01 75 2e 85 db 74 17 2b 77 30 0f af 77 28 8b 47
0x004c07e0: 20 0f b6 cb 2b 77 2c 03 75 e8 66 89 0c 70 5f 5e
0x004c07f0: 5b 8b 4d fc 33 cd e8 34 6f 10 00 8b e5 5d c2 0c
0x004c0800: 00 3c 02 74 08 3c 03 75 e5 85 db 74 e1 2b 77 30
0x004c0810: 0f af 77 28 8b 47 20 6a 10 51 2b 77 2c 03 75 e8
0x004c0820: 8d 34 70 0f b7 06 50 e8 24 58 00 00 8b 4d fc 83
0x004c0830: c4 0c 66 89 06 33 cd 5f 5e 5b e8 f0 6e 10 00 8b
0x004c0840: e5 5d c2 0c 00
```

- Successor alignment `[0x004c0845,0x004c0850)` is eleven `cc` bytes.
- Successor alignment SHA256:
  `3682C0A62515050101266CC639BF81F5D8C5395F49E7DA93FCC22603018E0943`.
- MCP bytes and mapped-PE bytes produce identical hashes.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004c0710-0x004c076d` | UID00016K BlendRgb555 | predecessor RGB555 math helper | true | UID0000NT | `90/92` | already source-ready |
| `0x004c076d-0x004c0770` | UID0000VN ignored | predecessor alignment | no | none | `100` | already present |
| `0x004c0770-0x004c0845` | UID0002PI target | RGB565 slot-0 pixel callback | true | UID0000OC | current `92/94` | source-ready body implemented and validated |
| `0x004c0845-0x004c0850` | UID0000VN ignored | successor alignment | no | none | `100` | exact ignored row implemented and validated |
| `0x004c0850-0x004c0f7a` | UID0002PJ | RGB565 line callback successor | true | UID0000OC | `87/89` | separate target |
| `0x004c6050-0x004c60c7` | UID00016M | RGB565 one-pixel blend dependency | true | UID0000NT | `90/92` | already source-ready |
| `0x0069b3e0-0x0069b3e4` | UID0001PI within table | zero-initialized slot-0 global storage | true | UID0000TN | table `89/88` | source declaration on UID0000TN |
| `0x00558690-0x0055883d` | UID00039V | out-of-line callback initializer | true | UID0000OC | `90/92` | already source-ready |
| `0x00558840-0x00558f63` | UID00039W | live host containing inline initializer copy | false/non-emitting | UID0000OC research | current | liveness support |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00558833` | target data ref | raw UID00039V loads RGB565 target address |
| `0x00558e9c` | target data ref in `sub_558840` | live inline setup stores target into slot 0 |
| `0x0055875f` | slot storage ref | raw initializer shared write to `0x0069b3e0` |
| `0x00558b80` | slot storage ref | live inline compat assignment |
| `0x00558e9c` | slot storage ref | live inline RGB565 assignment |
| `0x005c15d4`, `0x005c1641` | UID0003PJ calls | two small-splash pixels |
| `0x005c16b4`, `0x005c171e`, `0x005c178b`, `0x005c17f8` | UID0003PJ calls | four large-splash pixels |
| `0x005c1977`, `0x005c19e7` | UID0003PK calls | two target-view small-splash pixels |
| `0x005c1a61`, `0x005c1acc`, `0x005c1b3a`, `0x005c1ba8` | UID0003PK calls | four target-view large-splash pixels |
| `0x004b96c0` | callee | GrafPort effective clip rectangle |
| `0x004b7e80` | callee | half-open point-in-rectangle test |
| `0x00543d40` | callee | PaletteLib current palette |
| `0x00542ac0` | callee | DLPalette index-to-packed-color map |
| `0x004c6050` | callee | fixed-weight RGB565 pixel blend |
| `0x005c772f` | compiler callee | security-cookie check, no source call |

## Callback Dispatch And Mode Taxonomy

| Mode | Source-facing role | Zero-color behavior | Written value |
| ---: | --- | --- | --- |
| `0` | pixel copy/direct | not gated | low eight bits of full color index, zero-extended |
| `1` | color-keyed pixel copy/direct | full color index zero skips write | same low-byte direct value |
| `2` | fixed half blend | not gated | `BlendRgb565Pixel(existing, mapped, 16)` |
| `3` | color-keyed fixed half blend | full color index zero skips write | same fixed blend |
| other | unsupported/no-op | no write | none |

- Mapping is performed for all clipped calls before the mode branch.
- Direct modes do not use the mapped result.
- Blend modes do not use `m_alpha`; their fixed existing-pixel weight is 16 of
  32.
- Color-key tests use the full 32-bit argument, not the truncated low byte or
  mapped packed pixel.

## Receiver Field And Type Resolution

| Offset | Accepted source field/type | Target use | Disposition |
| ---: | --- | --- | --- |
| `+0x20` | `void *m_surfaceContext.pixelData` | 16-bit destination base | direct read |
| `+0x28` | `int m_surfaceContext.rowStridePixels` | row multiplier in pixels | direct read |
| `+0x2c` | `int m_surfaceContext.bounds.left` | horizontal origin subtraction | direct read |
| `+0x30` | `int m_surfaceContext.bounds.top` | vertical origin subtraction | direct read |
| `+0x70` | `unsigned char m_drawMode` | mode 0 through 3 dispatch | direct read |
| `+0x71` | `bool m_drawEnabled` | first early-exit guard | direct read |
| `+0x74` | `unsigned int m_drawColor` | active GrafPort color for other paths | not read here |
| `+0x84` | borrowed `DLPalette *m_palette` | per-port palette for other paths | not read here |
| `+0x90` | `float m_alpha` | variable blend weight for other paths | not read here |

- `m_surfaceContext` begins at outer offset `+0x1c`.
- `rowStridePixels` is the current accepted project name. Historical generic
  `rowStride` survives only in stale compat formal text and older history.
- Target code should not introduce offset comments, raw field numbers, or
  reverse-engineering names.

## Documentation Evidence And IDA Status

- Current target documentation is complete on range, table role, Surface owner,
  no direct callers, helper set, exact fields, callback typedef, caller
  inventory, direct low-byte behavior, palette timing, negative fields, modes,
  compiler boundary, and complete C++.
- UID0002PF is the accepted ABI/CFG peer and now uses
  `m_surfaceContext.rowStridePixels` with branch-local pointer calculation.
- UID00016L remains correctly non-emitting at `90/92`; its target row and split
  backlog now classify UID0002PI as source-ready.
- UID0000TN and UID0001PI identify slot 0 and the two targets. UID0000TN now
  owns the exact bounded typedef/global formal at position 20; UID0001PI
  remains blank fixed-storage documentation without duplicate source.
- UID00039V already uses both source-facing target names in formal C++ and
  requires no body change.
- GrafPort class/file, EPFTileContext, GetClipRect, RectGeometryHelpers,
  PaletteLib, DLPalette, and BlendRgb565Pixel already carry same-or-greater
  support facts and require no ordinary edit in this bounded callback.
- UID0003PJ and UID0003PK identify the two Raining methods and their roles.
  Target-level caller inventory can record their twelve exact slot calls
  without changing those otherwise unrelated method pages.
- Generated Surface output is validator-owned and mutable. The terminal
  callback readback is external command `000000014335`, SHA256
  `3A8EF215DBBB8B9307B20919BFE26E67A73B2B308212CF0CD3569D14205C57FE`,
  24,026 bytes, and 675 physical lines. B001 did not edit it; the authorized
  waited validator command `000000014303` first refreshed it and the later
  external header refresh preserved every target-specific assertion.

## Ranked Ownership Analysis

### 1. UID0000OC Surface

- Evidence for: both target-address refs come from Surface callback setup;
  UID00039V and the live inline copy select compat versus RGB565 target pairs;
  no ordinary direct caller exists; slot storage is process-wide render
  infrastructure; current generated route is `NexusTK/render/Surface.cpp`.
- Evidence against: `Surface.cpp` remains a broad reconstructed source bucket
  rather than source-path-string proof of the exact original filename.
- Decision: accepted direct semantic owner and emitter. The remaining filename
  breadth is a score cap, not an owner blocker.

### 2. UID00005V GrafPort

- Evidence for: ECX is a GrafPort receiver; every object field belongs to
  GrafPort/embedded EPFTileContext; the target calls GrafPort::GetClipRect.
- Evidence against: there is no member/vtable/direct-call route; two backend
  implementations are selected through one process-wide function-pointer
  global; target names and neighboring callback families are Surface render
  implementations.
- Decision: receiver/layout dependency only, not direct owner.

### 3. UID0000TN / UID0001PI SurfaceRenderCallbackTable

- Evidence for: owns the typed global symbol/storage and all dispatch refs.
- Evidence against: storage pages do not own the selected target body, and
  handwritten table-body C++ would duplicate the exact callback child.
- Decision: source declaration/storage support. UID0000TN gets the slot-0 type
  and global; UID0001PI remains blank formal storage evidence.

### 4. UID0000NT SoftwareBlend16

- Evidence for: owns `BlendRgb565Pixel` and neighboring packed-pixel math.
- Evidence against: UID0002PI is installed as a stateful GrafPort callback,
  calls clip/palette helpers, and has twelve indirect dispatch uses.
- Decision: math dependency only.

### 5. RankingEventListPane / RainingLayerPane

- Evidence for: older generated owner pollution used Ranking names; all live
  dynamic dispatches occur in two Raining methods.
- Evidence against: Ranking has no binary ownership route; Raining calls the
  global slot and owns no target address/global setup.
- Decision: reject Ranking ownership as stale and Raining ownership as
  consumer-biased.

### Proposed new file/grouping, if applicable

- Proposed owner/name/path: not applicable. Keep current Surface route.
- A narrower future callback source unit is not justified by source-path or
  object-file evidence and is outside this target pass.

## Source Placement

- Recommended source file: `NexusTK/render/Surface.cpp` through UID0000OC.
- Recommended source shape: file-local callback implementation plus a typed
  process-wide slot global declared/defined before callback initialization.
- Recommended target linkage: `static`, because only same-source initializer
  code takes the function address and there is no export/direct external route.
- Recommended slot global linkage: external module global, because broad code
  in other source families dispatches through `g_pfnDrawPixel`.
- Target emitter position: blank, preserving current address/scan ordering
  among unpositioned Surface callbacks.
- Slot-global emitter position: `20`, after current positions 9 and 10 for
  format/lookup globals and before positions 100 through 105 and unpositioned
  callback definitions.
- Rejected placements:
  GrafPort.cpp member method, SoftwareBlend16.cpp helper, RainingLayerPane.cpp,
  RankingDialog.cpp, callback-memory handwritten body, and a new one-target
  source file.

## Range / Split / Padding / Reclassification Analysis

- Exact target is one modeled function; no internal table, embedded data,
  second entry point, thunk, cold child, or split candidate exists.
- Predecessor:
  UID00016K ends at `0x004c076d`; the existing ignored interval
  `[0x004c076d,0x004c0770)` is three `cc` bytes.
- Successor:
  UID0002PJ begins at `0x004c0850`; `[0x004c0845,0x004c0850)` is eleven
  `cc` bytes and should be added to `by-memory/-ignored.md`.
- The eleven-byte padding hash is
  `3682C0A62515050101266CC639BF81F5D8C5395F49E7DA93FCC22603018E0943`.
- UID00016L remains an address-family index over twelve exact children and
  must stay non-emitting.
- No rename, range correction, new child, new UID, new parent, or aggregate
  C++ is recommended.

## Negative Evidence Summary

- No ordinary call targets `0x004c0770`.
- No xref targets exclusive end `0x004c0845`.
- No vtable cell, export, registration, RTTI, string, or feature singleton
  references the target address.
- No instruction reads receiver `+0x74`, `+0x84`, or `+0x90`.
- No instruction uses `m_drawColor` as an implicit pixel value.
- No instruction converts `m_alpha` to a blend weight.
- No per-port palette pointer fallback exists.
- Direct paths do not write the palette-mapped RGB565 value.
- Default modes do not calculate a destination address.
- Target does not own or index the callback table.
- Target does not contain handwritten padding, a jump table, EH source, or a
  source-level security-cookie call.
- The decompiler's residual `int` result in Raining methods is not evidence of
  a non-void callback.
- Generated Ranking ownership and old broad no-code text are not current
  binary/source-placement evidence.

## Historical / Superseded Assumptions

- Historical aggregate state below the assignment gate is superseded by
  current UID00016L `90/92`, Surface routing, and exact target research.
- Historical target text saying callback typedef, fields, mode taxonomy,
  palette names, and source routing remain open is superseded.
- Historical B005 whole-Surface decision to keep UID0000TN formal blank was
  correct for an unresolved all-slot pass; it is superseded only for the now
  fully resolved slot-0 declaration.
- Historical compat `rowStride` spelling is superseded by accepted
  `rowStridePixels`.
- Historical suspicion that `+0x74` and `+0x90` might be direct target inputs
  is disproved by the complete target disassembly.
- Historical generated `RankingEventListPane::PutPixel_565` is retained only
  as provenance for caller-biased output pollution.
- Historical direct-C++ blank state is retained only as marker-cause history,
  not as a current recommendation.

## IDA Rename / Type / Comment Recommendations

- Source-facing function name: `SoftwareRenderRgb565PixelCallback`.
- Source-facing callback typedef: `SurfaceDrawPixelProc`.
- Source-facing global: `g_pfnDrawPixel`.
- Source-facing receiver and parameters:
  `GrafPort *port`, `int x`, `int y`, `unsigned int colorIndex`.
- Source-facing fields:
  `m_surfaceContext.pixelData`, `m_surfaceContext.rowStridePixels`,
  `m_surfaceContext.bounds.left`, `m_surfaceContext.bounds.top`,
  `m_drawMode`, `m_drawEnabled`, with negative documentation for
  `m_drawColor`, `m_palette`, and `m_alpha`.
- Source-facing helper names:
  `GetClipRect`, `PointInRect`, `GetCurrentPalette`, `MapColor`,
  `BlendRgb565Pixel`.
- Mode labels for prose/review:
  pixel copy, color-keyed pixel copy, fixed half blend, and color-keyed fixed
  half blend.
- IDA DB mutation is not requested and is forbidden in this assignment.
  `sub_4C0770` and raw names remain evidence labels only.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes. Exact behavior, ABI, fields, helper contracts,
  owner/emitter, source order, and boundaries are resolved.
- Exactly three complete managed blocks were accepted and are present at their
  destination pages. No other example,
  declaration, or body-only C++ is part of this report.

Destination 1:
`by-memory/0x004c0770-0x004c0845.SoftwareRenderRgb565PixelCallback.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
static void __thiscall SoftwareRenderRgb565PixelCallback(
    GrafPort *port,
    int x,
    int y,
    unsigned int colorIndex)
{
    if (!port->m_drawEnabled) {
        return;
    }

    RectBounds clipRect;
    port->GetClipRect(&clipRect);
    if (!PointInRect(y, x, &clipRect)) {
        return;
    }

    DLPalette *palette = g_pPaletteLib->GetCurrentPalette();
    const unsigned short mappedColor = palette->MapColor(colorIndex);
    const unsigned char drawMode = port->m_drawMode;

    switch (drawMode) {
    case 0:
    case 1: {
        if (drawMode == 1 && colorIndex == 0) {
            return;
        }

        unsigned short *pixel =
            static_cast<unsigned short *>(port->m_surfaceContext.pixelData) +
            (y - port->m_surfaceContext.bounds.top) *
                port->m_surfaceContext.rowStridePixels +
            (x - port->m_surfaceContext.bounds.left);

        *pixel = static_cast<unsigned short>(
            static_cast<unsigned char>(colorIndex));
        break;
    }

    case 2:
    case 3: {
        if (drawMode == 3 && colorIndex == 0) {
            return;
        }

        unsigned short *pixel =
            static_cast<unsigned short *>(port->m_surfaceContext.pixelData) +
            (y - port->m_surfaceContext.bounds.top) *
                port->m_surfaceContext.rowStridePixels +
            (x - port->m_surfaceContext.bounds.left);

        *pixel = BlendRgb565Pixel(*pixel, mappedColor, 0x10);
        break;
    }

    default:
        break;
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination 4:
`by-global/SurfaceRenderCallbackTable.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class GrafPort;

typedef void (__thiscall *SurfaceDrawPixelProc)(
    GrafPort *port,
    int x,
    int y,
    unsigned int colorIndex);

SurfaceDrawPixelProc g_pfnDrawPixel;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination 6:
`by-memory/0x004bb8d0-0x004bb9a5.SoftwareRenderCompatPixelCallback.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
static void __thiscall SoftwareRenderCompatPixelCallback(
    GrafPort *port,
    int x,
    int y,
    unsigned int colorIndex)
{
    if (!port->m_drawEnabled) {
        return;
    }

    RectBounds clipRect;
    port->GetClipRect(&clipRect);
    if (!PointInRect(y, x, &clipRect)) {
        return;
    }

    DLPalette *palette = g_pPaletteLib->GetCurrentPalette();
    const unsigned short mappedColor = palette->MapColor(colorIndex);
    const unsigned char drawMode = port->m_drawMode;

    switch (drawMode) {
    case 0:
    case 1: {
        if (drawMode == 1 && colorIndex == 0) {
            return;
        }

        unsigned short *pixel =
            static_cast<unsigned short *>(port->m_surfaceContext.pixelData) +
            (y - port->m_surfaceContext.bounds.top) *
                port->m_surfaceContext.rowStridePixels +
            (x - port->m_surfaceContext.bounds.left);

        *pixel = static_cast<unsigned short>(
            static_cast<unsigned char>(colorIndex));
        break;
    }

    case 2:
    case 3: {
        if (drawMode == 3 && colorIndex == 0) {
            return;
        }

        unsigned short *pixel =
            static_cast<unsigned short *>(port->m_surfaceContext.pixelData) +
            (y - port->m_surfaceContext.bounds.top) *
                port->m_surfaceContext.rowStridePixels +
            (x - port->m_surfaceContext.bounds.left);

        *pixel = BlendRgb555(*pixel, mappedColor, 0x10);
        break;
    }

    default:
        break;
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Behavior preservation:
  palette mapping remains before mode dispatch; color-key checks use the full
  input; direct writes use only the low byte; unknown modes perform no pointer
  calculation; blend argument order and fixed weight remain exact.
- Source-era fit:
  plain C++03 syntax, explicit early returns, `NULL`-era project types, no
  templates/lambdas/RAII scaffolding, accepted MSVC calling convention, and
  source-facing project names.
- Compiler-only exclusions:
  security-cookie load/check, saved registers, exact block scheduling, duplicate
  epilogues, raw relative calls, and alignment bytes.

## Final Recommendation

- Applied target state is `92/94`, UID0000OC owner/emitter, true, blank target
  position, `Nested:4`, exact path/title, and exact Destination 1.
- Applied UID0000TN state includes the bounded slot-0 formal and
  `EMITTER_POSITION_OPTIONAL:20`; `89/86`, owner/emitter UID0000OC, and
  reconstructable true are preserved.
- Applied compat Destination 6 preserves `88/91`, owner/emitter,
  reconstructable, blank position, range, title, and `Nested:4`.
- UID00016L, Surface, UID0000TN, and UID0001PI prose now contains the full
  accepted union without dropping unrelated callback-family facts.
- Only the exact successor alignment was added to `by-memory/-ignored.md`.
- UID00039V, GrafPort class/file, EPFTileContext, palette helpers, clip helpers,
  blend helper, and Raining methods were verified unchanged at
  same-or-greater detail.
- No target split, rename, new child, new source file, IDA edit, generated
  manual edit, coverage edit, or lifecycle action was performed by B001.

## Recommended Target Doc Changes

- Target path:
  `by-memory/0x004c0770-0x004c0845.SoftwareRenderRgb565PixelCallback.md`.
- Applied metadata:
  `COMPLETION:92`, `CONFIDENCE:94`; preserve owner UID0000OC,
  reconstructable true, emitter UID0000OC, blank position, `Nested:4`.
- Applied formal:
  Destination 1 exactly.
- Current summary/status now contains:
  exact bytes/hash/section/raw offset, ABI, CFG, xrefs, caller/callee inventory,
  fields/types, palette and clipping routes, full mode taxonomy, fixed blend,
  low-byte direct behavior, compiler exclusions, source placement, score
  rationale, and generated marker cause.
- Preserved and historicalized:
  valid older range/table/peer/owner evidence, old blank-C++ state, and
  superseded unresolved field/typedef/mode claims with rejection reasons.
- The target now has an explicit negative field table for `+0x74`, `+0x84`,
  and `+0x90`.
- Exact Raining dispatch inventory is present without assigning ownership to the
  callers.

## Recommended Support Doc Changes

1. Destination 2:
   `by-memory/0x004c0770-0x004c5fde.SoftwareRenderRgb565Callbacks.md`
   - Keep `90/92`, NONE/FALSE, blank emitter/position/formal, `Nested:0`.
   - Applied UID0002PI row is `92/94`, source-ready formal status,
     resolved slot-0 ABI/fields/modes, and exact successor padding.
   - Only UID0002PI split-backlog wording changed; all other child
     evidence and aggregate no-emission.

2. Destination 3:
   `by-file/Surface.md`
   - Keep `88/85` and current path.
   - UID0002PI Surface inventory row now records the exact source-ready slot-0
     body.
   - Slot-0 type/global source order and the compat peer stride/control
     correction.
   - Preserve the full current cross-family Surface union and all unrelated
     source-boundary caveats.

3. Destination 4:
   `by-global/SurfaceRenderCallbackTable.md`
   - Keep `89/86`, UID0000OC owner/emitter, reconstructable true.
   - Position is `20`.
   - Destination 4 is present exactly.
   - Slot 0 now has exact typedef, both file-local targets, explicit receiver
     and arguments, source return void, and complete direct/blend behavior.
   - State that only slot 0 is formally emitted in this bounded pass; remaining
     slot typedefs retain their existing independent status.

4. Destination 5:
   `by-memory/0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable.md`
   - Keep `89/88`, UID0000TN owner/emitter, reconstructable true, blank
     position/formal, `Nested:0`.
   - Slot-0 storage and setup/dispatch facts, source-ready target state,
     exact type name, and no-duplicate-body boundary.

5. Destination 6:
   `by-memory/0x004bb8d0-0x004bb9a5.SoftwareRenderCompatPixelCallback.md`
   - Keep `88/91` and all metadata.
   - Destination 6 is present exactly.
   - `rowStridePixels` replaces stale `rowStride`.
   - The eager pointer calculation is historicalized and exact
     write-branch-local/default-no-address behavior.

6. Destination 7:
   `by-memory/-ignored.md`
   - `[0x004c0845,0x004c0850)` is present as eleven `0xcc` alignment bytes between
     UID0002PI and UID0002PJ.
   - Preserve predecessor and every unrelated ignored interval.

7. Verify-only dependencies:
   - UID00039V initializer.
   - GrafPort class/file/aggregate.
   - EPFTileContext class.
   - GetClipRect and RectGeometryHelpers.
   - PaletteLib, DLPaletteMapColor, and g_pPaletteLib.
   - BlendRgb565Pixel.
   - UID0003PJ and UID0003PK Raining caller pages.
   - Readback found no contradiction; all remain unchanged with
     already-present proof recorded above.

## Score And Metadata Recommendation

- Historical pre-callback target: `87/89`, owner/emitter UID0000OC, true,
  blank position/C++, `Nested:4`.
- Current target: `92/94`, same owner/emitter/reconstructable/position/nesting,
  populated formal.
- Completion rationale:
  exact function/boundaries, bytes/hash, section/raw offset, complete
  instructions/CFG, ABI, all target and slot xrefs, all dynamic dispatchers,
  all callees, fields, palette route, four modes, negative paths, owner,
  emitter, source placement, formal body, compiler boundary, history, support
  plan, manual handoff, and generated expectations are closed.
- Confidence rationale:
  independent MCP/PE hashes and current docs agree. Original lexical spelling,
  static linkage, and exact original header organization remain inferred, so
  95+ is not justified.
- Score-improvement attempt:
  - callback typedef blocker: resolved to `SurfaceDrawPixelProc`;
  - receiver blocker: resolved to GrafPort;
  - x/y/color blocker: resolved through helper/caller order;
  - field blocker: all six direct fields and three negative surrounding fields
    resolved;
  - mode blocker: all four modes/default resolved;
  - palette blocker: exact global-current route resolved;
  - alpha blocker: proved unused and fixed weight resolved;
  - liveness blocker: all two target refs and twelve dispatches resolved;
  - source placement blocker: Surface/file-local callback resolved;
  - generated marker blocker: blank formal identified;
  - padding blocker: exact missing successor row resolved;
  - direct-write anomaly: preserved rather than normalized.
- Support metadata:
  UID0000TN position becomes 20; all support scores and other metadata remain
  unchanged.

## Open Questions With Attempted Resolution

| Question | Evidence checked | Resolution | Score/C++ impact |
| --- | --- | --- | --- |
| Is the receiver Surface or GrafPort? | field offsets, GetClipRect, callers, initializer | GrafPort receiver; Surface source owner | closed |
| Is the callback a GrafPort member? | no direct/vtable route, paired global selection | no; file-local receiver callback | closed |
| What is the return type? | epilogue, no return construction, ignored caller results | source `void` | closed |
| What are stack args? | register loads, PointInRect order, caller pushes | x, y, unsigned colorIndex | closed |
| What is `+0x28`? | current EPFTileContext/GrafPort docs and address math | `int rowStridePixels` | closed |
| Are `+0x74/+0x90` read? | complete 84-instruction scan | no; surrounding state only | closed |
| Does target use per-port palette? | complete offset/callee scan | no; global current palette only | closed |
| Are direct writes mapped RGB565? | exact `movzx ecx,bl` | no; low-byte direct word | closed |
| Does mode 1/3 gate truncated/mapped color? | `test ebx,ebx` | full 32-bit input | closed |
| Is blend alpha variable? | immediate 16, no +0x90 read | fixed 50/50 | closed |
| What should typedef be called? | current `Surface*Proc` conventions and global name | descriptive `SurfaceDrawPixelProc` | lexical cap only |
| Should target be static? | only same-source address refs, no export/direct route | highest-probability file-local static | lexical/linkage cap only |
| Should callback table be a struct? | all fixed absolute accesses, no base/index | no; independent typed globals | closed |
| Should target be split? | exact function/end/padding/CFG | no | closed |
| Is a new source file justified? | no source path/object boundary proof, current route | no; retain Surface.cpp | closed |
| Is IDA mutation needed? | all report requirements satisfied read-only | no and forbidden | none |

No assigned behavioral, ownership, field, type, mode, helper, source-placement,
score, or final-C++ blocker remains deferred.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Manual files inspected read-only:
  - `by-memory/-coverage-report.md`, current evidence-time SHA256
    `28519EC29A329E50F26567E5AD845231716C33BA64B3B6C5F3856C635BE35CAB`;
  - `by-class/-coverage-report.md`, current evidence-time SHA256
    `37519F59619A71953B1019D6175D96F19159B039CFA60763393B8DEBE918AE45`;
  - `by-file/-coverage-report.md`, current evidence-time SHA256
    `28DD34838534E65F5AABA8A4E147754C5B37AB08A04C99BBFC0888F252127672`;
  - `by-global/-coverage-report.md`, current evidence-time SHA256
    `CA6748C2ED56235F95727DFE7C000B30B03213EF42D1F9A93BF796B550A5DB32`.
- By-class GrafPort row was inspected and needs no replacement because this
  report proposes no class metadata/formal/score change.
- Callback-time reread confirms the affected UID00016L, UID0002PI,
  UID0002PF, UID0001PI, UID0000TN, and UID0000OC rows remain stale and the
  successor-padding row remains absent. The exact handoff text below therefore
  remains current and was not edited into any manual file by B001.
- Later concurrent coverage additions advanced the by-memory/by-class/by-file
  hashes and added unrelated rows/content. Exact readback of every row in this
  callback's bounded handoff shows no affected-row change; by-global stayed
  byte-identical. These external additions do not alter the replacement/
  insertion text below.
- Exact supervisor replacement for current UID00016L row:

```text
    - [UID:00016L][0x004c0770-0x004c5fde.SoftwareRenderRgb565Callbacks](by-memory/0x004c0770-0x004c5fde.SoftwareRenderRgb565Callbacks.md) 0x004c0770-0x004c5fde | function-family | SoftwareRenderRgb565Callbacks : not reconstructable : 90% : very strong : Non-emitting RGB565 callback-family index over twelve exact Surface-owned source children; UID0002PI is now a 92/94 source-ready slot-0 pixel callback with exact GrafPort/x/y/color ABI, low-byte direct modes, fixed RGB565 half-blend modes, complete fields/palette/clip evidence, and formal C++, while aggregate C++ remains blank and all unrelated child dispositions are preserved.
```

- Exact supervisor replacement for current UID0002PI row:

```text
        - [UID:0002PI][0x004c0770-0x004c0845.SoftwareRenderRgb565PixelCallback](by-memory/0x004c0770-0x004c0845.SoftwareRenderRgb565PixelCallback.md) 0x004c0770-0x004c0845 | function | SoftwareRenderRgb565PixelCallback : reconstructable : 92% : very strong : Exact 213-byte Surface-owned slot-0 RGB565 pixel callback with SHA256 3562BA86A71E5D553D9394A5A511D10C9EABA6D73EE31623091BA8D25D720735, GrafPort receiver plus x/y/colorIndex void ABI, complete clip/current-palette/MapColor route, low-byte direct and color-key modes, fixed 16-of-32 RGB565 blend and color-key blend modes, no direct use of m_drawColor/m_palette/m_alpha, two initializer refs, twelve rain dispatches, complete formal C++, and eleven-byte successor alignment.
```

- Exact supervisor insertion immediately after the UID0002PI row:

```text
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x004c0845-0x004c0850 | padding | SoftwareRenderRgb565PixelCallback to SoftwareRenderRgb565LineCallback alignment : ignored : 100% : strong : Eleven confirmed `0xcc` bytes after UID0002PI and before UID0002PJ; SHA256 3682C0A62515050101266CC639BF81F5D8C5395F49E7DA93FCC22603018E0943.
```

- Exact supervisor replacement for current UID0002PF row:

```text
        - [UID:0002PF][0x004bb8d0-0x004bb9a5.SoftwareRenderCompatPixelCallback](by-memory/0x004bb8d0-0x004bb9a5.SoftwareRenderCompatPixelCallback.md) 0x004bb8d0-0x004bb9a5 | function | SoftwareRenderCompatPixelCallback : reconstructable : 88% : very strong : Source-ready Surface slot-0 compat/RGB555 peer with the shared GrafPort/x/y/colorIndex void ABI, exact clipped low-byte direct/color-key and fixed RGB555 blend/color-key behavior, accepted rowStridePixels field, write-branch-local destination calculation, initializer/table xrefs, no direct callers, and complete formal C++.
```

- Exact supervisor replacement for current UID0001PI row:

```text
    - [UID:0001PI][0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable](by-memory/0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable.md) 0x0069b3e0-0x0069b410 | function-pointer table | SurfaceRenderCallbackTable : reconstructable : 89% : strong : Twelve zero-initialized declaration-ordered Surface render callback globals with complete paired setup and dispatch evidence; slot 0 is exact SurfaceDrawPixelProc/g_pfnDrawPixel over a GrafPort receiver plus int x, int y, unsigned colorIndex and void return, with source-ready compat/RGB555 UID0002PF and RGB565 UID0002PI targets, while raw storage remains nonduplicating blank formal evidence under UID0000TN.
```

- Exact supervisor replacement for current UID0000TN by-global row:

```text
- [UID:0000TN][SurfaceRenderCallbackTable](by-global/SurfaceRenderCallbackTable.md) : reconstructable : 89% : strong : Documentation/source owner for twelve fixed Surface render callback globals; slot 0 now has exact SurfaceDrawPixelProc and g_pfnDrawPixel source declaration at emitter position 20, paired source-ready compat UID0002PF and RGB565 UID0002PI targets, exact GrafPort/x/y/colorIndex void ABI and dispatch behavior, while remaining slot typedefs retain their current independent confidence limits.
```

- Exact supervisor replacement for current UID0000OC by-file row:

```text
- [UID:0000OC][Surface](by-file/Surface.md) : reconstructable : 88% : strong : `NexusTK/render/Surface.cpp` shared surface/render source route with typed slot-0 g_pfnDrawPixel storage, source-ready compat/RGB555 and RGB565 pixel callbacks, exact callback initializer selection, current format/lookup globals, existing callback-family implementations, DirectDraw presentation helpers, and preserved broader source-unit boundary caveats.
```

- Reason B001 must not apply these rows:
  every manual `-coverage-report.md` file is supervisor-owned. Validator-owned
  generated refresh does not apply or validate these manual rows.
- Tracker text:
  do not edit `auto-generated/-ag-research-tracker.md`; target metadata and
  formal C++ should drive validator-owned generated tracker state after an
  accepted callback.

## Follow-Up Actions

- Current B001 work: complete; no accepted implementation item remains.
- Report validation, manual coverage application, Gate 2, execution, count,
  path, move, and archive state are external supervisor/validator-owned state
  and are neither performed nor asserted by this artifact.
- A-agent actions: none.
- B001 lifecycle actions: none; no `execute_report`, probe/count, move, or
  archive command was run.

## Confidence

- Recommendation confidence: very strong.
- Binary/behavior confidence: very strong; exact MCP and PE evidence agree.
- ABI/type confidence: very strong for physical/source-semantic direction.
- Owner/emitter confidence: very strong for current Surface route.
- Lexical confidence: high but not original-symbol proof for
  `SoftwareRenderRgb565PixelCallback`, `SurfaceDrawPixelProc`, and static
  linkage.
- Score confidence: high for `92/94`; no unresolved behavioral blocker
  supports a lower target score, while stripped lexical/source-file proof
  prevents 95+.

## Validator Results

- Every changed ordinary page received one scoped validator. All commands ran
  from `source-3/project-documentation`, exited 0, and returned `ok:1`.

| Command ID | Timestamp | Scope | Result / relevant side effects |
| --- | --- | --- | --- |
| `000000014269` | `2026-07-16T15:45:04-04:00` | D1 UID0002PI | exit 0, `ok:1`; completion 92, confidence 94, formal registry blank-to-block, target hash refresh, UID0002PJ link insertion; existing missing-registry warnings for UID0003PJ/UID0003PK; generated deferred. |
| `000000014271` | `2026-07-16T15:45:58-04:00` | D6 UID0002PF | exit 0, `ok:1`; formal registry hash refresh; generated deferred. |
| `000000014273` | `2026-07-16T15:46:55-04:00` | D4 UID0000TN | exit 0, `ok:1`; position 20, formal blank-to-block, registry hash refresh; pre-existing UID0003XE warnings; generated deferred. |
| `000000014278` | `2026-07-16T15:47:33-04:00` | D5 UID0001PI | exit 0, `ok:1`; UID0002PI reference-index addition; pre-existing UID0003XE/UID0003PN warnings; generated deferred. |
| `000000014287` | `2026-07-16T15:48:26-04:00` | D2 UID00016L | exit 0, `ok:1`; no target-specific warning; generated deferred. |
| `000000014296` | `2026-07-16T15:49:48-04:00` | D3 Surface | exit 0, `ok:1`; UID0001PI reference-index addition; pre-existing missing-registry warnings in the broad Surface union; generated deferred. |
| `000000014302` | `2026-07-16T15:50:48-04:00` | D7 `-ignored.md` | exit 0, `ok:1`; UID0002PI/UID0002PJ reference-index additions; pre-existing broad ignored-page missing-registry warnings; generated deferred. |
| `000000014303` | `2026-07-16T15:51:05-04:00` | final D1 `--wait-generated` | exit 0, `ok:1`; generated refresh completed; validator registry rebuilt; generated metadata/tracker refreshed by validator-owned mechanisms. |

- Validator warnings are pre-existing registry/reference conditions on broad
  support pages or the two exact rain UIDs. The referenced rain pages exist,
  were read by path, and were not changed; B001 did not edit validator state.
- B001 generated checkpoint:
  `auto-generated/NexusTK/render/Surface.cpp`, command/header
  `000000014303`, refreshed `2026-07-16T15:51:05-04:00`, SHA256
  `3DD57EEB003205FFD993A9D47D289098F2AA90B881C8E99D0102D814050A1270`,
  24,026 bytes / 675 lines.
- Terminal-readback generated checkpoint after an external validator refresh:
  command/header `000000014335`, refreshed
  `2026-07-16T16:03:19-04:00`, SHA256
  `3A8EF215DBBB8B9307B20919BFE26E67A73B2B308212CF0CD3569D14205C57FE`,
  24,026 bytes / 675 lines. All assertions below were rerun against this
  current file and remain true; B001 does not claim command `000000014335`.
- Generated assertions:
  - one UID0002PI marker and one target definition;
  - zero UID0002PI Empty Emitter Markers;
  - one UID0000TN marker, one slot-0 declaration/definition block, and zero
    UID0000TN Empty Emitter Markers;
  - zero UID0001PI storage markers and zero UID00016L aggregate markers, so
    neither duplicates source;
  - one compat definition and one RGB565 definition;
  - one `SurfaceDrawPixelProc g_pfnDrawPixel` definition;
  - exactly two initializer assignments to `g_pfnDrawPixel`;
  - source order is UID0000TN declaration, UID0002PF compat, UID0002PI target,
    then UID00039V initializer;
  - target direct mode contains one low-byte input expression and does not use
    `mappedColor` for direct writes;
  - target contains one exact
    `BlendRgb565Pixel(*pixel, mappedColor, 0x10)` call;
  - target has two `rowStridePixels` references and compat uses the same field;
  - target block has zero `m_drawColor`, `m_palette`, or `m_alpha`;
  - target block has zero cookie, explicit padding, Ranking qualification,
    GrafPort member qualification, empty marker, or duplicate.

## Changed Files

- Updated report:
  `tools/leaser/Agents/Agent-B001/research/0002PI-SoftwareRenderRgb565PixelCallback-source-quality.md`.
- Modified ordinary files:
  - `by-memory/0x004c0770-0x004c0845.SoftwareRenderRgb565PixelCallback.md`
    SHA256 `BE677EA06337878F42D7729DE38018A5B6F6F2BE40C914281996E02088A8CBDB`;
  - `by-memory/0x004c0770-0x004c5fde.SoftwareRenderRgb565Callbacks.md`
    SHA256 `DC639271C6954882C1DE93BC02E27A08CA05982779FE36DBBB10D221D13EE99C`;
  - `by-file/Surface.md`
    SHA256 `DEACFBF623AA152451583F1BB98731C9D834117F7EC4A23544CE676F12713D3B`;
  - `by-global/SurfaceRenderCallbackTable.md`
    SHA256 `4F8C7C217E67AB9A4BA9CD9693D5D13A33DEC860A8276DEB7B789A8680AC3AC6`;
  - `by-memory/0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable.md`
    SHA256 `B48DEBFB8E66D64082894FAF9760D7855E683DBD2D7CE945CFFBBEEC13C9CB9A`;
  - `by-memory/0x004bb8d0-0x004bb9a5.SoftwareRenderCompatPixelCallback.md`
    SHA256 `B4EBCDE2C0CB38BB8249D5E22C3A7CF9FE2AA7CAE29A77FA870EA5E038522F9E`;
  - `by-memory/-ignored.md`
    SHA256 `C4875C9DB2BAEF070BE1E0EDFE9268918E93596311CA038F6195764F7D1BDFE9`.
- Renamed: none.
- Generated files were not edited by B001; B001 validator command
  `000000014303` refreshed generated output and later external command
  `000000014335` advanced validator-owned header provenance. Manual coverage,
  audit, supervisor, lifecycle, archive, and IDA files were not edited.
- IDA modified: no.
- Ordinary leases acquired serially for D1, D6, D4, D5, D2, D3, and D7; each
  was released immediately after its scoped validator. Final shared lease
  readback contains no B001 row.
- Report execution: not run.
- Report lifecycle/probe/count/move/archive commands: not run.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor validated exact report SHA
  `0206659D5ADB336A7331398FBDBE1AA4166EB661814A15E92D480FF9EAFAC9D3`.
- [x] D1 was reread immediately before lease/edit.
- [x] D1 metadata is exactly `92/94`, UID0000OC owner/emitter, true, blank
  position, `Nested:4`.
- [x] D1 exact managed target block is inserted without compression.
- [x] D1 exact bytes/hash/CFG/ABI/xrefs/callers/callees are incorporated.
- [x] D1 all receiver fields and negative `+0x74/+0x84/+0x90` evidence are
  incorporated.
- [x] D1 palette timing, low-byte direct behavior, modes 0 through 3/default,
  and fixed blend direction are incorporated.
- [x] D1 historical blank-C++/generated-owner/field blockers are preserved only
  as labeled superseded history.
- [x] D2 UID00016L remains `90/92`, NONE/FALSE/blank and updates only
  UID0002PI child/backlog/support facts.
- [x] D3 Surface preserves the complete current union and adds only accepted
  slot-0 source-ready/source-order facts.
- [x] D4 UID0000TN preserves `89/86`, sets position 20, and inserts the exact
  slot-0 managed block.
- [x] D4 preserves every unrelated current callback slot fact.
- [x] D5 UID0001PI preserves `89/88`, UID0000TN route, blank position/formal,
  and adds exact slot-0 storage/setup/dispatch/source-ready facts.
- [x] D6 UID0002PF preserves `88/91` metadata and inserts the exact complete
  corrected managed block.
- [x] D6 uses `rowStridePixels` and preserves low-byte direct/RGB555 blend
  behavior.
- [x] D7 adds only `[0x004c0845,0x004c0850)` and preserves all ignored rows.
- [x] UID00039V current formal and both slot-0 target assignments remain
  unchanged at hash `F37F817A...74CA`.
- [x] GrafPort class/file/aggregate fields remain same-or-greater; all three
  were verified read-only and not edited.
- [x] EPFTileContext, RectBounds, GetClipRect, PointInRect, PaletteLib,
  DLPalette, g_pPaletteLib, and BlendRgb565Pixel remain same-or-greater.
- [x] UID0003PJ and UID0003PK remain caller/support pages and were not assigned
  target ownership.
- [x] Owner/emitter/source-placement reasoning and all rejected alternatives
  are preserved.
- [x] Exact predecessor and successor padding evidence is preserved.
- [x] Exact compiler-only cookie/epilogue/alignment exclusions are preserved.
- [x] No split, rename, new UID, new file, third-party import, IDA edit,
  table-object source, or aggregate body was applied.
- [x] One scoped validator ran for every changed ordinary page while its sole
  lease was held.
- [x] Every ordinary lease was released immediately after its scoped validator.
- [x] Final target validation ran with `--wait-generated` as command
  `000000014303`.
- [x] Every generated assertion listed under Validator Results passes.
- [x] Current manual coverage files were reread; exact supervisor-owned handoff
  remains current and B001 edited none.
- [x] Exact validator command IDs/timestamps/exits/ok counts and side effects
  are recorded.
- [x] Exact final ordinary hashes and generated command/header/hash are
  recorded.
- [x] C2PI-001 through C2PI-060 use legal terminal states with claim-specific
  proof.
- [x] Callback rows were checked only after ordinary and generated readback.
- [x] Temporary tokens/placeholders are absent.
- [x] B001 holds zero leases.
- [x] B001 did not run `execute_report`, lifecycle, probe, count, move, archive,
  generated/manual edit, coverage edit, or IDA mutation.

Implementation callback pass:

- [x] Exact report accepted by supervisor for implementation.
- [x] All accepted D1-D7 details are incorporated at report-level detail.
- [x] All verify-only dependencies were rechecked and recorded with hashes.
- [x] All three exact managed blocks are present once at their destinations.
- [x] Target and support metadata/score/position changes are applied exactly.
- [x] Historical assumptions, rejected alternatives, and negative evidence are
  preserved without compression.
- [x] All scoped validators and final waited generated refresh pass.
- [x] Generated target/global/peer uniqueness, order, fields, modes, and
  no-duplicate assertions pass.
- [x] Exact manual supervisor-owned coverage text remains complete/current.
- [x] No accepted item remains unapplied or blocked.
- [x] Ledger, Validator Results, Changed Files, current state, and checklist are
  reconciled to terminal callback truth.
- [x] Zero leases remain.

READY_FOR_SUPERVISOR_GATE2_REVIEW

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000014348","destination_path":"executed-b-agent-research/B001/0002PI-SoftwareRenderRgb565PixelCallback-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B001/research/0002PI-SoftwareRenderRgb565PixelCallback-source-quality.md","timestamp":"2026-07-16T16:11:32-04:00","uid":"0002PI"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
