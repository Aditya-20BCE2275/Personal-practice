#include <iostream>
#include <vector>

class Participant
{
public:
    Participant() {}

    void receive_vote_request(int transaction_id)
    {
        std::cout << "Received VOTE_REQUEST from Coordinator for Transaction " << transaction_id << std::endl;
        std::string vote;
        std::cout << "Do you vote 'COMMIT' or 'ABORT'? ";
        std::cin >> vote;
        if (vote == "COMMIT")
        {
            this->votes[transaction_id] = true;
        }
        else
        {
            this->votes[transaction_id] = false;
        }
    }

    bool get_vote(int transaction_id)
    {
        return this->votes[transaction_id];
    }

private:
    std::vector<bool> votes;
};

class Coordinator
{
public:
    Coordinator() {}

    void send_vote_request(int transaction_id)
    {
        std::cout << "Sending VOTE_REQUEST to all participants for Transaction " << transaction_id << std::endl;
        for (auto &participant : participants)
        {
            participant.receive_vote_request(transaction_id);
        }
    }

    bool all_votes_are(int transaction_id, bool vote)
    {
        for (auto &participant : participants)
        {
            if (participant.get_vote(transaction_id) != vote)
            {
                return false;
            }
        }
        return true;
    }

    void send_commit(int transaction_id)
    {
        std::cout << "Sending COMMIT to all participants for Transaction " << transaction_id << std::endl;
    }

    void send_abort(int transaction_id)
    {
        std::cout << "Sending ABORT to all participants for Transaction " << transaction_id << std::endl;
    }

    void start(int transaction_id)
    {
        send_vote_request(transaction_id);
        if (all_votes_are(transaction_id, true))
        {
            send_commit(transaction_id);
        }
        else
        {
            send_abort(transaction_id);
        }
    }

    void add_participant(Participant participant)
    {
        participants.push_back(participant);
    }

private:
    std::vector<Participant> participants;
};

int main()
{
    Participant participant1;
    Participant participant2;
    Coordinator coordinator;

    coordinator.add_participant(participant1);
    coordinator.add_participant(participant2);

    coordinator.start(1);

    return 0;
}
