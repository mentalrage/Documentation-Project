** TARGET-REPORT-UID:0002K6 **
** AUTHOR-AGENT-ID:B007 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID0002K6 RankingCategoryRecordGetUserEntryAt Source-Quality Research


## Finalized Report / Current Recommendation

- Current recommendation: accept UID0002K6 as the source-authored, non-const `RankingCategoryRecord::GetUserEntryAt(int)` method, correct its half-open range to `[0x0045bfe0,0x0045c01b)`, and replace the stale physical-vector-field draft with source-facing `std::vector<RankingUserEntry>` code.
- Final disposition: reconstructable and source-emitting through [UID:0000BL] `RankingCategoryRecord`, with [UID:0000MZ] `RankingDialog` as the file owner.
- B007 callback result: C01-C05, C07-C13, C22, C25, and C27-C31 are applied; C06 was already present; C26 is verified as an excluded protected boundary. The target remains `by-memory/0x0045bfe0-0x0045c01b.RankingCategoryRecordGetUserEntryAt.md`, carries the exact CPP body and `94/95` metadata, and the target, aggregate, layout, class, and file pages now contain the corrected physical postpad item model at report-level detail.
- Supervisor-role boundary: C14-C21 and C23 are stable supervisor-owned recommendations; their checklist boxes remain clear solely because B007 did not claim those external actions. C24 is checked only as proof that the stable supervisor lifecycle policy is present, not as execution, movement, archive, Gate 1, or Gate 2 credit. Current gate and lifecycle truth is external to this report body. C27-C31 preserve the earlier item-absence assumption only as dated corrected history and do not reopen any valid method/source conclusion.
- Dated Gate2B history: the `2026-08-04T14:21:00-04:00` supervisor transaction reached ID01-ID03 but failed the obsolete ID04 requirement that Hex-Rays continue displaying `v2`; no local rename/type action had occurred. The worker was discarded without save and fresh-session rollback restored canonical prestate. The corrected ID03/ID04 recommendation accepts automatic `RankingUserEntry *m_userEntriesBegin` rendering while still forbidding explicit local mutation. Whether any external Gate2B transaction later applies that recommendation is authoritative only from supervisor audit/IDA persistence records, not from the unchecked B007 actor boxes.
- Shared-state reconciliation: B005's separately accepted UID0002KA callback subsequently added `ResetUserEntries()` clear-without-free semantics, the `m_localPlayerRank = -1` contract, caller/consumer evidence, and sibling CPP/H routing to the shared aggregate/layout/class/pane/file pages. Those additions are compatible with and disjoint from UID0002K6: they do not change this target's range, signed lookup behavior, physical postpad item, owner/emitter, formal source, score, or any C01-C31 actor/state boundary.
- Recommended target metadata: `COMPLETION:94`, `CONFIDENCE:95`, `CANONICAL_OWNER:0000BL`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000BL`.
- Confidence: very strong. The 59-byte body, exact signed comparison, one live caller, vector layout, row layout, return contract, source owner, and source placement are closed. Only the original lexical spellings remain inferred rather than symbol-proven.

## Supporting Research

- Dated read-only evidence snapshot session `9081c1f3-bc94-49a3-a909-a60eafeb0a99` used MCP database `b005-persist-reopen`, worker/PID `2652`, and `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`. The primary supervisor later legitimately closed that worker during another report's persistence test. Sessions `058dd8a9-4648-49de-b5d4-cf1e8fc521d9` and `a6c5315b-4d5d-48b0-ab1f-f41348c13880` are also dated corroborating reads; no recorded session/PID is permanent, sole, or active-current authority.
- In the dated session9081c1f3 snapshot, `server_health` returned `status:ok`, module `NexusTK.exe`, image base `0x400000`, `hexrays_ready:true`, `strings_cache_ready:true`, and no active IDB analysis. `auto_analysis_ready:false` was contextual because the target, caller, decompiler, bytes, xrefs, and types were all available and stable. Session rotation does not reopen any technical conclusion, but every Gate2B/current-state/post-move check must dynamically rerun `idb_list` and `server_health` against the then-selected database.
- Current repair-time saved IDB authority is `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, SHA256 `CE0222E87E1A569A73EB43DD72BF53412B103DD9281A535EEC2BCC01DE0932FA`, `143196420` bytes, last written `2026-08-04T14:52:17-04:00`, after B002's unrelated accepted UID0004HS save/persistence transaction. SHA256 `85582A483733EC1F54725DBC305E16219A4C6E86B0D948563AF87E59C035AF5D`, SHA256 `74720635DA2BED8F69DFFDBE8E7ED345C6F6ECB44F38FF03A8E8FACC9539FC46`, and SHA256 `92CD98A20133155CEC96C4AB6B60A00B7C5635A7C47E0A3F51BE918C13ACC5A0` are retained only as dated earlier disk snapshots. Repair-time healthy session `b002-uid0004hs-persist-reopen`, worker PID `20412`, is bounded read-only evidence only, not permanent current authority. The primary supervisor must freshly reread path, size, last-write time, SHA256, `idb_list`, and `server_health` at every Gate2B/current-state/persistence/post-move check and select the then-healthy session.
- Fresh Gate2B prestate audit `2026-08-04T12:30:00-04:00` used then-healthy session `b005-uid0002yf-final-persist-verify`, worker PID `25564`, against that canonical disk identity. This is a dated bounded snapshot, not permanent session authority. The transaction stopped before dry-run rename, type declaration, mutation, backup, or save.
- Dated primary-supervisor Gate2B transaction `2026-08-04T14:21:00-04:00` used session `b005-uid0002ka-persist-verify`, worker PID `15224`, after fresh path/hash/size, health, collision, type, function, frame, comment, xref, byte, and item prestates all matched. Backup `E:\NTK\Resources\NexusTK\NexusTK.exe.i64.bak-UID0002K6-prestate-20260804-141734` matched canonical SHA256 `85582A483733EC1F54725DBC305E16219A4C6E86B0D948563AF87E59C035AF5D` and size `143196420`. Both rename dry-runs passed; ID01 and ID02 applied/read back exactly; ID03 renamed and typed the target and read back its expected body and `index` frame argument. Before the target comment, caller mutation, save, or manual/generated work, the old ID04 postcondition failed only because Hex-Rays deterministically rendered the untouched register-`esi` local as `m_userEntriesBegin` after the exact UDT/field/function typing. No local rename request and no local type request was issued.
- The supervisor stopped immediately, tore down PID `15224` without saving, and opened fresh dated rollback-verification session `b007-uid0002k6-nosave-rollback-verify`. That fresh session proved complete canonical-disk restoration: `RankingUserEntry` and `RankingUserListPane` absent; all three `RankingCategoryRecord` vector fields restored to `void *`; target/caller raw names, types, comments, `arg_0` frame, and decompiler local `int v2` restored; target/body/postpad bytes and xrefs unchanged. Gate2B therefore failed at the obsolete ID04 render-name assertion with **no save and verified rollback**; it did not disprove ID01-ID03 or authorize an explicit local mutation.
- The fresh contradicting prestate is exact: `inspect_items` at each address `0x0045c01b` through `0x0045c01f` returned the same existing physical item with head `0x0045c01b`, end `0x0045c020`, size `5`, unnamed, untyped, `is_code:false`, and `is_data:true`. The item's bytes are `cc cc cc cc cc`, all comment channels are blank, and xrefs are zero. Earlier report language asserting item absence is superseded; the source conclusion remains five-byte non-emitting alignment.
- Fresh repair-time read-only MCP checks against `b002-uid0004hs-persist-reopen`/PID20412 reproduced every ID01-ID06 prestate: proposed names/types remain absent; target `sub_45BFE0` and caller `sub_45F3A0` retain their exact extents, raw prototypes, frames, comments, bytes, xrefs, and decompilation; the 15-member/688-byte `RankingCategoryRecord` still has `void *` at `+0x258/+0x25c/+0x260`; and the postpad remains the same unnamed/untyped/non-code five-byte data item. B002's UID0004HS save did not affect this transaction package. This session identity is a dated bounded snapshot and must be selected dynamically again at Gate2B.
- Active-current generated evidence is coherent foreground refresh command `000000021052`, refreshed `2026-08-04T14:56:27-04:00`: `RankingDialog.cpp` SHA256 `B0AB8360A81812E473929A926E5AD23C168D9C82595D85A01EF00D4414C48AAE`, `54655` bytes; `RankingDialog.h` SHA256 `A9794ADF8ACEC6925B845908E850C5E24B05786FC5454DC7CB7B70EF70581D17`, `2505` bytes; memory coverage SHA256 `38C758BB3F60ECBFF263227F7DC994C9FC226C0D408B53717A90F2463F3BB41E`; class coverage SHA256 `27D6EDA98B0D5BD75F27698227AD2D21724274F77225EE2C260086074E05491A`; file coverage SHA256 `5F51D6EF87789A3051D60A59F7E25BF1A1B0F968D2DCFC534A5766C9AD90ED64`; type coverage SHA256 `2A130CD094998B4F9100F6B18B89D928BC6079FAD17BA3BB96483DC29AA2E099`; and global coverage SHA256 `C54854B52D0B772DB4556D378F6AD31E8E2793BE85621237D14A63E8362835F6`.
- Command20995 is retained only as dated predecessor-generation evidence: tracker `46EF19C5FE0B890B0685AABB69E1D88A8190A2214C0A4473A8624258E074B9CF`; memory `05F2F872C17A3CD3B2BA5191446C5321A98A33EEEFB70C450B8F4C9DFEC9971B`; class `4A3CFD8F2AA2E7DBA65F2EBDE381F761F586AC4E4D2F3E6B40C363C24453858F`; file `5F84535E3035FF27A6341F0618ED83E96ED722EB324E21B6855785C3BBF19BEE`; type `3D232B4935769F7D39BB9C2BA7134CEAA74233571E0F4BFA7E941E20F8AD3153`; global `6898040E07C5DA5521D76F018EDB8DA1BA5BA9B5239D79A8A88F36CF2FCC46D9`; `RankingDialog.cpp` `E6636DF16B0A715E828DB455FF3D246E1E40B9ECB3B97289113A3B950A788603`; and `RankingDialog.h` `B1C63C256AF8037DE03747C9B12CC4465C09A9C641771839EB7B6F58F27024D0`.
- Historical lifecycle command20996 execution and command20997 de-execution advanced only the lifecycle-sensitive tracker. Command20997 is retained as a dated snapshot at SHA256 `2B2190785A6A4A605B8D1C17986FA0315275C2067F5FE95CB399409A6A882ED2`; it showed UID0002K6 at the corrected path, `94/95`, and zero report coverage.
- Command21007/21008 tracker snapshots and mixed command21031/21027/21021/21020/21007 source/aggregate hashes are dated predecessors. Command21036 tracker SHA256 `CE703CBE51083E3051C288318334B929FCD31FF80933150099B5FBE6027DF135`, command21048 tracker SHA256 `42EFF3C38E67C15C1AFF400F8D8AE2BAD5A4169258564A4163D6450524EE1B3D`, and command21052 tracker SHA256 `9D921C8C650C3B27E692BFA8BB371A4F95C2F00BC7EAF309877F28B8F843392C` are retained as dated prior tracker snapshots. The repair-time physical tracker snapshot is command21055, refreshed `2026-08-04T15:38:56-04:00`, SHA256 `BBFB31CCB98E6EE4BD37E6D6194EBFBCC1A8AC135D4A11EA07278529A0242E86`: UID0002K6 is `94/95`, reconstructable true, with direct/additional/total report counts `0/0/0`; executed sibling UID0002KA is `94/95`, reconstructable true, with counts `1/0/1`, direct agent `B005`, execution timestamp `2026-08-04T14:23:55`, and archive `executed-b-agent-research/B005/0002KA-RankingCategoryRecordResetUserEntries-source-quality.md`. Every tracker identity, including command21055, is only a dated gate snapshot and must be reread dynamically at every gate/post-move audit.
- Command21052 memory coverage marks both UID0002K6 and UID0002KA `coded` through UID0000BL/`RankingDialog.cpp`, and its CPP/H contain each accepted body/declaration exactly once. UID0002K6 still emits the accepted non-const vector lookup; UID0002KA separately emits `void ResetUserEntries()`, `m_userEntries.clear()`, and `m_localPlayerRank = -1`. Owner/emitter/file routes are coherent and no empty or duplicate target marker is present. Command21036 and command21048 remain dated predecessor authority only.
- Commands `000000020957`, `000000020962`, `000000020968`, `000000020969` through `000000020976`, `000000021007`, `000000021008`, and the mixed command21031-era files are explicitly dated predecessor/callback/gate authorities. Their prior RankingDialog/source/aggregate/tracker hashes are historical, not active-current identities. C23 records the stable supervisor policy for a coherent generated refresh after the external prerequisites defined by current project standards; whether that policy has been applied is external to this report body.
- Exact dated generated-authority history is retained rather than discarded. Command21031-era identities were CPP `A3168D49E21457AFF44B7111EDA20BE86E7F96D61C3774D6278276348DCB4914`, H `A4719B31C0B52F7DC7C5C631178A1F345821CC739545B913A7B17A52F919F9E4`, memory `6D93FC6A4B3F27F19E0ED6D3469B183F5DDA96A3E9C0C59806FB33F0330A360F`, command21027 class `9B30B80DAD1D5ECCD8327FDCB0BA066B77F5D2D2B1A9E85DED5902DA69828173`, command21021 file `C021014C4A244C231BC5F78190100F4BE251AB3B9251191D0D110BA6ED123CBF`, command21020 type `0B4B382EB7DF4A1D67D210699D052D86B1080C1A7549CB92B97F9DFFE6B01421`, command21007 global `CEA47C28C8CB9077D771F207217318FB1B6CA06B28E88B674B1BFA06D7744416`, and command21031 tracker `168770500DE325DF6B2711012FB77514B5B2B238C631AE4CCE9B054B8E789254`. Earlier command21007 CPP `E2B92F5FE277A358D91315575D44D74BA5332BEB38EB957DAE6D9E9CAC519F84`, H `1FDBE613055E145FA833971F0CB5DBA660412E01C19A5628E3BF08AB8F3BC30B`, memory `FD1018202915384A0DD2D9AE1EA66EDE1D0A9D38F1FA20A616BE37730141FBF9`, class `E8DA0181D3972058913159EAF773F5BF81B82C5EC709181DE627820523B4D766`, file `487BD67567D1167EDF01A08DC756992FA563E3FE8BF259CF0D627800DAD9B444`, type `2A5CE850ECBFB609B019D51187349DFB440483FD54FEEA7A93C0996A6D8D5E03`, global `CEA47C28C8CB9077D771F207217318FB1B6CA06B28E88B674B1BFA06D7744416`, tracker `F85AA4E1DEBE80FB190A3DFFB3FC3FA4D24A39EA8EE6E1DB510C908B0DA7EAD2`, and command21008 tracker `89D3FAD2EC1358D03F6412AB6D76B9A46973E28D918B8252B2DF606588BA59C7` are also dated predecessor evidence only.
- Manual shared-file identities literally reread for this repair are by-memory `83F9DB69CE0FA41B94B5B3EE0BFC3C1FFF2B399B869BD95B869A80F9099532CA`; by-class `92BDFAC672CF9A7CD22BFE83507875F32662E208BEAD4775E39663309F353A1A`; by-file `435FA5F4A1EE2EBD92E101B75412F814C764B271A17FDF087A0FE81F4DEDBC4D`; and by-type/by-struct `4B6995A919504E744922F1C99BE53D7A2330B53BCF3B6B67DCD65E184107ABF1`. At that dated snapshot, B005's accepted UID0002KA/UID0000Y9/UID0000BL/UID0000MZ/UID0001VN rows were physically present and compatible; B002's UID0001E4/UID0004HS Palette memory rows, UID00003Z DLPalette class row, and UID0000MA Palette file row were physically present, unrelated, and disjoint from the Ranking family rows. The same snapshot showed the UID0002K6 row in the pre-C20 form and UID0000BQ as a no-change row. C20/C21 preserve the exact supervisor-owned replacement/no-clobber policy; application status is external.
- Validator command20969 normalized the UID0002K6 link target in manual by-memory coverage as a validator-owned rename side effect. At the repair snapshot, the row still had the stale `0x0045c01a` range, `82%` score, `strong` label, and generic summary. C20 records the exact supervisor-owned replacement policy; the report body does not claim whether a later external transaction applied it.
- No older manual-coverage hash is treated as active-current authority. Any earlier identity is dated history only.
- The historical B002 family report named by the tracker for UID0002K0 does not declare UID0002K6 as an additional target. Its family discussion is useful lead material but is not child-specific report coverage.
- The earlier post-callback ordinary identity snapshot (`2668ED6A...`, `35E8196B...`, `549D8C0E...`, `C8A249EA...`, `988BD0ED...`, `BDA8807E...`) is retained only as dated pre-C27/B005 history. After C27-C31, target UID0002K6 froze at SHA256 `BB0D9E6BCFC4EEB1E7F4B4BBB8237AC0D5CCC1523A760C40971B914B770399B0`, 9396 bytes, 93 lines.
- Current shared ordinary identities after B005's disjoint accepted UID0002KA callback are UID0000Y9 aggregate `800AEFFA0752D261DDEA7BD0B5E07F377842037A16D433B1A2A04D90AD883249`, 36801 bytes, 223 lines; UID0000BL class `5FCDFFB0684E48614D48B2295FAD6D4449CD768D95E4B44F0E1D46F3D7C04B98`, 39579 bytes, 260 lines; UID0001VN layout `6DB375B2B7FB73D4C4FF8BC686ED6034DC42A18E4172E41900DF5B833C5FD7FE`, 28273 bytes, 221 lines; UID0000BQ pane `A27A5FC20168FEC30616EF34E4575D6764D48B443160C49C8ADDCF78D7FCC896`, 18436 bytes, 149 lines; UID0000MZ file `40F9B2AFB14E3B8902E3DEE8CF29775B5D0276D86D53B288900C3A5C666696F5`, 94407 bytes, 503 lines; and direct-link support UID0003YT remains `9E00B8A1F38E9EFDE00B7D1A6CAE1D480B5C2CFB9D926731C60A92E4087FC3CF`, 3748 bytes, 54 lines. Fresh reads confirm every B007 UID0002K6/postpad claim remains present alongside B005's sibling additions.

## Target

- Target UID: `0002K6`.
- Additional target UIDs: none.
- Declared-target inventory: UID0002K6 only, now `by-memory/0x0045bfe0-0x0045c01b.RankingCategoryRecordGetUserEntryAt.md`, source-emitting method child of UID0000Y9 and class-owned by UID0000BL. The former `0x0045c01a` path is retained only as pre-callback history.
- Current target path: `by-memory/0x0045bfe0-0x0045c01b.RankingCategoryRecordGetUserEntryAt.md`.
- Source queue history: command20968 listed the old path at `86/91`, combined `88.5`, and zero reports; predecessor command20976 first resolved the corrected path. Dated tracker snapshots command20995, command20997, command21007, command21008, command21031, command21036, command21048, command21052, and command21055 all show the corrected UID0002K6 path and `94/95`; lifecycle report coverage remains supervisor-owned and must be reread dynamically rather than inferred from any frozen snapshot.
- Dated supervisor audit history: exact pre-callback SHA256 `1EBF96FFB9F159B38D48D8881E57DBAA86AD9406B3894C678C857AEA2A6FE40D` passed its historical Gate1 and authorized only C27-C31; B007 completed those repairs and validators. Exact SHA256 `4BA1BF6640F0AC0EC2F562CF4F18B970592564A9AC395F0D94F6F6676069ACDD` failed on the command21031 transition; SHA256 `14BB14E2AD095F59BE7A84848FCF1D6060909FC43C228B3B3F7CBCB438A957B6` failed when command21036, B005 manual rows, and the saved IDB advanced shared authority; SHA256 `9E19F3B679235A8B32DCA9636BE8D0C50053A1D172BC75B16A36E89AE169397C` reached the dated failed-no-save Gate2B transaction; and overflow audit `2026-08-04T15:40:32-04:00` failed exact SHA256 `9974806DE8DBBF2E45577C5FC36A0CADB64DFB2892C8B6912C92612E06BC3910` only on lifecycle neutrality. These are immutable historical facts. Any current supervisor action requires a matching exact-artifact audit recorded externally; this report body does not assert its current Gate1, Gate2, execution, movement, or archive state.
- Current parent state: UID0000Y9 is a non-emitting sixteen-child split/index at `92/94`; UID0000BL is a class/header emitter at `93/95`; UID0000MZ is the source-file root at `88/91`.

## Current Target State

- Current metadata is `94/95`, owner/emitter UID0000BL, reconstructable true. Owner, emitter, and reconstructable state are unchanged from the accepted Gate1 recommendation.
- Current formal CPP is the accepted non-const `std::vector<RankingUserEntry>` body. The stale `m_userEntriesBegin/m_userEntriesEnd` body remains documented only as corrected history.
- Current target H payload remains blank as intended because UID0000BL owns the declaration. UID0000BL now carries `RankingUserEntry* GetUserEntryAt(int index);` without the unsupported trailing `const`.
- Current ordinary-document truth records the exact signed upper-bound-only contract, negative-index before-begin pointer result, sole `0..9` caller contract, no callees, and a five-byte non-emitting postpad represented in IDA by one existing unnamed, untyped, non-code data item over `[0x0045c01b,0x0045c020)`. C27-C31 place that same model in the target, UID0000Y9 aggregate, UID0001VN layout, UID0000BL class, and UID0000MZ file pages.
- B005's later shared additions are compatible and separately owned: UID0002KA clears the same source vector without freeing capacity, writes `m_localPlayerRank = -1`, and is called before a page request. Those facts strengthen the existing vector abstraction but do not modify UID0002K6's signed accessor contract or transfer sibling coverage into this report.
- Current path/title end at the correct half-open `0x0045c01b`; the old path is absent and direct ordinary-document links are corrected.
- Source routing remains direct class owner/emitter UID0000BL and file source UID0000MZ.
- Current coherent command21052 CPP/H and generated aggregates preserve UID0002K6 exactly and include B005's separate UID0002KA source once. The dated manual snapshot preserves B005's Ranking rows and B002's disjoint Palette rows. The dated `2026-08-04T14:21:00-04:00` UID0002K6 attempt was discarded without save, fresh-session rollback was verified, and the repair-time B002-backed read-only session reproduced every ID01-ID06 prestate. C20 and C23 state stable supervisor replacement/refresh policy without claiming current application status. Command21036, command21048, mixed command21031-era, and earlier generated authorities are dated history; command21052 tracker is also dated, while command21055 is the repair-time tracker snapshot and remains dynamically reread.
- Artifact lifecycle language is intentionally neutral: report execution/archive state is authoritative only from the artifact's current path and validator-owned lifecycle metadata. This body records report-only research, completed callback results, and current-authority reconciliation without asserting a pending, executed, moved, or archived state.

## Executive Recommendation

- Keep UID0002K6 owned/emitted by UID0000BL and placed in `RankingDialog.cpp`.
- Correct the child filename/title/range to the true half-open `[0x0045bfe0,0x0045c01b)` extent.
- Emit a non-const source method using `static_cast<int>(m_userEntries.size())`, an upper-bound-only signed comparison, `NULL`, and `&m_userEntries[index]`.
- Replace `RankingUserEntry* GetUserEntryAt(int index) const;` in the UID0000BL formal H block with `RankingUserEntry* GetUserEntryAt(int index);`.
- Preserve the deliberate absence of an `index < 0` check. Do not use `at()`, unsigned-only comparison, exception handling, or a defensive lower-bound guard.
- Raise UID0002K6 to `94/95`. Keep support metadata unchanged unless a later supervisor-wide score audit chooses to credit the class separately.
- Apply the target function/type/comment IDA handoff at Gate 2B; preserve the existing five-byte postpad data item exactly and do not create a function, name, type, comment, or patch over it or over the raw setter at `0x0045c020`.

## Supervisor Active Recheck

- Historical assignment trigger: the B007 Gate1 goal required a fresh UID0002K6 child audit and rejected historical family-report discussion as coverage. The current supervisor override is the same-report authority reconciliation recorded here.
- Split repair was required only as a range/path correction. No new source-bearing child is needed because one modeled function already occupies the target; `[0x0045c01b,0x0045c020)` is five bytes of `0xcc` alignment stored as one existing unnamed, untyped, non-code IDA data item, not a source body.
- Every source-bearing item in the assigned range is accounted for by UID0002K6. The next source-shaped body begins at `0x0045c020` and is already documented separately as UID000428.
- Command20968 tracker and command20963 category/source artifacts were accepted historical Gate1 baselines. Callback validators20969-20976, commands20995/20997/21007/21008, the mixed command21031-era files, command21036, and command21048 are dated history for superseded artifacts. B005's accepted transaction/manual work culminated in command21036; B002's unrelated Palette/UID0004HS work advanced the coherent physical authority to command21052 without any direct B007 generated/tracker edit. Every tracker identity still requires dynamic reread.

## Inference Research Guidance Check

- Direct IDA facts, documentation evidence, and inference are separated throughout this report.
- Existing assumptions treated as uncertain were the `0x0045c01a` endpoint, `const` declaration, raw vector-field C++, broad "bounds-checked" wording, and the dated IDA snapshot's missing row type.
- The binary proves physical begin/end pointers but not developer source fields. Append, reset, growth, clone, destroy, class H, and generated H together prove the source abstraction is `std::vector<RankingUserEntry>`.
- The binary ABI does not encode member-function constness. Mutable pointer return, non-const sole caller, and ordinary vector source shape make a non-const method substantially more plausible than a const method plus `const_cast`.
- `GetUserEntryAt`, `m_userEntries`, `RankingUserEntry`, `userEntryCount`, and `index` are inferred/source-facing names. They are not claimed as recovered symbols.
- Any Wave2/Wave3 mentions encountered in historical documentation were ignored as stale and were not used as evidence.

## Heuristic / Inference Reanalysis And Validation

| Issue | Evidence checked | Best resolution | Classification |
| --- | --- | --- | --- |
| Function endpoint and physical postpad item | IDA modeled size `0x3b`, full bytes, disassembly, adjacent bytes, and fresh `inspect_items` at all five postpad addresses | Rename end from `0x0045c01a` to half-open `0x0045c01b`; preserve `[0x0045c01b,0x0045c020)` as alignment and as one existing unnamed/untyped/non-code five-byte data item | Direct fact |
| Negative index | Signed `cmp` plus `jg`, return arithmetic, caller loop | Preserve upper-bound-only signed behavior; do not add lower-bound guard | Direct fact |
| Source vector form | Target count/index math, append/reset/growth support, UID0000BL H | Use `std::vector<RankingUserEntry>` rather than physical begin/end source fields | Strong inference backed by repeated compiler layout |
| Method constness | ABI neutrality, mutable pointer return, current vector declaration, caller | Remove `const`; reject source-only `const_cast` | High-probability source inference |
| Row type/layout | Append copies 76 bytes; parser/paint use `+0/+4/+8/+0x48` | Keep `RankingUserEntry { categoryId, rank, name[32], score }`, size `0x4c` | Strong documentation plus live binary corroboration |
| Return type | Success returns begin plus `index*76`; failure returns zero | `RankingUserEntry *`, nullable | Direct behavior plus inferred type |
| Ownership | Receiver offset `+0x258`, record sibling methods, source tree | UID0000BL direct owner/emitter; UID0000MZ file source | Very strong |
| Generated mismatch | Historical command20963/command21007/mixed-command21031/command21036 states and current coherent command21052 readback | B007's source docs remain corrected; B005's disjoint sibling callback supplied the separate UID0002KA form, and current command21052 regenerates both accepted UID0002K6 and UID0002KA source forms once under coherent routes without direct generated edits by B007 | Direct dated and current generated facts |
| IDA source quality | Dated session9081c1f3 snapshot: `sub_45BFE0`, integer prototype, absent row UDT/comments | Dynamically bind the canonical IDB, then define/type/rename/comment through supervisor Gate 2B | Implementation-ready repair |

Rejected alternatives:

- `if (index >= 0 && index < count)` changes executable behavior for negative indexes.
- `m_userEntries.at(index)` adds lower-bound/range checks and exception behavior absent from the executable.
- `index < m_userEntries.size()` performs an unsigned comparison on ordinary standard-library implementations and rejects negative indexes, unlike the signed `jg` body.
- Retaining raw `m_userEntriesBegin/m_userEntriesEnd` source fields contradicts the current source declaration and leaks compiler container layout.
- Retaining `const` requires a non-evidenced `const_cast` to return a mutable pointer from a const vector.
- Collection, pane, or generic vector-helper ownership is rejected because the receiver is a `RankingCategoryRecord` and the method is in its method cluster.

## Evidence Standards Used

- Dated live read-only IDA MCP snapshots: server health, open database identity, function lookup, decompilation, disassembly, raw bytes, xrefs, callees, stack frame, comments, entity/type queries, byte-pattern searches, and immediate searches. Dynamic authority selection remains mandatory before any current-state or Gate2B use.
- Primary-supervisor audit `2026-08-04T14:21:00-04:00 - Primary B007 UID0002K6 Gate 2B Failed Transaction / No-Save Rollback - 9E19F3B6`: exact prestate, backup identity, ID01-ID03 progress, deterministic automatic `m_userEntriesBegin` Hex-Rays rendering, absence of any local rename/type request, fail-closed stop, no-save worker teardown, and fresh-session canonical rollback readback.
- Raw executable verification: PE raw offset `0x5b3e0`, 59-byte body, SHA256 `775ce790509e5e305dd258b915880e77e78219e06e4679c6c9b607e988277372`.
- Documentation reread for this report-repair snapshot: target, UID0000Y9 aggregate, UID0000BL class, UID0001VN layout, UID0000BQ caller class, UID0000MZ file, append/reset siblings, and associated manual coverage rows. C20-C22 state stable dynamic-reread/no-clobber policy; whether an external supervisor action has applied that policy is not asserted here.
- Repair-time generated-source and non-tracker aggregate evidence is coherent command21052, with exact hashes and semantics listed above. Repair-time tracker command21055/SHA256 `BBFB31CCB98E6EE4BD37E6D6194EBFBCC1A8AC135D4A11EA07278529A0242E86` preserves UID0002K6 at `94/95`, reconstructable true, counts `0/0/0`, and UID0002KA at `94/95`, reconstructable true, counts `1/0/1` with direct B005 execution/archive history. Commands20995/20997/21007/21008, the mixed command21031-era set, command21036, command21048, and command21052 tracker identity are dated predecessor evidence. No tracker identity substitutes for dynamic supervisor readback; C23 is stable refresh policy rather than a current-status assertion.
- Negative evidence from the dated canonical-IDB snapshots and the fresh read-only `b002-uid0004hs-persist-reopen`/PID20412 check: no target callees, no data/pointer/immediate routes, no lower-bound branch, no exception path, no xref to endpoint/postpad, and no `RankingUserEntry` IDA type. B002's unrelated saved changes did not affect ID01-ID06, but Gate2B must dynamically reread these prestates; session rotation alone does not negate them.
- Evidence is sufficient for `94/95` because behavior, extent, caller, layout, route, and formal source repair are all implementation-ready; missing retail symbols prevent claiming exact original spellings.

## Evidence Checked

- IDA MCP/manual checks: `server_health`, `idb_list`, `lookup_funcs` at target/end/postpad/successor/caller, `analyze_function`, `decompile`, `xrefs_to`, `callees`, `get_bytes`, `get_comments`, `inspect_items` at every address `0x0045c01b..0x0045c01f`, `stack_frame`, `type_query`, `entity_query`, `find_bytes`, and immediate `find`; the repair-time read-only repetition used healthy session `b002-uid0004hs-persist-reopen`/PID20412 and made no mutation or save.
- Target bytes: 59 bytes beginning `55 8b ec 56 8b b1 58 02 00 00` and ending `6b c1 4c 03 c6 5e 5d c2 04 00`; raw/IDA hashes agree.
- Support binary: `0x0045c1e0` append uses `+0x258/+0x25c/+0x260`, copies `0x4c`, and calls growth only when full; `0x0045c240` resets end to begin; `0x0045f3a0` loops indexes `0..9` and reads returned row fields.
- Documentation checked: target, current UID0000Y9/UID0000BL/UID0001VN/UID0000BQ/UID0000MZ shared pages, sibling UID0002KA, UID000204 analogous reward-item accessor, all repair-snapshot associated manual coverage rows including B002's disjoint Palette additions, coherent command21052 CPP/H/memory/class/file/type/global non-tracker output, repair-time tracker command21055, and dated predecessor tracker/source snapshots through command21052 tracker and the mixed command21031 era.
- Failed/unavailable checks: original retail symbols are absent; `RankingUserEntry` and `RankingUserListPane` UDTs were absent from the dated session9081c1f3 IDA type catalog. These are resolved with exact type/prototype recommendations rather than deferred; Gate2B must freshly verify the selected database's prestate before applying them.
- Gate1 intentionally skipped all IDA mutation/save operations, validators, generated edits, lifecycle execution, and by-* edits. During the accepted callback B007 edited only authorized ordinary destinations, ran scoped validators20969-20976, and still performed no IDA, manual coverage, direct generated/tracker, audit/catalog, or lifecycle mutation.

## Claim And Incorporation Ledger

This is the sole authoritative implementation ledger. Its 31 atomic rows are mirrored one-for-one by the single checklist at the end of this report, with identical claim ID, UID, destination, action, actor, and verification state. The stable population records 19 `applied` rows, one `already-present` row, one `excluded-with-reason` row, nine unchecked `supervisor-owned-recommendation` rows that grant B007 no external-action credit, and one checked `policy-recorded` lifecycle row that grants no execution credit. Current external action and lifecycle status is authoritative only from matching supervisor audit/IDA/manual/generated records, current path, and validator-owned lifecycle metadata.

| Claim ID | UID | Destination | Action | Actor | Verification state |
| --- | --- | --- | --- | --- | --- |
| C01 | 0002K6 | `by-memory/0x0045bfe0-0x0045c01a.RankingCategoryRecordGetUserEntryAt.md` path/title and every direct link | Rename the target endpoint to half-open `0x0045c01b` while preserving UID0002K6. | B007 callback | applied |
| C02 | 0002K6 | UID0002K6 Status, IDA evidence, range, and padding sections | Add the exact 59-byte extent, raw offset `0x5b3e0`, body SHA256 `775ce790509e5e305dd258b915880e77e78219e06e4679c6c9b607e988277372`, terminal return bytes, and five-byte CC postpad proof. | B007 callback | applied |
| C03 | 0002K6 | UID0002K6 Behavior and Reconstruction sections | Document the signed upper-bound-only comparison and exact negative-index before-begin pointer behavior without adding a lower-bound guard. | B007 callback | applied |
| C04 | 0002K6 | UID0002K6 caller contract | Document the sole call at `0x0045f637`, the caller's `0..9` loop, null contract, no callees, and no alternate entry route. | B007 callback | applied |
| C05 | 0002K6 | UID0002K6 formal `RECONSTRUCTION_CPP CODE` | Replace the stale physical-pointer draft with the exact non-const `std::vector` source body in this report. | B007 callback | applied |
| C06 | 0002K6 | UID0002K6 formal `RECONSTRUCTION_H CODE` | Keep the target H payload blank because the class page owns the declaration. | B007 callback | already-present |
| C07 | 0002K6 | UID0002K6 metadata, Item Summary, and change history | Set `COMPLETION:94`, `CONFIDENCE:95`; preserve owner/emitter/reconstructable fields; add the exact summary and retain corrected stale-endpoint/raw-field/const history. | B007 callback | applied |
| C08 | 0000BL | `by-class/RankingCategoryRecord.md` formal H declaration | Replace `RankingUserEntry* GetUserEntryAt(int index) const;` with `RankingUserEntry* GetUserEntryAt(int index);`. | B007 callback | applied |
| C09 | 0000BL | `by-class/RankingCategoryRecord.md` behavior, method table/link, layout interpretation, and history | Incorporate the signed contract, mutable return, vector source shape, corrected endpoint, and rejected raw-member/const assumptions without pruning prior evidence. | B007 callback | applied |
| C10 | 0001VN | `by-type/by-struct/RankingCategoryRecordLayout.md` nested-row/accessor evidence | Add the exact `0x4c` row/accessor/caller evidence and corrected endpoint/padding while preserving metadata. | B007 callback | applied |
| C11 | 0000Y9 | `by-memory/0x0045bf60-0x0045c257.RankingCategoryRecord.md` child inventory/range analysis | Correct the UID0002K6 child link/end and add five-byte postpad evidence while preserving non-emitting `Nested:16`. | B007 callback | applied |
| C12 | 0000BQ | `by-class/RankingUserListPane.md` paint/caller evidence | Add the sole-caller `0..9` nonnegative-loop contract and corrected UID0002K6 child link. | B007 callback | applied |
| C13 | 0000MZ | `by-file/RankingDialog.md` source route and generated-state notes | Add the child-specific non-const vector-source route; preserve command20963/20975-20976/20995/21007/21008, mixed command21031-era identities, command21036, and command21048 as dated history; bind active-current generated readback to coherent command21052 CPP/H/aggregates without changing the file route. | B007 callback | applied |
| C14 | 0002K6 | IDA type catalog `RankingUserEntry` | Gate2B recommendation policy: dynamically run `idb_list`/`server_health`, freshly bind canonical disk authority against repair snapshot `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, `143196420` bytes, SHA256 `CE0222E87E1A569A73EB43DD72BF53412B103DD9281A535EEC2BCC01DE0932FA`, last written `2026-08-04T14:52:17-04:00`, then ID01 declares and reads back the exact four-member, 76-byte `RankingUserEntry` UDT; `b002-uid0004hs-persist-reopen`/PID20412 and all earlier session/PID evidence are bounded snapshots, so select the then-healthy session at mutation time. | Primary supervisor Gate2B | supervisor-owned-recommendation |
| C15 | 0002K6 | IDA UDT `RankingCategoryRecord` | Gate2B recommendation policy: after the same dynamic health check and fresh canonical path/size/SHA binding required by C14, ID02 redeclares the complete 15-member/688-byte model with only `+0x258/+0x25c/+0x260` changed from `void *` to `RankingUserEntry *`; protect all other members. | Primary supervisor Gate2B | supervisor-owned-recommendation |
| C16 | 0002K6 | IDA function `0x0045bfe0` | Gate2B recommendation policy: after the same dynamic health check and fresh canonical path/size/SHA binding required by C14, ID03 collision-checks, renames, sets the exact prototype and regular function comment, and proves extent/frame/xrefs/bytes/decompilation readback; accept Hex-Rays' deterministic automatic post-type rendering of the untouched register local as `m_userEntriesBegin` while requiring no explicit local rename/type action. | Primary supervisor Gate2B | supervisor-owned-recommendation |
| C17 | 0002K6 | IDA target register local (prestate `v2`; automatic post-render `m_userEntriesBegin`) | Gate2B recommendation policy: after the same dynamic health check and fresh canonical path/size/SHA binding required by C14, ID04 is a literal no-change decision; issue no local rename and no local type action, preserve the register/local/frame constraints, and accept `m_userEntriesBegin` only as Hex-Rays' deterministic automatic decompiler consequence of ID01-ID03, not as an explicit local mutation. | Primary supervisor Gate2B | supervisor-owned-recommendation |
| C18 | 0000BQ | IDA caller `0x0045f3a0` and opaque `RankingUserListPane` type | Gate2B recommendation policy: after the same dynamic health check and fresh canonical path/size/SHA binding required by C14, ID05 declares the forward type, collision-checks, renames/types/comments the caller, and proves its full unchanged frame, extent, vtable xref, target call, and decompilation readback. | Primary supervisor Gate2B | supervisor-owned-recommendation |
| C19 | 0002K6 | IDA `[0x0045c01b,0x0045c020)` | Gate2B recommendation policy: after the same dynamic health check and fresh canonical path/size/SHA binding required by C14, ID06 makes no mutation and proves one existing physical item with head `0x0045c01b`, end `0x0045c020`, size `5`, unnamed, untyped, `is_code:false`, `is_data:true`, bytes `cc cc cc cc cc`, blank comments, and zero xrefs remains unchanged; create/delete/resize/retype/name/comment/function/patch actions are forbidden. | Primary supervisor Gate2B | supervisor-owned-recommendation |
| C20 | 0002K6 | `by-memory/-coverage-report.md` UID0002K6 row | Supervisor manual-coverage policy: under matching external exact-artifact Gate1/Gate2 records, dynamically reread by-memory manual coverage (repair snapshot SHA256 `83F9DB69CE0FA41B94B5B3EE0BFC3C1FFF2B399B869BD95B869A80F9099532CA` showed `82%` and range text ending `0x0045c01a` at line 419), replace that stale path/score/detail with the exact row in this report when still applicable, and validate the replacement before any lifecycle execution. | Primary supervisor | supervisor-owned-recommendation |
| C21 | 0000Y9/0000BL/0000BQ/0000MZ/0001VN | Current manual by-memory/by-class/by-file/by-type rows and identities | Supervisor no-clobber policy: dynamically reread all six associated rows against repair snapshot hashes by-memory `83F9DB69CE0FA41B94B5B3EE0BFC3C1FFF2B399B869BD95B869A80F9099532CA`, by-class `92BDFAC672CF9A7CD22BFE83507875F32662E208BEAD4775E39663309F353A1A`, by-file `435FA5F4A1EE2EBD92E101B75412F814C764B271A17FDF087A0FE81F4DEDBC4D`, and by-type/by-struct `4B6995A919504E744922F1C99BE53D7A2330B53BCF3B6B67DCD65E184107ABF1`; preserve compatible B005 UID0002KA/shared UID0000Y9/0000BL/0000MZ/0001VN rows, preserve UID0000BQ when no change is supported, treat B002's UID0001E4/UID0004HS/UID00003Z/UID0000MA Palette rows as compatible/disjoint, and ensure C20 clobbers none of those rows. | Primary supervisor | supervisor-owned-recommendation |
| C22 | 0002K6/0000BL/0001VN/0000Y9/0000BQ/0000MZ | Every renamed or edited by-* destination | Preserve the dated successful scoped validators20969-20976 and their callback readbacks as applied evidence; at Gate2A dynamically reread every current ordinary destination identity and exact metadata/formal-source/content state rather than assuming the historical hashes remain current. | B007 callback | applied |
| C23 | 0002K6 | Validator-generated CPP/H, coverage reports, and research tracker | Supervisor generated-refresh policy: after the external IDA/manual prerequisites required by current project standards, perform one coherent refresh newer than generated baseline command21052, verify UID0002K6 and separately owned UID0002KA each occur exactly once through UID0000BL/RankingDialog.cpp, and capture tracker identity only as a dated same-gate snapshot. Command21036/SHA256 `CE703CBE51083E3051C288318334B929FCD31FF80933150099B5FBE6027DF135`, command21048/SHA256 `42EFF3C38E67C15C1AFF400F8D8AE2BAD5A4169258564A4163D6450524EE1B3D`, command21052/SHA256 `9D921C8C650C3B27E692BFA8BB371A4F95C2F00BC7EAF309877F28B8F843392C`, and repair-time command21055/SHA256 `BBFB31CCB98E6EE4BD37E6D6194EBFBCC1A8AC135D4A11EA07278529A0242E86` are dated snapshots; current tracker truth is always reread dynamically. | Primary supervisor | supervisor-owned-recommendation |
| C24 | 0002K6 | Report lifecycle policy for this exact artifact | Stable supervisor lifecycle policy: execution and post-move review are supervisor-only and are permitted only when immutable external audit history records matching exact-artifact Gate1/Gate2 plus all required IDA/manual/generated work under current standards. Actual execution, movement, archive, and post-move status is authoritative solely from immutable audit history, the report's current path, and validator-owned status/history metadata; tracker and canonical IDB/session truth are reread dynamically for each action. This checked row proves policy presence only and grants no lifecycle credit. | Primary supervisor | policy-recorded |
| C25 | 0002K6/0000BL | Target/class historical assumptions and rejected alternatives | Preserve raw-field, const, defensive lower-bound, stale-endpoint, and conditional-IDA recommendations as dated corrected history with reasons; do not prune them. | B007 callback | applied |
| C26 | 0002KA | Sibling child `[0x0045c240,0x0045c256)` / `by-memory/0x0045c240-0x0045c256.RankingCategoryRecordResetUserEntries.md` | Do not edit, fold, claim, or execute sibling UID0002KA through this report. B005's separate accepted child-specific callback legitimately advanced that sibling and shared support pages; preserve those compatible additions as external state without transferring coverage or authorship to UID0002K6. | B007 callback | excluded-with-reason |
| C27 | 0002K6 | `by-memory/0x0045bfe0-0x0045c01b.RankingCategoryRecordGetUserEntryAt.md` postpad item model | Replace the current item-absence assertion in Status/IDA evidence/Range And Padding with the exact existing-item model: one unnamed, untyped, non-code five-byte data item at `[0x0045c01b,0x0045c020)`, bytes `cc cc cc cc cc`, blank comments, zero xrefs, and no source emission; preserve the earlier absence claim as dated corrected history. | B007 callback | applied |
| C28 | 0000Y9 | `by-memory/0x0045bf60-0x0045c257.RankingCategoryRecord.md` child inventory/range/evidence | Clarify that the five-byte alignment span is represented by one existing unnamed, untyped, non-code data item with five CC bytes, blank comments, and zero xrefs; it remains aggregate padding, not a child or emitter. | B007 callback | applied |
| C29 | 0001VN | `by-type/by-struct/RankingCategoryRecordLayout.md` UID0002K6 postpad evidence | Add the exact existing five-byte data-item model and preserve its distinction from source-authored record layout, child coverage, and emitted code. | B007 callback | applied |
| C30 | 0000BL | `by-class/RankingCategoryRecord.md` UID0002K6 evidence/history | Add the exact existing five-byte data-item model to the UID0002K6 endpoint/postpad evidence while preserving class ownership, method source, and no-source-alignment disposition. | B007 callback | applied |
| C31 | 0000MZ | `by-file/RankingDialog.md` UID0002K6 source-route/history | Clarify that the five-byte non-emitting alignment span is one existing unnamed, untyped, non-code data item with five CC bytes, blank comments, and zero xrefs; preserve file placement and all source routing. | B007 callback | applied |

## Positive Evidence Summary

- IDA models one 59-byte `__thiscall` function at `0x0045bfe0` and one direct call at `0x0045f637`.
- The body reads `this+0x258` and `this+0x25c`, divides their signed byte difference by 76, compares the count to the signed input, and returns `begin + 76*index` or zero.
- The caller loops from zero through nine, null-checks the result, and reads rank at `+4`, name at `+8`, and score at `+72`.
- Append, growth, reset, clone, destruction, layout docs, and class H independently agree that the three physical slots are one `std::vector<RankingUserEntry>`.
- The exact `RankingUserEntry` source layout has size `0x4c`: `int categoryId`, `int rank`, `wchar_t name[32]`, `int score`.
- Source placement and owner/emitter routing are already coherent through UID0000BL and UID0000MZ.
- The strongest inference chain is the source form: signed count from vector size, upper-bound-only comparison, nullable pointer return, and standard vector indexing. It preserves the binary while removing compiler-layout names.

## IDA MCP Facts

- Dated session9081c1f3 database snapshot: `b005-persist-reopen`/PID2652; target name `sub_45BFE0`; modeled size `0x3b` / 59 bytes. The session is closed and is not current authority; a dynamically selected canonical-IDB session must reprove this prestate.
- Current canonical rollback prestate prototype: `int __thiscall(_DWORD *this, int)`; decompiler argument `a2`; local `v2` is `int` in `esi`; stack argument is `arg_0` type `_DWORD` at frame offset `+0xc`.
- Dated failed-transaction post-ID03 evidence: with ID01/ID02 exact types and the target's exact function type temporarily applied, Hex-Rays automatically rendered the same untouched `esi` local as `RankingUserEntry *m_userEntriesBegin`. No local rename/type request was issued, and fresh no-save rollback restored `int v2`; this proves the render transition is deterministic type propagation rather than persistent or explicit local mutation.
- Current pseudocode computes `(this[151] - this[150]) / 76`, compares it to `a2`, returns `this[150] + 76*a2` on signed greater-than, otherwise zero.
- Exact body range: `[0x0045bfe0,0x0045c01b)`; full `retn 4` bytes occupy `0x0045c018-0x0045c01a`.
- Alignment: five `0xcc` bytes at `[0x0045c01b,0x0045c020)` are represented by one existing physical item with head `0x0045c01b`, end `0x0045c020`, size `5`, unnamed, untyped, `is_code:false`, and `is_data:true`; comments are blank and xrefs are zero. In the dated IDA snapshot raw source-shaped UID000428 begins at `0x0045c020` but is not modeled as a function. Dynamic Gate2B readback must reprove both physical-item states.
- Xrefs: one code xref to target start from `0x0045f637`; zero xrefs to `0x0045c01a` and `0x0045c01b`; no callees.
- Pointer/immediate searches found no stored VA, RVA, or raw-offset pointer for the target; direct relative call liveness is sufficient.
- Target address comments: regular absent, repeatable absent, function regular absent, function repeatable absent.
- Current `RankingCategoryRecord` UDT exists at size `0x2b0` / 688 and has `void *` fields `m_userEntriesBegin`, `m_userEntriesEnd`, and `m_userEntriesCapacityEnd` at `+0x258/+0x25c/+0x260`.
- `RankingUserEntry` is absent from the IDA type catalog. `RankingUserListPane` is also absent.
- Caller `sub_45F3A0` is size `0x5a5`, currently polluted as `void __thiscall(GrafPort *this)`, has no direct caller because it is virtual, and has all regular/repeatable function comments absent.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `[0x0045bfe0,0x0045c01b)` | UID0002K6 corrected path | `RankingCategoryRecord::GetUserEntryAt` | true | UID0000BL | current `94/95`; historical `86/91` | assigned source-bearing method |
| `[0x0045c01b,0x0045c020)` | aggregate padding | one existing unnamed/untyped/non-code five-byte data item containing `cc cc cc cc cc` | no source body | UID0000Y9 | n/a | preserve item exactly as padding; no function/name/type/comment/patch or child |
| `0x0045c020` raw body | UID000428 | `SetListIndex` sibling | true | UID0000BL | independent | out of target range |
| `0x0045c1e0` | UID0002K9 | append support | true | UID0000BL | `86/90` | corroborates vector/stride |
| `0x0045c240` | UID0002KA | reset support | true | UID0000BL | `86/91` | corroborates vector triplet |
| `0x0045f3a0` | UID0000BQ support | `RankingUserListPane::OnPaint` | true | UID0000MZ | support score unchanged | sole caller and row consumer |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0045f637 -> 0x0045bfe0` | sole code caller | Paint requests row indexes from a bounded ten-iteration loop |
| `0x0045f629-0x0045f75a` | caller loop | `i` begins at zero, continues while `i < 10`, and increments by one |
| caller row `+0x04` | rank read | formatted as integer rank |
| caller row `+0x08` | name read | formatted as wide string |
| caller row `+0x48` | score read | formatted as integer score |
| target callee set | empty | accessor is self-contained vector arithmetic |
| target endpoint/postpad | zero xrefs | no alternate entry or data route at the boundary |
| `0x0045cd5d -> 0x0045c1e0` | append support caller | parser appends exact `0x4c` rows |
| `0x004594f7 -> 0x0045c240` | reset support caller | selected-category path resets vector end and local rank |

## Documentation Evidence And IDA Status

- UID0000BL already supplies the exact `RankingUserEntry` fields and source-facing vector member, but its `GetUserEntryAt` declaration has an unsupported `const` suffix.
- UID0001VN supplies the exact `0x2b0` record layout, physical vector triplet, and `0x4c` row field table.
- UID0000BQ documents the ten-row paint loop and row field consumers.
- UID0000Y9 correctly treats the broad record family as a non-emitting sixteen-child index, but its UID0002K6 link/end and range evidence are stale.
- UID0000MZ remains the correct `RankingDialog.cpp/.h` source route.
- Historical command20963 generated source was internally inconsistent for UID0002K6: CPP used removed physical fields while H declared `m_userEntries` and a const method; command20968 advanced only the tracker, command20975/20976 were callback-time corrections, and command20995/command21007/mixed-command21031/command21036 files are dated predecessor generation. Current coherent command21052 CPP/H reproduces UID0002K6's accepted non-const vector body/declaration and B005's separate source-facing UID0002KA reset body exactly once. C23 records the stable supervisor generated-refresh policy; its external application status is not stated here.
- Command21052 generated memory coverage says both UID0002K6 and UID0002KA are `coded` through RankingDialog.cpp with owner/emitter UID0000BL, CPP yes, H no. Repair-time tracker command21055/SHA256 `BBFB31CCB98E6EE4BD37E6D6194EBFBCC1A8AC135D4A11EA07278529A0242E86` retains UID0002K6 at its corrected path, `94/95`, reconstructable true, with counts `0/0/0`; it records executed sibling UID0002KA at `94/95`, reconstructable true, with counts `1/0/1`, direct agent `B005`, execution timestamp `2026-08-04T14:23:55`, and archive `executed-b-agent-research/B005/0002KA-RankingCategoryRecordResetUserEntries-source-quality.md`. Command21036/`CE703C...135B`, command21048/`42EFF3...1B3D`, and command21052/`9D921C...3392C` are dated tracker evidence. Source emission and B-report coverage remain separate registries, and tracker truth always requires dynamic gate readback.
- Historical claims that all eleven method names were once saved in IDA are not established current truth for this target: the dated session9081c1f3 snapshot named it `sub_45BFE0`. The next Gate2B/current-state check must reread the dynamically selected canonical database rather than assume either name state.

## Ranked Ownership Analysis

### 1. UID0000BL RankingCategoryRecord

- Evidence for: the target reads receiver offsets `+0x258/+0x25c`, sits inside the record method cluster, returns a record-owned row, and is declared by this class.
- Evidence against: no original class symbol survives at the target.
- Decision: direct canonical owner and emitter, very strong.

### 2. UID0000MZ RankingDialog

- Evidence for: current source-tree route, aggregate placement, generated CPP/H route, and all ranking UI support are in this file family.
- Evidence against: it is a file owner, not the direct semantic class owner.
- Decision: retain as source file, not direct child owner.

### 3. UID0000BK RankingCategoryCollection or UID0000BQ RankingUserListPane

- Evidence for: the collection populates records and the pane is the sole caller.
- Evidence against: neither owns the `+0x258` vector member; consumer/populator relationships do not transfer method ownership.
- Decision: reject both as direct owners.

### Proposed new file/grouping, if applicable

- No new source file or class is warranted.
- Keep `RankingUserEntry` as a support struct in `RankingDialog.h` beside `RankingCategoryRecord`.
- Keep UID0002K6 as an exact by-memory child definition routed into `RankingDialog.cpp`.

## Source Placement

- Recommended source: `NexusTK/ui/dialogs/RankingDialog.cpp`, with declaration and `RankingUserEntry` in `RankingDialog.h` through UID0000BL.
- This placement matches the contiguous ranking method cluster, existing project ownership, collection/parser callers, and generated route.
- Rejected placements: `RankingUserListPane.cpp` because the pane only consumes rows; collection-owned source because the receiver is the record; generic vector utility because the method is source-authored record API.
- No material placement uncertainty remains.

## Range / Split / Padding / Reclassification Analysis

- Exact body: `[0x0045bfe0,0x0045c01b)`, size `0x3b` / 59.
- The historical pre-callback `0x0045c01a` endpoint omitted the final byte under the project's half-open convention. `0x0045c01a` itself is the third byte of `c2 04 00`; the current endpoint is `0x0045c01b`.
- Exact postpad: `[0x0045c01b,0x0045c020)`, five `0xcc` bytes, represented by one existing physical data item with head `0x0045c01b`, end `0x0045c020`, size `5`, no name or type, `is_code:false`, `is_data:true`, blank comments, and zero xrefs.
- Predecessor `GetTitleText` is `[0x0045bfd0,0x0045bfd4)`, followed by twelve `0xcc` bytes before the target.
- Successor UID000428 begins at `0x0045c020`; the dated session9081c1f3 IDA snapshot did not model that raw setter as a function, but its separate page remains valid. Dynamic Gate2B readback must confirm the same boundary/item state.
- Callback result: the UID0002K6 file/title and all ordinary links now end at `0x0045c01b`, and UID0002K6/UID0000Y9 document the postpad.
- No new source child, merge, or ownership reclassification is needed. UID0000Y9 remains `Nested:16` because padding is not a source-bearing child.

## Negative Evidence Summary

- No callee, exception, range-check helper, `std::out_of_range`, or lower-bound branch exists.
- No data xref, VA pointer, RVA pointer, raw-offset pointer, or immediate route points to the target. The direct call at `0x0045f637` is the only external route.
- No evidence supports adding `index >= 0`; the exact signed `jg` accepts negative values when count is nonnegative.
- No evidence proves the method was const. The binary calling convention is identical either way.
- No evidence supports preserving `m_userEntriesBegin/m_userEntriesEnd` as developer-authored members after the vector reconstruction.
- No evidence supports `RankingCategoryCollection`, `RankingUserListPane`, or a generic vector helper as direct owner.
- No xref enters the final return bytes or postpad, rejecting an overlapping child or alternate entry.
- Original retail symbols are absent. This prevents 100% lexical-name confidence but does not justify retaining `sub_45BFE0`, `_DWORD`, `a2`, or raw pointer fields.

## IDA Rename / Type / Comment Recommendations

### Gate2B database binding and fresh prestate

- Current repair-time canonical disk authority is `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, size `143196420`, SHA256 `CE0222E87E1A569A73EB43DD72BF53412B103DD9281A535EEC2BCC01DE0932FA`, last written `2026-08-04T14:52:17-04:00`, after B002's unrelated saved UID0004HS transaction. Repair-time session `b002-uid0004hs-persist-reopen`, PID `20412`, is a bounded read-only snapshot only. SHA256 `85582A483733EC1F54725DBC305E16219A4C6E86B0D948563AF87E59C035AF5D`, SHA256 `74720635DA2BED8F69DFFDBE8E7ED345C6F6ECB44F38FF03A8E8FACC9539FC46`, size `143196412`, SHA256 `92CD98A20133155CEC96C4AB6B60A00B7C5635A7C47E0A3F51BE918C13ACC5A0`, and former b005/PID2652/session9081c1f3 bindings are dated history, not executable current bindings.
- Before any Gate2B mutation, current-state assertion, persistence proof, or post-move audit, the primary supervisor must freshly run `idb_list` and `server_health`, reread the canonical disk path/size/SHA256, require a healthy session, select the database then bound to that canonical IDB, and record its returned database ID, worker PID, and session identity for that bounded check. The symbolic `<gate2b-database>` below means only that freshly selected database; neither the current gate SHA nor any replacement session identity may be assumed to remain current later.
- Dated read-only session `9081c1f3-bc94-49a3-a909-a60eafeb0a99` reconfirmed `idb_list` active/owned/adopted, `server_health.status=ok`, `hexrays_ready=true`, target/caller lookup, frames, comments, xrefs, type catalog, proposed-name collisions, bytes, and decompilation. Fresh repair-time read-only session `b002-uid0004hs-persist-reopen`/PID20412 repeated those bounded checks against the current canonical disk and proved B002's unrelated saved transaction did not alter ID01-ID06. `auto_analysis_ready=false` was contextual because all bounded IDB-backed reads succeeded. Session rotation does not invalidate these facts, but the selected Gate2B database must freshly reproduce every prestate before mutation.
- Dated function-name collision checks were empty: `lookup_funcs` returned `Not found` and `entity_query(kind=names)` returned zero rows for both `RankingCategoryRecord_GetUserEntryAt` and `RankingUserListPane_OnPaint`. Re-run both checks against `<gate2b-database>` immediately before mutation.
- Dated type collision checks found `RankingUserEntry` absent, `RankingUserListPane` absent, and `RankingCategoryRecord` present at ordinal 962 with the exact model below. Re-run and require the same semantic prestate against `<gate2b-database>`; a different ordinal alone is not a technical mismatch if the complete UDT identity/model matches.
- The old conditional recommendations (`apply if stable`, `if needed`, `apply after safe...`) are superseded by the literal ID04 no-change and ID05 apply decisions below. They remain historical context only, not executable current instructions.

### ID01 deterministic apply - `RankingUserEntry`

- Prestate: type absent.
- Exact request against the dynamically bound database: `declare_type(database="<gate2b-database>", decls="struct RankingUserEntry { int categoryId; int rank; wchar_t name[32]; int score; };")`.
- Required immediate readback: `type_inspect` must return one UDT, size `76`/`0x4c`, exactly `categoryId` `+0x0` size 4 `int`; `rank` `+0x4` size 4 `int`; `name` `+0x8` size 64 `wchar_t[32]`; `score` `+0x48` size 4 `int`; no fifth member, overlap, tail padding, or relationship to an existing conflicting type.
- Classification: **apply** at 98% confidence.

### ID02 deterministic apply - complete `RankingCategoryRecord` UDT

The complete pre/post model is authoritative; only the three marked member types may change. Names, offsets, sizes, order, total size `688`/`0x2b0`, and the 12 unaffected members are protected.

| # | Member | Offset | Size | Exact pre type | Exact post type | Disposition |
| --- | --- | --- | --- | --- | --- | --- |
| 1 | `m_listIndex` | `0x0` | 2 | `__int16` | `__int16` | protected unchanged |
| 2 | `_idaAlignmentAfterListIndex` | `0x2` | 2 | `char[2]` | `char[2]` | protected unchanged |
| 3 | `m_categoryId` | `0x4` | 4 | `int` | `int` | protected unchanged |
| 4 | `m_stateCode` | `0x8` | 4 | `int` | `int` | protected unchanged |
| 5 | `m_startTime` | `0xc` | 36 | `tm` | `tm` | protected unchanged |
| 6 | `m_endTime` | `0x30` | 36 | `tm` | `tm` | protected unchanged |
| 7 | `m_title` | `0x54` | 512 | `wchar_t[256]` | `wchar_t[256]` | protected unchanged |
| 8 | `m_totalRankCount` | `0x254` | 4 | `int` | `int` | protected unchanged |
| 9 | `m_userEntriesBegin` | `0x258` | 4 | `void *` | `RankingUserEntry *` | permitted type delta |
| 10 | `m_userEntriesEnd` | `0x25c` | 4 | `void *` | `RankingUserEntry *` | permitted type delta |
| 11 | `m_userEntriesCapacityEnd` | `0x260` | 4 | `void *` | `RankingUserEntry *` | permitted type delta |
| 12 | `m_loadedRowsCategoryId` | `0x264` | 4 | `int` | `int` | protected unchanged |
| 13 | `m_localPlayerRank` | `0x268` | 4 | `int` | `int` | protected unchanged |
| 14 | `m_reservedLocalPlayerFooter` | `0x26c` | 64 | `unsigned __int8[64]` | `unsigned __int8[64]` | protected unchanged |
| 15 | `m_localPlayerScore` | `0x2ac` | 4 | `int` | `int` | protected unchanged |

Exact request after ID01 passes:

```text
declare_type(database="<gate2b-database>", decls="struct RankingCategoryRecord { __int16 m_listIndex; char _idaAlignmentAfterListIndex[2]; int m_categoryId; int m_stateCode; tm m_startTime; tm m_endTime; wchar_t m_title[256]; int m_totalRankCount; RankingUserEntry *m_userEntriesBegin; RankingUserEntry *m_userEntriesEnd; RankingUserEntry *m_userEntriesCapacityEnd; int m_loadedRowsCategoryId; int m_localPlayerRank; unsigned __int8 m_reservedLocalPlayerFooter[64]; int m_localPlayerScore; };")
```

Immediate `type_inspect` must exactly match all 15 rows and size 688. Any changed protected member, offset, size, order, name, or total size fails Gate2B. Classification: **apply** at 98% confidence.

### ID03 deterministic apply - target function

- Dated session9081c1f3 prestate extent/item: `sub_45BFE0`, `[0x0045bfe0,0x0045c01b)`, size `0x3b`; declaration `int __thiscall(_DWORD *this, int)`; no callees; sole external code xref to target from `0x0045f637`; regular/address-repeatable/function-regular/function-repeatable comments all empty. `<gate2b-database>` must freshly match this semantic prestate before mutation.
- Exact action: dry-run collision check, rename to `RankingCategoryRecord_GetUserEntryAt`, set `RankingUserEntry *__thiscall RankingCategoryRecord_GetUserEntryAt(RankingCategoryRecord *this, int index)`, and set the regular function comment to `Returns the indexed RankingUserEntry when index is below the signed vector count; returns NULL otherwise. No lower-bound check; the observed caller supplies indexes 0 through 9.` Leave address regular, address repeatable, and function repeatable comments empty.
- Exact dated-prestate/post calling interface: return `int` -> `RankingUserEntry *`; register receiver `_DWORD *this` -> `RankingCategoryRecord *this`; sole explicit stack argument unnamed/`a2` `_DWORD` -> `index` `int`; no added/removed argument and no calling-convention change.

| Target stack-frame item | Dated snapshot prestate | Exact expected post | Protection/delta |
| --- | --- | --- | --- |
| `__saved_registers` | offset `0x4`, size `0x4`, `_DWORD` | offset `0x4`, size `0x4`, `_DWORD` | protected unchanged |
| `__return_address` | offset `0x8`, size `0x4`, `_UNKNOWN *` | offset `0x8`, size `0x4`, `_UNKNOWN *` | protected unchanged |
| `arg_0` | offset `0xc`, size `0x4`, `_DWORD` | `index`, offset `0xc`, size `0x4`, `int` | only permitted stack-argument delta |

- Protected decompiler local: fresh prestate must reproduce the register-`esi` local as `int v2` with the same frame shape. After ID01-ID03, Hex-Rays is expected to deterministically infer it as `RankingUserEntry *` and may automatically render it as `m_userEntriesBegin`. This render-name change is an allowed decompiler consequence of exact UDT member and function typing, not an explicit local rename or local type mutation. There is no target stack local to add, delete, rename, or retype, and the transaction must issue no local operation.
- Immediate readback must prove the exact extent, name/prototype/comment set, all three frame rows, unchanged register/local/frame constraints, the automatic `RankingUserEntry *m_userEntriesBegin` render, unchanged 59 bytes/body hash, same sole caller at `0x45f637`, no callees, signed comparison, and pointer return arithmetic. Any local render other than the exact prestate `int v2` before ID01-ID03 or the deterministic automatic poststate `RankingUserEntry *m_userEntriesBegin` after ID01-ID03 fails closed.
- Classification: **apply** at 99% confidence.

### ID04 deterministic no-change - target local

- Decision: **no-change**, replacing the earlier `if stable` condition. Do not call `rename.local`, `set_type(variable=...)`, or any equivalent local rename/type action for prestate `v2` or automatic post-render `m_userEntriesBegin`.
- Reason: the local is register-only in `esi` and absent from the stable stack-frame catalog. The dated failed transaction proved that exact ID01-ID03 UDT/member/function typing deterministically changes only Hex-Rays' automatic rendering from `int v2` to inferred `RankingUserEntry *m_userEntriesBegin`. That automatic render is the required accepted poststate; it is not an explicit local mutation. Register allocation, local count, frame rows, body bytes, control/data flow, and all other protected local/frame properties must remain unchanged, and no stack item may appear.
- Dated failure/rollback evidence: in the primary-supervisor `2026-08-04T14:21:00-04:00` transaction, ID01-ID03 reached the automatic `m_userEntriesBegin` rendering without any local action. The obsolete same-name-`v2` assertion caused an immediate fail-closed stop before target comment, ID05, ID06 completion, save, or external work. PID `15224` was discarded without saving; fresh session `b007-uid0002k6-nosave-rollback-verify` restored and read back canonical prestate `int v2` plus every type/name/frame/comment/byte/xref/item precondition. A retry must accept the same deterministic automatic post-render and reject any explicit local action or any different protected-state delta.
- Any attempted `firstEntry` rename is outside this transaction and fails the protected-prestate rule.

### ID05 deterministic apply - caller function

- Dated session9081c1f3 prestate extent/item: `sub_45F3A0`, `[0x0045f3a0,0x0045f945)`, size `0x5a5`; declaration `void __thiscall(GrafPort *this)`; comments all empty; no direct code caller; vtable/data xref at `0x00610d14`; call to target remains at `0x0045f637` inside the `i=0; i<10; ++i` loop. `<gate2b-database>` must freshly match this semantic prestate before mutation.
- Exact action: declare `struct RankingUserListPane;`, dry-run collision check, rename to `RankingUserListPane_OnPaint`, set `void __thiscall RankingUserListPane_OnPaint(struct RankingUserListPane *this)`, and set regular function comment to `Paints the selected ranking category and requests up to ten RankingUserEntry rows through RankingCategoryRecord::GetUserEntryAt.` Leave address regular, address repeatable, and function repeatable comments empty.
- Permitted interface delta: register receiver only, `GrafPort *this` -> `RankingUserListPane *this`; return remains `void`; no explicit stack argument is added, removed, renamed, or retyped.

| Caller stack-frame item | Dated snapshot prestate and exact expected post | Disposition |
| --- | --- | --- |
| `var_134` | offset `0xc`, size `0x4`, `_DWORD` | protected unchanged |
| `var_130` | offset `0x10`, size `0x4`, `_DWORD` | protected unchanged |
| `point` | offset `0x14`, size `0x8`, `Point` | protected unchanged |
| `outContext` | offset `0x1c`, size `0x28`, `EPFTileContext` | protected unchanged |
| `var_FC` | offset `0x44`, size `0x14`, `Region` | protected unchanged |
| `bounds` | offset `0x58`, size `0x10`, `RectBounds` | protected unchanged |
| `var_D8` | offset `0x68`, size `0x24`, `tm` | protected unchanged |
| `result` | offset `0x8c`, size `0x24`, `tm` | protected unchanged |
| `Buffer` | offset `0xb0`, size `0x2`, `wchar_t` (array extent retained by decompiler) | protected unchanged |
| `var_10` | offset `0x130`, size `0x4`, `_DWORD` | protected unchanged |
| `var_C` | offset `0x134`, size `0x4`, `_DWORD` | protected unchanged |
| `var_4` | offset `0x13c`, size `0x4`, `_DWORD` | protected unchanged |
| `__saved_registers` | offset `0x140`, size `0x4`, `_DWORD` | protected unchanged |
| `__return_address` | offset `0x144`, size `0x4`, `_UNKNOWN *` | protected unchanged |
| `arg_4` | offset `0x14c`, size `0x4`, `_DWORD` | protected unchanged; no argument semantic is inferred from this frame artifact |

- Protected non-frame decompiler locals are `m_visibleBounds`, `SelectedRecord`, `v4`, `v5`, `v6`, `v7`, `i`, `v9`, `j`, `v11`, `v12`, `v13`, `v14`, `v15`, `v16`, `point`, `outContext`, `v19`, `bounds`, `v21`, `result`, `Buffer`, and `v24`; this transaction issues no local/stack rename or type edit for any of them.
- Immediate readback must prove the exact extent, new name/prototype/comment, all 15 frame rows unchanged, same `0x610d14` vtable/data xref, target call at `0x45f637`, ten-iteration loop, and semantically unchanged decompilation apart from the receiver and target-call types/names.
- Classification: **apply** at 96% confidence. `RankingUserListPane` is unconditionally declared as an opaque forward type; there is no `if needed` branch.

### ID06 deterministic no-change - postpad

- The fresh `2026-08-04T12:30:00-04:00` prestate supersedes the earlier item-absence assumption: `inspect_items` at every address `0x0045c01b..0x0045c01f` returns the same existing physical item, head `0x0045c01b`, end `0x0045c020`, size `5`, unnamed, untyped, `is_code:false`, `is_data:true`. The item contains exactly `cc cc cc cc cc`, all comment channels are blank, xrefs are zero, and no function begins in the range. `<gate2b-database>` must freshly reproduce that complete prestate.
- Decision: **no-change**. Preserve the one existing five-byte data item exactly. Do not create, delete, resize, retype, name, comment, convert to code/function, or patch it. Read back the single shared item identity, bytes, flags, blank comments, zero xrefs, and function absence before save and after fresh reopen.

### Exact ordered Gate2B transaction

1. Fresh-read `idb_list`, `server_health`, canonical physical path/size/SHA256, `lookup_funcs`, `analyze_function`, `stack_frame`, `get_comments`, `xref_query`, `get_bytes`, `type_inspect`, and `entity_query`; bind `<gate2b-database>` to the currently returned canonical-IDB database and record that bounded PID/session identity. Require every semantic prestate above to match. Abort before mutation on any mismatch; never require reuse of a historical PID/session.
2. Run `rename(database="<gate2b-database>", batch={func:[{addr:"0x0045bfe0",name:"RankingCategoryRecord_GetUserEntryAt"},{addr:"0x0045f3a0",name:"RankingUserListPane_OnPaint"}],stop_on_error:true,dry_run:true,allow_overwrite:false})`; require both dry-run rows succeed and no collision.
3. Apply ID01 with the exact `declare_type` request and immediately `type_inspect` it.
4. Apply ID02 with the exact complete-UDT `declare_type` request and immediately `type_inspect` all 15 members and size.
5. Apply ID03 in order against `<gate2b-database>`: `rename` target with `stop_on_error:true,dry_run:false,allow_overwrite:false`; `set_type(database="<gate2b-database>", edits={addr:"0x0045bfe0",kind:"function",signature:"RankingUserEntry *__thiscall RankingCategoryRecord_GetUserEntryAt(RankingCategoryRecord *this, int index)"})`; `set_function_comments(database="<gate2b-database>", items={addr:"0x0045bfe0",comment:"Returns the indexed RankingUserEntry when index is below the signed vector count; returns NULL otherwise. No lower-bound check; the observed caller supplies indexes 0 through 9."})`. Issue no local rename/type action. Immediately read back every ID03 requirement, accepting the deterministic automatic post-type render `RankingUserEntry *m_userEntriesBegin` for the unchanged register-`esi` local while requiring every protected register/local/frame property to match.
6. Perform ID04 as a literal no-op: issue no mutation request; prove that no local rename/type action occurred, read back automatic `RankingUserEntry *m_userEntriesBegin` in `esi`, and prove the unchanged local population and target frame. The pre-typing name `v2` is required only in fresh prestate and rollback readback, not after ID01-ID03.
7. Apply ID05 in order against `<gate2b-database>`: `declare_type(database="<gate2b-database>", decls="struct RankingUserListPane;")`; `rename` caller with `stop_on_error:true,dry_run:false,allow_overwrite:false`; `set_type(database="<gate2b-database>", edits={addr:"0x0045f3a0",kind:"function",signature:"void __thiscall RankingUserListPane_OnPaint(struct RankingUserListPane *this)"})`; `set_function_comments(database="<gate2b-database>", items={addr:"0x0045f3a0",comment:"Paints the selected ranking category and requests up to ten RankingUserEntry rows through RankingCategoryRecord::GetUserEntryAt."})`. Immediately read back every ID05 requirement.
8. Read back ID06 at each address `0x0045c01b..0x0045c01f` and re-run collision/range/xref/item checks. Require every address to resolve to the same item head/end/size with unchanged unnamed/untyped/non-code/data flags, five CC bytes, blank comments, zero xrefs, and no function; require no unlisted name, type, frame, comment, byte, extent, xref, item, or decompiler-semantic delta anywhere in ID01-ID06 scope. The only permitted local-render delta is the enumerated automatic `int v2` -> `RankingUserEntry *m_userEntriesBegin` consequence of ID01-ID03, with no local action issued.
9. On **any** mismatch through step 8: do not call `idb_save`; stop all further mutation; the primary supervisor must discard the unsaved selected-worker state through the supervisor-only controlled worker teardown, then reopen the unchanged canonical disk IDB and prove path, size, SHA256, a real PID/session transition, and complete prestates. The MCP exposes no `idb_close`, so `idb_open` while the selected worker remains alive is not rollback or fresh-reopen proof. If discard/reopen cannot be proven, Gate2B fails closed.
10. Only after every immediate readback passes, call exactly one save: `idb_save(database="<gate2b-database>")`. No earlier or second save is permitted in this transaction.
11. For persistence proof, the primary supervisor performs a controlled teardown of the bounded Gate2B worker after the save, confirms that exact PID/session is gone, then calls `idb_open(input_path="E:\\NTK\\Resources\\NexusTK\\NexusTK.exe.i64", mode="prefer_headless", run_auto_analysis=false, build_caches=true, init_hexrays=true, idle_ttl_sec=3600, preferred_session_id="b007-uid0002k6-persist-reopen")`. Fresh `idb_list`/`server_health` must return a different PID/session bound to the canonical path; no specific replacement identity is presumed or retained as permanently current.
12. Against the newly returned database ID, repeat every ID01-ID06 type/name/prototype/comment/frame/extent/xref/byte/item/decompiler readback, including the accepted automatic `RankingUserEntry *m_userEntriesBegin` render with no local mutation and the one unchanged five-byte data item at all five covered addresses, and verify the saved file still has canonical path/size plus a recorded post-save SHA256. No save follows this persistence readback. At every later current-state or post-move audit, dynamically rerun `idb_list`/`server_health` and reread canonical disk path/size/SHA rather than relying on this reopen identity.

Negative constraints remain binding: do not widen the target; do not create, delete, resize, retype, name, comment, convert, or patch the existing postpad data item; do not rename the three physical UDT members to source-level `m_userEntries`, add const return/receiver semantics, add a lower-bound check, overwrite collisions, issue any explicit local rename/type action, otherwise mutate protected frame/local state, or save after a failed readback. Hex-Rays' enumerated automatic `m_userEntriesBegin` rendering after ID01-ID03 is accepted precisely because it requires no local mutation. B007 performed no IDA mutation or save.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes; the accepted result replaced the historical raw-field draft during the completed callback.
- Current target CPP block disposition: the complete UID0002K6 formal CPP payload is:

```cpp
RankingUserEntry *RankingCategoryRecord::GetUserEntryAt(int index)
{
    int userEntryCount = static_cast<int>(m_userEntries.size());

    if (userEntryCount <= index)
        return NULL;

    return &m_userEntries[index];
}
```

- Current target H block disposition: the UID0002K6 formal H payload remains blank because UID0000BL owns the declaration.
- Support H callback history: inside UID0000BL's formal class block, the callback replaced the historical declaration:

```cpp
RankingUserEntry* GetUserEntryAt(int index) const;
```

with:

```cpp
RankingUserEntry* GetUserEntryAt(int index);
```

- Exact behavior preservation: casting `size()` to `int` produces the signed row-count comparison. Testing only `userEntryCount <= index` preserves the lack of a negative-index guard. `&m_userEntries[index]` preserves element-size scaling and mutable pointer return.
- Plausible original source shape: a short class accessor over a standard vector is natural mid-2000s C++; it contains no raw offsets, magic stride, decompiler names, or compiler vector fields.
- Names/style: `m_userEntries`, `RankingUserEntry`, `userEntryCount`, `index`, and `NULL` match current project conventions and the accepted analogous UID000204 vector accessor.
- Third-party import directive: not applicable; this is project-owned method code.
- Rejected source: the historical raw pointer-field draft, a const method with `const_cast`, unsigned-only `size()` comparison, `at()`, exceptions, or an added lower-bound guard.

## Final Recommendation

- B007 callback completed the UID0002K6 rename to corrected half-open endpoint `0x0045c01b` while preserving UID identity.
- Target metadata is now `94/95` with owner/emitter/reconstructable route preserved.
- Formal CPP now carries the exact vector-based non-const body above; target H remains blank as accepted.
- UID0000BL's formal H declaration and target/class/layout/aggregate/caller/file support documentation now carry the signed upper-bound-only contract and source-shape evidence.
- C27-C31 now also give the target, aggregate, layout, class, and file pages one consistent physical postpad model: a single existing unnamed, untyped, non-code five-byte data item containing five CC bytes, with blank comments, zero xrefs, and no source emission. The earlier item-absence statement survives only as dated corrected history on the target.
- Close ID01-ID06 at supervisor Gate 2B using their literal apply/no-change dispositions and prove every protected/readback condition only after fresh `idb_list`/`server_health` plus canonical disk path/size/SHA/last-write binding. ID03/ID04 must issue no local rename/type action while accepting Hex-Rays' deterministic automatic `RankingUserEntry *m_userEntriesBegin` rendering for the unchanged register-`esi` local after exact UDT/field/function typing; every other register/local/frame property remains protected. ID06 must preserve and reprove the one existing unnamed/untyped/non-code five-byte data item, its five CC bytes, blank comments, and zero xrefs. The repair-time disk baseline is SHA256 `CE0222E87E1A569A73EB43DD72BF53412B103DD9281A535EEC2BCC01DE0932FA`, `143196420` bytes, last written `2026-08-04T14:52:17-04:00`, but it must be reread before mutation; treat `b002-uid0004hs-persist-reopen`/PID20412, `b005-uid0002ka-persist-verify`/PID15224, and any later selected session as bounded evidence, not permanent authority. The dated `2026-08-04T14:21:00-04:00` failed attempt was discarded without save and fresh-session rollback was verified; the later B002 save was unrelated and the current read-only recheck reproduced every prestate.
- Stable supervisor ordering policy: matching exact-artifact Gate1/Gate2 evidence and required IDA/manual/generated validation precede any lifecycle execution; when C20's replacement is still applicable, its manual row replacement and validation occur before lifecycle execution. Actual completion/execution status is authoritative only from external audit and validator-owned lifecycle metadata.
- Coherent command21052 reproduces UID0002K6's corrected source and B005's separate UID0002KA reset source exactly once in current `RankingDialog.cpp/.h`; memory/class/file/type/global aggregates retain command21052 authority. Repair-time tracker command21055/SHA256 `BBFB31CCB98E6EE4BD37E6D6194EBFBCC1A8AC135D4A11EA07278529A0242E86` records UID0002K6 as `94/95`, reconstructable true, with counts `0/0/0`; executed sibling UID0002KA is `94/95`, reconstructable true, with counts `1/0/1`, direct agent `B005`, execution timestamp `2026-08-04T14:23:55`, and archive `executed-b-agent-research/B005/0002KA-RankingCategoryRecordResetUserEntries-source-quality.md`. Command21036/`CE703C...135B`, command21048/`42EFF3...1B3D`, and command21052/`9D921C...3392C` are dated prior tracker evidence. Mixed command21031-era and command21007/21008 identities are dated predecessors. C23 records stable coherent-refresh policy without asserting its current application status.
- No source-bearing item remains no-owner/non-emitting within this target. The postpad's existing physical data item belongs to aggregate padding evidence, requires no source owner/emitter, and must remain non-emitting alignment.
- Sibling UID0002KA remains outside this target and must not be silently folded into this report. B005's separately accepted callback has now completed its child-specific ordinary/source correction; this report only preserves that compatible current shared state under protected boundary C26.

## Recommended Target Doc Changes

- Rename path to `by-memory/0x0045bfe0-0x0045c01b.RankingCategoryRecordGetUserEntryAt.md` and title to `# 0x0045bfe0-0x0045c01b RankingCategoryRecordGetUserEntryAt`.
- Change metadata to `COMPLETION:94`, `CONFIDENCE:95`; preserve owner UID0000BL, reconstructable true, emitter UID0000BL.
- Replace formal CPP exactly as specified; keep formal H blank.
- Replace Item Summary with: `Exact signed upper-bound lookup over the RankingCategoryRecord user-entry vector, preserving the binary's no-lower-bound behavior, nullable return, 0x4c row stride, sole ten-row paint caller, corrected endpoint, and source-ready std::vector form.`
- Expand Status/Behavior with the non-const source decision, signed comparison, negative-index result, sole caller contract, exact source route, historical generated mismatch, current validator-owned correction, and the corrected one-item/no-source postpad model.
- Expand IDA MCP Evidence with the dated session/database snapshots, 59-byte extent/hash, raw offset, disassembly, comments, xrefs/callees, type state, pointer searches, boundary padding, fresh five-address `inspect_items` result, and the requirement for dynamic canonical-IDB authority reread at every later current-state/Gate2B/post-move check.
- Add source-shape reasoning and rejected alternatives without deleting the earlier evidence that established the vector/row model.
- Add a change entry recording the old `86/91`, stale `0x0045c01a` endpoint, raw pointer-field draft, and const declaration as corrected historical state.
- Callback outcome: all target recommendations above are physically present under C01-C07 and C27; C27 is validated by command21012, and no target H declaration was invented.

## Recommended Support Doc Changes

- `by-class/RankingCategoryRecord.md` [UID0000BL]: preserve the accepted non-const declaration, corrected method link/range, upper-bound-only behavior, `0..9` caller, and compiler-only physical vector fields; add the corrected existing unnamed/untyped/non-code five-byte data-item postpad model under C30. Keep `93/95`, owner/emitter, and all unrelated class content.
- `by-type/by-struct/RankingCategoryRecordLayout.md` [UID0001VN]: preserve the target's signed count semantics, corrected endpoint, and non-const mutable accessor source decision; add the exact existing five-byte data-item postpad model under C29 without treating it as a source member or emitted child. Keep `92/95` and blank formal blocks.
- `by-memory/0x0045bf60-0x0045c257.RankingCategoryRecord.md` [UID0000Y9]: preserve the corrected UID0002K6 child link/range and exact signed/no-lower-bound contract; under C28 clarify that `[0x0045c01b,0x0045c020)` is one existing unnamed/untyped/non-code five-byte data item containing five CC bytes with blank comments and zero xrefs, still aggregate padding rather than a child. Keep `92/94`, `RECONSTRUCTABLE:FALSE`, blank emitter, `Nested:16`, and blank formal blocks.
- `by-class/RankingUserListPane.md` [UID0000BQ]: link UID0002K6 at the corrected path and state that the sole paint caller passes only indexes `0..9`, null-checks, and reads row `+4/+8/+0x48`. Keep its metadata unchanged.
- `by-file/RankingDialog.md` [UID0000MZ]: preserve the child-specific source route, corrected endpoint, non-const vector method, generated CPP/H mismatch resolution, and unchanged `RankingDialog.cpp/.h` placement; under C31 add the exact existing five-byte data-item/no-source postpad model. Keep `88/91` and existing routing.
- Generated files: never edit directly. Stable supervisor policy is to refresh `RankingDialog.cpp/.h`, memory/class/file/type/global coverage, and the research tracker through the approved validator flow after the required external IDA/manual verification and before any lifecycle execution; actual application status remains external.
- Sibling UID0002KA: B005's separate accepted callback now supplies source-facing `m_userEntries.clear(); m_localPlayerRank = -1;` code and shared support evidence. Preserve those additions as separate-child work and do not alter, claim, or duplicate them under UID0002K6.
- Callback outcome: the five original support destinations remain updated, the extra UID0003YT direct link remains normalized under C01, and C28-C31 add the corrected postpad item model to UID0000Y9, UID0001VN, UID0000BL, and UID0000MZ. Commands21013-21016 validate those four repairs; all support metadata/routing remained as accepted.

## Score And Metadata Recommendation

- Historical pre-callback target: `86/91`, owner/emitter UID0000BL, reconstructable true.
- Current post-callback target: `94/95`, owner/emitter UID0000BL, reconstructable true.
- Reason higher: exact bytes/hash from the dated canonical-IDB evidence snapshot, corrected range/padding, fresh exact physical-item model for the postpad, one live caller, no callees, exact signed contract, closed negative-index behavior, exact row and record layout, source-facing vector reconstruction, coherent CPP/H plan, complete support destinations, manual coverage text, and complete dynamically rebound IDA pre-state/actions. Session rotation alone does not reopen these technical conclusions.
- Reason not lower: no material behavior, ownership, placement, range, type-layout, caller, return-contract, or source-form blocker remains.
- Reason not higher: original symbols do not prove retail method/member/local spellings, and only one release caller is observed. The selected names are high-probability source reconstruction, not recovered source text.
- Support metadata: keep UID0000BL `93/95`, UID0001VN `92/95`, UID0000Y9 `92/94`, UID0000MZ `88/91`, and UID0000BQ `87/90`. Their broader unrelated uncertainty is not erased by this child audit.
- Score-improvement attempt summary:
  - Endpoint blocker resolved by modeled extent, raw bytes, and padding readback.
  - Negative-index blocker resolved by signed branch semantics and caller loop.
  - Source-field blocker resolved through vector support and current class H.
  - Constness blocker resolved by mutable return/API analysis and rejected `const_cast` alternative.
  - Naming/type blocker resolved with best source names plus exact IDA type/prototype handoff.
  - Generated mismatch converted into exact target/support edits and coherent refresh plan.

## Open Questions With Attempted Resolution

- Was the original method declared `const`? Binary ABI cannot prove it. A const method over `std::vector` cannot naturally return a mutable pointer. The non-const declaration is the highest-probability human source and avoids an unevidenced `const_cast`; this question is resolved by inference for implementation.
- Did the original developer use `GetUserEntryAt`, `GetUser`, or another spelling? No symbol survives. Existing project naming, sibling accessors, role, and documentation support `GetUserEntryAt`; this is the selected descriptive source name and does not block C++.
- Did the source use `static_cast<int>(size())` or `end()-begin()`? Both can yield a signed count. The current project uses `static_cast<int>(vector.size())` in analogous accessors, and it removes compiler-layout exposure, so it is selected. Runtime behavior is preserved.
- What happens for a negative index? Resolved exactly: the signed upper-bound check succeeds for ordinary nonnegative counts and return arithmetic forms a pointer before begin. The sole caller never supplies a negative value.
- Is `score` the retail field name? Not symbol-proven, but parser/UI semantics make it the strongest source-facing name. The full row layout is exact and safe.
- Are any material questions unresolved? No. Missing original symbols cap lexical confidence but do not justify deferral, unchanged score, raw names, or blank source.
- Does the five-byte postpad lack an IDA item? No. Fresh `inspect_items` disproved that earlier assumption: one unnamed, untyped, non-code data item spans the full five CC bytes. This changes the physical IDA/documentation model and requires C27-C31, but it does not change the method endpoint, source ownership, emitted C++, or score.
- Does Hex-Rays' post-ID03 `m_userEntriesBegin` local rendering prove or require a local rename? No. The dated `2026-08-04T14:21:00-04:00` failed/no-save transaction issued no local rename or local type request; exact ID01-ID03 typing deterministically produced that rendering. The corrected transaction accepts it as an automatic decompiler consequence while protecting `esi`, local/frame population, body bytes, and control/data flow and continuing to forbid every explicit local action.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Manual coverage identities literally reread for this report-repair snapshot are: by-memory `83F9DB69CE0FA41B94B5B3EE0BFC3C1FFF2B399B869BD95B869A80F9099532CA`, 2168115 bytes, 4874 lines; by-class `92BDFAC672CF9A7CD22BFE83507875F32662E208BEAD4775E39663309F353A1A`, 276381 bytes, 626 lines; by-file `435FA5F4A1EE2EBD92E101B75412F814C764B271A17FDF087A0FE81F4DEDBC4D`, 167025 bytes, 319 lines; by-type/by-struct `4B6995A919504E744922F1C99BE53D7A2330B53BCF3B6B67DCD65E184107ABF1`, 58910 bytes, 137 lines. Immediate predecessor hashes by-memory `B1B55ECD1AC53C0EF308F92648A99674BF82610C8761196E4B752559F30460CB`, by-class `03BA4A726AA4A1501AF30122AA20A985C93EFB23F8F61247372FC159D012F3F5`, and by-file `D10C5582DCF7D528AA1176EA95E0589FA826155C0FC091A9F709CD72FDD65AC9` are dated history; still earlier `101F84837C3B627902B863E6936D4E24F224559A4193E5DF8004B97E35A8C051`, `6689DB2B4B15AF0390F4EACE96F5F0C6E655300D890BF138E36327406BCBD1F7`, `1AE9186F9024FBE5BEE9D018A0D1026641084D95A6AEA0605DFEFEA1CD548888`, and by-type/by-struct `D7432B6FF4AB69314C25D67E5D6DC81C88F0F6637614CEC84728C3F5607E4C5F` remain dated history as well.
- Commands `000000020960`, `000000020961`, and `000000020962` remain dated manual baseline history. Command20969's validator-owned rename normalization changed only the UID0002K6 by-memory row link target. B007 made no direct manual coverage edit, and C20/C21 remain primary-supervisor rows.
- At the repair snapshot, `by-memory/-coverage-report.md` placed UID0000Y9 at line 412, UID0002K6 at line 419, and separately owned UID0002KA at line 424. B005's UID0000Y9 row physically included exact reset clear-without-free/local-rank semantics, and UID0002KA was physically present at `94%`, `very-strong`, with its exact 23-byte/source-route summary. UID0002K6's snapshot row used the corrected filename but retained range text ending `0x0045c01a`, completion `82%`, confidence `strong`, and a generic summary. C20 supplies the exact conditional replacement policy; external manual coverage truth must be reread before action.
- Current `by-class/-coverage-report.md` places UID0000BL at line 442 and UID0000BQ at line 447. UID0000BL's `93%` row physically includes B005's exact `ResetUserEntries` clear-without-free and `m_localPlayerRank=-1` semantics while preserving UID0002K6's non-const vector/class route. UID0000BQ remains `87%` with no row change required.
- Current `by-file/-coverage-report.md` places UID0000MZ at line 224, `88%`, and physically includes B005's reset-before-page-request/local-rank semantics alongside the existing RankingDialog/vector/source route.
- Current `by-type/by-struct/-coverage-report.md` places UID0001VN at line 94, `92%`, and physically includes B005's clear-without-free/rank-sentinel evidence alongside the exact 688-byte/vector/user-row layout and UID0002K6 evidence.
- B002's later manual additions are compatible and disjoint: by-memory UID0001E4 and UID0004HS are Palette rows, by-class UID00003Z is the DLPalette row, and by-file UID0000MA is the Palette row. None changes the Ranking family rows above.
- C21 is a stable supervisor-owned no-clobber recommendation. Its unchecked box records only that B007 did not perform or claim manual edits; it does not state current external completion. At action time the supervisor dynamically confirms the B005 rows, UID0000BQ no-change disposition, B002's disjoint Palette rows, and C20's UID0002K6-only scope.
- Supervisor replacement in `by-memory/-coverage-report.md`, replacing the entire current UID0002K6 row in place:

```markdown
        - [UID:0002K6][0x0045bfe0-0x0045c01b.RankingCategoryRecordGetUserEntryAt](by-memory/0x0045bfe0-0x0045c01b.RankingCategoryRecordGetUserEntryAt.md) 0x0045bfe0-0x0045c01b | method | RankingCategoryRecordGetUserEntryAt : reconstructable : 94% : very-strong : Exact modeled 59-byte RankingCategoryRecord user-row accessor with one RankingUserListPane::OnPaint caller, no callees, signed vector-count comparison over +0x258/+0x25c, 0x4c RankingUserEntry stride, deliberate no-lower-bound behavior, source-ready std::vector C++, corrected half-open endpoint, and complete IDA handoff.
```

- This report adds no competing class/file/type replacement text: B005's accepted sibling payloads are already physically present, while C21 retains only the supervisor's current-row/no-clobber verification boundary.
- Do not manually edit `auto-generated/-ag-research-tracker.md` or any `auto-generated/-ag-*` file. The validator owns their refresh.
- B007 must not apply the manual row because coverage reports are supervisor-owned collision surfaces.

## Follow-Up Actions

- Supervisor audit policy: every callback, Gate2 action, lifecycle execution, and post-move review relies on a matching exact-artifact audit and external verification record under current standards. Gate2A claim-by-claim verification uses C01-C13, C22, C25-C31, target SHA256 `BB0D9E6B...99B0`, current shared ordinary identities, historical B007 validators20969-20976/21012-21016, B005's compatible additions, B002's disjoint Palette additions, coherent command21052 generated evidence, current manual rows, and dynamically reread tracker truth. Commands21007/21008, mixed command21031-era identities, command21036, command21048, command21052 tracker, and command21055 tracker are dated snapshots; this report does not assert current gate status.
- Historical B007 callback facts are fixed: C01-C13, C22, C25, and C26 were completed under the earlier callback, and C27-C31 were completed under their dated callback. Any further ordinary-document action requires an externally recorded exact defect and authorization; the report does not infer such an action from its current path.
- Supervisor Gate2B policy: dynamically bind a healthy session to the freshly reread canonical IDB path/size/SHA/last-write, using SHA256 `CE0222E87E1A569A73EB43DD72BF53412B103DD9281A535EEC2BCC01DE0932FA`, `143196420` bytes, and `2026-08-04T14:52:17-04:00` only as a dated repair baseline; treat `b002-uid0004hs-persist-reopen`/PID20412, `b005-uid0002ka-persist-verify`/PID15224, and rollback-verification session identities as bounded history. The accepted package applies ID01-ID03 and ID05, performs literal no-change ID04 and ID06 checks, accepts only the enumerated automatic `m_userEntriesBegin` local rendering with no local rename/type action, and records exact transaction/readback/persistence results. Actual transaction status is external.
- Supervisor manual/generated/lifecycle policy: dynamically reread manual hashes/rows, apply C20 only when its UID0002K6 snapshot difference still exists, enforce C21's B005/UID0000BQ/B002 no-clobber rules, validate any manual change, and produce one coherent generated refresh newer than command21052 under the required external prerequisites. Lifecycle execution and post-move review are supervisor-only and rely exclusively on matching external Gate1/Gate2/audit and validator-owned metadata; tracker and canonical IDB/session authority are dynamically reread for each action.
- Sibling UID0002KA is already separately researched and updated by B005. Preserve its current ordinary/generated contributions as external compatible state; do not reopen, edit, claim, or execute that sibling through B007/C26.
- A-agent actions: none.
- B007 role policy: no additional UID0002K6 research or ordinary edit is inferred from this report body. Only an exact supervisor callback identifying a concrete same-report or ordinary-document defect authorizes further B007 work.

## Confidence

- Recommendation confidence: `95/100`.
- Score confidence: `95/100` for `94/95`.
- Range/byte/branch/caller confidence: `100/100`.
- Owner/emitter/source-placement confidence: `98/100`.
- Source lexical/name confidence: `90/100`; high-probability inference, not symbol proof.
- Remaining uncertainty is non-material to runtime reconstruction and does not justify raw IDA names or deferred source.

## Validator Results

- Gate1 report-only research ran no validator. The accepted callback then ran scoped file validators serially from `source-3/project-documentation`:
  - command `000000020969`, `2026-08-04T01:06:14-04:00`, renamed UID0002K6 target, exit `0`, `ok: 1`, generated refresh deferred;
  - command `000000020970`, `2026-08-04T01:07:04-04:00`, UID0000BL class, exit `0`, `ok: 1`, generated refresh deferred;
  - command `000000020971`, `2026-08-04T01:07:39-04:00`, UID0001VN layout, exit `0`, `ok: 1`, generated refresh deferred;
  - command `000000020972`, `2026-08-04T01:08:35-04:00`, UID0000Y9 aggregate, exit `0`, `ok: 1`, generated refresh deferred;
  - command `000000020973`, `2026-08-04T01:09:21-04:00`, UID0000BQ caller class, exit `0`, `ok: 1`, generated refresh deferred;
  - command `000000020974`, `2026-08-04T01:10:44-04:00`, UID0000MZ source file, exit `0`, `ok: 1`, generated refresh deferred;
  - command `000000020975`, `2026-08-04T01:11:14-04:00`, UID0003YT direct-link support, exit `0`, `ok: 1`, generated refresh deferred;
  - command `000000020976`, `2026-08-04T01:14:47-04:00`, UID0000MZ current-generated-state reconciliation, exit `0`, `ok: 1`, generated refresh deferred.
- Command20969 performed validator-owned path-reference normalization, including the manual by-memory coverage link and aggregate direct links; B007 did not directly edit manual coverage or generated/tracker files. Commands20969-20976 also updated projected completion stats and deferred validator-owned generation.
- Historical B007 generated evidence before C27-C31 was command21007, and validators21012-21016 deferred generation. B005's separately accepted UID0002KA callback advanced shared ordinary/generated/manual/IDA state and culminated in command21036; B002's unrelated Palette/UID0004HS work advanced coherent generated authority to command21052 without any B007 external edit. Command21036, command21048, and command21052 tracker identities remain dated history. Repair-time command21055 tracker `BBFB31CC...42E86` records UID0002K6 as `94/95`, reconstructable true, with counts `0/0/0`, while executed sibling UID0002KA is `94/95`, reconstructable true, with counts `1/0/1`, direct agent `B005`, execution timestamp `2026-08-04T14:23:55`, and archive `executed-b-agent-research/B005/0002KA-RankingCategoryRecordResetUserEntries-source-quality.md`. The repair snapshot found B005's Ranking rows and B002's disjoint Palette rows physically present; saved-IDB authority is recorded separately. C23 is stable supervisor refresh policy, and its current external application status is not asserted.
- Fresh Gate2B prestate audit `2026-08-04T12:30:00-04:00` ran no validator and stopped before IDA dry-run/mutation/save. After exact SHA `1EBF96FFB9F159B38D48D8881E57DBAA86AD9406B3894C678C857AEA2A6FE40D` passed Gate1 `23/23`, the C27-C31 callback ran these scoped file validators serially from `source-3/project-documentation`:
  - command `000000021012`, `2026-08-04T12:39:26-04:00`, C27 UID0002K6 target, exit `0`, `ok: 1`, projected stats updated, generated refresh deferred;
  - command `000000021013`, `2026-08-04T12:40:49-04:00`, C28 UID0000Y9 aggregate, exit `0`, `ok: 1`, projected stats updated, generated refresh deferred; four pre-existing missing UID0003X1 references remained;
  - command `000000021014`, `2026-08-04T12:41:39-04:00`, C29 UID0001VN layout, exit `0`, `ok: 1`, projected stats updated, generated refresh deferred; pre-existing missing UID0003YV/UID0003WT references remained and UID0003YT was added to the validator reference index;
  - command `000000021015`, `2026-08-04T12:42:18-04:00`, C30 UID0000BL class, exit `0`, `ok: 1`, projected stats updated, generated refresh deferred; six pre-existing UID0003X1/UID0003X3/UID0003YV reference warnings remained and UID0003YT was added to the validator reference index;
  - command `000000021016`, `2026-08-04T12:42:56-04:00`, C31 UID0000MZ file, exit `0`, `ok: 1`, projected stats updated, generated refresh deferred.
- Target-specific validator errors: none. The unrelated existing missing-reference warnings above were recorded rather than used to excuse any C27-C31 callback claim. No manual coverage, generated, tracker, IDA, audit, or lifecycle file was edited directly.
- Dated primary-supervisor Gate2B transaction `2026-08-04T14:21:00-04:00` ran no validator. It passed fresh prestate, backup, rename dry-runs, ID01, ID02, and the target rename/type portion of ID03, then failed the obsolete ID04 same-name-`v2` postcondition when Hex-Rays automatically rendered `m_userEntriesBegin` without any local action. The supervisor stopped before target comment/ID05/save/external work, discarded PID `15224` without saving, and proved complete canonical rollback in fresh session `b007-uid0002k6-nosave-rollback-verify`. Result: `FAILED at ID04; NO SAVE; ROLLBACK VERIFIED`. Checklist C14-C21/C23 are clear solely as B007 no-credit provenance, while checked C24 records lifecycle policy only; no current external action status is inferred from those boxes.

## Changed Files

- Ordinary callback destinations after validation:

| Claim(s) | Current ordinary destination | SHA256 | Bytes | Lines |
| --- | --- | --- | ---: | ---: |
| C01-C07/C22/C25/C27 | `by-memory/0x0045bfe0-0x0045c01b.RankingCategoryRecordGetUserEntryAt.md` | `BB0D9E6BCFC4EEB1E7F4B4BBB8237AC0D5CCC1523A760C40971B914B770399B0` | 9396 | 93 |
| C08-C09/C22/C25/C30 | `by-class/RankingCategoryRecord.md` | `5FCDFFB0684E48614D48B2295FAD6D4449CD768D95E4B44F0E1D46F3D7C04B98` | 39579 | 260 |
| C10/C22/C29 | `by-type/by-struct/RankingCategoryRecordLayout.md` | `6DB375B2B7FB73D4C4FF8BC686ED6034DC42A18E4172E41900DF5B833C5FD7FE` | 28273 | 221 |
| C11/C22/C28 | `by-memory/0x0045bf60-0x0045c257.RankingCategoryRecord.md` | `800AEFFA0752D261DDEA7BD0B5E07F377842037A16D433B1A2A04D90AD883249` | 36801 | 223 |
| C12/C22 | `by-class/RankingUserListPane.md` | `A27A5FC20168FEC30616EF34E4575D6764D48B443160C49C8ADDCF78D7FCC896` | 18436 | 149 |
| C13/C22/C31 | `by-file/RankingDialog.md` | `40F9B2AFB14E3B8902E3DEE8CF29775B5D0276D86D53B288900C3A5C666696F5` | 94407 | 503 |
| C01/C22 | `by-memory/0x0045d5f0-0x0045d653.RankingUserEntryVectorDestroy.md` | `9E00B8A1F38E9EFDE00B7D1A6CAE1D480B5C2CFB9D926731C60A92E4087FC3CF` | 3748 | 54 |

- Renamed outside report: old target path removed; corrected target path above present. No ordinary by-* page retains the stale old filename.
- Protected no-edit boundary C26: B007 did not edit UID0002KA. B005's separate accepted callback legitimately advanced it to SHA256 `D93B32A91FAB0A3F0F6ACE4FA2E1F303AEA6AD661892A8B6BF2E1DD5B0321775`, 9803 bytes, 126 lines, with formal `void ResetUserEntries()` CPP and blank child H. That external change does not transfer sibling coverage into this report.
- Report artifact maintained additively at `tools/leaser/Agents/Agent-B007/research/0002K6-RankingCategoryRecordGetUserEntryAt-source-quality.md`; C27-C31 now record the five implemented ordinary-document repairs and exact scoped-validator evidence.
- IDA/MCP mutations by B007: none. The earlier `2026-08-04T12:30:00-04:00` UID0002K6 prestate check stopped before dry-run/mutation/save after proving the existing five-byte data item. The later primary-supervisor `2026-08-04T14:21:00-04:00` transaction temporarily reached ID01-ID03, failed at the obsolete ID04 render-name assertion, and was discarded without save; fresh session `b007-uid0002k6-nosave-rollback-verify` proved full canonical prestate restoration. B002's unrelated saved UID0004HS transaction advanced disk authority to SHA256 `CE0222E87E1A569A73EB43DD72BF53412B103DD9281A535EEC2BCC01DE0932FA`, `143196420` bytes, last written `2026-08-04T14:52:17-04:00`; fresh read-only session `b002-uid0004hs-persist-reopen`/PID20412 reproduced every ID01-ID06 prestate. All named sessions/PIDs are bounded evidence only, and dynamic healthy-session/disk binding remains required. Manual/generated/tracker direct edits by B007: none. Current coherent generated authority is command21052; command21036, command21048, and command21052 tracker identities are dated prior evidence. Repair-time tracker command21055/SHA256 `BBFB31CCB98E6EE4BD37E6D6194EBFBCC1A8AC135D4A11EA07278529A0242E86` records UID0002K6 as `94/95`, reconstructable true, with counts `0/0/0`; executed sibling UID0002KA is `94/95`, reconstructable true, with counts `1/0/1`, direct agent `B005`, execution timestamp `2026-08-04T14:23:55`, and archive `executed-b-agent-research/B005/0002KA-RankingCategoryRecordResetUserEntries-source-quality.md`. At that snapshot B005's Ranking rows and B002's disjoint Palette rows were physically present; older identities remain predecessor history, and current truth is dynamically reread.
- Lease-release proof: C27 target, C28 aggregate, C29 layout, C30 class, and C31 file were each leased serially only for their edit/scoped-validator batch, and every `unlease` command returned `Success` before the next destination began. No B007 ordinary destination lease remained when this report reconciliation started. The report lease is released after this reconciliation/readback.
- Report lifecycle boundary: execution/archive status is supervisor-owned and authoritative only from the report path plus validator-owned lifecycle metadata. This report does not execute, move, archive, or claim current executed state.

## Implementation Tracking Checklist

This is the one authoritative checklist and exactly mirrors the ledger above. Its stable population has 22 checked boxes: 21 callback/exclusion facts plus C24 checked solely as `policy-recorded`, with no lifecycle credit. The nine clear boxes C14-C21 and C23 record only that B007 did not perform the external supervisor-owned recommendations; they do not assert that those actions are currently pending or incomplete. Current external action and lifecycle status is authoritative only from matching supervisor audit/IDA/manual/generated records, current path, and validator-owned lifecycle metadata. No separate callback checklist exists.

| State | Claim ID | UID | Destination | Action | Actor | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| [x] | C01 | 0002K6 | `by-memory/0x0045bfe0-0x0045c01a.RankingCategoryRecordGetUserEntryAt.md` path/title and every direct link | Rename the target endpoint to half-open `0x0045c01b` while preserving UID0002K6. | B007 callback | applied |
| [x] | C02 | 0002K6 | UID0002K6 Status, IDA evidence, range, and padding sections | Add the exact 59-byte extent, raw offset `0x5b3e0`, body SHA256 `775ce790509e5e305dd258b915880e77e78219e06e4679c6c9b607e988277372`, terminal return bytes, and five-byte CC postpad proof. | B007 callback | applied |
| [x] | C03 | 0002K6 | UID0002K6 Behavior and Reconstruction sections | Document the signed upper-bound-only comparison and exact negative-index before-begin pointer behavior without adding a lower-bound guard. | B007 callback | applied |
| [x] | C04 | 0002K6 | UID0002K6 caller contract | Document the sole call at `0x0045f637`, the caller's `0..9` loop, null contract, no callees, and no alternate entry route. | B007 callback | applied |
| [x] | C05 | 0002K6 | UID0002K6 formal `RECONSTRUCTION_CPP CODE` | Replace the stale physical-pointer draft with the exact non-const `std::vector` source body in this report. | B007 callback | applied |
| [x] | C06 | 0002K6 | UID0002K6 formal `RECONSTRUCTION_H CODE` | Keep the target H payload blank because the class page owns the declaration. | B007 callback | already-present |
| [x] | C07 | 0002K6 | UID0002K6 metadata, Item Summary, and change history | Set `COMPLETION:94`, `CONFIDENCE:95`; preserve owner/emitter/reconstructable fields; add the exact summary and retain corrected stale-endpoint/raw-field/const history. | B007 callback | applied |
| [x] | C08 | 0000BL | `by-class/RankingCategoryRecord.md` formal H declaration | Replace `RankingUserEntry* GetUserEntryAt(int index) const;` with `RankingUserEntry* GetUserEntryAt(int index);`. | B007 callback | applied |
| [x] | C09 | 0000BL | `by-class/RankingCategoryRecord.md` behavior, method table/link, layout interpretation, and history | Incorporate the signed contract, mutable return, vector source shape, corrected endpoint, and rejected raw-member/const assumptions without pruning prior evidence. | B007 callback | applied |
| [x] | C10 | 0001VN | `by-type/by-struct/RankingCategoryRecordLayout.md` nested-row/accessor evidence | Add the exact `0x4c` row/accessor/caller evidence and corrected endpoint/padding while preserving metadata. | B007 callback | applied |
| [x] | C11 | 0000Y9 | `by-memory/0x0045bf60-0x0045c257.RankingCategoryRecord.md` child inventory/range analysis | Correct the UID0002K6 child link/end and add five-byte postpad evidence while preserving non-emitting `Nested:16`. | B007 callback | applied |
| [x] | C12 | 0000BQ | `by-class/RankingUserListPane.md` paint/caller evidence | Add the sole-caller `0..9` nonnegative-loop contract and corrected UID0002K6 child link. | B007 callback | applied |
| [x] | C13 | 0000MZ | `by-file/RankingDialog.md` source route and generated-state notes | Add the child-specific non-const vector-source route; preserve command20963/20975-20976/20995/21007/21008, mixed command21031-era identities, command21036, and command21048 as dated history; bind active-current generated readback to coherent command21052 CPP/H/aggregates without changing the file route. | B007 callback | applied |
| [ ] | C14 | 0002K6 | IDA type catalog `RankingUserEntry` | Gate2B recommendation policy: dynamically run `idb_list`/`server_health`, freshly bind canonical disk authority against repair snapshot `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, `143196420` bytes, SHA256 `CE0222E87E1A569A73EB43DD72BF53412B103DD9281A535EEC2BCC01DE0932FA`, last written `2026-08-04T14:52:17-04:00`, then ID01 declares and reads back the exact four-member, 76-byte `RankingUserEntry` UDT; `b002-uid0004hs-persist-reopen`/PID20412 and all earlier session/PID evidence are bounded snapshots, so select the then-healthy session at mutation time. | Primary supervisor Gate2B | supervisor-owned-recommendation |
| [ ] | C15 | 0002K6 | IDA UDT `RankingCategoryRecord` | Gate2B recommendation policy: after the same dynamic health check and fresh canonical path/size/SHA binding required by C14, ID02 redeclares the complete 15-member/688-byte model with only `+0x258/+0x25c/+0x260` changed from `void *` to `RankingUserEntry *`; protect all other members. | Primary supervisor Gate2B | supervisor-owned-recommendation |
| [ ] | C16 | 0002K6 | IDA function `0x0045bfe0` | Gate2B recommendation policy: after the same dynamic health check and fresh canonical path/size/SHA binding required by C14, ID03 collision-checks, renames, sets the exact prototype and regular function comment, and proves extent/frame/xrefs/bytes/decompilation readback; accept Hex-Rays' deterministic automatic post-type rendering of the untouched register local as `m_userEntriesBegin` while requiring no explicit local rename/type action. | Primary supervisor Gate2B | supervisor-owned-recommendation |
| [ ] | C17 | 0002K6 | IDA target register local (prestate `v2`; automatic post-render `m_userEntriesBegin`) | Gate2B recommendation policy: after the same dynamic health check and fresh canonical path/size/SHA binding required by C14, ID04 is a literal no-change decision; issue no local rename and no local type action, preserve the register/local/frame constraints, and accept `m_userEntriesBegin` only as Hex-Rays' deterministic automatic decompiler consequence of ID01-ID03, not as an explicit local mutation. | Primary supervisor Gate2B | supervisor-owned-recommendation |
| [ ] | C18 | 0000BQ | IDA caller `0x0045f3a0` and opaque `RankingUserListPane` type | Gate2B recommendation policy: after the same dynamic health check and fresh canonical path/size/SHA binding required by C14, ID05 declares the forward type, collision-checks, renames/types/comments the caller, and proves its full unchanged frame, extent, vtable xref, target call, and decompilation readback. | Primary supervisor Gate2B | supervisor-owned-recommendation |
| [ ] | C19 | 0002K6 | IDA `[0x0045c01b,0x0045c020)` | Gate2B recommendation policy: after the same dynamic health check and fresh canonical path/size/SHA binding required by C14, ID06 makes no mutation and proves one existing physical item with head `0x0045c01b`, end `0x0045c020`, size `5`, unnamed, untyped, `is_code:false`, `is_data:true`, bytes `cc cc cc cc cc`, blank comments, and zero xrefs remains unchanged; create/delete/resize/retype/name/comment/function/patch actions are forbidden. | Primary supervisor Gate2B | supervisor-owned-recommendation |
| [ ] | C20 | 0002K6 | `by-memory/-coverage-report.md` UID0002K6 row | Supervisor manual-coverage policy: under matching external exact-artifact Gate1/Gate2 records, dynamically reread by-memory manual coverage (repair snapshot SHA256 `83F9DB69CE0FA41B94B5B3EE0BFC3C1FFF2B399B869BD95B869A80F9099532CA` showed `82%` and range text ending `0x0045c01a` at line 419), replace that stale path/score/detail with the exact row in this report when still applicable, and validate the replacement before any lifecycle execution. | Primary supervisor | supervisor-owned-recommendation |
| [ ] | C21 | 0000Y9/0000BL/0000BQ/0000MZ/0001VN | Current manual by-memory/by-class/by-file/by-type rows and identities | Supervisor no-clobber policy: dynamically reread all six associated rows against repair snapshot hashes by-memory `83F9DB69CE0FA41B94B5B3EE0BFC3C1FFF2B399B869BD95B869A80F9099532CA`, by-class `92BDFAC672CF9A7CD22BFE83507875F32662E208BEAD4775E39663309F353A1A`, by-file `435FA5F4A1EE2EBD92E101B75412F814C764B271A17FDF087A0FE81F4DEDBC4D`, and by-type/by-struct `4B6995A919504E744922F1C99BE53D7A2330B53BCF3B6B67DCD65E184107ABF1`; preserve compatible B005 UID0002KA/shared UID0000Y9/0000BL/0000MZ/0001VN rows, preserve UID0000BQ when no change is supported, treat B002's UID0001E4/UID0004HS/UID00003Z/UID0000MA Palette rows as compatible/disjoint, and ensure C20 clobbers none of those rows. | Primary supervisor | supervisor-owned-recommendation |
| [x] | C22 | 0002K6/0000BL/0001VN/0000Y9/0000BQ/0000MZ | Every renamed or edited by-* destination | Preserve the dated successful scoped validators20969-20976 and their callback readbacks as applied evidence; at Gate2A dynamically reread every current ordinary destination identity and exact metadata/formal-source/content state rather than assuming the historical hashes remain current. | B007 callback | applied |
| [ ] | C23 | 0002K6 | Validator-generated CPP/H, coverage reports, and research tracker | Supervisor generated-refresh policy: after the external IDA/manual prerequisites required by current project standards, perform one coherent refresh newer than generated baseline command21052, verify UID0002K6 and separately owned UID0002KA each occur exactly once through UID0000BL/RankingDialog.cpp, and capture tracker identity only as a dated same-gate snapshot. Command21036/SHA256 `CE703CBE51083E3051C288318334B929FCD31FF80933150099B5FBE6027DF135`, command21048/SHA256 `42EFF3C38E67C15C1AFF400F8D8AE2BAD5A4169258564A4163D6450524EE1B3D`, command21052/SHA256 `9D921C8C650C3B27E692BFA8BB371A4F95C2F00BC7EAF309877F28B8F843392C`, and repair-time command21055/SHA256 `BBFB31CCB98E6EE4BD37E6D6194EBFBCC1A8AC135D4A11EA07278529A0242E86` are dated snapshots; current tracker truth is always reread dynamically. | Primary supervisor | supervisor-owned-recommendation |
| [x] | C24 | 0002K6 | Report lifecycle policy for this exact artifact | Stable supervisor lifecycle policy: execution and post-move review are supervisor-only and are permitted only when immutable external audit history records matching exact-artifact Gate1/Gate2 plus all required IDA/manual/generated work under current standards. Actual execution, movement, archive, and post-move status is authoritative solely from immutable audit history, the report's current path, and validator-owned status/history metadata; tracker and canonical IDB/session truth are reread dynamically for each action. This checked row proves policy presence only and grants no lifecycle credit. | Primary supervisor | policy-recorded |
| [x] | C25 | 0002K6/0000BL | Target/class historical assumptions and rejected alternatives | Preserve raw-field, const, defensive lower-bound, stale-endpoint, and conditional-IDA recommendations as dated corrected history with reasons; do not prune them. | B007 callback | applied |
| [x] | C26 | 0002KA | Sibling child `[0x0045c240,0x0045c256)` / `by-memory/0x0045c240-0x0045c256.RankingCategoryRecordResetUserEntries.md` | Do not edit, fold, claim, or execute sibling UID0002KA through this report. B005's separate accepted child-specific callback legitimately advanced that sibling and shared support pages; preserve those compatible additions as external state without transferring coverage or authorship to UID0002K6. | B007 callback | excluded-with-reason |
| [x] | C27 | 0002K6 | `by-memory/0x0045bfe0-0x0045c01b.RankingCategoryRecordGetUserEntryAt.md` postpad item model | Replace the current item-absence assertion in Status/IDA evidence/Range And Padding with the exact existing-item model: one unnamed, untyped, non-code five-byte data item at `[0x0045c01b,0x0045c020)`, bytes `cc cc cc cc cc`, blank comments, zero xrefs, and no source emission; preserve the earlier absence claim as dated corrected history. | B007 callback | applied |
| [x] | C28 | 0000Y9 | `by-memory/0x0045bf60-0x0045c257.RankingCategoryRecord.md` child inventory/range/evidence | Clarify that the five-byte alignment span is represented by one existing unnamed, untyped, non-code data item with five CC bytes, blank comments, and zero xrefs; it remains aggregate padding, not a child or emitter. | B007 callback | applied |
| [x] | C29 | 0001VN | `by-type/by-struct/RankingCategoryRecordLayout.md` UID0002K6 postpad evidence | Add the exact existing five-byte data-item model and preserve its distinction from source-authored record layout, child coverage, and emitted code. | B007 callback | applied |
| [x] | C30 | 0000BL | `by-class/RankingCategoryRecord.md` UID0002K6 evidence/history | Add the exact existing five-byte data-item model to the UID0002K6 endpoint/postpad evidence while preserving class ownership, method source, and no-source-alignment disposition. | B007 callback | applied |
| [x] | C31 | 0000MZ | `by-file/RankingDialog.md` UID0002K6 source-route/history | Clarify that the five-byte non-emitting alignment span is one existing unnamed, untyped, non-code data item with five CC bytes, blank comments, and zero xrefs; preserve file placement and all source routing. | B007 callback | applied |

READY_FOR_FRESH_GATE1

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B007","command_id":"000000021067","destination_path":"executed-b-agent-research/B007/0002K6-RankingCategoryRecordGetUserEntryAt-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B007/research/0002K6-RankingCategoryRecordGetUserEntryAt-source-quality.md","timestamp":"2026-08-04T16:12:04-04:00","uid":"0002K6"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
