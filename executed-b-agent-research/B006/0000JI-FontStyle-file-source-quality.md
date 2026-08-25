# UID0000JI FontStyle Whole-File Source-Quality Research
** TARGET-REPORT-UID:0000JI **
** AUTHOR-AGENT-ID:B006 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **


Project context: GhidraBridge/NexusTK is a local old-game preservation and software-archaeology initiative reconstructing an unsupported NexusTK client so the game can remain runnable after official support. This report is limited to archival compatibility research and behaviorally faithful source reconstruction.

## Finalized Report / Current Recommendation

- Implemented ordinary recommendation: retain [UID:0000JI] as the standalone reusable `NexusTK/ui/controls/FontStyle.cpp` compilation unit with its required sibling `FontStyle.h` emitted through the owning formal H channel.
- Implemented disposition: three source-authored out-of-line methods emit in physical order under [UID:00005C]; the body at `0x004536e0` is documented as compiler-emitted implicit `std::vector<FontStyleRule>` destruction and emits no authored empty destructor; `0x0049ac60` remains documented compiler/template vector growth and emits no source body.
- Ordinary callback result: declarations now reside in the complete H block, source uses natural C++ alignment rather than explicit padding members, consumer routes include `FontStyle.h`, duplicate/comment-only generated fragments are absent, and target/support metadata is updated. Remaining supervisor work is exactly six unchecked manual-coverage claims plus six unchecked IDA claims. The IDA claims use seven action groups (`T01-T02` and `A01-A05`) comprising fifteen ordered public endpoint stages.
- Confidence: very high for behavior, ranges, layout, compiler/source distinction, caller fanout, and required header dependency; high for the standalone physical file split and descriptive lexical names.

## Supporting Research

- Fresh read-only IDA MCP authority was session `supervisor_uid0000mi_persistence_20260816`, canonical path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`. This identifier is dated evidence only and confers no future mutation authority.
- The live IDB provided bounded function, type, field-xref, comment, frame, caller, callee, decompile, and byte evidence for all five modeled bodies. MCP stayed available; no fallback-only conclusion was used.
- Matching historical reports were used only as leads: B006 `00011T-FontStyleCore-source-quality.md` SHA256 `C3EDC9DD28F97F08FC50573B38BF6745AC7C8AB75990F94EA055DF2A92174B79`, B012 `00005C-FontStyle-class-source-quality.md` SHA256 `46167E9AEA4190AE0F71AAE8A2A5EFB4F59AF5040F18E8D9F6E3E0E29E3C170B`, and B012 `00011T-FontStyleCore-source-quality.md` SHA256 `7513A9EB08B4C401C001D12F134C5CB328D524ECB50910F1370F87B34CD4201C`. Their offline-MCP or older-state claims were rechecked rather than inherited.
- Dated generated snapshot command `000000025247` at `2026-08-16T12:02:49-04:00` produced `FontStyle.cpp` SHA256 `2E89CFEDB9EADD7BA5D9D11AF8FD37F69C2192E1176A3E39B7C702C4034E4423`, 2,649 bytes/83 lines. It is evidence of the present defect set, not continuing generated-state authority; later supervisor readback must be fresh.
- Dated implementation refresh command `000000025343` at `2026-08-17T09:46:38-04:00` produced the clean callback snapshot: `FontStyle.cpp` SHA256 `A9876BFCA6CAF051006275C78B5B05FE451895849A517D9C3BCBBE95E0BEE331`, 1,219 bytes/39 lines; `FontStyle.h` SHA256 `1EE059D4BFE75C0E1CA6B1A42E9E12846DB69D3ABA29581783CE07CC442B89BC`, 1,425 bytes/45 lines; `StaticTextControlPane.cpp` SHA256 `A2FD0D2F3BB9E482F0D64EC4FF826BC7CDFF20535D7C148A2A0E3BC7BBB907FC`, 17,393 bytes/484 lines; and `HelpPanes.cpp` SHA256 `698F24B4C9D8E7A343AE79C209F0F5AB5E74A5FE89A0C9167C8529488EFD44F2`, 50,635 bytes/1,542 lines. These identities are dated receipts; authoritative generated identity remains dynamic and requires fresh supervisor physical readback.
- A fresh closeout readback after an unrelated concurrent generator refresh observed command `000000025350` at `2026-08-17T09:52:06-04:00`: `FontStyle.cpp` SHA256 `A703AF1F2787788B10C41785BECB1EEB6138EF946710E94C46A38308F2EB5FDE`, 1,219 bytes/39 lines; `FontStyle.h` SHA256 `CC358C69477460EF86018796683D122CBA169F0EB62D47ED972AB9EC90545CFC`, 1,425 bytes/45 lines; `StaticTextControlPane.cpp` SHA256 `022F7C42C9FDFCB118CC31EB4A72B11D4C0929797A4A835734BE2BCBC08243ED`, 17,393 bytes/484 lines; and `HelpPanes.cpp` SHA256 `91CE82B5DAAD814EDA34A00BEA5935CC8F81213874C32C72572058F4AE1F5276`, 50,635 bytes/1,542 lines. Physical reread reconfirmed the same required semantics; this is another dated snapshot, not frozen current-state authority.
- Fresh read-only Gate 2B repair evidence used dated MCP session `supervisor_uid0000hf_postdiscard_20260817` at canonical IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`. `server_health` returned `status:ok`; `lookup_funcs` reported size `0x52`; `analyze_function` reported 82 bytes and a terminal five-byte call at `0x0045372d`; `0x00453732` was not a function. `get_bytes` returned the exact 82 function bytes plus a separate fourteen-byte all-`0xcc` alignment span. The session identifier is dated evidence only and confers no future mutation authority.
- Deterministic boundary hashes were recomputed over raw `get_bytes` values decoded in increasing address order, with SHA256 applied to the exact byte arrays: body `[0x004536e0,0x00453732)` is `FBCB522B63D7C1AD48E3941E428AF7099395E16D73C1425896BD613950A33F04`; alignment `[0x00453732,0x00453740)` is `1E875C76536C8496BED8C8760B539327F24ACFFBCF0A4B941877B4BFB4C44356`. The first alignment byte is excluded from the function hash.
- Dated Gate 2B body-hash repair receipt (`2026-08-17`): read-only canonical session `supervisor_uid0000n5_persistverify_20260817` at `E:\NTK\Resources\NexusTK\NexusTK.exe.i64` returned identical repeated `get_bytes` reads for `[0x00499f10,0x00499f51)`/65 bytes, `[0x00499f60,0x00499f85)`/37 bytes, `[0x00499f90,0x00499fda)`/74 bytes, and `[0x0049ac60,0x0049ad74)`/276 bytes. Each SHA256 was recomputed deterministically from the exact raw bytes in increasing address order. Fresh bounded readback also reconfirmed the protected names, function types, complete frames, absent comment channels, ranges, inbound xref sets, and callee sets recorded below; no IDA mutation or save occurred. The dated session identifier confers no future authority.
- Dated Gate 2B public-type-endpoint receipt (`2026-08-17`): the report's bare `declare_type` input parsed `FontStyleRule` as size 14 with dword `m_alignment` at `+0x0a`, changed the `HelpPane__SimpleHelpTextPartPane__OnPaint` local to `style/+0x38/0x0e/FontStyleRule`, and rendered `0x004c6674` as `mov [ebp+style.m_alignment+2], 0`; that exact unsaved result is rejected. On the fresh byte-identical rollback-copy session `supervisor_uid0000ji_gate2b_rollback20260817`, the public `declare_type` endpoint with explicit `#pragma pack(4)` produced the required size-16/four-member layout at `+0x00/+0x04/+0x08/+0x0c`; the local `style` remained `+0x38/0x10/FontStyleRule`, and bounded disassembly rendered `0x004c6674` exactly as `mov [ebp+style.m_alignment], 0`. Public `xrefs_to_field` retained `m_textColor -> {0x4c666d data}`, `m_secondaryColor -> {0x4c6666 data}`, and `m_effect -> {0x4c667b data}`, but returned an empty set for replacement `m_alignment`; deleted `_reserved` was no longer queryable. This proves correct stack-member rendering but not a migrated public field-xref. The failed attempts were unsaved; the canonical file was not changed, and all session identifiers are dated evidence only.
- Public schema review found no endpoint for explicitly adding or migrating a structure-field xref. `xrefs_to_field` is read-only; `set_op_type` is a mutating operand-format endpoint without a dry-run and does not promise migration of a nested stack-variable member relation. It was not invoked. The deterministic safe handoff therefore uses the tested packed declarations and requires the factual empty `m_alignment` field-xref poststate rather than inventing an unproved operand mutation.
- Dated Gate 2A destination-drift repair (`2026-08-17`): current `by-memory/-ignored.md` had reverted only UID0000XM to stale 83-byte/13-alignment evidence at pre-repair SHA256 `8922A9D45507B481A479685FADAA4DA952EA77FC103454C98CDD1E6E9E1AA485`, 1,144,621 bytes/5,484 lines, last write `2026-08-17T12:38:39.7727290-04:00`. The narrow callback restored exact body `[0x004536e0,0x00453732)`/82 bytes/SHA256 `FBCB522B63D7C1AD48E3941E428AF7099395E16D73C1425896BD613950A33F04` and separate alignment `[0x00453732,0x00453740)`/fourteen `0xcc` bytes/SHA256 `1E875C76536C8496BED8C8760B539327F24ACFFBCF0A4B941877B4BFB4C44356`, while preserving all unrelated ignored-ledger entries and UID0000XM ownership, xref, compiler-destruction, and source-replacement facts.
- Dated Gate 2A canonical-body destination repair (`2026-08-17`, commands `000000025556`-`000000025560`) reconciled the five ordinary destinations that still carried stale current hashes or boundaries. The repaired current facts are UID0000XM body `[0x004536e0,0x00453732)`/82 bytes/SHA256 `FBCB522B63D7C1AD48E3941E428AF7099395E16D73C1425896BD613950A33F04`, separate alignment `[0x00453732,0x00453740)`/fourteen `0xcc` bytes/SHA256 `1E875C76536C8496BED8C8760B539327F24ACFFBCF0A4B941877B4BFB4C44356`, constructor body SHA256 `E2C92A3449ED6693F5F2F7933CA215DAE05FDE09FE4C635EE2A9C2FC449525A7`, GetRule body SHA256 `A7C6EA02E0464241B69BADAC2417EE6DE85349D158FD8F045A5DC0D15B4D73EB`, Configure body SHA256 `7C90F35C90A82A8A5E379E68787F2F9CBDF5720FA1F3E77F926FC383325576DB`, and vector-growth body SHA256 `DB6C0E4F6F2DAA5F7EE94BBB589E1433A5BDDFD8ACBC2C80F70840F85EAFA7D2`. Scoped validation and physical reread found zero active stale values; the old 83-byte boundary remains only in explicit historical-correction prose.
- Dated narrow Gate 2A wording repair (`2026-08-17`) corrected the final two stale checked-claim destinations without changing their underlying behavior, metadata, ownership, formal source, or hashes. Command `000000025680` changed UID0000JI's UID0001UN disposition to exact no-source wording with UID00005C H as sole declaration owner. Command `000000025684` changed the MiniMap aggregate's obsolete `FontStyleClearRules` label to the compiler-emitted `FontStyleImplicitDestructor` child split. Both scoped validators returned `ok:1`, and exact physical reread found zero old-phrase occurrences in either destination.
- Dated supervisor Gate 2B observation (`2026-08-17T19:15:00-04:00`): T01, T02, A01-A03, A04-R, and A04-T existed only in the disposable transaction. A04-T accepted the source-facing declaration with `unsigned char effect`, while public `inspect_items` and `stack_frame` canonically returned function item type `void __thiscall(FontStyle *this, unsigned int textColor, unsigned int secondaryColor, unsigned __int8 effect, unsigned int alignment)` and frame row `effect/+0x20/0x1/unsigned __int8`. This is an IDA rendering distinction for the same one-byte unsigned ABI, not a source or behavioral disagreement. The transaction worker was stopped without `idb_save`; none of its changes currently persist. Canonical disk identity remained byte-for-byte unchanged at SHA256 `C453AEF982EAAFA8063F7B554FC37F526E30D0FC79589C1CF7C0B75243DAAC26`, 143,209,618 bytes, last-write UTC `2026-08-17T22:56:16.6600025Z`.
- During read-only research, `by-project-structure/proposed-source-tree.md` changed concurrently from SHA256 `E651D3074869DB3C6CA7C618A3D612F8848D8741C042FF1FED956D739FF12277` to `D99D2A6ECB6298A52A9423B07E7579B39FC6AA087D64791CA365A52739ADC4CA` (last write `2026-08-16T12:30:49-04:00`). B006 neither leased nor wrote it; the FontStyle tree entry and placement paragraph were reread and remain semantically consistent with this report.

## Target

- Target UID: `0000JI`.
- Additional target UIDs: none. All other UIDs in this report are support destinations, not additional report-coverage targets.
- Target path: `by-file/FontStyle.md`.
- Source queue row: `86/89`, zero direct reports and zero additional reports, under `## by-file` -> `### Not-Covered Files - Not Reconstructable` in the assignment-time research tracker.
- Assignment-time supervisor classification was report-only exhaustive whole-file source-quality research; the accepted ordinary callback is now applied, while manual coverage, IDA, and lifecycle authority remain external.
- Current metadata after the accepted ordinary callback: `COMPLETION:94`, `CONFIDENCE:94`, `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/controls/"`, `CANONICAL_OWNER:FILE`.
- Inferred compilation-unit boundary: the authored cluster is the constructor/GetRule/Configure sequence at `0x00499f10-0x00499fda`; the discontiguous `0x004536e0` body and `0x0049ac60` helper are compiler products caused by the header declaration and vector member. Cross-feature use proves a reusable header, while the compact contiguous authored cluster between CheckBox and StaticText code supports a standalone `FontStyle.obj`/`FontStyle.cpp` link unit.

## Current Target State

- The following assignment-time defect snapshot is retained as dated history; it is superseded by the accepted ordinary callback described after it.
- `by-file/FontStyle.md` is SHA256 `C6E22371387CBFBCBE5E4E91D40FB8F3E8FA8891B123F03C512359AF7AA5976F`, 10,317 bytes/98 lines. It correctly identifies the broad role and three core methods but still calls the implicit vector destructor source-facing empty destructor code and treats header separation as unresolved.
- [UID:00005C] `by-class/FontStyle.md` is SHA256 `718B90E026A909B2C94B829B3F56EA0E7F6051FF0EB867CC373B1891C6353536`, 14,509 bytes/174 lines, `89/91`, owner/emitter `0000JI`, reconstructable. Its declaration is incorrectly emitted in CPP, its H is blank, it explicitly declares a destructor, it carries reverse-engineering padding fields, and its prose has a dangling vector-growth table row.
- [UID:0001UN] is `86/91`, owner/emitter `00005C`, reconstructable. Its layout prose is mostly accurate, but its formal CPP emits a redundant comment and its historical IDA type-state claim is stale.
- [UID:0000XM] is `87/92`, owner/emitter `00005C`, reconstructable, and emits an empty `FontStyle::~FontStyle()`. That authored-source interpretation is rejected by the current compiler/EH evidence.
- [UID:00011T] is `86/91`, owner/emitter `00005C`, reconstructable. Its three formal method bodies are behaviorally sound; class/header placement, natural padding, current hashes, and complete live MCP state need incorporation.
- [UID:00011W] is `85/90`, ownerless, non-reconstructable, and non-emitting. Its compiler-vector disposition is correct but its current exact hash, padding, type relationship, and score rationale are incomplete.
- Whole-file inventory: five modeled bodies, of which three are authored out-of-line methods and two are compiler-generated support; six source-level inline accessors with no required out-of-line body; implicit copy construction/assignment/destruction behavior with no additional authored entry point; two source types; zero file-owned globals/statics/string literals/tables/vtables/RTTI/resources/imports.
- Generated source is incomplete. The dated `FontStyle.cpp` snapshot emits declarations in CPP, an unnecessary empty destructor, and a layout comment. `auto-generated/NexusTK/ui/controls/FontStyle.h` does not exist. Dated `StaticTextControlPane.cpp` and `HelpPanes.cpp` use `FontStyle` and `FontStyleRule` without including a defining header.
- Current ordinary state after callback: UID0000JI is `94/94`, UID00005C `94/95`, UID0001UN `94/96`, UID0000XM `93/96`, UID00011T `94/96`, and UID00011W `93/96`; all accepted formal CPP/H, no-code, dependency, source-tree, rename/link, and ignored-ledger changes are physically present and scoped-validated.
- Current generated semantic state was reverified after the Gate 2A destination repair by dated owning refresh command `000000025560` at `2026-08-17T16:23:26-04:00`: FontStyle CPP contains only the header include and constructor/GetRule/Configure in physical order, and FontStyle H contains the complete natural-layout declarations, six inline accessors, three method declarations, and no destructor. Commands `000000025343` and `000000025350` remain historical callback snapshots; later generated identity remains dynamic and requires fresh supervisor physical readback.
- Execution/archive authority remains external and derives only from the report's current path plus validator-owned lifecycle metadata.

## Executive Recommendation

- Keep `FontStyle.cpp` as the direct file owner. It is a reusable UI-control support type used by MiniMap, NewMail, StaticTextControlPane2, and HelpPane; no feature consumer owns the class.
- Generate `FontStyle.h` from [UID:00005C] formal H. Move the class/record declaration there; make the class CPP block only include the header and expand `[[CHILDREN]]`.
- Keep [UID:00011T] as the one authored method child in source position `10`; do not split three already-complete same-owner methods merely to mirror function boundaries.
- Rename/reclassify [UID:0000XM] as `FontStyleImplicitDestructor`, set it non-reconstructable/non-emitting, and leave both formal channels blank. The source declaration must omit an explicit destructor.
- Keep [UID:00011W] ownerless/non-reconstructable/non-emitting and represent it solely through `m_rules.push_back(rule)`.
- Correct `FontStyleRule` so its dword `m_alignment` is at `+0x0c`, not byte `+0x09`; use natural padding in source and explicit tested 4-byte packing in the IDA declaration input so parser defaults cannot change the layout.

## Supervisor Active Recheck

- The assignment required a full by-file reconstruction audit, not a representative method pass. All five modeled bodies, six inline accessors, implicit special-member effects, two types, all direct callers/xrefs/callees, emitted files, manual coverage rows, and related support pages received a disposition.
- No new by-memory split is required. Existing [UID:00011T] precisely groups the three adjacent authored methods; [UID:0000XM] and [UID:00011W] already isolate the two compiler products.
- Every known source-bearing item has exact formal CPP/H text below. Every non-source item has target-specific compiler-covered/no-code proof.
- The prior blockers were not deferred: header ownership, explicit-vs-implicit destructor, natural padding, rule alignment width/offset, source file ownership, vector growth, generated consumer dependencies, and current IDA type state are resolved here.
- Callback recheck: the ordinary documentation/formal-source subset is applied and verified. Exactly six manual-coverage claims and six IDA claims remain deliberately unchecked for independent supervisor closure. The IDA handoff consists of two UDT action groups (`T01-T02`) and five function action groups (`A01-A05`), expanded into fifteen ordered public endpoint stages; no B-agent IDA or lifecycle action occurred.
- Historical Gate 2B boundary report repair first superseded the prior UID0000XM range arithmetic without changing ordinary documents or IDB state. The accepted Gate 2A destination callback has now propagated the exact 82-byte half-open body `[0x004536e0,0x00453732)` and separate fourteen-byte linker alignment `[0x00453732,0x00453740)` through all five affected ordinary destinations.
- Historical Gate 2B report repair first superseded the four erroneous A02-A05 protected body hashes without changing ordinary documents or IDB state. The accepted Gate 2A destination callback has now propagated all five canonical body hashes and the separate alignment hash while preserving exact ranges, byte counts, names, types, frames, comments, xrefs, callees, compiler/source dispositions, and action semantics.
- Fresh Gate 2B UDT reanalysis supersedes the bare T01/T02 parser-default contract and its false automatic field-xref-migration promise. The tested public result is explicit `#pragma pack(4)`, exact size/offset/frame/disassembly readback, retained first-three rule-field xrefs, and an empty replacement `m_alignment` field-xref; no extra operand mutation is authorized.
- Narrow Gate 2A wording recheck confirms UID0001UN emits no source because UID00005C H is the sole declaration owner, and confirms the MiniMap aggregate names the compiler-emitted FontStyleImplicitDestructor child split rather than the rejected ClearRules interpretation.

## Inference Research Guidance Check

- Direct IDA facts are addresses, bytes, hashes, types, frames, comments, xrefs, callees, UDT layouts, and decompiled writes. Documentation facts are current UID routes, generated output, scores, and historical claims. Source names, header split, access control, `std::vector`, and implicit-special-member source shape are evidence-backed inference.
- Existing documentation was treated as fallible. In particular, `ClearRules`, an authored empty destructor, explicit padding arrays, no local UDT, and CPP-only declaration emission were reanalyzed and rejected or historicalized.
- The source uses plausible human C++ rather than decompiler fields: `bool`, `float`, `std::vector<FontStyleRule>`, natural alignment, source methods, and no hand-coded allocator/free logic.
- Stale Wave2/Wave3 text in project-structure history was ignored as authority. Current by-* docs, live IDA, generated output, and the active assignment controlled the result.

## Heuristic / Inference Reanalysis And Validation

| Issue | Best resolution | Evidence and classification |
| --- | --- | --- |
| File owner | Standalone `ui/controls/FontStyle.cpp` plus `FontStyle.h` | Cross-feature use, three contiguous authored methods, current file route, and header necessity; high-probability source-placement inference. |
| Class name | `FontStyle` | Existing cross-project documentation and current local UDT; descriptive/corpus-consistent, not original-symbol proof. |
| Rule name | `FontStyleRule` | Exact 16-byte vector element used by Configure/GetRule and consumers; current UDT and project-wide use. |
| `sub_499F10` | `FontStyle::FontStyle` | Exact 0x20 initialization and seven callers constructing style values; high confidence. |
| `sub_499F60` | `void FontStyle::GetRule(unsigned int, FontStyleRule *) const` | Bounds check plus 16-byte side-effect copy; two callers ignore mixed EAX and consume output. Count/bool/pointer returns are rejected. |
| `sub_499F90` | `FontStyle::Configure` | Appends one complete rule and seven corpus callers already use this name. `AddRule` is semantically plausible but has no stronger lexical evidence; corpus-consistent `Configure` is retained. |
| `sub_4536E0` | compiler-emitted implicit `FontStyle` destructor | Only vector triplet free/reset behavior, EH references from four consumer families, and no authored side effect. `ClearRules` and explicit empty-destructor source are superseded. |
| `sub_49AC60` | compiler `std::vector<FontStyleRule>` growth | Single caller from Configure, 1.5x growth, allocator/memmove/free, maximum-size and large-allocation guards. No project method emits. |
| Enabled field | `bool m_enabled` | Byte storage, values 0/1, gating semantics, and human source convention. Unsigned-byte IDA representation remains binary-compatible but is weaker source shape. |
| Padding | natural compiler padding | `bool` before float and byte effect before dword alignment naturally create the exact three-byte gaps. Explicit `m_padding0`/`m_reserved` arrays are unnecessary reverse-engineering artifacts. |
| Rule offset `+0x0c` | `unsigned int m_alignment` | Configure writes the fourth dword argument to local `+0x0c`; consumers copy/use it as alignment state. Current IDA byte member at `+0x09` is wrong. |
| Destructor declaration | omit it | An implicit destructor invokes vector destruction and reproduces the observed body. An explicit empty destructor adds source not evidenced by behavior. |
| Copy/assignment | implicit compiler-covered operations | HelpPane/StaticText consumers deep-copy scalar/vector state; no separate authored special-member entry point was found. |
| Header | required `FontStyle.h` | Multiple compilation units require complete by-value `FontStyle` and rule declarations; current missing H causes unresolved consumer source. |

Rejected alternatives: MiniMap, MailDialogs, HelpPanes, or StaticTextControlPane ownership is too narrow; a headerless CPP-local type cannot support by-value cross-unit consumers; manually emitted vector free/growth code is compiler-shaped; widening `m_effect` to dword contradicts the byte write; keeping `m_alignment` at `+0x09` contradicts the fourth dword store; an explicit padding array is not needed to preserve ABI.

## Evidence Standards Used

- Highest-weight evidence: live IDA function/decompile/type/frame/comment/xref/callee/field-xref data and current bytes hashed per exact range.
- Corroboration: current by-* pages, generated CPP/H presence, cross-feature class/file docs, manual coverage rows, and only matching historical reports.
- Negative evidence: no FontStyle names, globals, strings, vtables, RTTI, resources, imports, or additional modeled methods; no second caller to the vector-growth helper; no source behavior in the cleanup body beyond vector destruction.
- Confidence is below original-symbol certainty because lexical spellings and original Visual Studio file list are stripped. That does not justify IDA-style names in final source; the most plausible consistent human names are selected.

## Evidence Checked

- IDA MCP: `idb_list`, `server_health`, `inspect_items`, `stack_frame`, `get_comments`, `xrefs_to`, `callees`, `decompile`, `get_bytes`, `type_inspect`, `xrefs_to_field`, bounded `disasm`/`insn_query`, and bounded entity searches for all five functions/types and representative consumers. Public endpoint schemas for `declare_type`, read-only `xrefs_to_field`, and mutating/no-dry-run `set_op_type` were compared before rejecting an unproved field-xref recreation action.
- Exact body hashes: `0x004536e0-0x00453732` `FBCB522B63D7C1AD48E3941E428AF7099395E16D73C1425896BD613950A33F04`; `0x00499f10-0x00499f51` `E2C92A3449ED6693F5F2F7933CA215DAE05FDE09FE4C635EE2A9C2FC449525A7`; `0x00499f60-0x00499f85` `A7C6EA02E0464241B69BADAC2417EE6DE85349D158FD8F045A5DC0D15B4D73EB`; `0x00499f90-0x00499fda` `7C90F35C90A82A8A5E379E68787F2F9CBDF5720FA1F3E77F926FC383325576DB`; `0x0049ac60-0x0049ad74` `DB6C0E4F6F2DAA5F7EE94BBB589E1433A5BDDFD8ACBC2C80F70840F85EAFA7D2`. UID0000XM's separately excluded alignment hash is `1E875C76536C8496BED8C8760B539327F24ACFFBCF0A4B941877B4BFB4C44356`.
- Related docs: UID0000JI, UID00005C, UID0001UN, UID0000XM, UID00011T, UID00011W, `by-memory/-ignored.md`, StaticTextControlPane2, HelpPane, MiniMapDialog, NewMailDialog, their owning by-file pages, consumer by-memory pages UID0004L8/UID0004LB, and `proposed-source-tree.md`.
- Generated audit: `FontStyle.cpp`, absent `FontStyle.h`, `StaticTextControlPane.cpp`, and `HelpPanes.cpp`; repository-wide generated search found FontStyle only in these three CPP files and no generated H.
- Report search terms: `0000JI`, `00005C`, `00011T`, `FontStyle`, `FontStyleRule`, `sub_499F10`, `sub_499F60`, `sub_499F90`, `sub_4536E0`, and `sub_49AC60`.
- Negative bounded IDA search found zero names, strings, or globals matching `FontStyle` or `TextStyle`. Current UDTs are the only named IDB entities.
- No required research check failed or was unavailable. The later accepted ordinary callback ran the serial scoped validators and dated owning generated refresh recorded under Validator Results; no validator lifecycle command was run.

## Claim And Incorporation Ledger

Post-callback allocation: 42 applied/already-present claims and 12 unchecked supervisor-owned claims, partitioned exactly as six manual-coverage claims and six IDA claims. The six IDA claims map to seven action groups (`T01-T02`, `A01-A05`) and fifteen ordered public endpoint stages. Verification state records the current ordinary implementation result; it does not assert report execution or archival.

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| CJI-001 | 0000JI | FontStyle is a reusable UI text-style compilation unit, not a feature-owned helper. | Very high | Four consumer families and three-method authored cluster. | UID0000JI File Role | incorporate | applied |
| CJI-002 | 0000JI | Keep `NexusTK/ui/controls/FontStyle.cpp` as owner path. | High | Current route, link neighborhood, cross-feature fanout. | UID0000JI Source Placement | incorporate | applied |
| CJI-003 | 0000JI | Add required sibling `FontStyle.h`. | Very high | By-value cross-unit consumers and absent generated H. | UID0000JI Header/Generated State | incorporate | applied |
| CJI-004 | 0000JI | Whole-file inventory is five modeled bodies, three authored and two compiler-generated. | Very high | Live function/xref/decompile inventory. | UID0000JI Proposed Contents | incorporate | applied |
| CJI-005 | 0000XM | The exact 82-byte body at `0x004536e0` is implicit destructor lowering, not authored ClearRules or empty-destructor source. | Very high | Commands 25558/25560 prove exact body/alignment hashes; command 25684 proves the MiniMap aggregate now names the compiler-emitted FontStyleImplicitDestructor split. | UID0000XM identity/no-code | reject-stale | applied |
| CJI-006 | 00011W | `0x0049ac60` is compiler vector growth represented by push_back. | Very high | Commands 25557/25559 prove exact 276-byte body `DB6C0E4F6F2DAA5F7EE94BBB589E1433A5BDDFD8ACBC2C80F70840F85EAFA7D2` and compiler-only disposition. | UID00011W no-code | incorporate | applied |
| CJI-007 | 00005C | Six field accessors remain header-inline and require no out-of-line symbols. | High | Direct consumer field reads/writes and no entries. | UID00005C Inline Accessors | incorporate | applied |
| CJI-008 | 00005C | Copy construction, assignment, and destruction remain implicit compiler-covered special members. | High | Consumer deep copies/EH and no authored entries. | UID00005C Special Members | incorporate | applied |
| CJI-009 | 0000JI | File owns no globals, statics, strings, tables, vtables, RTTI, resources, or imports. | Very high | Bounded entity/type/xref searches. | UID0000JI Negative Inventory | incorporate | applied |
| CJI-010 | 00011T | Constructor initializes empty vector, enabled true, two 0.2f values, 1 and 0x80. | Very high | Command 25556 proves exact 65-byte body `E2C92A3449ED6693F5F2F7933CA215DAE05FDE09FE4C635EE2A9C2FC449525A7`. | UID00011T Constructor | incorporate | applied |
| CJI-011 | 00011T | GetRule is void bounded 16-byte copy and leaves output unchanged out of range. | Very high | Command 25556 proves exact 37-byte body `A7C6EA02E0464241B69BADAC2417EE6DE85349D158FD8F045A5DC0D15B4D73EB` and two ignored-EAX callers. | UID00011T GetRule | reject-stale | applied |
| CJI-012 | 00011T | Configure appends one 16-byte rule with byte effect and dword alignment. | Very high | Command 25556 proves exact 74-byte body `7C90F35C90A82A8A5E379E68787F2F9CBDF5720FA1F3E77F926FC383325576DB`, stores, and growth call. | UID00011T Configure | incorporate | applied |
| CJI-013 | 0001UN | FontStyle is 0x20 with bool, natural padding, two floats, two uints, and vector. | Very high | Constructor/cleanup offsets and type layout. | UID0001UN Object Layout | incorporate | applied |
| CJI-014 | 0001UN | FontStyleRule is 0x10 with natural padding and alignment at +0x0c. | Very high | Configure stores and consumers. | UID0001UN Rule Layout | reject-stale | applied |
| CJI-015 | 0001UN | Current IDA FontStyleRule +0x09 byte alignment member is stale and must be corrected. | Very high | Fresh type_inspect versus binary writes. | UID0001UN IDA Status | reject-stale | applied |
| CJI-016 | 00005C | Formal CPP becomes include plus `[[CHILDREN]]`. | Very high | Required sibling header and child route. | UID00005C formal CPP | incorporate | applied |
| CJI-017 | 00005C | Formal H becomes complete human-written declarations without explicit padding/destructor. | Very high | Exact layout and implicit compiler behavior. | UID00005C formal H | incorporate | applied |
| CJI-018 | 00011T | Formal CPP retains exact constructor/GetRule/Configure bodies in address order. | Very high | Binary behavior and current valid draft. | UID00011T formal CPP | incorporate | applied |
| CJI-019 | 0000XM | Both formal channels stay blank and emitter is removed. | Very high | Compiler-covered implicit destructor proof. | UID0000XM formal CPP/H | reject-stale | applied |
| CJI-020 | 0001UN | Both layout formal channels stay blank; remove generated comment pollution. | Very high | Command 25680 proves UID0001UN emits no source and UID00005C H is the sole declaration owner. | UID0001UN formal CPP/H | reject-stale | applied |
| CJI-021 | 00011W | Both growth-helper formal channels remain blank. | Very high | Compiler/template helper proof. | UID00011W formal CPP/H | incorporate | applied |
| CJI-022 | 00011T | Set emitter position 10; constructor, GetRule, Configure remain ordered inside one child. | Very high | Physical addresses and one-owner route. | UID00011T metadata/source order | incorporate | applied |
| CJI-023 | 0000JI | Dated command 25247 proved the assignment-time generated CPP/H defects; dated command 25343 proves clean FontStyle CPP/H callback output. | Very high | Commands 25247/25343 physical readbacks and exact hashes. | UID0000JI Generated Audit | incorporate | applied |
| CJI-024 | 0000JI | Dated assignment-time consumers lacked FontStyle.h; dated command 25343 proves both generated consumers now include it before first use. | Very high | Commands 25247/25343 physical generated searches. | UID0000JI Consumer Dependencies | incorporate | applied |
| CJI-025 | 0000E4 | Add `#include "FontStyle.h"` before StaticTextControlPane2 declaration. | Very high | First complete-type use in generated file. | UID0000E4 formal CPP | incorporate | applied |
| CJI-026 | 000063 | Add `#include "FontStyle.h"` before HelpPane declaration. | Very high | First complete-type use in generated file. | UID000063 formal CPP | incorporate | applied |
| CJI-027 | 0000O8 | Document FontStyle.h dependency and generated include requirement. | High | StaticText by-value/member/rule use. | UID0000O8 Dependency Evidence | incorporate | applied |
| CJI-028 | 0000JU | Document FontStyle.h dependency and generated include requirement. | High | HelpPane by-value/member/rule use. | UID0000JU Dependency Evidence | incorporate | applied |
| CJI-029 | 0001R1 | The proposed source tree now lists FontStyle.cpp and FontStyle.h with the corrected implicit-destructor disposition. | High | Applied tree text and scoped validator command 25341. | Proposed Source Tree FontStyle paragraph | incorporate | applied |
| CJI-030 | 00008C | MiniMap remains a consumer using local style values, not owner. | Very high | Constructor/Configure/cleanup call sites. | UID00008C verify/history | incorporate | already-present |
| CJI-031 | 000096 | NewMail remains a consumer using local style values, not owner. | Very high | Calls 0x47d0d2/0x47d3fa. | UID000096 verify/history | incorporate | already-present |
| CJI-032 | 0000JI | Reject MiniMap, MailDialogs, HelpPanes, StaticText-only, and headerless ownership. | Very high | Cross-feature fanout and complete-type requirement. | UID0000JI Rejected Alternatives | incorporate | applied |
| CJI-033 | 0000JI | Preserve exact authored ranges and compiler padding/boundary exclusions, including UID0000XM's 82-byte body and separate fourteen-byte alignment. | Very high | Commands 25556-25560 verify all five full canonical body hashes, the separate full alignment hash, and zero active stale boundary/hash values. | UID0000JI Boundary Inventory | incorporate | applied |
| CJI-034 | 0000JI | Target metadata is now 94/94 with the path and FILE owner retained; assignment-time metadata was 86/89. | High | All blockers resolved, lexical split still inferred. | UID0000JI metadata | incorporate | applied |
| CJI-035 | 00005C | Raise class 89/91 to 94/95; retain owner/emitter 0000JI and reconstructable true. | High | Complete CPP/H and behavior. | UID00005C metadata | incorporate | applied |
| CJI-036 | 0001UN | Raise layout 86/91 to 94/96; retain owner 00005C, set emitter blank. | Very high | Exact offsets/natural padding/current UDT issue. | UID0001UN metadata | incorporate | applied |
| CJI-037 | 0000XM | Raise 87/92 to 93/96, rename page, set reconstructable false and emitter blank. | Very high | Exact compiler-covered disposition. | UID0000XM metadata/path | incorporate | applied |
| CJI-038 | 00011T | Raise core 86/91 to 94/96; retain owner/emitter 00005C and set position 10. | Very high | Exact three bodies and callers. | UID00011T metadata | incorporate | applied |
| CJI-039 | 00011W | Raise growth 85/90 to 93/96; retain owner NONE/non-reconstructable/no emitter. | Very high | Exact helper/caller/callees/hash. | UID00011W metadata | incorporate | applied |
| CJI-040 | 0000JI | Replace stale by-file manual coverage row with exact 94% row. | Very high | Current row says 84%. | by-file/-coverage-report.md | incorporate | proposed |
| CJI-041 | 00005C | Replace stale class manual coverage row with exact 94% row. | Very high | Current row says 84%. | by-class/-coverage-report.md | incorporate | proposed |
| CJI-042 | 0001UN | Replace struct manual coverage row with exact 94% natural-layout row. | Very high | Current row says 86%. | by-type/by-struct/-coverage-report.md | incorporate | proposed |
| CJI-043 | 0000XM | Replace memory coverage row with the renamed ignored/compiler row at 93% and its corrected 82-byte body boundary. | Very high | Current row retains stale identity, score, and pre-correction boundary evidence. | by-memory/-coverage-report.md | reject-stale | proposed |
| CJI-044 | 00011T | Replace core memory coverage row with exact 94% row. | Very high | Current row says 84%. | by-memory/-coverage-report.md | incorporate | proposed |
| CJI-045 | 00011W | Replace growth memory coverage row with exact ignored 93% row. | Very high | Current row says 80%. | by-memory/-coverage-report.md | incorporate | proposed |
| CJI-046 | 0000XM | Preserve the implicit-destructor ignored entry and correct drift to the exact 82-byte body plus separate fourteen-byte alignment without changing UID00011W or unrelated entries. | Very high | Command 25469 and physical reread prove the exact body/alignment hashes and retained compiler-only/source-replacement facts. | by-memory/-ignored.md lines 1324-1328 | incorporate | applied |
| CJI-047 | 0001UN | Apply deterministic 4-byte-packed FontStyleRule/FontStyle UDT declarations; require exact natural-layout offsets, unchanged consumer frame, exact `style.m_alignment` disassembly rendering, retained first-three rule-field xrefs, and the factual empty replacement `m_alignment` public field-xref. | Very high | Tested bare-versus-`#pragma pack(4)` public declare_type behavior, type_inspect, stack_frame, disassembly, and xrefs_to_field. | Supervisor Gate 2B T01/T02 type handoff | incorporate | proposed |
| CJI-048 | 0000XM | Rename/type/comment implicit destructor without changing its exact 82-byte body, separate alignment, frame, or xrefs. | Very high | Corrected body/alignment hashes and EH/direct xrefs. | Supervisor Gate 2B A01 | incorporate | proposed |
| CJI-049 | 00011T | Rename/type/comment constructor while preserving body `E2C92A3449ED6693F5F2F7933CA215DAE05FDE09FE4C635EE2A9C2FC449525A7`, frame, and xrefs. | Very high | Exact 65-byte initialization and seven callers; repeated canonical readback. | Supervisor Gate 2B A02 | incorporate | proposed |
| CJI-050 | 00011T | Rename/type/comment GetRule with exact void signature and frame delta while preserving body `A7C6EA02E0464241B69BADAC2417EE6DE85349D158FD8F045A5DC0D15B4D73EB`. | Very high | Exact 37-byte copy body and two ignored-EAX callers; dated A03 transaction-local readback passed but was discarded unsaved after the later A04-T hard stop. | Supervisor Gate 2B A03 | incorporate | proposed |
| CJI-051 | 00011T | Rename/type/comment Configure with human-source `unsigned char effect`, exact public-IDA `unsigned __int8 effect` item/frame readback, and preserved body `7C90F35C90A82A8A5E379E68787F2F9CBDF5720FA1F3E77F926FC383325576DB`. | Very high | Exact 74-byte append body, seven ignored-return callers, and dated A04-T canonical type/frame readback from the discarded unsaved transaction. | Supervisor Gate 2B A04 | incorporate | proposed |
| CJI-052 | 00011W | Add repeatable compiler-support comment only; protect function identity/type/frame and body `DB6C0E4F6F2DAA5F7EE94BBB589E1433A5BDDFD8ACBC2C80F70840F85EAFA7D2`. | Very high | Exact 276-byte single-caller compiler helper; repeated canonical readback. | Supervisor Gate 2B A05/protections | incorporate | proposed |
| CJI-053 | 0000JI | Scoped-validate every changed ordinary page, refresh owner once, and physically verify all three generated CPP plus FontStyle H. | Very high | Commands 25330-25343, 25350, 25469, 25556-25560, 25680, and 25684 with physical FontStyle CPP/H readback. | Validator Results | incorporate | applied |
| CJI-054 | 0000JI | Report execution/archive and all manual coverage/IDA mutation remain supervisor-owned. | Very high | B-agent lifecycle boundary. | Changed Files/Follow-Up | incorporate | applied |

## Positive Evidence Summary

- The three source-authored methods are contiguous and ordered at `0x00499f10`, `0x00499f60`, and `0x00499f90`; their bodies operate on one exact 0x20-byte object and 16-byte rule records.
- Constructor and Configure each have seven direct callers spanning MiniMap and NewMail plus HelpPane construction; GetRule has two calls in HelpPane drawing. The class is reusable, not feature-owned.
- The current UDT size and most members agree with the binary. The sole material rule-layout defect is directly falsified by the dword store at local `+0x0c`.
- The cleanup body and growth helper exhibit canonical MSVC vector lowering, including the same large-allocation guard and free helper. Normal C++ vector source regenerates them.
- Cross-unit by-value members and rule references require a header. The absent generated H and missing includes are observable source-closure defects, not speculative style preferences.

## IDA MCP Facts

- `0x004536e0`, `sub_4536E0`, type `void __thiscall(_DWORD *this)`, body `[0x004536e0,0x00453732)`, 82 bytes, raw-byte SHA256 `FBCB522B63D7C1AD48E3941E428AF7099395E16D73C1425896BD613950A33F04`. The terminal instruction is the five-byte call at `0x0045372d`; `[0x00453732,0x00453740)` is a separate fourteen-byte all-`0xcc` span with SHA256 `1E875C76536C8496BED8C8760B539327F24ACFFBCF0A4B941877B4BFB4C44356`. Frame: only `__return_address/+0x4/0x4/_UNKNOWN *`. AR absent; AP absent; FR absent; FP absent. Inbound xrefs are exactly `{0x45214a,0x452be3,0x5f9bc9,0x5f9c8d,0x5f9cc0,0x5f9cff,0x5f9d23,0x5fbf65,0x5fd1f0,0x5ff4d4}`; direct callees `{0x5c7526,0x5cd607}`.
- `0x00499f10`, `sub_499F10`, type `_DWORD *__thiscall(_DWORD *this)`, body `[0x00499f10,0x00499f51)`, 65 bytes, raw-byte SHA256 `E2C92A3449ED6693F5F2F7933CA215DAE05FDE09FE4C635EE2A9C2FC449525A7`. Frame: `var_4/+0x0/0x4/_DWORD`, saved `+0x4`, return `+0x8`. All four comment channels absent. Callers exactly `{0x450e3e,0x451f32,0x452408,0x452887,0x452ad2,0x47d0d2,0x4c69d2}`; no callees.
- `0x00499f60`, `sub_499F60`, type `unsigned int __thiscall(_DWORD *this, unsigned int, _OWORD *)`, body `[0x00499f60,0x00499f85)`, 37 bytes, raw-byte SHA256 `A7C6EA02E0464241B69BADAC2417EE6DE85349D158FD8F045A5DC0D15B4D73EB`. Frame: saved `+0x0`, return `+0x4`, `arg_0/+0x8/0x4/_DWORD`, `arg_4/+0xc/0x4/_DWORD`. All comment channels absent. Callers exactly `{0x4c6723,0x4c67b3}`; no callees.
- `0x00499f90`, `sub_499F90`, type `_OWORD *__thiscall(char *this, int, int, char, int)`, body `[0x00499f90,0x00499fda)`, 74 bytes, raw-byte SHA256 `7C90F35C90A82A8A5E379E68787F2F9CBDF5720FA1F3E77F926FC383325576DB`. Frame: `var_10/+0x0/0x10/int[4]`, saved `+0x10`, return `+0x14`, args at `+0x18/+0x1c/+0x20/+0x24` with sizes `4/4/1/4`. All entry comment channels absent. Callers exactly `{0x450f22,0x451f74,0x451f8d,0x4528be,0x452b09,0x452c2b,0x47d3fa}`; sole callee `0x49ac60`.
- `0x0049ac60`, `sub_49AC60`, type `int __thiscall(int this, void *Src, _OWORD *)`, body `[0x0049ac60,0x0049ad74)`, 276 bytes, raw-byte SHA256 `DB6C0E4F6F2DAA5F7EE94BBB589E1433A5BDDFD8ACBC2C80F70840F85EAFA7D2`. Frame: locals `var_C/+0xc`, `var_8/+0x10`, `var_4/+0x14`, saved `+0x18`, return `+0x1c`, `Src/+0x20/void *`, `arg_4/+0x24/int`. All entry comment channels absent. Sole caller `0x499fcf`; callees `{0x421500,0x49ba30,0x5c7526,0x5c9b30,0x5cd607}`.
- Literal durable Gate 2B prestate before the failed unsaved type tests: `FontStyle` is size 32 and places scalar/vector fields at the correct offsets but names its natural `+0x01` gap `_alignment`; `FontStyleRule` is size 16 with byte `m_alignment` at `+0x09` and `_reserved/+0x0a/6`, while exact binary/source layout requires dword `m_alignment` at `+0x0c`. The failed bare declaration instead produced a non-durable size-14 layout with dword `m_alignment/+0x0a`, `style/+0x38/0x0e/FontStyleRule`, and `mov [ebp+style.m_alignment+2], 0` at `0x004c6674`; it was not saved and is not an acceptable poststate.
- Literal durable field-xref prestate is `m_textColor -> {0x4c666d data}`, `m_secondaryColor -> {0x4c6666 data}`, `m_effect -> {0x4c667b data}`, stale byte `m_alignment -> {}`, and `_reserved -> {0x4c6674 data}`. The tested packed replacement retained the first three sets, deleted `_reserved`, left replacement dword `m_alignment -> {}`, and independently changed the stack-variable rendering at `0x004c6674` to exact `mov [ebp+style.m_alignment], 0`; the rendering is required semantic readback, not evidence of a public field-xref relation.
- The packed rollback-copy readback also preserved the complete `HelpPane__SimpleHelpTextPartPane__OnPaint` frame: `var_40/+0x0c/4/_DWORD`, `var_3C/+0x10/4/_DWORD`, `var_38/+0x14/4/_DWORD`, `point/+0x18/8/Point`, `var_2C/+0x20/4/_DWORD`, `var_28/+0x24/4/_DWORD`, `var_24/+0x28/0x10/struct RectBounds`, `style/+0x38/0x10/FontStyleRule`, `var_4/+0x48/4/_DWORD`, saved `+0x4c/4/_DWORD`, and return `+0x50/4/_UNKNOWN *`.
- Bounded entity searches found no FontStyle/TextStyle named functions, globals, or strings. No FontStyle vtable/RTTI exists because the class is non-polymorphic.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `FontStyle` compilation unit | UID0000JI `by-file/FontStyle.md` | File owner and complete route | yes | FILE | current 94/94; assignment-time 86/89 | Standalone CPP and required H route are present. |
| `FontStyle` class | UID00005C `by-class/FontStyle.md` | Declaration, inline accessors, child owner | yes | UID0000JI | 89/91 -> 94/95 | Move declaration to H; CPP include plus children. |
| `FontStyle`/rule layout | UID0001UN | Two source types and offsets | yes, docs | UID00005C | 86/91 -> 94/96 | No emit; declaration owned by UID00005C. |
| `[0x00499f10,0x00499f51)` | UID00011T | Authored default constructor | yes | UID00005C | 86/91 -> 94/96 | Emit first. |
| `[0x00499f51,0x00499f60)` | no source UID | 15-byte `0xcc` alignment | no | linker | n/a | Exclude. |
| `[0x00499f60,0x00499f85)` | UID00011T | Authored bounded rule copy | yes | UID00005C | 86/91 -> 94/96 | Emit second. |
| `[0x00499f85,0x00499f90)` | no source UID | 11-byte `0xcc` alignment | no | linker | n/a | Exclude. |
| `[0x00499f90,0x00499fda)` | UID00011T | Authored rule append | yes | UID00005C | 86/91 -> 94/96 | Emit third. |
| `[0x00499fda,0x00499fe0)` | no source UID | 6-byte `0xcc` alignment before StaticText code | no | linker | n/a | Exclude. |
| `[0x004536e0,0x00453732)` | UID0000XM `by-memory/0x004536e0-0x00453732.FontStyleImplicitDestructor.md` | Exact 82-byte implicit vector destructor lowering | no | UID00005C semantic | current 93/96; assignment-time 87/92 | Already reclassified and non-emitting; renamed path exists and active links are repaired. |
| `[0x00453732,0x00453740)` | no source UID | Fourteen-byte all-`0xcc` alignment | no | linker | n/a | Exclude from body hash, source, and ownership. |
| `[0x0049ac60,0x0049ad74)` | UID00011W | Compiler vector growth | no | NONE | 85/90 -> 93/96 | Keep ignored/no emit. |
| `[0x0049ad74,0x0049ad80)` | ignored ledger | 12-byte `0xcc` alignment | no | linker | n/a | Exclude. |
| Six inline accessors | UID00005C H | bool/opacity/color field access | compiler-covered inline | UID00005C | included | Declare/define inline in H. |
| Implicit copy construction/assignment | UID00005C H | Deep scalar/vector copies used by consumers | compiler-covered | UID00005C | included | No authored out-of-line body. |
| Globals/statics/strings/tables | none | Searched file-owned data | n/a | n/a | n/a | None found. |
| Vtable/RTTI/resources/imports | none | Non-polymorphic local support type | n/a | n/a | n/a | None found. |

Inventory totals: five modeled code bodies, three source-authored; two compiler-generated bodies; six source inline methods; two source type declarations; three implicit special-member behaviors including the modeled destructor; zero owned globals/data/string/table/vtable/RTTI/resource/import items. Every item above has behavior, ownership, formal CPP/H or no-code, score, document, ledger, and checklist disposition.

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x004536e0` | direct calls `0x45214a`, `0x452be3`; EH refs `0x5f9bc9`, `0x5f9c8d`, `0x5f9cc0`, `0x5f9cff`, `0x5f9d23`, `0x5fbf65`, `0x5fd1f0`, `0x5ff4d4` | Generic implicit cleanup across MiniMap, NewMail, StaticText2, and HelpPane. |
| `0x004536e0` | callees `sub_5C7526`, invalid-parameter failure | Vector free with MSVC large-allocation protection. |
| `0x00499f10` | five MiniMap sites, NewMail `0x47d0d2`, HelpPane `0x4c69d2` | Reusable constructor fanout. |
| `0x00499f60` | HelpPane draw calls `0x4c6723`, `0x4c67b3` | Bounded output-copy accessor; EAX ignored. |
| `0x00499f90` | six MiniMap sites and NewMail `0x47d3fa` | Rule append/configuration; observed effects 0/1/3. |
| `0x0049ac60` | sole call `0x499fcf` from Configure | Compiler slow path, not public API. |
| `FontStyleRule +0/+4/+8` | HelpPane field xrefs at `0x4c666d/0x4c6666/0x4c667b` | Confirms text/secondary/effect semantics. |
| `FontStyleRule +0x0c` | no current field xref because UDT is wrong; binary consumers copy the dword | UDT correction required, not negative semantic evidence. |

## Documentation Evidence And IDA Status

- Existing docs correctly establish the 0x20 object, 16-byte rule stride, vector triplet, caller fanout, void GetRule behavior, Configure append, and separate file owner.
- Stale/incomplete docs are the source-facing `ClearRules`/empty destructor, explicit padding fields, layout comment emission, blank H, missing consumer includes, outdated manual coverage percentages, dangling class table row, and older "no local UDT" statements.
- The current IDB improved beyond those historical reports by adding `FontStyle` and `FontStyleRule` UDTs, but the rule UDT is materially wrong at `+0x09/+0x0c`.
- Dated generated command 25247 is structurally incomplete. Final authority must be a fresh post-callback owner validation and physical generated readback.

## Ranked Ownership Analysis

### 1. Standalone `ui/controls/FontStyle.cpp` and `FontStyle.h`

- Evidence for: compact contiguous authored method cluster, reusable cross-feature type, required shared complete declaration, current owner route, and proposed source-tree placement.
- Evidence against: authored cluster is physically adjacent to StaticTextControlPane2 and exact original project file list is unavailable.
- Decision: accepted with high confidence. A separate small object file naturally links adjacent to related control objects.

### 2. Fold into `StaticTextControlPane.cpp`

- Evidence for: immediate address adjacency and StaticText2 by-value ownership/use.
- Evidence against: MiniMap, NewMail, and HelpPane all need the same type; a shared H is still mandatory; current route and separate three-method cluster fit a standalone helper file.
- Decision: rejected as weaker physical placement.

### 3. Fold into MiniMap, MailDialogs, or HelpPanes

- Evidence for: each is a direct constructor/configure or GetRule consumer; the implicit destructor is linked inside the MiniMap corridor.
- Evidence against: none owns the complete fanout. The destructor location is COMDAT/EH compiler placement, not authored-source locality.
- Decision: rejected.

### Proposed new file/grouping, if applicable

- Proposed owner/name/path: existing `NexusTK/ui/controls/FontStyle.cpp` plus new generated sibling `NexusTK/ui/controls/FontStyle.h`.
- Full contents: H owns `FontStyleRule`, `FontStyle`, six inline accessors, three authored method declarations, and implicit special members; CPP owns constructor, GetRule, and Configure definitions.
- Rejected contents: vector destructor lowering, vector growth helper, EH refs, alignment, globals, feature consumers, and consumer-owned draw logic.
- Inference: narrow standalone reusable support module.

## Source Placement

- Recommended placement is `NexusTK/ui/controls/FontStyle.cpp` and `.h`.
- It fits the CheckBox/FontStyle/StaticText binary neighborhood and shared UI-control semantics while allowing MiniMap, mail, and help source files to include one reusable declaration.
- The prior uncertainty about whether declarations lived only in CPP is resolved negatively: by-value use in independent generated modules requires a shared definition. A private forward declaration is insufficient for `FontStyle m_fontStyle`.
- Exact original file name remains inferred rather than symbol-proven, which caps the file score at 94 rather than 100; no source-quality blocker remains.

## Range / Split / Padding / Reclassification Analysis

- Exact authored ranges are `[0x00499f10,0x00499f51)`, `[0x00499f60,0x00499f85)`, and `[0x00499f90,0x00499fda)`. Intervening 15-, 11-, and 6-byte `0xcc` spans are linker alignment and remain excluded.
- UID00011T remains a valid one-owner aggregate. Its internal source order is exact and no mixed emitter behavior remains after compiler bodies stay separate.
- UID0000XM exact body is `[0x004536e0,0x00453732)`, 82 bytes, followed by the separately hashed fourteen-byte all-`0xcc` alignment `[0x00453732,0x00453740)`. The first alignment byte is not part of the function. Retain the compiler-generated implicit-destructor, same-UID, non-emitting disposition.
- UID00011W exact body is `[0x0049ac60,0x0049ad74)` followed by 12 `0xcc` bytes. Keep ownerless, ignored, and non-emitting.
- UID0001UN should remain a documentation/type page but lose its emitter and comment fragment because UID00005C H is the sole declaration owner.
- No new function split, range expansion, or padding ownership is recommended.

## Negative Evidence Summary

- No original symbols prove the exact lexical names. That does not justify retaining `sub_` or `_DWORD`; corpus-consistent human names are selected.
- No vtable or RTTI exists for FontStyle; that is expected for a non-polymorphic value type and does not weaken class identity.
- No named FontStyle/TextStyle globals, strings, tables, resources, or imports exist.
- No caller uses GetRule's mixed EAX value; return-bearing interpretations are rejected.
- No source-visible behavior in `0x004536e0` supports `ClearRules`; it is only vector destruction/reset.
- No second caller or feature semantics supports promoting `0x0049ac60` to a NexusTK method.
- Address adjacency to MiniMap or StaticText is insufficient to override complete cross-feature ownership.

## IDA Rename / Type / Comment Recommendations

Classification is `apply` for seven action groups: two UDT groups `T01-T02` and five function groups `A01-A05`. They expand to fifteen ordered public endpoint stages: `T01`, `T02`, `A01-R`, `A01-T`, `A01-C`, `A02-R`, `A02-T`, `A02-C`, `A03-R`, `A03-T`, `A03-C`, `A04-R`, `A04-T`, `A04-C`, and `A05-C`. The supervisor must select a fresh canonical DB, attest it, take a backup, re-read each literal prestate, apply stages in this order, hard-stop without save on any mismatch, then perform complete post-save readback. Session names below are dated evidence only. All mutations and saving are supervisor-owned. The dated `2026-08-17T19:15:00-04:00` attempt reached transaction-local T01, T02, A01-A03, A04-R, and A04-T, then stopped because A04-T's public IDA rendering differed from the report's old literal spelling. The worker was terminated without `idb_save`, the canonical SHA/size/mtime remained `C453AEF982EAAFA8063F7B554FC37F526E30D0FC79589C1CF7C0B75243DAAC26` / 143,209,618 / `2026-08-17T22:56:16.6600025Z`, and no transaction-local change currently persists or earns claim credit.

### Type actions

- **T01 apply via public `declare_type` with deterministic packing**. Literal durable UDT prestate: named UDT `FontStyleRule`, kind UDT, size 16, five members exactly `m_textColor/+0x00/4/unsigned int`, `m_secondaryColor/+0x04/4/unsigned int`, `m_effect/+0x08/1/unsigned __int8`, `m_alignment/+0x09/1/unsigned __int8`, `_reserved/+0x0a/6/unsigned __int8[6]`. Literal durable field-xref prestate is `m_textColor -> {0x4c666d data}`, `m_secondaryColor -> {0x4c6666 data}`, `m_effect -> {0x4c667b data}`, `m_alignment -> {}`, `_reserved -> {0x4c6674 data}`; all four nonempty xrefs belong to `HelpPane__SimpleHelpTextPartPane__OnPaint` at `0x004c6630`. That consumer's complete frame must initially be `var_40/+0x0c/4/_DWORD`, `var_3C/+0x10/4/_DWORD`, `var_38/+0x14/4/_DWORD`, `point/+0x18/8/Point`, `var_2C/+0x20/4/_DWORD`, `var_28/+0x24/4/_DWORD`, `var_24/+0x28/0x10/struct RectBounds`, `style/+0x38/0x10/FontStyleRule`, `var_4/+0x48/4/_DWORD`, saved `+0x4c/4/_DWORD`, return `+0x50/4/_UNKNOWN *`. Submit one public `declare_type` request whose exact `decls` text is the line `#pragma pack(4)`, then a literal newline, then `struct FontStyleRule { unsigned int m_textColor; unsigned int m_secondaryColor; unsigned char m_effect; unsigned int m_alignment; };`; the explicit pragma is mandatory because the bare declaration was proven to parse as size 14 with `m_alignment/+0x0a`. The only permitted UDT delta is removal of byte `m_alignment` and `_reserved`, creation of dword `m_alignment/+0x0c/4/unsigned int`, and conversion of `+0x09..+0x0b` to unnamed natural padding; size remains 16, member count becomes four, and the first three members remain byte-for-byte identical. Factual reproducible field-xref poststate is `m_textColor -> {0x4c666d data}`, `m_secondaryColor -> {0x4c6666 data}`, `m_effect -> {0x4c667b data}`, replacement `m_alignment -> {}`, with `_reserved` absent/not queryable. Complete consumer-frame poststate remains exactly the eleven rows above, including `style/+0x38/0x10/FontStyleRule`; bounded disassembly at `0x004c6674` must render exactly `mov [ebp+style.m_alignment], 0`. That rendering is an independent required readback and does not imply an `xrefs_to_field` result. No `set_op_type` or other operand action is authorized: the public schema has no field-xref writer or dry-run, and no tested safe action recreates the deleted `_reserved` relation without risking stack-variable semantics. Hard-stop without save if the parsed UDT is size 14, if `m_alignment` is at `+0x0a`, if any first-three field xref changes, if replacement `m_alignment` gains an unproved relation, if the consumer frame/display differs, or if any other protected state drifts.
  - T01 literal physical-IDB protection, required unchanged before and after: `0x004536e0` head `[0x004536e0,0x004536e1)`, code/not-data, width 1, name `sub_4536E0`, function type `void __thiscall(_DWORD *this)`, no data type, entry byte `56`, enclosing range `[0x004536e0,0x00453732)`/82/body SHA256 `FBCB522B63D7C1AD48E3941E428AF7099395E16D73C1425896BD613950A33F04`; `0x00499f10` head `[0x00499f10,0x00499f11)`, code/not-data, width 1, name `sub_499F10`, function type `_DWORD *__thiscall(_DWORD *this)`, no data type, entry byte `55`, enclosing range `[0x00499f10,0x00499f51)`/65/body SHA256 `E2C92A3449ED6693F5F2F7933CA215DAE05FDE09FE4C635EE2A9C2FC449525A7`; `0x00499f60` head `[0x00499f60,0x00499f61)`, code/not-data, width 1, name `sub_499F60`, function type `unsigned int __thiscall(_DWORD *this, unsigned int, _OWORD *)`, no data type, entry byte `55`, enclosing range `[0x00499f60,0x00499f85)`/37/body SHA256 `A7C6EA02E0464241B69BADAC2417EE6DE85349D158FD8F045A5DC0D15B4D73EB`; `0x00499f90` head `[0x00499f90,0x00499f91)`, code/not-data, width 1, name `sub_499F90`, function type `_OWORD *__thiscall(char *this, int, int, char, int)`, no data type, entry byte `55`, enclosing range `[0x00499f90,0x00499fda)`/74/body SHA256 `7C90F35C90A82A8A5E379E68787F2F9CBDF5720FA1F3E77F926FC383325576DB`; `0x0049ac60` head `[0x0049ac60,0x0049ac61)`, code/not-data, width 1, name `sub_49AC60`, function type `int __thiscall(int this, void *Src, _OWORD *)`, no data type, entry byte `55`, enclosing range `[0x0049ac60,0x0049ad74)`/276/body SHA256 `DB6C0E4F6F2DAA5F7EE94BBB589E1433A5BDDFD8ACBC2C80F70840F85EAFA7D2`. At all five heads: `AR absent; AP absent; FR absent; FP absent`. No physical item head, kind, width, name, function/data type, byte, function range, body hash, or comment channel may change. Hard-stop without save if any literal UDT, field-xref, or physical protection differs.
- **T02 apply after T01 via public `declare_type` with deterministic packing**. Literal UDT prestate includes T01's complete factual `FontStyleRule` poststate: kind UDT, size 16, four members at `+0x00/+0x04/+0x08/+0x0c` with sizes `4/4/1/4` and types `unsigned int/unsigned int/unsigned __int8/unsigned int`, unnamed gap `+0x09..+0x0b`, field xrefs `{0x4c666d}/{0x4c6666}/{0x4c667b}/{}` respectively, deleted `_reserved` absent, the complete eleven-row consumer frame unchanged, and exact `0x004c6674` rendering `mov [ebp+style.m_alignment], 0`. The independently inspected `FontStyle` prestate is kind UDT, size 32, nine members exactly `m_enabled/+0x00/1/unsigned __int8`, `_alignment/+0x01/3/unsigned __int8[3]`, `m_parentOpacity/+0x04/4/float`, `m_textOpacity/+0x08/4/float`, `m_foregroundColor/+0x0c/4/unsigned int`, `m_backgroundColor/+0x10/4/unsigned int`, `m_rulesBegin/+0x14/4/FontStyleRule *`, `m_rulesEnd/+0x18/4/FontStyleRule *`, `m_rulesCapacity/+0x1c/4/FontStyleRule *`; every listed `FontStyle` field has an empty field-xref set. Submit one public `declare_type` request whose exact `decls` text is the line `#pragma pack(4)`, then a literal newline, then `struct FontStyle { bool m_enabled; float m_parentOpacity; float m_textOpacity; unsigned int m_foregroundColor; unsigned int m_backgroundColor; FontStyleRule *m_rulesBegin; FontStyleRule *m_rulesEnd; FontStyleRule *m_rulesCapacity; };`. The only permitted T02 delta is `m_enabled` type to `bool`, removal of named `_alignment`, conversion of `+0x01..+0x03` to unnamed natural padding, and member count from nine to eight; size stays 32 and all seven members from `+0x04` through `+0x1c` retain exact names, offsets, widths, and types. Expected poststate has all eight `FontStyle` field-xref sets still empty and leaves the complete T01 UDT, field-xref, consumer-frame, and disassembly-rendering poststate unchanged. Hard-stop without save on parser-default drift, any new/missing field relation beyond this literal contract, any consumer-frame/display change, or any other protected delta.
  - T02 literal physical-IDB protection, required unchanged before and after: `0x004536e0` head `[0x004536e0,0x004536e1)`, code/not-data, width 1, name `sub_4536E0`, function type `void __thiscall(_DWORD *this)`, no data type, entry byte `56`, enclosing range `[0x004536e0,0x00453732)`/82/body SHA256 `FBCB522B63D7C1AD48E3941E428AF7099395E16D73C1425896BD613950A33F04`; `0x00499f10` head `[0x00499f10,0x00499f11)`, code/not-data, width 1, name `sub_499F10`, function type `_DWORD *__thiscall(_DWORD *this)`, no data type, entry byte `55`, enclosing range `[0x00499f10,0x00499f51)`/65/body SHA256 `E2C92A3449ED6693F5F2F7933CA215DAE05FDE09FE4C635EE2A9C2FC449525A7`; `0x00499f60` head `[0x00499f60,0x00499f61)`, code/not-data, width 1, name `sub_499F60`, function type `unsigned int __thiscall(_DWORD *this, unsigned int, _OWORD *)`, no data type, entry byte `55`, enclosing range `[0x00499f60,0x00499f85)`/37/body SHA256 `A7C6EA02E0464241B69BADAC2417EE6DE85349D158FD8F045A5DC0D15B4D73EB`; `0x00499f90` head `[0x00499f90,0x00499f91)`, code/not-data, width 1, name `sub_499F90`, function type `_OWORD *__thiscall(char *this, int, int, char, int)`, no data type, entry byte `55`, enclosing range `[0x00499f90,0x00499fda)`/74/body SHA256 `7C90F35C90A82A8A5E379E68787F2F9CBDF5720FA1F3E77F926FC383325576DB`; `0x0049ac60` head `[0x0049ac60,0x0049ac61)`, code/not-data, width 1, name `sub_49AC60`, function type `int __thiscall(int this, void *Src, _OWORD *)`, no data type, entry byte `55`, enclosing range `[0x0049ac60,0x0049ad74)`/276/body SHA256 `DB6C0E4F6F2DAA5F7EE94BBB589E1433A5BDDFD8ACBC2C80F70840F85EAFA7D2`. At all five heads: `AR absent; AP absent; FR absent; FP absent`. No physical item head, kind, width, name, function/data type, byte, function range, body hash, comment channel, unrelated named type, or T01 result may change. Hard-stop without save if any literal UDT, field-xref, or physical protection differs.

### Function actions

- **A01-R apply via public `rename`, `pure:true`** at `0x004536e0`. Literal prestate: name `sub_4536E0`; type `void __thiscall(_DWORD *this)`; frame exactly `__return_address/+0x4/0x4/_UNKNOWN *`; `AR absent; AP absent; FR absent; FP absent`; range `[0x004536e0,0x00453732)`; size 82; body SHA256 `FBCB522B63D7C1AD48E3941E428AF7099395E16D73C1425896BD613950A33F04`; terminal instruction bytes at `0x0045372d` are `e8 d5 9e 17 00`; successor alignment is exactly `[0x00453732,0x00453740)`, fourteen `0xcc` bytes, SHA256 `1E875C76536C8496BED8C8760B539327F24ACFFBCF0A4B941877B4BFB4C44356`; inbound set exactly `{0x45214a,0x452be3,0x5f9bc9,0x5f9c8d,0x5f9cc0,0x5f9cff,0x5f9d23,0x5fbf65,0x5fd1f0,0x5ff4d4}`; callees exactly `{0x5c7526,0x5cd607}`. Expected poststate changes only name to `FontStyle__Destructor`; all other fields, including the separate body/alignment hashes and boundary, remain literal prestate. Hard-stop on collision, if `0x00453732` is modeled inside the function, or on any protected drift.
- **A01-T apply via public `set_type` after A01-R**. Prestate is the complete A01-R poststate with name `FontStyle__Destructor`; submit signature `void __thiscall FontStyle__Destructor(FontStyle *this)`. Expected poststate changes only function tinfo; frame remains exactly the sole return row; all comments, range/hash/xrefs/callees remain exact. Hard-stop if any frame row appears or protected fact changes.
- **A01-C apply via public `set_repeatable_comments` after A01-T**. Prestate is the complete A01-T poststate with FP absent. Set FP exactly `Compiler-emitted implicit FontStyle destructor for the std::vector<FontStyleRule> member; frees valid storage and clears the vector triplet. Source omits an explicit destructor.` Expected poststate changes only FP; AR/AP/FR remain absent and all name/type/frame/range/hash/xrefs/callees remain exact.
- **A02-R apply via public `rename`, `pure:true`** at `0x00499f10`. Literal prestate: name `sub_499F10`; type `_DWORD *__thiscall(_DWORD *this)`; frame exactly `var_4/+0/4/_DWORD`, saved `+4/4/_DWORD`, return `+8/4/_UNKNOWN *`; `AR absent; AP absent; FR absent; FP absent`; range `[0x00499f10,0x00499f51)`; size 65; body hash `E2C92A3449ED6693F5F2F7933CA215DAE05FDE09FE4C635EE2A9C2FC449525A7`; inbound exactly `{0x450e3e,0x451f32,0x452408,0x452887,0x452ad2,0x47d0d2,0x4c69d2}`; callees empty. Expected poststate changes only name to `FontStyle__Constructor`. Hard-stop on collision or any other literal prestate/protected-state drift.
- **A02-T apply via public `set_type` after A02-R**. Complete prestate is A02-R poststate. Submit `FontStyle *__thiscall FontStyle__Constructor(FontStyle *this)`. Expected poststate changes only function tinfo; all three frame rows, comments, range/hash, caller set, and empty callee set remain exact. Hard-stop on frame drift.
- **A02-C apply via public `set_repeatable_comments` after A02-T**. Complete prestate is A02-T poststate with FP absent. Set FP exactly `Initializes FontStyle with enabled state, 0.2f parent/text opacity, colors 1 and 0x80, and an empty FontStyleRule vector.` Expected poststate changes only FP; all other literal state remains exact.
- **A03-R apply via public `rename`, `pure:true`** at `0x00499f60`. Literal prestate: name `sub_499F60`; type `unsigned int __thiscall(_DWORD *this, unsigned int, _OWORD *)`; frame exactly saved `+0/4/_DWORD`, return `+4/4/_UNKNOWN *`, `arg_0/+8/4/_DWORD`, `arg_4/+c/4/_DWORD`; `AR absent; AP absent; FR absent; FP absent`; range `[0x00499f60,0x00499f85)`; size 37; body hash `A7C6EA02E0464241B69BADAC2417EE6DE85349D158FD8F045A5DC0D15B4D73EB`; inbound exactly `{0x4c6723,0x4c67b3}`; callees empty. Expected poststate changes only name to `FontStyle__GetRule`. Hard-stop on collision or any other literal prestate/protected-state drift.
- **A03-T apply via public `set_type` after A03-R**. Complete prestate is A03-R poststate. Submit `void __thiscall FontStyle__GetRule(FontStyle *this, unsigned int index, FontStyleRule *outRule)`. Expected function tinfo exact; frame becomes saved `+0/4/_DWORD`, return `+4/4/_UNKNOWN *`, `index/+8/4/unsigned int`, `outRule/+c/4/FontStyleRule *`; no row added/deleted/moved/resized. All comments, range/hash/xrefs/callees remain exact. Hard-stop if public endpoint readback differs.
- **A03-C apply via public `set_repeatable_comments` after A03-T**. Complete prestate is A03-T poststate with FP absent. Set FP exactly `Copies the indexed 16-byte FontStyleRule when index is in range; leaves the output unchanged when out of range.` Expected poststate changes only FP; all other state remains exact.
- **A04-R apply via public `rename`, `pure:true`** at `0x00499f90`. Literal prestate: name `sub_499F90`; type `_OWORD *__thiscall(char *this, int, int, char, int)`; frame exactly `var_10/+0/0x10/int[4]`, saved `+0x10/4/_DWORD`, return `+0x14/4/_UNKNOWN *`, args `arg_0/+0x18/4/_DWORD`, `arg_4/+0x1c/4/_DWORD`, `arg_8/+0x20/1/_BYTE`, `arg_C/+0x24/4/_DWORD`; `AR absent; AP absent; FR absent; FP absent`; range `[0x00499f90,0x00499fda)`; size 74; body hash `7C90F35C90A82A8A5E379E68787F2F9CBDF5720FA1F3E77F926FC383325576DB`; inbound exactly `{0x450f22,0x451f74,0x451f8d,0x4528be,0x452b09,0x452c2b,0x47d3fa}`; sole callee `0x49ac60`. Expected poststate changes only name to `FontStyle__Configure`. Hard-stop on collision or any other literal prestate/protected-state drift.
- **A04-T apply via public `set_type` after A04-R**. Complete prestate is A04-R poststate. Submit the human-source declaration `void __thiscall FontStyle__Configure(FontStyle *this, unsigned int textColor, unsigned int secondaryColor, unsigned char effect, unsigned int alignment)`. Public IDA canonicalizes that one-byte unsigned source type, so the required persisted/readback function item type is exactly `void __thiscall(FontStyle *this, unsigned int textColor, unsigned int secondaryColor, unsigned __int8 effect, unsigned int alignment)`. The frame retains `var_10/+0/0x10/int[4]`, saved `+0x10/4/_DWORD`, and return `+0x14/4/_UNKNOWN *`, and changes only arguments to `textColor/+0x18/4/unsigned int`, `secondaryColor/+0x1c/4/unsigned int`, `effect/+0x20/0x1/unsigned __int8`, `alignment/+0x24/4/unsigned int`. Source-facing formal C++ remains `unsigned char effect`; IDA's `unsigned __int8` rendering is behaviorally and ABI-equivalent. No row may be added/deleted/moved/resized; AR/AP/FR/FP remain absent and range/hash/xrefs/callee remain exact. Hard-stop without save if public item type or frame differs from these literal canonical spellings or if any protected field drifts.
- **A04-C apply via public `set_repeatable_comments` after A04-T**. Complete prestate is A04-T poststate with exact function item type `void __thiscall(FontStyle *this, unsigned int textColor, unsigned int secondaryColor, unsigned __int8 effect, unsigned int alignment)`, exact `effect/+0x20/0x1/unsigned __int8` frame row, and FP absent. Set FP exactly `Appends one FontStyleRule containing text color, secondary color, byte effect, and dword alignment.` Expected poststate changes only FP; the canonical IDA type/frame spelling and all other state remain exact.
- **A05-C apply via public `set_repeatable_comments` only** at `0x0049ac60`. Literal prestate: name `sub_49AC60`; type `int __thiscall(int this, void *Src, _OWORD *)`; frame exactly `var_C/+0x0c/0x04/_DWORD`, `var_8/+0x10/0x04/_DWORD`, `var_4/+0x14/0x04/_DWORD`, `__saved_registers/+0x18/0x04/_DWORD`, `__return_address/+0x1c/0x04/_UNKNOWN *`, `Src/+0x20/0x04/void *`, `arg_4/+0x24/0x04/int`; `AR absent; AP absent; FR absent; FP absent`; range `[0x0049ac60,0x0049ad74)`; size 276; body hash `DB6C0E4F6F2DAA5F7EE94BBB589E1433A5BDDFD8ACBC2C80F70840F85EAFA7D2`; sole inbound `0x499fcf`; callees exactly `{0x421500,0x49ba30,0x5c7526,0x5c9b30,0x5cd607}`. Set FP exactly `Compiler-generated std::vector<FontStyleRule> growth path used only by FontStyle::Configure; source is m_rules.push_back(rule).` Expected poststate changes only FP from absent to that exact text. Name, type, all seven frame rows with exact offsets/widths/types, AR/AP/FR absence, bytes, range, size, body hash, xrefs, and callees are protected; no rename, set_type, frame action, or other comment action is permitted. Hard-stop without save if any literal prestate or protected poststate differs.

Protected no-change contract: do not create/delete/rebound functions or data; do not alter bytes; preserve A01's exact 82-byte function boundary and separate fourteen-byte successor alignment; do not rename internal instruction comments; do not create a FontStyle vtable/RTTI/global; do not rename allocator/memmove/free dependencies; do not type or rename the Configure local stack record unless a later separately audited action proves exact public endpoint behavior. Any unexpected delta requires rollback/no-save.

## First-Draft C++ Recommendation

- Eligible source items: UID00005C parent CPP/H and UID00011T authored CPP. UID0000XM, UID0001UN, and UID00011W formal channels must remain blank for the target-specific reasons below.
- These are exact formal insertion payloads, not illustrative snippets.

UID00005C formal `RECONSTRUCTION_CPP CODE`:

```cpp
#include "FontStyle.h"

[[CHILDREN]]
```

UID00011T formal `RECONSTRUCTION_CPP CODE`:

```cpp
FontStyle::FontStyle()
    : m_enabled(true),
      m_parentOpacity(0.2f),
      m_textOpacity(0.2f),
      m_foregroundColor(1),
      m_backgroundColor(0x80)
{
}

void FontStyle::GetRule(unsigned int index, FontStyleRule *outRule) const
{
    if (index < m_rules.size()) {
        *outRule = m_rules[index];
    }
}

void FontStyle::Configure(unsigned int textColor,
                          unsigned int secondaryColor,
                          unsigned char effect,
                          unsigned int alignment)
{
    FontStyleRule rule;
    rule.m_textColor = textColor;
    rule.m_secondaryColor = secondaryColor;
    rule.m_effect = effect;
    rule.m_alignment = alignment;

    m_rules.push_back(rule);
}
```

UID00005C formal `RECONSTRUCTION_H CODE`:

```cpp
#pragma once

#include <vector>

struct FontStyleRule
{
    unsigned int m_textColor;
    unsigned int m_secondaryColor;
    unsigned char m_effect;
    unsigned int m_alignment;
};

class FontStyle
{
public:
    FontStyle();

    bool IsEnabled() const { return m_enabled; }
    void SetEnabled(bool enabled) { m_enabled = enabled; }
    float GetParentOpacity() const { return m_parentOpacity; }
    float GetTextOpacity() const { return m_textOpacity; }
    unsigned int GetForegroundColor() const { return m_foregroundColor; }
    unsigned int GetBackgroundColor() const { return m_backgroundColor; }

    void GetRule(unsigned int index, FontStyleRule *outRule) const;
    void Configure(unsigned int textColor,
                   unsigned int secondaryColor,
                   unsigned char effect,
                   unsigned int alignment);

private:
    bool m_enabled;
    float m_parentOpacity;
    float m_textOpacity;
    unsigned int m_foregroundColor;
    unsigned int m_backgroundColor;
    std::vector<FontStyleRule> m_rules;
};
```

- UID0000XM CPP/H blank proof: the exact body is emitted automatically by the implicit destructor of `std::vector<FontStyleRule>`; writing any destructor body is unnecessary source and writing the allocator/free sequence would be decompiler-shaped.
- UID0001UN CPP/H blank proof: UID00005C H owns both declarations once; a comment emitter pollutes output without adding source.
- UID00011W CPP/H blank proof: `m_rules.push_back(rule)` generates the capacity-growth helper; no handwritten helper exists.
- Behavior preservation: natural alignment yields `sizeof(FontStyleRule)==0x10` and `sizeof(FontStyle)==0x20` on the target 32-bit MSVC ABI. An ordinary uninitialized local rule also preserves the observed indeterminate three padding bytes between effect and alignment.
- Source-shape preservation: the code contains no explicit ABI padding arrays, raw vector triplets, `_DWORD`, `_OWORD`, `sub_` labels, hand-coded growth/free, or empty authored destructor.

## Final Recommendation

- The accepted ordinary subset is applied: UID0000JI remains the standalone owner with the required H route through UID00005C.
- UID0000XM is renamed/reclassified as compiler-emitted implicit destruction, UID00011W remains ignored compiler growth, UID00011T remains grouped and ordered, and UID0001UN no longer emits duplicate declaration text.
- StaticTextControlPane2 and HelpPane formal CPP dependencies now place `FontStyle.h` before first complete-type use, and the dated generated readback confirms both includes.
- Perform the structured IDA handoff only during supervisor Gate 2B, with fresh attestation, literal prestate checks, backup, staged readback, save, and post-save verification.
- T01/T02 must use the tested explicit `#pragma pack(4)` input, not parser defaults. Gate 2B must require exact size/offset/frame/disassembly readback and the factual public field-xref result: the first three FontStyleRule relations remain, `_reserved` disappears, and replacement `m_alignment` remains empty even though `0x004c6674` renders `style.m_alignment`. No unproved operand-typing action is part of the handoff.
- A04-T must submit human-source `unsigned char effect` but accept only the proven public-IDA canonical poststate `unsigned __int8 effect` in both the function item type and `effect/+0x20/0x1/unsigned __int8` frame row. These spellings describe the same one-byte unsigned ABI; formal CPP/H remains human-written `unsigned char`.
- The supervisor still owns six manual-coverage claims and six IDA claims. The latter are represented by two UDT groups `T01-T02`, five function groups `A01-A05`, and fifteen ordered public endpoint stages; final verification and report lifecycle also remain supervisor-owned. No further B-agent research or ordinary-document blocker remains. Original lexical/file-list proof is unavailable but no behavior, type, header, owner, emitter, range, formal-source, parser-packing, or public field-xref question is deferred.

## Recommended Target Doc Changes

- Target: `by-file/FontStyle.md`.
- Applied result: the exhaustive inventory, exact body hashes/ranges, live UDT status, implicit-destructor and compiler-growth distinctions, complete CPP/H split, generated readback expectations, consumer includes, rejected alternatives, score rationale, and historical corrections are present at report-level detail.
- Applied metadata: assignment-time `86/89` is now `94/94`; path and `CANONICAL_OWNER:FILE` are retained.
- Useful history is preserved with the authored empty-destructor, explicit-padding, header-uncertain, and old no-UDT assumptions explicitly superseded.

## Recommended Support Doc Changes

The following accepted support actions are now applied and scoped-validated except the verify-only consumer rows, which were already present at same-or-greater detail.

| Support path | Exact action |
| --- | --- |
| `by-class/FontStyle.md` UID00005C | Replace formal CPP/H exactly; remove explicit destructor/padding; fix dangling row; add implicit special-member, UDT, caller, generated, source-order, score, and negative evidence; set 94/95. |
| `by-type/by-struct/FontStyleLayout.md` UID0001UN | Correct current IDA mismatch and natural padding; blank formal CPP/H; emitter blank; set 94/96. |
| `by-memory/0x004536e0-0x00453732.FontStyleImplicitDestructor.md` UID0000XM | Same UID remains renamed/compiler-covered with blank formals, reconstructable false, no emitter, and current 93/96 metadata; fresh Gate 2B evidence corrects its exact report handoff to an 82-byte body plus separate fourteen-byte alignment for subsequent supervisor verification. |
| `by-memory/0x00499f10-0x00499fda.FontStyleCore.md` UID00011T | Install exact formal CPP, live hashes/frames/callers/types, natural-padding/source reasoning, position 10, 94/96. |
| `by-memory/0x0049ac60-0x0049ad74.FontStyleRuleVectorGrowth.md` UID00011W | Add current hash/frame/callee/type/no-code evidence and 93/96; retain NONE/false/blank. |
| `by-memory/-ignored.md` | Add UID0000XM implicit destructor entry; preserve and enrich UID00011W and exact padding entries. |
| `by-class/StaticTextControlPane2.md` UID0000E4 | Add `#include "FontStyle.h"` before its declaration and dependency evidence; score unchanged. |
| `by-class/HelpPane.md` UID000063 | Add `#include "FontStyle.h"` before its declaration and dependency evidence; score unchanged. |
| `by-file/StaticTextControlPane.md` UID0000O8 | Add required FontStyle H/generated include route; preserve all unrelated source. |
| `by-file/HelpPanes.md` UID0000JU | Add required FontStyle H/generated include route; preserve all unrelated source. |
| `by-class/MiniMapDialog.md`, `by-class/NewMailDialog.md`, UID0004L8, UID0004LB | Verify-only: current consumer behavior remains correct; no score/formal change. |
| `by-project-structure/proposed-source-tree.md` | Applied and scoped-validated: the FontStyle.cpp/FontStyle.h listing and corrected implicit-destructor/header rationale are currently present, while stale Wave text is preserved only as history. |

## Score And Metadata Recommendation

| UID | Assignment-time | Applied/current | Metadata disposition |
| --- | --- | --- | --- |
| 0000JI | 86/89 | 94/94 | Keep path and FILE owner. |
| 00005C | 89/91 | 94/95 | Keep owner/emitter 0000JI, true; replace CPP/H. |
| 0001UN | 86/91 | 94/96 | Keep owner 00005C/true; clear emitter; blank formals. |
| 0000XM | 87/92 | 93/96 | Rename page; owner 00005C; false; blank emitter/formals. |
| 00011T | 86/91 | 94/96 | Keep owner/emitter 00005C/true; position 10. |
| 00011W | 85/90 | 93/96 | Keep NONE/false/blank emitter/formals. |

- Reason not higher: exact historical lexical spellings, exact original project file-list entry, and compiler-identical output have not been proven. Those are real sub-100 caps, not unresolved source-quality blockers.
- Reason not lower: every body, boundary, caller/callee, type offset, compiler product, source/header channel, consumer dependency, owner alternative, generated defect, and manual coverage row was checked and resolved with live MCP plus physical source evidence. The empty public `m_alignment` field-xref after packed replacement is a precisely characterized IDA-query limitation, not missing binary/source evidence: exact layout, stack-frame size, and instruction rendering independently prove the member use.
- Score improvement attempt: the previous header-placement, destructor, padding, UDT, name, vector helper, generated-source, parser-default packing, and field-xref-migration blockers were directly investigated and closed. No generic "future investigation" remains.

## Open Questions With Attempted Resolution

- Exact original physical source file: adjacency permits a StaticText fold, but separate authored cluster, current route, and cross-unit header use make standalone FontStyle the highest-probability answer. Resolved for implementation; confidence cap only.
- Exact names: no original symbols/strings exist. `FontStyle`, `FontStyleRule`, `GetRule`, and `Configure` are the project-wide coherent names and match semantics. `AddRule` was considered and rejected as not better evidenced. Resolved by best-supported inference.
- Padding declarations: direct stores prove gaps but not explicit arrays. Natural C++ alignment reproduces both gaps and looks like developer source. Resolved; explicit padding rejected.
- Destructor: current docs called it ClearRules/empty destructor. EH fanout and vector-only body prove implicit destructor lowering. Resolved; no authored destructor.
- Copy/assignment: consumers prove deep copy but no standalone authored function. Normal implicit vector special members reproduce behavior. Resolved as compiler-covered.
- Public field-xref migration: tested packed `declare_type` corrects the UDT and stack-variable rendering but does not migrate `_reserved`'s old relation to replacement `m_alignment`; the public schema exposes no dedicated field-xref writer, and mutating operand typing is not a proven safe substitute for this nested stack-variable use. Resolved by specifying the reproducible empty-xref poststate and requiring exact disassembly/frame readback instead of an invented relation.
- Configure effect type spelling: human-source C++ uses `unsigned char effect`; the public IDA endpoint canonically persists and reads that one-byte unsigned type as `unsigned __int8 effect`, including frame row `effect/+0x20/0x1/unsigned __int8`. Resolved as a tool-rendering distinction with identical width, signedness, ABI, and behavior; no source change is required.
- No open question remains that blocks score, metadata, formal CPP/H, IDA handoff, or callback implementation.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

The following manual rows remain supervisor-owned and stale after the ordinary callback. Only the supervisor may edit these collision-prone coverage reports after callback verification. Validator command `000000025334` automatically repaired UID0000XM's renamed link path in `by-memory/-coverage-report.md`; it did not apply the replacement row's identity, ignored disposition, score, or evidence, so CJI-043 remains unchecked with the full payload below.

- `by-file/-coverage-report.md` replace UID0000JI row with: `- [UID:0000JI][FontStyle](by-file/FontStyle.md) : reconstructable : 94% : very-strong : Standalone reusable UI text-style compilation unit with complete FontStyle.cpp/FontStyle.h split, exact constructor/GetRule/Configure source, natural 0x20/0x10 layouts, cross-feature MiniMap/NewMail/StaticText/Help consumers, implicit vector destructor and vector-growth compiler exclusions, complete generated dependency route, and resolved ownership/score/source-quality blockers.`
- `by-class/-coverage-report.md` replace UID00005C row with: `- [UID:00005C][FontStyle](by-class/FontStyle.md) : reconstructable : 94% : very-strong : Complete reusable FontStyle declaration in FontStyle.h with natural 0x20-byte layout, 16-byte FontStyleRule, six inline accessors, exact constructor/GetRule/Configure children, implicit vector special members, cross-feature callers, and no decompiler padding or authored compiler-support code.`
- `by-type/by-struct/-coverage-report.md` replace UID0001UN row with: `- [UID:0001UN][FontStyleLayout](by-type/by-struct/FontStyleLayout.md) : reconstructable : 94% : very-strong : Exact 0x20-byte FontStyle and 0x10-byte FontStyleRule natural layouts, bool/float/color/vector offsets, byte effect at +0x08, dword alignment at +0x0c, constructor/copy/cleanup/growth/consumer proof, and sole declaration emission through UID00005C FontStyle.h.`
- `by-memory/-coverage-report.md` replace UID0000XM row with: `    - [UID:0000XM][0x004536e0-0x00453732.FontStyleImplicitDestructor](by-memory/0x004536e0-0x00453732.FontStyleImplicitDestructor.md) 0x004536e0-0x00453732 | compiler-generated implicit destructor | FontStyle implicit vector teardown : ignored : 93% : very-strong : Exact 82-byte vector-only free/reset body with ten direct/EH xrefs across MiniMap, NewMail, StaticText2, and HelpPane, large-allocation guard, exact body hash, separate fourteen-byte alignment boundary, semantic class owner, and no authored destructor or emitted source.`
- `by-memory/-coverage-report.md` replace UID00011T row with: `    - [UID:00011T][0x00499f10-0x00499fda.FontStyleCore](by-memory/0x00499f10-0x00499fda.FontStyleCore.md) : reconstructable : 94% : very-strong : Exact ordered FontStyle constructor, void bounded GetRule, and Configure/push_back methods with complete body hashes, frames, callers, natural layout, formal CPP, class/header owner route, and compiler helper exclusions.`
- `by-memory/-coverage-report.md` replace UID00011W row with: `    - [UID:00011W][0x0049ac60-0x0049ad74.FontStyleRuleVectorGrowth](by-memory/0x0049ac60-0x0049ad74.FontStyleRuleVectorGrowth.md) : ignored : 93% : very-strong : Exact one-caller compiler std::vector<FontStyleRule> growth helper with 276-byte body hash, 1.5x capacity logic, allocator/memmove/free/invalid-parameter callees, trailing alignment, and source replacement by m_rules.push_back(rule).`
- Validator-owned `auto-generated/-ag-*` tracker rows must refresh through normal validation, not manual edits.

## Follow-Up Actions

- Supervisor: perform fresh exact-artifact Gate 1 against this marker-free same-report repair. Prior Gate 1/Gate 2A/coverage receipts remain dated evidence only and do not authorize reuse of the discarded IDA transaction.
- Supervisor after fresh Gate 1: rerun Gate 2B from a fresh clean transaction. Execute the IDA handoff as seven action groups (`T01-T02`, `A01-A05`) and fifteen ordered public endpoint stages under fresh attestation/backup/readback/save rules. For T01/T02 use explicit tested 4-byte packing, reject the known size-14 bare parse, require the literal packed layouts and consumer frame/disassembly rendering, require the factual empty replacement `m_alignment` field-xref, and do not add an unproved operand mutation. For A04-T submit source-facing `unsigned char effect` and require exact public-IDA item/frame readback as `unsigned __int8`; then independently verify every claim before any save.
- B006 ordinary callback is complete; no further B006 action is authorized unless the supervisor returns this same report with exact repair findings.
- A-agent actions: none.
- Future B research: none required for this target unless new original source/symbol evidence contradicts the selected lexical or physical split.

## Confidence

- Recommendation confidence: very high for behavior/layout/compiler disposition/header need; high for standalone file and exact source names.
- Score confidence: high. The recommended values reflect complete present evidence while preserving sub-100 lexical/file-list uncertainty.
- IDA contract confidence: very high for the corrected A04-T rendering because the public endpoint accepted source-facing `unsigned char` and independently returned `unsigned __int8` in both item type and frame. The spelling distinction does not reduce source, ABI, or behavioral confidence.
- Remaining uncertainty: only stripped original spellings and exact original project file-list form; neither affects runtime behavior or implementation readiness.

## Validator Results

- Every command below was run serially from `source-3/project-documentation` with `--mode file --file <path> --apply --queue-timeout 240`; all exited `0` with `ok:1`. No `execute_report` or report-lifecycle command was run.
- `000000025330` at `2026-08-17T09:35:44-04:00`: `by-file/FontStyle.md`; scoped pass, generated refresh deferred.
- `000000025331` at `2026-08-17T09:36:46-04:00`: `by-class/FontStyle.md`; scoped pass, generated refresh deferred.
- `000000025332` at `2026-08-17T09:37:34-04:00`: `by-type/by-struct/FontStyleLayout.md`; scoped pass, generated refresh deferred.
- `000000025333` at `2026-08-17T09:39:40-04:00`: `by-memory/0x00499f10-0x00499fda.FontStyleCore.md`; scoped pass, generated refresh deferred.
- `000000025334` at `2026-08-17T09:40:52-04:00`: renamed `by-memory/0x004536e0-0x00453732.FontStyleImplicitDestructor.md`; scoped pass plus validator-owned reference repair. It updated active links in UID0000JI, UID00005C, UID0001UN, UID00011T, UID00008C, the MiniMap aggregate, and the UID0000XM manual-coverage link path. The manual coverage row's stale identity/disposition/score/text remain supervisor work. Only pre-existing missing-reference warnings UID00039L and UID0003T6 remained.
- `000000025335` at `2026-08-17T09:41:35-04:00`: `by-memory/0x0049ac60-0x0049ad74.FontStyleRuleVectorGrowth.md`; scoped pass, generated refresh deferred.
- `000000025336` at `2026-08-17T09:42:23-04:00`: `by-memory/-ignored.md`; scoped pass, generated refresh deferred. Its 157 missing-UID warnings pre-existed this callback and are unrelated to the two accepted entries.
- Drift-repair validation `000000025469` at `2026-08-17T13:46:06-04:00`: exact command `python .\tools\validator.py --mode file --file 'by-memory/-ignored.md' --apply --queue-timeout 240`; exit `0`, `ok:1`, one scanned Markdown file, generated refresh deferred. The validator reported 155 pre-existing missing-reference UIDs, `stats_incremental_noop:1`, and a projected-stats update side effect; no target-specific error occurred. Physical reread after validation found UID0000XM exactly at lines 1324-1328 with the corrected 82-byte body and separate fourteen-byte alignment, zero stale range/body-hash/83-byte/13-alignment phrases, and all ownership/xref/compiler/source-replacement facts retained.
- `000000025337` at `2026-08-17T09:43:11-04:00`: `by-class/StaticTextControlPane2.md`; scoped pass, generated refresh deferred.
- `000000025338` at `2026-08-17T09:43:41-04:00`: `by-class/HelpPane.md`; scoped pass, generated refresh deferred; pre-existing UID0003AQ warning retained.
- `000000025339` at `2026-08-17T09:44:26-04:00`: `by-file/StaticTextControlPane.md`; scoped pass, generated refresh deferred.
- `000000025340` at `2026-08-17T09:44:56-04:00`: `by-file/HelpPanes.md`; scoped pass, generated refresh deferred; pre-existing UID0003AQ warning retained.
- `000000025341` at `2026-08-17T09:45:49-04:00`: `by-project-structure/proposed-source-tree.md`; scoped pass, generated refresh deferred; five pre-existing missing-UID warnings retained.
- Owning refresh `000000025343` at `2026-08-17T09:46:38-04:00`: `by-file/FontStyle.md` with `--wait-generated`; exit `0`, `ok:1`, generated refresh complete. Broad unrelated generator diagnostics remained outside UID0000JI; the four required physical outputs passed exact semantic readback.
- Dated generated `FontStyle.cpp`: SHA256 `A9876BFCA6CAF051006275C78B5B05FE451895849A517D9C3BCBBE95E0BEE331`, 1,219 bytes/39 lines. It contains `#include "FontStyle.h"`, then constructor, GetRule, Configure in address order, and no declaration shell, explicit destructor, layout comment, empty marker, stub, placeholder, compiler-growth body, raw ABI label, `_DWORD`, or `_OWORD`.
- Dated generated `FontStyle.h`: SHA256 `1EE059D4BFE75C0E1CA6B1A42E9E12846DB69D3ABA29581783CE07CC442B89BC`, 1,425 bytes/45 lines. It contains the complete natural-layout `FontStyleRule` and `FontStyle` declarations, six inline accessors, three out-of-line declarations, and no explicit destructor or reverse-engineering padding member.
- Dated generated `StaticTextControlPane.cpp`: SHA256 `A2FD0D2F3BB9E482F0D64EC4FF826BC7CDFF20535D7C148A2A0E3BC7BBB907FC`, 17,393 bytes/484 lines; `#include "FontStyle.h"` is line 62 immediately before the StaticTextControlPane2 declaration route and its behavior remains present.
- Dated generated `HelpPanes.cpp`: SHA256 `698F24B4C9D8E7A343AE79C209F0F5AB5E74A5FE89A0C9167C8529488EFD44F2`, 50,635 bytes/1,542 lines; `#include "FontStyle.h"` is line 8 before all FontStyle/FontStyleRule uses and Help behavior remains present.
- Fresh closeout snapshot command `000000025350` at `2026-08-17T09:52:06-04:00` changed generated metadata identities but not the accepted semantics or physical sizes/line counts: `FontStyle.cpp` SHA256 `A703AF1F2787788B10C41785BECB1EEB6138EF946710E94C46A38308F2EB5FDE`; `FontStyle.h` SHA256 `CC358C69477460EF86018796683D122CBA169F0EB62D47ED972AB9EC90545CFC`; `StaticTextControlPane.cpp` SHA256 `022F7C42C9FDFCB118CC31EB4A72B11D4C0929797A4A835734BE2BCBC08243ED`; `HelpPanes.cpp` SHA256 `91CE82B5DAAD814EDA34A00BEA5935CC8F81213874C32C72572058F4AE1F5276`. The exact include/order/declaration/no-stub checks still pass.
- Gate 2A canonical-hash repair `000000025556` at `2026-08-17T16:21:02-04:00`: exact command `python .\tools\validator.py --mode file --file 'by-memory/0x00499f10-0x00499fda.FontStyleCore.md' --apply --queue-timeout 240`; exit `0`, `ok:1`, generated refresh deferred. Physical reread proved all three exact authored-body ranges and full hashes.
- Gate 2A canonical-hash repair `000000025557` at `2026-08-17T16:21:24-04:00`: exact command `python .\tools\validator.py --mode file --file 'by-memory/0x0049ac60-0x0049ad74.FontStyleRuleVectorGrowth.md' --apply --queue-timeout 240`; exit `0`, `ok:1`, generated refresh deferred. Physical reread proved the exact 276-byte compiler-growth body and full hash.
- Gate 2A canonical-boundary repair `000000025558` at `2026-08-17T16:22:18-04:00`: exact command `python .\tools\validator.py --mode file --file 'by-memory/0x004536e0-0x00453732.FontStyleImplicitDestructor.md' --apply --queue-timeout 240`; exit `0`, `ok:1`, generated refresh deferred. Physical reread proved the exact 82-byte body, separate fourteen-byte alignment, both full hashes, and historical-only retention of the superseded 83-byte range.
- Gate 2A ignored-ledger repair `000000025559` at `2026-08-17T16:22:41-04:00`: exact command `python .\tools\validator.py --mode file --file 'by-memory/-ignored.md' --apply --queue-timeout 240`; exit `0`, `ok:1`, generated refresh deferred. Physical reread proved UID0000XM remained exact and UID00011W now carries the full canonical growth hash. The validator reported 146 pre-existing missing-reference warnings unrelated to these entries.
- Gate 2A owning validation `000000025560` at `2026-08-17T16:23:26-04:00`: exact command `python .\tools\validator.py --mode file --file 'by-file/FontStyle.md' --apply --queue-timeout 240 --wait-generated`; exit `0`, `ok:1`, generated refresh complete. Physical reread proved the aggregate table contains all five full canonical body hashes, the separate full alignment hash, and no active stale boundary/hash value.
- Dated command-25560 generated `FontStyle.cpp`: SHA256 `84A5B2693A217EDB38A6D5D976FD2E6A6831509CEE25D1AE48CECE0C5619D564`, 1,219 bytes/39 lines. It contains `#include "FontStyle.h"`, then constructor, GetRule, Configure in physical order, with accepted semantics and no declaration shell, explicit destructor, layout comment, empty marker, stub, placeholder, compiler-growth body, raw ABI label, `_DWORD`, or `_OWORD`.
- Dated command-25560 generated `FontStyle.h`: SHA256 `4B1B62C9F47AF87B92A3472DC868D39EA8932111F844106D87BB58266FE467F0`, 1,425 bytes/45 lines. It contains complete natural-layout `FontStyleRule` and `FontStyle` declarations, six inline accessors, three out-of-line declarations, and no explicit destructor or reverse-engineering padding member.
- Narrow Gate 2A wording repair `000000025680` at `2026-08-17T18:16:17-04:00`: exact command `python .\tools\validator.py --mode file --file 'by-file/FontStyle.md' --apply --queue-timeout 240`; exit `0`, `ok:1`, one Markdown file scanned, generated refresh deferred. Physical reread found the exact text `emits no source; UID00005C H is the sole declaration owner.` and zero occurrences of the superseded comment-emission wording.
- Narrow Gate 2A wording repair `000000025684` at `2026-08-17T18:16:53-04:00`: exact command `python .\tools\validator.py --mode file --file 'by-memory/0x00450ca0-0x0045381b.MiniMapDialog.md' --apply --queue-timeout 240`; exit `0`, `ok:1`, one Markdown file scanned, generated refresh deferred. Physical reread found the exact phrase `GetControlLayout and compiler-emitted FontStyleImplicitDestructor child splits` and zero occurrences of the superseded slash/ClearRules phrase.
- Validator-owned deferred refresh from command `000000025680` produced a dated physical snapshot: `FontStyle.cpp` SHA256 `AF09D55ABDB69D8788A53564F079A4C7B4BA5BF058BD213F12DB68FEC14D31B4`, 1,217 bytes/39 lines; `FontStyle.h` SHA256 `B09595F580F7E006E6C65CBD3FB92CF7640FB34CC0C18F9DB209A2D9DC0BBD8A`, 1,423 bytes/45 lines. Physical reread reconfirmed the header include, constructor/GetRule/Configure order and semantics, complete natural-layout declarations, six inline accessors, three method declarations, no explicit destructor, and no reverse-engineering padding member.
- Generated command/hash identities above are dated callback/closeout/Gate 2A repair receipts, not continuing current-state authority. Fresh supervisor Gate readback controls later generated identity.

## Changed Files

- Modified ordinary documents, dated initial callback-snapshot physical identities after scoped validation on `2026-08-17`; these receipts have no continuing current-state authority and are retained as implementation history:
  - `by-file/FontStyle.md`: SHA256 `1B8DA6B3B4C72B0852AE0AEABF513C3C0B7D6493EBE71078A765432A2DEFFF4E`, 14,103 bytes/119 lines.
  - `by-class/FontStyle.md`: SHA256 `C13281BFCAD48A130EC901AB3E818D8F940EAFC70BD03A3F7419558102DDF662`, 15,190 bytes/183 lines.
  - `by-type/by-struct/FontStyleLayout.md`: SHA256 `6CD0AC725E59C532BD4487DAF93A0433A83267016E72E8DAF00B47B0E4F8A912`, 14,645 bytes/121 lines.
  - `by-memory/0x00499f10-0x00499fda.FontStyleCore.md`: SHA256 `47D06FA10CE077AD3F9A2962F468A7FBF3D48F04044E3EBF3E88AF616A777D7A`, 14,589 bytes/171 lines.
  - `by-memory/0x0049ac60-0x0049ad74.FontStyleRuleVectorGrowth.md`: SHA256 `357444F688F9F1958A1CDC42C981DC16245754D5F1755DF48C399F486DD048FB`, 7,308 bytes/85 lines.
  - `by-memory/-ignored.md`: dated original callback receipt SHA256 `308623A1F6575AD139D06F3AD616B6027BA30813EB27E0B3E9E7C5B56FA967C0`, 1,144,347 bytes/5,484 lines; dated first drift-repair receipt SHA256 `0E1939FC96BA4344AB6D8C4BA2B320EFA11306CCD74FF46F28AF6F623C7A9A8C`, 1,144,765 bytes/5,484 lines. Both are historical receipts superseded by the Gate 2A repair identity below.
  - `by-class/StaticTextControlPane2.md`: SHA256 `B9276EE8595FCA0F071949C3C2E99B572C2BE0BE6122BB61585ADE44D64B0B92`, 13,930 bytes/175 lines.
  - `by-class/HelpPane.md`: SHA256 `35E895CF5B8D68D704D6084275C1755E84505EF2B8B89FA7608D09F756BD932E`, 24,506 bytes/202 lines.
  - `by-file/StaticTextControlPane.md`: dated callback receipt SHA256 `A95EF52DEBD7C780DFD2309F30663456256F8997A33E93E7F5A3FACB6A1D96FB`, 22,684 bytes/129 lines. Fresh read-only physical identity is SHA256 `D15BF79858CD2BA9B45504C8697A29D5032F8CBBBBE94066D7BD6B4516CE75E8`, 23,448 bytes/134 lines, last write `2026-08-17T11:43:17.1364958-04:00`. The later additive revision retains all B006 FontStyle dependency material and history: UID0000JI/UID00005C remain separate owners, UID0000E4 still supplies the required `FontStyle.h` include route and generated-readback expectation, unrelated StaticText ownership/metadata/source remain preserved, and the dated `2026-08-17` B006 accepted UID0000JI dependency callback history remains present.
  - `by-file/HelpPanes.md`: SHA256 `AD396F02F5F8BCDF37C6B20B80C4DE99C6594AB55153CCFF9F065FE1CBB36ED9`, 85,986 bytes/362 lines.
  - `by-project-structure/proposed-source-tree.md`: SHA256 `1F94E2072C061219CB4A08363F7A0708390CA6748FC85FA031CCC54B4C606279`, 328,250 bytes/2,161 lines.
- Renamed ordinary document: `by-memory/0x004536e0-0x00453732.FontStyleClearRules.md` -> `by-memory/0x004536e0-0x00453732.FontStyleImplicitDestructor.md`; dated pre-Gate-2A repair identity SHA256 `1928557D0F40275DD451CDD6923FFCB36EB9EFC4ABCFA0185F315E1057BC5732`, 10,219 bytes/120 lines. UID0000XM is unchanged.
- Gate 2A repair physical identities after commands `000000025556`-`000000025560`; these are dated receipts, and fresh supervisor readback remains final current-state authority:
  - `by-file/FontStyle.md`: SHA256 `98F659780C8FFA136F31F6A4335C9A0C4D5DDAC19B0ADC977BF40B77D2E684F3`, 14,581 bytes/120 lines.
  - `by-memory/0x00499f10-0x00499fda.FontStyleCore.md`: SHA256 `945C409F2509E42A0B627DACD84348CCB9AA2F9339B21E1A56FC2EDCBEB39D9F`, 14,636 bytes/171 lines.
  - `by-memory/0x0049ac60-0x0049ad74.FontStyleRuleVectorGrowth.md`: SHA256 `2556226671D567E0D9EB80D822F7764175C8221493CF27624F1A2FB0F59E740C`, 7,329 bytes/85 lines.
  - `by-memory/0x004536e0-0x00453732.FontStyleImplicitDestructor.md`: SHA256 `5A765ADD72D66C484B911AA1A65770D254CA52D4F504299DFDED00019BDCA36D`, 11,156 bytes/123 lines.
  - `by-memory/-ignored.md`: SHA256 `313B0005532A2613DD3E0BBB997B44B254C33620C3533787AF243DD71F43E748`, 1,144,783 bytes/5,484 lines. UID0000XM retains exact compiler-destruction/source-replacement facts and UID00011W now retains the exact full growth-body hash; unrelated entries are preserved.
- Narrow Gate 2A wording-repair physical identities after commands `000000025680` and `000000025684`; these are dated receipts and fresh supervisor readback remains final current-state authority:
  - `by-file/FontStyle.md`: SHA256 `367EE8B025A1055BB5660A70EC4A3DE601D105C6A6C0EEAE7A6BBF43B32ACEDF`, 14,587 bytes/120 lines. The only semantic delta from its command-25560 identity is the exact UID0001UN no-source/sole-H-owner wording.
  - `by-memory/0x00450ca0-0x0045381b.MiniMapDialog.md`: SHA256 `33FE14D0BC31C8478BE4D01AAC87B771053FE5F92C402738D30BB8D54A97A432`, 27,867 bytes/210 lines. The summary now names GetControlLayout and the compiler-emitted FontStyleImplicitDestructor child split; all other aggregate facts remain preserved.
- Verify-only consumer pages [UID:00008C] MiniMapDialog, [UID:000096] NewMailDialog, [UID:0004L8], and [UID:0004LB] already contained the accepted consumer-only facts at same-or-greater detail; no B006 semantic edit was needed.
- Automatic validator link-repair side effects from command 25334: `by-class/MiniMapDialog.md` now SHA256 `329F2CA080D36FD3C74D79F6685BC2688E7C338FE14A1EB00597E29FE3D2DF49`, 16,792 bytes/125 lines; `by-memory/0x00450ca0-0x0045381b.MiniMapDialog.md` now SHA256 `67AD3BB5C57213A4F640C4B722E99027D388A59F725C600638FE225E86045D47`, 27,838 bytes/210 lines. The validator also changed only UID0000XM's link path in `by-memory/-coverage-report.md`; that collision-prone file was not manually edited, and its stale row content remains unchecked supervisor work.
- Generated files were validator-owned outputs and were never edited directly. Tracker, audit, registry, catalog, goal, notes, IDA, and lifecycle files were not edited by B006.
- Same-report Gate 2B contract repair: only this report changed. The dated failed transaction's T01, T02, A01-A03, A04-R, and A04-T state was discarded without `idb_save`; canonical IDB SHA256 `C453AEF982EAAFA8063F7B554FC37F526E30D0FC79589C1CF7C0B75243DAAC26`, size 143,209,618 bytes, and last-write UTC `2026-08-17T22:56:16.6600025Z` remained unchanged. No ordinary, coverage, generated, tracker, audit, validator, lifecycle, or IDA file was changed by B006 during this repair.
- Report lifecycle boundary: execution/archive status remains supervisor-owned and authoritative only from the current report path plus validator-owned status/history metadata.

## Implementation Tracking Checklist

Exact ledger twin. Post-callback allocation is 42 checked / 12 unchecked. Fields after Done are identical to the Claim And Incorporation Ledger in the same order. Unchecked rows are exactly CJI-040..045 manual coverage and CJI-047..052 supervisor Gate 2B IDA work.

| Done | Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| [x] | CJI-001 | 0000JI | FontStyle is a reusable UI text-style compilation unit, not a feature-owned helper. | Very high | Four consumer families and three-method authored cluster. | UID0000JI File Role | incorporate | applied |
| [x] | CJI-002 | 0000JI | Keep `NexusTK/ui/controls/FontStyle.cpp` as owner path. | High | Current route, link neighborhood, cross-feature fanout. | UID0000JI Source Placement | incorporate | applied |
| [x] | CJI-003 | 0000JI | Add required sibling `FontStyle.h`. | Very high | By-value cross-unit consumers and absent generated H. | UID0000JI Header/Generated State | incorporate | applied |
| [x] | CJI-004 | 0000JI | Whole-file inventory is five modeled bodies, three authored and two compiler-generated. | Very high | Live function/xref/decompile inventory. | UID0000JI Proposed Contents | incorporate | applied |
| [x] | CJI-005 | 0000XM | The exact 82-byte body at `0x004536e0` is implicit destructor lowering, not authored ClearRules or empty-destructor source. | Very high | Commands 25558/25560 prove exact body/alignment hashes; command 25684 proves the MiniMap aggregate now names the compiler-emitted FontStyleImplicitDestructor split. | UID0000XM identity/no-code | reject-stale | applied |
| [x] | CJI-006 | 00011W | `0x0049ac60` is compiler vector growth represented by push_back. | Very high | Commands 25557/25559 prove exact 276-byte body `DB6C0E4F6F2DAA5F7EE94BBB589E1433A5BDDFD8ACBC2C80F70840F85EAFA7D2` and compiler-only disposition. | UID00011W no-code | incorporate | applied |
| [x] | CJI-007 | 00005C | Six field accessors remain header-inline and require no out-of-line symbols. | High | Direct consumer field reads/writes and no entries. | UID00005C Inline Accessors | incorporate | applied |
| [x] | CJI-008 | 00005C | Copy construction, assignment, and destruction remain implicit compiler-covered special members. | High | Consumer deep copies/EH and no authored entries. | UID00005C Special Members | incorporate | applied |
| [x] | CJI-009 | 0000JI | File owns no globals, statics, strings, tables, vtables, RTTI, resources, or imports. | Very high | Bounded entity/type/xref searches. | UID0000JI Negative Inventory | incorporate | applied |
| [x] | CJI-010 | 00011T | Constructor initializes empty vector, enabled true, two 0.2f values, 1 and 0x80. | Very high | Command 25556 proves exact 65-byte body `E2C92A3449ED6693F5F2F7933CA215DAE05FDE09FE4C635EE2A9C2FC449525A7`. | UID00011T Constructor | incorporate | applied |
| [x] | CJI-011 | 00011T | GetRule is void bounded 16-byte copy and leaves output unchanged out of range. | Very high | Command 25556 proves exact 37-byte body `A7C6EA02E0464241B69BADAC2417EE6DE85349D158FD8F045A5DC0D15B4D73EB` and two ignored-EAX callers. | UID00011T GetRule | reject-stale | applied |
| [x] | CJI-012 | 00011T | Configure appends one 16-byte rule with byte effect and dword alignment. | Very high | Command 25556 proves exact 74-byte body `7C90F35C90A82A8A5E379E68787F2F9CBDF5720FA1F3E77F926FC383325576DB`, stores, and growth call. | UID00011T Configure | incorporate | applied |
| [x] | CJI-013 | 0001UN | FontStyle is 0x20 with bool, natural padding, two floats, two uints, and vector. | Very high | Constructor/cleanup offsets and type layout. | UID0001UN Object Layout | incorporate | applied |
| [x] | CJI-014 | 0001UN | FontStyleRule is 0x10 with natural padding and alignment at +0x0c. | Very high | Configure stores and consumers. | UID0001UN Rule Layout | reject-stale | applied |
| [x] | CJI-015 | 0001UN | Current IDA FontStyleRule +0x09 byte alignment member is stale and must be corrected. | Very high | Fresh type_inspect versus binary writes. | UID0001UN IDA Status | reject-stale | applied |
| [x] | CJI-016 | 00005C | Formal CPP becomes include plus `[[CHILDREN]]`. | Very high | Required sibling header and child route. | UID00005C formal CPP | incorporate | applied |
| [x] | CJI-017 | 00005C | Formal H becomes complete human-written declarations without explicit padding/destructor. | Very high | Exact layout and implicit compiler behavior. | UID00005C formal H | incorporate | applied |
| [x] | CJI-018 | 00011T | Formal CPP retains exact constructor/GetRule/Configure bodies in address order. | Very high | Binary behavior and current valid draft. | UID00011T formal CPP | incorporate | applied |
| [x] | CJI-019 | 0000XM | Both formal channels stay blank and emitter is removed. | Very high | Compiler-covered implicit destructor proof. | UID0000XM formal CPP/H | reject-stale | applied |
| [x] | CJI-020 | 0001UN | Both layout formal channels stay blank; remove generated comment pollution. | Very high | Command 25680 proves UID0001UN emits no source and UID00005C H is the sole declaration owner. | UID0001UN formal CPP/H | reject-stale | applied |
| [x] | CJI-021 | 00011W | Both growth-helper formal channels remain blank. | Very high | Compiler/template helper proof. | UID00011W formal CPP/H | incorporate | applied |
| [x] | CJI-022 | 00011T | Set emitter position 10; constructor, GetRule, Configure remain ordered inside one child. | Very high | Physical addresses and one-owner route. | UID00011T metadata/source order | incorporate | applied |
| [x] | CJI-023 | 0000JI | Dated command 25247 proved the assignment-time generated CPP/H defects; dated command 25343 proves clean FontStyle CPP/H callback output. | Very high | Commands 25247/25343 physical readbacks and exact hashes. | UID0000JI Generated Audit | incorporate | applied |
| [x] | CJI-024 | 0000JI | Dated assignment-time consumers lacked FontStyle.h; dated command 25343 proves both generated consumers now include it before first use. | Very high | Commands 25247/25343 physical generated searches. | UID0000JI Consumer Dependencies | incorporate | applied |
| [x] | CJI-025 | 0000E4 | Add `#include "FontStyle.h"` before StaticTextControlPane2 declaration. | Very high | First complete-type use in generated file. | UID0000E4 formal CPP | incorporate | applied |
| [x] | CJI-026 | 000063 | Add `#include "FontStyle.h"` before HelpPane declaration. | Very high | First complete-type use in generated file. | UID000063 formal CPP | incorporate | applied |
| [x] | CJI-027 | 0000O8 | Document FontStyle.h dependency and generated include requirement. | High | StaticText by-value/member/rule use. | UID0000O8 Dependency Evidence | incorporate | applied |
| [x] | CJI-028 | 0000JU | Document FontStyle.h dependency and generated include requirement. | High | HelpPane by-value/member/rule use. | UID0000JU Dependency Evidence | incorporate | applied |
| [x] | CJI-029 | 0001R1 | The proposed source tree now lists FontStyle.cpp and FontStyle.h with the corrected implicit-destructor disposition. | High | Applied tree text and scoped validator command 25341. | Proposed Source Tree FontStyle paragraph | incorporate | applied |
| [x] | CJI-030 | 00008C | MiniMap remains a consumer using local style values, not owner. | Very high | Constructor/Configure/cleanup call sites. | UID00008C verify/history | incorporate | already-present |
| [x] | CJI-031 | 000096 | NewMail remains a consumer using local style values, not owner. | Very high | Calls 0x47d0d2/0x47d3fa. | UID000096 verify/history | incorporate | already-present |
| [x] | CJI-032 | 0000JI | Reject MiniMap, MailDialogs, HelpPanes, StaticText-only, and headerless ownership. | Very high | Cross-feature fanout and complete-type requirement. | UID0000JI Rejected Alternatives | incorporate | applied |
| [x] | CJI-033 | 0000JI | Preserve exact authored ranges and compiler padding/boundary exclusions, including UID0000XM's 82-byte body and separate fourteen-byte alignment. | Very high | Commands 25556-25560 verify all five full canonical body hashes, the separate full alignment hash, and zero active stale boundary/hash values. | UID0000JI Boundary Inventory | incorporate | applied |
| [x] | CJI-034 | 0000JI | Target metadata is now 94/94 with the path and FILE owner retained; assignment-time metadata was 86/89. | High | All blockers resolved, lexical split still inferred. | UID0000JI metadata | incorporate | applied |
| [x] | CJI-035 | 00005C | Raise class 89/91 to 94/95; retain owner/emitter 0000JI and reconstructable true. | High | Complete CPP/H and behavior. | UID00005C metadata | incorporate | applied |
| [x] | CJI-036 | 0001UN | Raise layout 86/91 to 94/96; retain owner 00005C, set emitter blank. | Very high | Exact offsets/natural padding/current UDT issue. | UID0001UN metadata | incorporate | applied |
| [x] | CJI-037 | 0000XM | Raise 87/92 to 93/96, rename page, set reconstructable false and emitter blank. | Very high | Exact compiler-covered disposition. | UID0000XM metadata/path | incorporate | applied |
| [x] | CJI-038 | 00011T | Raise core 86/91 to 94/96; retain owner/emitter 00005C and set position 10. | Very high | Exact three bodies and callers. | UID00011T metadata | incorporate | applied |
| [x] | CJI-039 | 00011W | Raise growth 85/90 to 93/96; retain owner NONE/non-reconstructable/no emitter. | Very high | Exact helper/caller/callees/hash. | UID00011W metadata | incorporate | applied |
| [ ] | CJI-040 | 0000JI | Replace stale by-file manual coverage row with exact 94% row. | Very high | Current row says 84%. | by-file/-coverage-report.md | incorporate | proposed |
| [ ] | CJI-041 | 00005C | Replace stale class manual coverage row with exact 94% row. | Very high | Current row says 84%. | by-class/-coverage-report.md | incorporate | proposed |
| [ ] | CJI-042 | 0001UN | Replace struct manual coverage row with exact 94% natural-layout row. | Very high | Current row says 86%. | by-type/by-struct/-coverage-report.md | incorporate | proposed |
| [ ] | CJI-043 | 0000XM | Replace memory coverage row with the renamed ignored/compiler row at 93% and its corrected 82-byte body boundary. | Very high | Current row retains stale identity, score, and pre-correction boundary evidence. | by-memory/-coverage-report.md | reject-stale | proposed |
| [ ] | CJI-044 | 00011T | Replace core memory coverage row with exact 94% row. | Very high | Current row says 84%. | by-memory/-coverage-report.md | incorporate | proposed |
| [ ] | CJI-045 | 00011W | Replace growth memory coverage row with exact ignored 93% row. | Very high | Current row says 80%. | by-memory/-coverage-report.md | incorporate | proposed |
| [x] | CJI-046 | 0000XM | Preserve the implicit-destructor ignored entry and correct drift to the exact 82-byte body plus separate fourteen-byte alignment without changing UID00011W or unrelated entries. | Very high | Command 25469 and physical reread prove the exact body/alignment hashes and retained compiler-only/source-replacement facts. | by-memory/-ignored.md lines 1324-1328 | incorporate | applied |
| [ ] | CJI-047 | 0001UN | Apply deterministic 4-byte-packed FontStyleRule/FontStyle UDT declarations; require exact natural-layout offsets, unchanged consumer frame, exact `style.m_alignment` disassembly rendering, retained first-three rule-field xrefs, and the factual empty replacement `m_alignment` public field-xref. | Very high | Tested bare-versus-`#pragma pack(4)` public declare_type behavior, type_inspect, stack_frame, disassembly, and xrefs_to_field. | Supervisor Gate 2B T01/T02 type handoff | incorporate | proposed |
| [ ] | CJI-048 | 0000XM | Rename/type/comment implicit destructor without changing its exact 82-byte body, separate alignment, frame, or xrefs. | Very high | Corrected body/alignment hashes and EH/direct xrefs. | Supervisor Gate 2B A01 | incorporate | proposed |
| [ ] | CJI-049 | 00011T | Rename/type/comment constructor while preserving body `E2C92A3449ED6693F5F2F7933CA215DAE05FDE09FE4C635EE2A9C2FC449525A7`, frame, and xrefs. | Very high | Exact 65-byte initialization and seven callers; repeated canonical readback. | Supervisor Gate 2B A02 | incorporate | proposed |
| [ ] | CJI-050 | 00011T | Rename/type/comment GetRule with exact void signature and frame delta while preserving body `A7C6EA02E0464241B69BADAC2417EE6DE85349D158FD8F045A5DC0D15B4D73EB`. | Very high | Exact 37-byte copy body and two ignored-EAX callers; dated A03 transaction-local readback passed but was discarded unsaved after the later A04-T hard stop. | Supervisor Gate 2B A03 | incorporate | proposed |
| [ ] | CJI-051 | 00011T | Rename/type/comment Configure with human-source `unsigned char effect`, exact public-IDA `unsigned __int8 effect` item/frame readback, and preserved body `7C90F35C90A82A8A5E379E68787F2F9CBDF5720FA1F3E77F926FC383325576DB`. | Very high | Exact 74-byte append body, seven ignored-return callers, and dated A04-T canonical type/frame readback from the discarded unsaved transaction. | Supervisor Gate 2B A04 | incorporate | proposed |
| [ ] | CJI-052 | 00011W | Add repeatable compiler-support comment only; protect function identity/type/frame and body `DB6C0E4F6F2DAA5F7EE94BBB589E1433A5BDDFD8ACBC2C80F70840F85EAFA7D2`. | Very high | Exact 276-byte single-caller compiler helper; repeated canonical readback. | Supervisor Gate 2B A05/protections | incorporate | proposed |
| [x] | CJI-053 | 0000JI | Scoped-validate every changed ordinary page, refresh owner once, and physically verify all three generated CPP plus FontStyle H. | Very high | Commands 25330-25343, 25350, 25469, 25556-25560, 25680, and 25684 with physical FontStyle CPP/H readback. | Validator Results | incorporate | applied |
| [x] | CJI-054 | 0000JI | Report execution/archive and all manual coverage/IDA mutation remain supervisor-owned. | Very high | B-agent lifecycle boundary. | Changed Files/Follow-Up | incorporate | applied |

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B006","command_id":"000000025807","destination_path":"executed-b-agent-research/B006/0000JI-FontStyle-file-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B006/research/0000JI-FontStyle-file-source-quality.md","timestamp":"2026-08-17T19:55:40-04:00","uid":"0000JI"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
