<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B005\0002YF-SoftwareRenderCompatFillCallback-empty-emitter-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Legacy Material Archive

Source report: [0002YF-SoftwareRenderCompatFillCallback-empty-emitter-source-quality.md](0002YF-SoftwareRenderCompatFillCallback-empty-emitter-source-quality.md)

This archive is non-authoritative and must never be executed. It is not a B report and receives no Gate, coverage, score, IDA, validator, or lifecycle credit.

## Removed Block CLEANUP-20260813-0002YF-SECTION21

The following report-local transaction and request material is preserved verbatim from source artifact SHA256 `E4573F62F70A73F00ACC52246A3782EF1086EC4110F27B65CFBA88F0480C5FD9`.

<!-- BEGIN CLEANUP-20260813-0002YF-SECTION21 -->
## IDA Rename / Type / Comment Recommendations

Actionable function F1:

| Entity | Dated rollback prestate and mandatory fresh transaction-time reread | Accepted and fresh-persisted semantic/analyzed state | Evidence / confidence | Classification |
| --- | --- | --- | --- | --- |
| Function `0x004be680` | dated rollback snapshot: canonical SHA256 `92CD98...CC5A0`, size 143,196,412; name `sub_4BE680`; prototype `char __userpurge@<al>(int@<ecx>, int@<ebp>, struct RectBounds *)`; entry regular absent; entry repeatable absent; function regular absent; function repeatable absent; exactly frame rows `+0x04 var_8/_DWORD/4`, `+0x0c __return_address/_UNKNOWN */4`; all were freshly reread under audit 0409 | post-rename/profile transitional state exactly `SoftwareRenderCompatFillCallback` plus provisional `char __userpurge@<al>(const struct GrafPort *@<ecx>, int@<ebp>, struct RectBounds *)`, unchanged two-row frame/comments/metrics/xrefs/protections; then semantic `void __thiscall SoftwareRenderCompatFillCallback(GrafPort *port, const RectBounds *bounds)`; exact function-regular comment; exact immediate three-row frame, exact post-analysis four-row frame, and identical persisted four-row frame | retn4, ECX receiver, typedef, consumers, peer, decompile, twice-reproduced rename/profile inference, saved-reopen experiment, failed-before-save bounded-analysis experiment, and successful fresh persistence under audit 0409; very strong ABI/strong spelling and deterministic stage evidence | supervisor applied/fresh-persisted |

Exact function-regular comment:

```text
Surface slot-7 RGB555 rectangle-fill callback; clips the requested bounds, maps GrafPort draw colors, and performs copy, color-key, weighted-blend, or keyed-weighted-blend fills.
```

Literal supervisor mutation/readback order, to be bound to the sole session returned by immediate transaction-time `idb_list`:

```text
rename {batch:{func:{addr:"0x004be680",name:"SoftwareRenderCompatFillCallback"},dry_run:true,stop_on_error:true,allow_overwrite:false},database:"<current-session>"}
func_profile {queries:{addr:"0x004be680",include_lists:false,max_items:0,include_prototype:true},database:"<current-session>"}
rename {batch:{func:{addr:"0x004be680",name:"SoftwareRenderCompatFillCallback"},dry_run:false,stop_on_error:true,allow_overwrite:false},database:"<current-session>"}
func_profile {queries:{addr:"0x004be680",include_lists:false,max_items:0,include_prototype:true},database:"<current-session>"}
stack_frame {addrs:"0x004be680",database:"<current-session>"}
get_comments {addrs:"0x004be680",database:"<current-session>"}
set_type {edits:{addr:"0x004be680",kind:"function",signature:"void __thiscall SoftwareRenderCompatFillCallback(GrafPort *port, const RectBounds *bounds)"},database:"<current-session>"}
func_profile {queries:{addr:"0x004be680",include_lists:false,max_items:0,include_prototype:true},database:"<current-session>"}
stack_frame {addrs:"0x004be680",database:"<current-session>"}
set_function_comments {items:{addr:"0x004be680",comment:"Surface slot-7 RGB555 rectangle-fill callback; clips the requested bounds, maps GrafPort draw colors, and performs copy, color-key, weighted-blend, or keyed-weighted-blend fills."},database:"<current-session>"}
get_comments {addrs:"0x004be680",database:"<current-session>"}
analyze_function {addr:"0x004be680",include_asm:false,database:"<current-session>"}
stack_frame {addrs:"0x004be680",database:"<current-session>"}
```

- Transaction start is allowed only after a fresh sole-session health check, exact canonical disk SHA256/size readback, and byte-identical backup. The fresh transaction-time canonical prestate must exactly match raw name `sub_4BE680`, literal prototype `char __userpurge@<al>(int@<ecx>, int@<ebp>, struct RectBounds *)`, four blank entry/function comment channels, and the two-row physical frame `+0x04 var_8/_DWORD/4`, `+0x0c __return_address/_UNKNOWN */4`. The earlier `const GrafPort *` ECX rendering is not an acceptable substitute for this corrected literal prestate.
- Rename dry-run must be collision-free, pass `1/1`, and change nothing. Its readback must still show raw name `sub_4BE680`, raw prototype `char __userpurge@<al>(int@<ecx>, int@<ebp>, struct RectBounds *)`, four blank comments, the two-row frame, and unchanged metrics/xrefs/P2-P6. Actual rename must then pass `1/1` and write the exact name `SoftwareRenderCompatFillCallback`.
- The first mandatory post-rename `func_profile` is an explicit transitional analysis stage. It must read back only this permitted delta from raw prestate: exact name `SoftwareRenderCompatFillCallback` and exact provisional prototype `char __userpurge@<al>(const struct GrafPort *@<ecx>, int@<ebp>, struct RectBounds *)`. At this stage size must remain `0x6e7`, instructions 469, blocks 56, callers zero, callees seven, target xrefs exactly two, all four comments blank, frame exactly `+0x04 var_8/_DWORD/4` and `+0x0c __return_address/_UNKNOWN */4`, and P2-P6 unchanged. Any different inferred type or any other drift requires stopping/discarding the worker unsaved.
- That provisional post-rename/profile type is transient analysis/tool-stage inference only. It is not accepted source, not the desired semantic prototype, and not a persistence target. Semantic `set_type` is authorized only after the exact transitional state passes and must replace that exact known provisional rendering with `void __thiscall SoftwareRenderCompatFillCallback(GrafPort *port, const RectBounds *bounds)`.
- Semantic `set_type` must read back exactly and must not change bytes, range, xrefs, instruction/block counts, internal comments, or P2-P6 beyond the separately specified frame-stage effects.
- Required immediate post-`set_type`, pre-analysis frame poststate is exactly three rows: `+0x04 var_8/_DWORD/4`, `+0x0c __return_address/_UNKNOWN */4`, and `+0x10 bounds/const RectBounds */4`. The retry directly proved that `+0x00 var_C` is absent at this stage.
- The supervisor must then run the same bounded target `analyze_function` protection read needed for P1 before save. Required post-analysis frame poststate is exactly four rows: `+0x00 var_C/_DWORD/4`, `+0x04 var_8/_DWORD/4`, `+0x0c __return_address/_UNKNOWN */4`, and `+0x10 bounds/const RectBounds */4`. The retry directly proved this bounded analysis call is the materialization trigger.
- Required fresh-session persisted frame poststate is the identical exact four-row post-analysis inventory. The first saved experiment proves persistence retains the analysis-generated row; it does not prove or imply that save/reopen first creates it.
- The observed `var_C` row is permitted only at `+0x00`, name `var_C`, type `_DWORD`, width 4, and only after bounded analysis and after persistence. It is analysis-triggered, persistence-retained physical database metadata, not a reconstructed source local or source argument and not a reason to weaken the semantic prototype.
- No direct stack/local rename or type mutation is authorized. The supervisor must not manually create, remove, rename, or retype `var_C` or `bounds`; `bounds` must arise from the semantic function type and `var_C` must arise from the subsequent bounded analysis read. Any stage-specific inventory outside the exact three/four/four sequence above is drift.
- `set_function_comments` must affect only function-regular text. If the tool cannot target that channel exactly, stop with no save rather than substitute entry/repeatable text.

Protected entities:

| Protection | Required unchanged readback |
| --- | --- |
| P1 target body | range, 1,767-byte hash, 469 instructions, 56 blocks, complexity 36, exactly two xrefs, 18 internal comments, semantic callees, and all bytes |
| P2 boundaries | exact predecessor/successor bytes and hashes; next function remains `0x004bed80` |
| P3 slot 7 | zero bytes at `[0x0069b3fc,0x0069b400)`, semantic `g_pfnFillRect`/`SurfaceFillRectProc`, 206 xrefs, blank comments, neighbor slot bytes/items |
| P4 types | GrafPort `0xa0`, EPFTileContext `0x28`, RectBounds `0x10`, existing SurfaceFillRectProc; no UDT member mutation |
| P5 compiler dependencies | RGB555 mask/weight constants and `__isa_available` remain compiler/runtime state with no source-facing rename required here |
| P6 peer | `FillRgb565RectCallback` name/type/body/comments and all peer bytes/xrefs remain unchanged |

- Slot 7 physical one-byte item modeling is intentionally left unchanged in this pass. It is a table-wide IDA item-normalization concern; changing one slot would create inconsistent physical modeling and is not required to type or reconstruct this callback.
- B005 remains read-only. Only the primary supervisor may apply/save IDA changes after exact-artifact review and a byte-identical canonical backup.
- Before save, any prestate mismatch, collision, mutation error, deviation from the exact permitted post-rename/profile name/type/two-row-frame/comment/metric/xref state, failure of semantic `set_type` to replace that provisional rendering, deviation from the exact three-row immediate post-type frame, deviation from the exact four-row post-analysis frame, comment-channel drift, xref/range/byte/profile/type drift, or failed P1-P6 readback requires stopping the entire unsaved transaction with no save. Stop/discard that worker and freshly reopen the unmodified canonical disk; the resulting raw state is a dated rollback proof only and must still be freshly reread on any later attempt.
- Save exactly once only after F1, the exact three-row immediate frame, the exact four-row post-analysis frame, and P1-P6 all pass. Stop the saved worker, reopen the canonical IDB fresh, and require exact persisted name, semantic prototype, function-regular comment, three blank other comment channels, the identical exact four-row frame, and all P1-P6 protections.
- If fresh persistence differs in any way, stop the fresh worker, restore the byte-identical backup over the canonical IDB, verify SHA256 `92CD98A20133155CEC96C4AB6B60A00B7C5635A7C47E0A3F51BE918C13ACC5A0` and 143,196,412 bytes, reopen fresh, and require the exact rollback state: raw name `sub_4BE680`; prototype `char __userpurge@<al>(int@<ecx>, int@<ebp>, struct RectBounds *)`; four blank comment channels; two-row frame `var_8`/return only; and unchanged P1-P6. Do not save or claim credit after restore.
- The literal order and stop/rollback rules above remain the evidence-backed transaction contract. Audit 0409 records that the primary supervisor completed it end to end: all F1 stages, P1-P6, one save, and fresh persistence passed exactly; no rollback was required; C2YF-045..050 are externally complete. The canonical saved-IDB hash/size and dated audit/catalog entry, rather than any ephemeral session/PID, are the stable authority recorded by this report.
<!-- END CLEANUP-20260813-0002YF-SECTION21 -->
