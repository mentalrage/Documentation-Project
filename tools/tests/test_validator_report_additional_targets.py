from __future__ import annotations

import sys
import tempfile
import unittest
from datetime import datetime, timedelta
from pathlib import Path
from types import SimpleNamespace


TOOLS_DIR = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(TOOLS_DIR))

import validator_background as validator


class ValidatorAdditionalTargetsTests(unittest.TestCase):
    def setUp(self) -> None:
        self.temporary = tempfile.TemporaryDirectory()
        self.root = Path(self.temporary.name) / "project-documentation"
        (self.root / "tools").mkdir(parents=True)
        validator.DEFAULT_METADATA_CACHE = self.root / "tools" / "metadata-cache.json"
        validator._METADATA_CACHE = None
        validator._METADATA_CACHE_DIRTY = False
        validator._TEXT_CACHE.clear()
        validator._FILE_HASH_CACHE.clear()
        validator._RESOLVE_CACHE.clear()
        self.config = validator.load_config(self.root / "tools" / "validator.ini")

    def tearDown(self) -> None:
        self.temporary.cleanup()

    def add_target(self, uid: str, folder: str = "by-memory", reconstructable: str = "true") -> Path:
        path = self.root / folder / f"{uid}.md"
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_text(f"*** UID:{uid} | DO NOT MODIFY OR REMOVE!!! ***\n", encoding="utf-8")
        relative = path.relative_to(self.root).as_posix()
        self.config["files"][uid] = relative
        self.config["completion"][uid] = "0"
        self.config["confidence"][uid] = "0"
        self.config[validator.RECONSTRUCTABLE_SECTION][uid] = reconstructable
        return path

    def report_text(
        self,
        uid: str,
        agent: str = "B001",
        additional: tuple[str, ...] = (),
        specs: str | None = "CHATGPT | 5.6 | xHigh",
        status: str = "",
    ) -> str:
        lines = [validator.make_report_target_header(uid)]
        if additional:
            lines.append(validator.make_report_additional_uids_header(additional))
        lines.append(validator.make_report_author_header(agent))
        if specs is not None:
            lines.append(validator.make_report_author_specs_header(specs))
        if status:
            lines.append(validator.make_report_validation_status_header(status))
            lines.append(validator.make_report_revalidation_reason_header("fixture repair required"))
        lines.extend(["", "# Fixture report", "", "Report body.\n"])
        return "\n".join(lines)

    def add_registered_report(
        self,
        filename: str,
        uid: str,
        agent: str = "B001",
        additional: tuple[str, ...] = (),
    ) -> Path:
        path = self.root / "executed-b-agent-research" / agent / filename
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_text(self.report_text(uid, agent, additional), encoding="utf-8")
        record = validator.report_record_from_file(
            self.root,
            path,
            uid,
            agent,
            agent_specs="CHATGPT | 5.6 | xHigh",
            additional_uids=additional,
        )
        validator.add_report_registry_record(self.config, record)
        return path

    @staticmethod
    def command_args(**values):
        defaults = {
            "agent_id": "B001",
            "report_file": "report.md",
            "target_uid": "",
            "apply": False,
            "command_id": 7,
            "command_id_display": "000000000007",
            "command_timestamp": datetime.now().astimezone().isoformat(timespec="seconds"),
        }
        defaults.update(values)
        return SimpleNamespace(**defaults)

    def test_optional_header_is_backward_compatible_and_normalized(self) -> None:
        missing = validator.parse_report_headers(self.report_text("000001"))
        self.assertEqual((), missing.additional_target_uids)
        self.assertEqual((), missing.errors)

        parsed = validator.parse_report_headers(
            self.report_text("000001").replace(
                validator.make_report_target_header("000001"),
                "** TARGET-REPORT-UID:000001 **\n"
                "** TARGET-REPORT-ADDITIONAL-UIDS: 000003,000002 **",
            )
        )
        self.assertEqual(("000002", "000003"), parsed.additional_target_uids)
        self.assertEqual((), parsed.errors)

    def test_upsert_report_headers_keeps_markdown_h1_first(self) -> None:
        source = "\n".join(
            [
                "# Canonical report title",
                validator.make_report_target_header("000001"),
                validator.make_report_author_header("B001"),
                validator.make_report_author_specs_header("CHATGPT | 5.6 | xHigh"),
                "",
                "## Report body",
                "",
            ]
        )

        updated = validator.upsert_report_headers(
            source,
            "000001",
            "B001",
            "CHATGPT | 5.6 | xHigh",
            validation_status=validator.REPORT_VALIDATION_STATUS_NEEDS_REVALIDATION,
            revalidation_reason="fixture repair required",
        )

        self.assertEqual(
            [
                "# Canonical report title",
                validator.make_report_target_header("000001"),
                validator.make_report_author_header("B001"),
                validator.make_report_author_specs_header("CHATGPT | 5.6 | xHigh"),
                validator.make_report_validation_status_header(
                    validator.REPORT_VALIDATION_STATUS_NEEDS_REVALIDATION
                ),
                validator.make_report_revalidation_reason_header("fixture repair required"),
            ],
            updated.splitlines()[:6],
        )

    def test_upsert_report_headers_prepends_when_h1_is_absent(self) -> None:
        updated = validator.upsert_report_headers(
            "Legacy report body.\n",
            "000001",
            "B001",
            "CHATGPT | 5.6 | xHigh",
        )

        self.assertEqual(
            validator.make_report_target_header("000001"),
            updated.splitlines()[0],
        )
        self.assertEqual("Legacy report body.", updated.splitlines()[3])

    def test_malformed_headers_and_status_pairs_fail_precisely(self) -> None:
        malformed = validator.parse_report_headers(
            self.report_text("000001") + "\n**TARGET-REPORT-UID:** 000001\n"
        )
        self.assertIn("malformed TARGET-REPORT-UID header", malformed.errors)
        self.assertNotIn("duplicate TARGET-REPORT-UID header", malformed.errors)

        empty_additional = validator.parse_report_headers(
            "** TARGET-REPORT-UID:000001 **\n"
            "** TARGET-REPORT-ADDITIONAL-UIDS: **\n"
            "** AUTHOR-AGENT-ID:B001 **\n"
            "** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **\n"
        )
        self.assertTrue(
            any(
                error.startswith("malformed TARGET-REPORT-ADDITIONAL-UIDS header")
                for error in empty_additional.errors
            )
        )

        missing_reason = validator.parse_report_headers(
            self.report_text("000001")
            + "\n** REPORT-VALIDATION-STATUS: needs-revalidation **\n"
        )
        self.assertIn("revalidation reason is missing", missing_reason.errors)

    def test_registry_round_trip_and_removal_use_one_canonical_section(self) -> None:
        for uid in ("000001", "000002", "000003"):
            self.add_target(uid)
        path = self.add_registered_report("report.md", "000001", additional=("000003", "000002"))
        relative = path.relative_to(self.root).as_posix()
        self.assertEqual("000002;000003", self.config[validator.RESEARCH_REPORT_ADDITIONAL_UIDS_SECTION][relative])
        self.assertEqual(("000002", "000003"), validator.additional_uids_for_report(self.config, relative))
        reverse = validator.build_additional_report_paths_by_uid(self.config)
        self.assertEqual((relative,), reverse["000002"])
        validator.remove_report_registry_path(self.config, relative)
        self.assertNotIn(relative, self.config[validator.RESEARCH_REPORT_ADDITIONAL_UIDS_SECTION])

    def test_tracker_has_all_four_exclusive_states_and_b_only_filter(self) -> None:
        for uid in ("000001", "000002", "000003", "000004"):
            self.add_target(uid)
        self.add_registered_report("primary.md", "000001", additional=("000002", "000004"))
        self.add_registered_report("both.md", "000004")
        self.add_registered_report("a-only.md", "000003", agent="A001")

        state = validator.collect_research_report_state(self.root, self.config)
        entries = {
            entry.uid: entry
            for entry in validator.research_tracker_entries(
                self.config,
                state.direct_records_by_uid,
                state.additional_records_by_uid,
            )
        }
        self.assertEqual("direct_only", entries["000001"].coverage_state)
        self.assertEqual("additional_only", entries["000002"].coverage_state)
        self.assertEqual("not_covered", entries["000003"].coverage_state)
        self.assertEqual("direct_and_additional", entries["000004"].coverage_state)
        self.assertEqual(1, len(entries["000003"].direct_report_paths))

        rendered = validator.render_research_tracker(
            self.root, self.config, validator.CommandContext(), "unit-test"
        )
        self.assertIn("| `by-memory` | 4 | 3 | 75.0% | 1 | 1 | 1 |", rendered)
        self.assertIn("### Additionally-Covered-Only Files - Reconstructable", rendered)

    def test_execute_dry_run_is_non_mutating_and_apply_registers_all_edges(self) -> None:
        for uid in ("000001", "000002"):
            self.add_target(uid)
        source = self.root / "tools" / "leaser" / "Agents" / "Agent-B001" / "research" / "report.md"
        source.parent.mkdir(parents=True)
        source.write_text(self.report_text("000001", additional=("000002",)), encoding="utf-8")
        central_dir = self.root / "executed-b-agent-research" / "B001"

        validator.run_execute_report_command(self.command_args(), self.root, self.config)
        self.assertTrue(source.exists())
        self.assertFalse(central_dir.exists())
        self.assertEqual(0, len(self.config[validator.RESEARCH_REPORT_UID_SECTION]))

        validator.run_execute_report_command(
            self.command_args(apply=True), self.root, self.config
        )
        destination = central_dir / "report.md"
        self.assertFalse(source.exists())
        self.assertTrue(destination.exists())
        relative = destination.relative_to(self.root).as_posix()
        self.assertEqual("000001", self.config[validator.RESEARCH_REPORT_UID_SECTION][relative])
        self.assertEqual(("000002",), validator.additional_uids_for_report(self.config, relative))

    def test_execute_rejects_missing_specs_and_revalidation_without_mutation(self) -> None:
        self.add_target("000001")
        source = self.root / "tools" / "leaser" / "Agents" / "Agent-B001" / "research" / "report.md"
        source.parent.mkdir(parents=True)
        for text in (
            self.report_text("000001", specs=None),
            self.report_text(
                "000001", status=validator.REPORT_VALIDATION_STATUS_NEEDS_REVALIDATION
            ),
        ):
            source.write_text(text, encoding="utf-8")
            before = source.read_bytes()
            with self.assertRaises(SystemExit):
                validator.run_execute_report_command(
                    self.command_args(apply=True), self.root, self.config
                )
            self.assertEqual(before, source.read_bytes())
            self.assertEqual(0, len(self.config[validator.RESEARCH_REPORT_UID_SECTION]))

    def test_confirm_change_rejects_coverage_identity_change(self) -> None:
        for uid in ("000001", "000002"):
            self.add_target(uid)
        path = self.add_registered_report("report.md", "000001")
        changed = path.read_text(encoding="utf-8").replace(
            validator.make_report_target_header("000001"),
            validator.make_report_target_header("000001")
            + "\n"
            + validator.make_report_additional_uids_header(("000002",)),
        )
        path.write_text(changed, encoding="utf-8")
        before = path.read_bytes()
        with self.assertRaises(SystemExit):
            validator.run_execute_confirm_change_command(
                self.command_args(apply=True), self.root, self.config
            )
        self.assertEqual(before, path.read_bytes())

    def test_reassign_requires_registration(self) -> None:
        self.add_target("000001")
        source = self.root / "executed-b-agent-research" / "B001" / "report.md"
        source.parent.mkdir(parents=True)
        source.write_text(self.report_text("000001"), encoding="utf-8")
        args = self.command_args(new_agent_id="B002", apply=True)
        with self.assertRaises(SystemExit):
            validator.run_executed_reassign_command(args, self.root, self.config)
        self.assertTrue(source.exists())
        self.assertFalse((self.root / "executed-b-agent-research" / "B002").exists())

    def test_missing_integrity_registry_values_are_non_counting_errors(self) -> None:
        self.add_target("000001")
        path = self.add_registered_report("report.md", "000001")
        relative = path.relative_to(self.root).as_posix()
        self.config[validator.RESEARCH_REPORT_SHA256_SECTION].pop(relative)
        state = validator.collect_research_report_state(self.root, self.config)
        self.assertEqual(0, len(state.valid_records))
        self.assertTrue(any("report_sha256_registry_missing" in error for error in state.errors))

    def test_removed_report_archives_are_not_report_candidates(self) -> None:
        self.add_target("000001")
        report = self.add_registered_report("report.md", "000001")
        removed = report.with_name("report-removed.md")
        removed.write_text(
            "# Removed executable material\n\nNon-authoritative; do not execute.\n",
            encoding="utf-8",
        )

        central = validator.central_report_files(self.root)
        self.assertEqual([report], central)

        active_dir = self.root / "tools" / "leaser" / "Agents" / "Agent-B001" / "research"
        active_dir.mkdir(parents=True)
        active_report = active_dir / "active.md"
        active_removed = active_dir / "active-removed.md"
        active_report.write_text(self.report_text("000001"), encoding="utf-8")
        active_removed.write_text("# Removed executable material\n", encoding="utf-8")
        self.assertEqual([active_report], validator.active_b_agent_research_reports(self.root))

    def test_bulk_confirm_removed_archives_accepts_only_integrity_drift(self) -> None:
        self.add_target("000001")
        report = self.add_registered_report("report.md", "000001")
        archive = report.with_name("report-removed.md")
        archive.write_text(
            "# Removed executable material\n\n"
            "This archive is non-authoritative and must never be executed.\n",
            encoding="utf-8",
        )
        report.write_text(
            report.read_text(encoding="utf-8")
            + "\nExecutable material was preserved in [report-removed.md](report-removed.md).\n",
            encoding="utf-8",
        )

        actions = validator.run_execute_confirm_removed_archives_command(
            self.command_args(apply=True), self.root, self.config
        )

        self.assertEqual(
            ["research_report_removed_archive_confirm_change"],
            [action.action for action in actions],
        )
        state = validator.collect_research_report_state(self.root, self.config)
        self.assertEqual(1, len(state.valid_records))
        self.assertEqual((), state.errors)
        self.assertIn("content-change-confirmed", report.read_text(encoding="utf-8"))

    def test_full_autogen_removes_validator_owned_inactive_root(self) -> None:
        path = self.root / "auto-generated" / "NexusTK" / "legacy" / "Legacy.cpp"
        path.parent.mkdir(parents=True)
        path.write_text(
            validator.generated_cpp_content(
                "000001",
                "by-file/Legacy.md",
                "int legacy_value;\n",
                validator.CommandContext(
                    command_id=1,
                    command_id_display="000000000001",
                    command_timestamp="2026-07-22T00:00:00-04:00",
                ),
                "test",
            ),
            encoding="utf-8",
        )
        state = {"backup_root": None}
        dry_actions = validator.cleanup_stale_nexustk_generated_cpp(
            self.root,
            self.config,
            False,
            state,
            active_root_uids=set(),
        )
        self.assertTrue(path.exists())
        self.assertEqual("autogen_cpp_stale_delete", dry_actions[0].action)

        apply_actions = validator.cleanup_stale_nexustk_generated_cpp(
            self.root,
            self.config,
            True,
            state,
            active_root_uids=set(),
        )
        self.assertFalse(path.exists())
        self.assertEqual("autogen_cpp_stale_delete", apply_actions[0].action)

    def test_report_count_changes_replays_remove_and_reexecute(self) -> None:
        self.add_target("000001")
        current = self.add_registered_report("new.md", "000001")
        now = datetime.now().astimezone()
        events = (
            (1, "old.md", now - timedelta(hours=20)),
            (-1, "old.md", now - timedelta(hours=10)),
            (1, current.relative_to(self.root).as_posix(), now - timedelta(hours=5)),
        )
        for delta, report_path, timestamp in events:
            validator.add_report_change_event(
                self.config,
                delta,
                "000001",
                "by-memory",
                report_path,
                timestamp=timestamp.isoformat(timespec="seconds"),
            )
        rows = dict(
            (label, values)
            for label, *values in validator.report_count_change_rows(
                self.root, self.config
            )["by-memory"]
        )
        self.assertEqual([1, 2, 0, 2, 0], rows["Last 24 hours"])


if __name__ == "__main__":
    unittest.main()
