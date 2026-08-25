** TARGET-REPORT-UID:0002LW **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID0002LW VoteMenuPane DrawBorder Source-Quality Research


## Finalized Report / Current Recommendation

- Implemented recommendation: [UID:0002LW] `by-memory/0x00555cf0-0x00556012.VoteMenuPaneDrawBorder.md` is now `92/94`, retaining UID, path, owner/emitter UID0000FX, `RECONSTRUCTABLE:TRUE`, blank optional position, exact range, and `Nested:0`.
- Final source disposition: one source-authored `virtual void VoteMenuPane::DrawBorder()` body in `NexusTK/ui/menu/VoteMenuPane.cpp`. The method is reached through primary vtable cell `0x00623044`; absence of direct code callers is expected virtual-dispatch evidence, not dead-code evidence.
- Applied source shape: the current emitted body uses direct `EPFTileContext::Initialize`, `InitRectBounds`, `OffsetRect`, `g_pEPFLib->LookupLayoutEntry`, and inherited `GrafPort::RenderTileFrame` calls. It preserves four mandatory `do` loops, local zero-origin coordinates, tile order `1/6/3/4/0/2/5/7`, draw mode `1`, `SUBWIN.PAL`, and null options.
- Historical `DrawSubwinTile(tileIndex, x, y)` is rejected as a current abstraction. No such call, declaration, or out-of-line helper exists; the binary and current source perform one resource-layout lookup per edge role or corner, then repeat only `RenderTileFrame` inside each edge loop. The pre-callback draft's pane-absolute coordinates and pre-tested loops are retained only as superseded history.
- Direct-comparator result: `0x00555370`, `0x00481750`, and `0x005bd630` are separate vtable methods with the same `0x322` size, 292 instructions, nine blocks, six source callees plus compiler cookie, tile order, local layout, and decompiled behavior. The larger `0x0045b630` paint body independently contains the same border block inline. The strongest human-source model is a copied or header-inlined direct border sequence, not a reusable out-of-line `DrawSubwinTile` helper.
- Implemented support result: the complete combined B002/B004 VoteMenuPane union is preserved. UID0000FX remains `90/92`, UID0000P6 remains `91/92`, and UID0001FY remains semantic-owner-retaining, non-reconstructable/non-emitting, blank-formal `90/93`; B004 added only accepted border evidence. B002's UID0001Z1 `90/93` and UID0001WH `90/92` non-emitting reclassifications remain unchanged.
- Coordination result: B002 completed first and the supervisor executed/archive-moved `executed-b-agent-research/B002/0002LV-VoteMenuPaneDrawBackground-source-quality.md` under command `000000014423`; current archive SHA256 is `CE8ABAF71D18103594A39F5788828B8839CA8EB066C4024C8366E57597152A8E`, 82,239 bytes / 1,259 lines. Historical report-only sample SHA256 `473E6D691168F2641A4845EEABD8D96507E14DD07F74BCAA6832C45198061AF9` remains evidence-time provenance only. B004 reread the executed archive and every shared destination, preserved UID0002LV and the complete `EPFTileContext`/`FrameDrawRecord` class union, and applied only the additive UID0002LW delta.
- Durable lifecycle boundary: this artifact makes no claim about supervisor validation, execution, count, move, archive, or manual coverage application state. B004 performs no report lifecycle command.

## Supporting Research

- Canonical assignment: `tools/leaser/Agents/Agent-B004/goal.md`, top `Current Supervisor UID0002LW New Report-Only Assignment Override`.
- Workflow and literal-template sources:
  - `E:/NTK/GhidraBridge/.codex/skills/ntk-b-agent-workflow/SKILL.md`
  - `E:/NTK/GhidraBridge/.codex/skills/ntk-b-agent-workflow/references/b-agent-research-and-implementation-workflow.md`
  - `E:/NTK/GhidraBridge/.codex/skills/ntk-b-agent-workflow/references/b-agent-report-template.md`
  - `E:/NTK/GhidraBridge/.codex/skills/ntk-b-agent-workflow/references/score-blocker-audit-standard.md`
- MCP provenance:
  - streamable endpoint `http://127.0.0.1:13337/mcp`;
  - B004 protocol session `fb336f1a-db96-406d-a852-9064f058fcad`;
  - fresh `idb_list` returned one active NexusTK database `64c11373`, worker PID `21508`;
  - evidence-time `server_health` returned `status:"ok"`, image base `0x00400000`, auto-analysis ready, Hex-Rays ready, and strings cache ready;
  - bounded target lookup resolved `0x00555cf0` as `sub_555CF0`, size `0x322`, and bounded reads returned real prologue/epilogue bytes;
  - these are evidence-collection-time facts, not indefinite worker-availability assertions.
- Exact old-report and coordination search terms:
  - `UID0002LW`, `0002LW`, `0x00555cf0`, `0x00556012`, `VoteMenuPaneDrawBorder`, `VoteMenuPane`, `DrawBorder`;
  - `DrawSubwinTile`, `DrawSubwinBorder`, `SUBWIN.EPF`, `SUBWIN.PAL`;
  - `0x00457a60`, `0x004b7c50`, `0x004b7e10`, `0x004d02f0`, `0x004b9980`;
  - owner/source terms `UID0000FX`, `UID0000P6`, `UID0001FY`, `UID0001Z1`, `VoteMenuPane.cpp`, `RightButtonMenuPane`, `ChattingVarietySelectPane`, and `MenuVarietySelectPane`.
- Search-root outcomes:
  - `executed-b-agent-research/**`: no dedicated direct UID0002LW report; three exact-address matches and the relevant family/helper/comparator reports listed below.
  - actual project archive root `archived/**`: zero Markdown matches for the exact UID, address, target name, resource names, or border-helper terms.
  - `tools/leaser/Agents/Older-Research/**`: zero matching Markdown reports.
  - `tools/leaser/Agents/SpecialReports/**`: zero matching Markdown reports.
  - active agent roots: the initial evidence checkpoint found the current B004 goal/report assignment plus B002's UID0002LV goal before B002 had written its report; intermediate B002 artifacts at SHA256 `266DD938C4C9D3F02FE096763684E060EEA607DE0EEC60E257BD48704BFA9387`, `76DC3EE59622E3366D16E153F37912D439DD6D2D13BC591AA08E435C44D18D3B`, `3827E964289316753CF64B8072F32607BD73D61758A06619884F076A8CF951BC`, and `83A6BF049EA898EC3298188B0ED712EC586A832BA3E69A88E1E2B113282EB781` are historical snapshots; the final B004 evidence-time sample was `473E6D691168F2641A4845EEABD8D96507E14DD07F74BCAA6832C45198061AF9`, 70,418 bytes / 1,132 lines. No cross-report SHA is asserted as durable.
- Relevant reports opened and classified:

| Report | Evidence-time SHA256 | Classification and finding |
| --- | --- | --- |
| `executed-b-agent-research/B003/0002LR-0002LS-0002LT-0002LU-0002LV-0002LW-0002LX-0002LY-0002LZ-0001G3-votemenupane-source-quality.md` | `A5867E86582E20EDAEE099EA42A5A0B0B9AFD64CB137D315BFFB67152AC0A042` | Historical broad family report. It ran without live MCP, proposed `DrawSubwinTile`, and explicitly left inline expansion/helper placement open. Its owner, tile-role, and source-route findings remain leads; its target body is superseded by this live target-specific pass. |
| `executed-b-agent-research/B003/0001FY-VoteMenuPaneCore-source-quality.md` | `9AAE855A50F9DFE8B3EC1224D246D57523C6836BD608836457269ADE9F5B500A` | Current executed aggregate support. Confirms exact child split, padding, class/file route, and non-emitting aggregate policy. |
| `executed-b-agent-research/B003/0002LU-VoteMenuPaneOnPaint-source-quality.md` | `CEFED46472C235F61B74E194C54C96DECE3515DC6E0F07934B831850092CCE7A` | Current executed adjacent source method. Establishes source-void virtual ABI, primary vtable route, direct inherited GrafPort calls, and no synthetic drawing-helper policy. |
| `executed-b-agent-research/B014/0000FX-VoteMenuPane-class-source-quality.md` | `983ABC57326E19F098B74B40EFBE1FC3B6F1BAEDBBFD39725FF69414A595CE13` | Current executed class-shell support. Establishes `virtual void DrawBorder()`, class-before-children ordering, fields, owner, file route, and compiler-wrapper exclusions. |
| `executed-b-agent-research/B005/0001FX-RightButtonMenuPaneCore-source-quality.md` | `A99F5B9FCB12DF34F3F46DB1F5C829C65A129B40CCA30A3F63BF3FEAF18A42E6` | Direct comparator lead. Identifies the separate identical `0x00555370-0x00555692` border virtual under RightButtonMenuPane. |
| `executed-b-agent-research/B003/0002FH-0002FJ-0002FK-0002FL-0002FN-0002FO-000106-chatting-variety-select-pane-source-quality.md` | `4054973D0885D39F0892667D9A4E9904E3C420341B58FAF67D883CC3DAB61C91` | Direct comparator lead. Identifies the separate identical `0x00481750-0x00481a72` ChattingVarietySelectPane border virtual. |
| `executed-b-agent-research/B002/0001ZG-RankingRewardInfoDialogCore-source-quality.md` | `785678C282B72EAC41B45FC8BD1D151C6C933D179903A2E3BB2401146B698B2A` | Source-shape comparator. Its accepted paint formal uses direct `EPFTileContext`/`RectBounds`/resource lookup/render calls for an inline SUBWIN-like eight-part border block. |
| `executed-b-agent-research/B001/0000BU-RectBounds-class-source-quality.md` | `DE7D5C312B3790004CB859973FA9C63C57396C10154F430B590B4C7F17FE3AEF` | Current geometry support. Resolves `InitRectBounds` and free `OffsetRect` source contracts. |
| `executed-b-agent-research/B004/00004I-EPFTileContext-class-source-quality.md` | `D758C0B4531CB3C0507C31270E4E0ECD65B4829E3346E6CA5FCF722449018292` | Current render-record support. Resolves the 0x28-byte `EPFTileContext` and explicit `Initialize()` call. |
| `executed-b-agent-research/B002/0002LV-VoteMenuPaneDrawBackground-source-quality.md` | current archive SHA256 `CE8ABAF71D18103594A39F5788828B8839CA8EB066C4024C8366E57597152A8E` | Executed predecessor and callback baseline. UID0002LV is exact `92/94`; UID0001FY/UID0001Z1/UID0001WH carry their accepted false/non-emitting blank-formal states; the complete class formal includes the source-compatible `EPFTileContext`/`FrameDrawRecord` alias. Historical report-only sample `473E6D...61AF9` remains time-scoped provenance only. |

- Old reports were used as revalidated leads only. Target behavior, source-shape corrections, helper contracts, hashes, vtable reachability, and comparator equivalence were independently checked against live MCP and current ordinary/generated/manual documentation.
- Wave2/Wave3/simroot output was not used as behavioral authority.

## Target

- Target UID: `0002LW`.
- Target path: `by-memory/0x00555cf0-0x00556012.VoteMenuPaneDrawBorder.md`.
- Exact range: `[0x00555cf0,0x00556012)`, 0x322 / 802 bytes.
- Current ordinary hash after callback: `E0E498CCE219D6ECA5B258F3F51327C12D12B720BC49282D4542517CA4D6435A`, 16,821 bytes / 212 lines.
- Current metadata: `92/94`, owner/emitter UID0000FX, reconstructable true, blank optional emitter position, `Nested:0`.
- Current generated tracker command `000000014433` records UID0002LW at `92/94` on line 3222; tracker SHA256 is `2A675847CD5D58D6AF3ED1C0054D2B8B6C9CFAC506B953EAF77DFFF33791E296`, 1,508,875 bytes / 6,131 lines. Report execution/count state remains external supervisor/validator-owned.
- Current formal body is Destination 1 exactly and is byte-equal to the generated UID0002LW body.

## Current Target State

- Current applied facts:
  - exact modeled function start and size;
  - owner class/file and primary vtable slot;
  - eight SUBWIN tile roles and palette;
  - seven-pixel edge/corner geometry;
  - predecessor/successor padding;
  - broad callee set and no direct code caller;
  - target source route through VoteMenuPane.
- Historical pre-callback defects now corrected:
  - `DrawSubwinTile` is a descriptive pseudo-helper with no declaration, body, call target, or accepted shared API.
  - The page says the pseudo-helper initializes/loads the tile context per invocation. That would perform one layout lookup per repeated edge tile, but the binary performs one lookup before each edge loop and then repeats only the render call.
  - `left/top/right/bottom` are used as drawing coordinates. The binary initializes destination bounds at `(0,0,7,7)` and offsets from local zero; object bounds supply only width and height through `right-left` and `bottom-top`.
  - The four edge loops are written as `for` loops that can execute zero times. The binary has four back-edge blocks entered before testing, so each edge role renders at least once.
  - The source/destination rectangle objects, exact `EPFTileContext`, resource-layout API, GrafPort render API, draw mode, options type, and palette lookup behavior are not expressed.
- Historical pre-callback generated snapshot:
  - `auto-generated/NexusTK/ui/menu/VoteMenuPane.cpp`;
  - current final-readback validator header command `000000014373`, refreshed `2026-07-16T16:21:06-04:00`;
  - SHA256 `7D445718C54BFFFFDB012C2AA867BEA100A6A0788576CEAF6C55E73092A57BE7`, 8,559 bytes / 280 lines;
  - one UID0002LW definition containing the then-inaccurate `DrawSubwinTile` body and no target Empty Emitter Marker.
- Historical research-time tracker snapshot:
  - final B004 evidence-time read observed command `000000014379`, refreshed `2026-07-16T16:34:35-04:00`;
  - SHA256 `029BDD6BB3C2879D25303A0CF25A639A8B7117C4AF302931709B8C8F7083E141`, 1,508,588 bytes / 6,131 lines;
  - this volatile generated tracker header is time-scoped rather than asserted as durable current state.
- Current generated implementation proof:
  - `auto-generated/NexusTK/ui/menu/VoteMenuPane.cpp`;
  - validator header command `000000014433`, refreshed `2026-07-16T17:19:55-04:00`;
  - SHA256 `BD866AF4A339624BEF1890E193109BD092E4A7123C95D5F38D3BBA11A225BA6A`, 11,256 bytes / 359 lines;
  - one UID0002LW definition, four target `do` loops, eight target layout lookups, eight target render sites, zero target Empty Emitter Markers, zero `DrawSubwinTile`, and formal-to-generated byte equality. Two unrelated Empty Emitter Markers remain for UID0001G3 and UID0001FZ.
- Manual coverage remains supervisor-owned. Current by-memory UID0002LW row 2912 is still stale at `82%`; UID0001FY line 2900, UID0000FX line 593, and UID0000P6 line 302 also retain pre-B004 callback wording. Exact combined replacements are supplied below.
- Callback edits are limited to the four authorized ordinary pages plus this report. No manual coverage file was edited.

## Executive Recommendation

- Destination 1 is installed exactly under the target managed header.
- Target is `92/94`; all routing/range/nesting fields are preserved.
- Preserve source signature `void VoteMenuPane::DrawBorder()`. IDA's inferred integer return is a consequence of an untyped final render call; primary vtable declaration, class source, direct call-site use, and comparator declarations support source `void`.
- Use local `EPFTileContext tileContext`, `RectBounds sourceBounds`, and `RectBounds destinationBounds`.
- Initialize one 7x7 source rectangle, compute local width/height from inherited `m_visibleBounds`, and preserve the direct sequence:
  - top edge frame 1;
  - bottom edge frame 6;
  - left edge frame 3;
  - right edge frame 4;
  - corners 0, 2, 5, 7.
- Keep `g_pEPFLib->LookupLayoutEntry` outside each repeated edge loop and call inherited `RenderTileFrame` inside the loop with mode 1, `L"SUBWIN.PAL"`, and `NULL`.
- Use four `do` loops and local destination coordinates. Do not add dimension validation, clipping, clamping, helper calls, enum wrappers, or resource caching absent from the binary.
- B002's UID0002LV/support callback completed first. B004 then synchronized only bounded UID0002LW-specific facts into the reread class/file/aggregate state and preserved the false/non-emitting UID0001FY/UID0001Z1/UID0001WH dispositions plus the complete shared VoteMenuPane source union.

## Supervisor Active Recheck

- Historical assignment duplicate screening found no dedicated direct target report and no UID0002LW lease conflict.
- The callback recheck opened B002's executed archive at SHA256 `CE8ABAF71D18103594A39F5788828B8839CA8EB066C4024C8366E57597152A8E` and reread UID0002LW, UID0001FY, UID0000FX, UID0000P6, UID0001Z1, UID0001WH, and UID0002LV.
- Collision-free ownership/order was completed:
  - B002 retains UID0002LV and its UID0001FY/UID0001Z1/UID0001WH reclassification delta.
  - B004 owns UID0002LW and only the additive UID0002LW-specific class/file/aggregate synchronization.
  - UID0002LV was not leased, edited, or validated by B004 and remains SHA256 `70B78AB115846DE326A30CCE90237E07AB59C8F8F1F8E87599CEF5340838C523`.
  - B004 reread each shared destination after its short lease, preserved the full executed B002 union, validated the bounded delta, and released every lease.
- No collision or implementation blocker remains. External supervisor/validator lifecycle state is not asserted by this artifact.

## Inference Research Guidance Check

- Exact IDB facts were separated from source inference:
  - direct facts: bytes, CFG, stack shape, calls, constants, xrefs, vtable cell, resource strings, bounds offsets, loop ordering, and comparator bodies;
  - high-probability source inference: `void DrawBorder`, local variable names, direct copied/inlined statements, and numeric frame literals;
  - rejected inference: synthetic `DrawSubwinTile`, pane-absolute draw coordinates, pre-tested loops, out-of-line shared-helper ownership, and per-tile resource lookup.
- Existing docs/reports were treated as leads and checked against live MCP.
- The recommendation follows current accepted shared APIs instead of raw names:
  - `EPFTileContext::Initialize`;
  - `InitRectBounds`;
  - `OffsetRect`;
  - `g_pEPFLib->LookupLayoutEntry`;
  - inherited `GrafPort::RenderTileFrame`.
- Exact original local names and whether the duplicated sequence came from literal copy/paste or a header macro/inline template cannot be recovered. That lexical uncertainty caps the score but does not block a behaviorally exact human source body.
- No named score blocker remains deferred. Every in-scope helper, field, coordinate, palette, resource, ownership, source placement, signature, loop, and formal-C++ question has a selected disposition.

## Heuristic / Inference Reanalysis And Validation

- Function model:
  - `lookup_funcs` resolves `sub_555CF0`, size `0x322`;
  - `func_profile` reports 292 instructions, nine basic blocks, zero direct callers, and the expected helper set;
  - basic blocks contain four self-backed loop bodies at `0x555d60`, `0x555dd0`, `0x555e34`, and `0x555ea0`.
- Stack/type model:
  - frame reserves `0x5c` bytes;
  - the 0x28-byte region beginning at local `var_5C` is initialized by `0x00457a60`, matching `EPFTileContext`;
  - three consecutive 0x10-byte regions are source, base, and working `RectBounds`;
  - 0x28 + 0x10 + 0x10 + 0x10 + 4-byte cookie equals the observed 0x5c frame.
- Coordinate model:
  - source and base destination rectangles are initialized `(0,0,7,7)`;
  - top begins at local x 7, y 0;
  - bottom begins at local x 7, y `height-7`;
  - left begins at local x 0, y 7;
  - right begins at local x `width-7`, y 7;
  - corners use `(0,0)`, `(width-7,0)`, `(0,height-7)`, and `(width-7,height-7)`;
  - object `m_visibleBounds.left/top` are subtracted only to derive width/height; historical `m_bounds` is a superseded alias for the same inherited `+0x44` rectangle.
- Loop model:
  - each edge is entered unconditionally after its resource lookup;
  - the destination rectangle is offset after each render;
  - horizontal continuation tests working `right < source.left + width`;
  - vertical continuation tests working `bottom < source.top + height`;
  - no width/height validity check precedes the loops.
- Resource/render model:
  - one `EPFTileContext::Initialize()` call;
  - eight static `LookupLayoutEntry` sites in frame order `1/6/3/4/0/2/5/7`;
  - eight static `RenderTileFrame` sites, four of which are dynamically repeated;
  - all render sites use mode `1`, palette `SUBWIN.PAL`, and null options;
  - `RenderTileFrame` resolves the palette through `g_pPaletteLib` and dispatches through `g_pfnBlitSprite`;
  - no explicit context release occurs because this lookup result is borrowed/non-owning in the accepted resource-layout model.
- Source duplication model:
  - `0x00555370`, `0x00481750`, and `0x005bd630` each have size `0x322`, 292 instructions, nine blocks, zero direct callers, and one vtable data xref;
  - their decompiles match target statement for statement;
  - `0x0045b630` embeds the same edge/corner block inside a larger paint method;
  - separate vtable targets reject one shared out-of-line base implementation;
  - no call target supports a per-tile helper;
  - direct duplicated statements are highest probability; a macro/header-inline border snippet is the bounded runner-up.

## Evidence Standards Used

- Highest weight:
  - live MCP `idb_list`, `server_health`, `lookup_funcs`, `get_bytes`, `func_profile`, `analyze_function`, `decompile`, `disasm`, `basic_blocks`, `callees`, `xref_query`, `get_int`, and signature generation;
  - current target/support ordinary docs;
  - current generated source and manual coverage readback.
- Supporting weight:
  - executed reports only after current evidence reconfirmed the relevant fact;
  - identical comparator methods and accepted shared helper formals.
- Lead-only:
  - historical broad B003 target report because its MCP pass was unavailable;
  - stale simroot/generated owner names;
  - old completion thresholds and helper caveats.
- Confidence is capped below perfect by unrecoverable original lexical choices: local names, potential macro/header-inline origin, numeric constants versus private enum spellings, and exact include/header partition.

## Evidence Checked

- MCP transport/session:
  - `idb_list` -> active database `64c11373`;
  - `server_health(database=64c11373)` -> `status:ok`;
  - final bounded recheck through a fresh streamable protocol session again resolved target `sub_555CF0`, size `0x322`, and returned prologue bytes `55 8b ec 83 ec 5c a1 24 2f 67 00 33 c5 89 45 fc`;
  - bounded lookup/read at target and positive control `0x00401000`.
- Target function:
  - `lookup_funcs(0x00555cf0)` -> `sub_555CF0`, size `0x322`;
  - full `decompile`, first 120 disassembly instructions, `func_profile`, `basic_blocks`, `callees`, stack frame;
  - full 802-byte read and local SHA256;
  - relocatable function signature generation.
- Reachability/vtables:
  - `xref_query` to target -> sole data xref `0x00623044`;
  - `get_int(0x00623044,u32le)` -> `0x00555cf0`;
  - primary vtable cells `0x0062303c`, `0x00623040`, `0x00623044` -> OnPaint, DrawBackground, DrawBorder;
  - xrefs to primary base `0x00622ff8` -> raw constructor `0x00555913`, ordinary destructor `0x00555975`, scalar deleting destructor `0x0055634c`;
  - OnPaint disassembly -> calls primary slots `+0x48` and `+0x4c` and ignores both returns.
- Resources:
  - UTF-16 bytes at `0x00610b74` -> `SUBWIN.EPF`;
  - UTF-16 bytes at `0x00610b8c` -> `SUBWIN.PAL`;
  - target refs at `0x00555d54/0x00555dc2/0x00555e2a/0x00555e96/0x00555ee6/0x00555f38/0x00555f86/0x00555fdc` and matching palette refs at `0x00555d62/0x00555dd2/0x00555e36/0x00555ea2/0x00555ef6/0x00555f44/0x00555f92/0x00555fe8`.
- Shared helper bodies:
  - `0x00457a60`: 0x44-byte explicit 0x28-byte context initializer, clears buffers/bounds/state;
  - `0x004b7c50`: cdecl four-field rectangle initializer;
  - `0x004b7e10`: cdecl rectangle offset helper updating all four edges;
  - `0x004d02f0`: resource-layout entry lookup over `g_pEPFLib`, writing context data or a cleared record;
  - `0x004b9980`: GrafPort receiver call, palette-name lookup, sprite callback dispatch, `ret 0x18`.
- Exact comparators:
  - target `0x00555cf0`, RightButton `0x00555370`, Chatting selector `0x00481750`, and Menu selector `0x005bd630`;
  - all four profile as `0x322`, 292 instructions, nine blocks, zero direct callers, seven profile callees including self/profile artifact;
  - xrefs are vtable cells `0x00623044`, `0x00622fb4`, `0x00614f78`, and `0x00630e14`;
  - full decompiles are behaviorally identical;
  - larger `0x0045b630` contains the same border block inline.
- Boundaries:
  - predecessor `0x00555ce1-0x00555cf0`: fifteen `0xcc`, SHA256 `54CC9DD9593316E80CCAF5D10856E6502A0D75F20473A92FA01D63228EF1624C`;
  - successor `0x00556012-0x00556020`: fourteen `0xcc`, SHA256 `1E875C76536C8496BED8C8760B539327F24ACFFBCF0A4B941877B4BFB4C44356`.
- Current docs read:
  - target;
  - UID0000FX class;
  - UID0000P6 file;
  - UID0001FY aggregate;
  - UID0002LV and UID0002LX neighbors;
  - UID0001WH layout;
  - UID0001Z1 vtable;
  - UID0003CY vtable data;
  - `by-memory/-ignored.md`;
  - EPFTileContext, RectBounds, ResourceLayoutTable lookup, GrafPort RenderTileFrame, and g_pEPFLib support.
- Coordination artifact read:
  - current executed archive `executed-b-agent-research/B002/0002LV-VoteMenuPaneDrawBackground-source-quality.md`;
  - current archive SHA256 `CE8ABAF71D18103594A39F5788828B8839CA8EB066C4024C8366E57597152A8E`, 82,239 bytes / 1,259 lines;
  - historical report-only SHA256 `473E6D691168F2641A4845EEABD8D96507E14DD07F74BCAA6832C45198061AF9`, 70,418 bytes / 1,132 lines, remains evidence-time provenance;
  - B002's direct target and shared support reclassifications are complete, and B004 preserved the complete class formal including `struct EPFTileContext; typedef EPFTileContext FrameDrawRecord;`.
- Current generated/tracker/manual read:
  - VoteMenuPane.cpp;
  - research tracker;
  - by-memory, by-class, by-file, by-struct, and by-vtable manual coverage.
- Historical report-only restrictions were observed before Gate 1: no scoped
  validator, lease, IDA mutation, or ordinary/manual/generated/tracker/audit/
  lifecycle edit occurred during research.
- Authorized callback operations were limited to the four accepted ordinary
  destinations, scoped validators `000000014429`-`000000014432`, final waited
  validator `000000014433`, and this report reconciliation. No manual coverage,
  generated, tracker, audit, supervisor, lifecycle, or IDA file was edited
  manually.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C2LW-001 | UID0002LW is exactly `[0x00555cf0,0x00556012)`, 0x322 / 802 bytes. | very strong | lookup, bytes, predecessor/successor boundaries | target metadata/range/evidence | incorporate | applied |
| C2LW-002 | Full target bytes have SHA256 `CF50B71B823746310492ED905E454767023DA03B91B3FC1AFFB016996FF91F45`. | very strong | full MCP byte read, local SHA256 | target Item Summary/evidence | incorporate | applied |
| C2LW-003 | Target has a generated relocatable signature covering the exact function and adjacent boundary; exact raw bytes remain the primary identity. | strong | make_signature_for_function | target evidence/history | incorporate | applied |
| C2LW-004 | Target contains 292 instructions and nine basic blocks, including four mandatory loop back edges. | very strong | func_profile, basic_blocks, disasm | target behavior/CFG evidence | incorporate | applied |
| C2LW-005 | Source signature is `void VoteMenuPane::DrawBorder()`, not an integer-return helper. | very strong | current class declaration, vtable slot, OnPaint return ignored, identical class comparators | target formal/signature | incorporate | applied |
| C2LW-006 | Target is live through primary vtable cell `0x00623044`; the cell contains `0x00555cf0`. | very strong | xref_query, get_int | target liveness; vtable support note | incorporate | applied |
| C2LW-007 | No direct code caller exists; virtual dispatch and constructor/destructor vtable lifecycle are the correct liveness route. | very strong | func_profile, target xref, vtable-base xrefs | target status/negative evidence | incorporate | applied |
| C2LW-008 | Object offsets `+0x44/+0x48/+0x4c/+0x50` supply inherited `GrafPort::m_visibleBounds.left/top/right/bottom`, but drawing coordinates are local zero-origin; only width/height use that rectangle. Historical `m_bounds` is a superseded alias. | very strong | disasm/decompile, current GrafPort/Pane layout, executed B002 baseline | target behavior/formal/history | incorporate | applied |
| C2LW-009 | Stack locals are one 0x28-byte `EPFTileContext` plus three 0x10-byte `RectBounds` records and the security cookie. | very strong | stack frame, initializer, exact frame size | target type/evidence | incorporate | applied |
| C2LW-010 | `0x00457a60` is source-facing `EPFTileContext::Initialize()` and is called exactly once before all tile lookups. | very strong | helper decompile/support page, target disasm | target formal/helper table | incorporate | applied |
| C2LW-011 | `0x004b7c50` initializes both source and base destination rectangles as `(0,0,7,7)`. | very strong | helper/target decompile | target formal/geometry | incorporate | applied |
| C2LW-012 | `0x004b7e10` is free `OffsetRect(RectBounds *, int dx, int dy)` and must remain free-helper-shaped. | very strong | helper decompile, RectBounds support | target formal/helper table | incorporate | applied |
| C2LW-013 | `0x0067a744` is `g_pEPFLib`; target caches the pointer once and performs eight layout lookups. | very strong | target disasm, global support, xrefs | target formal/resource evidence | incorporate | applied |
| C2LW-014 | Resource strings are exact UTF-16 `SUBWIN.EPF` at `0x00610b74` and `SUBWIN.PAL` at `0x00610b8c`. | very strong | bounded bytes, xrefs | target behavior/formal | incorporate | applied |
| C2LW-015 | Tile/frame order is exactly top `1`, bottom `6`, left `3`, right `4`, then corners `0`, `2`, `5`, `7`. | very strong | constants, lookup sites, decompile | target behavior/formal | incorporate | applied |
| C2LW-016 | Top edge: lookup frame 1 once, render at local x 7, then offset +7 and continue while working right is below source-left plus width. | very strong | first loop disasm/decompile | target formal | incorporate | applied |
| C2LW-017 | Bottom edge: lookup frame 6 once, local y is `height-7`, and horizontal iteration matches the top edge. | very strong | second loop disasm/decompile | target formal | incorporate | applied |
| C2LW-018 | Left edge: lookup frame 3 once, render at local y 7, offset +7 vertically, and test working bottom against source-top plus height. | very strong | third loop disasm/decompile | target formal | incorporate | applied |
| C2LW-019 | Right edge: lookup frame 4 once, local x is `width-7`, and vertical iteration matches the left edge. | very strong | fourth loop disasm/decompile | target formal | incorporate | applied |
| C2LW-020 | Corner destinations are local `(0,0)`, `(width-7,0)`, `(0,height-7)`, and `(width-7,height-7)` for frames 0,2,5,7. | very strong | corner disasm/decompile | target formal | incorporate | applied |
| C2LW-021 | Every render uses inherited `GrafPort::RenderTileFrame`, draw mode 1, `SUBWIN.PAL`, and null options. | very strong | target call setup, exact GrafPort child formal | target formal/helper table | incorporate | applied |
| C2LW-022 | `RenderTileFrame` resolves the palette through `g_pPaletteLib` and dispatches `g_pfnBlitSprite`; target does not own palette lookup or callback implementation. | very strong | exact GrafPort child/support | target dependency evidence | incorporate | applied |
| C2LW-023 | `LookupLayoutEntry` writes a borrowed tile context; target performs no explicit release and must not add one. | strong | exact lookup helper, target absence, accepted consumer pattern | target formal/negative evidence | incorporate | applied |
| C2LW-024 | All four edge loops are `do` loops and execute at least once; no dimension guard/clamp exists. | very strong | CFG and disasm entry/test order | target formal/negative evidence | incorporate | applied |
| C2LW-025 | Historical pane-absolute `left/top/right/bottom` draw coordinates were stale and behaviorally wrong; current source uses local width/height. | very strong | direct target disasm/decompile and current formal | target formal/history | reject-stale | applied |
| C2LW-026 | Historical `DrawSubwinTile` was unsupported and changed lookup frequency; it is absent from current formal/current generated source and retained only as superseded history. | very strong | no helper call/definition, exact call ordering, generated command 14433 | target/class/file history | reject-invalid | applied |
| C2LW-027 | RightButton, Chatting selector, and Menu selector border virtuals are separate exact-size/profile/decompile clones. | very strong | lookup/profile/decompile/xrefs | target comparator evidence; class/file note | incorporate | applied |
| C2LW-028 | `0x0045b630` embeds the same border block inside a larger paint body, further rejecting a necessary out-of-line border helper. | strong | live decompile, accepted Ranking report | target source-shape analysis | incorporate | applied |
| C2LW-029 | Highest-probability human source is direct duplicated or header-inlined statements; macro/header-inline origin remains the bounded runner-up. | strong | four clones plus inline larger-body comparator | target source-shape/score rationale | incorporate | applied |
| C2LW-030 | Keep direct owner/emitter UID0000FX and source file UID0000P6 `NexusTK/ui/menu/VoteMenuPane.cpp`. | very strong | current metadata and generated route | target metadata/source placement | already-present | already-present |
| C2LW-031 | Preserve UID, path, reconstructable true, blank position, exact range, and `Nested:0`; no rename, split, or new child is needed. | very strong | current target/readback | target metadata/range | already-present | already-present |
| C2LW-032 | Raise target `86/90 -> 92/94`; remaining cap is lexical, not behavioral or routing uncertainty. | strong | current `92/94` metadata and closed blockers | target metadata/score rationale | incorporate | applied |
| C2LW-033 | Install Destination 1 as the only changed target formal block. | very strong | formal-to-generated byte equality | target managed C++ | incorporate | applied |
| C2LW-034 | Replace stale Item Summary/helper caveats and historicalize the June pseudo-helper body without deleting provenance. | very strong | current target hash/readback | target summary/status/history | historicalize | applied |
| C2LW-035 | Preserve UID0000FX at executed-B002 `90/92`, retain its complete formal and `EPFTileContext`/`FrameDrawRecord` alias, add border evidence, and add no border helper declaration. | strong | current class hash, executed B002 archive, validator 14430 | class support | incorporate | applied |
| C2LW-036 | Preserve UID0000P6 at executed-B002 `91/92`, retain every source/compiler piece, and add only the complete UID0002LW source behavior/evidence. | strong | current file hash, executed B002 archive, validator 14431 | file support | incorporate | applied |
| C2LW-037 | Preserve UID0001FY at B002's semantic-owner-retaining, non-reconstructable/non-emitting, blank-formal `90/93` state and add UID0002LW detail without losing any child or padding. | very strong | current aggregate hash and validator 14432 | aggregate support | incorporate | applied |
| C2LW-038 | Preserve executed-B002 UID0001Z1 `90/93` and UID0001WH `90/92` semantic-owner-retaining false/non-emitting blank-formal states; UID0003CY remains verify-only. | very strong | current support hashes/readback | vtable/layout coordination; vtable-data verification | already-present | already-present |
| C2LW-039 | UID0002LV remains B002-owned and unchanged by B004; current executed archive SHA256 is `CE8ABAF71D18103594A39F5788828B8839CA8EB066C4024C8366E57597152A8E`, and ordinary UID0002LV SHA256 remains `70B78AB115846DE326A30CCE90237E07AB59C8F8F1F8E87599CEF5340838C523`. | very strong | executed archive and current ordinary readback | coordination/follow-up/checklist | already-present | already-present |
| C2LW-040 | UID0002LX remains unchanged; its rectangle helper behavior is independent of border rendering. | very strong | current child hash/readback | neighbor verification | already-present | already-present |
| C2LW-041 | EPFTileContext, RectBounds, ResourceLayout lookup, GrafPort RenderTileFrame, and g_pEPFLib support are sufficient and received no target callback edit. | very strong | exact current support hashes/formals | support verification | already-present | already-present |
| C2LW-042 | Existing ignored rows already cover both adjacent all-CC padding spans; no ignored-page edit was required. | very strong | current ignored hash and row 1755 | padding verification | already-present | already-present |
| C2LW-043 | Final generated proof shows one exact UID0002LW body, zero target marker, zero `DrawSubwinTile`, four `do` loops, eight lookups, eight static render sites, formal equality, and no duplicate body. | very strong | validator/generated command 14433 | callback generated assertions | incorporate | applied |
| C2LW-044 | Current manual by-memory/class/file/aggregate rows remain stale and the exact combined supervisor-owned replacements below are current; B002-owned by-struct/vtable rows are already exact and preserved. | very strong | final current manual row/hash readback | manual handoff | incorporate | applied |
| C2LW-045 | Historical broad B003 target conclusions are retained only where current evidence confirms them; pseudo-helper and helper-blocker conclusions are superseded. | very strong | old report versus current target/readback | report/target history | historicalize | applied |
| C2LW-046 | Callback changed only four authorized ordinary pages and this report, used scoped validators `14429`-`14432` plus waited validator `14433`, manually edited no restricted file, ran no lifecycle command, and ended with zero leases and all checklist items terminal. | very strong | hashes, validator output, generated readback, lease cleanup | Validator Results/Changed Files/checklist | incorporate | applied |

## Positive Evidence Summary

- Exact function identity is strong: 802 bytes, SHA256, 292 instructions, nine blocks, unique relocatable signature, exact padding, and one vtable data xref.
- Liveness is strong: primary vtable cell `0x00623044` points to target, and the primary vtable base is installed/restored by constructor, ordinary destructor, and scalar deleting destructor.
- Source signature is strong: current class formal declares `virtual void DrawBorder()`, OnPaint calls the slot and ignores a return, and three parallel classes expose the same source role.
- Behavior is complete:
  - one tile context initialization;
  - two 7x7 rectangle initializations;
  - local width and height;
  - four mandatory edge loops;
  - four corners;
  - exact frame order and call arguments.
- Shared API names/types are no longer blockers because exact source-ready support pages exist for every non-compiler callee.
- Four exact standalone clones plus one larger inline comparator strongly resolve the source abstraction decision.

## IDA MCP Facts

- Database: `64c11373`; health was `ok` when evidence was collected.
- Target:
  - start `0x00555cf0`;
  - end `0x00556012`;
  - size `0x322`;
  - 292 instructions;
  - nine blocks;
  - zero direct callers;
  - six distinct non-self callees plus compiler cookie.
- Target bytes:
  - begin `55 8b ec 83 ec 5c a1 24 2f 67 00 33 c5 89 45 fc`;
  - end includes cookie check, frame teardown, `ret`;
  - full SHA256 `CF50B71B823746310492ED905E454767023DA03B91B3FC1AFFB016996FF91F45`.
- Sole target xref: data cell `0x00623044`.
- Primary vtable route:
  - `0x0062303c -> 0x00555af0` OnPaint;
  - `0x00623040 -> 0x00555c70` DrawBackground;
  - `0x00623044 -> 0x00555cf0` DrawBorder.
- Primary vtable-base xrefs:
  - `0x00555913` raw constructor;
  - `0x00555975` ordinary destructor;
  - `0x0055634c` scalar deleting destructor.
- Exact non-compiler callees:
  - `0x00457a60` EPFTileContext initialize;
  - `0x004b7c50` InitRectBounds;
  - `0x004b7e10` OffsetRect;
  - `0x004d02f0` resource layout lookup;
  - `0x004b9980` GrafPort RenderTileFrame.
- Compiler callee: `0x005c772f` security-cookie check; exclude from source.

## Function / Child Inventory

| Range / item | UID/path | Role | Current score | Recommendation |
| --- | --- | --- | --- | --- |
| `0x00555c70-0x00555ce1` | UID0002LV DrawBackground | Adjacent source virtual | `92/94` | Executed B002 source body; B004 verified unchanged. |
| `0x00555ce1-0x00555cf0` | UID0000VN ignored | Fifteen-byte alignment | ignored | Preserve exact row/bytes. |
| `0x00555cf0-0x00556012` | UID0002LW target | Source `void DrawBorder()` virtual | `92/94` | Exact direct body installed and generated once. |
| `0x00556012-0x00556020` | UID0000VN ignored | Fourteen-byte alignment | ignored | Preserve exact row/bytes. |
| `0x00556020-0x0055606d` | UID0002LX GetItemRect | File-local row rectangle helper | `87/92` | Preserve unchanged. |
| `0x005558d0-0x0055606d` | UID0001FY aggregate | Non-emitting core inventory | `90/93` | Executed B002 false/non-emitting blank-formal state preserved; target detail added without duplicate source. |
| `0x00622ff4-0x00623084` | UID0003CY | VoteMenuPane RTTI/vtable data | `87/92` | Verify-only generated-binary support. |
| class | UID0000FX VoteMenuPane | Class declaration/emitter | `90/92` | Full B002/B004 formal union preserved; border evidence added, no helper declaration. |
| file | UID0000P6 VoteMenuPane | Source route | `91/92` | Full B002/B004 source union preserved; border behavior/evidence added. |

Exact target internal operation inventory:

| Order | Operation | Resource frame / movement |
| ---: | --- | --- |
| 1 | Initialize tile context | one call |
| 2 | Initialize source and base destination bounds | both `(0,0,7,7)` |
| 3 | Draw top edge | frame 1, start `(7,0)`, step `(7,0)` |
| 4 | Draw bottom edge | frame 6, start `(7,height-7)`, step `(7,0)` |
| 5 | Draw left edge | frame 3, start `(0,7)`, step `(0,7)` |
| 6 | Draw right edge | frame 4, start `(width-7,7)`, step `(0,7)` |
| 7 | Draw top-left | frame 0, `(0,0)` |
| 8 | Draw top-right | frame 2, `(width-7,0)` |
| 9 | Draw bottom-left | frame 5, `(0,height-7)` |
| 10 | Draw bottom-right | frame 7, `(width-7,height-7)` |

## Direct Xref / Caller Inventory

| Address/item | Xref/caller/callee | Meaning |
| --- | --- | --- |
| `0x00555cf0` | sole data xref `0x00623044`; zero code callers | Primary virtual method. |
| `0x00623044` | value `0x00555cf0` | Exact primary DrawBorder slot. |
| `0x00622ff8` | refs `0x00555913`, `0x00555975`, `0x0055634c` | Constructor/destructor lifecycle for primary view. |
| `0x00555af0` | calls vtable `+0x48`, then `+0x4c` | OnPaint invokes DrawBackground then DrawBorder. |
| `0x00610b74` | eight target refs | SUBWIN.EPF lookup name. |
| `0x00610b8c` | eight target refs | SUBWIN.PAL render palette name. |
| `0x0067a744` | target loads once into `edi` | g_pEPFLib resource registry. |
| `0x00457a60` | one target call | Tile context initialization. |
| `0x004b7c50` | two target call sites | Source/base 7x7 bounds. |
| `0x004b7e10` | edge setup/advance and corner placement sites | Working destination movement. |
| `0x004d02f0` | eight target call sites | One tile lookup per edge role/corner. |
| `0x004b9980` | eight static target call sites | Four repeated edge render sites plus four corners. |
| `0x00555370` | vtable cell `0x00622fb4` | Identical RightButtonMenuPane comparator. |
| `0x00481750` | vtable cell `0x00614f78` | Identical ChattingVarietySelectPane comparator. |
| `0x005bd630` | vtable cell `0x00630e14` | Identical MenuVarietySelectPane comparator. |

## Documentation Evidence And IDA Status

- Target ordinary page:
  - current `92/94`, hash `E0E498CCE219D6ECA5B258F3F51327C12D12B720BC49282D4542517CA4D6435A`;
  - exact range/routing/tile roles, direct formal, local coordinates, loop form, score, summary, comparator evidence, and superseded-history treatment are applied.
- UID0000FX class:
  - remains `90/92`, hash `5AA86B00C4AA2B3C1FF578D0D3E83CF4C10E680818E94AA1E251EFA7D7EAAA66`;
  - declares `virtual void DrawBorder()`;
  - no `DrawSubwinTile` declaration exists or is needed;
  - class closes before `[[CHILDREN]]`;
  - exact Destination 2 remains byte-preserved with B002's source-compatible `struct EPFTileContext; typedef EPFTileContext FrameDrawRecord;` addition.
- UID0000P6 file:
  - remains `91/92`, hash `6B688E39C7542B461695BC79404A0DC9BB0E32F191C0FE4F202E4EE409634208`;
  - retains the `NexusTK/ui/menu/VoteMenuPane.cpp` route and complete VoteMenuPane source/compiler split;
  - includes target-specific direct-body/no-helper/source-quality synchronization.
- UID0001FY aggregate:
  - remains semantic-owner-retaining false/non-emitting blank-formal `90/93`, hash `BE14FE4DF5A1AD75AF6C6DD577BE42DE019EEE39CB88FAF74AD6B534AE5710E8`;
  - retains exact non-duplicating inventory and padding;
  - exact children, not this index page, emit source; B004 added only target-specific detail.
- UID0001Z1/UID0001WH/UID0003CY:
  - already identify primary slot `+0x4c`, target address, and lifecycle stores;
  - executed B002 states are current: UID0001Z1 `90/93` hash `08061D4275E25ED6E2D3A776C846FAAF323B925213F0CF9D8A99C71DA1756822` and UID0001WH `90/92` hash `FEE4938C2DF76C570F6F0ECE5271A7D5A7D6AD66667F53334E27E10E3903EC77`, both semantic-owner-retaining false/non-emitting blank-formal support;
  - B004 preserved them and added no handwritten vtable/layout source; UID0003CY remains verify-only at hash `CC322C8802CD9C812909C92AE6DDD6ABD3A07EB24F759B3A401F86C113ADF823`.
- UID0002LV:
  - executed B002 target remains `92/94`, ordinary hash `70B78AB115846DE326A30CCE90237E07AB59C8F8F1F8E87599CEF5340838C523`;
  - executed B002 report archive hash is `CE8ABAF71D18103594A39F5788828B8839CA8EB066C4024C8366E57597152A8E`;
  - B004 did not modify or preempt it.
- UID0002LX:
  - independent row geometry helper;
  - no target callback delta.
- Shared type/helper pages:
  - exact source-ready declarations/formals remain unchanged at the hashes recorded under Changed Files;
  - no target callback delta occurred.
- IDA status at evidence time was healthy. No IDA label/type/comment mutation was performed.

## Ranked Ownership Analysis

1. **VoteMenuPane class UID0000FX, source file UID0000P6** - very strong.
   - Primary vtable slot, object bounds, OnPaint call order, adjacent VoteMenu methods, class declaration, file route, and generated source all agree.
2. **Shared Pane/GrafPort inherited render surface** - dependency only.
   - `RenderTileFrame` is inherited/shared behavior used by the method; it does not own target source.
3. **ImageLib/ResourceLayoutTable/g_pEPFLib** - dependency only.
   - Supplies frame data; no source ownership transfer.
4. **RightButtonMenuPane / ChattingVarietySelectPane / MenuVarietySelectPane** - comparators only.
   - Separate class-specific vtable methods with duplicated behavior; none owns VoteMenuPane target.
5. **Generic `DrawSubwinTile` helper owner** - rejected.
   - No call target, no declaration, incorrect lookup frequency, and direct duplicated methods contradict it.

## Source Placement

- Primary source placement: `NexusTK/ui/menu/VoteMenuPane.cpp`.
- Declaration remains on UID0000FX `VoteMenuPane`.
- Method definition remains on UID0002LW under class emitter UID0000FX.
- No new source file, header, utility module, or helper page is needed.
- `RightButtonMenuPane.cpp`, Chatting source, and MenuVarietyPanes source contain their own class-specific copies/analogues; comparator similarity does not justify moving VoteMenuPane code.
- Shared dependencies remain in their established render/resource/geometry modules.
- Historical `simroot_v2/class_VoteMenuPane.cpp` is provenance only, not the current route.

## Range / Split / Padding / Reclassification Analysis

- Keep target path/range unchanged.
- No split:
  - one modeled function covers every target byte;
  - all nine blocks belong to one method;
  - no internal padding or separate helper start exists.
- No merge:
  - fifteen `0xcc` bytes separate UID0002LV;
  - fourteen `0xcc` bytes separate UID0002LX.
- No retained raw child:
  - every source operation belongs to the modeled target body.
- No compiler-data child:
  - security-cookie instructions are compiler lowering inside the function, not a separate documentation child.
- Reclassify only source quality:
  - preserve method/source-authored classification;
  - replace pseudo-helper body with exact direct body;
  - raise score after blockers close.
- Raw indentation `Nested:0` is correct and remains unchanged.

## Negative Evidence Summary

- No direct code caller; only vtable data xref.
- No `DrawSubwinTile` function, call target, class declaration, file-local prototype, or accepted support page.
- No helper call inside repeated edge loops except `RenderTileFrame` and `OffsetRect`.
- No resource-layout lookup inside loop back edges.
- No use of `m_visibleBounds.left` or `m_visibleBounds.top` as draw coordinates; historical `m_bounds` is not retained as the current member name.
- No pre-loop dimension check, empty-rect check, clamp, or early return.
- No `for`/while pre-test behavior; each loop body is entered first.
- No tile enum table or switch.
- No context release/destructor call.
- No use of `tileContext.bounds` as the source rectangle; source is explicit 7x7 local bounds.
- No target-owned palette lookup or callback implementation.
- No explicit vptr, RTTI, security cookie, stack frame, or callback pointer in source C++.
- No reason to edit neighboring UID0002LV/UID0002LX, vtable data, ignored padding, or helper support during this target callback; B002-owned UID0001Z1/UID0001WH reclassification is preserved rather than duplicated.

## IDA Rename / Type / Comment Recommendations

- Rename/type target as `VoteMenuPane::DrawBorder`, `void __thiscall VoteMenuPane::DrawBorder()`.
- Apply/retain `VoteMenuPane *this` with inherited `GrafPort::m_visibleBounds`; historical `m_bounds` remains provenance only.
- Type local frame:
  - `EPFTileContext tileContext`;
  - `RectBounds sourceBounds`;
  - `RectBounds destinationBounds`.
- Comment `0x00623044` as primary VoteMenuPane `DrawBorder` slot.
- Comment resource sites:
  - frame 1 top;
  - frame 6 bottom;
  - frame 3 left;
  - frame 4 right;
  - frames 0/2/5/7 corners.
- Comment mode `1`, palette `SUBWIN.PAL`, null options as common GrafPort tile-frame render arguments.
- Keep raw IDA names only as evidence aliases.
- Do not create or rename a `DrawSubwinTile` helper.
- Do not mutate IDA during this report/callback unless separately authorized.

## First-Draft C++ Recommendation

Destination 1 - UID0002LW target. Replace the complete target managed value with exactly:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void VoteMenuPane::DrawBorder()
{
    EPFTileContext tileContext;
    RectBounds sourceBounds;
    RectBounds destinationBounds;

    tileContext.Initialize();
    InitRectBounds(&sourceBounds, 0, 0, 7, 7);

    const int width = m_visibleBounds.right - m_visibleBounds.left;
    const int height = m_visibleBounds.bottom - m_visibleBounds.top;

    destinationBounds = sourceBounds;
    OffsetRect(&destinationBounds, 7, 0);
    g_pEPFLib->LookupLayoutEntry(L"SUBWIN.EPF", 1, &tileContext);
    do
    {
        RenderTileFrame(&tileContext,
                        &sourceBounds,
                        &destinationBounds,
                        1,
                        L"SUBWIN.PAL",
                        NULL);
        OffsetRect(&destinationBounds, 7, 0);
    }
    while (destinationBounds.right < sourceBounds.left + width);

    destinationBounds = sourceBounds;
    OffsetRect(&destinationBounds, 7, height - 7);
    g_pEPFLib->LookupLayoutEntry(L"SUBWIN.EPF", 6, &tileContext);
    do
    {
        RenderTileFrame(&tileContext,
                        &sourceBounds,
                        &destinationBounds,
                        1,
                        L"SUBWIN.PAL",
                        NULL);
        OffsetRect(&destinationBounds, 7, 0);
    }
    while (destinationBounds.right < sourceBounds.left + width);

    destinationBounds = sourceBounds;
    OffsetRect(&destinationBounds, 0, 7);
    g_pEPFLib->LookupLayoutEntry(L"SUBWIN.EPF", 3, &tileContext);
    do
    {
        RenderTileFrame(&tileContext,
                        &sourceBounds,
                        &destinationBounds,
                        1,
                        L"SUBWIN.PAL",
                        NULL);
        OffsetRect(&destinationBounds, 0, 7);
    }
    while (destinationBounds.bottom < sourceBounds.top + height);

    destinationBounds = sourceBounds;
    OffsetRect(&destinationBounds, width - 7, 7);
    g_pEPFLib->LookupLayoutEntry(L"SUBWIN.EPF", 4, &tileContext);
    do
    {
        RenderTileFrame(&tileContext,
                        &sourceBounds,
                        &destinationBounds,
                        1,
                        L"SUBWIN.PAL",
                        NULL);
        OffsetRect(&destinationBounds, 0, 7);
    }
    while (destinationBounds.bottom < sourceBounds.top + height);

    destinationBounds = sourceBounds;
    g_pEPFLib->LookupLayoutEntry(L"SUBWIN.EPF", 0, &tileContext);
    RenderTileFrame(&tileContext,
                    &sourceBounds,
                    &destinationBounds,
                    1,
                    L"SUBWIN.PAL",
                    NULL);

    destinationBounds = sourceBounds;
    OffsetRect(&destinationBounds, width - 7, 0);
    g_pEPFLib->LookupLayoutEntry(L"SUBWIN.EPF", 2, &tileContext);
    RenderTileFrame(&tileContext,
                    &sourceBounds,
                    &destinationBounds,
                    1,
                    L"SUBWIN.PAL",
                    NULL);

    destinationBounds = sourceBounds;
    OffsetRect(&destinationBounds, 0, height - 7);
    g_pEPFLib->LookupLayoutEntry(L"SUBWIN.EPF", 5, &tileContext);
    RenderTileFrame(&tileContext,
                    &sourceBounds,
                    &destinationBounds,
                    1,
                    L"SUBWIN.PAL",
                    NULL);

    destinationBounds = sourceBounds;
    OffsetRect(&destinationBounds, width - 7, height - 7);
    g_pEPFLib->LookupLayoutEntry(L"SUBWIN.EPF", 7, &tileContext);
    RenderTileFrame(&tileContext,
                    &sourceBounds,
                    &destinationBounds,
                    1,
                    L"SUBWIN.PAL",
                    NULL);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination 2 - UID0000FX complete no-loss class block. If the class page is edited, preserve every current declaration, add B002's source-compatible frame-record alias exactly, and do not add a border helper:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
struct PaneMouseEvent;
struct PaneEvent;
struct Rect;
struct EPFTileContext;
typedef EPFTileContext FrameDrawRecord;

class VoteMenuPane : public Pane
{
public:
    VoteMenuPane(int voteType, const wchar_t *targetName);
    virtual ~VoteMenuPane();

protected:
    virtual bool OnMouseEvent(const PaneMouseEvent *event);
    virtual bool OnDismiss(const PaneEvent *event);
    virtual void OnPaint();
    virtual void DrawBackground();
    virtual void DrawBorder();

private:
    enum {
        kPromoteRow = 0,
        kDemoteRow = 1,
        kNoVoteRow = -1
    };

    unsigned char m_voteRowPressed;       // +0xf8
    signed char m_highlightedVoteRow;     // +0xf9
    unsigned char m_reservedFA[2];        // +0xfa..+0xfb alignment
    int m_voteType;                       // +0xfc; constructor context, not row submit flag
    wchar_t m_targetName[0x21];           // +0x100
};

extern VoteMenuPane *g_pVoteMenuPane;

static void GetVoteMenuItemRect(int row, Rect *rect);
static int HitTestVoteMenuItem(int x, int y);
static void SubmitVote(const wchar_t *targetName, unsigned char voteFlag);

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination 3 - UID0001FY aggregate preservation block. If the aggregate is edited for score/prose, preserve the managed body blank:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

No other formal block changes are recommended.

## Final Recommendation

- Destination 1 is implemented exactly and is byte-equal to the generated target definition.
- Destinations 2 and 3 are preserved exactly while bounded prose updates are applied; Destination 2 retains the full class and executed-B002 frame-record alias, while Destination 3 remains blank under the false/non-emitting aggregate state.
- Target source uses direct shared APIs, not a new helper.
- Preserve all existing VoteMenuPane constructor/destructor/input/paint/background/row/packet/global/compiler-wrapper content.
- UID0002LV remains under executed B002 ownership and was not edited by B004. B002 completed first; B004 reread/rebased shared supports before applying the additive delta.
- B002's UID0001WH and UID0001Z1 false/non-emitting support states are preserved. UID0002LX, UID0003CY, ignored padding, EPFTileContext, RectBounds, ResourceLayout lookup, GrafPort RenderTileFrame, and g_pEPFLib remain unchanged.
- All four changed ordinary pages passed scoped validation, and final target waited refresh `000000014433` completed.
- Manual coverage text remains supervisor-owned and is supplied exactly below.

## Recommended Target Doc Changes

Applied to `by-memory/0x00555cf0-0x00556012.VoteMenuPaneDrawBorder.md`:

- Set `COMPLETION:92`.
- Set `CONFIDENCE:94`.
- Preserve:
  - UID0002LW;
  - canonical owner/emitter UID0000FX;
  - reconstructable true;
  - blank optional position;
  - range/title/path;
  - `Nested:0`.
- Replaced the managed formal with Destination 1.
- Replaced Item Summary with full exact facts:
  - 0x322 / 802 bytes;
  - SHA256;
  - 292 instructions / nine blocks;
  - source-void primary virtual;
  - vtable cell and lifecycle;
  - local EPFTileContext plus three RectBounds;
  - exact resource/palette strings;
  - all eight frames;
  - four do loops;
  - local width/height coordinates;
  - exact helper contracts;
  - comparator evidence;
  - rejected pseudo-helper/absolute-coordinate/pre-test alternatives;
  - source route and score cap.
- Preserved old June history explicitly as superseded broad-report provenance, not current source truth.
- Added exact full-byte and padding hashes.
- Added exact generated expectations and no-duplicate/no-compiler-source exclusions.

## Recommended Support Doc Changes

1. `by-class/VoteMenuPane.md` UID0000FX:
   - retained executed-B002 `90/92`;
   - preserved Destination 2 byte-for-byte, including every declaration and the `EPFTileContext`/`FrameDrawRecord` alias;
   - added exact UID0002LW source-ready direct-body summary;
   - recorded that `DrawBorder` uses inherited/shared render/resource/geometry APIs directly and needs no class helper;
   - historicalized `DrawSubwinTile` as a superseded target-only pseudo-abstraction;
   - preserved all unrelated class fields, methods, compiler exclusions, and the complete B002 UID0002LV union, including inherited `m_visibleBounds`.
2. `by-file/VoteMenuPane.md` UID0000P6:
   - retained executed-B002 `91/92`;
   - added exact target source order, resource/frame/loop/helper behavior, local-coordinate correction, and direct source route while preserving B002's EPFTileContext header/FrameDrawRecord alias visibility;
   - preserved complete current source union and no handwritten vtable/RTTI/scalar-wrapper policy;
   - preserved B002's background facts and support reclassification route.
3. `by-memory/0x005558d0-0x0055606d.VoteMenuPaneCore.md` UID0001FY:
   - preserved `90/93`, semantic owner UID0000P6, reconstructable false, blank emitter/position, and non-emitting/index-only disposition;
   - preserved Destination 3 blank;
   - updated only UID0002LW child status to `92/94`, exact source-ready direct body, and no synthetic helper;
   - preserved every range, padding row, child, semantic owner, and no-duplicate policy.
4. B002-owned support state verified/preserved, not duplicated:
   - UID0001Z1 VoteMenuPaneVtables at `90/93`, semantic owner UID0000FX, reconstructable false, blank emitter/position/formal;
   - UID0001WH VoteMenuPaneLayout at `90/92`, semantic owner UID0000FX, reconstructable false, blank emitter/position/formal.
5. Verify-only, no edit because no contradiction appeared:
   - UID0003CY VoteMenuPaneVtableData;
   - UID0002LX GetItemRect;
   - `by-memory/-ignored.md`;
   - EPFTileContext, RectBounds, ResourceLayout lookup, GrafPort RenderTileFrame, and g_pEPFLib support.
6. Explicitly excluded from B004 edits:
   - UID0002LV DrawBackground, owned by the executed B002 callback;
   - RightButtonMenuPane, ChattingVarietySelectPane, and MenuVarietySelectPane comparator pages. Their duplicated bodies are evidence for this target, not B004 callback destinations.

## Score And Metadata Recommendation

| Page | Before B002/B004 callbacks | Current applied | Metadata/formal result | Rationale |
| --- | --- | --- | --- | --- |
| UID0002LW target | `86/90` | `92/94` | owner/emitter/range/position/Nested unchanged; exact formal replaced stale body | Every behavioral/helper/source blocker is closed; only original lexical/macro uncertainty remains. |
| UID0000FX class | `89/91` | `90/92` | complete class formal plus B002 alias preserved | Combined B002/B004 background and border closure is type-compatible without helper invention. |
| UID0000P6 file | `90/90` | `91/92` | file route unchanged | Complete direct background/border source closes resource/helper/source-shape caveats without changing source split. |
| UID0001FY aggregate | `88/91` | `90/93` | semantic owner UID0000P6; false/non-emitting; blank emitter/position/formal | B002 resolved the index-only emission defect; B004 added exact border-child detail without duplicate source. |
| UID0001Z1 | `85/90` | `90/93` B002-owned | semantic owner UID0000FX; false/non-emitting; blank emitter/position/formal | Compiler-generated vtable support is caused by class/method declarations and does not emit. |
| UID0001WH | `87/90` | `90/92` B002-owned | semantic owner UID0000FX; false/non-emitting; blank emitter/position/formal | Class formal emits fields; layout page remains support only. |
| UID0003CY | `87/92` | unchanged | generated-binary formal unchanged | Exact vtable-data page already contains the required slot/lifecycle facts. |
| UID0002LV | `86/90` | `92/94` B002-owned | no B004 target edit | Executed B002 archive and current ordinary page prove the independent completed implementation. |
| UID0002LX | `87/92` | unchanged | unchanged | No target dependency change. |

Why target is not scored higher:

- exact original local variable spellings are unrecoverable;
- direct copy/paste versus macro/header-inline origin cannot be proven;
- numeric frame literals versus original private enum constants cannot be proven;
- exact include/header partition is inferred from current source architecture.

These are lexical/source-history caps, not unresolved runtime behavior.

## Open Questions With Attempted Resolution

1. **Is source return `void`?**
   - Resolution: yes. Current class formal, vtable role, OnPaint call-site use, and three comparator class declarations support `void`. IDA's integer return is untyped final-call residue.
2. **Are draw coordinates absolute pane bounds?**
   - Resolution: no. Target initializes zero-origin bounds and uses only `right-left` / `bottom-top`.
3. **Can edge loops be ordinary `for` loops?**
   - Resolution: not without changing behavior. The binary executes each edge loop once before testing; use `do`.
4. **Does `DrawSubwinTile` exist?**
   - Resolution: no evidence. It is absent from call graph, class/file declarations, support docs, and binary. Its documented per-call load behavior contradicts the target.
5. **Was there an out-of-line shared border helper?**
   - Resolution: no. Four separate vtable bodies and a fifth inline larger-body copy reject an out-of-line helper. Direct duplication is primary; macro/header inline is runner-up.
6. **What are the local types?**
   - Resolution: `EPFTileContext` plus three `RectBounds`, proven by stack size and exact initializer/helper APIs.
7. **What is the resource API?**
   - Resolution: `g_pEPFLib->LookupLayoutEntry(resource, frame, &tileContext)`.
8. **What is the render API?**
   - Resolution: inherited `GrafPort::RenderTileFrame(&tileContext, &sourceBounds, &destinationBounds, 1, palette, NULL)`.
9. **Is a tile context release needed?**
   - Resolution: no observed release and accepted lookup consumers treat this context as borrowed.
10. **Should frame roles use new enums?**
    - Resolution: no. Roles are documented, but numeric literals avoid inventing unrecovered enum declarations.
11. **Does UID0002LV need B004 edits?**
    - Resolution: no. B002 owns it. B002's callback executed first under supervisor command `000000014423`; B004 reread the current archive and resulting union, then left UID0002LV unchanged.
12. **Do comparator pages need edits to make target valid?**
    - Resolution: no. They are evidence only; all target helper/type declarations already exist elsewhere.
13. **Is the inherited bounds member named `m_bounds`?**
    - Resolution: no as current source-facing state. Current GrafPort/Pane layout and B002's fresh target pass resolve `+0x44` as inherited `GrafPort::m_visibleBounds`; `m_bounds` is retained only as a historical alias.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

Final report read-only manual snapshots:

- `by-memory/-coverage-report.md`: SHA256 `6DEF1A277ECC95CFEDBFC95DD8DD1081AEF00D5856046E7949884EEE07B20D56`, 1,788,624 bytes / 4,276 lines; UID0001FY is at line 2900 and UID0002LW is at line 2912. Both rows retain pre-B004 callback wording and require the replacements below.
- `by-class/-coverage-report.md`: SHA256 `CEF7789F454B1D9004DCB9D161215D07EA0D5651B5FDDB0486CFE21095346713`, 231,113 bytes / 622 lines; UID0000FX is at line 593 and retains pre-B004 callback wording.
- `by-file/-coverage-report.md`: SHA256 `147077FED5BD2058174DC029E16668AB772762ABE58C229D6FD1035CFF5AD00D`, 132,779 bytes / 316 lines; UID0000P6 is at line 302 and retains pre-B004 callback wording.
- `by-type/by-struct/-coverage-report.md`: SHA256 `A59DA1DB4C5D4FFA760A2BDD8EA84D49D412D559AD428FCDE03523096EFE9C0C`, 57,240 bytes / 137 lines; UID0001WH is at line 126 and already equals the executed B002 replacement below, so no B004 manual delta remains for this file.
- `by-type/by-vtable/-coverage-report.md`: SHA256 `7AFEEB7F9E6E3691C8D7E91A79AA27353A5E832ABAA83835DDD51E73749771C4`, 65,384 bytes / 142 lines; UID0001Z1 is at line 131 and already equals the executed B002 replacement below, so no B004 manual delta remains for this file.

Supervisor replacement in `by-memory/-coverage-report.md` at current line 2912, between the existing `0x00555ce1-0x00555cf0` and `0x00556012-0x00556020` padding rows:

```text
      - [UID:0002LW][0x00555cf0-0x00556012.VoteMenuPaneDrawBorder](by-memory/0x00555cf0-0x00556012.VoteMenuPaneDrawBorder.md) 0x00555cf0-0x00556012 | method | VoteMenuPaneDrawBorder : reconstructable : 92% : very strong : B004 live MCP proves the exact 0x322-byte, 292-instruction, nine-block source-void primary-vtable VoteMenuPane::DrawBorder method and SHA256 CF50B71B823746310492ED905E454767023DA03B91B3FC1AFFB016996FF91F45; vtable cell 0x00623044 and constructor/ordinary-destructor/scalar-destructor primary-table stores prove liveness. The exact source-ready body initializes one EPFTileContext and zero-origin 7x7 RectBounds, derives local width/height from inherited GrafPort m_visibleBounds, performs one SUBWIN.EPF layout lookup per edge role/corner in frame order 1/6/3/4/0/2/5/7, preserves four mandatory do loops and local corner placement, and calls inherited GrafPort::RenderTileFrame with mode 1, SUBWIN.PAL, and null options. Three separate 0x322 virtual clones plus one larger inline comparator resolve direct copied/header-inlined source as strongest; stale pane-absolute for loops, historical m_bounds naming, and unsupported DrawSubwinTile/per-tile-load prose are superseded. Owner/emitter UID0000FX, source route NexusTK/ui/menu/VoteMenuPane.cpp, exact padding, rejected alternatives, and complete managed C++ are documented.
```

Supervisor replacement in `by-memory/-coverage-report.md` for UID0001FY at current line 2900 after both accepted callbacks:

```text
    - [UID:0001FY][0x005558d0-0x0055606d.VoteMenuPaneCore](by-memory/0x005558d0-0x0055606d.VoteMenuPaneCore.md) 0x005558d0-0x0055606d | aggregate class-method index | VoteMenuPaneCore : ignored : 90% : very strong : Exact non-duplicating VoteMenuPane core index at 90/93 preserves the raw constructor boundary, every exact method child, all internal and successor padding, vtable/helper routes, and source/compiler distinctions while remaining semantic file-owned support with blank formal C++. Exact children carry all source: UID0002LU remains exact 92/94 OnPaint, UID0002LV carries B002's exact 92/94 EPFTileContext/m_drawMode/m_visibleBounds background body, and UID0002LW carries B004's exact 92/94 local-coordinate EPFTileContext/RectBounds SUBWIN border body with four do loops and frames 1/6/3/4/0/2/5/7; the aggregate emits no duplicate body or Empty Emitter Marker.
```

Supervisor replacement in `by-class/-coverage-report.md` for UID0000FX at current line 593 after both accepted callbacks:

```text
- [UID:0000FX][VoteMenuPane](by-class/VoteMenuPane.md) : reconstructable : 90% : very strong : VoteMenuPane at 90/92 remains attached to [UID:0000P6][VoteMenuPane](by-file/VoteMenuPane.md) with its complete Pane-derived declaration, EPFTileContext/FrameDrawRecord compatibility alias, three vtable views, singleton, tail layout, row constants, target name, file-local helpers, class closure before children, and compiler-wrapper exclusions. UID0002LU retains exact direct GrafPort paint behavior; UID0002LV resolves DrawBackground through EPFTileContext::Initialize, g_pEPFLib, inherited m_drawMode/m_visibleBounds, direct one-pixel inset, and DrawTiledBackground; UID0002LW resolves DrawBorder through direct EPFTileContext/RectBounds/layout/render calls, local coordinates, four do loops, and frames 1/6/3/4/0/2/5/7. Historical target-local m_bounds and synthetic clip/fill/resource/DrawSubwinTile helpers are superseded; no cast, border-helper declaration, owner transfer, duplicate body, or handwritten compiler table is introduced.
```

Supervisor replacement in `by-file/-coverage-report.md` for UID0000P6 at current line 302 after both accepted callbacks:

```text
- [UID:0000P6][VoteMenuPane](by-file/VoteMenuPane.md) : reconstructable : 91% : very strong : NexusTK/ui/menu/VoteMenuPane.cpp at 91/92 retains the complete class/method/helper/singleton source split, EPFTileContext header and FrameDrawRecord alias visibility, exact child ranges, packet behavior, SUBWIN resource behavior, compiler-wrapper exclusions, and generated route. UID0002LU preserves exact direct-call OnPaint C++; UID0002LV emits exact source-ready background drawing through EPFTileContext, g_pEPFLib, inherited GrafPort m_drawMode/m_visibleBounds, direct one-pixel inset, and DrawTiledBackground; UID0002LW emits one exact direct SUBWIN border body with local width/height, four mandatory do loops, frames 1/6/3/4/0/2/5/7, one layout lookup per edge role/corner, and inherited RenderTileFrame calls. No cast, synthetic helper, target-local bounds field, duplicate body, or handwritten ABI source is introduced.
```

B002-owned current row in `by-type/by-struct/-coverage-report.md` for UID0001WH at line 126 is already exact and is preserved as no-loss handoff evidence:

```text
- [UID:0001WH][VoteMenuPaneLayout](by-type/by-struct/VoteMenuPaneLayout.md) : ignored : 90% : very strong : Exact VoteMenuPane layout support at 90/92 retains the three view offsets, m_voteRowPressed +0xf8, m_highlightedVoteRow +0xf9, alignment +0xfa..+0xfb, m_voteType +0xfc, m_targetName[0x21] +0x100, row geometry, and normalized secondary-view evidence. Semantic owner remains [UID:0000FX][VoteMenuPane](by-class/VoteMenuPane.md), whose class formal already emits the fields; this layout page is non-reconstructable/non-emitting and produces no duplicate declaration or Empty Emitter Marker.
```

B002-owned current row in `by-type/by-vtable/-coverage-report.md` for UID0001Z1 at line 131 is already exact and is preserved as no-loss handoff evidence:

```text
- [UID:0001Z1][VoteMenuPaneVtables](by-type/by-vtable/VoteMenuPaneVtables.md) : ignored : 90% : very strong : Exact primary/secondary/tertiary VoteMenuPane vtable support at 90/93 with all bases, slot targets, constructor/destructor/scalar-wrapper stores, RTTI/string boundaries, adjustor thunks, and helper distinctions preserved. Semantic owner remains [UID:0000FX][VoteMenuPane](by-class/VoteMenuPane.md), whose class declarations and exact method children regenerate the tables; this compiler-generated cluster is non-reconstructable/non-emitting and produces no handwritten table or Empty Emitter Marker.
```

UID0003CY requires no manual replacement because its score, exact table bytes, source-declared/generated-binary disposition, slot map, and lifecycle facts remain unchanged.

No tracker edit is performed by B004. Validator/supervisor regeneration after accepted implementation owns tracker state.

## Follow-Up Actions

- Supervisor/validator lifecycle state is external and is neither asserted nor directed by this artifact.
- Implementation and validation are complete:
  - B002 UID0002LV/support work completed first and was reread from its executed archive;
  - B004 preserved UID0002LV, UID0001FY, UID0001Z1, and UID0001WH and applied only the additive UID0002LW target/support delta;
  - each ordinary page was leased only for its immediate edit/validator window and released immediately;
  - final target waited validator `000000014433` completed;
  - generated VoteMenuPane.cpp satisfies every C2LW-043 assertion;
  - this report is reconciled claim by claim with 46 terminal ledger rows and a fully checked callback checklist.
- B004 does not edit manual coverage; exact text above is supervisor-owned.
- No implementation item remains. Report validation, execution, count, move, archive, and manual coverage application state remain external supervisor/validator-owned.

## Confidence

- Range/bytes/hash/CFG: very strong.
- Vtable liveness/owner/source route: very strong.
- Tile order, edge/corner behavior, coordinates, and loop form: very strong.
- Local `EPFTileContext`/`RectBounds` types: very strong.
- Shared API identities and argument meanings: very strong.
- Source `void` signature: very strong.
- Direct copied/header-inlined source versus macro origin: strong, with direct statements primary.
- Exact original local names, enum spellings, and includes: medium-high lexical confidence only.
- Overall recommendation: target `92/94`.

## Validator Results

| Command | Timestamp | Scoped file | Exit / ok | Warnings and side effects |
| --- | --- | --- | --- | --- |
| `000000014429` | `2026-07-16T17:17:28-04:00` | `by-memory/0x00555cf0-0x00556012.VoteMenuPaneDrawBorder.md` | `0 / 1` | Updated UID0002LW completion `92`, confidence `94`, autogen registry hash, and projected stats; generated refresh deferred. |
| `000000014430` | `2026-07-16T17:18:12-04:00` | `by-class/VoteMenuPane.md` | `0 / 1` | No target-specific warning; projected stats update and deferred generated refresh. |
| `000000014431` | `2026-07-16T17:18:54-04:00` | `by-file/VoteMenuPane.md` | `0 / 1` | No target-specific warning; projected stats update and deferred generated refresh. |
| `000000014432` | `2026-07-16T17:19:42-04:00` | `by-memory/0x005558d0-0x0055606d.VoteMenuPaneCore.md` | `0 / 1` | No target-specific warning; projected stats update and deferred generated refresh. |
| `000000014433` | `2026-07-16T17:19:55-04:00` | final target `--wait-generated` | `0 / 1` | Generated refresh completed. Broad existing generator diagnostics included 13 fallback child inserts, 85 missing preferred child markers, and 142 emitting-parent-with-no-code notices; none names UID0002LW, UID0000FX, UID0000P6, or UID0001FY as a target-specific failure. |

- Current generated file: `auto-generated/NexusTK/ui/menu/VoteMenuPane.cpp`, header command `000000014433`, refreshed `2026-07-16T17:19:55-04:00`, SHA256 `BD866AF4A339624BEF1890E193109BD092E4A7123C95D5F38D3BBA11A225BA6A`, 11,256 bytes / 359 lines.
- Target block proof: one `VoteMenuPane::DrawBorder()` definition; formal-to-generated byte equality; four `do` loops; eight `LookupLayoutEntry(L"SUBWIN.EPF", ...)` calls; eight `RenderTileFrame` calls; local width/height and all four corner offsets; zero target Empty Emitter Markers; zero `DrawSubwinTile`; zero explicit vptr/RTTI/cookie/callback-pointer/IDA-label/raw-address source inside the body.
- Whole-file unrelated marker accounting: two existing Empty Emitter Markers remain for UID0001G3 scalar deleting destructor and UID0001FZ aggregate helper cluster; neither is UID0002LW.
- Live MCP calls were read-only evidence operations and are not implementation validators.
- B004 ran no report execution, probe, count, revalidation, move, archive, or lifecycle command.

## Changed Files

| Path | Before SHA256 | Current SHA256 | Current bytes / lines | Callback result |
| --- | --- | --- | --- | --- |
| `by-memory/0x00555cf0-0x00556012.VoteMenuPaneDrawBorder.md` | `1D3F948371C7FFB7C672939E8228FAE0C61D3EA4384D595B9D6796DD7158EBD6` | `E0E498CCE219D6ECA5B258F3F51327C12D12B720BC49282D4542517CA4D6435A` | 16,821 / 212 | Applied target `92/94`, Destination 1, exact Item Summary/evidence/history. |
| `by-class/VoteMenuPane.md` | `D94517A8C5872A419006B1BB6E3DB3DC8A1A90E8667FECC1F70AB32AB3EB037F` | `5AA86B00C4AA2B3C1FF578D0D3E83CF4C10E680818E94AA1E251EFA7D7EAAA66` | 25,277 / 254 | Preserved Destination 2/B002 union; added only border evidence and no-helper correction. |
| `by-file/VoteMenuPane.md` | `91C0F3DCD97309FFE4983056F444F860433AFADBA4F53E12541AE96ED12C5605` | `6B688E39C7542B461695BC79404A0DC9BB0E32F191C0FE4F202E4EE409634208` | 22,968 / 209 | Preserved `91/92` and full B002 source union; added exact border route/behavior/history. |
| `by-memory/0x005558d0-0x0055606d.VoteMenuPaneCore.md` | `30EF35FFB91B65C021F418008B44B77732093578F4DF791047AD34A12F3AA3FE` | `BE14FE4DF5A1AD75AF6C6DD577BE42DE019EEE39CB88FAF74AD6B534AE5710E8` | 25,095 / 202 | Preserved `90/93`, false/non-emitting blank Destination 3 and every child/padding row; added exact border child detail. |
| `tools/leaser/Agents/Agent-B004/research/0002LW-VoteMenuPaneDrawBorder-source-quality.md` | accepted Gate 1 SHA256 `DD82D3866C35019AD8AB02EFD50605AEE3C7CD22E79276EEF8784D616EC81CB4` | current callback artifact hash is reported at return | current metrics reported at return | Reconciled C2LW-001..046, validators, generated proof, manual handoff, changed files, and checklist. |

Verify-only current hashes:

- UID0002LV: `70B78AB115846DE326A30CCE90237E07AB59C8F8F1F8E87599CEF5340838C523`.
- UID0001Z1: `08061D4275E25ED6E2D3A776C846FAAF323B925213F0CF9D8A99C71DA1756822`.
- UID0001WH: `FEE4938C2DF76C570F6F0ECE5271A7D5A7D6AD66667F53334E27E10E3903EC77`.
- UID0003CY: `CC322C8802CD9C812909C92AE6DDD6ABD3A07EB24F759B3A401F86C113ADF823`.
- UID0002LX: `01E59A0841457A243D5123ABEF5D5B34CD747D7A9B4CEDBD59EF03C7DD54AD20`.
- `by-memory/-ignored.md`: `C4875C9DB2BAEF070BE1E0EDFE9268918E93596311CA038F6195764F7D1BDFE9`; row 1755 still covers both adjacent spans.
- EPFTileContext: `7EC740D8A5B1FBA0A74EF46A75FBD6B684408E3EC42A939E4A20ABE7D9347F28`.
- RectBounds: `710057507F3BCBAC7528CFC299AC57C6652068EBB24F1CEF06D60C513BAF370E`.
- ResourceLayout lookup: `F5C3CC25ACC5616E03847265AFD0BAF5D4F4CD55EAE28FA4067F23A5ADCA8FB1`.
- GrafPort RenderTileFrame: `E40425DEC34D076538A18B821BBC87F68323894672AC29F267B0A0E902A15256`.
- g_pEPFLib: `871E781E5291FE7021819AE007482C3587943F132F70AF49211949271BD02157`.

- No manual coverage file was edited; the exact current handoff remains under its required section.
- Generated/tracker/projected-stat/registry outputs changed only through the authorized validators, not manual edits.
- No audit, supervisor, validator-state, lifecycle, archive, queue, lock, or IDA file was manually edited.
- Leases used serially: target, class, file, aggregate. Each was released immediately after its scoped validator; `B004: No active leases` was confirmed after final validation.

## Implementation Tracking Checklist

Callback implementation and terminal proof:

- [x] Supervisor Gate 1 accepted exact pre-callback SHA256 `DD82D3866C35019AD8AB02EFD50605AEE3C7CD22E79276EEF8784D616EC81CB4`.
- [x] Re-read the accepted report immediately before callback work.
- [x] Re-read executed B002 UID0002LV archive SHA256 `CE8ABAF71D18103594A39F5788828B8839CA8EB066C4024C8366E57597152A8E` before shared support edits.
- [x] Preserved B002 evidence-time SHA history through sample `473E6D691168F2641A4845EEABD8D96507E14DD07F74BCAA6832C45198061AF9` as historical only and pinned the current executed archive.
- [x] Followed serialization: B002 completed first; B004 reread/rebased second.
- [x] Preserved B002 ownership of UID0002LV and did not edit its target.
- [x] Re-read every destination immediately after acquiring its short lease.
- [x] Applied C2LW-001 through C2LW-046 claim by claim.
- [x] Kept every claim Verification state legal and terminal after callback.
- [x] Preserved target UID/path/range/title.
- [x] Preserved target owner/emitter UID0000FX.
- [x] Preserved target reconstructable true.
- [x] Preserved target blank optional emitter position.
- [x] Preserved target `Nested:0`.
- [x] Changed target score `86/90 -> 92/94`.
- [x] Replaced target Item Summary with full exact evidence.
- [x] Installed Destination 1 exactly inside the managed header.
- [x] Removed `DrawSubwinTile` from current formal/generated source and retained it only as superseded history.
- [x] Historicalized the June pseudo-helper recommendation without deleting provenance.
- [x] Preserved exact 802-byte range and SHA256 evidence.
- [x] Preserved exact 292-instruction/nine-block evidence.
- [x] Preserved source-void primary virtual decision.
- [x] Preserved vtable cell `0x00623044` and primary lifecycle stores.
- [x] Preserved no-direct-caller virtual-dispatch reasoning.
- [x] Preserved local zero-origin coordinate correction.
- [x] Preserved inherited `m_visibleBounds` width/height derivation and historicalized `m_bounds`.
- [x] Preserved one EPFTileContext plus three RectBounds stack-type evidence.
- [x] Preserved exact frame order `1/6/3/4/0/2/5/7`.
- [x] Preserved top edge lookup/loop semantics.
- [x] Preserved bottom edge lookup/loop semantics.
- [x] Preserved left edge lookup/loop semantics.
- [x] Preserved right edge lookup/loop semantics.
- [x] Preserved all four corner placements.
- [x] Preserved all four mandatory `do` loops.
- [x] Preserved no dimension guard/clamp behavior.
- [x] Preserved one layout lookup per edge role/corner, not per repeated tile.
- [x] Preserved mode 1, SUBWIN.PAL, and null options.
- [x] Preserved no explicit tile-context release.
- [x] Preserved compiler-cookie exclusion.
- [x] Preserved exact predecessor/successor padding and hashes.
- [x] Preserved the three external standalone-clone comparators plus target-equivalence evidence.
- [x] Preserved larger inline comparator evidence.
- [x] Preserved direct-copy/header-inline primary and macro runner-up ranking.
- [x] Preserved rejected absolute-coordinate/pre-test/helper alternatives.
- [x] Re-read/rebased UID0000FX under a short lease after executed B002.
- [x] Preserved UID0000FX at current `90/92`.
- [x] Preserved Destination 2 complete class formal exactly, including `struct EPFTileContext; typedef EPFTileContext FrameDrawRecord;`.
- [x] Added no `DrawSubwinTile` declaration.
- [x] Preserved all unrelated class fields/methods/helpers/compiler exclusions.
- [x] Re-read/rebased UID0000P6 under a short lease after executed B002.
- [x] Preserved UID0000P6 at current `91/92`.
- [x] Preserved the complete current VoteMenuPane source union.
- [x] Re-read/rebased UID0001FY under a short lease after executed B002.
- [x] Preserved UID0001FY `90/93`, semantic owner UID0000P6, reconstructable false, blank emitter/position/formal, and non-emitting index disposition.
- [x] Preserved Destination 3 aggregate formal blank.
- [x] Preserved every aggregate child/range/padding/no-duplicate fact.
- [x] Verified/preserved B002-owned UID0001Z1 `90/93`, semantic owner UID0000FX, false/non-emitting, blank emitter/position/formal.
- [x] Verified UID0003CY unchanged.
- [x] Verified UID0002LX unchanged.
- [x] Verified/preserved B002-owned UID0001WH `90/92`, semantic owner UID0000FX, false/non-emitting, blank emitter/position/formal.
- [x] Verified `by-memory/-ignored.md` unchanged and both padding rows present.
- [x] Verified EPFTileContext support unchanged.
- [x] Verified RectBounds support unchanged.
- [x] Verified ResourceLayout lookup support unchanged.
- [x] Verified GrafPort RenderTileFrame support unchanged.
- [x] Verified g_pEPFLib support unchanged.
- [x] Leased only one ordinary page at a time.
- [x] Ran one scoped validator for every changed ordinary page while leased.
- [x] Recorded every validator command ID, timestamp, exit, ok, warnings, and side effects.
- [x] Released each ordinary lease immediately after its validation window.
- [x] Ran final authorized target validator `000000014433` with `--wait-generated`.
- [x] Verified exactly one UID0002LW generated definition.
- [x] Verified zero UID0002LW Empty Emitter Markers.
- [x] Verified zero `DrawSubwinTile` tokens in current generated VoteMenuPane.cpp.
- [x] Verified exactly four `do` loops in the target body.
- [x] Verified eight `LookupLayoutEntry(L"SUBWIN.EPF", ...)` target sites.
- [x] Verified eight static target `RenderTileFrame` sites.
- [x] Verified local width/height coordinates and four corner offsets.
- [x] Verified no explicit vptr/RTTI/cookie/callback-pointer/IDA-label/raw-address source in the target body.
- [x] Verified no duplicate target body in class/file/aggregate.
- [x] Re-read current manual by-memory/class/file/struct/vtable coverage.
- [x] Preserved exact supervisor-owned manual handoff with current hashes/anchors.
- [x] Verified the B002-owned by-struct UID0001WH row is already exact; no B004 manual delta remains there.
- [x] Verified the B002-owned by-vtable UID0001Z1 row is already exact; no B004 manual delta remains there.
- [x] Updated this report's Current Target State after callback.
- [x] Updated all ledger rows to legal callback terminal states with destination proof.
- [x] Populated Validator Results with exact commands/results.
- [x] Populated Changed Files with exact paths/hashes.
- [x] Checked implementation rows only after independent readback proof.
- [x] Confirmed no ordinary lease remains.
- [x] Confirmed B004 did not manually edit manual coverage/generated/tracker/audit/supervisor/validator/lifecycle/IDA state.
- [x] Confirmed B004 did not run or probe `execute_report` or any lifecycle/count/revalidation/move/archive command.

READY_FOR_SUPERVISOR_EXECUTE

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000014462","destination_path":"executed-b-agent-research/B004/0002LW-VoteMenuPaneDrawBorder-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B004/research/0002LW-VoteMenuPaneDrawBorder-source-quality.md","timestamp":"2026-07-16T17:47:22-04:00","uid":"0002LW"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
