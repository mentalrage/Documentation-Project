** TARGET-REPORT-UID:0002LU **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **

# UID0002LU VoteMenuPaneOnPaint Source-Quality Report

## Finalized Report / Current Recommendation

UID0002LU is live source-authored `VoteMenuPane::OnPaint` code, not compiler glue, dead code, a raw helper, or a data range. The implemented target remains `0x00555af0-0x00555c68`, size `0x178` / 376 bytes, with direct class owner/emitter UID0000FX and source route UID0000P6 `NexusTK/ui/menu/VoteMenuPane.cpp`.

The accepted callback is complete. UID0002LU is now `92/94` with exact R1 and preserved owner/emitter/range/position/nesting; UID0000FX is `89/91`; UID0000P6 is `90/90`; UID0001FY remains `88/91` with its blank non-duplicating formal and complete child/padding inventory. The former synthetic `DrawShadowedCenteredText` and `DrawVoteMenuHighlight` body is historicalized, and waited generated command 13386 emits the direct inherited GrafPort sequence exactly once.

Implementation result:

- UID0002LU preserves `CANONICAL_OWNER:0000FX`, `EMITTER_UIDS:0000FX`, `RECONSTRUCTABLE:TRUE`, blank optional position, `Nested:0`, title, path, and exact range;
- target, class, file, and aggregate incorporate C01-C20 at destination-appropriate report depth without unrelated-content loss;
- target/report/generated R1 normalized code SHA256 is identically `74E1845EE78367A2582A22851AFC077C02A8D5C063D69855037B03EC4FD06CEB`;
- the complete verify-only set was reread and remained compatible, so no scope expansion occurred;
- scoped validators 13377, 13380, 13381, and 13383 passed, followed by waited generated command 13386;
- B003 edited no manual coverage, generated, tracker, audit, supervisor, validator-state, lifecycle, archive, or IDA file and invoked no report execution/lifecycle command.

Artifact validation, execution, count, path, move, and archive state remain external supervisor/validator-owned and are neither asserted nor directed by this artifact. No B003 implementation item remains.

## Supporting Research

Required process material read:

- `tools/leaser/Agents/Agent-B003/goal.md`;
- project skill `ntk-b-agent-workflow/SKILL.md`;
- `references/b-agent-research-and-implementation-workflow.md`;
- `references/b-agent-report-template.md`;
- current target, class, file, aggregate, layout, vtable, string-data, row-rectangle, and GrafPort helper documentation;
- read-only generated `auto-generated/NexusTK/ui/menu/VoteMenuPane.cpp`;
- current manual by-memory, by-class, and by-file coverage rows.

Historical-report search used the exact terms `UID0002LU`, `VoteMenuPaneOnPaint`, `0x00555af0`, `DrawVoteMenuHighlight`, and `DrawShadowedCenteredText` against each required root:

| Root | Exact outcome | Classification |
| --- | --- | --- |
| `executed-b-agent-research/**` | Three matches: B003 `0002LR-...-votemenupane-source-quality.md`, B003 `0001FY-VoteMenuPaneCore-source-quality.md`, and B014 `0000FX-VoteMenuPane-class-source-quality.md`. | Relevant historical leads, independently revalidated below. |
| `archived/**` | No match. | No additional target evidence. |
| `tools/leaser/Agents/Older-Research/**` | No match. | No additional target evidence. |
| `tools/leaser/Agents/SpecialReports/**` | No match. | No additional target evidence. |
| `tools/leaser/Agents/**` | Only the current B003 goal matched. | No active report collision or competing target assignment found. |

Target-specific classification of the three executed matches:

- The older B003 ten-target VoteMenuPane report established the correct owner, source file, row fields, labels, row helper, and source-authored disposition. Its `DrawShadowedCenteredText` and `DrawVoteMenuHighlight` recommendation was explicitly descriptive and is now superseded because fresh MCP and completed GrafPort support expose the real direct calls.
- The B003 UID0001FY report governs the aggregate's non-duplicating formal policy and exact child inventory. It does not independently validate the current target C++ body; it remains useful support for the unchanged parent range and route.
- The B014 UID0000FX report established the class declaration, row constants, tail fields, class-before-children ordering, and UID0000P6 source route. It did not validate either synthetic drawing helper. Its class-shape conclusions remain compatible with R1 because all called drawing methods are inherited GrafPort APIs.

A second target-triggered comparator search for `0x00481490`, `sub_481490`, `ChattingVarietySelectPaneOnPaint`, `SetDrawColor`, and `LineTo` found B003's executed Chatting selector report and current UID0002FL. Fresh MCP then independently compared that six-row paint body with UID0002LU. The comparator inlines the same MoveTo/DrawWideText and split-color four-edge frame pattern, but uses six labels, a different label offset, a different row helper, inset `4`, and right adjustment `9`. It supports a copied/shared source idiom, not a callable cross-class helper or owner transfer.

## Target

- UID: `0002LU`.
- Ordinary page: `by-memory/0x00555af0-0x00555c68.VoteMenuPaneOnPaint.md`.
- Documentation title: `VoteMenuPaneOnPaint`; source-facing method: `VoteMenuPane::OnPaint`.
- Exact half-open range: `[0x00555af0,0x00555c68)`.
- Exact size: `0x178` / 376 bytes.
- Full target byte SHA256: `DAB99C735A0B92A28079F49EE87A9493532F52DEF4CDDD3DFFAEE16FB46AE4DB`.
- Pre-callback page SHA256 at evidence collection: `30BDD2A0983120DF6CE5DB91329B44DD97A7627757AEC41F44FCAF2456C64276`; implemented SHA256: `79C9CEFF1DD1F5C51B8B1909F5D4B5854DB81F0A35AEE49F9E496E5BB3B82331`.
- Implemented metadata: `92/94`, `CANONICAL_OWNER:0000FX`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000FX`, blank optional position, `Nested:0`.
- Current file route: UID0000FX through UID0000P6, `NexusTK/ui/menu/VoteMenuPane.cpp`.
- Current IDA name: `sub_555AF0`.
- Rename disposition: none at the documentation-path level; source/IDA-facing name is `VoteMenuPane::OnPaint`.

## Current Target State

The implemented target page records the exact range/hash/CFG, primary-vtable ownership, Promote/Demote literals, signed `+0xf8/+0xf9` state reads, row-rectangle helper, direct inherited drawing APIs, palette-edge roles, exact geometry, source-void ABI, historical correction, negative evidence, and eight-byte successor padding. Metadata is `92/94`, owner/emitter UID0000FX, reconstructable true, blank optional position, and `Nested:0`.

Historical pre-callback generated snapshot: external command 13366 at `2026-07-15T18:12:05-04:00`, SHA256 `3A44645CB36CF912013B890F7E86CADE6801C2C9D6DDE22DAD8778103944A51B`, contained one target body with two `DrawShadowedCenteredText` calls and one `DrawVoteMenuHighlight` call. It is retained only as evidence of the defect replaced by this callback.

Waited callback snapshot:

- path `auto-generated/NexusTK/ui/menu/VoteMenuPane.cpp`;
- validator command `000000013386`, refreshed `2026-07-15T18:53:57-04:00`;
- SHA256 `8ECF7F395B6DA7BD00B49B99999C2ADD2AE8A435BDE2E0F07A27E40BFE1DEE18`, `8,559` bytes, `280` lines;
- class closes at line 37 before UID0002LU definition at line 116;
- target/report/generated R1 are byte-for-byte equal after LF normalization, SHA256 `74E1845EE78367A2582A22851AFC077C02A8D5C063D69855037B03EC4FD06CEB`;
- static target calls are five `MoveTo`, four `DrawWideText`, four `SetDrawColor`, and six `LineTo`; each runtime branch executes two color changes and four line edges;
- one UID0002LU header and one `VoteMenuPane::OnPaint` definition; zero target Empty Emitter Markers, synthetic helper calls, duplicate/wrong-range bodies, or target raw-address source;
- five unrelated family Empty Emitter Markers remain for UID0001G3, UID0001WH, UID0001Z1, UID0001FY, and UID0001FZ; they were not broadened into this callback;
- no handwritten vtable/RTTI arrays, cookie calls, or compiler scaffolding occur in the target source body.

Command 13386 is B003's bounded waited callback verification epoch. A later read-only external refresh advanced the header to command `000000013397` at `2026-07-15T19:04:00-04:00`, SHA256 `BDFB7E442339AE457064659A233F213B63EAB344E821D05D965BD514749CB420`, while retaining `8,559` bytes / `280` lines, R1 parity, one target definition, zero target/synthetic markers, five unrelated markers, and every semantic assertion above. That later header epoch was not issued by B003 and does not change the callback proof; neither checkpoint is asserted as indefinite future state.

## Executive Recommendation

The implemented target replaces the synthetic abstraction with direct inherited GrafPort calls and preserves the exact machine order:

1. call the two class virtuals at primary slots `+0x48` and `+0x4c`, currently `DrawBackground` then `DrawBorder`;
2. compute signed C++ midpoint division from bounds and subtract `24`;
3. draw each seven-character label twice, offset one pixel only in x;
4. accept only highlighted rows `0` and `1`;
5. obtain the fixed row rectangle through UID0002LX;
6. begin at `(left+5,bottom)`;
7. draw left and top edges with color `128` when pressed or `143` when not pressed;
8. switch color to `143` when pressed or `128` when not pressed;
9. draw right and bottom edges and finish at the starting point.

Do not invent shade names for palette entries 128/143, do not call the frame nested/outer/inner, do not replace the direct text calls with `DrawOutlinedText`, and do not factor the duplicated cross-class paint idiom into an unproved helper.

## Supervisor Active Recheck

Implemented ordinary state after scoped validation:

| Destination | SHA256 | Current role |
| --- | --- | --- |
| UID0002LU target | `79C9CEFF1DD1F5C51B8B1909F5D4B5854DB81F0A35AEE49F9E496E5BB3B82331` | Implemented `92/94`, exact R1 and full target evidence; validator 13377 passed. |
| UID0000FX class | `0FD33C3C5CCF4A8C1525FA53DD23B364CD3C590DEC4970E34E8BFBDB0A6F3DC8` | Implemented `89/91` bounded OnPaint sync; formal preserved at SHA256 `6B3D8363704BA1E813F096DA61DC76421C420A4C0524BECC4F31A8F26E980817`; validator 13380 passed. |
| UID0000P6 file | `70271629FDD251F9502817E714CF7FD8396D3B1D35E7C8BAEFFC72D2B7C63977` | Implemented `90/90` source-ready inventory/dependency/history sync; validators 13381 and final waited 13386 passed. |
| UID0001FY aggregate | `B0BF64850E66BD5EDBEB2525A2EE1B08D90B0B7C6A01763068BCD85AD6B6A865` | Implemented target-only inventory sync; `88/91`, formal, children, padding, owner/emitter, and nesting preserved; validator 13383 passed. |
| UID0002LX row helper | `01E59A0841457A243D5123ABEF5D5B34CD747D7A9B4CEDBD59EF03C7DD54AD20` | Exact helper and geometry, verify-only. |
| UID0001WH layout | `CA5AD94A4E3524CC376DDB4BFD872C62092EAECD6B25160E9448C5F384C1D629` | Exact `+0xf8/+0xf9` field roles, verify-only. |
| UID0003CY vtable data | `CC322C8802CD9C812909C92AE6DDD6ABD3A07EB24F759B3A401F86C113ADF823` | Compiler data and exact slot context, verify-only. |
| UID0003D0 strings | `F71C627B7CB90713A158B365DB78750B577A9F9ABD3D9922A7C6ADC98E20C707` | Literal-data support, verify-only. |

The full verify-only set was reread after implementation. Its target-relevant hashes/facts remained compatible with R1, including UID0002LX `01E59A...AD20`, UID0001WH `CA5AD9...D629`, UID0001Z1 `7FE50F...ADF0`, UID0003CY `CC322C...F823`, UID0003D0 `F71C62...C707`, UID000162 `0A77A4...5795`, UID0004H4 `228DD5...228E`, UID00016C `55890F...1F29`, UID00005V `F1AD63...053C`, Pane `B9686C...AC10`, UID0002LT, UID0002LV, ignored padding, UID0002FL, and Chatting class/file support. No contradiction or scope expansion was required.

B003 used one short ordinary lease at a time, reread each destination after acquisition, validated it, and released immediately. UID0000P6 was briefly leased again for the final waited validator. Zero B003 leases remained at callback reconciliation.

## Inference Research Guidance Check

The recommendation follows the project inference mandate:

- Binary facts are separated from source-shape inference.
- Existing descriptive names were treated as hypotheses, not inherited authority.
- Shared helper identity was established from exact helper bodies and current canonical docs, not caller-biased generated names.
- The near-duplicate Chatting selector body was used as a comparator, not as proof of common ownership or an invented helper.
- Exact source names without symbol evidence remain descriptive and cap confidence rather than blocking a complete source-ready body.
- Compiler cookie handling and Hex-Rays' incidental byte return are excluded from human source.
- No modern abstraction, lambda, template, raw address, manual vtable, or decompiler artifact is introduced.
- The source shape remains plausible for the late-1990s/mid-2000s codebase: direct method calls, local rectangle coordinates, integer constants, and ordinary branching.

## Heuristic / Inference Reanalysis And Validation

| Question | Evidence checked | Best supported resolution | Rejected alternatives and impact |
| --- | --- | --- | --- |
| What are `0x004b9600`, `0x004b9660`, `0x004b98f0`, and `0x004bab70`? | Fresh decompile/profile plus UID000162, UID0004H4, UID00016C. | `GrafPort::MoveTo`, `GrafPort::SetDrawColor`, `GrafPort::LineTo`, and `GrafPort::DrawWideText`. | Feature-local helpers and raw `sub_*` spellings are rejected. All target call blockers close. |
| Is the label helper centered or outlined? | Exact four call sites and comparator `0x00481490`. | Direct seven-character `DrawWideText` calls at x and x+1, same y, after midpoint minus 24. | `DrawShadowedCenteredText` and `DrawOutlinedText` are behaviorally wrong. |
| What does `+0xf9` mean? | Constructor `0xff`, OnMouseEvent writes hit-test result, layout, target unsigned machine compare. | Signed highlighted-row byte with `-1` sentinel; source accepts exactly row 0 or 1. | Boolean and unsigned no-sentinel models are rejected. |
| What does `+0xf8` mean? | Constructor clear, mouse press/release state, target branch. | Byte-backed pressed/captured state that reverses bevel colors. | Selected-row index and generic flag-only wording are rejected. |
| Are 128/143 RGB values or palette roles? | `SetDrawColor` writes active draw color; line callback consumes it; many UI frame callers use the same values. | Exact active palette/draw-color indices. The target proves edge orientation, not human shade names. | `outerColor`, `innerColor`, `light`, and `dark` are not claimed as original semantics. |
| What is the exact frame geometry? | Stack rectangle reconstruction, UID0002LX geometry, direct MoveTo/LineTo sequence. | Begin bottom-left at `left+5`; draw left/top to `right-5`; change color; draw right/bottom back to start. | A filled selection, two nested rectangles, and full-width row border are rejected. |
| Does `LineTo` update the cursor? | UID0004H4 and Surface callback contract. | Wrapper sends deltas from the current cursor; the callback owns line drawing/cursor advancement semantics, matching sequential endpoints. | Direct raw callback calls and manual cursor writes are rejected. |
| Is target return type byte or void? | Primary OnPaint slot, class declaration, plain `ret`, no source return use, tail-call result artifact. | Source return type is `void`; Hex-Rays' `unsigned char` is incidental last-call AL propagation. | Returning row/color/LineTo result is rejected. |
| Is a common highlight helper justified by comparator `0x00481490`? | Full comparator decompile and current UID0002FL docs. | No. Both methods inline the pattern and differ in labels, row count, center offset, row helper, inset, and width adjustment. Direct source statements are safest. | Callable common helper, cross-class ownership, or unproved inline macro are rejected. |
| Are inherited calls source-accessible? | Target is a derived Pane method; shared GrafPort helpers have broad pane caller fan-in and class ownership. | The original declaration must expose them to derived panes as public/protected or equivalent. R1 uses normal inherited calls. | Private-access failure does not justify synthetic wrappers. |
| Does no direct caller imply dead code? | One vtable cell points to target; three lifecycle xrefs install/restore each VoteMenuPane view. | No. Virtual dispatch is the live route. | Dead source, no-owner, and covered-by/no-code dispositions are rejected. |

## Evidence Standards Used

- Direct IDA facts: exact bytes, ranges, instruction count, basic blocks, vtable pointer values, xrefs, helper calls, constants, and raw string bytes.
- Documentation facts: accepted owner/file route, class layout, canonical GrafPort method names, current row-helper contract, and current generator snapshot.
- Strong inference: source `void`, descriptive local names, direct-call source shape, and copied paint idiom rather than an unproved helper.
- Negative evidence: no direct code caller, no synthetic helper contract, no exact duplicate body, no raw source symbol, and no evidence for shade names.
- Historical evidence: old executed reports are retained only where fresh target evidence agrees; synthetic helper conclusions are explicitly superseded.

## Evidence Checked

Fresh MCP database evidence at `2026-07-15T18:08-18:15-04:00`:

- `idb_list` returned one active/adopted/owned NexusTK IDB session `64c11373`, worker PID `21508`.
- `server_health(database=64c11373)` returned `status:ok`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, and strings cache ready with 2067 entries.
- Bounded `get_bytes` returned real target, predecessor, successor, vtable-cell, and string bytes.
- `lookup_funcs`, `func_profile`, `basic_blocks`, `decompile`, `callees`, `xrefs_to`, `get_int`, and `find_bytes` succeeded for the target and bounded dependencies.
- No valid bounded MCP call used by this report failed or timed out.

Current documentation checked:

- UID0002LU target, UID0000FX class, UID0000P6 file, UID0001FY parent, UID0002LX row helper, UID0001WH layout, UID0001Z1 vtable inventory, UID0003CY vtable data, UID0003D0 strings;
- UID000162 GrafPort draw-state accessors, UID0004H4 LineTo, UID00016C text-run helpers, UID00005V GrafPort, UID0000A2 Pane;
- predecessor UID0002LT, successor UID0002LV, ignored padding, and generated VoteMenuPane source;
- manual by-memory, by-class, and by-file coverage rows.

Historical and comparator evidence checked:

- the three exact historical-report matches listed under Supporting Research;
- UID0002FL current page and B003 executed Chatting selector report after the fresh signature comparator was discovered;
- B013 Chatting string-data report only for its independently established principle that direct consumer literals, not a raw combined data object, are the plausible source shape.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state | Implementation proof |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C01 | Database `64c11373` was healthy at evidence collection and all valid bounded target calls succeeded. | Very strong | Fresh list, health, target bytes and analyses. | UID0002LU Evidence; report MCP sections | incorporate | applied | UID0002LU records the bounded healthy-session provenance; target validator 13377 passed, exit 0 / ok 1. |
| C02 | UID0002LU is exactly `[0x00555af0,0x00555c68)`, `0x178` / 376 bytes, SHA256 `DAB99C735A0B92A28079F49EE87A9493532F52DEF4CDDD3DFFAEE16FB46AE4DB`. | Very strong | Full bytes/local SHA, lookup/profile. | UID0002LU range, summary, evidence | incorporate | applied | Exact range/size/hash are in target SHA `79C9CEFF...2331`; validator 13377. |
| C03 | The target is one 137-instruction, six-basic-block method; it must not split. | Very strong | func_profile/basic_blocks. | UID0002LU range/CFG; UID0001FY inventory | incorporate | applied | Target and UID0001FY SHA `B0BF6485...A865` record one six-block child/no split; validators 13377/13383. |
| C04 | The source signature is `void VoteMenuPane::OnPaint()`; Hex-Rays' byte return is a last-call artifact and the security cookie is compiler-only. | Strong | Vtable contract, class declaration, epilogue, decompile. | UID0002LU ABI/source notes | reject-invalid | applied | Target Source ABI section rejects byte-return/cookie source; generated R1 is void with no cookie code. |
| C05 | Primary vtable cell `0x0062303c` contains `0x00555af0`; no direct code caller is expected for this live virtual. | Very strong | get_int, bytes, xrefs; vtable lifecycle xrefs. | UID0002LU reachability; UID0000FX/UID0001FY support | incorporate | applied | Target/class/aggregate record slot/data/no-static-caller lifecycle route; validators 13377/13380/13383. |
| C06 | Target first calls primary slots `+0x48`/`+0x4c`, current source-facing `DrawBackground` then `DrawBorder`. | Very strong | Disassembly/decompile and current class/vtable docs. | UID0002LU behavior/R1 | incorporate | applied | Exact R1 begins with those calls; parity SHA `74E1845E...6CEB`; validator 13377/generated 13386. |
| C07 | Label x is `(left+right)/2 - 24`; each seven-character label is drawn twice at x and x+1 with the same y. | Very strong | Exact integer sequence and four call pairs. | UID0002LU behavior/R1 | reject-stale | applied | Target historicalizes unadjusted midpoint and emits four exact passes; generated static counts 5 MoveTo/4 DrawWideText. |
| C08 | Literal bytes are exact UTF-16LE `Promote` and `Demote`, with two target xrefs to each. | Very strong | Raw 32 bytes and xrefs. | UID0002LU evidence/R1 | incorporate | applied | Target records all four xrefs/complete strings and R1 emits both length-7 literals twice. |
| C09 | `+0xf9` is signed `m_highlightedVoteRow`; only source rows 0 and 1 paint, while `-1` and all other values do not. | Very strong | Constructor/mouse/layout plus target compare. | UID0002LU behavior/R1; class support | already-present | already-present | UID0000FX formal/UID0001WH already supplied signed field/constants; target R1 now consumes them exactly. |
| C10 | UID0002LX is the sole row-rectangle callee and returns fixed row geometry; target consumes it with five-pixel horizontal inset. | Very strong | Helper decompile/xrefs and target math. | UID0002LU/R1; UID0001FY support | incorporate | applied | Target/aggregate record sole edge `0x00555b9f` and `left+5/right-5`; UID0002LX reread unchanged. |
| C11 | `+0xf8` is `m_voteRowPressed`; pressed uses 128 for left/top and 143 for right/bottom, unpressed reverses them. | Very strong | Branch/call order and current layout. | UID0002LU behavior/R1; class support | incorporate | applied | Target/class record exact field/edge roles; generated R1 has four static color calls, two per runtime branch. |
| C12 | Exact inherited helper identities are `MoveTo`, `DrawWideText`, `SetDrawColor`, and `LineTo`. | Strong | Fresh helper analyses and canonical helper pages. | UID0002LU dependencies/R1; UID0000FX/UID0000P6 support | incorporate | applied | All three destinations name direct inherited APIs; canonical UID000162/4H4/16C/05V reread compatible; validators 13377/13380/13381. |
| C13 | `DrawShadowedCenteredText`, `DrawVoteMenuHighlight`, and outer/inner color semantics are unsupported and were removed from current source. | Very strong | No helper body/declaration; exact direct sequence. | UID0002LU formal/history; class/file prose | reject-invalid | applied | Target/class/file historicalize the abstractions; generated command 13386 contains zero occurrences. |
| C14 | The older B003 synthetic-helper recommendation remains useful history but is superseded by current canonical helper evidence. | Very strong | Executed report and fresh MCP/support pages. | UID0002LU Changes/History; support prose | historicalize | applied | Target Reconstruction Notes/Changes and class/file evidence retain it explicitly as superseded provenance. |
| C15 | The Chatting selector comparator proves an inline source idiom, not a callable shared helper or ownership transfer. | Strong | Full `0x00481490` comparison and distinct constants/helpers. | UID0002LU heuristic/negative evidence | reject-invalid | applied | Target/class/file preserve comparator distinctions and reject shared-helper/owner transfer; UID0002FL/Chatting reread unchanged. |
| C16 | Preserve UID/title/path/range/owner/emitter/true/blank position/Nested0; raise target `86/90 -> 92/94` and apply exact R1. | Very strong | C01-C15 blocker closure. | UID0002LU metadata/formal/summary | incorporate | applied | Target metadata is exact; report/target/generated R1 parity SHA `74E1845E...6CEB`; validator 13377. |
| C17 | UID0000FX remains owner and UID0000P6 remains source route; bounded target evidence supports `88/90 -> 89/91` and `89/88 -> 90/90`, with class formal unchanged. | Strong | Current class/file plus exact target source closure. | UID0000FX and UID0000P6 prose/scores | incorporate | applied | Class/file hashes `0FD33C3C...3DC8`/`70271629...3977`; validators 13380/13381; class formal hash unchanged `6B3D8363...0817`. |
| C18 | UID0001FY remains `88/91`, same route and blank aggregate formal; only the target inventory/source-quality prose synchronizes. | Very strong | Exact child model and anti-duplication policy. | UID0001FY inventory/evidence | incorporate | applied | Aggregate hash `B0BF6485...A865`; validator 13383; metadata/formal/children/padding unchanged. |
| C19 | UID0002LX, UID0001WH, UID0001Z1, UID0003CY, UID0003D0, UID000162, UID0004H4, and UID00016C remain verify-only because current facts support R1 without contradiction. | Strong to very strong | Current docs plus fresh MCP. | Verify-only set; report checklist | already-present | already-present | Complete verify-only set reread after implementation; hashes/contracts remained compatible and no page was edited. |
| C20 | Manual target/parent/class/file coverage rows are stale and require exact supervisor-owned replacements; B003 must not edit them. | Very strong | Direct coverage readback. | Exact coverage section | incorporate | applied | Current rows reread at by-memory 2842/2850, class 593, file 302; exact handoff retained; zero manual coverage edits by B003. |

## Positive Evidence Summary

- Complete target bytes, exact 376-byte SHA, 137 instructions, and six basic blocks.
- Unique 32-byte semantic signature at `0x00555b08`; the shorter generic prologue also occurs at `0x00481490` and was not misreported as unique.
- Primary vtable cell `0x0062303c` points exactly to the target.
- Primary/secondary/tertiary vtable bases each have constructor, ordinary-destructor, and scalar-destructor lifecycle xrefs.
- Four exact label passes and raw UTF-16 strings.
- Exact row-state fields with constructor/mouse-handler corroboration.
- Sole row helper call and complete row geometry.
- Existing canonical GrafPort method bodies and source-facing names.
- Exact bevel edge order and palette reversal.
- A closely related six-row source comparator that independently inlines the same low-level idiom.
- Current command-13386 class-before-children generated structure and target body are both source-valid; the historical synthetic target body is removed.

## IDA MCP Facts

- Session: `64c11373`, healthy at evidence collection; protocol endpoint `http://127.0.0.1:13337/mcp`.
- Target lookup: `sub_555AF0`, start `0x555af0`, size `0x178`.
- Predecessor: `sub_555AE0`, size `0x10`, ending exactly at target start.
- Successor start: `sub_555C70`, size `0x71`; `0x555c68` itself is not a function.
- Target profile: 137 instructions, six basic blocks, zero direct callers, seven profiled callee entries including a recursive-profile artifact, 21 constants.
- Actual external/internal callees: `0x4b9600`, `0x4bab70`, `0x556020`, `0x4b9660`, `0x4b98f0`, and `@__security_check_cookie@4`, plus two virtual calls through the target receiver.
- Full byte SHA256: `DAB99C735A0B92A28079F49EE87A9493532F52DEF4CDDD3DFFAEE16FB46AE4DB`.
- Target xrefs: exactly one data xref from `0x0062303c`; no direct code xref.
- Vtable cell bytes at `0x0062303c`: `f0 5a 55 00`, little-endian `0x00555af0`.
- Vtable base xrefs: three each at `0x00622ff8`, `0x0062304c`, and `0x0062307c` from constructor/destructor lifecycle sites.
- Label xrefs: Promote at `0x555b30/0x555b4b`; Demote at `0x555b63/0x555b7b`.
- Label bytes: `L"Promote"`, immediately followed by `L"Demote"`, ending before `0x006230c8`.
- Row helper: `sub_556020`, size `0x4d`, sole code xref at `0x555b9f`, one rectangle-setter callee.
- Shared helper lookups: MoveTo size `0x13`; SetDrawColor size `0x0d`; LineTo size `0x1c`; DrawWideText size `0x158`.
- DrawWideText current profile: 63 caller functions; accepted helper documentation separately records 188 direct rel32 call sites.
- Comparator: `sub_481490`, size `0x23e`, 203 instructions, six blocks. It shares the low-level pattern but differs materially in content and geometry.
- Padding: eight `0xcc` bytes at `[0x00555c68,0x00555c70)`.

## Function / Child Inventory

| Range / item | UID | Role | Status/recommendation |
| --- | --- | --- | --- |
| `0x00555ae0-0x00555af0` | UID0002LT | `VoteMenuPane::OnDismiss` predecessor | Existing exact child; no gap before target; verify-only. |
| `0x00555af0-0x00555c68` | UID0002LU | Target `VoteMenuPane::OnPaint` | One implemented source method; exact R1, `92/94`, no split. |
| `0x00555c68-0x00555c70` | UID0000VN ignored alignment | Eight-byte successor padding | Parent-only ignored padding; preserve. |
| `0x00555c70-0x00555ce1` | UID0002LV | `VoteMenuPane::DrawBackground` successor | Existing exact child; verify-only. |
| `0x00556020-0x0055606d` | UID0002LX | File-local row rectangle helper | Existing exact source body; sole target caller; verify-only. |
| `0x00481490-0x004816ce` | UID0002FL | Chatting selector paint comparator | Separate class/source family; comparator only, never a child/owner. |

UID0002LU has no internal padding, no mixed data, no nested compiler helper, and no child split. `Nested:0` remains correct because no relative address-sorted nesting delta is introduced by this direct-target update.

## Direct Xref / Caller Inventory

| Target | Direct evidence | Interpretation |
| --- | --- | --- |
| UID0002LU start | One data xref at `0x0062303c`, zero direct code callers. | Live primary virtual, not dead/no-route code. |
| Primary vtable base `0x00622ff8` | Xrefs at `0x555913`, `0x555975`, `0x55634c`. | Constructor install plus ordinary/scalar destructor restore. |
| Row helper `0x00556020` | Sole code xref `0x555b9f`. | Target-owned consumer route; file-local helper remains UID0002LX. |
| Promote literal | Two data xrefs from target. | Two x-position passes. |
| Demote literal | Two data xrefs from target. | Two x-position passes. |
| MoveTo/SetDrawColor/LineTo/DrawWideText | Broad cross-feature fan-in; one target execution contributes 5/2/4/4 runtime calls respectively. | Shared inherited GrafPort APIs, not VoteMenu-owned helpers. |

The target has no direct static caller because dispatch is through the vtable. Absence of a direct call therefore has no negative source-retention effect.

## Documentation Evidence And IDA Status

Validated current documentation:

- UID0000FX correctly owns the source method and already declares `virtual void OnPaint()` plus the exact `+0xf8/+0xf9` fields and row constants.
- UID0000P6 correctly routes the family to `NexusTK/ui/menu/VoteMenuPane.cpp`.
- UID0001FY correctly keeps the broad method island as a blank aggregate and enumerates UID0002LU.
- UID0002LX correctly emits `GetVoteMenuItemRect` with row `-1` sentinel and fixed row geometry.
- UID0001WH correctly distinguishes pressed byte, signed highlighted row, natural alignment, constructor context, and target name.
- UID0001Z1 and UID0003CY correctly place target in primary vtable slot `+0x44`; raw table emission remains prohibited.
- UID0003D0 correctly owns the two source literals as data support; raw bytes resolve IDA's fragmented Demote label.
- UID000162, UID0004H4, and UID00016C supply the exact shared drawing APIs needed by R1.

Pre-callback contradictions now historicalized or rejected in the implemented destinations:

- Target's synthetic helper body and its claim that low-level expansion is optional.
- Target prose that calls the label operation centered without recording `-24` and direct passes.
- Target prose that calls the frame a generic highlight outline without exact edge orientation.
- Any inference that 128/143 mean outer/inner or proven light/dark shades.
- Any use of Hex-Rays' byte return as source ABI.

IDA itself still uses `sub_*` labels and fragmented wide-string typing. That does not block source reconstruction because exact bytes, call contracts, vtable placement, and canonical support names resolve the behavior.

## Ranked Ownership Analysis

1. UID0000FX `VoteMenuPane`: strongest and retained. The receiver fields, class vtable, sibling virtuals, row constants, and method declaration all belong to this class.
2. UID0000P6 `VoteMenuPane.cpp`: strongest source-file route and retained as indirect file emitter. It owns the local row helper and class family, but is not the target's direct semantic owner.
3. UID00005V `GrafPort`: dependency owner only. It owns MoveTo, SetDrawColor, LineTo, and DrawWideText, not this feature method.
4. UID00001Z Chatting selector family: comparator only. Similar copied paint idiom does not transfer target ownership.
5. Surface/callback table: backend dependency only. It owns low-level draw callbacks, not the GrafPort wrappers or VoteMenu method.
6. UID0003CY/UID0003D0 data pages: compiler data/literal support only, not method owners.
7. UID0001FY aggregate or direct file-bucket target ownership: rejected for semantic ownership. The aggregate remains an inventory and the file remains the source route.

## Source Placement

Keep the existing source placement:

- class owner: UID0000FX `VoteMenuPane`;
- file route: UID0000P6 `NexusTK/ui/menu/VoteMenuPane.cpp`;
- shared graphics declarations/definitions remain in GrafPort support/source;
- file-local `GetVoteMenuItemRect` remains in VoteMenuPane source;
- compiler vtables, RTTI, cookies, and literal-pool addresses are not handwritten source objects in this method.

No new file, header split, PopupMenuControls migration, Chatting migration, Surface migration, or third-party import is justified.

## Range / Split / Padding / Reclassification Analysis

- Keep exact range `[0x00555af0,0x00555c68)` and size `0x178` / 376.
- Keep one source method; do not split text drawing, row gate, or bevel drawing into child pages.
- Predecessor UID0002LT ends exactly at `0x00555af0`; there is no predecessor padding to transfer.
- Preserve eight `0xcc` successor bytes `[0x00555c68,0x00555c70)` as parent-only ignored alignment.
- Preserve UID0002LV start `0x00555c70` and all following child ranges.
- Keep `Nested:0`; this is a direct child with no relative level change.
- Keep reconstructable true and direct class emitter. No raw/no-route, compiler-only, covered-by, imported, or non-reconstructable reclassification applies.
- Keep title/path. `VoteMenuPaneOnPaint` is already the correct semantic title.
- The generic first 29 target bytes also occur at `0x00481490`, but a 32-byte semantic interior signature at `0x00555b08` is unique. The comparator is a different 0x23e-byte class method, not a range duplicate.

## Negative Evidence Summary

- No direct code caller to the target; explained by the exact vtable route.
- No `DrawShadowedCenteredText` function, method declaration, macro proof, or support contract.
- No `DrawVoteMenuHighlight` function, method declaration, macro proof, or support contract.
- No call to GrafPort `DrawOutlinedText`; that method has a different five-pass color-changing behavior.
- No fill call or second nested rectangle in the row frame.
- No evidence that palette indices 128 and 143 should be named light/dark, foreground/background, or outer/inner in this method.
- No source return value despite Hex-Rays' incidental AL result.
- No internal range split or mixed data.
- No exact duplicate target body. The Chatting comparator differs in size, labels, rows, geometry, and helper.
- No ownership evidence for Chatting, GrafPort, Surface, the vtable data page, or the literal-data page.
- No original debug symbol for local names or exact formatting/factorization. This caps confidence but does not block R1.

## IDA Rename / Type / Comment Recommendations

- Documentation path/title: leave unchanged.
- Source-facing function name: `VoteMenuPane::OnPaint`.
- Conceptual source type: nonstatic x86 `thiscall` method with source return `void` and no explicit parameters.
- Useful comments, if a future IDA annotation pass is separately authorized: primary vtable slot `+0x44`; `+0xf8` pressed byte; `+0xf9` signed highlighted row; direct label and bevel sequence; palette edge reversal.
- Preserve subfunction names only as historical IDA evidence in docs; do not leak them into source.
- Do not rename/type/comment IDA during this B-agent pass. IDA DB mutation is neither safe nor requested under the assignment.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes. This is a live source-authored virtual with exact range, ABI, class route, fields, callees, geometry, and branch behavior.
- Formal destination R1: replace the complete managed block on UID0002LU with the following exact text.

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void VoteMenuPane::OnPaint()
{
    DrawBackground();
    DrawBorder();

    const int textX = (m_bounds.left + m_bounds.right) / 2 - 24;

    MoveTo(textX, 21);
    DrawWideText(L"Promote", 7);
    MoveTo(textX + 1, 21);
    DrawWideText(L"Promote", 7);

    MoveTo(textX, 37);
    DrawWideText(L"Demote", 7);
    MoveTo(textX + 1, 37);
    DrawWideText(L"Demote", 7);

    if (m_highlightedVoteRow == kPromoteRow ||
        m_highlightedVoteRow == kDemoteRow) {
        Rect itemRect;
        GetVoteMenuItemRect(m_highlightedVoteRow, &itemRect);

        const int left = itemRect.left + 5;
        const int right = itemRect.right - 5;

        MoveTo(left, itemRect.bottom);

        if (m_voteRowPressed) {
            SetDrawColor(128);
            LineTo(left, itemRect.top);
            LineTo(right, itemRect.top);
            SetDrawColor(143);
        } else {
            SetDrawColor(143);
            LineTo(left, itemRect.top);
            LineTo(right, itemRect.top);
            SetDrawColor(128);
        }

        LineTo(right, itemRect.bottom);
        LineTo(left, itemRect.bottom);
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

Why R1 preserves original behavior:

- source integer division reproduces the signed midpoint sequence for realistic pane coordinates;
- call order, literal lengths, x/y values, row gate, row helper, inset, palette calls, and all four line endpoints match the disassembly;
- no return value, stack cookie, raw vtable call, address, or decompiler variable is emitted;
- exact current class fields/constants and canonical inherited GrafPort names are used;
- branch duplication matches the observed compiler shape more closely than computing abstract color variables or calling a synthetic frame helper.

Why this is plausible original-era source:

- the Chatting selector body independently inlines the same direct GrafPort idiom;
- no callable shared helper exists;
- ordinary local coordinates and direct calls fit the existing codebase style;
- inferred names are limited to `textX`, `left`, and `right`, whose roles are exact and do not claim recovered symbols.

Third-party import directive: not applicable. This is proprietary NexusTK UI source, not a vetted static third-party embed.

## Final Recommendation

Implemented callback result:

- C01-C20 and R1 are terminal with destination-specific proof in the ledger;
- UID0002LU is `92/94` with exact Item Summary, full evidence, corrected source history, and unchanged owner/emitter/range/position/nesting;
- UID0000FX is `89/91` with bounded OnPaint/helper/source-access evidence and its formal declaration preserved byte-for-byte;
- UID0000P6 is `90/90` with bounded source-ready OnPaint and generated-state history, preserving route and unrelated family facts;
- UID0001FY received inventory/evidence-only synchronization, preserving `88/91`, owner/emitter, true state, blank formal, and all children/padding;
- all verify-only pages were reread and remained unchanged because no contradiction existed;
- scoped validators and final waited UID0000P6 refresh passed;
- manual coverage edits remain external and the exact current text is retained below.

No split, rename, new UID, owner change, source-file move, IDA mutation, import, compiler-wrapper emitter, or raw data array occurred or remains required.

## Recommended Target Doc Changes

Target path: `by-memory/0x00555af0-0x00555c68.VoteMenuPaneOnPaint.md`.

Implemented changes:

- Applied `COMPLETION:86 -> 92` and `CONFIDENCE:90 -> 94`.
- Preserved UID, title, exact path/range, owner UID0000FX, emitter UID0000FX, reconstructable true, blank optional position, and `Nested:0`.
- Replaced the formal body with R1 exactly; report/target/generated normalized code hash is `74E1845EE78367A2582A22851AFC077C02A8D5C063D69855037B03EC4FD06CEB`.
- Replaced the Item Summary with:
  `Exact primary-vtable VoteMenuPane OnPaint body: two inherited background/border calls, four direct DrawWideText label passes, signed highlighted-row gate, GetVoteMenuItemRect geometry, and pressed-state reversal of 128/143 top-left versus bottom-right bevel edges; fresh MCP confirms 0x178 bytes, six blocks, slot 0x0062303c, and eight-byte successor alignment.`
- Added full range/size/hash/instruction/basic-block evidence.
- Added exact label coordinate/pass table, row gate, rectangle/inset/edge sequence, helper identities, vtable route, and source-void ABI.
- Preserved state-field, row-helper, literal, vtable, and padding evidence.
- Historicalized the older descriptive synthetic-helper body and explained why completed shared-helper docs supersede it.
- Preserved rejected alternatives and negative evidence at report depth.

## Recommended Support Doc Changes

| Support destination | Implemented bounded change | Metadata/formal result |
| --- | --- | --- |
| `by-class/VoteMenuPane.md` UID0000FX | Added exact OnPaint direct-call/edge behavior, source-void slot, inherited GrafPort API/access rationale, and synthetic-helper historical correction. Preserved all fields, layout, methods, helper prototypes, unrelated evidence, and class closure before `[[CHILDREN]]`. | Applied `88/90 -> 89/91`; owner/emitter/position/formal unchanged; validator 13380. |
| `by-file/VoteMenuPane.md` UID0000P6 | Added source-ready OnPaint inventory, direct GrafPort dependency list, copied-idiom comparator classification, generated pre-callback defect, and no-helper/no-array exclusions. Preserved all constructor/destructor/input/resource/packet/singleton facts. | Applied `89/88 -> 90/90`; route/path/formal unchanged; validators 13381/13386. |
| `by-memory/0x005558d0-0x0055606d.VoteMenuPaneCore.md` UID0001FY | Synchronized the UID0002LU inventory row to `92/94`, exact hash/blocks/body/source route, and corrected no-synthetic-helper state. Preserved every child, padding span, aggregate no-duplicate policy, and generated aggregate marker history. | Score/owner/emitter/true/Nested/formal unchanged at `88/91`; validator 13383. |

Verify-only reread result, no edit required or performed:

- UID0002LX already supplies exact rectangle source and sole caller.
- UID0001WH already supplies exact field types/layout.
- UID0001Z1 and UID0003CY already supply slot/lifecycle/compiler-data evidence.
- UID0003D0 already supplies the source literal range; fresh raw bytes resolve label fragmentation without requiring a separate emitter.
- UID000162, UID0004H4, UID00016C, UID00005V, and Pane already establish shared methods/receiver inheritance.
- UID0002LT, UID0002LV, and ignored padding remain range-boundary verification only.
- UID0002FL and Chatting support remain comparator-only and were not edited by this callback.

## Score And Metadata Recommendation

| Destination | Pre-callback | Implemented | Rationale/cap |
| --- | --- | --- | --- |
| UID0002LU | `86/90` | `92/94` | All method blockers are closed with exact bytes, CFG, slot, calls, fields, geometry, palette order, source route, and formal body. Below 95 because original local spelling and source-level copy/macro factorization are not symbol-proven. |
| UID0000FX | `88/90` | `89/91` | One major method is exact/source-ready and inherited-access evidence closes synthetic APIs. Broader constructor/resource/helper spellings and `m_voteType` semantics still cap the class. |
| UID0000P6 | `89/88` | `90/90` | File inventory gained exact emitted OnPaint source and corrected generated expectations. Other existing method/helper source-quality caveats remain. |
| UID0001FY | `88/91` | `88/91` unchanged | Parent inventory improved, but the aggregate remains intentionally blank and does not duplicate child bodies. |

Target metadata preserved: UID, owner, emitter, reconstructable true, blank optional position, Nested0, range, path, title. No child registration, rename, split, or import metadata was required.

Score-improvement attempt:

| Former blocker | Research performed | Resolution |
| --- | --- | --- |
| Drawing helper identities | Fresh decompile/profile plus canonical GrafPort pages. | Closed: MoveTo, DrawWideText, SetDrawColor, LineTo. |
| Label placement/helper | Exact arithmetic/calls and sibling comparator. | Closed: midpoint minus 24, four direct passes. |
| State fields/types | Constructor, mouse handler, layout, target reads. | Closed: byte pressed state and signed row sentinel. |
| Palette semantics | Exact branch/edge sequence and SetDrawColor contract. | Closed behaviorally as top-left/right-bottom reversal; shade names intentionally not invented. |
| Reachability | Target/vtable xrefs and lifecycle base xrefs. | Closed: live primary virtual. |
| ABI/return | Slot contract, epilogue, last-call artifact. | Closed: source void. |
| Range/split | Full bytes, lookup, blocks, adjacent bytes. | Closed: one exact method, eight-byte successor pad. |
| Source placement/owner | Current class/file/support and comparator. | Closed: VoteMenuPane class, VoteMenuPane.cpp. |
| Source factorization | Compared complete 0x00481490 body and searched synthetic names. | Closed conservatively: direct statements; no helper evidence. |
| Original exact local spelling | Symbols/IDA/current reports searched. | Not recoverable; descriptive local names only, confidence cap but no code blocker. |

## Open Questions With Attempted Resolution

- Were the duplicate x-offset label passes intended as shadow, faux-bold, or another visual style?
  - Checked exact call/color order, DrawOutlinedText behavior, sibling comparator, and current docs.
  - Resolution: intent label is not source-proven. R1 emits the exact two passes and prose calls them one-pixel horizontal duplicate passes, avoiding an invented helper/intent name.
- Are palette 128 and 143 light/dark shades?
  - Checked SetDrawColor, line callback, current palette-related docs, and sibling UI callers.
  - Resolution: exact palette indices and edge roles are proven; shade names are not. R1 uses literals and prose uses edge orientation.
- Was a shared inline helper or macro used by VoteMenuPane and ChattingVarietySelectPane?
  - Compared complete methods, callees, constants, geometry, and searches for a callable helper.
  - Resolution: possible in the abstract but not evidence-backed. Direct calls are the least-assumptive source representation and preserve behavior. This caps confidence below 95.
- Are the GrafPort methods public or protected?
  - Checked derived-pane call sites and canonical class/helper ownership.
  - Resolution: exact keyword is unavailable, but binary source causation proves they are accessible to derived panes. No target-local wrappers are needed.
- Is `textX` the original local name?
  - No debug symbol survives.
  - Resolution: it is a narrow descriptive local only; the arithmetic is exact and the spelling has no ABI effect.
- Are any other target questions unresolved enough to block C++?
  - No. All behavior, type, owner, range, helper, source-route, and access blockers have a defensible implementation-ready answer.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

Post-callback read-only coverage reinspection confirms four stale rows for the implemented ordinary destinations. After external supervisor command 13372, current `by-memory/-coverage-report.md` is SHA256 `619DD7561D09481636BF8DF5CA41EB1F022A2D0151B8724D4EAAD0B53C6A1866`, `1,709,616` bytes, and `4,127` lines. The unrelated UID0003V0/padding insertion occurs later in the file and did not move or alter the VoteMenuPane rows: UID0001FY and UID0002LU remain at current lines 2842 and 2850 with the same surrounding order. UID0001FY remains after the `0x005558c2-0x005558d0` parent alignment; UID0002LU remains after UID0002LT and before the `0x00555c68-0x00555c70` successor padding. Class/file rows remain at lines 593/302 in current SHA256 `FEBF3FFEB3B8A9BE22CAC36C5BC3D864EEC3B3EAB3665A0561D6705C6FE15710` / `265426CA879AB5C3BFEA08ACED8329314A70D66CA265D29D47F47CC2DF78522D`. The exact replacement text below was reread after implementation and remains a no-loss handoff. B003 did not and must not apply these edits directly.

File/placement: `by-memory/-coverage-report.md`, replace the exact UID0001FY row at current line 2842 with:

```text
    - [UID:0001FY][0x005558d0-0x0055606d.VoteMenuPaneCore](by-memory/0x005558d0-0x0055606d.VoteMenuPaneCore.md) 0x005558d0-0x0055606d | aggregate class-method cluster | VoteMenuPaneCore : reconstructable : 88% : very strong : Exact non-duplicating VoteMenuPane core inventory at 88/91; current child ranges, all internal padding, vtable routes, row-helper edges, source/compiler distinctions, and direct class/file ownership remain preserved, while UID0002LU now carries exact source-ready OnPaint behavior without synthetic drawing helpers.
```

File/placement: `by-memory/-coverage-report.md`, replace the exact nested UID0002LU row at current line 2850 with:

```text
      - [UID:0002LU][0x00555af0-0x00555c68.VoteMenuPaneOnPaint](by-memory/0x00555af0-0x00555c68.VoteMenuPaneOnPaint.md) 0x00555af0-0x00555c68 | method | VoteMenuPaneOnPaint : reconstructable : 92% : very strong : Fresh B003 live MCP proves the exact 0x178-byte, 137-instruction, six-block primary-vtable OnPaint method and SHA256 DAB99C735A0B92A28079F49EE87A9493532F52DEF4CDDD3DFFAEE16FB46AE4DB; source calls DrawBackground/DrawBorder, performs four direct MoveTo/DrawWideText Promote/Demote passes at midpoint-minus-24 x positions, gates signed highlighted row 0/1, calls GetVoteMenuItemRect, and draws a five-pixel-inset four-edge frame whose top-left/right-bottom palette indices 128/143 reverse with m_voteRowPressed. Slot 0x0062303c, no-direct-caller virtual reachability, shared GrafPort helper identities, source-void ABI, exact predecessor/successor boundaries, eight-byte successor padding, VoteMenuPane owner/source route, and rejection of synthetic DrawShadowedCenteredText/DrawVoteMenuHighlight helpers are documented with exact formal C++.
```

File/placement: `by-class/-coverage-report.md`, replace the exact UID0000FX row at current line 593 with:

```text
- [UID:0000FX][VoteMenuPane](by-class/VoteMenuPane.md) : reconstructable : 89% : strong : VoteMenuPane at 89/91 remains attached to [UID:0000P6][VoteMenuPane](by-file/VoteMenuPane.md) with its exact Pane-derived declaration, three vtable views, singleton, tail layout, row constants, target name, file-local helper prototypes, and class closure before child definitions. Fresh UID0002LU evidence resolves OnPaint to direct inherited GrafPort MoveTo/DrawWideText/SetDrawColor/LineTo calls, exact Promote/Demote placement, signed highlighted-row gating, and pressed-state bevel-color reversal; the old synthetic DrawShadowedCenteredText/DrawVoteMenuHighlight model is retained only as superseded history, while unrelated constructor, packet, resource, and compiler-wrapper caveats remain preserved.
```

File/placement: `by-file/-coverage-report.md`, replace the exact UID0000P6 row at current line 302 with:

```text
- [UID:0000P6][VoteMenuPane](by-file/VoteMenuPane.md) : reconstructable : 90% : strong : `NexusTK/ui/menu/VoteMenuPane.cpp` at 90/90 retains the complete VoteMenuPane class/method/helper/singleton/source split, exact child ranges, packet and SUBWIN resource behavior, compiler-wrapper exclusions, and generated route. UID0002LU now emits exact source-ready OnPaint C++ through direct inherited GrafPort drawing methods, with four literal text passes and the exact split-color four-edge row frame; no synthetic VoteMenuPane drawing helper, duplicate body, handwritten vtable/RTTI array, or cross-family owner transfer is introduced.
```

No manual rows are requested for verify-only UID0002LX, UID0001WH, UID0001Z1, UID0003CY, UID0003D0, or shared GrafPort dependencies because this callback made no ordinary changes to them. No validator-owned `auto-generated/-ag-*` file text is supplied.

## Follow-Up Actions

- External supervisor/validator state owns artifact Gate review, manual coverage application, validation, execution, count, path, move, and archive outcomes. This report neither asserts nor directs those lifecycle states.
- The bounded implementation callback is complete: C01-C20, R1, four destinations, validators, generated assertions, and manual coverage handoff are reconciled in this artifact; no B003 implementation item remains.
- No additional B-agent research is required for source emission. Later symbol recovery could refine local spelling or prove a macro, but it would not change the exact behavior documented here.
- No A-agent action, IDA mutation, new child registration, source-tree split, or third-party import is required by the evidence.

## Confidence

- Recommendation confidence: very strong.
- Target score confidence: very strong for `92/94`.
- Owner/emitter/source-placement confidence: very strong.
- Formal C++ behavioral confidence: very strong.
- Exact original local spelling/factorization confidence: moderate; this is the reason confidence remains below 95.
- Remaining uncertainty does not block implementation because R1 uses only exact behavior and already accepted shared API names.

## Validator Results

All authorized callback validators were invoked from `source-3/project-documentation`; each exited `0` with `ok:1`.

| Destination / purpose | Exact command | Command metadata | Result and side effects |
| --- | --- | --- | --- |
| UID0002LU target | `python .\tools\validator.py --mode file --file by-memory/0x00555af0-0x00555c68.VoteMenuPaneOnPaint.md --apply --queue-timeout 240` | ID `000000013377`; `2026-07-15T18:49:21-04:00` | Exit 0 / ok 1. Completion 92 and confidence 94 applied; autogen registry and projected stats updated; generated refresh deferred to command 13377. |
| UID0000FX class | `python .\tools\validator.py --mode file --file by-class/VoteMenuPane.md --apply --queue-timeout 240` | ID `000000013380`; `2026-07-15T18:50:29-04:00` | Exit 0 / ok 1. Completion 89 and confidence 91 applied; projected stats updated; generated refresh deferred to command 13380. Class formal remained SHA256 `6B3D8363704BA1E813F096DA61DC76421C420A4C0524BECC4F31A8F26E980817`. |
| UID0000P6 file | `python .\tools\validator.py --mode file --file by-file/VoteMenuPane.md --apply --queue-timeout 240` | ID `000000013381`; `2026-07-15T18:51:38-04:00` | Exit 0 / ok 1. Completion/confidence 90/90 applied; UID0002LU reference-index entry added; projected stats updated; generated refresh deferred to command 13381. |
| UID0001FY aggregate | `python .\tools\validator.py --mode file --file by-memory/0x005558d0-0x0055606d.VoteMenuPaneCore.md --apply --queue-timeout 240` | ID `000000013383`; `2026-07-15T18:52:44-04:00` | Exit 0 / ok 1. No metadata change; projected stats updated; generated refresh deferred to command 13383. |
| Final waited VoteMenuPane refresh | `python .\tools\validator.py --mode file --file by-file/VoteMenuPane.md --apply --queue-timeout 240 --wait-generated` | ID `000000013386`; `2026-07-15T18:53:57-04:00` | Exit 0 / ok 1; generated refresh completed at the same command/timestamp. Registry rebuild reported 4,998 nodes/4,028 edges and 281 generated metadata refreshes. Existing global warnings were 14 fallback inserts, 85 missing child markers, and 160 no-code emitters; none names the target as a failure. |

Waited generated proof for `auto-generated/NexusTK/ui/menu/VoteMenuPane.cpp`:

- header command `000000013386`, refreshed `2026-07-15T18:53:57-04:00`; SHA256 `8ECF7F395B6DA7BD00B49B99999C2ADD2AE8A435BDE2E0F07A27E40BFE1DEE18`; `8,559` bytes / `280` lines;
- class closes at line 37; constructor starts at 46 and every qualified method definition follows the close; UID0002LU starts at 116;
- constructor, destructor, OnMouseEvent, OnDismiss, OnPaint, DrawBackground, and DrawBorder each have one definition; each file-local helper has one declaration and one definition;
- one UID0002LU header/definition and normalized R1 SHA256 `74E1845EE78367A2582A22851AFC077C02A8D5C063D69855037B03EC4FD06CEB`, exactly equal to report and target;
- target static counts are five `MoveTo`, four `DrawWideText`, four `SetDrawColor`, and six `LineTo`; each runtime row-frame branch executes two color changes and four line edges;
- zero `DrawShadowedCenteredText`, zero `DrawVoteMenuHighlight`, zero UID0002LU Empty Emitter Marker, and no duplicate/wrong-range target body;
- the sole raw-address-pattern hit is the validator-owned UID0002LU path comment, not source; the sole `vtable` text hit is the unrelated UID0001Z1 Empty Emitter Marker comment, not a handwritten array;
- no target handwritten vtable/RTTI array, security cookie, raw address, or compiler scaffolding; five unrelated family Empty Emitter Markers remain unchanged.

Later read-only generated rebase: external command `000000013397`, refreshed `2026-07-15T19:04:00-04:00`, SHA256 `BDFB7E442339AE457064659A233F213B63EAB344E821D05D965BD514749CB420`, retained `8,559` bytes / `280` lines and all command-13386 semantic assertions. It is recorded as an external header epoch, not a B003 validator command or an indefinite-current lifecycle assertion.

## Changed Files

- Report artifact updated in place: `tools/leaser/Agents/Agent-B003/research/0002LU-VoteMenuPaneOnPaint-source-quality.md`.
- Modified ordinary destination: `by-memory/0x00555af0-0x00555c68.VoteMenuPaneOnPaint.md`, SHA256 `30BDD2A0983120DF6CE5DB91329B44DD97A7627757AEC41F44FCAF2456C64276 -> 79C9CEFF1DD1F5C51B8B1909F5D4B5854DB81F0A35AEE49F9E496E5BB3B82331`; exact R1 code SHA256 `74E1845EE78367A2582A22851AFC077C02A8D5C063D69855037B03EC4FD06CEB`; complete managed block SHA256 `DB9972C2D235559E0F7C429D131F16C2EDC761A1BBE6CA1EFC4B83978B176821`.
- Modified ordinary destination: `by-class/VoteMenuPane.md`, SHA256 `71F5F98867D4DB2F3D603B88984F832A133D7418D0544D2C1EF258A7B23721C8 -> 0FD33C3C5CCF4A8C1525FA53DD23B364CD3C590DEC4970E34E8BFBDB0A6F3DC8`; complete formal remained SHA256 `6B3D8363704BA1E813F096DA61DC76421C420A4C0524BECC4F31A8F26E980817`.
- Modified ordinary destination: `by-file/VoteMenuPane.md`, SHA256 `E38A8F001BDE0AFB2949A25BF5EE5EED249CE29A2D30C909C29E2AD9F4CCF8A3 -> 70271629FDD251F9502817E714CF7FD8396D3B1D35E7C8BAEFFC72D2B7C63977`; file route unchanged and no managed formal exists on this by-file page.
- Modified ordinary destination: `by-memory/0x005558d0-0x0055606d.VoteMenuPaneCore.md`, SHA256 `F615221B980BF08838D480F7B7A354945E6463BDF1E0D0DF09D67A144037DB0A -> B0BF64850E66BD5EDBEB2525A2EE1B08D90B0B7C6A01763068BCD85AD6B6A865`; blank code SHA256 `E3B0C44298FC1C149AFBF4C8996FB92427AE41E4649B934CA495991B7852B855` and complete managed block SHA256 `BC263E4A872397A338F7D26782FCD0A2A4E925863C0A4D1C983130939A7B68EC` preserved.
- Renamed files: none.
- New child/UID/split/import files: none.
- Verify-only files changed: none; all were reread after implementation with no contradiction.
- Generated and projected metadata changed only through authorized validator side effects. B003 manually edited no generated, manual coverage, tracker, audit, supervisor, validator-state, lifecycle, archive, or IDA file.
- Report execution/lifecycle command run by B003: none.
- Ordinary leases: one at a time for UID0002LU, UID0000FX, UID0000P6, and UID0001FY; each released immediately after its scoped validator. UID0000P6 was leased once more for waited command 13386 and released immediately.
- Report-only Gate 1 repairs: generated command/hash/size/line evidence, current manual by-memory placement, and the external command-13372 coverage snapshot were rebased without changing research, C01-C20, R1, scores, exact replacement text, or checklist content. The later unrelated UID0003V0/padding insertion was preserved as external drift with no VoteMenuPane row movement.
- Report leasing: the pre-creation attempt was rejected as `File not found`; after creation, short report-only leases covered the final consistency edit and bounded snapshot rebases, and each was released immediately.
- Active B003 leases at callback reconciliation: zero.

## Implementation Tracking Checklist

Report-only requirements, accepted and preserved through implementation:

- [x] Exact artifact accepted by supervisor for implementation: SHA256 `C9F29914DEECB36B21146C673C9E2E136827D78995477210B886497B5D29521A`.
- [x] Target/support docs applied: UID0002LU, UID0000FX, UID0000P6, and UID0001FY; hashes are in Changed Files.
- [x] Verify-only docs reread without editing: UID0002LX, UID0001WH, UID0001Z1, UID0003CY, UID0003D0, UID000162, UID0004H4, UID00016C, UID00005V, Pane, UID0002LT, UID0002LV, ignored padding, UID0002FL, Chatting support, and generated VoteMenuPane.cpp.
- [x] Current target state and actual evidence remain recorded, with pre-callback defect explicitly historical and command 13386 bounded as callback proof.
- [x] Claim And Incorporation Ledger C01-C20 is terminal claim by claim with legal actions/states and destination proof.
- [x] Target metadata applied: `92/94`, owner/emitter UID0000FX, true, blank position, Nested0, exact range/path/title; validator 13377.
- [x] Target Item Summary and report-level range/hash/CFG/xref/behavior/evidence/history applied in target SHA `79C9CEFF...2331`.
- [x] Exact formal R1 applied without compression or synthetic helper substitution; report/target/generated code SHA `74E1845E...6CEB`.
- [x] UID0000FX bounded prose and `89/91` score applied while preserving formal SHA `6B3D8363...0817` and unrelated facts; validator 13380.
- [x] UID0000P6 bounded prose and `90/90` score applied while preserving source route and unrelated facts; validators 13381/13386.
- [x] UID0001FY bounded inventory sync applied with `88/91`, route, formal, children, and padding unchanged; validator 13383.
- [x] Historical synthetic-helper recommendation preserved only as superseded provenance in target/class/file.
- [x] Positive, negative, comparator, rejected-alternative, palette, ABI, and source-placement evidence preserved at report depth.
- [x] Range/split/padding/reclassification decision applied: no split, exact range, eight-byte parent-only pad, Nested0.
- [x] IDA rename/type/comment decision retained with zero IDA mutation.
- [x] Third-party import remains concretely not applicable to proprietary NexusTK UI source.
- [x] Exact manual supervisor-owned coverage replacements retained and reread at current rows without B003 coverage edits.
- [x] Validator/generated plan completed as scoped commands 13377/13380/13381/13383 and waited command 13386.

Implementation callback verification:

- [x] Gate-1-passed artifact authorization matched the exact accepted SHA before ordinary edits.
- [x] Current leases were checked and each destination was reread immediately after its bounded lease acquisition.
- [x] Only one ordinary destination was leased at a time; every lease was released immediately after validation.
- [x] C01-C20 actions/states are legal terminal values with claim-specific hashes/validator/generated proof.
- [x] UID0002LU exact metadata, Item Summary, evidence, history, and R1 are implemented; validator 13377.
- [x] UID0000FX bounded support/score update is implemented without formal or unrelated-content loss; validator 13380.
- [x] UID0000P6 bounded support/score update is implemented without route or unrelated-content loss; validators 13381/13386.
- [x] UID0001FY bounded inventory update is implemented without child, padding, metadata, or formal loss; validator 13383.
- [x] Every verify-only destination was reread and remained compatible; no exact contradiction required expansion.
- [x] Scoped UID0002LU validator 13377 at `2026-07-15T18:49:21-04:00`: exit 0 / ok 1; side effects recorded.
- [x] Scoped UID0000FX validator 13380 at `2026-07-15T18:50:29-04:00`: exit 0 / ok 1; side effects recorded.
- [x] Scoped UID0000P6 validator 13381 at `2026-07-15T18:51:38-04:00`: exit 0 / ok 1; side effects recorded.
- [x] Scoped UID0001FY validator 13383 at `2026-07-15T18:52:44-04:00`: exit 0 / ok 1; side effects recorded.
- [x] Final authorized waited refresh 13386 completed at `2026-07-15T18:53:57-04:00`; header/hash/freshness recorded.
- [x] Generated class closure, method/helper uniqueness, exact R1/direct calls, zero synthetic helpers, zero target marker, no duplicate, and no handwritten compiler/raw source assertions are proven.
- [x] Exact manual coverage text remains supervisor-owned and current at by-memory 2842/2850, class 593, and file 302.
- [x] Validator Results and Changed Files record exact command metadata, destination hashes, formal hashes, side effects, and generated proof.
- [x] No accepted item remains unapplied, blocked, or silently excluded.
- [x] Zero B003 leases remain; no restricted manual edit, execute_report, probe, lifecycle, move, or archive command was run.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000013401","destination_path":"executed-b-agent-research/B003/0002LU-VoteMenuPaneOnPaint-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B003/research/0002LU-VoteMenuPaneOnPaint-source-quality.md","timestamp":"2026-07-15T19:11:17-04:00","uid":"0002LU"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
